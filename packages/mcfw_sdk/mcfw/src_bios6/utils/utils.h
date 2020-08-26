/*******************************************************************************
 *                                                                             *
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

#ifndef _UTILS_H_
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#define _UTILS_H_

#include <mcfw/src_bios6/utils/utils_common.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/utils/Load.h>
#include <ti/sysbios/hal/Cache.h>

#include <ti/psp/vps/vps.h>

#include <mcfw/src_bios6/utils/utils_trace.h>
#include <mcfw/src_bios6/utils/utils_prf.h>

#include <mcfw/interfaces/link_api/system_linkId.h>

#define UTILS_MAX_BITSTREAM_BUF_PTR  (64)

typedef struct Utils_frameSkipContext {
   Int32 inputFrameRate;
   Int32 outputFrameRate;
   Int32 firstTime;
   Int32 inCnt;
   Int32 outCnt;
   Int32 multipleCnt;
} Utils_frameSkipContext;

int Utils_setL3Pri(UInt32 initPressure0, UInt32 initPressure1);

int xstrtoi(char *hex);

UInt32 Utils_setCpuFrequency (UInt32 freq);

UInt32 Utils_getCurTimeInMsec();

UInt64 Utils_getCurTimeInUsec();

UInt64 Utils_getTimeIn64bit(FVID2_Frame *pFrame);


Bool Utils_doSkipFrame(Utils_frameSkipContext *frameSkipCtx );


#define UTILS_SNPRINTF(sbuf,...)                                               \
                                do {                                           \
                                    snprintf (sbuf, sizeof(sbuf) - 1,          \
                                              __VA_ARGS__);                    \
                                    sbuf[sizeof(sbuf) - 1] = 0;                \
                                } while (0)

#define UTILS_ARRAYSIZE(array)             ((sizeof(array)/sizeof((array)[0])))

#define UTILS_ARRAYINDEX(elem,array)                   ((elem) - &((array)[0]))

#define UTILS_ARRAYISVALIDENTRY(elem,array) ((UTILS_ARRAYINDEX(elem,array) <   \
                                             UTILS_ARRAYSIZE(array))           \
                                             ? TRUE                            \
                                             : FALSE)

#define UTILS_DIV(num,den)                  (((den) != 0) ? ((num)/(den)) : 0)

static inline UInt32 Utils_getNumPlanes(FVID2_DataFormat dataFormat)
{
    UInt32 numPlanes = 0;

    switch(dataFormat)
    {
        case FVID2_DF_YUV422I_UYVY:
        case FVID2_DF_YUV422I_YUYV:
        case FVID2_DF_YUV422I_YVYU:
        case FVID2_DF_YUV422I_VYUY:
        case FVID2_DF_YUV444I:
            numPlanes = 1;
            break;
        case FVID2_DF_YUV422SP_UV:
        case FVID2_DF_YUV422SP_VU:
        case FVID2_DF_YUV420SP_UV:
        case FVID2_DF_YUV420SP_VU:
            numPlanes = 2;
            break;
        case FVID2_DF_YUV422P:
        case FVID2_DF_YUV420P:
        case FVID2_DF_YUV444P:
            numPlanes = 3;
            break;
        default:
            Vps_printf("UTILS:!WARNING.Unknow data format[%d].Setting numPlanes to zero",
                       dataFormat);
            numPlanes = 0;
    }
    return numPlanes;
}

void Utils_get_walltime(UInt64 *wall_time);
void Utils_set_walltime(UInt64 wall_time);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif                                                     /* ifndef
                                                            * _UTILS_TRACE_H_
                                                            */
