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
 *  ======== TimerSupport.xs ========
 *
 */

var TimerSupport = null;
var numTimers = 2;              /* should be retrieved from catalog file */

/*
 *  ======== module$meta$init ========
 */
function module$meta$init()
{
    /* Only process during "cfg" phase */
    if (xdc.om.$name != "cfg") {
        return;
    }

    TimerSupport = this;

    TimerSupport.timer.length = numTimers;
    for (var i=0; i < numTimers; i++) {
        TimerSupport.timer[i].suspSrc = TimerSupport.SuspSrc_DSP;
    }
    
    /* set fxntab default */
    TimerSupport.common$.fxntab = false;
}

/*
 *  ======== module$use ========
 */
function module$use()
{
}

/*
 *  ======== module$static$init ========
 */
function module$static$init(mod, params)
{
    mod.suspSrc.length = numTimers;

    for (var i=0; i < mod.suspSrc.length; i++) {
        mod.suspSrc[i] = params.timer[i].suspSrc;
    }
}
/*
 *  @(#) ti.sysbios.family.c64p.primus; 2, 0, 0, 0,411; 5-18-2012 06:04:54; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

