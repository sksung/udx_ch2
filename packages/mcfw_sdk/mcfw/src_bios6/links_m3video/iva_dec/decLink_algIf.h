/*******************************************************************************
 *                                                                             *
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

#ifndef _DEC_LINK_ALG_IF_H_
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define _DEC_LINK_ALG_IF_H_

#include <mcfw/interfaces/link_api/decLink.h>
#include <ih264vdec.h>
#include <ijpegvdec.h>

#define DEC_LINK_H264_VERSION_STRING_MAX_LEN                              (255)
#define DEC_LINK_MPEG4_VERSION_STRING_MAX_LEN                             (255)
#define DEC_LINK_JPEG_VERSION_STRING_MAX_LEN                              (255)

typedef struct DecLink_AlgCreateParams {
    IVIDEO_Format format;
    Bool  fieldMergeDecodeEnable;
    Int32 maxWidth;
    Int32 maxHeight;
    Int32 maxFrameRate;
    Int32 maxBitRate;
    Int32 presetProfile;
    Int32 presetLevel;
    Int32 displayDelay;
    Bool tilerEnable;
    Int32 processCallLevel;
    Int32 dpbBufSizeInFrames;
} DecLink_AlgCreateParams;

typedef struct DecLink_AlgDynamicParams {
    XDM_DecMode decodeHeader;
    Int32 displayWidth;
    Int32 frameSkipMode;
    Int32 newFrameFlag;
} DecLink_AlgDynamicParams;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif                                                     /* _DEC_LINK_ALG_IF_H_
                                                            */
