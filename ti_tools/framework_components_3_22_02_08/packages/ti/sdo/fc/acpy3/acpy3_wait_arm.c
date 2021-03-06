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
 *  ======== acpy3_wait_arm.c ========
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include <ti/xdais/idma3.h>
#include <ti/sdo/fc/acpy3/acpy3_qdma_arm.h>
#include <ti/sdo/fc/acpy3/acpy3_util.h>


#ifndef _ACPY3_CPUCOPY_

extern Registry_Desc ti_sdo_fc_acpy3_desc;

/*
 *  ======== ACPY3_wait ========
 */
Void ACPY3_wait(IDMA3_Handle restrict handle)
{
//    IDMA3_Handle  * restrict  lockPtr;

    ACPY3_MoreEnv * restrict moreEnv;
    volatile Uns            *iprRegister; /* QDMA Interrupt pending register */
    Uns                      iprMask;
    Uns                      icrlMask;
    Uns                      icrhMask;
    Uns                      pending;
    Uns                      StatusReg;
    //IDMA3_Handle             prevLock;
    UInt32                   count = 0;

#if defined(ACPY3_WAIT_IMPLEMENTATION)
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
#endif

    Log_print1(Diags_ENTRY, "[+E] ACPY3_wait> Enter (handle=0x%x)",
            (IArg)handle);

    moreEnv = (ACPY3_MoreEnv *)(handle->env);         /* read in advance ptr */

    pending = handle->transferPending;                /* read in advance */
//    lockPtr = &_ACPY3_qchLockTbl[handle->qdmaChan];   /* read in advance ptr */
    handle->transferPending = FALSE;                  /* reset in advance */

    iprRegister = (volatile Uns *)moreEnv->iprRegister; /* read in advance */

    iprMask = moreEnv->iprMask;                       /* read in advance */
    icrlMask = moreEnv->icrlMask;                     /* read in advance */
    icrhMask = moreEnv->icrhMask;                     /* read in advance */
    StatusReg = *iprRegister;                         /* read STATUS */

    /*
     * Wait for a channel only once. Set the 'pending' flag whenever new
     * transfer is submitted, then clear it when ACPY3_wait* is issued.
     */
    if (!pending) {
        return;
    }

    while (!(StatusReg & iprMask)) {    /* wait on the final TCC being set */
        StatusReg = *iprRegister;

        if (++count >= _ACPY3_TIMEOUT) {
            Log_print2(Diags_USER6, "[+6] ACPY3_wait> "
                    "Timed out polling for tcc, "
                    "StatusReg [0x%x], QCHMAP [0x%x]",
                    (IArg)StatusReg, (IArg)(ACPY3_QCHMAP[handle->qdmaChan]));
            count = 0;
        }
    }

    /*
     * Mark the QDMA channel as unlocked.
     * This must be done atomically.
     */
    ///csr = _disable_interrupts();
    // Currently not using _ACPY3_qchLockTbl[] optimization
    //prevLock = *lockPtr;

    /* Clear all the TCCs for the channel (moved here for removing nops) */
    if (icrlMask)
       *ACPY3_QDMA_ICR = icrlMask;
    if (icrhMask)
       *ACPY3_QDMA_ICRH = icrhMask;

    //if (prevLock == handle)
    //    *lockPtr = 0;
    ///_restore_interrupts(csr); /* TODO: reenable interrupts */

    Log_print0(Diags_EXIT, "[+X] ACPY3_wait> Exit");
}

#endif
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,3; 4-16-2012 00:00:11; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

