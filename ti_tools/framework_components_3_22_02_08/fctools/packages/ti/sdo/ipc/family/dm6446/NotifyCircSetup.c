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
 *  ======== NotifyCircSetup.c ========
 */
#include <xdc/std.h>
#include <xdc/runtime/Error.h> 

#include <ti/sdo/ipc/notifyDrivers/NotifyDriverCirc.h>
#include <ti/sdo/ipc/_Notify.h>
#include <ti/sdo/utils/_MultiProc.h>

#include "package/internal/NotifyCircSetup.xdc.h"

/*
 *************************************************************************
 *                      Module functions
 *************************************************************************
 */

/*!
 *  ======== NotifyCircSetup_attach ========
 *  Initialize interrupt
 */     
Int NotifyCircSetup_attach(UInt16 remoteProcId, Ptr sharedAddr)
{
    NotifyDriverCirc_Params notifyShmParams;
    Error_Block eb;
    Int status = Notify_S_SUCCESS;
    
#ifdef xdc_target__isaCompatible_64
    NotifyDriverCirc_Handle armDriverHandle0, armDriverHandle1;
    UInt armProcId = 1 - MultiProc_self();

    /* Initialize the error block */
    Error_init(&eb);

    /*
     *  Setup the notify driver to the ARM (Line 0)
     */     
    NotifyDriverCirc_Params_init(&notifyShmParams);
    notifyShmParams.localIntId     = NotifyCircSetup_dspRecvIntId0;
    notifyShmParams.remoteIntId    = NotifyCircSetup_armRecvIntId0;
    notifyShmParams.intVectorId    = NotifyCircSetup_dspIntVectId0;
    notifyShmParams.remoteProcId   = armProcId;
    notifyShmParams.sharedAddr     = sharedAddr;
    
    armDriverHandle0 = NotifyDriverCirc_create(&notifyShmParams, &eb);
    if (armDriverHandle0 == NULL) {
        return (Notify_E_FAIL);
    }
    
    ti_sdo_ipc_Notify_create(NotifyDriverCirc_Handle_upCast(armDriverHandle0), 
                  armProcId,
                  0,
                  NULL,
                  &eb);
    if (Error_check(&eb)) {
        /* Delete the driver and then return */
        NotifyDriverCirc_delete(&armDriverHandle0);
        return (Notify_E_FAIL);
    }

    if (!NotifyCircSetup_useSecondLine) {
        return (status);
    }
    /*
     *  Setup the notify driver to the ARM (Line 1)
     */     
    NotifyDriverCirc_Params_init(&notifyShmParams);
    notifyShmParams.localIntId     = NotifyCircSetup_dspRecvIntId1;
    notifyShmParams.remoteIntId    = NotifyCircSetup_armRecvIntId1;
    notifyShmParams.intVectorId    = NotifyCircSetup_dspIntVectId1;
    notifyShmParams.remoteProcId   = armProcId;
    notifyShmParams.sharedAddr     = (Ptr)((UInt32)sharedAddr + 
        NotifyDriverCirc_sharedMemReq(&notifyShmParams));
    armDriverHandle1 = NotifyDriverCirc_create(&notifyShmParams, &eb);

    if (armDriverHandle1 == NULL) {
        return (Notify_E_FAIL);
    }

    ti_sdo_ipc_Notify_create(NotifyDriverCirc_Handle_upCast(armDriverHandle1), 
                  armProcId,
                  1,
                  NULL,
                  &eb);
    if (Error_check(&eb)) {
        /* Delete the driver and then return */
        NotifyDriverCirc_delete(&armDriverHandle1);
        return (Notify_E_FAIL);
    }

#else /* ARM code */
    NotifyDriverCirc_Handle dspDriverHandle0, dspDriverHandle1;
    UInt dspProcId =  1 - MultiProc_self();
    
    /* Initialize the error block */
    Error_init(&eb);
    
    /*
     *  Setup the notify driver to the DSP (Line 0)
     */     
    NotifyDriverCirc_Params_init(&notifyShmParams);
    notifyShmParams.localIntId     = NotifyCircSetup_armRecvIntId0;
    notifyShmParams.remoteIntId    = NotifyCircSetup_dspRecvIntId0;
    notifyShmParams.remoteProcId   = dspProcId;
    notifyShmParams.sharedAddr     = sharedAddr;
    
    dspDriverHandle0 = NotifyDriverCirc_create(&notifyShmParams, &eb);
    if (dspDriverHandle0 == NULL) {
        return (Notify_E_FAIL);
    }
    
    ti_sdo_ipc_Notify_create(NotifyDriverCirc_Handle_upCast(dspDriverHandle0), 
                  dspProcId,
                  0,
                  NULL,
                  &eb);
    if (Error_check(&eb)) {
        /* Delete the driver and then return */
        NotifyDriverCirc_delete(&dspDriverHandle0);
        return (Notify_E_FAIL);
    }

    if (!NotifyCircSetup_useSecondLine) {
        return (status);
    }
    /*
     *  Setup the notify driver to the DSP (Line 1)
     */     
    NotifyDriverCirc_Params_init(&notifyShmParams);
    notifyShmParams.localIntId     = NotifyCircSetup_armRecvIntId1;
    notifyShmParams.remoteIntId    = NotifyCircSetup_dspRecvIntId1;
    notifyShmParams.remoteProcId   = dspProcId;
    notifyShmParams.sharedAddr     = (Ptr)((UInt32)sharedAddr + 
        NotifyDriverCirc_sharedMemReq(&notifyShmParams));
    dspDriverHandle1 = NotifyDriverCirc_create(&notifyShmParams, &eb);
    if (dspDriverHandle1 == NULL) {
        return (Notify_E_FAIL);
    }
    
    ti_sdo_ipc_Notify_create(NotifyDriverCirc_Handle_upCast(dspDriverHandle1), 
                  dspProcId,
                  1,
                  NULL,
                  &eb);
    if (Error_check(&eb)) {
        /* Delete the driver and then return */
        NotifyDriverCirc_delete(&dspDriverHandle1);
        return (Notify_E_FAIL);
    }

#endif

    return (status);
}

/*!
 *  ======== NotifyCircSetup_sharedMemReq ========
 *  Return the amount of shared memory required
 */     
SizeT NotifyCircSetup_sharedMemReq(UInt16 remoteProcId, Ptr sharedAddr) 
{
    SizeT memReq;
    NotifyDriverCirc_Params params;
    
    NotifyDriverCirc_Params_init(&params);
    params.sharedAddr = sharedAddr;
    
    if (!NotifyCircSetup_useSecondLine) {
        memReq = NotifyDriverCirc_sharedMemReq(&params);
    }
    else {
        memReq = 2 * NotifyDriverCirc_sharedMemReq(&params);
    }
    
    return(memReq);
}

/*!
 * ======== NotifyCircSetup_numIntLines ========
 */
UInt16 NotifyCircSetup_numIntLines(UInt16 remoteProcId)
{
    UInt16 numLines;

    if (NotifyCircSetup_useSecondLine) {
        numLines = 2;
    }
    else {
        numLines = 1;
    }

    return (numLines);
}

/*
 *  @(#) ti.sdo.ipc.family.dm6446; 1, 0, 0, 0,2; 2-11-2012 16:30:55; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

