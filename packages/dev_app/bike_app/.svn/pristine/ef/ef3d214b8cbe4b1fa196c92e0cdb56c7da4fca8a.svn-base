/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
/**
 * @file    app_cap.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 *     - 2013.08.20 : Modified by sksung
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
 -----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cmem.h>

#include <mcfw/src_linux/mcfw_api/ti_vsys_priv.h>
#include "ti_vsys.h"
#include "ti_vcap.h"
#include "ti_venc.h"
#include "ti_vdis.h"
#include "ti_mjpeg.h"

#include "udavi.h"

#include "ucx_main.h"
#include "app_gui.h"
#include "app_cap.h"
#include "app_dev.h"
#include "app_set.h"
#include "app_ctrl.h"
#include "app_util.h"
#include "app_snd.h"
#include "app_dev.h"
#include "app_rec.h"
#include "app_file.h"

#include "app_rtsptx.h"
#include "dev_gpio.h"
#include "dev_micom.h"

/*----------------------------------------------------------------------------
 Definitions and macro
 -----------------------------------------------------------------------------*/
#define EN_CMEM			1

#define G_MEM_SIZE		0x2800000
#define G_MEM_INFO_SIZE	0x0100000
#define MAX_BUF_OFFSET	700//500

typedef struct {
	int s_addr;
	int c_addr;
	int size;
} g_mem_t;

typedef struct {
	app_thr_obj *cptObj;	//# video capture thread (ipcbits)
	app_thr_obj *audObj;	//# audio thread
	OSA_MutexHndl mutex;
} app_cap_t;

/*----------------------------------------------------------------------------
 Declares variables
 -----------------------------------------------------------------------------*/
static app_cap_t t_cap;
static app_cap_t *icap;

static g_mem_t		gmem;
static g_mem_info_t	*imem;

static app_meta_t gmeta;

//#define VIDEO_DUMP

#ifdef VIDEO_DUMP
#define OPEN_CREATE(fd, path) (NULL != (fd = fopen(path, "wb+")))
#define WRITE_PTSZ(fd, pt, sz)   ( sz == fwrite(pt, 1, sz, fd))
#define CLOSE_BKT(fd) fclose(fd)
int dumpCnt;
char path_cap[CHAR_32];
FILE *fd_cap;
#endif
/*----------------------------------------------------------------------------
 Declares a function prototype
 -----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
 -----------------------------------------------------------------------------*/
int init_g_mem(void)
{
#if	EN_CMEM
    CMEM_AllocParams  prm;

    prm.type      = CMEM_HEAP;
    prm.flags     = CMEM_CACHED;//CMEM_CACHED;//CMEM_NONCACHED;
    prm.alignment = 32;

	CMEM_init();

	gmem.s_addr = (int)CMEM_alloc(G_MEM_SIZE, &prm);
	dprintf("--- %s: 0x%x(phy: 0x%x), size:0x%x\n", __func__, gmem.s_addr, (int)CMEM_getPhys((void *)gmem.s_addr), G_MEM_SIZE);
#else
	gmem.s_addr = (int)app_malloc(G_MEM_SIZE);
	dprintf("--- %s: 0x%x, size:0x%x\n", __func__, gmem.s_addr, G_MEM_SIZE);
#endif

	imem = (g_mem_info_t *)gmem.s_addr;

	gmem.c_addr = gmem.s_addr+G_MEM_INFO_SIZE;

	imem->max_num = 0;
	imem->cur_num = -1;
	imem->read_num = 0;
	//imem->num_ch = app_cfg->num_ch;

	return 0;
}

static void reset_g_mem(void)
{
	gmem.c_addr = gmem.s_addr+G_MEM_INFO_SIZE;

    memset(imem->ifr, 0, MAX_STREAM_NUM);
	imem->max_num = 0;
	imem->cur_num = -1;
	imem->read_num = 0;
}

void exit_g_mem(void)
{
#if EN_CMEM
	CMEM_AllocParams  prm;

    prm.type      = CMEM_HEAP;
    prm.flags     = 0;
    prm.alignment = 0;

    CMEM_free((void *)gmem.s_addr, &prm);

    CMEM_exit();
#else
    app_mfree((void *)gmem.s_addr);
#endif
}

static void *get_g_mem_addr(int size, int *idx)
{
	char *addr = NULL;
	int wr_offset=0;

	OSA_mutexLock(&icap->mutex);

	if(app_cfg->state.rec && !app_cfg->state.park)		//# protect overflow
	{
		if(imem->read_num > imem->cur_num)
			wr_offset = (imem->max_num - imem->read_num) + imem->cur_num;
		else
			wr_offset = imem->cur_num - imem->read_num;

		if(wr_offset > MAX_BUF_OFFSET) {
			dprintf("%s: max:%d, read:%d, cur:%d--- skip write!\n", __func__, imem->max_num, imem->read_num, imem->cur_num);
			OSA_mutexUnlock(&icap->mutex);
			return NULL;
		}
	}

	//# align 32bit
	if(size%0x20)
		size = (size + 0x20) & (~0x1f);

	if( (((int)gmem.s_addr+G_MEM_SIZE-(int)gmem.c_addr) < size)
			|| (imem->cur_num > (MAX_STREAM_NUM-2)) ) {
		gmem.c_addr = gmem.s_addr+G_MEM_INFO_SIZE;
		imem->ifr[imem->cur_num].end = 1;
		imem->max_num = imem->cur_num+1;
		imem->cur_num = 0;
	} else {
		imem->cur_num++;
	}

	imem->ifr[imem->cur_num].end = 0;

	addr = (char *)gmem.c_addr;
	gmem.c_addr += size;

#if 0
	if(imem->cur_num == 0)
	{
#if	EN_CMEM
		dprintf("%s: idx(%3d/%3d), addr(0x%x, phy:0x%x), size(%d)\n",
				__func__, imem->cur_num, imem->max_num, addr, (int)CMEM_getPhys((void *)addr), size);
#else
		dprintf("%s: idx(%3d/%3d), addr(0x%x), size(%d)\n",
				__func__, imem->cur_num, imem->max_num, addr, size);
#endif
	}
#endif

	*idx = imem->cur_num;

	OSA_mutexUnlock(&icap->mutex);

	return addr;
}

void* app_get_gmem(void)
{
	return (void *)imem;
}

int get_g_mem_phyaddr(void)
{
	return (int)CMEM_getPhys((void *)gmem.s_addr);
}

int get_g_mem_size(void)
{
	return G_MEM_SIZE;
}

/*----------------------------------------------------------------------------
 ipcBits process function
 -----------------------------------------------------------------------------*/
static void ipc_bits_process(void)
{
	VCODEC_BITSBUF_LIST_S fullBufList;
	VCODEC_BITSBUF_S *pFullBuf;
	int i, idx, meta_size=0;
	Uint64 captime;
    int ch=0;

    meta_size = sizeof(app_meta_t);
	Venc_getBitstreamBuffer(&fullBufList, 0);

	for (i = 0; i < fullBufList.numBufs; i++)
	{
		pFullBuf = &fullBufList.bitsBuf[i];
		captime = (Uint64)((Uint64)pFullBuf->upperTimeStamp<<32|pFullBuf->lowerTimeStamp);

		app_cfg->wd_flags |= WD_ENC;

//        if(app_cfg->state.rec)
		{
			stream_info_t *ifr;
			char *addr;

			if(pFullBuf->codecType == IVIDEO_H264HP && pFullBuf->chnId < ENC_D1_CHANNEL)
			{
				addr = get_g_mem_addr(pFullBuf->filledBufSize, &idx);
				if(addr == NULL){
                    OSA_waitMsecs(5);
					continue;
                }

				ifr = &imem->ifr[idx];
				ifr->d_type = DATA_TYPE_VIDEO_MAIN;
				ifr->ch 	= pFullBuf->chnId;
                if(app_cfg->num_ch == 1){
                    ifr->ch = 0;
                }
				ifr->buf 	= addr;
				ifr->offset = (int)ifr->buf - gmem.s_addr;
				ifr->b_size = pFullBuf->filledBufSize;
				ifr->img_w 	= pFullBuf->frameWidth;
				ifr->img_h 	= pFullBuf->frameHeight;
				ifr->is_key = (pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME) ? 1:0;
				ifr->t_sec 	= (Uint32)(captime/1000);
				ifr->t_msec = (Uint32)(captime%1000);
				app_memcpy(addr, (char*)pFullBuf->bufVirtAddr, ifr->b_size);

				//dprintf("CH%d %dx%d\n", pFullBuf->chnId, pFullBuf->frameWidth, pFullBuf->frameHeight);

#ifdef VIDEO_DUMP
                if(dumpCnt < 100){
        		WRITE_PTSZ(fd_cap, ifr->buf, ifr->b_size);
        		dumpCnt++;
            	}

            	if(dumpCnt == 100){
            		CLOSE_BKT(fd_cap);
            		dumpCnt++;
            		printf("@@@@@@ Writer Video Dump Closed!! path:%s\n", path_cap);
            	}
#endif

				if(app_cfg->state.rtsptx)
				{
					//# rtsp_tx
					if(app_cfg->state.wifi && pFullBuf->codecType == IVIDEO_H264HP){
					    app_rtsptx_write((void *)ifr->buf, ifr->offset, ifr->b_size,
			   			       			ifr->is_key?FTYPE_VID_I:FTYPE_VID_P, (ifr->ch==1)?STYPE_VID_CH2:STYPE_VID_CH1, captime);
					}
				}

                //#--- META DATA (GPS+G_SENSOR)
                if(app_cfg->num_ch == MAX_CH_NUM)
                    ch = 0;
                else
                    ch = pFullBuf->chnId;

                if(pFullBuf->chnId == ch && pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME)
                {
                    memset(&gmeta, 0, meta_size);

                    addr = get_g_mem_addr(meta_size, &idx);
                    if(addr != NULL)
                    {
                        ifr = &imem->ifr[idx];
                        memset(ifr, 0, sizeof(stream_info_t));

                        ifr->d_type = DATA_TYPE_META;
                        ifr->ch 	= 0;
                        ifr->buf 	= addr;
						ifr->offset = (int)ifr->buf - gmem.s_addr;
                        ifr->b_size = meta_size;
                        ifr->t_sec 	= (Uint32)(captime/1000);
                        ifr->t_msec = (Uint32)(captime%1000);

                        app_dev_get_gps((void*)&gmeta.gps);

                        app_memcpy(addr, (char*)&gmeta, ifr->b_size);
                    }
                }
			}
            /*else if(pFullBuf->codecType == IVIDEO_MJPEG || pFullBuf->codecType == 0)
            {
                if(app_cfg->state.rec)
                    app_save_jpeg(pFullBuf->chnId, pFullBuf->bufVirtAddr, pFullBuf->filledBufSize, (Uint32)(captime/1000));
			}*/            
		}
	}

	if( app_cfg->state.rec && !app_cfg->state.mmc_sz )
		app_rec_notify();

	Venc_releaseBitstreamBuffer(&fullBufList);
}

/*----------------------------------------------------------------------------
 ipcBits process function
-----------------------------------------------------------------------------*/
static int aud_capt_process(unsigned char *buf)
{
	char *addr;
	stream_info_t *ifr;
	int r_size=0, idx;

	r_size = app_aud_capt(buf);
	if(r_size <= 0){
		eprintf("audio read zero!!\n");
		return -1;
	}


	//# if num_ch has zero, all camera is no-signal and video gmem not run
	//# so, audio gmem stop too.
	if(app_cfg->num_ch > 0)
	{
		addr = get_g_mem_addr(r_size, &idx);
		if(addr == NULL){
			printf("audio g_mem is NULL!!\n");
			return -1;
		}

		ifr = &imem->ifr[idx];
		ifr->d_type = DATA_TYPE_AUDIO;
		ifr->ch = 0;
		ifr->buf = addr;
		ifr->b_size = r_size;
		
		app_memcpy(addr, buf, r_size);
	}

	return 0;
}

/*****************************************************************************
* @brief    ipcBits main function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void *ipc_bits_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int cmd, exit=0;

	printf(" [task] %s start\n", __func__);
	tObj->done = 0;
	imem->process = 1;

    #ifdef VIDEO_DUMP
    sprintf(path_cap, "/mmc/encVideo");
    printf("\n path_cap = %s \n", path_cap);
	OPEN_CREATE(fd_cap, path_cap);
    #endif

	while(!exit)
	{
		//# wait cmd or ipcBitsIn event(callback)
		cmd = event_wait(tObj);
		if(cmd == UBX_CMD_STOP) {
			break;
		}

		//# process full buffers
		ipc_bits_process();
	}

	imem->process = 0;
	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*----------------------------------------------------------------------------
 ipcBits callback function
-----------------------------------------------------------------------------*/
void ipc_bits_in_fxn(void)
{
	event_send(icap->cptObj, UBX_CMD_NOTY, 0, 0);
}


/*****************************************************************************
* @brief    audio capture main function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void *aud_capt_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int cmd, exit=0;
	Uint8 *enc_buf;
	int buf_size;

	printf(" [task] %s start\n", __func__);
	tObj->done = 0;
	tObj->cmd = -1;

	buf_size = app_aud_capt_init(125);	//ms
	if(buf_size <= 0 || buf_size > MAX_AENC_BUF_SIZE){
		eprintf("aud capture init failed!!\n");
		return NULL;
	}

	enc_buf = app_malloc(buf_size);
	if(enc_buf == NULL) {
		eprintf("audio buffer malloc fail\n");
		app_aud_capt_exit();
		return NULL;
	}

	if(!app_set->aud.mic_on)
		tObj->cmd = UBX_CMD_PAUSE;

	while(!exit)
	{
		//# wait cmd
		cmd = tObj->cmd;
		if(cmd == UBX_CMD_STOP) {
			break;
		} else if(cmd == UBX_CMD_PAUSE) {
			cmd = event_wait(tObj);
		}

		//# process audio capture
		if(aud_capt_process(enc_buf) < 0) {
			OSA_waitMsecs(125);
		}
	}

	app_mfree(enc_buf);
	app_aud_capt_exit();

	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}

void app_aud_capt_ctrl(int enable)
{
	if(enable)
	{
		if(app_set->aud.mic_on)
			return;

		event_send(icap->audObj, UBX_CMD_START, 0, 0);
		app_set->aud.mic_on	= 1;
	}
	else
	{
		if(!app_set->aud.mic_on)
			return;

		event_send(icap->audObj, UBX_CMD_PAUSE, 0, 0);
		app_set->aud.mic_on	= 0;
	}
}

/*****************************************************************************
 * @brief	video/audio init/exit function
 * @section	DESC Description
 *	- desc
 *****************************************************************************/
static int va_capture_init(void)
{
	app_thr_obj *tObj;
	VENC_CALLBACK_S callback;

	icap = &t_cap;
	memset(icap, 0, sizeof(t_cap));
	OSA_mutexCreate(&icap->mutex);

	//# Register call back with encoder
	callback.newDataAvailableCb = (VENC_CALLBACK_NEW_DATA)ipc_bits_in_fxn;
	Venc_registerCallback(&callback, NULL);

	//#--- create video capture thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj == NULL) {
		eprintf("thread obj malloc fail\n");
		return -1;
	}

	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	OSA_thrCreate(&tObj->thr, ipc_bits_main, FXN_TSK_PRI, 0, tObj);
	icap->cptObj = tObj;

	//#--- create audio capture thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj == NULL) {
		eprintf("thread obj malloc fail\n");
		return -1;
	}

	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	OSA_thrCreate(&tObj->thr, aud_capt_main, FXN_TSK_PRI, 0, tObj);
	icap->audObj = tObj;

	return 0;
}

static void va_capture_exit(void)
{
	app_thr_obj *tObj;

	//#--- recording stop
	app_rec_stop();

	//#--- audio capture thread stop
	tObj = icap->audObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}

	//#--- video capture thread stop
	tObj = icap->cptObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}

    OSA_mutexDelete(&icap->mutex);

	//exit_g_mem();

	icap = NULL;
	printf(" [app] %s done!\n", __func__);
}

/*----------------------------------------------------------------------------
 encoder channel init function
 -----------------------------------------------------------------------------*/
static void capt_enc_init(VENC_PARAMS_S *pContext)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };
	int i;

	for(i=0; i<MAX_CH_NUM; i++)
	{
		//# enc motion enable
		pContext->encChannelParams[i].enableAnalyticinfo = 1;
		params.frameRate            = app_cfg->ifrm[i].fr;
		params.inputFrameRate       = DEFAULT_FPS;
		params.targetBitRate        = app_cfg->ifrm[i].br * 1000;

		Venc_params_set(pContext, i, &params, VENC_ALL);

		if(app_cfg->en_jpg)
		{
			params.frameRate = JPEG_FPS;
			Venc_params_set(pContext, i+MAX_CH_NUM, &params, VENC_ALL);
		}		
	}
}

static void cap_jpeg_quality(int ch, int value)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

	params.qpMin 	= 1;
	params.qpMax 	= 100;
	params.qpInit	= value;

	Venc_setDynamicParam(ch, 0, &params, VENC_QPVAL_I);
	//dprintf("ch %d, value %d\n", ch, value);
}


static void capt_enc_late_init(void)
{
	int i;

	for(i=0; i<MAX_CH_NUM; i++)
	{
		//#--- apply rate control
		ctrl_enc_rc_set(i, app_set->ch[i].rate_ctrl, app_cfg->ifrm[i].br);

		//#--- apply motion
		if(app_set->rec_type == REC_TYPE_MOT)
	        ctrl_enc_motion_set(i, app_set->wd.motion);
		else
			ctrl_enc_motion_set(i, 0);
		if(app_cfg->en_jpg){
			cap_jpeg_quality(i+MAX_CH_NUM, JPEG_QUALITY);
		}
	}
}

/*----------------------------------------------------------------------------
 frame init function
 -----------------------------------------------------------------------------*/
static int get_frame_size(int resol, int *wi, int *he)
{
	if(resol == RESOL_1080P) {
		*wi = 1920;
		*he = 1080;
	}
	else if(resol == RESOL_720P) {
		*wi = 1280;
		*he = 720;
	}
	else if(resol == RESOL_480P) {
		*wi = 720;
		*he = 480;
	}
	else {
		eprintf("Invaild resol param %d\n", resol);
		return -1;
	}

	return 0;
}

static int capt_param_init(VCAP_PARAMS_S *vcapParams, VENC_PARAMS_S *vencParams)
{
	int i, ret, default_fps = DEFAULT_FPS;
	int wi, he, br;
	app_ch_cfg_t* ch;

	for(i=0; i<MAX_CH_NUM; i++)
	{
		if(app_cfg->state.park)
			ch = &app_set->ch_prk[i];
		else
			ch = &app_set->ch[i];


        //# check setting param
		ret = get_frame_size(ch->resol, &wi, &he);
		if(ret < 0)
			return -1;

		//#--- apply resolution, framerate, bitrate
		app_cfg->ifrm[i].wi = wi;
		app_cfg->ifrm[i].he = he;
 		app_cfg->ifrm[i].fr = get_fps_val(ch->framerate);

		br = get_bitrate_val(ch->quality, ch->resol);
        app_cfg->ifrm[i].br = (br * app_cfg->ifrm[i].fr)/default_fps;
		//app_cfg->ifrm[i].br = (br * app_cfg->ifrm[i].fr)/DEFAULT_FPS;

		printf(" [app] (CH%d): %dx%d, fr %d, br %d\n", i, wi, he, app_cfg->ifrm[i].fr, app_cfg->ifrm[i].br);

		if(i==0) {
			//# set cap param
			vcapParams->width = wi;
			vcapParams->height = he;
		}
	}

	capt_enc_init(vencParams);

	return 0;
}

/*----------------------------------------------------------------------------
 Sensor init function
 -----------------------------------------------------------------------------*/
static int capt_sensor_int(void)
{
	int i=0, ret=0, ste=0;
    int front=0, rear=0;

	for(i=0; i<app_cfg->num_ch; i++)
	{
		ret = app_dev_hdsens_status(i);
		if(ret) {
            ctrl_hdcam_frame_set(i, DEFAULT_FPS);
			//ctrl_hdcam_frame_set(i, app_cfg->ifrm[i].fr);
		}
		else {           
			eprintf("#%d sensor disconnected!!!\n", i);
            if(i == 0){
                printf(" [%s] system starting hd detect(only rear)!!! \n", __func__);
                front = 1;
                ste = 1;
                app_cfg->layout = UBX_LAYOUT_S;
            }
            else if(i == 1){
                printf(" [%s] system starting hd detect(only front)!!! \n", __func__);
                rear = 1;
                ste = 1;
                app_cfg->layout = UBX_LAYOUT_M;
            }
		}
	}
    if(ste == 1)
        app_cfg->num_ch = 1;

    if(front == 1 && rear == 1){
        app_cfg->num_ch = 0;
        app_cfg->state.cam_buzzer = 1;
    }

	return 0;
}

/*----------------------------------------------------------------------------
 SWOSD init function
 -----------------------------------------------------------------------------*/
static void capt_swosd_init(void)
{
	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = 0;

#if 0
	strcpy((char*)swosdGuiPrm.usrString, "UCX");
	Vsys_setSwOsdPrm(VSYS_SWOSD_USERSTR, &swosdGuiPrm);
#endif
}


/*****************************************************************************
 * @brief    video capture start/stop function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int app_capt_start()
{
	VSYS_PARAMS_S   vsysParams;
	VCAP_PARAMS_S   vcapParams;
	VENC_PARAMS_S   vencParams;
	VDIS_PARAMS_S   vdisParams;
	int ret, slevel;
	char msg[CHAR_128] = {0,};

	printf(" [app] %s start\n", __func__);

	reset_g_mem();

	//# check m3vpss device
	app_cfg->layout		= UBX_LAYOUT_D;

    app_cfg->state.nokey = 1;

 	//#--- init params
	Vsys_params_init(&vsysParams);
	Vcap_params_init(&vcapParams);
	Venc_params_init(&vencParams);
	Vdis_params_init(&vdisParams);

	//#--- init module
	vsysParams.enableEncode     = app_cfg->en_enc;
	vsysParams.enableMjpeg      = app_cfg->en_jpg;

	vsysParams.systemUseCase    = VSYS_USECASE_CAPTURE;
	vsysParams.captMode         = CAPT_MODE_720P;
    vsysParams.decoderHD	 	= SYSTEM_DEVICE_VID_DEC_PH3100K_DRV;
	vsysParams.numChs			= app_cfg->num_ch;

	slevel = get_serdes_lv(app_set->sys.serdes_level);
    vsysParams.serdesEQ[0]		= slevel;
	vsysParams.serdesEQ[1]		= slevel;

	sprintf(msg, " [APP_CAP] Init Serdes level: %02d...", slevel);
	app_log_write(MSG_LOG_WRITE, msg);

	printf("==================================\n");
	printf("  %s \n", msg);
	printf("==================================\n");

	ret = capt_param_init(&vcapParams, &vencParams);
	if(ret < 0)
		return ret;

	Vsys_init(&vsysParams);
	Vcap_init(&vcapParams);
	Venc_init(&vencParams);
	Vdis_init(&vdisParams);

	ret = va_capture_init();
	if(ret < 0)
		return ret;

	//#--- start link
	Vsys_create();
	Vsys_datetime_init();	//# m3 Date/Time init

	Vcap_start();
	Venc_start();
	Vdis_start();

	capt_sensor_int();	//# sensor frame change
	capt_swosd_init();	//# swosd init
	capt_enc_late_init();

	app_gui_layout(app_cfg->layout);

	ctrl_get_hw_version(app_set->info.hw_ver);
	ctrl_hdcam_mirror(1, app_set->lcd.sub_mirror);

    ctrl_hdcam_brightness(0, app_set->cam.front_bright);
    ctrl_hdcam_brightness(1, app_set->cam.rear_bright);

	//#--- when system start or change driving mode from parking mode then gps_sync flag 1 for time sync
	if(!app_cfg->state.park)
	    app_cfg->state.tsync = 1;

    event_send(app_cfg->uObj, UBX_GUI_CAPT, 0, 0);

	//# get tv-out jack status
	if(app_tvout_status() == 0)
		ctrl_tvo_enable(0);

    app_cfg->state.cap 		= 1;
//    app_cfg->state.nokey 	= 0;

	//#--- record start
	if(!app_cfg->state.mmc_err)
	    app_rec_start();//(void *)imem);

	printf(" [app] %s done!\n", __func__);

	return 0;
}

void app_capt_stop(void)
{
	if(!app_cfg->state.cap)
		return;

// 	app_cfg->state.nokey = 1;
	app_cfg->state.cap = 0;

	ctrl_tvo_enable(1);

	//#--- stop link
	Vcap_stop();
	Venc_stop();
	Vdis_stop();

	//Vsys_delete();

	va_capture_exit();

    Vsys_delete();

	//#--- exit module
	Vdis_exit();
	Vdec_exit();
	Venc_exit();
	Vcap_exit();
	Vsys_exit();

//    app_cfg->state.nokey = 0;

	printf(" [app] %s done!\n", __func__);
}

void app_capt_buff_reset(void)
{
    reset_g_mem();
}
