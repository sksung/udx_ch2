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
 *  ======== fcpy_ti_idma3vt.c ========
 *  This file contains the function table definitions for the
 *  IDMA3 interface implemented by the FCPY_TI module.
 */
#include <xdc/std.h>

#include <ti/xdais/idma3.h>
#include <fcpy_ti.h>
#include <fcpy_ti_priv.h>

/*
 *  ======== FCPY_TI_IDMA3 ========
 *  This structure defines TI's implementation of the IDMA2 interface
 *  for the FCPY_TI module.
 */
IDMA3_Fxns FCPY_TI_IDMA3 = {      /* module_vendor_interface */
    &FCPY_TI_IALG,              /* IALG functions */    
    FCPY_TI_dmaChangeChannels,  /* ChangeChannels */
    FCPY_TI_dmaGetChannelCnt,   /* GetChannelCnt */
    FCPY_TI_dmaGetChannels,     /* GetChannels */
    FCPY_TI_dmaInit             /* initialize logical channels */
};




/*
 *  @(#) ti.sdo.fc.dman3.examples.fastcopy; 1, 0, 0,3; 4-16-2012 00:00:08; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

