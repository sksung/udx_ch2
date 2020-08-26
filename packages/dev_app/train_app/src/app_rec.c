/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_rec.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 *	   - 2014.02.27 : Modified by sksung
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/timeb.h>

#include <cmem.h>

#include "dev_common.h"
#include "dev_micom.h"
#include "udavi.h"

#include "ucx_main.h"
#include "app_ctrl.h"
#include "app_util.h"
#include "app_gui.h"
#include "app_snd.h"
#include "app_cap.h"
#include "app_dev.h"
#include "app_rec.h"
#include "app_file.h"
#include "app_set.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
//#define EN_REC_MONITOR

#define MAX_ENCODE_BIT	5

#define TIME_POST_REC	10
#define TIME_PRE_REC	10


typedef struct {
	app_thr_obj *rObj;	//# record thread
	app_thr_obj *eObj;	//# event record thread

	OSA_MutexHndl mtx_avi;
	FILE *favi;			//# for normal file
	FILE *fevt;			//# for event file

    char nor_fname[CHAR_128];
    char evt_fname[CHAR_128];

    int rec_first;
	int num_ch;
	int old_min;
	int chg_file;
	int snapshoot;

	int evt_rec;
	int evt_type;
	int evt_btime;		//# pre recording time
	int evt_atime;		//# post recording time

	int sub_rec;		//# first key frame flag
	int rec_min;		//# rec duration 1,5,10,20,30,60
} app_rec_t;

typedef struct {
	app_thr_obj *rmObj;
	int 		bps[MAX_CH_NUM];
	int 		fps[MAX_CH_NUM];
	int 		elapsed_msec[MAX_CH_NUM];
} app_rec_mon_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_rec_t t_rec;
static app_rec_t *irec=NULL;
static g_mem_info_t	*imem;

static app_rec_mon_t t_mon;
static app_rec_mon_t *imon=NULL;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 function for frame index
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
	int cur_idx = imem->cur_num - 3;	//# protect 3 buffers
	int f_num = 0;

	if(cur_idx < 0)
		return 0;

	if(idx < cur_idx) {
		f_num = cur_idx - idx;
	}
	else if(idx > cur_idx) {
		if( (idx-cur_idx) < 2*30) {
			dprintf("WARRING! : idx buffer not enough\n");
			return 0;
		}
		f_num = (imem->max_num - idx) + cur_idx;
	}
	else {
		return 0;
	}

	//dprintf("cur_num %d, max_num %d -> idx %d, f_num %d\n", imem->cur_num, imem->max_num, idx, f_num);

	return f_num;
}

static int serach_frame(int sec)
{
	int idx, max_cnt;
	stream_info_t *ifr;

	if(imem->cur_num < 0)
		return 0;

	idx = imem->cur_num - 1;
	if(imem->max_num == 0)	//# for first loop
		max_cnt = imem->cur_num;
	else
		max_cnt = imem->max_num;

	while(max_cnt--)
	{
		ifr = &imem->ifr[idx];
		if((ifr->d_type==DATA_TYPE_VIDEO_MAIN) && (ifr->is_key) && (ifr->ch == 0)) {
			sec--;
			if(sec==0)	return idx;
		}
		idx = idx_decrease(idx);
	}

	return 0;
}

/*----------------------------------------------------------------------------
 avi file open/close function
-----------------------------------------------------------------------------*/
static FILE *avi_file_open(char *full_path, char* fname, stream_info_t *ifr, int mode)
{
	FILE *favi;
	AVI_SYSTEM_PARAM aviInfo;
	struct timeb t_start, t_end; 
	int t_diff;

	if(irec == NULL)
		return NULL;

	//memset(&aviInfo, 0, sizeof(AVI_SYSTEM_PARAM));
	aviInfo.uSystemType		= SYSTEM_TYPE_VIDEO;
	aviInfo.uChannelMode	= mode;	//# 0:CHANNEL_MODE_SINGLE, 1:CHANNEL_MODE_SUBPIC
	aviInfo.uVideoType		= ENCODING_H264;
	aviInfo.nMainWidth		= app_cfg->ifrm[0].wi;
	aviInfo.nMainHeight		= app_cfg->ifrm[0].he;
	aviInfo.nSubWidth		= app_cfg->ifrm[1].wi;
	aviInfo.nSubHeight		= app_cfg->ifrm[1].he;
	aviInfo.fFrameRate		= (double)(app_cfg->ifrm[0].fr*1000./1001.);

	//# audio infor
	if(app_set->aud.mic_on){
		aviInfo.uSystemType			= SYSTEM_TYPE_AUDIO_VIDEO;
		aviInfo.nAudioType			= ENCODING_ULAW;
		aviInfo.nAudioChannel		= 1;
		aviInfo.nSamplesPerSec		= AUD_SAMPLE_LATE;
		aviInfo.nAudioBitRate		= AUD_SAMPLE_LATE;
		aviInfo.nAudioBitPerSample	= 16;
		aviInfo.nAudioFrameSize		= 2000;
	}

	//# meta info
	aviInfo.nEnableMeta		= TRUE;
	aviInfo.nMetaFps		= META_REC_FPS;

	ftime(&t_start);
	favi = LIBAVI_createAvi(full_path, &aviInfo, FILE_ENCODING);
	ftime(&t_end);

	t_diff = (int)(1000.0 * (t_end.time - t_start.time)
				   + (t_end.millitm - t_start.millitm)); 
	if(t_diff > 500)
		printf("########LIBAVI_createAvi() over 500ms (%d ms)########\n", t_diff);

	if(favi == NULL)
		eprintf("avi file handle is NULL!\n");

	return favi;
}

static void avi_file_close(FILE *favi, char* fname, int rec_type)
{
	struct timeb t_start, t_end; 
	int t_diff;
	
	if(!app_cfg->state.mmc || irec==NULL)
		return;

	if(favi) {
		ftime(&t_start);
		LIBAVI_closeAvi(favi);
		ftime(&t_end);

		t_diff = (int)(1000.0 * (t_end.time - t_start.time)
   					   + (t_end.millitm - t_start.millitm)); 
		if(t_diff > 500)
			printf("########LIBAVI_closeAvi() over 500ms (%d ms)########\n", t_diff);

		favi = NULL;
		app_file_update(fname, 1);
	}
}

static int avi_file_write(FILE *favi, stream_info_t *ifr)
{
	AVI_FRAME_PARAM frame;
	struct timeb t_start, t_end; 
	int t_diff, i;	
	int ret = SOK;

	if(favi)
	{
		if(ifr->d_type == DATA_TYPE_VIDEO_MAIN)
		{
			if(ifr->ch == 1 && ifr->is_key && irec->sub_rec == 0)
				irec->sub_rec = 1;

			if(ifr->ch == 1 && irec->sub_rec == 0)
				return 0;

#ifdef EN_REC_MONITOR
			imon->bps[ifr->ch] += ifr->b_size;
			imon->fps[ifr->ch]++;
#endif

#if FILE_ENCODING
			if(ifr->is_key){
				for(i = 0; i < MAX_ENCODE_BIT; i++){
					ifr->buf[i] = ~(ifr->buf[i]);
				}
			}
#endif

			frame.buf			= (char*)ifr->buf;
			frame.size			= ifr->b_size;
			frame.data_type		= ifr->ch;		//# DATA_TYPE_MAIN or DATA_TYPE_SUB
			frame.iskey_frame 	= ifr->is_key;
			//frame.time_sec	= ifr->t_sec;
			//frame.time_usec 	= ifr->t_msec;
		}
		else if(ifr->d_type == DATA_TYPE_AUDIO)
		{
			frame.buf			= (char*)ifr->buf;
			frame.size			= ifr->b_size;
			frame.data_type		= DATA_TYPE_AUDIO;
		}

		else if(ifr->d_type == DATA_TYPE_META)
		{
			frame.buf			= (char*)ifr->buf;
			frame.size			= ifr->b_size;
			frame.data_type		= DATA_TYPE_META;
 		}
		else
		{
			eprintf("Unknown data type!!!\n");
			return 0;
		}

		ftime(&t_start);
		ret = LIBAVI_write_frame(favi, &frame);
		ftime(&t_end);

		t_diff = (int)(1000.0 * (t_end.time - t_start.time)
					   + (t_end.millitm - t_start.millitm)); 
		if(t_diff > 500)
			printf("########LIBAVI_write_frame() over 500ms (%d ms)########\n", t_diff);
	}

    return ret;
}

/*****************************************************************************
* @brief    normal record function
* @section  DESC Description
*   - desc
*****************************************************************************/
static ifrm_cnt = 0;
static int nor_file_open(stream_info_t *ifr)
{
	char buf[CHAR_32]			= {0,};;
	char rec_dir[CHAR_64] 		= {0,};
	char full_path[CHAR_128]	= {0,};
	
	struct tm ts;
	int rec_type = REC_DRIVE;
    int minute_change=0;

	localtime_r((const time_t *)&ifr->t_sec, &ts);

#if FREC_TEST

	if(ifr->is_key) ifrm_cnt++;
	if((ifrm_cnt%10)==0)  irec->chg_file=1;	//# 10 sec
	
#else

	if(app_cfg->num_ch)
	{
		//# record per 5 min
	    if(!irec->rec_first){
	        if(ts.tm_min%irec->rec_min == 0)
	            minute_change = 1;
	    }
	    
	    if(irec->rec_first){
	        minute_change = 1;
	        irec->rec_first = 0;
	    }
	}
	
#endif

 	if( (irec->old_min != ts.tm_min && minute_change) || irec->chg_file || app_set->rec_type == REC_TYPE_MOT)//irec->evt_rec)
	{
	
#if FREC_TEST
		ifrm_cnt = 0;	
#endif	

		irec->old_min 	= ts.tm_min;
		irec->num_ch 	= app_cfg->num_ch;
		irec->chg_file 	= 0;
        minute_change = 0;

		avi_file_close(irec->favi, irec->nor_fname, rec_type);

		irec->favi = NULL;

		//#Do not create avi file because connected cameras are nothing. 
		if(app_cfg->num_ch == 0)
			return 0;
		
        if(app_set->rec_type == REC_TYPE_NOR)
        {
            memset(irec->nor_fname, 0, CHAR_128);

            strftime(buf, sizeof(buf), "%Y%2m%2d_%2H%2M%2S", &ts);
            sprintf(irec->nor_fname, "N_%s_%dch.%s", buf, irec->num_ch, REC_EXT);

			app_file_update(irec->nor_fname, 0);

			if(app_get_dir_name(rec_dir) != 0){
				eprintf("Failed Get Rec Dir!!! \n");
				return -1;
		    }
			
		    sprintf(full_path, "%s/%s", rec_dir, irec->nor_fname);
			printf("new filename %s\n", full_path);

			if(app_cfg->state.mmc)
			{
				irec->favi = avi_file_open(full_path, irec->nor_fname, ifr, irec->num_ch-1);
				if(irec->favi == NULL){
					eprintf("AVI file crate failed!!\n");
					return -1;
				}
			}

			irec->sub_rec = 0;
        }
	}

	return 0;
}

static int nor_file_save(stream_info_t *ifr)
{
	int ret;
	char msg[CHAR_128];

	if(ifr->ch > 0)		//# only CH01 Camera
		return 0;

	if(ifr->is_key && (ifr->ch == 0) && (ifr->d_type == DATA_TYPE_VIDEO_MAIN)) {
		if(nor_file_open(ifr) != 0){
            sprintf( msg, " !!! NOR file open failed !!!");
			app_log_write( MSG_LOG_WRITE, msg );
			
            return -1;
        }
	}

	ret = avi_file_write(irec->favi, ifr);

    return ret;
}

static int check_rec_state()
{
    if(app_cfg->state.mmc)
		app_cfg->state.mmc = 0;

	if(!app_cfg->state.mmc)
		return EFAIL;

	if(app_cfg->state.mmc)
		return SOK;
}

/*----------------------------------------------------------------------------
 normal record main function
-----------------------------------------------------------------------------*/
static void *nor_rec_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int cmd, exit=0;
	int frame_num, read_idx=0;
	int i, rec_type=REC_DRIVE;
	
	printf(" [task] %s start\n", __func__);
	tObj->done = 0;

	while(!exit)
	{
		//# wait cmd
		cmd = event_wait(tObj);
		if(cmd == UBX_CMD_STOP) {
			break;
		}

		frame_num = get_valid_frame(read_idx);
		#if 0
		if(frame_num < 10) {
			//OSA_waitMsecs(30);
			continue;
		}
		#endif

		if(frame_num > 100)
		{
			dprintf("imem (%4d/%4d, %4d) -> idx %4d, f_num %d\n",
				imem->cur_num, imem->max_num, imem->read_num, read_idx, frame_num);
		}

		for(i=0; i<frame_num; i++)
		{
			if(nor_file_save(&imem->ifr[read_idx]) == EFAIL){
				//# could not recording to HDD and SD
				app_cfg->state.sd_buzzer	= 1;
				app_cfg->state.rec			= 0;
				app_cfg->state.mmc_err		= 1;
				exit = 0;
				break;
#if 0				
				if(check_rec_state() == EFAIL){
					//# could not recording to HDD and SD
            	    app_cfg->state.sd_buzzer	= 1;
					app_cfg->state.rec 			= 0;
					app_cfg->state.mmc_err		= 1;
					break;
				}
				else{
					irec->chg_file = 1;		//# change path to SD
					
					sprintf( msg, " !!! HDD Recording Failed !!!" );
					app_log_write( MSG_LOG_WRITE, msg );
				}
#endif				
			}

			read_idx = idx_increase(read_idx);
			imem->read_num = read_idx;

			if(cmd == UBX_CMD_STOP)
				break;
		}
	}

	avi_file_close(irec->favi, irec->nor_fname, rec_type);
	irec->favi = NULL;

	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}


static void *rec_mon_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int i, cmd, exit=0;
	int cycle, msec=3000;
	int calbps;

	printf(" [task] %s start\n", __func__);
	tObj->done = 0;

	tObj->cmd = -1;
	cycle = 0;
	while(!exit)
	{
		//# wait cmd
		cmd = tObj->cmd;
		if(cmd == UBX_CMD_STOP) {
			exit = 1;
			break;
		}

		if(cycle > 0 && (cycle%msec == 0))
		{
			printf("\n");

			printf("(W) - ");
			for (i = 0; i < app_cfg->num_ch; i++){
				printf("%4u ",(imon->bps[i] / (msec/1000))*8 / KB);
				imon->bps[i] = 0;
			}

			printf(", ");
			for (i = 0; i < app_cfg->num_ch; i++){
				calbps = imon->fps[i] / (msec/1000);
				printf("%2u ", calbps);
				imon->fps[i] = 0;
			}
			printf("\n");
		}

		OSA_waitMsecs(100);
		cycle += 100;
	}

	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    record thread start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_rec_start(void)// *g_mem_info)
{
	app_thr_obj *tObj;
	int status;

	if(app_cfg->state.rec || !app_cfg->state.mmc || app_cfg->state.mmc_sz)
		return 0;

	irec = &t_rec;
	imem = (g_mem_info_t *)app_get_gmem();

#ifdef 	EN_REC_MONITOR
		memset(&t_mon, 0, sizeof(t_mon));
		imon = &t_mon;
#endif

    status = OSA_mutexCreate(&irec->mtx_avi);
    OSA_assert(status == OSA_SOK);

	//# init config
	irec->favi 		= NULL;
	irec->fevt 		= NULL;

	irec->old_min 	= -1;
	irec->num_ch 	= app_cfg->num_ch;
	irec->chg_file 	= 0;

	irec->evt_rec 	= 0;
	irec->evt_btime = TIME_PRE_REC;
	irec->evt_atime = TIME_POST_REC;

    irec->rec_first = 1;
	irec->rec_min	= get_rec_dur_val(app_set->sys.rec_duration);

	//#--- create normal record thread

	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj ==NULL) {
		eprintf("thread obj malloc fail\n");
		return -1;
	}
	irec->rObj = tObj;

	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	OSA_thrCreate(&tObj->thr, nor_rec_main, FXN_TSK_PRI, 0, tObj);


#ifdef EN_REC_MONITOR
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj ==NULL) {
		eprintf("thread obj malloc fail\n");
		return -1;
	}
	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	OSA_thrCreate(&tObj->thr, rec_mon_main, FXN_TSK_PRI+3, 0, tObj);
	imon->rmObj = tObj;
#endif

	app_cfg->state.rec 		= 1;
    app_cfg->state.sd_buzzer = 0;
	printf(" [app ] %s done!\n\n", __func__);

	return 0;
}

void app_rec_stop(void)
{
	int status;
	app_thr_obj *tObj;

	if(!app_cfg->state.rec || irec == NULL)
		return;

	app_cfg->state.rec = 0;

	tObj = irec->rObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		free(tObj);
		tObj = NULL;
	}

#ifdef EN_REC_MONITOR
	tObj = imon->rmObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		free(tObj);
		tObj = NULL;
	}
	imon = NULL;
#endif

    status = OSA_mutexDelete(&(irec->mtx_avi));
    OSA_assert(status == OSA_SOK);

    #if 0
	if (app_cfg->state.mmc) {
		sync();
	}
    #endif

	app_capt_buff_reset();

	irec = NULL;

	printf(" [app ] %s done!\n\n", __func__);
}

/*----------------------------------------------------------------------------
 record notify function
-----------------------------------------------------------------------------*/
void app_rec_notify(void)
{
	if(irec == NULL)
		return;

	if(irec->rObj != NULL)
		event_send(irec->rObj, UBX_CMD_NOTY, 0, 0);
}


/*****************************************************************************
* @brief	snapshot function
* @section	DESC Description
*	- desc
*****************************************************************************/
void app_snap_shoot(void)
{
	int i;

	if(!app_cfg->state.rec || !app_cfg->state.cap || irec->snapshoot > 0)
		return;

	if(irec->snapshoot == 0)
	{
		for(i=0; i<app_cfg->num_ch; i++)
			irec->snapshoot |= (ON<<i);
	}
}

/*****************************************************************************
* @brief	change file function
* @section	DESC Description
*	- desc
*****************************************************************************/
void app_change_file(void)
{
	if(!app_cfg->state.rec)
		return;

	irec->chg_file = 1;
}


void app_rec_change_dur(int dur)
{
	if(dur < REC_DUR_01 || dur >= REC_DUR_MAX)
		return;
	
	if(app_cfg->state.rec)
	{
		irec->chg_file = 1;
		irec->rec_min	= get_rec_dur_val((app_rec_dur_e)dur);
	}

	app_set->sys.rec_duration = dur;
}


void app_rec_file_close(void)
{
	if(irec == NULL) return;

	avi_file_close(irec->favi, irec->nor_fname, REC_DRIVE);
	irec->favi = NULL;
}


