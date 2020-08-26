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
 *  ======== app.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/dskt2/dskt2.h>
#include <ti/sdo/fc/ires/iresman.h>
#include <ti/sdo/fc/ires/vicp/iresman_vicp.h>
#include <ires_algorithm.h>


/*
 * global declarations
 */

IRESMAN_VicpParams configParams = {
    {0,      /* Size of this structure */
            /*
             * RMAN_PERSISTENTALLOCFXN,
             * RMAN_PERSISTENTFREEFXN,
             */
    NULL,
    NULL},
};

/*
 *  ======== smain ========
 */
/* ARGSUSED - this line tells the compiler to not generate compiler warnings
 * for unused arguments */
Int smain(UArg arg0, UArg arg1)
{
    IRES_Status         status;
    Int                 size = 0;
    Int                 scratchId = 2;
    IALG_Status         algStatus;
    IALG_Fxns         * algFxns = &DUMRES_TI_IALG;
    IRES_Fxns         * resFxns = &DUMRES_TI_IRES;
    DUMRES_TI_Handle    dumHandle = NULL;


    status = RMAN_init();
    if (IRES_OK != status) {
        System_abort("RMAN initialization Failed \n");
    }

    /*
     * Create an instance of the algorithm using "algFxns"
     */
    dumHandle = (DUMRES_TI_Handle)DSKT2_createAlg(scratchId,
            (IALG_Fxns *)algFxns, NULL, (IALG_Params *)NULL);
    if (dumHandle == NULL) {
        System_abort("Alg creation failed \n");
    }

    /* Create an instance of an algorithm that implements IALG and IRES_Fxns */
    status = RMAN_assignResources((IALG_Handle)dumHandle, resFxns, scratchId);
    if (status != IRES_OK) {
        System_printf("Assign Resource Failed [%d]\n", status);
        System_abort("Aborting...\n");
    }


    /* Activate the Algorithm */
    DSKT2_activateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Activate All Resources */
    RMAN_activateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Use IALG interfaces to do something */
    DSKT2_controlAlg((IALG_Handle)dumHandle, (IALG_Cmd)NULL, &algStatus);

    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Deactivate algorithm */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Free resources assigned to this algorihtm */
    status = RMAN_freeResources((IALG_Handle)(dumHandle), resFxns, scratchId);
    if (status != IRES_OK) {
        System_printf("Free Resource Failed [%d]\n", status);
        System_abort("Aborting...\n");
    }

    /* Free instance of the algorithm created */
    DSKT2_freeAlg(scratchId, (IALG_Handle)dumHandle);

    RMAN_exit();
        
    return (1);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.vicp; 1, 0, 0,3; 4-16-2012 00:02:34; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

