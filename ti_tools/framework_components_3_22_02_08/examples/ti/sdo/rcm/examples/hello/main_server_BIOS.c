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
 *
 */

/* package header files */
#include <xdc/std.h>            /* must be first */

#include <ti/ipc/Ipc.h>
#include <ti/ipc/MultiProc.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>


/* local header files */
#include "Global.h"
#include "Server.h"

/* private functions */
static Void smain(UArg arg0, UArg arg1);


/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    Error_Block eb;
    Task_Params taskParams;


    Error_init(&eb);

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "smain";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x1000;
    Task_create(smain, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main: failed to create application startup thread");
    }

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    return(0);
}


/*
 *  ======== smain ========
 */
Void smain(UArg arg0, UArg arg1)
{
    Int         status = 0;
    Error_Block eb;
    UInt16      remoteProcId;
    Bool        running = TRUE;

    Log_print0(Diags_ENTRY | Diags_INFO, "--> smain:");

    Error_init(&eb);

    /* initialize module */
    Server_init();

    /* turn on some trace */
    Diags_setMask("Server+F");

    /* loop forever */
    while (running) {

        /* only one thread must call start */
        do {
            status = Ipc_start();
        } while (status == Ipc_E_NOTREADY);

        if (status < 0) {
            goto leave;
        }

        /* attach to the remote processor */
        remoteProcId = MultiProc_getId("HOST");

        /* connect to remote processor */
        do {
            status = Ipc_attach(remoteProcId);

            if (status == Ipc_E_NOTREADY) {
#ifdef __ARCTIC__
                Task_yield(); /* no timers on EVE simulator */
#else
                Task_sleep(10); /* ticks */
#endif
            }
        } while (status == Ipc_E_NOTREADY);

        if (status < 0) {
            Log_error0("smain: Ipc_attach() failed");
            goto leave;
        }

        /*
         *  BEGIN server phase
         */

        /* server setup phase */
        status = Server_setup();

        if (status < 0) {
            goto leave;
        }

        /* server execute phase */
        status = Server_run();

        if (status < 0) {
            goto leave;
        }

        /* server shutdown phase */
        status = Server_finish();

        if (status < 0) {
            goto leave;
        }

        /*
         *  END server phase
         */

        /* disconnect from remote processor */
        do {
            status = Ipc_detach(remoteProcId);

            if (status == Ipc_E_NOTREADY) {
#ifdef __ARCTIC__
                Task_yield(); /* no timers on EVE simulator */
#else
                Task_sleep(10); /* ticks */
#endif
            }
        } while (status == Ipc_E_NOTREADY);

        if (status < 0) {
            goto leave;
        }

        /* only one thread must call stop */
        Ipc_stop();

    } /* while (running) */


    /* finalize modules */
    Server_exit();

leave:
    Log_print1(Diags_EXIT, "<-- smain: %d", (IArg)status);
    return;
}
/*
 *  @(#) ti.sdo.rcm.examples.hello; 1,0,0,3; 4-16-2012 00:03:20; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

