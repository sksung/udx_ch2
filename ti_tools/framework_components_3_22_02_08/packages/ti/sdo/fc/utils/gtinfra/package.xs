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
 * ======== getLibs ========
 */
function getLibs(prog)
{
    var gtinfra = this.GTINFRA;
    var suffix;
    var libName;
    var profile;
    var isa = prog.build.target.isa;

    // Get the target suffix (eg, "64P", "470MV")
    suffix = Program.build.target.findSuffix(this);
    if (suffix == null) {
        print(this.$name + ".getLibs(): Can't find suffix for " +
              prog.build.target.name + " target.");
        return (null);
    }

    if (gtinfra.runtimeEnv == gtinfra.NONE) {
        lib = "gt_noOS.a" + suffix;

    }
    else if (gtinfra.runtimeEnv == gtinfra.DSPBIOS) {
        lib = "gt_bios.a" + suffix;
    }
    else if (gtinfra.runtimeEnv == gtinfra.WINCE) {
        lib = "gt_wince.a" + suffix;
    }
    else {
        throw(" Bad OS TYPE configured: " + this.runtimeEnv);
    }

    var dir = "lib/" + this.profile;

    if (!java.io.File(this.packageBase + dir + "/" + lib).exists()) {
        print(this.$name + ": Requested profile '" + this.profile + "' does "
                + "not exist.\n\tDefaulting to the 'release' profile");

       dir = "lib/release";
    }

    return (dir + "/" + lib);
}

/*
 *  ======== getSects ========
 */
function getSects()
{
    if (0) {
        /* there is a linker command file for BIOS flavors */
        if (this.GTINFRA.runtimeEnv == this.GTINFRA.DSPBIOS) {
            return (this.$name.replace(/\./g, "/") + "/link.xdt");
        }
    }

    return (null);
}

/*
 *  ======== close ========
 */
function close() {

    if ((this.GTINFRA.debug) ) {
        print(this + ": This module no longer supports the .debug "
                + "or the .trace config params. Set desired profile for all "
                + "FC modules as follows: "
                + "xdc.useModule\('ti.sdo.fc.global.Settings'\).profile = "
                + "\"debug\""
                + " or set profiles for individual packages like this: "
                + "xdc.loadPackage('"
                + this + "').profile = \"debug\"\;"
                + " .\n\tDefaulting to the 'release' profile");
    }

    if (this.profile == undefined) {
        this.profile = xdc.useModule('ti.sdo.fc.global.Settings').profile;
    }

/*      xdc.useModule('ti.sdo.utils.trace.GT');*/

    xdc.useModule("xdc.runtime.System");

    // Set up to use BIOS6 semaphore
    if (this.GTINFRA.runtimeEnv == this.GTINFRA.DSPBIOS) {
        var sem = xdc.useModule('xdc.runtime.knl.SemThread');
        sem.Proxy = xdc.useModule('ti.sysbios.xdcruntime.SemThreadSupport');
    }
}

/*
 *  @(#) ti.sdo.fc.utils.gtinfra; 1, 0, 0,3; 4-16-2012 00:02:45; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

