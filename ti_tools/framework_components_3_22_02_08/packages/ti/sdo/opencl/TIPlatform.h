/* 
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

/*
 *  ======== TIPlatform.h ========
 */

#ifndef ti_sdo_opencl_TIPlatform__include
#define ti_sdo_opencl_TIPlatform__include

#include <CL/cl.h>
#include <ti/sdo/opencl/TIDevice.h>

#if defined (__cplusplus)
extern "C" {
#endif

struct _cl_platform_id
{
    const char *                profile;
    const char *                version;
    const char *                name;
    const char *                vendor;
    const char *                extensions;
    ti_sdo_opencl_DeviceArray   devices;
    void *                      heapH; /* IHeap_Handle */
};

typedef struct {
    int                 length;
    cl_platform_id *    elem;
} ti_sdo_opencl_PlatformArray;

extern ti_sdo_opencl_PlatformArray ti_sdo_opencl_Platforms;


/* TI extensions */

cl_device_id    TIPlatform_getDeviceType(cl_device_type type);
void *          TIPlatform_getHeapHandle(cl_platform_id platform);
int             TIPlatform_setHeapHandle(cl_platform_id platform, void *heapH);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* ti_sdo_opencl_TIPlatform__include */
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,3; 4-16-2012 00:03:02; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

