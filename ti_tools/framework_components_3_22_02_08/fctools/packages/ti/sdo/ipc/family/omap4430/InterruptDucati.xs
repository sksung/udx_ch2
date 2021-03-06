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
 *  ======== InterruptDucati.xs ========
 *
 */

var Hwi             = null;
var Core            = null;
var MultiProc       = null;

/*
 *  ======== module$use ========
 */
function module$use()
{        
    Hwi         = xdc.useModule("ti.sysbios.family.arm.m3.Hwi");
    Core        = xdc.useModule("ti.sysbios.family.arm.ducati.Core");
    MultiProc   = xdc.useModule("ti.sdo.utils.MultiProc");
    Ipc         = xdc.useModule("ti.sdo.ipc.Ipc");
    
    this.dspProcId    = MultiProc.getIdMeta("DSP");
    this.core0ProcId  = MultiProc.getIdMeta("CORE0");
    this.core1ProcId  = MultiProc.getIdMeta("CORE1");
    this.hostProcId   = MultiProc.getIdMeta("HOST");    
}

/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{    
    /* M3 to C674 */
    mod.fxnTable[0].func  = null;
    mod.fxnTable[0].arg   = 0;
    
    /* HOST to M3 */
    mod.fxnTable[1].func  = null;
    mod.fxnTable[1].arg   = 0;
    
    /* Inter-M3 interrupt */
    mod.fxnTable[2].func  = null;
    mod.fxnTable[2].arg   = 0;
    
    mod.numPlugged = 0;
}
/*
 *  @(#) ti.sdo.ipc.family.omap4430; 1, 0, 0, 0,2; 2-11-2012 16:31:01; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

