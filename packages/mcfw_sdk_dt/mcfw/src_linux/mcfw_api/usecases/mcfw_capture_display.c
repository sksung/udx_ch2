/******************************************************************************
 * Copyright Texas Instruments Inc 2011, 2012
 * Use of this software	is controlled by the terms and conditions found
 * in the license agreement	under which	this software has been supplied
 *---------------------------------------------------------------------------*/
 /**
 * @file	mcfw_capture_display.c
 * @brief
 * @author	phoong
 * @section	MODIFY history
 *	   - 2012.12.07	: First	Created	based multich_Stream_CaptureDisplay.c
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include "mcfw/src_linux/mcfw_api/usecases/multich_common.h"
#include "mcfw/src_linux/mcfw_api/usecases/multich_ipcbits.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
//# link buffer numbers
#define	NUM_CAPTURE_BUFFERS		8
#define	NUM_ENCODE_BUFFERS		8
#define	NUM_DECODE_BUFFERS		4
#define	NUM_SWMS_BUFFERS		8

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
#define	eprintf(x...) printf(" [mcfw_api] err: " x);
#define	dprintf(x...) printf(" [mcfw_api] "	x);
//#define dprintf(x...)

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/
static void	capture_link_params_init(CaptureLink_CreateParams *capturePrm, int numVipInst)
{
	CaptureLink_VipInstParams	*pCaptureInstPrm;
	CaptureLink_OutParams		*pCaptureOutPrm;

	CaptureLink_CreateParams_Init(capturePrm);

	capturePrm->numVipInst		= numVipInst;
	capturePrm->tilerEnable		= FALSE;
	capturePrm->numBufsPerCh	= NUM_CAPTURE_BUFFERS;
	{
		//# serdes #1
		pCaptureInstPrm						= &capturePrm->vipInst[0];
		pCaptureInstPrm->vipInstId			= SYSTEM_CAPTURE_INST_VIP0_PORTB;
		pCaptureInstPrm->videoDecoderId		= gVsysModuleContext.vsysConfig.decoderHD;
		pCaptureInstPrm->captureMode		= SYSTEM_CAPTURE_MODE_SINGLE_CH_NON_MUX_EMBEDDED_SYNC;
		pCaptureInstPrm->inDataFormat		= SYSTEM_DF_YUV422P;
		pCaptureInstPrm->standard			= SYSTEM_STD_720P_60;
		pCaptureInstPrm->serdesEQ			= gVsysModuleContext.vsysConfig.serdesEQ[0];
		pCaptureInstPrm->serdesPE			= gVsysModuleContext.vsysConfig.serdesPE[0];
		pCaptureInstPrm->numOutput			= 1;

		pCaptureOutPrm						= &pCaptureInstPrm->outParams[0];
		pCaptureOutPrm->dataFormat			= SYSTEM_DF_YUV420SP_UV;
		pCaptureOutPrm->scEnable			= FALSE;
		pCaptureOutPrm->scOutWidth			= 0;
		pCaptureOutPrm->scOutHeight			= 0;
		pCaptureOutPrm->outQueId			= 0;

		if(gVsysModuleContext.vsysConfig.enableDual) {
			pCaptureInstPrm->numOutput			+= 1;
			pCaptureOutPrm						= &pCaptureInstPrm->outParams[1];
			pCaptureOutPrm->dataFormat			= SYSTEM_DF_YUV420SP_UV;
			pCaptureOutPrm->scEnable			= TRUE;
			pCaptureOutPrm->scOutWidth			= 640;
			pCaptureOutPrm->scOutHeight			= 480;
			pCaptureOutPrm->outQueId			= 0;

			return;		//#	support	only 1 VipInst
		}
	}

	if(numVipInst == 2)
	{
		//# serdes #0
		pCaptureInstPrm						= &capturePrm->vipInst[1];
		pCaptureInstPrm->vipInstId			= SYSTEM_CAPTURE_INST_VIP0_PORTA;
		pCaptureInstPrm->videoDecoderId		= gVsysModuleContext.vsysConfig.decoderHD;
		pCaptureInstPrm->captureMode		= SYSTEM_CAPTURE_MODE_SINGLE_CH_NON_MUX_EMBEDDED_SYNC;
		pCaptureInstPrm->inDataFormat		= SYSTEM_DF_YUV422P;
		pCaptureInstPrm->standard			= SYSTEM_STD_720P_60;
		pCaptureInstPrm->serdesEQ			= gVsysModuleContext.vsysConfig.serdesEQ[1];
		pCaptureInstPrm->serdesPE			= gVsysModuleContext.vsysConfig.serdesPE[1];		
		pCaptureInstPrm->numOutput			= 1;

		pCaptureOutPrm						= &pCaptureInstPrm->outParams[0];
		pCaptureOutPrm->dataFormat			= SYSTEM_DF_YUV420SP_UV;
		pCaptureOutPrm->scEnable			= FALSE;
		pCaptureOutPrm->scOutWidth			= 0;
		pCaptureOutPrm->scOutHeight			= 0;
		pCaptureOutPrm->outQueId			= 0;
	}
}

static void	enc_link_params_init(EncLink_CreateParams *encPrm)
{
	EncLink_ChCreateParams *pLinkChPrm;
	EncLink_ChDynamicParams	*pLinkDynPrm;
	VENC_CHN_DYNAMIC_PARAM_S *pDynPrm;
	VENC_CHN_PARAMS_S *pChPrm;
	UInt32 i, vidch;

	vidch =	gVsysModuleContext.vsysConfig.numChs;
	if(gVsysModuleContext.vsysConfig.enableDual) {
		vidch += 1;
	}

	EncLink_CreateParams_Init(encPrm);
	encPrm->numCh =	vidch;
	encPrm->numBufPerCh[0]	= NUM_ENCODE_BUFFERS;

	for	(i=0; i<vidch; i++)
	{
		pLinkChPrm	= &encPrm->chCreateParams[i];
		pLinkDynPrm	= &pLinkChPrm->defaultDynamicParams;

		pChPrm		= &gVencModuleContext.vencConfig.encChannelParams[i];
		pDynPrm		= &pChPrm->dynamicParam;

		pLinkChPrm->format					= IVIDEO_H264HP;
		pLinkChPrm->profile					= gVencModuleContext.vencConfig.h264Profile[i];
		pLinkChPrm->dataLayout				= IVIDEO_PROGRESSIVE;
		pLinkChPrm->fieldMergeEncodeEnable	= FALSE;
		pLinkChPrm->enableAnalyticinfo		= pChPrm->enableAnalyticinfo;
		pLinkChPrm->maxBitRate				= pChPrm->maxBitRate;
		pLinkChPrm->encodingPreset			= pChPrm->encodingPreset;
		pLinkChPrm->rateControlPreset		= pChPrm->rcType;
		pLinkChPrm->enableHighSpeed         = FALSE;
		pLinkChPrm->StreamPreset            = 1;

		pLinkDynPrm->outputFrameRate		= pDynPrm->frameRate * 1000;
		pLinkDynPrm->intraFrameInterval		= pDynPrm->intraFrameInterval;
		pLinkDynPrm->targetBitRate			= pDynPrm->targetBitRate;
		pLinkDynPrm->interFrameInterval		= 1;
		pLinkDynPrm->mvAccuracy				= IVIDENC2_MOTIONVECTOR_QUARTERPEL;
		pLinkDynPrm->inputFrameRate			= pDynPrm->inputFrameRate;
		pLinkDynPrm->rcAlg					= pDynPrm->rcAlg;
		pLinkDynPrm->qpMin					= pDynPrm->qpMin;
		pLinkDynPrm->qpMax					= pDynPrm->qpMax;
		pLinkDynPrm->qpInit					= pDynPrm->qpInit;
		pLinkDynPrm->vbrDuration			= pDynPrm->vbrDuration;
		pLinkDynPrm->vbrSensitivity			= pDynPrm->vbrSensitivity;

		gVencModuleContext.encFormat[i]		= pLinkChPrm->format;
	}

	//#	MJPEG
	if(gVsysModuleContext.vsysConfig.enableMjpeg)
	{
		for	(i=vidch; i<(vidch*2); i++)
		{
			pLinkChPrm	= &encPrm->chCreateParams[i];
			pLinkDynPrm = &pLinkChPrm->defaultDynamicParams;

			pChPrm		= &gVencModuleContext.vencConfig.encChannelParams[i];
			pDynPrm		= &pChPrm->dynamicParam;

			pLinkChPrm->format					= IVIDEO_MJPEG;
			pLinkChPrm->profile					= 0;
			pLinkChPrm->dataLayout				= IVIDEO_PROGRESSIVE;
			pLinkChPrm->fieldMergeEncodeEnable	= FALSE;
			pLinkChPrm->enableAnalyticinfo		= 0;
			pLinkChPrm->maxBitRate				= 0;
			pLinkChPrm->encodingPreset			= 0;
			pLinkChPrm->rateControlPreset		= 0;

			pLinkDynPrm->outputFrameRate		= pDynPrm->frameRate * 1000;
			pLinkDynPrm->intraFrameInterval		= 0;
			pLinkDynPrm->targetBitRate			= 100*1000;
			pLinkDynPrm->interFrameInterval		= 0;
			pLinkDynPrm->mvAccuracy				= 0;
			pLinkDynPrm->inputFrameRate			= pDynPrm->inputFrameRate;
			pLinkDynPrm->qpMin					= 0;
			pLinkDynPrm->qpMax					= 0;
			pLinkDynPrm->qpInit					= 0;
			pLinkDynPrm->vbrDuration			= 0;
			pLinkDynPrm->vbrSensitivity			= 0;
		}
	}
}

static void	dec_link_params_init(DecLink_CreateParams *decPrm, IpcBitsOutLinkHLOS_CreateParams *ipcBitsOutHostPrm)
{
	DecLink_ChCreateParams	*pLinkChPrm;
	VDEC_CHN_PARAMS_S		*pChPrm;
	UInt32 i;

	decPrm->tilerEnable	= FALSE;
	decPrm->numBufPerPool[0] = NUM_DECODE_BUFFERS;

	for(i=0; i<gVdecModuleContext.vdecConfig.numChn; i++)
	{
		pLinkChPrm	= &decPrm->chCreateParams[i];
		pChPrm		= &gVdecModuleContext.vdecConfig.decChannelParams[i];

		pLinkChPrm->format					= IVIDEO_H264HP;
		pLinkChPrm->profile					= IH264VDEC_PROFILE_ANY;
		pLinkChPrm->fieldMergeDecodeEnable	= FALSE;
		pLinkChPrm->targetMaxWidth			= ipcBitsOutHostPrm->inQueInfo.chInfo[i].width;
		pLinkChPrm->targetMaxHeight			= ipcBitsOutHostPrm->inQueInfo.chInfo[i].height;
		pLinkChPrm->defaultDynamicParams.targetFrameRate = pChPrm->dynamicParam.frameRate;
		pLinkChPrm->defaultDynamicParams.targetBitRate	 = pChPrm->dynamicParam.targetBitRate;
		pLinkChPrm->dpbBufSizeInFrames		= 2;
	}

	if(gVsysModuleContext.vsysConfig.enableMjpeg)
	{
		pLinkChPrm	= &decPrm->chCreateParams[i];
		pChPrm		= &gVdecModuleContext.vdecConfig.decChannelParams[i];

		pLinkChPrm->format					= IVIDEO_MJPEG;
		pLinkChPrm->profile					= 0;
		pLinkChPrm->targetMaxWidth			= 1920;		//#	max	size
		pLinkChPrm->targetMaxHeight			= 1080;
		pLinkChPrm->defaultDynamicParams.targetFrameRate = pChPrm->dynamicParam.frameRate;
		pLinkChPrm->defaultDynamicParams.targetBitRate	 = 100*1000;
		pLinkChPrm->dpbBufSizeInFrames		= 2;
	}
}

static void	swms_link_params_init(SwMsLink_CreateParams	*swMsPrm, int dev_id, int win_num)
{
	SwMsLink_CreateParams_Init(swMsPrm);

	swMsPrm->numSwMsInst			= 1;
	swMsPrm->swMsInstId[0]			= SYSTEM_SW_MS_SC_INST_SC5;
	swMsPrm->maxInputQueLen			= 4;
	swMsPrm->numOutBuf				= NUM_SWMS_BUFFERS;
	swMsPrm->maxOutRes				= gVdisModuleContext.vdisConfig.deviceParams[dev_id].resolution;
	swMsPrm->lineSkipMode			= FALSE;
	swMsPrm->enableLayoutGridDraw	= FALSE;

	MultiCh_swMsGetUserLayoutPrm(dev_id, swMsPrm, win_num);
}

static void	disp_link_pararms_init(DisplayLink_CreateParams *dispPrm, int dev_id)
{
	DisplayLink_CreateParams_Init(dispPrm);

	dispPrm->displayRes = gVdisModuleContext.vdisConfig.deviceParams[dev_id].resolution;
}

/*----------------------------------------------------------------------------
 encoder & ipc link create/delete function
-----------------------------------------------------------------------------*/
static void encoder_link_create(UInt32 prevLinkId, UInt32 prevLinkQueId, int en_mjpeg)
{
	SwosdLink_CreateParams			swosdPrm;
	DupLink_CreateParams			dupPrm1;
	MergeLink_CreateParams			mergePrm2;

	IpcLink_CreateParams			ipcOutVpssPrm;
	IpcLink_CreateParams 			ipcInVideoPrm;
	EncLink_CreateParams			encPrm;
	IpcBitsOutLinkRTOS_CreateParams	ipcBitsOutVideoPrm;
	IpcBitsInLinkHLOS_CreateParams	ipcBitsInHostPrm0;

	UInt32 ipcOutVpssId, ipcInVideoId;

	//# link IDs
	gVsysModuleContext.swOsdId				= SYSTEM_LINK_ID_SWOSD_0;
	ipcOutVpssId 							= SYSTEM_VPSS_LINK_ID_IPC_OUT_M3_0;
	ipcInVideoId 							= SYSTEM_VIDEO_LINK_ID_IPC_IN_M3_0;
	gVencModuleContext.encId				= SYSTEM_LINK_ID_VENC_0;
	gVencModuleContext.ipcBitsOutRTOSId		= SYSTEM_VIDEO_LINK_ID_IPC_BITS_OUT_0;
	gVencModuleContext.ipcBitsInHLOSId		= SYSTEM_HOST_LINK_ID_IPC_BITS_IN_0;

	//#--- swOsd link params
	swosdPrm.inQueParams.prevLinkId 	= prevLinkId;
	swosdPrm.inQueParams.prevLinkQueId	= prevLinkQueId;
	swosdPrm.frameSync 					= 0;
	swosdPrm.frameSycChId				= 0;
	if(en_mjpeg)
		swosdPrm.outQueParams.nextLink	= SYSTEM_VPSS_LINK_ID_DUP_1;
	else
		swosdPrm.outQueParams.nextLink	= ipcOutVpssId;

	if(en_mjpeg)
	{
		//#--- dup link params - for mjpeg
		dupPrm1.inQueParams.prevLinkId		= gVsysModuleContext.swOsdId;
		dupPrm1.inQueParams.prevLinkQueId	= 0;
		dupPrm1.numOutQue					= 2;
		dupPrm1.notifyNextLink				= TRUE;
		dupPrm1.outQueParams[0].nextLink	= SYSTEM_VPSS_LINK_ID_MERGE_2;
		dupPrm1.outQueParams[1].nextLink	= SYSTEM_VPSS_LINK_ID_MERGE_2;

		//#--- merge link params
		mergePrm2.numInQue = 2;
		mergePrm2.inQueParams[0].prevLinkId		= SYSTEM_VPSS_LINK_ID_DUP_1;
		mergePrm2.inQueParams[0].prevLinkQueId	= 0;
		mergePrm2.inQueParams[1].prevLinkId		= SYSTEM_VPSS_LINK_ID_DUP_1;
		mergePrm2.inQueParams[1].prevLinkQueId	= 1;
		mergePrm2.outQueParams.nextLink			= ipcOutVpssId;
		mergePrm2.notifyNextLink				= TRUE;
	}

	//--------------------------------------------------------------------------
	//# IPC struct init
	MULTICH_INIT_STRUCT(IpcLink_CreateParams, ipcOutVpssPrm);
	MULTICH_INIT_STRUCT(IpcLink_CreateParams, ipcInVideoPrm);
	MULTICH_INIT_STRUCT(IpcBitsOutLinkRTOS_CreateParams, ipcBitsOutVideoPrm);
	MULTICH_INIT_STRUCT(IpcBitsInLinkHLOS_CreateParams, ipcBitsInHostPrm0);

	//#--- ipcOutVpss link params
	if(en_mjpeg)
		ipcOutVpssPrm.inQueParams.prevLinkId 	= SYSTEM_VPSS_LINK_ID_MERGE_2;
	else
		ipcOutVpssPrm.inQueParams.prevLinkId 	= gVsysModuleContext.swOsdId;
	ipcOutVpssPrm.inQueParams.prevLinkQueId	= 0;
	ipcOutVpssPrm.numOutQue					= 1;
	ipcOutVpssPrm.notifyNextLink			= TRUE;
	ipcOutVpssPrm.notifyPrevLink			= TRUE;
	ipcOutVpssPrm.noNotifyMode				= FALSE;
	ipcOutVpssPrm.outQueParams[0].nextLink	= ipcInVideoId;

	//#--- ipcInVideo link params
	ipcInVideoPrm.inQueParams.prevLinkId	= ipcOutVpssId;
	ipcInVideoPrm.inQueParams.prevLinkQueId	= 0;
	ipcInVideoPrm.numOutQue					= 1;
	ipcInVideoPrm.notifyNextLink			= TRUE;
	ipcInVideoPrm.notifyPrevLink			= TRUE;
	ipcInVideoPrm.noNotifyMode				= FALSE;
	ipcInVideoPrm.outQueParams[0].nextLink	= gVencModuleContext.encId;

	//#--- encoder link params
	MULTICH_INIT_STRUCT(EncLink_CreateParams, encPrm);
	enc_link_params_init(&encPrm);
	encPrm.inQueParams.prevLinkId		= ipcInVideoId;
	encPrm.inQueParams.prevLinkQueId	= 0;
	encPrm.outQueParams.nextLink		= gVencModuleContext.ipcBitsOutRTOSId;

	//#--- ipcBitsOutVideo link params
	ipcBitsOutVideoPrm.baseCreateParams.inQueParams.prevLinkId = gVencModuleContext.encId;
	ipcBitsOutVideoPrm.baseCreateParams.inQueParams.prevLinkQueId = 0;
	ipcBitsOutVideoPrm.baseCreateParams.numOutQue = 1;
	ipcBitsOutVideoPrm.baseCreateParams.outQueParams[0].nextLink = gVencModuleContext.ipcBitsInHLOSId;
	MultiCh_ipcBitsInitCreateParams_BitsOutRTOS(&ipcBitsOutVideoPrm, TRUE);

	//#--- ipcBitsInHost link params
	ipcBitsInHostPrm0.baseCreateParams.inQueParams.prevLinkId = gVencModuleContext.ipcBitsOutRTOSId;
	ipcBitsInHostPrm0.baseCreateParams.inQueParams.prevLinkQueId = 0;
	MultiCh_ipcBitsInitCreateParams_BitsInHLOS(&ipcBitsInHostPrm0);

	//#--- encoder link creation -------------------------------------
	System_linkCreate(gVsysModuleContext.swOsdId, &swosdPrm, sizeof(swosdPrm));
	if(en_mjpeg) {
		System_linkCreate(SYSTEM_VPSS_LINK_ID_DUP_1, &dupPrm1, sizeof(dupPrm1));
		System_linkCreate(SYSTEM_VPSS_LINK_ID_MERGE_2, &mergePrm2, sizeof(mergePrm2));
	}
	System_linkCreate(ipcOutVpssId, &ipcOutVpssPrm, sizeof(ipcOutVpssPrm));
	System_linkCreate(ipcInVideoId, &ipcInVideoPrm, sizeof(ipcInVideoPrm));
	System_linkCreate(gVencModuleContext.encId, &encPrm, sizeof(encPrm));
	System_linkCreate(gVencModuleContext.ipcBitsOutRTOSId, &ipcBitsOutVideoPrm, sizeof(ipcBitsOutVideoPrm));
	System_linkCreate(gVencModuleContext.ipcBitsInHLOSId, &ipcBitsInHostPrm0, sizeof(ipcBitsInHostPrm0));

}

static void encoder_link_delete(int en_mjpeg)
{
	System_linkDelete(gVencModuleContext.ipcBitsInHLOSId);
	System_linkDelete(gVencModuleContext.ipcBitsOutRTOSId);
	System_linkDelete(gVencModuleContext.encId);
	System_linkDelete(SYSTEM_VIDEO_LINK_ID_IPC_IN_M3_0);
	System_linkDelete(SYSTEM_VPSS_LINK_ID_IPC_OUT_M3_0);
	if(en_mjpeg) {
		System_linkDelete(SYSTEM_VPSS_LINK_ID_MERGE_2);
		System_linkDelete(SYSTEM_VPSS_LINK_ID_DUP_1);
	}
	System_linkDelete(gVsysModuleContext.swOsdId);
}

/*----------------------------------------------------------------------------
 display link create/delete function
-----------------------------------------------------------------------------*/
static void display_link_create(UInt32 prevLinkId, UInt32 prevLinkQueId, int layout)
{
	SwMsLink_CreateParams		swMsPrm;
	DisplayLink_CreateParams	dispPrm;

	//# link IDs
	gVdisModuleContext.swMsId[0]				= SYSTEM_LINK_ID_SW_MS_MULTI_INST_0;
	gVdisModuleContext.displayId[VDIS_DEV_SD]	= SYSTEM_LINK_ID_DISPLAY_2;

	//#--- swMs	Link Params
	swms_link_params_init(&swMsPrm,	VDIS_DEV_SD, layout);
	swMsPrm.inQueParams.prevLinkId		= prevLinkId;
	swMsPrm.inQueParams.prevLinkQueId	= prevLinkQueId;
	swMsPrm.outQueParams.nextLink		= gVdisModuleContext.displayId[VDIS_DEV_SD];

	//#--- display link	params (TV-out)
	disp_link_pararms_init(&dispPrm, VDIS_DEV_SD);
	dispPrm.inQueParams[0].prevLinkId	= gVdisModuleContext.swMsId[0];
	dispPrm.inQueParams[0].prevLinkQueId	= 0;

	//#--- display link	creation -------------------------------------
	System_linkCreate(gVdisModuleContext.swMsId[0],	&swMsPrm, sizeof(swMsPrm));
	System_linkCreate(gVdisModuleContext.displayId[VDIS_DEV_SD], &dispPrm, sizeof(dispPrm));
}

static void display_link_delete(void)
{
	System_linkDelete(gVdisModuleContext.displayId[VDIS_DEV_SD]);
	System_linkDelete(gVdisModuleContext.swMsId[0]);
}

/*****************************************************************************
* @brief	mcfw_capture_display init function for ucx
* @section	DESC Description
*	- desc : HD	2ch
*****************************************************************************/
/*----------------------------------------------------------------------------------------
 CAPTURE(720Px2)---> DU0 -->SWOSD--------->IPCM3OUT->IPCM3IN->H264ENC->BITSOUT->BITSIN
					  |			  |	   |	 (VPS)	   (VID)			 (VID)	  (A8)
					  |			 (DU1/M2)
					  -->SWMS------------->DISPLAY(SD)
----------------------------------------------------------------------------------------*/
void mcfw_capture_display_init(void)
{
	CaptureLink_CreateParams		capturePrm;
	DupLink_CreateParams			dupPrm0;

	int	num_ch = gVsysModuleContext.vsysConfig.numChs;
	int	capt_mode =	gVsysModuleContext.vsysConfig.captMode;
	int	pre_display_id;

	dprintf("%s: capt_mode %d, num_ch %d\n", __func__, capt_mode, num_ch);

	//#	link IDs
	gVcapModuleContext.captureId	= SYSTEM_LINK_ID_CAPTURE;
	pre_display_id					= gVcapModuleContext.captureId;

	//#-------------------------------------------
	//# Capture link
	//#-------------------------------------------
	if(capt_mode ==	CAPT_MODE_720P)
	{
		//#--- capture link params
		capture_link_params_init(&capturePrm, num_ch);
		if(gVsysModuleContext.vsysConfig.enableEncode) {
			capturePrm.outQueParams[0].nextLink	= SYSTEM_VPSS_LINK_ID_DUP_0;
		} else {
			capturePrm.outQueParams[0].nextLink	= SYSTEM_LINK_ID_SW_MS_MULTI_INST_0;
		}

		//#--- capture link creation
		System_linkCreate(gVcapModuleContext.captureId,	&capturePrm, sizeof(capturePrm));

		if(gVsysModuleContext.vsysConfig.enableEncode)
		{
			//#--- dup link params
			dupPrm0.inQueParams.prevLinkId		= gVcapModuleContext.captureId;
			dupPrm0.inQueParams.prevLinkQueId	= 0;
			dupPrm0.numOutQue					= 2;
			dupPrm0.notifyNextLink				= TRUE;
			dupPrm0.outQueParams[0].nextLink	= SYSTEM_LINK_ID_SW_MS_MULTI_INST_0;
			dupPrm0.outQueParams[1].nextLink	= SYSTEM_LINK_ID_SWOSD_0;

			System_linkCreate(SYSTEM_VPSS_LINK_ID_DUP_0, &dupPrm0, sizeof(dupPrm0));
			pre_display_id = SYSTEM_VPSS_LINK_ID_DUP_0;

			//#--- encoder link
			encoder_link_create(SYSTEM_VPSS_LINK_ID_DUP_0, 1, gVsysModuleContext.vsysConfig.enableMjpeg);
		}

		//#--- display link
		display_link_create(pre_display_id,	0, num_ch);
	}

	dprintf("%s done!\n", __func__);
}

void mcfw_capture_display_exit(void)
{
	//#-------------------------------------------
	//# link deletion
	//#-------------------------------------------
	display_link_delete();

	if(gVsysModuleContext.vsysConfig.enableEncode) {
		encoder_link_delete(gVsysModuleContext.vsysConfig.enableMjpeg);
		System_linkDelete(SYSTEM_VPSS_LINK_ID_DUP_0);
	} else {
		System_linkDelete(SYSTEM_VPSS_LINK_ID_NULL_0);
	}

	System_linkDelete(gVcapModuleContext.captureId);

	dprintf("%s done!\n", __func__);
}

/*****************************************************************************
* @brief	mcfw_decoder_display_init function
* @section	DESC Description
*	- desc
*****************************************************************************/
/*------------------------------------------------------------------------
 BITSOUT(A8)->BITSIN(VID)->H264DEC->IPCM3OUT->IPCM3IN->SWMS->DISPLAY(SD)
------------------------------------------------------------------------*/
void mcfw_decoder_display_init(void)
{
	System_LinkQueInfo				decLinkInfo;
	IpcBitsOutLinkHLOS_CreateParams ipcBitsOutHostPrm;
	IpcBitsInLinkRTOS_CreateParams	ipcBitsInVideoPrm;
	DecLink_CreateParams			decPrm;
	IpcLink_CreateParams			ipcOutVideoPrm;
	IpcLink_CreateParams			ipcInVpssPrm;

	UInt32 ipcOutVideoId, ipcInVpssId;
	int i;

	dprintf("%s start\n", __func__);

	//#-------------------------------------------
	//# link IDs
	//#-------------------------------------------
	gVdecModuleContext.ipcBitsOutHLOSId			= SYSTEM_HOST_LINK_ID_IPC_BITS_OUT_0;
	gVdecModuleContext.ipcBitsInRTOSId			= SYSTEM_VIDEO_LINK_ID_IPC_BITS_IN_0;
	gVdecModuleContext.decId					= SYSTEM_LINK_ID_VDEC_0;
	ipcOutVideoId								= SYSTEM_VIDEO_LINK_ID_IPC_OUT_M3_0;
	ipcInVpssId									= SYSTEM_VPSS_LINK_ID_IPC_IN_M3_0;
	gVdisModuleContext.swMsId[0]				= SYSTEM_LINK_ID_SW_MS_MULTI_INST_0;

	//#-------------------------------------------
	//# link params
	//#-------------------------------------------
	MULTICH_INIT_STRUCT(IpcBitsInLinkRTOS_CreateParams,ipcBitsInVideoPrm);
	MULTICH_INIT_STRUCT(IpcLink_CreateParams,ipcOutVideoPrm);
	MULTICH_INIT_STRUCT(IpcLink_CreateParams,ipcInVpssPrm);

	if(gVsysModuleContext.vsysConfig.enableMjpeg)
		decLinkInfo.numCh = gVdecModuleContext.vdecConfig.numChn+1;
	else
		decLinkInfo.numCh = gVdecModuleContext.vdecConfig.numChn;

	for(i=0; i<decLinkInfo.numCh; i++) {
		decLinkInfo.chInfo[i].width = gVdecModuleContext.vdecConfig.decChannelParams[i].maxVideoWidth;
		decLinkInfo.chInfo[i].height = gVdecModuleContext.vdecConfig.decChannelParams[i].maxVideoHeight;
	}
	MultiCh_ipcBitsInitCreateParams_BitsOutHLOS(&ipcBitsOutHostPrm, &decLinkInfo);

	//#--- ipcBitsInVideo link params
	ipcBitsInVideoPrm.baseCreateParams.inQueParams.prevLinkId       = gVdecModuleContext.ipcBitsOutHLOSId;
	ipcBitsInVideoPrm.baseCreateParams.inQueParams.prevLinkQueId    = 0;
	ipcBitsInVideoPrm.baseCreateParams.numOutQue                    = 1;
	ipcBitsInVideoPrm.baseCreateParams.outQueParams[0].nextLink     = gVdecModuleContext.decId;
	MultiCh_ipcBitsInitCreateParams_BitsInRTOS(&ipcBitsInVideoPrm, TRUE);

	//#--- decoder link params
	MULTICH_INIT_STRUCT(DecLink_CreateParams, decPrm);
	dec_link_params_init(&decPrm, &ipcBitsOutHostPrm);
	decPrm.inQueParams.prevLinkId		= gVdecModuleContext.ipcBitsInRTOSId;
	decPrm.inQueParams.prevLinkQueId	= 0;
	decPrm.outQueParams.nextLink		= ipcOutVideoId;

	//#--- ipcOutVideo link params
	ipcOutVideoPrm.inQueParams.prevLinkId	= gVdecModuleContext.decId;
	ipcOutVideoPrm.inQueParams.prevLinkQueId = 0;
	ipcOutVideoPrm.numOutQue				= 1;
	ipcOutVideoPrm.notifyNextLink			= TRUE;
	ipcOutVideoPrm.notifyPrevLink			= TRUE;
	ipcOutVideoPrm.noNotifyMode				= FALSE;
	ipcOutVideoPrm.outQueParams[0].nextLink	= ipcInVpssId;

	//#--- ipcInVpss link params
	ipcInVpssPrm.inQueParams.prevLinkId		= ipcOutVideoId;
	ipcInVpssPrm.inQueParams.prevLinkQueId	= 0;
	ipcInVpssPrm.numOutQue					= 1;
	ipcInVpssPrm.notifyNextLink				= TRUE;
	ipcInVpssPrm.notifyPrevLink				= TRUE;
	ipcInVpssPrm.noNotifyMode				= FALSE;
	ipcInVpssPrm.outQueParams[0].nextLink	= gVdisModuleContext.swMsId[0];

	//#-------------------------------------------
	//# link creation
	//#-------------------------------------------
	System_linkCreate(gVdecModuleContext.ipcBitsOutHLOSId, &ipcBitsOutHostPrm, sizeof(ipcBitsOutHostPrm));
	System_linkCreate(gVdecModuleContext.ipcBitsInRTOSId,  &ipcBitsInVideoPrm, sizeof(ipcBitsInVideoPrm));
	System_linkCreate(gVdecModuleContext.decId, &decPrm, sizeof(decPrm));
	System_linkCreate(ipcOutVideoId, &ipcOutVideoPrm, sizeof(ipcOutVideoPrm));
	System_linkCreate(ipcInVpssId,   &ipcInVpssPrm,   sizeof(ipcInVpssPrm)  );

	//#--- display link
	display_link_create(ipcInVpssId, 0, 1);

	dprintf("%s done!\n", __func__);
}

void mcfw_decoder_display_exit(void)
{
	//#-------------------------------------------
	//# link deletion
	//#-------------------------------------------
	display_link_delete();

	System_linkDelete(SYSTEM_VPSS_LINK_ID_IPC_IN_M3_0);
	System_linkDelete(SYSTEM_VIDEO_LINK_ID_IPC_OUT_M3_0);
	System_linkDelete(gVdecModuleContext.decId);
	System_linkDelete(gVdecModuleContext.ipcBitsInRTOSId);
	System_linkDelete(gVdecModuleContext.ipcBitsOutHLOSId);

	/* Print the HWI, SWI and all tasks load */
	/* Reset the accumulated timer ticks */
	MultiCh_prfLoadCalcEnable(FALSE, TRUE, FALSE);

	dprintf("%s done!\n", __func__);
}
