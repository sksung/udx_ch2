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
 *  ======== PIP.xs ========
 *
 */

/*
 *  ======== instance$meta$init ========
 *  Initializes instance name to the name parameter.
 */
function instance$meta$init(name)
{
    var PIP = xdc.module('ti.bios.PIP');

    if (!name) {
        PIP.$logError("PIP instance needs a name", this);
    }
    if (name.indexOf('_') == 0) {
        name = name.substr(1);
    }
    this.name = name;
}

/*
 *  ======== close ========
 */
function close()
{
    var insts = this.$instances;

    /* Add PIP_startup into the startup if there are static devices */
    if (insts.length > 0) {
        var BIOS = xdc.module("ti.sysbios.BIOS");
        BIOS.addUserStartupFunction('&PIP_startup');

        /* Loop through all instances and deal with inst.bufSeg */
        for (var i = 0; i < insts.length; i++) {
            if (insts[i].bufSeg != null) {
                /* place the buffers into specified MEM segment */
                Program.sectMap["_" + insts[i].name + "$bufs"] = 
                    insts[i].bufSeg.name;
            }
        }

    }
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
 *  @(#) ti.bios; 5, 6, 0,546; 5-18-2012 06:03:21; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

