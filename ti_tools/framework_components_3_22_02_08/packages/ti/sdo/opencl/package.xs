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
 *  ======== package.xs ========
 *
 */


/*
 *  ======== close ========
 */
function close()
{
    /* opencl implementation uses the following modules */
    xdc.useModule('ti.sdo.rcm.RcmClient');
}


/*
 *  ======== getLibs ========
 */
function getLibs(prog)
{
    var suffix;
    var file;
    var name;
    var libAry = [];
    var profile = this.profile;

    suffix = prog.build.target.findSuffix(this);
    if (suffix == null) {
        return "";  // nothing to contribute
    }

    // check which library to use
    if (this.OpenCL.$used) {
        name = "opencl_api";
    }
    else if (this.ComputeDevice.$used) {
        name = "opencl_runtime";
    }
    else {
        throw new Error("must use a module from this package.");
    }

    // make sure the library exists, else fallback to a built library
    file = "lib/" + profile + "/" + name +".a" + suffix;
    if (java.io.File(this.packageBase + file).exists()) {
        libAry.push(file);
    }
    else {
        file = "lib/release/" + name + ".a" + suffix;
        if (java.io.File(this.packageBase + file).exists()) {
            libAry.push(file);
        }
        else {
            // fallback to a compatible library built by this package
            for (var p in this.build.libDesc) {
                if ((this.build.libDesc[p].suffix == suffix) &&
                    (p.match(RegExp("/"+ name + "/")))) {
                    libAry.push(p);
                    break;
                }
            }
        }
    }

    return libAry.join(";");
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,3; 4-16-2012 00:03:02; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

