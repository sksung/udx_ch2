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
 *  ======== shmbuf_test0.c ========
 *  Test functionality of the SHMBUF Resource Manager. This test initializes
 *  the SHMBUF resource as persistent. This means that if one thread is
 *  holding the resource, no other thread will succeed in getting it.
 *  Running one instance at a time of this test should succeed. If a second
 *  instance of the test is started whille the first instance is still running,
 *  the second instance should fail.
 *
 *  Initialize and de-initialize the resource with SHMBUF APIs (no calls to
 *  RMAN functions).
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sdo/fc/ires/iresman.h>

#define ti_sdo_fc_ires_NOPROTOCOLREV
#include <ti/sdo/fc/ires/shmbuf/shmbuf.h>
#include "shmbuf_util.h"

#define SHMBUFSIZE 0x400


extern Int smain(Int argc, Char * argv[]);

/*
 *  ======== smain ========
 */
/* ARGSUSED */
Int smain(Int argc, Char * argv[])
{
    SHMBUF_Args        args;
    SHMBUF_Handle      shmBuf;
    IRES_Status        status;
    Int                scratchId;
    Void              *base;
    Bool               passed = FALSE;


    /* Initialize the shared memory resource */
    SHMBUF_PARAMS.bufsize = SHMBUFSIZE;
    SHMBUF_PARAMS.isScratch = FALSE;
    status = SHMBUF_init(&SHMBUF_PARAMS);

    if (status != IRES_OK) {
        /* Test failed */
        printf("SHMBUF_init() failed: 0x%x\n", status);
        goto done;
    }
    else {
        args.iresArgs.size = sizeof(SHMBUF_Args);
        args.iresArgs.mode = IRES_PERSISTENT;
        args.align = 8;
        args.length = 0x18;
        scratchId = 1;

        /* Allocate the resource */
        if ((shmBuf = SHMBUF_get((IALG_Handle)NULL, &args, scratchId,
                &status)) == NULL) {
            printf("SHMBUF_get() failed: 0x%x\n", status);
            goto done;
        }
        else {
            base = shmBuf->base;
            System_printf("Sleeping...\n");
            sleep(1);

            System_printf("Freeing resource...\n");
            /* Free the resource */
            status = SHMBUF_free((IALG_Handle)NULL, shmBuf, &args,
                    scratchId);
            shmBuf = NULL;
            if (status != IRES_OK) {
                goto done;
            }
        }

        passed = TRUE;
    }

done:

    SHMBUF_exit();

    if (passed) {
        System_printf("TEST PASSED\n");
    }
    else {
        System_printf("TEST FAILED\n");
    }

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.shmbuf; 1, 0, 0,3; 4-16-2012 00:02:30; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

