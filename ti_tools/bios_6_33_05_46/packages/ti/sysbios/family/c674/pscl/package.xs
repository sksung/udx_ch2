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
 *  ======== package.xs ========
 *
 */

function close()
{
    Power = xdc.module("ti.sysbios.family.c674.Power");

    /* if using a pre-built PMI library load the pmi package */
    if (Power.pmiControlLib != Power.pmiLib_user) {
        xdc.loadPackage('ti.sysbios.family.c674.pmi');
    }
}

function getLibs(prog)
{
    var Power = xdc.module("ti.sysbios.family.c674.Power");
    var lib;

    if (Power.psclConfigLib == Power.psclLib_evm6748) {
        lib = "lib/release/" + "psclLib_evm6748.a" + prog.build.target.suffix;
    }
    else if (Power.psclConfigLib == Power.psclLib_evm6748_372) {
        lib = "lib/release/" + "psclLib_evm6748_372.a" + prog.build.target.suffix;
    }
    else if (Power.psclConfigLib == Power.psclLib_evm6748_408) {
        lib = "lib/release/" + "psclLib_evm6748_408.a" + prog.build.target.suffix;
    }
    else if (Power.psclConfigLib == Power.psclLib_evm6748_456) {
        lib = "lib/release/" + "psclLib_evm6748_456.a" + prog.build.target.suffix;
    }
    else if (Power.psclConfigLib == Power.psclLib_lcdk) {
        lib = "lib/release/" + "psclLib_lcdk.a" + prog.build.target.suffix;
    }
    else if (Power.psclConfigLib == Power.psclLib_null) {
        lib = "lib/release/" + "psclLib_null.a" + prog.build.target.suffix;
    }

    if (java.io.File(this.packageBase + lib).exists()) {
        return lib;
    }
    else {
        throw Error("Library not found: " + lib);
    }
}
/*
 *  @(#) ti.sysbios.family.c674.pscl; 1, 0, 0,24; 5-18-2012 06:05:13; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

