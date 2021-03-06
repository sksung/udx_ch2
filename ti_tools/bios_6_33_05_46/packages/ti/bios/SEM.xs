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
 *  ======== SEM.xs ========
 *
 */
 
/*
 *  ======== module$meta$init ========
 *  Stores defaults. Sets up $private.realModule.
 */
function module$meta$init()
{
    /* Only process during "cfg" phase */
    if (xdc.om.$name != "cfg") {
        return;
    }

    var Semaphore = xdc.module('ti.sysbios.knl.Semaphore');
    this.$private.bios6xMod = Semaphore;
}

/*
 *  ======== instance$meta$init ========
 *  Initializes instance name to the name parameter.
 */
function instance$meta$init(name)
{
    if (name.indexOf('_') == 0) {
        name = name.substr(1);
    }
    this.name = name;
}

/*
 *  ======== close ========
 *  Create a Semaphore instance for each SEM instance.  Make the SEM instance
 *  name a global symbol. This function is called in close() of package.xs
 */
function close()
{
    var Sem = xdc.module("ti.sysbios.knl.Semaphore");

    /* Loop through each SEM instance and create a Semaphore instance */
    var insts = this.$instances;

    for (var i = 0; i < insts.length; i++) {
        Program.symbol[insts[i].name] = Sem.create(insts[i].count);
    }
}

/*
 *  ======== exportMod ========
 */
function exportMod()
{
    Program.exportModule("ti.sysbios.knl.Semaphore");
}

/*
 *  ======== destroy ========
 */
function destroy()
{
    this.$logError("Please remove the associated create() call, " +
        "the destroy() method is not supported", this);
}
/*
 *  @(#) ti.bios; 5, 6, 0,546; 5-18-2012 06:03:22; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

