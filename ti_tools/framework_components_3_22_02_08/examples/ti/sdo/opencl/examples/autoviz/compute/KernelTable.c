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
 *  ======== KernelTable.c ========
 *
 */

#include <xdc/std.h>
#include <ti/sdo/opencl/ComputeDevice.h>

#include "PdKnl.h"
#include "TsrKnl.h"


/*  must declare these two symbols
 *
 *  ti_sdo_opencl_ComputeDevice_units           // array of units
 *  ti_sdo_opencl_ComputeDevice_numUnits        // number of units
 */

ComputeDevice_Unit ti_sdo_opencl_ComputeDevice_units[] = {

    {   /* PdKnl */
        PdKnl_init,
        PdKnl_exit,
        PdKnl_numFxns,
        PdKnl_fxnTab
    },
    {   /* TsrKnl */
        TsrKnl_init,
        TsrKnl_exit,
        TsrKnl_numFxns,
        TsrKnl_fxnTab
    }
};

Int ti_sdo_opencl_ComputeDevice_numUnits = 2;
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,3; 4-16-2012 00:03:04; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

