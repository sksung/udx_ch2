/*
 * package.xs
 *
 * XDC script file for the RM module
 *
 * Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

/*
 * ======== package.xs ========
 *
 */

/*
 * ======== getLibs ========
 */
function getLibs(prog)
{
    var bool = 0;

    print ("Inside EDMA3 RM getLibs");

    /* Prepare variables to form the library path within this package */
    var name = "edma3_lld_rm";
    var lib = "lib/";
    var target;
    var extension;

    /* Boards supported */
    var boards = [
                        'evmDA830',
                        'simTCI6608',
                        'simTCI6616',
                        'evm6670',
                        'evm6678',
                        'evm6748',
                        'evmOMAPL138',
                        'simDM8168',
                        'evmDM8168',
                        'evm6472',
                        'evmTCI6486',
                        'evmDM8148',
                        'evmTI814X',
                        'evmTI816X',
                    ];

    /* Directories for each platform */
    var dir = [
                'da830-evm/',
                'tci6608-sim/',
                'tci6616-sim/',
                'c6670-evm/',
                'c6678-evm/',
                'c6748-evm/',
                'omapl138-evm/',
                'ti816x-sim/',
                'ti816x-evm/',
                'c6472-evm/',
                'tci6486-evm/',
                'ti814x-evm/',
                'ti814x-evm/',
                'ti816x-evm/',
              ];

    for (var i = 0; i < boards.length; i++)
        {
        if (java.lang.String(Program.platformName).contains(boards[i]))
            {
                /* Choose the selected platform and build the complete name   */
                lib = lib + dir[i];
                extension = ".a" + Program.build.target.suffix;
                if (java.lang.String(Program.build.target.suffix).contains('674'))
                	target = "674/";
                if (java.lang.String(Program.build.target.suffix).contains('64P'))
                	target = "64p/";
                if (java.lang.String(Program.build.target.suffix).contains('66'))
                	target = "66/";
                if (java.lang.String(Program.build.target.suffix).contains('a8'))
                	target = "a8/";
                if (java.lang.String(Program.build.target.suffix).contains('m3'))
                	target = "m3/";
                if (java.lang.String(Program.build.target.suffix).contains('9'))
                	target = "arm9/";
                lib = lib + target;
                bool = 1;
                break;
            }
        }

    if (bool == 0) {
        /*
        throw new Error('Unexpected value in "platform" parameter')
        */
        lib = lib + "generic/";
        extension = ".a" + Program.build.target.suffix;
        if (java.lang.String(Program.build.target.suffix).contains('674'))
        	target = "674/";
        if (java.lang.String(Program.build.target.suffix).contains('64P'))
        	target = "64p/";
        if (java.lang.String(Program.build.target.suffix).contains('66'))
        	target = "66/";
        if (java.lang.String(Program.build.target.suffix).contains('a8'))
        	target = "a8/";
        if (java.lang.String(Program.build.target.suffix).contains('m9'))
        	target = "m9/";
        if (java.lang.String(Program.build.target.suffix).contains('9'))
        	target = "arm9/";
        lib = lib + target;

    }

    switch (this.profile) {
    case 'debug':
        /* enable debug build for debug profile only */
        lib = lib + "debug/" + name + extension;
        break;

    default:
        /* release profile for everything else */
        lib = lib + "release/" + name + extension;
    }

    print("    will link with " + this.$name + ":" + lib);

    /* return the library name */
    return (lib);
}

