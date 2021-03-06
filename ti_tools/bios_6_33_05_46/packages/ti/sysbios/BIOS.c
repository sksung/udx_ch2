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
 *  ======== BIOS.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Error.h>

#include "package/internal/BIOS.xdc.h"

/*
 *  For TI runtime, register a lock and unlock function. Other runtime
 *  libraries are assumed to be thread-safe.
 */
#if defined(__ti__)
extern void _register_lock();
extern void _register_unlock();

/*
 *  ======== rtsLock ========
 *  Called by rts _lock() function
 */
static Void rtsLock()
{
    IArg key;

    key = BIOS_RtsGateProxy_enter(BIOS_module->rtsGate);
    if (BIOS_module->rtsGateCount == 0) {
        BIOS_module->rtsGateKey = key;
    }
    /* Increment need not be atomic */
    BIOS_module->rtsGateCount++;
}

/*
 *  ======== rtsUnLock ========
 *  Called by rts _unlock() function
 */
static Void rtsUnlock()
{
    Assert_isTrue((BIOS_module->rtsGateCount), NULL);

    BIOS_module->rtsGateCount--;

    if (BIOS_module->rtsGateCount == 0) {
        BIOS_RtsGateProxy_leave(BIOS_module->rtsGate, BIOS_module->rtsGateKey);
    }
}

/*
 *  ======== nullFunc ========
 */
static Void nullFunc()
{
}
#endif

/*
 *  ======== BIOS_registerRTSLock ========
 */
Void BIOS_registerRTSLock(Void)
{
#if defined(__ti__)
    if (BIOS_module->rtsGate != NULL) {
        _register_lock(rtsLock);
        _register_unlock(rtsUnlock);
    }
#endif
}

/*
 *  ======== BIOS_removeRTSLock ========
 */
Void BIOS_removeRTSLock(Void)
{
#if defined(__ti__)
    if (BIOS_module->rtsGate != NULL) {
        _register_lock(nullFunc);
        _register_unlock(nullFunc);
    }
#endif
}

/*!
 *  ======== BIOS_getThreadType ========
 */
BIOS_ThreadType BIOS_getThreadType(Void)
{
    return (BIOS_module->threadType);
}

/*!
 *  ======== BIOS_setThreadType ========
 */
BIOS_ThreadType BIOS_setThreadType(BIOS_ThreadType ttype)
{
    BIOS_ThreadType prevThreadType = BIOS_module->threadType;

    BIOS_module->threadType = ttype;

    return (prevThreadType);
}

/*
 *  ======== BIOS_setCpuFreq ========
 */
Void BIOS_setCpuFreq(Types_FreqHz *freq)
{
    BIOS_module->cpuFreq = *freq;
}

/*
 *  ======== BIOS_getCpuFreq ========
 */
Void BIOS_getCpuFreq(Types_FreqHz *freq)
{
   *freq = BIOS_module->cpuFreq;
}

/*
 *  ======== BIOS_start ========
 */
Void BIOS_start(void)
{
    BIOS_module->startFunc();
}

/*
 *  ======== BIOS_exit ========
 */
Void BIOS_exit(Int stat)
{
    /* remove the RTS lock */
    BIOS_removeRTSLock();

    /* force thread type to 'Main' */
    BIOS_setThreadType(BIOS_ThreadType_Main);

    System_exit(stat);
}

/*
 *  ======== BIOS_errorRaiseHook ========
 */
Void BIOS_errorRaiseHook(Error_Block *eb)
{
    /* 
     * If this is an Assert thread, defang Gate threadtype check 
     */
    if (eb->id == xdc_runtime_Assert_E_assertFailed) {
        /* remove the RTS lock */
        BIOS_removeRTSLock();

        /* force thread type to 'Main' */
        BIOS_setThreadType(BIOS_ThreadType_Main);
    }

    /* Call the default/user's Error.raiseHook */
    BIOS_installedErrorHook(eb);
}

/*! Revision History
 *! ================
 *! 06-Apr-2011 agd     SDOCM00078301 defang GateMutex in Error_raise thread
 *! 30-Sep-2010 agd     SDOCM00046248 enable threadtype check Assert 
 *!                     in GateMutex
 *! 20-Mar-2007 toddm   Moved register into startupFxns list
 *!                     Added nesting support for rtsLock/Unlock
 *! 20-Nov-2006 toddm   Added runtime locking for ti codegen
 *! 10-Oct-2006 nitya   created
 */
/*
 *  @(#) ti.sysbios; 2, 0, 0, 0,573; 5-18-2012 06:03:33; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

