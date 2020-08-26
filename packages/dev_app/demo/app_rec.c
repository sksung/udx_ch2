/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_rec.c
 * @brief	app record thread
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include "app_comm.h"
#include "app_main.h"
#include "app_gmem.h"
#include "app_cap.h"
#include "app_avi.h"
#include "app_disk.h"
#include "app_rec.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define EN_AVI			1
#define MAX_REC_SEC		2*60	//# 1 min.

typedef struct {
	app_thr_obj rObj;			//# rec thread

	int ste_rec;				//# 1:recording, 0:idle

	AVI_SYSTEM_PARAM avi_info;
	FILE *fevt;					//# for record file
} app_rec_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_rec_t rec_obj;
static app_rec_t *irec=&rec_obj;

static g_mem_info_t	*imem;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 functions for imem index
-----------------------------------------------------------------------------*/
static int idx_increase(int idx)
{
	if(imem->ifr[idx].end) {
		idx = 0;
	} else {
		idx++;
	}

	return idx;
}

static int idx_decrease(int idx)
{
	idx--;
	if(idx < 0) {
		idx = imem->max_num-1;
	}

	return idx;
}

static int get_valid_frame(int idx)
{
	int cur_idx = idx_decrease(imem->cur_num);	//# protect 1 buffers
	int f_num = 0;

	if(cur_idx < 0)
		return 0;

	if(idx < cur_idx) {
		f_num = cur_idx - idx;
	}
	else if(idx > cur_idx) {
		if( (idx-cur_idx) < 5*30) {
			dprintf("WARRING! : idx buffer not enough\n");
			return 0;
		}
		f_num = (imem->max_num - idx) + cur_idx;
	}
	else {
		return 0;
	}

	return f_num;
}

//# search I frame index
static int search_frame(int ch, int sec)
{
	int idx, max_cnt, key_idx=-1;
	stream_info_t *ifr;

	if(imem->max_num == 0 && imem->cur_num < 1) {
		return -1;
	}

	idx = idx_decrease(imem->cur_num);	//# protect 1 buffers
	if(imem->max_num == 0) {			//# for first loop
		max_cnt = imem->cur_num;
	} else {
		max_cnt = imem->max_num;
	}

	while(max_cnt--)
	{
		ifr = &imem->ifr[idx];
		if((ifr->ch==ch) && (ifr->d_type==CAP_TYPE_VIDEO) && ifr->is_key) {
			sec--; key_idx = idx;
			if(sec<0) break;
		}
		idx = idx_decrease(idx);
	}

	return key_idx;
}

/*----------------------------------------------------------------------------
 avi file open/close function
-----------------------------------------------------------------------------*/
static FILE *avi_file_open(char *file_name)
{
	FILE *favi;

	favi = LIBAVI_createAvi(file_name, &irec->avi_info);
	if(favi == NULL) {
		eprintf("avi save handle is NULL!\n");
	}

	return favi;
}

static void avi_file_close(FILE *favi)
{
	if(favi) {
		LIBAVI_closeAvi(favi);
	}
}

static int avi_file_write(FILE *favi, stream_info_t *ifr)
{
	AVI_FRAME_PARAM frame;

	if(favi)
	{
		if(ifr->d_type == CAP_TYPE_VIDEO) {
			frame.data_type		= DATA_TYPE_VIDEO;
			frame.channel 		= 0/*ifr->ch*/;
			frame.iskey_frame 	= ifr->is_key;
		}
		else if(ifr->d_type == CAP_TYPE_AUDIO) {
			frame.data_type		= DATA_TYPE_AUDIO;
		}
		else if(ifr->d_type == CAP_TYPE_META) {
			frame.data_type		= DATA_TYPE_META;
		}
		else {
			dprintf("unknown data type\n");
			return 0;
		}

		frame.buf	= (char *)(ifr->addr);
		frame.size	= ifr->b_size;

		if(LIBAVI_write_frame(favi, &frame) < 0) {
			eprintf("LIBAVI_write_frame\n");
			return -1;
		}
	}

	return 0;
}

static int avi_file_init(stream_info_t *ifr)
{
	AVI_SYSTEM_PARAM *aviInfo;
	int i;

	aviInfo = &irec->avi_info;
	memset(aviInfo, 0, sizeof(AVI_SYSTEM_PARAM));

	aviInfo->nVidCh		= 1/*iapp->num_ch*/;
	aviInfo->bEnAudio	= EN_REC_AUD;
	aviInfo->bEnMeta	= EN_REC_META;
	aviInfo->uVideoType	= ENCODING_H264;

	for(i=0; i<aviInfo->nVidCh; i++) {
		aviInfo->nVidWi[i] = ifr->frm_wi;
		aviInfo->nVidHe[i] = ifr->frm_he;
	}
	aviInfo->fFrameRate	= (double)(ifr->frm_rate*1000./1001.);

	return 0;
}

/*****************************************************************************
* @brief    event record function
* @section  [desc]
*****************************************************************************/
static int evt_file_open(stream_info_t *ifr)
{
	char filename[128];

	struct tm ts;
	char buf_time[64];

	//# get current date & time
	localtime_r((const time_t *)&ifr->t_sec, &ts);

	strftime(buf_time, sizeof(buf_time), "%Y%2m%2d_%2H%2M%2S", &ts);
	#if EN_AVI
	sprintf(filename, "%s/REC_%s_CH%d.avi", DIR_REC, buf_time, ifr->ch);
	#else
	sprintf(filename, "%s/REC_%s_CH%d.h264", DIR_REC, buf_time, ifr->ch);
	#endif

	#if EN_AVI
	avi_file_init(ifr);
	irec->fevt = avi_file_open(filename);	//# open new file
	#else
	irec->fevt = fopen(filename, "wb");
	#endif
	if(irec->fevt == NULL) {
		eprintf("new file open (%s)\n", filename);
		return -1;
	}

	aprintf("new filename %s\n", filename);

	return 0;
}

static void evt_file_close(void)
{
	if(irec->fevt) {
		#if EN_AVI
		avi_file_close(irec->fevt);
		#else
		fclose(irec->fevt);
		#endif
		irec->fevt = NULL;
	}
}

static int evt_file_write(stream_info_t *ifr)
{
	int ret = 0;

	#if EN_AVI
	ret =  avi_file_write(irec->fevt, ifr);
	#else
	if(ifr->d_type == CAP_TYPE_VIDEO) {
		ret = fwrite(ifr->addr, 1, ifr->b_size, irec->fevt);
	}
	#endif

	return ret;
}

/*****************************************************************************
* @brief    record thread function
* @section  [desc]
*****************************************************************************/
static void *THR_rec(void *prm)
{
	app_thr_obj *tObj = &irec->rObj;
	int cmd, exit=0, ret;
	int ch, sec;
	int i, frame_num, read_idx=0;
	int done;
	stream_info_t *ifr;

	aprintf("enter...\n");
	tObj->active = 1;

	while(!exit)
	{
		//# wait cmd
		irec->ste_rec = 0;
		cmd = event_wait(tObj);
		if(cmd == APP_CMD_EXIT) {
			break;
		}
		if(cmd == APP_CMD_STOP) {
			continue;
		}
		ch = tObj->param0;
		sec = tObj->param1;

		irec->ste_rec = 1;

		read_idx = search_frame(ch, 0);		//# search current I-frame
		if(read_idx < 0) {
			continue;
		}

		//# file open
		ret = evt_file_open(&imem->ifr[read_idx]);
		if(ret < 0) {
			continue;
		}

		done = 0;
		while(!done)
		{
			if(tObj->cmd == APP_CMD_EXIT || tObj->cmd == APP_CMD_STOP) {
				break;
			}

			frame_num = get_valid_frame(read_idx);
			if(frame_num < 10) {
				OSA_waitMsecs(10);
				continue;
			}

			for(i=0; i<frame_num; i++)
			{
				ifr = &imem->ifr[read_idx];
				if( (ifr->ch==ch) && (ifr->d_type==CAP_TYPE_VIDEO) && ifr->is_key ) {
					sec--;
					if(sec<0) {
						done = 1;
						break;
					}
				}
				if(ifr->ch==ch) {
					ret = evt_file_write(ifr);
					if(ret < 0) {
						done = 1;
						break;
					}
				}
				read_idx = idx_increase(read_idx);
				if(tObj->cmd == APP_CMD_EXIT || tObj->cmd == APP_CMD_STOP) {
					break;
				}
			}
		}

		//# record done
		evt_file_close();

		dprintf("record done!\n");
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    record start/stop function
* @section
*****************************************************************************/
int app_rec_start(int ch)
{
	if(!iapp->en_rec || !iapp->ste.b.cap) {
		eprintf("record is inactive state!\n");
		return EFAIL;
	}
	if(irec->ste_rec) {		//# currently record
		return EFAIL;
	}

	dprintf("record start ch %d, time %d\n", ch, MAX_REC_SEC);

	iapp->ste.b.rec = 1;
	event_send(&irec->rObj, APP_REC_START, ch, MAX_REC_SEC);

	return SOK;
}

int app_rec_stop(void)
{
	if(irec->ste_rec)
	{
		event_send(&irec->rObj, APP_CMD_STOP, 0, 0);
		while(irec->ste_rec) {	//# wait rec stop
			OSA_waitMsecs(20);
		}

		sync();
		OSA_waitMsecs(200);		//# wait for safe
		iapp->ste.b.rec = 0;
	}

	return SOK;
}

/*****************************************************************************
* @brief    mjpeg save function
* @section  [desc]
*****************************************************************************/
int app_save_jpeg(int ch, void *addr, int size, unsigned int sec)
{
	FILE *fout;
	struct tm ts;
	char buf[64], file_name[128];
	int save_ch;

	if(addr == NULL) {
		return EPARAM;
	}

	localtime_r((const time_t *)&sec, &ts);

	strftime(buf, sizeof(buf), "%Y%2m%2d_%2H%2M%2S", &ts);
	sprintf(file_name, "%s/IMG_%s_CH%d.jpeg", DIR_REC, buf, ch);

	fout = fopen(file_name, "wb");
	if (fout == NULL) {
		return EFAIL;
	}
	fwrite(addr, 1, size, fout);
	fclose(fout);

	dprintf("%s save done!\n", file_name);

	return SOK;
}

/*****************************************************************************
* @brief    app record init/exit function
* @section  [desc]
*****************************************************************************/
int app_rec_init(void)
{
	app_thr_obj *tObj = &irec->rObj;

	//# record directory init
	disk_chk_rec_dir(DIR_REC, 0);

	if(!iapp->en_rec) {
		return SOK;
	}

	//# static config clear
	memset((void *)irec, 0x0, sizeof(app_rec_t));

	imem = (g_mem_info_t *)g_mem_get_virtaddr();

	//# record directory init
	disk_chk_rec_dir(DIR_REC, 0);

	//# start rec process
	//#--- create dio thread
	if(thread_create(tObj, THR_rec, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

int app_rec_exit(void)
{
	app_thr_obj *tObj;

	if(!iapp->en_rec) {
		return SOK;
	}

	//#--- stop thread
	tObj = &irec->rObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);

	return SOK;
}
