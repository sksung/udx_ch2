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
 *  ======== InterruptDsp.xs ========
 *
 */

var Hwi             = null;
var Cache           = null;
var MultiProc       = null;

/*
 *  ======== module$use ========
 */
function module$use()
{        
    Hwi         = xdc.useModule("ti.sysbios.family.c64p.Hwi");
    Cache       = xdc.useModule("ti.sysbios.family.c64p.Cache");
    MultiProc   = xdc.useModule("ti.sdo.utils.MultiProc");
    Ipc         = xdc.useModule("ti.sdo.ipc.Ipc");
    
    this.dspProcId      = MultiProc.getIdMeta("DSP");
    this.arp32ProcId     = MultiProc.getIdMeta("ARP32");
    
    /* must disable MAR89 which contains the mailbox registers */
    if (Cache.MAR64_95 === undefined) {
        Cache.MAR64_95 = 0;
    }
    else {
        /* MAR89 is bit 25, must zero this bit */
        Cache.MAR64_95 &= 0xFDFFFFFF;
    }
}

function module$static$init(mod, params)
{
    mod.fxnTable.func  = null;
    mod.fxnTable.arg   = 0;
    
    mod.numPlugged = 0;
}


/*
 *  @(#) ti.sdo.ipc.family.arctic; 1, 0, 0, 0,2; 2-11-2012 16:30:48; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

