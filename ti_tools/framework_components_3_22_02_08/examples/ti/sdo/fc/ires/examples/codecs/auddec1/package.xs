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
 *    Implementation of the xdc.IPackage interface.
 */

/*
 *  ======== getLibs ========
 *  Determine the name of the library to use, based on the program
 *  configuration (prog).
 */
function getLibs(prog)
{
    var suffix = prog.build.target.findSuffix(this);

    if (null == suffix) {
        return (null);
    }

    /*
     * Note that this package demonstrates several different ways to
     * build, including CCS projects, GNU makefiles and XDC Builds.
     * The location of the libraries, however are always in the same place.
     * As a result, this getLibs function is relatively simple.
     */

     var lib = "auddec1_ti.a" + suffix;

     var dir = "lib/" + this.profile;

     if (!java.io.File(this.packageBase + dir + "/" + lib ).exists()) {

         print(this.$name + ": Requested profile '" + this.profile + "' does"
                    + " not exist.\n\tDefaulting to the 'release' profile");

         dir = "lib/release";
     }

    return (dir + "/" + lib);
}


/*
 *  ======== close ========
 */
function close() {

    xdc.loadPackage("ti.xdais");

    xdc.useModule("ti.sdo.fc.ires.bufres.BUFRES");
}
/*
 *  @(#) ti.sdo.fc.ires.examples.codecs.auddec1; 1, 0, 0,3; 4-16-2012 00:01:14; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

