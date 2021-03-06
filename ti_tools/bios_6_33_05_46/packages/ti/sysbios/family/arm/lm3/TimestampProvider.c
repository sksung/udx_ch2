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
 *  ======== TimestampProvider.c ========
 */


#include <xdc/std.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>

#define ti_sysbios_hal_Timer__internalaccess
#define ti_sysbios_hal_Timer__nolocalnames
#include <ti/sysbios/hal/Timer.h>

#include <ti/sysbios/family/arm/lm3/Timer.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>

#include "package/internal/TimestampProvider.xdc.h"

#define MOD     TimestampProvider_module

/*
 *  ======== TimestampProvider_Module_startup ========
 */
Int TimestampProvider_Module_startup( Int phase )
{
    return Startup_DONE;
}

/*
 *  ======== TimestampProvider_initTimerHandle ========
 *  Installed as a firstFxn ONLY if TimestampProvder.useClockTimer == true
 */
Void TimestampProvider_initTimerHandle()
{
    ti_sysbios_hal_Timer_Handle halTimer;    

    /* get lm3_Timer handle from hal_Timer object */
    halTimer = Clock_getTimerHandle();
    Assert_isTrue((halTimer != NULL), NULL);
    MOD->timer = (Timer_Handle)halTimer->pi;
}

/*
 *  ======== TimestampProvider_startTimer ========
 */
Void TimestampProvider_startTimer()
{
    Timer_start(MOD->timer);
}

/*
 *  ======== TimestampProvider_rolloverFunc ========
 */
Void TimestampProvider_rolloverFunc(UArg unused)
{
    MOD->hi++;
}

/*
 *  ======== TimestampProvider_get32 ========
 */
Bits32 TimestampProvider_get32()
{
    if (TimestampProvider_useClockTimer) {
        UInt key;
        UInt32 timestamp;

        key = Hwi_disable();

        timestamp = Clock_getTicks() * Timer_getPeriod(MOD->timer)
                   + Timer_getExpiredCounts(MOD->timer);

        Hwi_restore(key);

        return (timestamp);
    }
    else {
        return (~Timer_getCount(MOD->timer));
    }
}

/*
 *  ======== TimestampProvider_get64 ========
 */
Void TimestampProvider_get64(Types_Timestamp64 *result)
{
    UInt key;
    UInt64 timestamp;

    key = Hwi_disable();

    if (TimestampProvider_useClockTimer) {

        timestamp = Clock_getTicks() * Timer_getPeriod(MOD->timer)
                   + Timer_getExpiredCounts(MOD->timer);
    }
    else {
        timestamp = ((UInt64)MOD->hi << 32) + Timer_getExpiredCounts(MOD->timer);
    }

    Hwi_restore(key);

    result->hi = timestamp >> 32;
    result->lo = timestamp;
}

/*
 *  ======== TimestampProvider_getCounterFreq ========
 */
Void TimestampProvider_getFreq(Types_FreqHz *freq)
{
    BIOS_getCpuFreq(freq);
}

/*
 */

/*
 *  @(#) ti.sysbios.family.arm.lm3; 2, 0, 0, 0,230; 5-18-2012 06:04:26; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

