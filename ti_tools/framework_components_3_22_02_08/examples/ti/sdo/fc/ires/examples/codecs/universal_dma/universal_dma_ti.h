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
 * */
/*
 *  ======== universal_dma_ti.h ========
 *  Interface for the audio decoder copy example that uses an example IRES
 *  resource. This example exposes both an IUNIVERSAL_Fxns interface and an
 *  IRES_Fxns interface.
 */
#ifndef UNIVERSAL_DMA_TI_
#define UNIVERSAL_DMA_TI_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/xdais/dm/iuniversal.h>

/*
 *  ======== UNIVERSAL_DMA_TI_IALG ========
 *  Our implementation of the IALG interface
 */
extern IALG_Fxns UNIVERSAL_DMA_TI_IALG;

/*
 *  ======== UNIVERSAL_DMA_TI_CODECIRES ========
 *  Our implementation of the IUNIVERSAL interface
 */
extern IUNIVERSAL_Fxns UNIVERSAL_DMA_TI_CODECIRES;

/*
 *  ======== UNIVERSAL_DMA_TI_IRES ========
 *  Our implementation of the IRES_Fxns interface
 */
extern IRES_Fxns UNIVERSAL_DMA_TI_IRES;


/*
 *  ======== UNIVERSAL_DMA_TI_PARAMS ========
 */
extern IUNIVERSAL_Params UNIVERSAL_DMA_TI_PARAMS;

typedef struct UNIVERSAL_DMA_InArgs {
    XDAS_Int32 size;
    XDAS_Int32 numBytes;
} UNIVERSAL_DMA_InArgs;



#ifdef __cplusplus
}
#endif

#endif
/*
 *  @(#) ti.sdo.fc.ires.examples.codecs.universal_dma; 1, 0, 0,3; 4-16-2012 00:01:24; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

