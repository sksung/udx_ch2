/*=============================================================
 * @file:       ti_vdis.c
 *
 * @brief:  Video Display function declare.
 *
 * @vers:       0.5.0.0 2011-06
 *
 *=============================================================
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include "mcfw/src_linux/mcfw_api/usecases/multich_common.h"
#include "ti_vsys_priv.h"
#include "ti_vcap_priv.h"
#include "ti_vdis_priv.h"
#include "ti_vdis.h"
#include "ti_vdis_timings.h"

#include <mcfw/interfaces/link_api/displayLink.h>
#include <mcfw/interfaces/link_api/swMsLink.h>
#include <mcfw/interfaces/link_api/deiLink.h>
#include <mcfw/interfaces/link_api/avsync.h>

#define VDIS_TRACE_ENABLE_FXN_ENTRY_EXIT           (0)
#define VDIS_TRACE_INFO_PRINT_INTERVAL             (8192)


#if VDIS_TRACE_ENABLE_FXN_ENTRY_EXIT
#define VDIS_TRACE_FXN(str,...)                    do {                           \
                                                     static Int printInterval = 0;\
                                                     if ((printInterval % VDIS_TRACE_INFO_PRINT_INTERVAL) == 0) \
                                                     {                                                          \
                                                         OSA_printf("TI_VDIS:%s function:%s",str,__func__);     \
                                                         OSA_printf(__VA_ARGS__);                               \
                                                     }                                                          \
                                                     printInterval++;                                           \
                                                   } while (0)
#define VDIS_TRACE_FXN_ENTRY(...)                  VDIS_TRACE_FXN("Entered",__VA_ARGS__)
#define VDIS_TRACE_FXN_EXIT(...)                   VDIS_TRACE_FXN("Leaving",__VA_ARGS__)
#else
#define VDIS_TRACE_FXN_ENTRY(...)
#define VDIS_TRACE_FXN_EXIT(...)
#endif

/* =============================================================================
 * Globals
 * =============================================================================
 */

VDIS_MODULE_CONTEXT_S gVdisModuleContext;
VDIS_CHN_MAP_INFO_S gVdisChnMapInfo[VDIS_DEV_MAX];

static int std_sd=VSYS_STD_NTSC;

/* =============================================================================
 * Vdis internal APIs prototype
 * =============================================================================
 */
static Void Vdis_setDefaultConfig();
static Void Vdis_swMs_PrintLayoutParams(VDIS_DEV vdDevId, SwMsLink_LayoutPrm * vdMosaicParam);

/* =============================================================================
 * Vdis module APIs
 * =============================================================================
 */
/**
 * \brief:
 *      Initialize parameters to be passed to init
 * \input:
 *      NA
 * \output:
 *      NA
 * \return
*       ERROR_NOERROR       --  while success
*       ERROR_CODE          --  refer for err defination
*/
Void Vdis_params_init(VDIS_PARAMS_S *pContext)
{
    UInt16 i;

    memset(pContext, 0, sizeof(VDIS_PARAMS_S));
    for(i = 0; i < VDIS_DEV_MAX; i++)
    {
		pContext->deviceParams[i].backGroundColor = 0;

		if(i == VDIS_DEV_DVO2) {	//# for lcd
		    pContext->deviceParams[i].resolution  = VSYS_STD_WVGA_60;
		}
		else if(i == VDIS_DEV_SD) {
			pContext->deviceParams[i].resolution  = std_sd;
		}
		else {
			pContext->deviceParams[i].resolution  = VSYS_STD_1080P_60;
		}
    }

    /* Configure output Info for vencs */
    pContext->tiedDevicesMask = VDIS_VENC_HDMI | VDIS_VENC_DVO2;
    pContext->enableConfigExtVideoEncoder = TRUE;	//# 9022

#if defined (TI814X_DVR) || defined (TI814X_EVM)
    pContext->enableConfigExtVideoEncoder = FALSE;
#endif

	#ifdef TI810X_UBX
	pContext->tiedDevicesMask = 0;
    pContext->enableConfigExtVideoEncoder = FALSE;
	#endif

    pContext->deviceParams[VDIS_DEV_DVO2].enable = FALSE;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.vencNodeNum = VDIS_VENC_DVO2;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.aFmt = VDIS_A_OUTPUT_COMPOSITE;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.dvoFidPolarity = VDIS_POLARITY_ACT_HIGH;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.dvoVsPolarity = VDIS_POLARITY_ACT_LOW;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.dvoHsPolarity = VDIS_POLARITY_ACT_LOW;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.dvoActVidPolarity = VDIS_POLARITY_ACT_HIGH;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.dvoFmt = VDIS_DVOFMT_TRIPLECHAN_DISCSYNC;
    pContext->deviceParams[VDIS_DEV_DVO2].outputInfo.dataFormat = SYSTEM_DF_RGB24_888;

    pContext->deviceParams[VDIS_DEV_HDMI].enable = FALSE;
    pContext->deviceParams[VDIS_DEV_HDMI].outputInfo.vencNodeNum = VDIS_VENC_HDMI;
    pContext->deviceParams[VDIS_DEV_HDMI].outputInfo.aFmt = VDIS_A_OUTPUT_COMPOSITE;
    pContext->deviceParams[VDIS_DEV_HDMI].outputInfo.dvoFmt = VDIS_DVOFMT_TRIPLECHAN_EMBSYNC;
    pContext->deviceParams[VDIS_DEV_HDMI].outputInfo.dataFormat = SYSTEM_DF_RGB24_888;

    pContext->deviceParams[VDIS_DEV_SD].enable = TRUE;
    pContext->deviceParams[VDIS_DEV_SD].outputInfo.vencNodeNum = VDIS_VENC_SD;
    pContext->deviceParams[VDIS_DEV_SD].outputInfo.aFmt = VDIS_A_OUTPUT_COMPOSITE;
    pContext->deviceParams[VDIS_DEV_SD].outputInfo.dvoFmt = VDIS_DVOFMT_TRIPLECHAN_DISCSYNC;
    pContext->deviceParams[VDIS_DEV_SD].outputInfo.dataFormat = SYSTEM_DF_RGB24_888;

    pContext->deviceParams[SYSTEM_DC_VENC_HDMI].colorSpaceMode = VDIS_CSC_MODE_SDTV_GRAPHICS_Y2R;

    pContext->enableLayoutGridDraw = FALSE;
}

/**
* \brief:
*       Setup the Tied Venc Configuration
* \input:
*       Tied Display Devices, Vdis Context
* \output:
*        NA
* \return:
*        ERROR_NOERROR        -- while success
*        ERROR_CODE             -- refer for err defination
*/

Int32 Vdis_tiedVencInit(VDIS_DEV VdDevId1, VDIS_DEV VdDevId2, VDIS_PARAMS_S * pContext)
{
    pContext->tiedDevicesMask = VDIS_VENC_DVO2 | VDIS_VENC_HDMI;
    pContext->deviceParams[VDIS_DEV_DVO2].resolution = pContext->deviceParams[VDIS_DEV_HDMI].resolution;

    return 0;
}
/**
 * \brief:
 *      Initialize Vdis instance
 * \input:
 *      NA
 * \output:
 *      NA
 * \return
*       ERROR_NOERROR       --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_init(VDIS_PARAMS_S * pContext)
{
    UInt32 devId;
    Int32  status = 0;

    for(devId = 0; devId < VDIS_DEV_MAX; devId++)
    {
        gVdisModuleContext.swMsId[devId] = SYSTEM_LINK_ID_INVALID;
        gVdisModuleContext.displayId[devId] = SYSTEM_LINK_ID_INVALID;
        gVdisModuleContext.grpxId[devId] = SYSTEM_LINK_ID_INVALID;
    }
    gVdisModuleContext.ipcFramesInVpssFromHostId = SYSTEM_LINK_ID_INVALID;
    gVdisModuleContext.ipcFramesOutHostId        = SYSTEM_LINK_ID_INVALID;

    Vdis_setDefaultConfig();

    if(pContext==NULL) {
        //Vdis_params_init(&gVdisModuleContext.vdisConfig);		//# phoong
    }
    else {
		memcpy(&gVdisModuleContext.vdisConfig, pContext, sizeof(VDIS_PARAMS_S));
    }

    return  status;
}

/**
 * \brief:
 *      Finalize Vdis instance
 * \input:
 *      NA
 * \output:
 *      NA
 * \return
*       ERROR_NOERROR       --  while success
*       ERROR_CODE          --  refer for err defination
*/
Void Vdis_exit()
{

}

/**
 * \brief:
 *      Start Vdis instance for display
 * \input:
 *      NA
 * \output:
 *      NA
 * \return
*       ERROR_NOERROR       --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_start()
{
    UInt32 devId;
    Int32 status = 0;

    if (gVdisModuleContext.ipcFramesInVpssFromHostId != SYSTEM_LINK_ID_INVALID)
    {
        System_linkStart(gVdisModuleContext.ipcFramesInVpssFromHostId);
        OSA_assert(gVdisModuleContext.ipcFramesOutHostId != SYSTEM_LINK_ID_INVALID);
        System_linkStart(gVdisModuleContext.ipcFramesOutHostId);
    }

    for(devId = 0; devId < VDIS_DEV_MAX; devId++)
    {
        if(gVdisModuleContext.swMsId[devId]!=SYSTEM_LINK_ID_INVALID)
    {
            System_linkStart(gVdisModuleContext.swMsId[devId]);
        }
    }

    for(devId = 0; devId < VDIS_DEV_MAX; devId++)
    {
        if(gVdisModuleContext.displayId[devId]!=SYSTEM_LINK_ID_INVALID)
        {
            System_linkStart(gVdisModuleContext.displayId[devId]);
			Vdis_switchActiveChannel(devId,0);
        }
    }

    return status;
}

/**
 * \brief:
 *      Stop Vdis instance
 * \input:
 *      NA
 * \output:
 *      NA
 * \return
*       ERROR_NOERROR       --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_stop()
{
    UInt32 devId;

    if (gVdisModuleContext.ipcFramesOutHostId != SYSTEM_LINK_ID_INVALID)
    {
        System_linkStop(gVdisModuleContext.ipcFramesOutHostId);
        OSA_assert(gVdisModuleContext.ipcFramesInVpssFromHostId != SYSTEM_LINK_ID_INVALID);
        System_linkStop(gVdisModuleContext.ipcFramesInVpssFromHostId);
    }

    for(devId = 0; devId < VDIS_DEV_MAX; devId++)
    {
        if(gVdisModuleContext.swMsId[devId]!=SYSTEM_LINK_ID_INVALID)
        {
            System_linkStop(gVdisModuleContext.swMsId[devId]);
        }
    }

    for(devId = 0; devId < VDIS_DEV_MAX; devId++)
    {
        if(gVdisModuleContext.displayId[devId]!=SYSTEM_LINK_ID_INVALID)
        {
            System_linkStop(gVdisModuleContext.displayId[devId]);
        }
    }

    return 0;
}

/* Generic description */
/* There will be 3 levels as:
   1. Device -- device ports setting, different chip have different mapping.
   2. Mosaic -- multiple set for video window layout, just switch different mosaic id for different layout.
   3. Channel -- virtual channel, which need add to mosaic window

   need support
    privacy mask for specific channel
    insert raw data to specific channel -- ?? display or capture??
*/

/* =============================================================================
 * Device related APIs
 * =============================================================================
 */
/**
 * \brief:
 *      Set display device parameters
 * \input:
 *      vdDevId             -- capture device id, refer to VCAP_DEV define
 *      psVdDevParam        -- Device parameter structure
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_setParamDevice(VDIS_DEV VdDevId, VDIS_DEV_PARAM_S *psVdDevParam)
{
    memcpy(&gVdisModuleContext.vdisConfig.deviceParams[VdDevId], psVdDevParam, sizeof(VDIS_DEV_PARAM_S));
    return 0;
}

/**
 * \brief:
 *      Get display device parameters
 * \input:
 *      vdDevId             -- capture device id, refer to VCAP_DEV define
 * \output:
 *      psVdDevParam    -- Device parameter structure
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_getParamDevice(VDIS_DEV VdDevId, VDIS_DEV_PARAM_S *psVdDevParam)
{
    memcpy(psVdDevParam, &gVdisModuleContext.vdisConfig.deviceParams[VdDevId], sizeof(VDIS_DEV_PARAM_S));
    return 0;
}
/**
 * \brief:
 *      Get display device parameters
 * \input:
 *      vdDevId             -- capture device id, refer to VCAP_DEV define
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_enableDevice(VDIS_DEV vdDevId)
{
    return 0;
}
/**
 * \brief:
 *      Get display device parameters
 * \input:
 *      vdDevId             -- capture device id, refer to VCAP_DEV define
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_disableDevice(VDIS_DEV vdDevId)
{
    return 0;
}


/* =============================================================================
 * Mosaic related APIs
 * =============================================================================
 */

/**
 * \brief:
 *      Set the mosaic window parameters
 * \input:
 *      vdDevId                -- Device id
 *      psVdMosaicParam -- Mosaic layout window parameters
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS          --    while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_setMosaicParams(VDIS_DEV vdDevId, VDIS_MOSAIC_S *psVdMosaicParam )
{
    UInt32 winId, chId;
    UInt32 swMsId = SYSTEM_LINK_ID_INVALID;
    UInt32 displayId = SYSTEM_LINK_ID_INVALID;
    Bool changeDisplayInputMode = FALSE;
    SwMsLink_LayoutPrm vdisLayoutPrm;

    if( vdDevId == VDIS_DEV_DVO2) {
	    swMsId = gVdisModuleContext.swMsId[1];
	}
	else if(vdDevId == VDIS_DEV_SD) {
	    swMsId = gVdisModuleContext.swMsId[0];

	    /* for DM814x, switch to 60fps input, interlaced 60fps output when
	        psVdMosaicParam->outputFPS is set to 60fps */
	    changeDisplayInputMode = TRUE;
	    displayId = gVdisModuleContext.displayId[VDIS_DEV_SD];
	}
	else
	{
	    swMsId = SYSTEM_LINK_ID_INVALID;
	}

    if(swMsId==SYSTEM_LINK_ID_INVALID)
        return -1;

    /* Get display resolution and coordinates */

    /* Assign mosaic layout number and number of windows */
    vdisLayoutPrm.numWin = psVdMosaicParam->numberOfWindows;
    vdisLayoutPrm.onlyCh2WinMapChanged = psVdMosaicParam->onlyCh2WinMapChanged;
    vdisLayoutPrm.outputFPS = psVdMosaicParam->outputFPS;


    /* Assign each windows coordinates, size and mapping */
    for(winId=0; winId<vdisLayoutPrm.numWin; winId++)
    {
        vdisLayoutPrm.winInfo[winId].channelNum         = psVdMosaicParam->chnMap[winId];
        vdisLayoutPrm.winInfo[winId].bufAddrOffset      = -1;
        vdisLayoutPrm.winInfo[winId].width              = psVdMosaicParam->winList[winId].width;
        vdisLayoutPrm.winInfo[winId].height             = psVdMosaicParam->winList[winId].height;
        vdisLayoutPrm.winInfo[winId].startX             = psVdMosaicParam->winList[winId].start_X;
        vdisLayoutPrm.winInfo[winId].startY             = psVdMosaicParam->winList[winId].start_Y;
        vdisLayoutPrm.winInfo[winId].bypass             = psVdMosaicParam->useLowCostScaling[winId];

        chId = psVdMosaicParam->chnMap[winId];

        if((chId < gVdisModuleContext.vdisConfig.numChannels) && (chId >= 0))
        {
            gVdisChnMapInfo[vdDevId].ch2WinMap[chId] = winId;

            if(gVdisChnMapInfo[vdDevId].isEnableChn[chId] == FALSE)
            {
                vdisLayoutPrm.winInfo[winId].channelNum = SYSTEM_SW_MS_INVALID_ID;
            }
        }
    }


    Vdis_swMs_PrintLayoutParams(vdDevId, &vdisLayoutPrm);
    System_linkControl(swMsId, SYSTEM_SW_MS_LINK_CMD_SWITCH_LAYOUT, &(vdisLayoutPrm), sizeof(vdisLayoutPrm), TRUE);

    if(changeDisplayInputMode)
    {
        DisplayLink_SwitchInputMode prm;

        prm.enableFieldSeparatedInputMode = FALSE;

        if(vdisLayoutPrm.outputFPS >= 50 )
            prm.enableFieldSeparatedInputMode = TRUE;

        System_linkControl(displayId, DISPLAY_LINK_CMD_SWITCH_INPUT_MODE, &prm, sizeof(prm), TRUE);
    }

    return 0;
}
/**
 * \brief:
 *      Get the mosaic window parameters
 * \input:
 *      vdMosaicId      -- Mosaic id
 * \output:
 *      psVdMosaicParam -- Mosaic layout window parameters
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_getMosaicParams(VDIS_DEV vdDevId, VDIS_MOSAIC_S *psVdMosaicParam)
{
    SwMsLink_LayoutPrm vdisLayoutPrm;
    UInt32 winId;

    UInt32 swMsId = 0;

    /* Initialize numWindows to zero by default */
    psVdMosaicParam->numberOfWindows = 0;
    psVdMosaicParam->outputFPS = 30;

    if( vdDevId == VDIS_DEV_DVO2) {
	    swMsId = gVdisModuleContext.swMsId[1];
	}
	else if(vdDevId == VDIS_DEV_SD) {
	    swMsId = gVdisModuleContext.swMsId[0];
	}
	else {
	    swMsId = SYSTEM_LINK_ID_INVALID;
	}

	if(swMsId==SYSTEM_LINK_ID_INVALID)
	    return -1;

    System_linkControl(swMsId, SYSTEM_SW_MS_LINK_CMD_GET_LAYOUT_PARAMS, &(vdisLayoutPrm), sizeof(vdisLayoutPrm), TRUE);

    /* Get display resolution and coordinates */
    psVdMosaicParam->displayWindow.width    = 0;
    psVdMosaicParam->displayWindow.height   = 0;
    psVdMosaicParam->displayWindow.start_X  = 0;
    psVdMosaicParam->displayWindow.start_Y  = 0;

    /* get number of windows */
    psVdMosaicParam->numberOfWindows = vdisLayoutPrm.numWin;
    psVdMosaicParam->onlyCh2WinMapChanged = vdisLayoutPrm.onlyCh2WinMapChanged;
    psVdMosaicParam->outputFPS = vdisLayoutPrm.outputFPS;


    /* Get each windows coordinates, size and mapping */
    for(winId=0; winId<vdisLayoutPrm.numWin; winId++)
    {
        psVdMosaicParam->chnMap[winId]              = vdisLayoutPrm.winInfo[winId].channelNum;
        psVdMosaicParam->winList[winId].width       = vdisLayoutPrm.winInfo[winId].width;
        psVdMosaicParam->winList[winId].height      = vdisLayoutPrm.winInfo[winId].height;
        psVdMosaicParam->winList[winId].start_X     = vdisLayoutPrm.winInfo[winId].startX;
        psVdMosaicParam->winList[winId].start_Y     = vdisLayoutPrm.winInfo[winId].startY;
        psVdMosaicParam->useLowCostScaling[winId]   = vdisLayoutPrm.winInfo[winId].bypass;
    }

    return 0;
}



/**
 * \brief:
 *      pause the mosaic window, repeat the last frame
 * \input:
 *      vdMosaicId      -- Mosaic id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_pauseMosaic(VDIS_MOSAIC vdMosaicId)
{
    return 0;
}
/**
 * \brief:
 *      resume the mosaic window
 * \input:
 *      vdMosaicId      -- Mosaic id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_resumeMosaic(VDIS_MOSAIC vdMosaicId)
{
    return 0;
}
/**
 * \brief:
 *      Step the mosaic window based on command
 * \input:
 *      vdMosaicId      -- Mosaic id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_stepMosaic(VDIS_MOSAIC vdMosaicId)
{
    return 0;
}

/* ------------ Channel related APIs ------------*/
/**
 * \brief:
 *      Set the display channel to mosaic window mapping
 * \input:
 *      vdDevId         --Device id
 *      usChnMap        --Array Mapping Channel to Window
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS        --  while success
*       ERROR_CODE          --  refer for err defination
*/

Int32 Vdis_setMosaicChn(VDIS_DEV vdDevId, VDIS_CHN *usChnMap)
{
    UInt32 winId, status;
    VDIS_MOSAIC_S sVdMosaicParam;

    status = Vdis_getMosaicParams(vdDevId,&sVdMosaicParam);

    if(status<0)
        return status;

    sVdMosaicParam.onlyCh2WinMapChanged = TRUE;

    for(winId=0;winId<VDIS_MOSAIC_WIN_MAX;winId++)
    {
        sVdMosaicParam.chnMap[winId] = *(usChnMap+winId);

        if(sVdMosaicParam.chnMap[winId] >= gVdisModuleContext.vdisConfig.numChannels)
        {
            sVdMosaicParam.chnMap[winId] = sVdMosaicParam.chnMap[winId] - gVdisModuleContext.vdisConfig.numChannels;
        }
    }
    status = Vdis_setMosaicParams(vdDevId, &sVdMosaicParam);
    return status;
}



/**
 * \brief:
 *      Diable the display channel with show blank frame
 * \input:
 *      vdChnId         -- display channel id
 *      vdDevId         -- Device Id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS        --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_disableChn(VDIS_DEV vdDevId, VDIS_CHN vdChId)
{
    VDIS_MOSAIC_S sVdMosaicParam;
    UInt32 winId, status;
	#if TI_VDIS_DEBUG
	UInt32 chId = 0;
	#endif

    status = Vdis_getMosaicParams(vdDevId,&sVdMosaicParam);

    if(status<0)
        return status;

    sVdMosaicParam.onlyCh2WinMapChanged = FALSE;

    for(winId=0;winId<sVdMosaicParam.numberOfWindows;winId++)
    {
        if(sVdMosaicParam.chnMap[winId] == vdChId )
        {
            sVdMosaicParam.chnMap[winId] = VDIS_CHN_INVALID;
            OSA_printf("Disabling Channel Number: %d Window %d Device %d\n", vdChId, winId, vdDevId);
            break;
        }
    }

    /* Update whether channel is enabled or disabled */
    gVdisChnMapInfo[vdDevId].isEnableChn[vdChId] = FALSE;
	#if TI_VDIS_DEBUG
    OSA_printf("\%s >> ----------- Device: %d \n", __FUNCTION__, vdDevId);
    OSA_printf("\nCHANNEL | WINDOW | ENABLE(1)/DISABLE(0)\n");
    for(chId=0;chId<gVdisModuleContext.vdisConfig.numChannels;chId++)
    {
        OSA_printf(" %6d | %6d | %6d\n", chId, gVdisChnMapInfo[vdDevId].ch2WinMap[chId], gVdisChnMapInfo[vdDevId].isEnableChn[chId]);
    }
	#endif
    status = Vdis_setMosaicParams(vdDevId, &sVdMosaicParam);


    return status;
}

/**
 * \brief:
 *      Pause the display channel with repeat last frame
 * \input:
 *      vdChnId         -- display channel id
 *      vdDevId         -- Device Id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/

Int32 Vdis_pauseChn(VDIS_DEV vdDevId, VDIS_CHN VdChnId)
{
    return 0;
}

/**
 * \brief:
 *      Resume the display channel
 * \input:
 *           vdDevId            -- Device Id
 *      vdChnId         -- display channel id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_resumeChn(VDIS_DEV vdDevId, VDIS_CHN VdChnId)
{
    return 0;
}

/**
 * \brief:
 *      Step the display channel with command
 * \input:
 *           vdDevId            -- Device Id
 *      vdChnId         -- display channel id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS    --  while success
*       ERROR_CODE          --  refer for err defination
*/

Int32 Vdis_stepChn(VDIS_DEV vdDevId, VDIS_CHN VdChnId)
{
    return 0;
}

/**
 * \brief:
 *      Enable the display channel
 * \input:
 *      vdChnId         -- display channel id
 *      vdDevId         -- Device Id
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS        --  while success
*       ERROR_CODE          --  refer for err defination
*/


Int32 Vdis_enableChn(VDIS_DEV vdDevId, VDIS_CHN vdChId)
{
    VDIS_MOSAIC_S sVdMosaicParam;
    UInt32 status;
	#if TI_VDIS_DEBUG
	UInt32 chId = 0;
	#endif

    status = Vdis_getMosaicParams(vdDevId,&sVdMosaicParam);

    if(status<0)
        return status;

    sVdMosaicParam.onlyCh2WinMapChanged = FALSE;

    /* Update whether channel is enabled or disabled */
    gVdisChnMapInfo[vdDevId].isEnableChn[vdChId] = TRUE;

    if(gVdisChnMapInfo[vdDevId].ch2WinMap[vdChId] < sVdMosaicParam.numberOfWindows)
    {
        sVdMosaicParam.chnMap[(gVdisChnMapInfo[vdDevId].ch2WinMap[vdChId])] = vdChId;
        OSA_printf("Enabling Channel Number: %d Window %d Device %d\n", vdChId, (gVdisChnMapInfo[vdDevId].ch2WinMap[vdChId]), vdDevId);
    }
	#if TI_VDIS_DEBUG
    OSA_printf("\%s >> ----------- Device: %d \n", __FUNCTION__, vdDevId);
    OSA_printf("\nCHANNEL | WINDOW | ENABLE(1)/DISABLE(0)\n");
    for(chId=0;chId<gVdisModuleContext.vdisConfig.numChannels;chId++)
    {
        OSA_printf(" %6d | %6d | %6d\n", chId, gVdisChnMapInfo[vdDevId].ch2WinMap[chId], gVdisChnMapInfo[vdDevId].isEnableChn[chId]);
    }
	#endif
    status = Vdis_setMosaicParams(vdDevId, &sVdMosaicParam);

    return status;
}


Bool  Vdis_isEnableChn(VDIS_DEV vdDevId, VDIS_CHN vdChId)
{
    return 0;
}


/**
    \brief Set playback control configuration to Avsync logic

    decoder output frame rate is controlled based on trickplay setting.
    this call is used to make avsync logic to sync with new frame rate.

    \param vcChnId  [IN] decode channel ID

*/

void Vdis_setAvsyncConfig(VDIS_CHN vdispChnId, VDIS_AVSYNC speed)
{
#if AVSYNC_COMP_ENABLE
        if (gVsysModuleContext.vsysConfig.enableAVsync == TRUE)
        {
            AVSYNC_PlayRate_t  AVSYNC_PlayRate;
            VDIS_AVSYNC tSpeed;


            AVSYNC_PlayRate.strmId = vdispChnId;
            AVSYNC_PlayRate.startFrameSeqNum = 0;
            tSpeed = speed;

            if(tSpeed == VDEC_TPLAY_IFRAMEONLY) {
                AVSYNC_PlayRate.scaleM = AVSYNC_PlayRate.scaleD = 1;
            }
            else if(tSpeed == VDEC_TPLAY_HALFX || tSpeed == VDEC_TPLAY_QUARTERX) {
                AVSYNC_PlayRate.scaleM = tSpeed;
                AVSYNC_PlayRate.scaleD =  100;
            }
            else {
                AVSYNC_PlayRate.scaleM = tSpeed;
                AVSYNC_PlayRate.scaleD = 1;
            }

            AVSYNC_Control(AVSync_PlayRate, &AVSYNC_PlayRate );
        }
#endif
}

Int32 Vdis_getScreenBuffer(VDIS_DEV vdDevId, VDIS_SCREEN_BUF_INFO_S *psScreenBugInfo)
{
    return 0;
}
Int32 Vdis_releaseScreenBuffer(VDIS_DEV vdDevId, VDIS_SCREEN_BUF_INFO_S *psScreenBugInfo)
{
    return 0;
}
VSYS_VIDEO_STANDARD_E Vdis_getResolution(VDIS_DEV devId)
{
    return(gVdisModuleContext.vdisConfig.deviceParams[devId].resolution);
}

Int32 Vdis_getDisplayId(VDIS_DEV vdDevId)
{
    Int32 displayId = 0;

    if( vdDevId == VDIS_DEV_HDMI)
    {
        displayId = gVdisModuleContext.displayId[VDIS_DEV_HDMI];
    }
    else if( vdDevId == VDIS_DEV_DVO2)
    {
        displayId = gVdisModuleContext.displayId[VDIS_DEV_DVO2];
    }
    else if(vdDevId == VDIS_DEV_SD)
    {
        displayId = gVdisModuleContext.displayId[VDIS_DEV_SD];
    }
    else
    {
        displayId = SYSTEM_LINK_ID_INVALID;
    }

    return(displayId);
}

Int32 Vdis_setResolution(VDIS_DEV devId, UInt32 resolution)
{
    Int32 status = 0;
    DisplayLink_RtParams params;

    Char  gBuff[100];

    gVdisModuleContext.vdisConfig.deviceParams[devId].resolution = resolution;

    /* Check for tied vencs */
    if(!gVdisModuleContext.vdisConfig.tiedDevicesMask) {

        switch(devId)
        {
            case VDIS_DEV_DVO2:
                VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 0, 1)
                switch(resolution) {
                    case VSYS_STD_1080P_60:
                        VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_1080P_60, 1)
                    break;
                    case VSYS_STD_720P_60:
                        VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_720P_60, 1)
                    break;
                    case VSYS_STD_XGA_60:
                        VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_XGA_60, 1)
                    break;
                    case VSYS_STD_SXGA_60:
                        VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_SXGA_60, 1)
                    break;
                    default:
                    break;
                }
                VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 1, 1)
            	break;
                    OSA_printf("\n Resolution not supported for DVO2!! \n");

            default:
            	break;
        }
    }
    else
    {
        if (devId == VDIS_DEV_HDMI || devId == VDIS_DEV_DVO2 ) {
            VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 0, 0)
            VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 0, 1)
            switch(resolution) {
                case VSYS_STD_1080P_60:
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_1080P_60, 0)
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_1080P_60, 1)
                break;
                case VSYS_STD_720P_60:
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_720P_60, 0)
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_720P_60, 1)
                break;
                case VSYS_STD_XGA_60:
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_XGA_60, 0)
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_XGA_60, 1)
                break;
                case VSYS_STD_SXGA_60:
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_SXGA_60, 0)
                    VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_SXGA_60, 1)
                break;
                default:
                    OSA_printf("\n Resolution not supported for this Venc!! \n");
                break;
            }
            /* Tie HDMI and DVO2 from A8 side */
            VDIS_CMD_ARG1(gBuff, VDIS_TIMINGS_TIEDVENCS, gVdisModuleContext.vdisConfig.tiedDevicesMask)

            VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 1, 0)
            VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 1, 1)
        }
        else {
            OSA_printf("\n Venc not supported!! \n");
        }

    }

    /* Assuming SD will not be tied */
    if(devId == VDIS_DEV_SD){
        VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 0, 2)
        switch(resolution) {
            case VSYS_STD_NTSC:
                VDIS_CMD_ARG1(gBuff, VDIS_MODE_NTSC, 2)
            break;
            case VSYS_STD_PAL:
                VDIS_CMD_ARG1(gBuff, VDIS_MODE_PAL, 2)
            break;
            default:
                OSA_printf("\n Resolution not supported for SD!! \n");
            break;
        }
        VDIS_CMD_ARG2(gBuff, VDIS_TIMINGS_SETVENC, 1, 2)
    }

    params.resolution = resolution;

    status = System_linkControl(Vdis_getDisplayId(devId),
                                DISPLAY_LINK_CMD_CHANGE_RESOLUTION,
                                &params,
                                sizeof(DisplayLink_RtParams),
                                TRUE
                                );

    return status;
}

Int32 Vdis_stopDrv(VDIS_DEV vdDevId)
{
    Int32 status;

    status = System_linkControl(Vdis_getDisplayId(vdDevId),
                                DISPLAY_LINK_CMD_STOP_DRV,
                                NULL,
                                0,
                                TRUE
                                );
    return status;

}

Int32 Vdis_startDrv(VDIS_DEV vdDevId)
{
    Int32 status;

    status = System_linkControl(Vdis_getDisplayId(vdDevId),
                                DISPLAY_LINK_CMD_START_DRV,
                                NULL,
                                0,
                                TRUE
                                );

    return status;

}

/* =============================================================================
 * Vdis internal APIs
 * =============================================================================
 */

 /**
 * \brief:
 *      Set Default Vdis Config
 * \input:
 *      NA
 * \output:
 *      NA
 * \return
 *      NONE
*/
static Void Vdis_setDefaultConfig()
{
    UInt32 chId, devId;

    /* WARNING !!! !This requires changes for 8 channel usecases */
    for (devId = 0; devId<VDIS_DEV_MAX; devId++)
    {
        for(chId=0;chId<VDIS_CHN_MAX;chId++)
        {
            gVdisChnMapInfo[devId].ch2WinMap[chId]      = chId;
            gVdisChnMapInfo[devId].isEnableChn[chId]    = TRUE;
        }
    }
	#if TI_VDIS_DEBUG
    for (devId = 0; devId<VDIS_DEV_MAX; devId++)
    {
        OSA_printf("\%s >> ----------- Device: %d \n", __FUNCTION__, devId);
        OSA_printf("\nCHANNEL | WINDOW | ENABLE(1)/DISABLE(0)\n");
        for(chId=0;chId<VDIS_CHN_MAX;chId++)
        {
            OSA_printf(" %6d | %6d | %6d\n", chId, gVdisChnMapInfo[devId].ch2WinMap[chId], gVdisChnMapInfo[devId].isEnableChn[chId]);
        }
    }
	#endif
}

Int32 Vdis_delete()
{
    UInt32 devId;

    if (gVdisModuleContext.ipcFramesInVpssFromHostId != SYSTEM_LINK_ID_INVALID)
    {
        System_linkDelete(gVdisModuleContext.ipcFramesInVpssFromHostId);
        OSA_assert(gVdisModuleContext.ipcFramesOutHostId != SYSTEM_LINK_ID_INVALID);
        System_linkDelete(gVdisModuleContext.ipcFramesOutHostId);
    }
    for(devId = 0; devId < VDIS_DEV_MAX; devId++)
    {
        if(gVdisModuleContext.swMsId[devId]!=SYSTEM_LINK_ID_INVALID)
        {
            System_linkDelete(gVdisModuleContext.swMsId[devId] );
        }
        if(gVdisModuleContext.displayId[devId]!=SYSTEM_LINK_ID_INVALID)
        {
            System_linkDelete(gVdisModuleContext.displayId[devId]);
        }
    }

    return 0;
}

static Void Vdis_copyVidFrameInfoLink2McFw(VIDEO_FRAMEBUF_S *dstBuf,
                                           VIDFrame_Buf    *srcBuf)
{
    Int i,j;
    OSA_assert(VIDEO_MAX_FIELDS == VIDFRAME_MAX_FIELDS);
    OSA_assert(VIDEO_MAX_PLANES == VIDFRAME_MAX_PLANES);

    for (i = 0; i < VIDEO_MAX_FIELDS; i++)
    {
        for (j = 0; j < VIDEO_MAX_PLANES; j++)
        {
            dstBuf->addr[i][j] = srcBuf->addr[i][j];
            dstBuf->phyAddr[i][j] = srcBuf->phyAddr[i][j];
        }
    }
    dstBuf->channelNum  = srcBuf->channelNum;
    dstBuf->fid         = srcBuf->fid;
    dstBuf->frameWidth  = srcBuf->frameWidth;
    dstBuf->frameHeight = srcBuf->frameHeight;
    dstBuf->linkPrivate = srcBuf->linkPrivate;
    dstBuf->timeStamp   = srcBuf->timeStamp;
    dstBuf->framePitch[0] = srcBuf->framePitch[0];
    dstBuf->framePitch[1] = srcBuf->framePitch[1];

    VDIS_TRACE_FXN_EXIT("VidFrameInfo:"
                         "virt[0][0]:%p,"
                         "phy[0][0]:%p,"
                         "channelNum:%d,"
                         "fid:%d,"
                         "frameWidth:%d,"
                         "frameHeight:%d,"
                         "framePitch[0]:%d,"
                         "framePitch[1]:%d,"
                         "timeStamp:%d,",
                         dstBuf->addr[0][0],
                         dstBuf->phyAddr[0][0],
                         dstBuf->channelNum,
                         dstBuf->fid,
                         dstBuf->frameWidth,
                         dstBuf->frameHeight,
                         dstBuf->framePitch[0],
                         dstBuf->framePitch[1],
                         dstBuf->timeStamp);
}

static Void Vdis_copyVidFrameInfoMcFw2Link(VIDFrame_Buf *dstBuf,
                                           VIDEO_FRAMEBUF_S    *srcBuf)
{
    Int i,j;
    OSA_assert(VIDEO_MAX_FIELDS == VIDFRAME_MAX_FIELDS);
    OSA_assert(VIDEO_MAX_PLANES == VIDFRAME_MAX_PLANES);

    for (i = 0; i < VIDEO_MAX_FIELDS; i++)
    {
        for (j = 0; j < VIDEO_MAX_PLANES; j++)
        {
            dstBuf->addr[i][j] = srcBuf->addr[i][j];
            dstBuf->phyAddr[i][j] = srcBuf->phyAddr[i][j];
        }
    }
    dstBuf->channelNum  = srcBuf->channelNum;
    dstBuf->fid         = srcBuf->fid;
    dstBuf->frameWidth  = srcBuf->frameWidth;
    dstBuf->frameHeight = srcBuf->frameHeight;
    dstBuf->linkPrivate = srcBuf->linkPrivate;
    dstBuf->timeStamp   = srcBuf->timeStamp;
    dstBuf->framePitch[0] = srcBuf->framePitch[0];
    dstBuf->framePitch[1] = srcBuf->framePitch[1];

    VDIS_TRACE_FXN_EXIT("VidFrameInfo:"
                         "virt[0][0]:%p,"
                         "phy[0][0]:%p,"
                         "channelNum:%d,"
                         "fid:%d,"
                         "frameWidth:%d,"
                         "frameHeight:%d,"
                         "framePitch[0]:%d,"
                         "framePitch[1]:%d,"
                         "timeStamp:%d,",
                         dstBuf->addr[0][0],
                         dstBuf->phyAddr[0][0],
                         dstBuf->channelNum,
                         dstBuf->fid,
                         dstBuf->frameWidth,
                         dstBuf->frameHeight,
                         dstBuf->framePitch[0],
                         dstBuf->framePitch[1],
                         dstBuf->timeStamp);
}


/**
    \brief Send filled video gBuffers to framework for display

    User calls this API to put full video frames for display

    \param pFrameBufList    [OUT]  List of video frames to be displayed

    \return ERROR_NONE on success
*/
Int32 Vdis_putFullVideoFrames(VIDEO_FRAMEBUF_LIST_S *pFrameBufList)
{
    VIDEO_FRAMEBUF_S *pSrcBuf;
    VIDFrame_Buf     *pDstBuf;
    VIDFrame_BufList  vidBufList;
    UInt32 i;
    Int status = 0;

	if (gVdisModuleContext.ipcFramesOutHostId == SYSTEM_LINK_ID_INVALID)
		return 0;

    VDIS_TRACE_FXN_ENTRY("Num bufs put:%d",pFrameBufList->numFrames);
    vidBufList.numFrames = pFrameBufList->numFrames;
    for (i = 0; i < vidBufList.numFrames; i++)
    {
        pSrcBuf = &pFrameBufList->frames[i];
        pDstBuf = &vidBufList.frames[i];
        Vdis_copyVidFrameInfoMcFw2Link(pDstBuf,pSrcBuf);
    }
    if (vidBufList.numFrames)
    {
        status =
        IpcFramesOutLink_putFullVideoFrames(gVdisModuleContext.ipcFramesOutHostId,
                                            &vidBufList);
    }
    VDIS_TRACE_FXN_ENTRY("VIDFrame release status:%d",status);
    return 0;
}


/**
    \brief Give displayed video frames back to the application

    Buffers that are were previously put by Vdis_putFullVideoFrames can be
    freed back to the framework by invoking this API.

    \param pFrameBufList [IN]   List of video frames

    \return ERROR_NONE on success
*/
Int32 Vdis_getEmptyVideoFrames(VIDEO_FRAMEBUF_LIST_S *pFrameBufList, UInt32 timeout)
{
    VIDFrame_BufList  vidBufList;
    VIDFrame_Buf     *pInBuf;
    VIDEO_FRAMEBUF_S *pOutBuf;
    UInt32 i;

	if (gVdisModuleContext.ipcFramesOutHostId == SYSTEM_LINK_ID_INVALID)
		return 0;

    VDIS_TRACE_FXN_ENTRY();
    pFrameBufList->numFrames = 0;
    vidBufList.numFrames = 0;
    IpcFramesOutLink_getEmptyVideoFrames(gVdisModuleContext.ipcFramesOutHostId,
                                         &vidBufList);

    pFrameBufList->numFrames = vidBufList.numFrames;
    for (i = 0; i < vidBufList.numFrames; i++)
    {
        pOutBuf = &pFrameBufList->frames[i];
        pInBuf = &vidBufList.frames[i];

        Vdis_copyVidFrameInfoLink2McFw(pOutBuf,pInBuf);
    }

    VDIS_TRACE_FXN_EXIT("NumFrames Received:%d",pFrameBufList->numFrames);
    return 0;
}

Void Vdis_swMs_PrintLayoutParams(VDIS_DEV vdDevId, SwMsLink_LayoutPrm * vdMosaicParam)
{
	#if TI_VDIS_DEBUG
    UInt32 chNum;

    OSA_printf ("\n ***  SW Mosaic Parameters *** NumWindows %d,  onlyCh2WinMapChanged %d\n",
            vdMosaicParam->numWin,
            vdMosaicParam->onlyCh2WinMapChanged);

    OSA_printf( " \n"
            " ***  SW Mosaic Parameters *** \n"
            " \n"
            " Win | Ch  | Output     |  Output         | Low Cost \n"
            " Num | Num | Start X, Y |  Width x Height | ON / OFF \n"
            " --------------------------------------------------- \n"
            );

    for (chNum=0; chNum < VDIS_CHN_MAX; chNum++)
    {
        OSA_printf ("\n ChNum %d, WinMap %d, Enable %d",
        chNum,
        gVdisChnMapInfo[vdDevId].ch2WinMap[chNum],
        gVdisChnMapInfo[vdDevId].isEnableChn[chNum]);
    }
    OSA_printf( " \n");
	#endif
}

static
Void  Vdis_copyChannelInfo(VIDEO_CHANNEL_LIST_INFO_S *dst,
                           System_LinkQueInfo        *src)
{
    Int i;

    OSA_COMPILETIME_ASSERT(OSA_ARRAYSIZE(src->chInfo)  ==
                           OSA_ARRAYSIZE(dst->chInfo));
    OSA_assert(src->numCh <= OSA_ARRAYSIZE(src->chInfo));
    dst->numCh = src->numCh;
    for (i = 0; i < src->numCh; i++)
    {
        dst->chInfo[i].width  = src->chInfo[i].width;
        dst->chInfo[i].height = src->chInfo[i].height;
    }
}

Int32 Vdis_getChannelInfo(VIDEO_CHANNEL_LIST_INFO_S *channelListInfo)
{
    System_LinkQueInfo inQueInfo;
    Int32 status;

    status =
    IpcFramesOutLink_getInQueInfo(gVdisModuleContext.ipcFramesOutHostId,
                                  &inQueInfo);
    if (status == ERROR_NONE)
    {
        Vdis_copyChannelInfo(channelListInfo,&inQueInfo);
    }
    else
    {
        inQueInfo.numCh = 0;
    }
    return status;
}

/**
 * \brief:
 *      Switch the queue from which frame are displayed
 * \input:
 *      vdDevId                -- Device id
 *      queueId                -- QueueID to switch to
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS          --    while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_switchActiveQueue(VDIS_DEV vdDevId, UInt32 queueId)
{
    Int32 status = ERROR_NONE;
    DisplayLink_SwitchActiveQueueParams prm;

    /* Multiple input queues is supported only for SD display
     * presently
     */
    if(vdDevId == VDIS_DEV_SD)
    {
        prm.activeQueueId = queueId;
        System_linkControl(Vdis_getDisplayId(vdDevId),
                           DISPLAY_LINK_CMD_SWITCH_ACTIVE_QUEUE,
                           &prm,
                           sizeof(prm),
                           TRUE);
    }
    else
    {
        status = ERROR_FAIL;
    }
    return status;
}
/**
 * \brief:
 *      Switch the queue from which frame are displayed
 * \input:
 *      vdDevId                -- Device id
 *      channelId              -- channelId to switch to
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS          --    while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_switchActiveChannel(VDIS_DEV vdDevId, UInt32 channelId)
{
    Int32 status = ERROR_NONE;

    return status;
}

/**
 * \brief:
 *      Switch the channel Id for SDTV live bypass path
 * \input:
 *      vdDevId                -- Device id
 *      chId                -- chID to switch to
 * \output:
 *      NA
 * \return
*       TI_MEDIA_SUCCESS          --    while success
*       ERROR_CODE          --  refer for err defination
*/
Int32 Vdis_switchSDTVChId(VDIS_DEV vdDevId, UInt32 chId)
{
    Int32 status = ERROR_NONE;
    DisplayLink_SwitchChannelParams prm;


    /* Multiple input queues is supported only for SD display
     * presently
     */
    if(vdDevId == VDIS_DEV_SD)
    {
        Vcap_setExtraFramesChId(chId);

        prm.activeChId = chId;
        System_linkControl(Vdis_getDisplayId(vdDevId),
                           DISPLAY_LINK_CMD_SWITCH_CH,
                           &prm,
                           sizeof(prm),
                           TRUE);
    }
    else
    {
        status = ERROR_FAIL;
    }
    return status;
}
/**
  * \brief:
  *     get channel input information from win ID
  * \input:
  *     vdDevId     -- Mosaic id
  *     winId       -- win ID which we want to get the channel information
  * \output:
  *     psChnlInfo  -- channel input infomation
  * \return:
  *     Always return success
  */

Int32 Vdis_getChnlInfoFromWinId(VDIS_DEV vdDevId, UInt32 winId, WINDOW_S * psChnlInfo)
{
    SwMsLink_WinInfo inputInfo;
    UInt32 swMsId = 0;

    if( vdDevId == VDIS_DEV_HDMI)
    {
        swMsId = gVdisModuleContext.swMsId[0];
    }
    else if( vdDevId == VDIS_DEV_DVO2)
    {
        swMsId = gVdisModuleContext.swMsId[1];
    }
    else if(vdDevId == VDIS_DEV_SD)
    {
        swMsId = gVdisModuleContext.swMsId[0];
    }
    else
    {
        swMsId = SYSTEM_LINK_ID_INVALID;
        return -1;
    }

    inputInfo.winId = winId;

    System_linkControl(swMsId, SYSTEM_SW_MS_LINK_CMD_GET_INPUT_CHNL_INFO, &(inputInfo), sizeof(inputInfo), TRUE);

    psChnlInfo->width       = inputInfo.width;
    psChnlInfo->height      = inputInfo.height;
    psChnlInfo->start_X     = inputInfo.startX;
    psChnlInfo->start_Y     = inputInfo.startY;

    return 0;
}


/**
  * \brief:
  *     set channel crop settings from window ID
  * \input:
  *     vdDevId     -- Mosaic id
  *     winId       -- win ID which we want to get the channel information
  *     cropParam   -- crop settings to apply
  * \return:
  *     Always return success
  */

Int32 Vdis_SetCropParam(VDIS_DEV vdDevId, UInt32 winId, WINDOW_S cropParam)
{
    SwMsLink_WinInfo inputInfo;
    UInt32 swMsId = 0;

    if( vdDevId == VDIS_DEV_HDMI) {
        swMsId = gVdisModuleContext.swMsId[0];
    }
    else if( vdDevId == VDIS_DEV_DVO2) {
        swMsId = gVdisModuleContext.swMsId[1];
    }
    else if(vdDevId == VDIS_DEV_SD) {
        swMsId = gVdisModuleContext.swMsId[0];
    }
    else {
        swMsId = SYSTEM_LINK_ID_INVALID;
    }

    inputInfo.winId     = winId;
    inputInfo.width     = cropParam.width;
    inputInfo.height    = cropParam.height;
    inputInfo.startX    = cropParam.start_X;
    inputInfo.startY    = cropParam.start_Y;

    System_linkControl(swMsId, SYSTEM_SW_MS_LINK_CMD_SET_CROP_PARAM, &(inputInfo), sizeof(inputInfo), TRUE);

    return 0;
}

void Vdis_swMs_pause(VDIS_DEV vdDevId, int value)
{
	UInt32 swMsId = 0;

	if( vdDevId == VDIS_DEV_DVO2) {
        swMsId = gVdisModuleContext.swMsId[1];
    }
    else if(vdDevId == VDIS_DEV_SD) {
        swMsId = gVdisModuleContext.swMsId[0];
    }
    else {
        swMsId = SYSTEM_LINK_ID_INVALID;
    }

	System_linkControl(swMsId, SYSTEM_SW_MS_LINK_CMD_PAUSE, &value, sizeof(value), TRUE);
}

void Vdis_set_standard(int pal)
{
	if(pal) {
		std_sd = VSYS_STD_PAL;
	}
	else {
		std_sd = VSYS_STD_NTSC;
	}
}

void Vdis_disp_ctrl_init(void)
{
	//# phoong - for open the fb
	Vdis_params_init(&gVdisModuleContext.vdisConfig);

	MultiCh_displayCtrlInit(&gVdisModuleContext.vdisConfig);

	OSA_printf(" %s done\n", __func__);
}

void Vdis_disp_ctrl_exit(void)
{
	MultiCh_displayCtrlDeInit(&gVdisModuleContext.vdisConfig);
}
