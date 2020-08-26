/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_pbk.c
 * @brief	app playback thread
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#include "ti_vsys.h"
#include "ti_vdec.h"
#include "ti_vdis.h"

#include "app_comm.h"
#include "app_main.h"
#include "app_rec.h"
#include "app_avi.h"
#include "app_disk.h"
#include "app_ctrl.h"
#include "gui_main.h"
#include "app_pbk.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define PB_MAX_WIDTH		(1280)
#define PB_MAX_HEIGHT		(720)
#define PB_BITBUF_SIZE		(PB_MAX_WIDTH*PB_MAX_WIDTH)/2

#define AVI_VIDEO	(0)
#define AVI_AUDIO	(1)

#define IVIDEO_MJPEG	24	//# #include <ti/xdais/dm/ivideo.h>
#define XSPEED			7	//# x2:16(16.6), x3:11, x4:8(8.3), x5:7(6.6)

#define BYTE2INT(a)		(int)((a[0] << 8) | a[1])

typedef struct {
	app_thr_obj vObj;		//# playback thread
	app_thr_obj aObj;

	int num_ch;
	int rate;
	int msec;
	int cur_idx;
} app_pbk_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_pbk_t pbk_obj;
static app_pbk_t *ipbk=&pbk_obj;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/
static void avi_get_type(unsigned long fccType, int *ch, int *type)
{
	int i;
	char fccIdx[2];
	int strmType;

	for(i = 0; i < 2; i++)
	{
		fccIdx[i] = fccType&0x000000FF;
		fccType = fccType >> 8;
	}

	if(fccType == cktypeDIBcompressed)
		strmType = AVI_VIDEO;
	else if(fccType == cktypeWAVEbytes)
		strmType = AVI_AUDIO;
	else
		strmType = -1;

	*ch = atoi(fccIdx);
	*type = strmType;

	//dprintf("%d, %s\n", atoi(fccIdx), strmType==AVI_VIDEO?"AVI_VIDEO":"AVI_AUDIO");
}

static int avi_get_info(AVIFile *iavi, char *filepath)
{
	dprintf("filepath : %s\n", filepath);

	iavi->pFile = fopen(filepath, "rb");
	if(iavi->pFile == NULL) {
		eprintf("fopen %s! \n", filepath);
		return -1;
	}

	//#--- read avi main header
	fseek(iavi->pFile, 0, SEEK_SET);
	fread(&iavi->Head, sizeof(AVIHeadBlock), 1, iavi->pFile);

	if(iavi->Head.ck_riff.ckID != formtypeRIFF || iavi->Head.ck_riff.ckCodec != formtypeAVI ||
		iavi->Head.ck_hdrl.ckType != listtypeAVIHEADER || iavi->Head.ck_avih.ckID != ckidAVIMAINHDR)
	{
		eprintf("different header information\n");
		return -1;
	}
	if(iavi->Head.avih.dwStreams == 0 || iavi->Head.avih.dwTotalFrames == 0) {
		eprintf("Empty stream data\n");
		return -1;
	}

	//# set framerate
	ipbk->rate = iavi->Head.avih.dwRate;
	ipbk->msec = (iavi->Head.avih.dwMicroSecPerFrame/1000);
	dprintf("rate %d.%d, msec %d\n", (int)(ipbk->rate/iavi->Head.avih.dwScale), (int)(ipbk->rate%iavi->Head.avih.dwScale), ipbk->msec);

	//#--- read movi header
	iavi->movi_pos = sizeof(CK_RIFF) + sizeof(CK) + iavi->Head.ck_hdrl.ckSize;
	fseek(iavi->pFile, iavi->movi_pos, SEEK_SET);
	fread(&iavi->Tail.ck_movi, sizeof(CK_LIST), 1, iavi->pFile);

	if(iavi->Tail.ck_movi.ckSize == 0 && iavi->Tail.ck_movi.ckType != listtypeAVIMOVIE) {
		eprintf("Invalid movi header\n");
		return -1;
	}

	//#--- read idx1 infomation
	iavi->idx1_pos = sizeof(CK_RIFF) + sizeof(CK) + iavi->Head.ck_hdrl.ckSize + sizeof(CK) + iavi->Tail.ck_movi.ckSize;
	fseek(iavi->pFile, iavi->idx1_pos, SEEK_SET);
	fread(&iavi->Tail.ck_idx1, sizeof(CK), 1, iavi->pFile);

	iavi->idx_entry = (AVIINDEXENTRY *)malloc(iavi->Tail.ck_idx1.ckSize);
	fread(iavi->idx_entry, iavi->Tail.ck_idx1.ckSize, 1, iavi->pFile);
	iavi->idx_cnt = iavi->Tail.ck_idx1.ckSize/sizeof(AVIINDEXENTRY);

	iavi->strm_pos = iavi->movi_pos+sizeof(CK_LIST)+4;		//# ???

	dprintf("idx_cnt %d\n", (int)iavi->idx_cnt);

	return 0;
}

static AVIINDEXENTRY *avi_get_frame(AVIFile *pAvi, int mode)
{
	AVIINDEXENTRY *idx=NULL;

	if(mode == APP_PB_FF)
	{
		while(1)
		{
			if(ipbk->cur_idx >= pAvi->idx_cnt) {
				dprintf("end of idx\n");
				break;
			}

			idx = &pAvi->idx_entry[ipbk->cur_idx++];
			if(idx->dwFlags == AVIIF_KEYFRAME) {
				break;
			}
		}
	}
	else if(mode == APP_PB_FR)
	{
		while(1)
		{
			if(ipbk->cur_idx < 0) {
				dprintf("end of idx\n");
				break;
			}

			idx = &pAvi->idx_entry[ipbk->cur_idx--];
			if(idx->dwFlags == AVIIF_KEYFRAME) {
				break;
			}
		}
	}
	else
	{
		if(ipbk->cur_idx < pAvi->idx_cnt) {
			idx = &pAvi->idx_entry[ipbk->cur_idx++];
		}
	}

	return idx;
}

/*****************************************************************************
* @brief    playback video thread function
* @section  [desc]
*****************************************************************************/
static void *THR_pbv(void *prm)
{
	app_thr_obj *tObj = &ipbk->vObj;
	int cmd, exit=0, ret, i;

	VCODEC_BITSBUF_LIST_S emptyBufList;
	VDEC_BUF_REQUEST_S reqInfo;

	AVIFile iavi;
	AVIINDEXENTRY *idx;
	int stream_id, stream_type;
	unsigned long time_start, time_offset, time_wait;

	aprintf("enter...\n");
	tObj->active = 1;

	//# avi info
	iavi.idx_entry = NULL;
	ret = avi_get_info(&iavi, (char *)prm);
	if(ret < 0) {
		goto pbv_exit;
	}

	reqInfo.numBufs = ipbk->num_ch;
	for (i=0; i<reqInfo.numBufs; i++) {
		reqInfo.minBufSize[i] = PB_BITBUF_SIZE;
	}

	//# run playback
	tObj->cmd = 0;
	while(!exit)
	{
		cmd = tObj->cmd;
		if(cmd == APP_CMD_EXIT) {
			exit = 1;
			break;
		}
		if(cmd == APP_PB_PAUSE) {
			event_wait(tObj);		//# wait play event
			continue;
		}

		time_start = app_get_time();

		idx = avi_get_frame(&iavi, cmd);	//APP_PB_PLAY, APP_PB_FF, APP_PB_FR
		if(idx == NULL) {
			goto pbv_exit;
		}

		avi_get_type(idx->ckid, &stream_id, &stream_type);
		if(stream_type == AVI_VIDEO && stream_id == 0)
		{
			//dprintf("---------------------------------\n");

			if((cmd == APP_PB_FF) || (cmd == APP_PB_FR))
				time_wait = (ipbk->msec*XSPEED);
			else
				time_wait = ipbk->msec;

			time_offset = app_get_time() - time_start;
			if(time_offset < time_wait) {
				OSA_waitMsecs(time_wait-time_offset);
			}
		}

		fseek(iavi.pFile, iavi.strm_pos+idx->dwChunkOffset, SEEK_SET);
		if(stream_type == AVI_VIDEO)
		{
			reqInfo.numBufs = 1;
			Vdec_requestBitstreamBuffer(&reqInfo, &emptyBufList, 0);
			if(emptyBufList.numBufs > 0)
			{
				//dprintf("#%d addr %x\n", stream_id, emptyBufList.bitsBuf[0].bufVirtAddr);
				emptyBufList.bitsBuf[0].chnId			= stream_id;
				emptyBufList.bitsBuf[0].codecType		= VCODEC_TYPE_H264;
				emptyBufList.bitsBuf[0].filledBufSize	= idx->dwChunkLength;
				emptyBufList.bitsBuf[0].frameWidth		= PB_MAX_WIDTH;
				emptyBufList.bitsBuf[0].frameHeight		= PB_MAX_HEIGHT;
				fread(emptyBufList.bitsBuf[0].bufVirtAddr, idx->dwChunkLength, 1, iavi.pFile);

				Vdec_putBitstreamBuffer(&emptyBufList);
			}
			else
			{
				dprintf("skip buf\n");
				fseek(iavi.pFile, idx->dwChunkLength, SEEK_CUR);
			}
		}
	}

pbv_exit:

	if(iavi.idx_entry) {
		free(iavi.idx_entry);
	}

	if(iavi.pFile) {
		fclose(iavi.pFile);
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    app playback start/stop function
* @section  [desc]
*****************************************************************************/
int app_pbk_start(char *file_path, int num_ch)
{
	app_thr_obj *tObj;

	//# static config clear
	memset((void *)ipbk, 0x0, sizeof(app_pbk_t));

	ipbk->num_ch = num_ch;

	//#--- create thread
	tObj = &ipbk->vObj;
	if(thread_create(tObj, THR_pbv, APP_THREAD_PRI, file_path) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

int app_pbk_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop thread
	tObj = &ipbk->vObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);

	return SOK;
}

void app_pbk_ctrl(int cmd)
{
	event_send(&ipbk->vObj, cmd, 0, 0);
}

/*****************************************************************************
* @brief    jpeg decoder function
* @section  [desc]
*****************************************************************************/
int app_img_view(char *file_path)
{
	VCODEC_BITSBUF_LIST_S emptyBufList;
    VDEC_BUF_REQUEST_S reqInfo;
	UInt32 bitBufSize;

	FILE *fd;
	JpegFile head;

	aprintf("start...\n");

	fd = fopen(file_path, "rb");
	if(fd == NULL) {
		eprintf("fopen() Fail (%s)!! \n", file_path);
		return EFAIL;
	}

	fread(&head, sizeof(JpegFile), 1, fd);
	//dprintf("0x%x, w:%d, h:%d\n", BYTE2INT(head.mark) , BYTE2INT(head.wi), BYTE2INT(head.he));
	if(0xFFD8 != BYTE2INT(head.mark)) {
		eprintf("Invalid jpeg header!! \n");
		return EFAIL;
	}
	if(BYTE2INT(head.wi)==0 || BYTE2INT(head.he) ==0) {
		eprintf("Invalid image size!! \n");
		return EFAIL;
	}
	fseek(fd, 0, SEEK_SET);

	fseek (fd , 0 , SEEK_END);
    bitBufSize = ftell (fd);
    rewind (fd);
    //dprintf("bitBufSize %d(0x%x)\n", bitBufSize, bitBufSize);

	{
		emptyBufList.numBufs = 0;
		reqInfo.numBufs = 1;

		reqInfo.minBufSize[0] = bitBufSize;
		Vdec_requestBitstreamBuffer(&reqInfo, &emptyBufList, 0);
		if(emptyBufList.numBufs > 0)
		{
			emptyBufList.bitsBuf[0].chnId			= 1;	//# image channel
			emptyBufList.bitsBuf[0].codecType		= IVIDEO_MJPEG;
			emptyBufList.bitsBuf[0].filledBufSize	= bitBufSize;
			fread(emptyBufList.bitsBuf[0].bufVirtAddr, 1, bitBufSize, fd);
		}

		if(emptyBufList.numBufs > 0) {
			Vdec_putBitstreamBuffer(&emptyBufList);
		}
	}

	if(fd != NULL) {
		fclose(fd);
	}

	aprintf("...done!\n");

	return 0;
}

/*****************************************************************************
* @brief    app playback start/stop function
* @section  [desc]
*****************************************************************************/
int app_dec_start(void)
{
	int ret=SOK;
	VSYS_PARAMS_S   vsysParams;
	VDEC_PARAMS_S   vdecParams;
	VDIS_PARAMS_S   vdisParams;

	dprintf("start ...\n");

	//#--- init params
	Vsys_params_init(&vsysParams);
	Vdec_params_init(&vdecParams);
	Vdis_params_init(&vdisParams);

	//#--- init module
	vsysParams.systemUseCase	= VSYS_USECASE_DECODE;
	vsysParams.enableMjpeg		= iapp->en_jpg;
	vsysParams.numChs			= 1;

	vdecParams.numChn = vsysParams.numChs;
	vdecParams.decChannelParams[0].maxVideoWidth = PB_MAX_WIDTH;	//# video
	vdecParams.decChannelParams[0].maxVideoHeight = PB_MAX_HEIGHT;
	vdecParams.decChannelParams[1].maxVideoWidth = PB_MAX_WIDTH;	//# mjpeg
	vdecParams.decChannelParams[1].maxVideoHeight = PB_MAX_HEIGHT;

	Vsys_init(&vsysParams);
	Vdec_init(&vdecParams);
	Vdis_init(&vdisParams);

	//#--- start link
	Vsys_create();
	Vdec_start();
	Vdis_start();

	dprintf("... done!\n");

	return ret;
}

int app_dec_stop(void)
{
	int ret=SOK;

	//#--- stop link
	Vdis_stop();
	Vdec_stop();
	Vsys_delete();

	//#--- exit module
	Vdis_exit();
	Vdec_exit();
	Vsys_exit();

	dprintf("... done!\n");

	return ret;
}

/*****************************************************************************
* @brief    playback run menu
* @section  [desc]
*****************************************************************************/
const char menu_pbk_run[] = {
	"\r\n -------------"
	"\r\n PBK run Menu"
	"\r\n -------------"
	"\r\n 0: stop"
	"\r\n%s1: PLAY"
	"\r\n%s2: PAUSE"
	"\r\n%s3: Fast Forward"
	"\r\n%s4: Fast Rewind"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_pbk_run(int type)
{
	int done=0;
	char cmd=0;
	int ch, ste_play=0;

	if(type == 1) {		//# image (swms ch1)
		ch = 1;
	} else {			//# video (swms ch0)
		ch = 0;
		ste_play=0x1;
	}

	ctrl_swms_set(iapp->disp_dev, 1, ch);
	app_msleep(500);	//# wait playback start
	gui_draw_clear();

	while (!done)
	{
		printf(menu_pbk_run,
			(ste_play & 0x1)?"*":" ", (ste_play & 0x2)?"*":" ",
			(ste_play & 0x4)?"*":" ", (ste_play & 0x8)?"*":" "
		);
		cmd = menu_get_cmd();

		if(type) {		//# when image view
			if(cmd == '0') {
				done = 1;
			}
			continue;
		}

		switch(cmd)
		{
			case '0':
				app_pbk_ctrl(APP_CMD_EXIT);
				app_msleep(500);	//# wait playback stop
				done = 1;
				break;
			case '1':		//# play
				if(!(ste_play & 0x1)) {
					app_pbk_ctrl(APP_PB_PLAY);
					ste_play=0x1;
				}
				break;
			case '2':		//# pause
				if(!(ste_play & 0x2)) {
					app_pbk_ctrl(APP_PB_PAUSE);
					ste_play=0x2;
				}
				break;
			case '3':		//# ff
				if(!(ste_play & 0x4)) {
					app_pbk_ctrl(APP_PB_FF);
					ste_play=0x4;
				}
				break;
			case '4':		//# fr
				if(!(ste_play & 0x8)) {
					app_pbk_ctrl(APP_PB_FR);
					ste_play=0x8;
				}
				break;
			default:
				break;
		}
	}

	gui_draw_logo();

	return 0;
}

/*****************************************************************************
* @brief    playback demo function
* @section  [desc]
*****************************************************************************/
const char menu_pbk[] = {
	"\r\n ================"
	"\r\n PBK Menu"
	"\r\n ================"
	"\r\n 0: exit"
	"\r\n 1: list & start"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_pbk(void)
{
	int done=0;
	char cmd=0;

	flist_t *flist;
	int i, idx, max_file;

	app_dec_start();

	//# create file list
	flist = disk_flist_create(DIR_REC, "*.*", SORT_NEW_FIRST);

	max_file = flist->cnt;
	while (!done)
	{
		printf(menu_pbk);
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
			{
				if(!flist->cnt) {
					eprintf("no exist file (%s)\n", DIR_REC);
					break;
				}

				printf(" --- playfile list (%s) -----------\n", DIR_REC);
				for(i=0; i<flist->cnt; i++) {
					printf(" [%3d] %s\n", i, flist->f[i].name);
				}
				printf(" ---------------------------------------\n\n");

				printf(" file idx? (0~%d) : ", max_file-1);
				idx = menu_get_data();
				if(idx > max_file-1) {
					eprintf("invalid idx %d\n", idx);
					break;
				}

				if(strstr(flist->f[idx].name, "avi"))
				{
					app_pbk_start(flist->f[idx].path, 1);
					test_pbk_run(0);
				}
				else if(strstr(flist->f[idx].name, "jpeg"))
				{
					if(iapp->en_jpg) {
						app_img_view(flist->f[idx].path);
						test_pbk_run(1);
					}
				} else {
					eprintf("invalid file (%s)\n", flist->f[idx].name);
				}

				break;
			}
		}
	}

	disk_flist_delete(flist);
	app_dec_stop();

	app_msleep(200);	//# wait decoder stop

	return 0;
}
