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
 *  ======== Swi.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Assert.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Intrinsics.h>

#include "package/internal/Swi.xdc.h"

#ifdef ti_sysbios_BIOS_taskEnabled__D
#define TASK_DISABLE Task_disable
#define TASK_RESTORE Task_restore
#else
#define TASK_DISABLE Swi_taskDisable
#define TASK_RESTORE Swi_taskRestore
#endif

#ifdef __ti__
/* disable unused local variable warning during optimized compile */
#pragma diag_suppress=179
#endif

/*
 *************************************************************************
 *                       Internal functions
 *************************************************************************
 */

/*
 *  ======== Swi_run ========
 *  Set up and run Swi.
 *  Enter with Hwi's disabled
 *  Calls Swi function with interrupts enabled
 *  Exits with Hwi's enabled
 *  When no Swis are running, curQ is NULL
 */
Void Swi_run(Swi_Object *swi)
{
    UInt saved_curTrigger = Swi_module->curTrigger;
    Swi_Object *saved_curSwi = Swi_module->curSwi;
    Queue_Handle saved_curQ = Swi_module->curQ;
    BIOS_ThreadType prevThreadType;
    Int i;

    Swi_module->curQ = swi->readyQ;
    Swi_module->curSwi = swi;
    Swi_module->curTrigger = swi->trigger;

    swi->trigger = swi->initTrigger;
    swi->posted = FALSE;

    Swi_module->locked = FALSE; /* unlock the scheduler while */
                                /* Swi is running  */

    /* set thread type to Swi */
    prevThreadType = BIOS_setThreadType(BIOS_ThreadType_Swi);

    Hwi_enable();

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
    for (i = 0; i < Swi_hooks.length; i++) {
        if (Swi_hooks.elem[i].beginFxn != NULL) {
            Swi_hooks.elem[i].beginFxn(swi);
        }
    }
#endif

    Log_write3(Swi_LM_begin, (UArg)swi, (UArg)swi->fxn, (UArg)prevThreadType);

    (swi->fxn)(swi->arg0, swi->arg1);

    Log_write1(Swi_LD_end, (UArg)swi);

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
    for (i = 0; i < Swi_hooks.length; i++) {
        if (Swi_hooks.elem[i].endFxn != NULL) {
            Swi_hooks.elem[i].endFxn(swi);
        }
    }
#endif

    Hwi_disable();

    /* restore thread type */
    BIOS_setThreadType(prevThreadType);

    Swi_module->locked = TRUE;       /* relock the scheduler */

    Swi_module->curQ = saved_curQ;
    Swi_module->curSwi = saved_curSwi;
    Swi_module->curTrigger = saved_curTrigger;
}

/*
 *  The following two target-unique Hwi APIs must be called
 *  directly in order to work properly. Thus they are not
 *  published in the Hwi interface spec in order to bypass the
 *  indirect function calls that arise in the release and debug
 *  builds.
 */

extern Char *ti_sysbios_family_xxx_Hwi_switchToIsrStack();
extern Void ti_sysbios_family_xxx_Hwi_switchToTaskStack(Char *oldTaskSP);

/*
 *  ======== Swi_schedule ========
 *  Run all ready (posted) Swis of higher priority than the currently
 *  running Swi.
 *  Invoked from Task and Swi threads. 
 *  Called by Swi_startup(), Swi_restore() and Swi_post().
 *  Entered with Swi_module->locked = TRUE;
 *  Exits with Swi_module->locked = FALSE;
 */

Void Swi_schedule()
{
    Queue_Handle curQ, maxQ;
    Swi_Object *swi;
    UInt hwiKey;
    UInt tskKey;
    Char *oldTaskSP;
    volatile Bool taskEnabled;

    /* Remember current Swi priority */
    curQ = Swi_module->curQ;

    hwiKey = Hwi_disable();     /* required for Swi's posted from Tasks */

    /* determine current highest priority Q */
    maxQ = (Queue_Handle)((UInt8 *)(Swi_module->readyQ) + 
                (UInt)(Intrinsics_maxbit(Swi_module->curSet)*(2*sizeof(Ptr))));

    if (maxQ > curQ) {

        if (BIOS_taskEnabled) {
            tskKey = TASK_DISABLE();    /* required for Swi's posted from Tasks */

            /* Switch to HWI stack if not already on it */
            oldTaskSP = ti_sysbios_family_xxx_Hwi_switchToIsrStack();

            /* must refresh local variables after stack switch */

            /* refresh curQ */
            curQ = Swi_module->curQ;

            /* refresh maxQ */
            maxQ = (Queue_Handle)((UInt8 *)(Swi_module->readyQ) + 
                        (UInt)(Intrinsics_maxbit(Swi_module->curSet)*(2*sizeof(Ptr))));
            /* set local variable inited after stack switch */
            taskEnabled = TRUE;  
        }
        else {
            taskEnabled = FALSE;
        }

        /* 
         * Run all Swis of higher priority than 
         * the current Swi priority.
         * Will pre-empt any currently running swi. 
         */
        do {
            swi = (Swi_Object *)Queue_dequeue(maxQ);

            /* remove from curSet if last one in this ready list */
            if (Queue_empty(maxQ)) {
                Swi_module->curSet &= ~swi->mask;
            }

            Swi_run(swi);

            if (Swi_module->curSet == 0) {
                break;
            }
            
            maxQ = (Queue_Handle)((UInt8 *)(Swi_module->readyQ) + 
                        (UInt)(Intrinsics_maxbit(Swi_module->curSet)*(2*sizeof(Ptr))));
        } 
        while (maxQ > curQ);

        /* check local variable inited after stack switch */
        if (taskEnabled) {
            /* Switch back to Task stack if at bottom of HWI stack */
            ti_sysbios_family_xxx_Hwi_switchToTaskStack(oldTaskSP);
        }

        /* MUST(!) unlock the scheduler before enabling interrupts */
        Swi_module->locked = FALSE;
        
        Hwi_restore(hwiKey);

        if (BIOS_taskEnabled) {
            TASK_RESTORE(tskKey);
        }
    }
    else {
        Swi_module->locked = FALSE;
        Hwi_restore(hwiKey);
    }
}

/*
 *************************************************************************
 *                      Module wide functions
 *************************************************************************
 */

/*
 *  ======== Swi_Module_startup ========
 */
Int Swi_Module_startup(Int phase)
{
    /*
     * Need not wait for anybody because Swi and task do no work
     * before BIOS_start(). Assuming hooks are OK.
     */
    if (BIOS_swiEnabled) {  /* minimize code foot print if Swi is disabled */
        Int i;
        UInt j;

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
        for (i = 0; i < Swi_hooks.length; i++) {
            if (Swi_hooks.elem[i].registerFxn != NULL) {
                Swi_hooks.elem[i].registerFxn(i);
            }
        }
#endif

        for (i = 0; i < Swi_Object_count(); i++) {
            Swi_postInit(Swi_Object_get(NULL, i), NULL);
        }

        /* do post init on all statically Constructed Swis */
        for (j = 0; j < Swi_numConstructedSwis; j++) {
            Swi_postInit(Swi_module->constructedSwis[j], NULL);
        }
    }

    return (Startup_DONE);
}

/*
 *  ======== Swi_startup ========
 */
Void Swi_startup()
{
    Swi_restore(FALSE);
}

/*
 *  ======== Swi_enabled ========
 */
Bool Swi_enabled()
{
    return (Swi_module->locked == FALSE);
}

/*
 *  ======== Swi_disable ========
 */
UInt Swi_disable()
{
    UInt key = Swi_module->locked;

    Swi_module->locked = TRUE;

    return (key);
}

/*
 *  ======== Swi_enable ========
 */
Void Swi_enable()
{
    Swi_restore(FALSE);
}

/*
 *  ======== Swi_restore ========
 */
Void Swi_restore(UInt swiKey)
{
    UInt hwiKey;

    if (swiKey == FALSE) {
        hwiKey = Hwi_disable();

        if (Swi_module->curSet) {
            Hwi_restore(hwiKey);
            Swi_schedule();     /* sets locked to FALSE */
        }
        else {
            Swi_module->locked = FALSE;
            Hwi_restore(hwiKey);
        }

        if (BIOS_taskEnabled) {
            /* run task scheduler if its unlocked */
            TASK_RESTORE(TASK_DISABLE());
        }
    }
}

/*
 *  ======== Swi_restoreHwi ========
 *  Restore Swi scheduler state.
 *
 *  Called by interrupt dispatcher.
 *  Optimized for running within dispatcher context.
 *  No Swi_taskDisable/restore, Hwi_disable/restore,
 *  SwitchToIsrStack/SwitchToTaskStack.
 *
 *  Assumes Hwis and Tasks already disabled and currently
 *  running on ISR stack.
 *
 *  if restored to unlocked state and there are Swis ready 
 *  to run, then run all ready (posted) Swis of higher 
 *  priority than the currently running Swi.
 *
 *  Entered with ints and Tasks disabled. 
 */

Void Swi_restoreHwi(UInt swiKey)
{
    Queue_Handle curQ, maxQ;
    Swi_Object *swi;

    if (swiKey == FALSE) {
        if (Swi_module->curSet) {
            /* Remember current Swi priority */
            curQ = Swi_module->curQ;

            /* determine current highest priority Q */
            maxQ = (Queue_Handle)((UInt8 *)(Swi_module->readyQ) + 
                        (UInt)(Intrinsics_maxbit(Swi_module->curSet)*(2*sizeof(Ptr))));

            /* Run all Swis of higher priority than the current Swi priority */
            /* Will pre-empt any currently running swi. */
            while (maxQ > curQ) {
                swi = (Swi_Object *)Queue_dequeue(maxQ);

                /* remove from curSet if last one in this ready list */
                if (Queue_empty(maxQ)) {
                    Swi_module->curSet &= ~swi->mask;
                }

                Swi_run(swi);

                if (Swi_module->curSet == 0) {
                    break;
                }
                maxQ = (Queue_Handle)((UInt8 *)(Swi_module->readyQ) + 
                        (UInt)(Intrinsics_maxbit(Swi_module->curSet)*(2*sizeof(Ptr))));
            }
        }
        Swi_module->locked = FALSE;
    }
}

/*
 *  ======== Swi_self ========
 */
Swi_Handle Swi_self()
{
    return (Swi_module->curSwi);
}


/*
 *  ======== Swi_getTrigger ========
 */
UInt Swi_getTrigger()
{
    return (Swi_module->curTrigger);
}

/*
 *  ======== Swi_raisePri ========
 *  !!! Warning, while raisePri is in effect, the !!!
 *  !!! current Swi's priority and mask don't     !!!
 *  !!! match curQ.                               !!!
 */
UInt Swi_raisePri(UInt priority)
{
    UInt hwiKey;

    Queue_Handle oldCurQ, newCurQ;

    hwiKey = Hwi_disable();

    oldCurQ = Swi_module->curQ;
    newCurQ = Queue_Object_get(Swi_module->readyQ, priority);
    Swi_module->curQ = newCurQ > oldCurQ ? newCurQ : oldCurQ;

    Hwi_restore(hwiKey);

    return (Swi_module->curSwi->priority);
}

/*
 *  ======== Swi_restorePri ========
 */
Void Swi_restorePri(UInt priority)
{
    UInt swiKey;

    swiKey = Swi_disable();

    Swi_module->curQ = Queue_Object_get(Swi_module->readyQ, priority);

    Swi_restore(swiKey);
}

/*
 *************************************************************************
 *                       Instance functions
 *************************************************************************
 */

/*
 *  ======== Swi_Instance_init ========
 */
Int Swi_Instance_init(Swi_Object *swi, Swi_FuncPtr fxn, 
                        const Swi_Params *params, Error_Block *eb)
{
    Int status;

    Assert_isTrue((BIOS_swiEnabled == TRUE), Swi_A_swiDisabled);

    Queue_elemClear(&swi->qElem);
    swi->fxn = fxn;
    swi->arg0 = params->arg0;
    swi->arg1 = params->arg1;

    if (params->priority == ~0) {
        swi->priority = Swi_numPriorities - 1;
    }
    else {
        swi->priority = params->priority;
    }

    Assert_isTrue((swi->priority < Swi_numPriorities), 
                   Swi_A_badPriority);

    swi->mask = 1 << swi->priority;
    swi->posted = FALSE;
    swi->initTrigger = swi->trigger = params->trigger;
    swi->readyQ = Queue_Object_get(Swi_module->readyQ, swi->priority);

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
    if (Swi_hooks.length > 0) {
        swi->hookEnv = Memory_alloc(Swi_Object_heap(),
                Swi_hooks.length * sizeof(Ptr), 0, eb);

        if (swi->hookEnv == NULL) {
            return (1);   /* see 2 below */
        }
    }
#endif

    status = Swi_postInit(swi, eb);

    /* 
     * floor of 2 here is to differentiate Swi_postInit errors
     * from Instance_init errors
     */
    if (Error_check(eb)) {
        return (2 + status); 
    }

    return (0);
}

/*
 *  ======== Swi_postInit ========
 *  Function to be called during module startup to complete the
 *  initialization of any statically created or constructed Swi.
 *
 *  returns (0) and clean 'eb' on success
 *  returns 'eb' *and* 'n' for number of successful createFxn() calls iff
 *      one of the createFxn() calls fails
 */
Int Swi_postInit (Swi_Object *swi, Error_Block *eb)
{
    Int i;

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
    for (i = 0; i < Swi_hooks.length; i++) {
        swi->hookEnv[i] = (Ptr)0;
        if (Swi_hooks.elem[i].createFxn != NULL) {
            Swi_hooks.elem[i].createFxn(swi, eb);

            if (Error_check(eb)) {
                return (i);
            }
        }
    }
#endif

    return (0);
}

/*
 *  ======== Swi_Instance_finalize ========
 *  free hookEnv if alloced during create
 */
Void Swi_Instance_finalize(Swi_Object *swi, Int status)
{
    Int i, cnt;

    if (status == 1) {
        return;
    }

    /* Can't delete a currently posted Swi */
    Assert_isTrue((swi->posted == 0), NULL);

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
    if (Swi_hooks.length > 0) {
        if (status == 0) {
            cnt = Swi_hooks.length;
        }
        else {
            cnt = status - 2;
        }

        for (i = 0; i < cnt; i++) {
            if (Swi_hooks.elem[i].deleteFxn != NULL) {
                Swi_hooks.elem[i].deleteFxn(swi);
            }
        }

        Memory_free(Swi_Object_heap(), swi->hookEnv,
                Swi_hooks.length * sizeof (Ptr));
    }
#endif
}

/*
 *  ======== Swi_post ========
 */
Void Swi_post(Swi_Object *swi)
{
    UInt hwiKey;
    UInt swiKey;
    Int i;

    Log_write3(Swi_LM_post, (UArg)swi, (UArg)swi->fxn, (UArg)swi->priority);

    hwiKey = Hwi_disable();

    if (swi->posted) {
        Hwi_restore(hwiKey);
        return;
    }

    swi->posted = TRUE;

    swiKey = Swi_disable();

    /* Place the Swi in the appropriate ready Queue. */
    Queue_enqueue(swi->readyQ, (Queue_Elem *)swi);

    /* Add this priority to current set */
    Swi_module->curSet |= swi->mask;

    Hwi_restore(hwiKey);  /* Not in FIFO order. OK! */

#ifndef ti_sysbios_knl_Swi_DISABLE_ALL_HOOKS
    /*
     * This hook location supports the STS "set ready time" operation on
     * Swis.  This is equivalent to pre-BIOS 6.
     */
    for (i = 0; i < Swi_hooks.length; i++) {
        if (Swi_hooks.elem[i].readyFxn != NULL) {
            Swi_hooks.elem[i].readyFxn(swi);
        }
    }
#endif

    /* 
     * Modified Swi_restore().
     * No need to check curSet since we just set it.
     */
    if (swiKey == FALSE) {
        Swi_schedule(); /* unlocks Swi scheduler on return */
    }
}

/*
 *  ======== Swi_getHookContext ========
 */
Ptr Swi_getHookContext(Swi_Object *swi, Int id)
{
    return swi->hookEnv[id];
}

/*
 *  ======== Swi_setHookContext ========
 */
Void Swi_setHookContext(Swi_Object *swi, Int id, Ptr hookContext)
{
    swi->hookEnv[id] = hookContext;
}

/*
 *  ======== Swi_getPri ========
 */
UInt Swi_getPri(Swi_Object *swi)
{
    return (swi->priority);
}

/*
 *  ======== Swi_FuncPtr ========
 */
Swi_FuncPtr Swi_getFunc(Swi_Object *swi, UArg *arg0, UArg *arg1)
{
    if (arg0 != NULL) {
        *arg0 = swi->arg0;
    }
    
    if (arg1 != NULL) {
        *arg1 = swi->arg1;
    }

    return (swi->fxn);
}

/*
 *  ======== Swi_inc ========
 */
Void Swi_inc(Swi_Object *swi)
{
    UInt hwiKey;

    hwiKey = Hwi_disable();
    swi->trigger += 1;
    Hwi_restore(hwiKey);
    Swi_post(swi);
}

/*
 *  ======== Swi_or ========
 */
Void Swi_or(Swi_Object *swi, UInt mask)
{
    UInt hwiKey;

    hwiKey = Hwi_disable();
    swi->trigger |= mask;
    Hwi_restore(hwiKey);
    Swi_post(swi);
}

/*
 */
/*
 *  @(#) ti.sysbios.knl; 2, 0, 0, 0,552; 5-18-2012 06:05:54; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

