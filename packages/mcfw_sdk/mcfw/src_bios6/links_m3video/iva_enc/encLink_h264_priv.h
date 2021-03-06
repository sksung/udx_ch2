/*******************************************************************************
 *                                                                             *
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

#ifndef _ENC_LINK_H264_PRIV_H_
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define _ENC_LINK_H264_PRIV_H_

#include <mcfw/interfaces/link_api/encLink.h>
#include <ih264enc.h>
#include "encLink_algIf.h"

/**
 *  Analytic info output buffer size, this buffer is used to place MV & SAD of
 *  encoded frame, should be big enough to hold the size of  typical HD sequence
*/
#define ANALYTICINFO_OUTPUT_BUFF_SIZE      0x00028000

#define ALG_VID_ENC_RATE_CONTROL_VBR    0
#define ALG_VID_ENC_RATE_CONTROL_CBR    1
#define ALG_VID_ENC_RATE_CONTROL_CVBR   2

#define ALG_VID_ENC_PRESET_AUTO     		0
#define ALG_VID_ENC_PRESET_HIGHSPEED   		1
#define ALG_VID_ENC_PRESET_HIGHQUALITY 		2
#define ALG_VID_ENC_PRESET_SVC_AUTO        	3

#define ALG_VID_ENC_ROI_PRIORITY_NONE      0
#define ALG_VID_ENC_ROI_PRIORITY_LOW       1
#define ALG_VID_ENC_ROI_PRIORITY_MEDIUM    2
#define ALG_VID_ENC_ROI_PRIORITY_HIGH      3

typedef struct EncLink_H264Obj {
    IH264ENC_Handle algHandle;
    Int8 versionInfo[ENC_LINK_ALG_VERSION_STRING_MAX_LEN];
    Int linkID;
    Int channelID;
    Int scratchID;
    UInt32 ivaChID;
    IH264ENC_DynamicParams dynamicParams;
    IH264ENC_Status status;
    IH264ENC_Params staticParams;
    IH264ENC_InArgs inArgs;
    IH264ENC_OutArgs outArgs;
    IVIDEO2_BufDesc inBufs;
    XDM2_BufDesc outBufs;
    IVIDEO_Format format;
    UInt32 memUsed[UTILS_MEM_MAXHEAPS];
} EncLink_H264Obj;

Int EncLinkH264_algCreate(EncLink_H264Obj * hObj,
                          EncLink_AlgCreateParams * algCreateParams,
                          EncLink_AlgDynamicParams * algDynamicParams,
                          Int linkID, Int channelID, Int scratchGroupID);
Void EncLinkH264_algDelete(EncLink_H264Obj * hObj);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif                                                     /* _ENC_LINK_PRIV_H_
                                                            */
