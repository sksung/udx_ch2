/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_cap.c
 * @brief	app video capture thread
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <mcfw/src_linux/mcfw_api/ti_vsys_priv.h>
#include "ti_vsys.h"
#include "ti_vcam.h"
#include "ti_vcap.h"
#include "ti_venc.h"
#include "ti_vdis.h"
#include "ti_mjpeg.h"

#include "app_comm.h"
#include "app_gmem.h"
#include "app_main.h"
#include "app_ctrl.h"
#include "app_rec.h"
#include "gui_main.h"
#include "app_cap.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
typedef struct {
	app_thr_obj vObj;		//# video capture(ipcbits) thread
	app_thr_obj aObj;		//# audio capture thread

	g_mem_info_t *imem;

	int en_audcap;
} app_cap_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_cap_t cap_obj;
static app_cap_t *icap=&cap_obj;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    video capture(ipcBits) function
* @section  [desc]
*****************************************************************************/
/*----------------------------------------------------------------------------
 ipcBits in callback function
-----------------------------------------------------------------------------*/
void ipc_bits_fxn(void)
{
	event_send(&icap->vObj, APP_CMD_NOTY, 0, 0);
}

/*----------------------------------------------------------------------------
 printf frame info
-----------------------------------------------------------------------------*/
static void frame_info_print(VCODEC_BITSBUF_S *pFullBuf)
{
	#if 0	//# h264 info
	if(pFullBuf->codecType == (VCODEC_TYPE_E)IVIDEO_H264HP) {
		if(pFullBuf->chnId == 0)
		{
			if(pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME)
			{
				dprintf("CH%d, 0x%x, %6d, %s, (%lld)\n", pFullBuf->chnId,
					(unsigned int)pFullBuf->bufVirtAddr, pFullBuf->filledBufSize,
					(pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME) ? "I":"P",
					(UInt_64)((UInt_64)pFullBuf->upperTimeStamp<<32|pFullBuf->lowerTimeStamp));
			}
		}
	}
	#endif

	#if 0	//# mjpeg info
	if(pFullBuf->codecType == (VCODEC_TYPE_E)0) {
		if(pFullBuf->chnId == 2)
		{
			if(pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME)
			{
				dprintf("CH%d, type %d, 0x%x, %6d, %s, (%lld)\n", pFullBuf->chnId, pFullBuf->codecType,
					(unsigned int)pFullBuf->bufVirtAddr, pFullBuf->filledBufSize,
					(pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME) ? "I":"P",
					(UInt_64)((UInt_64)pFullBuf->upperTimeStamp<<32|pFullBuf->lowerTimeStamp));
			}
		}
	}
	#endif
}

/*----------------------------------------------------------------------------
 video capture[ipcBits] process function
-----------------------------------------------------------------------------*/
static void proc_vid_cap(void)
{
	VCODEC_BITSBUF_LIST_S fullBufList;
	VCODEC_BITSBUF_S *pFullBuf;
	int i, idx;
	stream_info_t *ifr;
	char *addr;
	Uint64 captime;

	Venc_getBitstreamBuffer(&fullBufList, 0);

	for (i = 0; i < fullBufList.numBufs; i++)
	{
		pFullBuf = &fullBufList.bitsBuf[i];
		//frame_info_print(pFullBuf);

		if(pFullBuf->codecType == (VCODEC_TYPE_E)IVIDEO_H264HP)
		{
			if(pFullBuf->chnId < iapp->num_ch)
			{
				addr = g_mem_get_addr(pFullBuf->filledBufSize, &idx);
				if(addr == NULL) {
					OSA_waitMsecs(5);
					continue;
				}

				ifr = &icap->imem->ifr[idx];
				ifr->d_type = CAP_TYPE_VIDEO;
				ifr->ch = pFullBuf->chnId;
				ifr->addr = addr;
				ifr->offset = (int)addr - g_mem_get_virtaddr();
				ifr->b_size = pFullBuf->filledBufSize;
				ifr->frm_wi = pFullBuf->frameWidth;
				ifr->frm_he = pFullBuf->frameHeight;
				ifr->frm_rate = iapp->ich[ifr->ch].fr;
				ifr->is_key = (pFullBuf->frameType == VCODEC_FRAME_TYPE_I_FRAME) ? 1:0;

				captime = (Uint64)((Uint64)pFullBuf->upperTimeStamp<<32|pFullBuf->lowerTimeStamp);
				ifr->t_sec = (Uint32)(captime/1000);
				ifr->t_msec = (Uint32)(captime%1000);

				//dprintf("--- CH%d(%d) %dx%d\n", ifr->ch, ifr->is_key, ifr->frm_wi, ifr->frm_he);

				app_memcpy(addr, (char*)pFullBuf->bufVirtAddr, ifr->b_size);

				#if 0
				//# rtsp_tx
				if(iapp->en_rtsp) {
                   	app_rtsptx_write(ifr->addr, ifr->offset, ifr->b_size, ifr->is_key?FTYPE_VID_I:FTYPE_VID_P,
                   		ifr->ch?STYPE_VID_CH2:STYPE_VID_CH1, captime);
                }
                #endif
			}
		}

		if(iapp->snapshoot)
		{
			int ch;
			ch = pFullBuf->chnId - iapp->num_ch;
			if(ch == (iapp->snapshoot-1))
			{
				if(pFullBuf->codecType==(VCODEC_TYPE_E)IVIDEO_MJPEG || pFullBuf->codecType==(VCODEC_TYPE_E)0)
				{
					captime = (Uint64)((Uint64)pFullBuf->upperTimeStamp<<32|pFullBuf->lowerTimeStamp);
					app_save_jpeg(ch, pFullBuf->bufVirtAddr, pFullBuf->filledBufSize, (Uint32)(captime/1000));
					iapp->snapshoot = 0;
				}
			}
		}
	}

	Venc_releaseBitstreamBuffer(&fullBufList);
}

/*----------------------------------------------------------------------------
 video capture[ipcBits] thread function
-----------------------------------------------------------------------------*/
static void *THR_vid_cap(void *prm)
{
	app_thr_obj *tObj = &icap->vObj;
	int cmd, exit=0;

	aprintf("enter...\n");
	tObj->active = 1;

	while(!exit)
	{
		//# wait cmd or ipcBitsIn event(callback)
		cmd = event_wait(tObj);
		if(cmd == APP_CMD_EXIT) {
			break;
		}

		//# process full buffers
		proc_vid_cap();
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*----------------------------------------------------------------------------
 video/audio capture start function
-----------------------------------------------------------------------------*/
static int cap_vid_start(void)
{
	app_thr_obj *tObj;
	VENC_CALLBACK_S callback;

	icap->imem = (g_mem_info_t *)g_mem_reset();

	//# Register call back with encoder
	callback.newDataAvailableCb = (VENC_CALLBACK_NEW_DATA)ipc_bits_fxn;
	Venc_registerCallback(&callback, NULL);

	//#--- create video capture thread
	tObj = &icap->vObj;
	if(thread_create(tObj, THR_vid_cap, APP_THREAD_PRI-1, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	dprintf("... done!\n");

	return SOK;
}

static void cap_vid_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop video capture thread
	tObj = &icap->vObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);

	//dprintf("... done!\n");
}

/*----------------------------------------------------------------------------
 Sensor init function
-----------------------------------------------------------------------------*/
static int cap_sensor_int(void)
{
	int i;

	//# sensor control
	for(i=0; i<iapp->num_ch; i++) {
		ctrl_vid_frame(i, iapp->ich[i].fr);
	}

	return 0;
}

/*----------------------------------------------------------------------------
 SWOSD init function
-----------------------------------------------------------------------------*/
static void cap_swosd_init(void)
{
	int i;
	Vsys_swOsdPrm swosdGuiPrm;

	#if 1		//# date,time (default enable)
	for(i=0; i<iapp->num_ch; i++) {
		swosdGuiPrm.streamId = i;	//# ch
		swosdGuiPrm.enable = DIS;
		Vsys_setSwOsdPrm(VSYS_SWOSD_EN_DATETIME, &swosdGuiPrm);
	}
	#endif

	#if 1		//# user string
	swosdGuiPrm.streamId = 0;
	swosdGuiPrm.enable = ENA;
	strcpy(swosdGuiPrm.usrString, "UDX");
	Vsys_setSwOsdPrm(VSYS_SWOSD_USERSTR, &swosdGuiPrm);
	#endif
}

/*----------------------------------------------------------------------------
 encoder channel init function
-----------------------------------------------------------------------------*/
static int cap_enc_init(VENC_PARAMS_S *vencParams)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };
	int i, j;

	for(i=0; i<(iapp->num_ch+iapp->en_dual); i++)
	{
		//# enc motion enable
		vencParams->encChannelParams[i].enableAnalyticinfo = 1;

		params.frameRate = iapp->ich[i].fr;
		params.inputFrameRate = params.frameRate;
		params.targetBitRate = iapp->ich[i].br * 1000 * 1000;

		Venc_params_set(vencParams, i, &params, VENC_ALL);
	}

	if(iapp->en_jpg)
	{
		for(j=0; j<(iapp->num_ch+iapp->en_dual); j++) {
			params.frameRate = 1;
			params.inputFrameRate = iapp->ich[j].fr;

			Venc_params_set(vencParams, i++, &params, VENC_ALL);
		}
	}

	return SOK;
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

static void cap_enc_late_init(void)
{
	int i, j;

	for(i=0; i<(iapp->num_ch+iapp->en_dual); i++)
	{
		//# rate control, all sensors are same
		ctrl_vid_rate(i, iapp->ich[i].rc, iapp->ich[i].br);

		//# apply motion
		if(iapp->ich[i].mot) {
			ctrl_vid_motion(i, Q_MD);
		}
	}

	//# set jpeg quality
	if(iapp->en_jpg)
	{
		for(j=0; j<(iapp->num_ch+iapp->en_dual); j++) {
			cap_jpeg_quality(i++, 60);	//# default 60%
		}
	}
}

/*****************************************************************************
* @brief    app capture start/stop function
* @section  [desc]
*****************************************************************************/
int app_cap_start(int idx)
{
	int ret, i;

	VSYS_PARAMS_S   vsysParams;
	VCAP_PARAMS_S   vcapParams;
	VENC_PARAMS_S   vencParams;
	VDIS_PARAMS_S   vdisParams;

	if(iapp->ste.b.cap)		//# already start
		return SOK;

	dprintf("start...(demo idx %d)\n", idx);

	//#--- init params
	Vsys_params_init(&vsysParams);
	Vcap_params_init(&vcapParams);
	Venc_params_init(&vencParams);
	Vdis_params_init(&vdisParams);

	//#--- init module
	vsysParams.enableEncode	= iapp->en_enc;
	vsysParams.enableMjpeg	= iapp->en_jpg;
	vsysParams.enableDual	= iapp->en_dual;

	vsysParams.systemUseCase = VSYS_USECASE_CAPTURE;
	vsysParams.captMode = CAPT_MODE_720P;
	vsysParams.decoderHD = SYSTEM_DEVICE_VID_DEC_PH3100K_DRV;
	vsysParams.serdesEQ[0] = SERDES_EQ_LV4;
	vsysParams.serdesEQ[1] = SERDES_EQ_LV4;

	if(idx == 1) {		//# 720p
		vsysParams.captMode = CAPT_MODE_720P;
		vsysParams.numChs = 2;
		if(iapp->en_dual) {
			vsysParams.numChs = 1;
		}

		for(i=0; i<vsysParams.numChs; i++) {
			iapp->ich[i].wi = 1280;
			iapp->ich[i].he = 720;
			iapp->ich[i].fr = iapp->is_pal?25:30;
			iapp->ich[i].br = 5;
			iapp->ich[i].rc = RATE_CTRL_CBR;
		}
		if(iapp->en_dual) {		//# second stream
			iapp->ich[i].wi = 640;
			iapp->ich[i].he = 480;
			iapp->ich[i].fr = iapp->is_pal?25:30;
			iapp->ich[i].br = 2;
			iapp->ich[i].rc = RATE_CTRL_CBR;
		}
	}
	else {
		eprintf("invaild demo idx %d\n", idx);
		return -1;
	}

	iapp->num_ch = vsysParams.numChs;

	cap_enc_init(&vencParams);

	Vsys_init(&vsysParams);
	Vcap_init(&vcapParams);
	Venc_init(&vencParams);
	Vdis_init(&vdisParams);

	if(iapp->en_enc) {
		ret = cap_vid_start();
		if(ret < 0)
			return ret;
	}

	//#--- start link
	Vsys_create();
	Vsys_datetime_init();	//# m3 Date/Time init

	Vcam_start();
	Vcap_start();
	Vdis_start();
	if(iapp->en_enc) {
		Venc_start();
	}

	//#--- late init
	cap_sensor_int();
	cap_swosd_init();
	cap_enc_late_init();

	iapp->ste.b.cap = 1;

	dprintf("... done!\n");

	return SOK;
}

int app_cap_stop(void)
{
	if(!iapp->ste.b.cap)		//# already stop
		return EINVALID;

	dprintf("start ...\n");
	iapp->ste.b.cap = 0;

	//#--- stop link
	if(iapp->en_enc) {
		Venc_stop();
	}
	Vdis_stop();
	Vcap_stop();

	cap_vid_stop();

	Vsys_delete();

	//#--- exit module
	Vdis_exit();
	Venc_exit();
	Vcap_exit();
	Vsys_exit();

	dprintf("... done!\n");

	return SOK;
}
