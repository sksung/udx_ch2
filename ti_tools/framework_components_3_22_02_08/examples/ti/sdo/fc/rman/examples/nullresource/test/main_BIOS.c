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
 *  ======== main_BIOS.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <ti/sysbios/BIOS.h>

#include <ti/xdais/ires.h>

#include <ti/sdo/fc/rman/rman.h>

extern Void smain(Int argc, Char * argv[]);

/*
 *  ======== main ========
 */
/* ARGSUSED */
Void main(Int argc, Char * argv[])
{
    IRES_Status        status;
    Int                size = 0;


    //TODO: Convert to Diags_setMask()
    //GT_set(MOD_NAME "=01234567");

    status = RMAN_init();

    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] main> RMAN initialization Failed ");
        System_abort("Aborting...\n");
    }

    BIOS_start();
}
/*
 *  @(#) ti.sdo.fc.rman.examples.nullresource.test; 1, 0, 0,3; 4-16-2012 00:02:27; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

