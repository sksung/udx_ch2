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
 *  ======== Timer.c ========
 *
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>

#define ti_sysbios_hal_Timer__internalaccess
#define ti_sysbios_hal_Timer__nolocalnames
#include <ti/sysbios/hal/Timer.h>

#include <ti/sysbios/family/msp430/Hwi.h>
#include <ti/catalog/msp430/peripherals/timer/timer.h>

#include "package/internal/Timer.xdc.h"

#define MC           0x0020        /* mode, control = continous up counting */
#define TxCLR        0x0004        /* clear timer counter */
#define CCIE         0x0010        /* compare interrupt enable */
#define CCIFG        0x0001        /* compare interrupt pending flag */
#define TSSEL        0x0100        /* source select = ACLK */
#define ID           0x0000        /* input divider = 1 */

#define TIMER_CONTROL_START           MC
#define TIMER_CONTROL_CLEAR           TxCLR
#define TIMER_CONTROL_DEFAULT         (TSSEL | ID)
#define TIMER_COMPARE_INTR_ENABLE     CCIE
#define TIMER_COMPARE_INTR_PENDING    CCIFG

#define INIT_OK                         0
#define INIT_INVALID_TIMER_ID           1
#define INIT_TIMER_NOT_AVAILABLE        2
#define INIT_HWI_CREATE_FAILED          3
#define INIT_SET_PERIOD_FAILED          4

#define READ_LATENCY                    10   /* # MCLK cycles to allow for
                                                back-to-back read of count */

static Int postInit(Timer_Object *timer, Error_Block *eb);
static Void initDevice(Timer_Object *obj);
static Bool checkOverflow(UInt32 a, UInt32 b);

/*
 *  ======== Timer_getNumTimers ========
 *  Get number of timer peripherals available on the device.
 */
UInt Timer_getNumTimers()
{
    return (Timer_numTimerDevices);
}

/*
 *  ======== Timer_getStatus ========
 *  Get the FREE/INUSE status of the timer.
 */
Timer_Status Timer_getStatus(UInt timerId)
{
    Assert_isTrue(timerId < Timer_numTimerDevices, NULL);

    if (Timer_module->availMask & (0x1 << timerId)) {
        return (Timer_Status_FREE);
    }
    else {
        return (Timer_Status_INUSE);
    }
}

/*
 *  ======== Timer_getMaxTicks ========
 */
UInt32 Timer_getMaxTicks(Timer_Object *obj, UInt32 periodCounts)
{
    return (0x0000FFFF / periodCounts);
}

/*
 *  ======== Timer_setNextTick ========
 */
Void Timer_setNextTick(Timer_Object *obj, UInt32 newPeriod, 
    UInt32 countsPerTick)
{
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;
    UInt countsTick = countsPerTick;
    UInt next;
    UInt previous;
    UInt now;

    /* get timer base address */
    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    previous = obj->prevThreshold;
    next = previous + newPeriod;

    /* set the compare threshold for next interrupt */
    timer->cc_compare_0 = next;

    /* 
     * MSP430 timers will only interrupt if the timer *counts* to the threshold.
     * So must check to make sure that didn't set the threshold too late, and
     * missed an interrupt.  If did, assert the timer interrupt immediately. 
     * Because we're also doing tick suppression, we need to be careful not to 
     * inadvertently trigger an interrupt when the next threshold is set far
     * in the future.  The below checks will accomodate a delay of at least
     * one timer tick interval; any accomodation of more delay would require a 
     * reduction in the maximum number of suppressible ticks.
     */

    /* get current timer count */
    now = Timer_getCount(obj);

    /* check for late setting of next interrupt threshold ... */

    /* for the next-threshold-is-greater-than-previous case */
    if (next > previous) {  
        if (now >= next) {  /* if haven't wrapped thru zero */
            if ((now - next) < countsTick) {
                timer->cctl_0 |= CCIFG;  /* trigger interrupt now */
            }
        }
        else {  /* now < next and now < previous so have wrapped thru zero */
            if ((now < previous) && (now < (next + countsTick))) {
                timer->cctl_0 |= CCIFG;  /* trigger interrupt now */
            }
        }
    }
    /* else, the next-is-less-than-previous case expecting a wrap thru zero */
    else {
        if (now >= previous) {
        }
        else if ((now >= next) && (now < (next + countsTick)) ) { 
            timer->cctl_0 |= CCIFG;  /* trigger interrupt now ... */
        }
    }

    /* save the new period counts */
    obj->period = newPeriod;
}

/*
 *  ======== Timer_Module_startup ========
 *  Calls postInit for all statically-created & constructed
 *  timers to initialize them.
 */
Int Timer_Module_startup(status)
{
    Int i;
    Timer_Object *obj;

    if (Timer_startupNeeded) {
        for (i = 0; i < Timer_numTimerDevices; i++) {
            obj = Timer_module->handles[i];
            /* if timer was statically created/constructed */
            if ((obj != NULL) && (obj->staticInst)) {
                postInit(obj, NULL);
            }
        }
    }

    return (Startup_DONE);
}

/*
 *  ======== Timer_startup ========
 *  Here after call to main().  Called from BIOS_start().
 */
Void Timer_startup()
{
    Int i;
    Timer_Object *obj;

    if (Timer_startupNeeded) {
        for (i = 0; i < Timer_numTimerDevices; i++) {
            obj = Timer_module->handles[i];
            /* if timer was statically created/constructed */
            if ((obj != NULL) && (obj->staticInst)) {
                if (obj->startMode == Timer_StartMode_AUTO) {
                        Timer_start(obj);
                }
            }
        }
    }
}

/*
 *  ======== Timer_getHandle ========
 */
Timer_Handle Timer_getHandle(UInt id)
{
    Assert_isTrue((id < Timer_numTimerDevices), NULL);
    return (Timer_module->handles[id]);
}

/*
 *  ======== Timer_Instance_init ========
 * 1. Select timer based on id
 * 2. Mark timer as in use
 * 3. Init timer obj using params
 * 4. Create Hwi if tickFxn != NULL
 * 5. Initialize timer
 * 6. Configure timer (wrt emulation, frequency, etc.)
 * 7. Set period
 * 8. Timer_start()
 *
 */
Int Timer_Instance_init(Timer_Object *obj, Int id, Timer_FuncPtr tickFxn, const Timer_Params *params, Error_Block *eb)
{
    /* NOTE: Dynamic timer creation is currently disabled because we don't 
       support runtime interrupt plugging.  Timers must be created statically,
       in the app configuration.  */

    Error_raise(eb, Timer_E_runtimeCreate, id, 0);

    return (INIT_OK);
}

/*
 *  ======== Timer_reconfig ========
 *
 * 1. Init obj using params
 * 2. Timer_init()
 * 3. Configure timer (wrt emulation, frequency, etc.)
 * 4. Set period
 * 5. Timer_start()
 *
 */
Void Timer_reconfig (Timer_Object *obj, Timer_FuncPtr tickFxn, const 
    Timer_Params *params, Error_Block *eb)
{
    obj->controlRegInit = params->controlRegInit.source;
    obj->runMode = params->runMode;
    obj->startMode = params->startMode;
    obj->period = params->period;
    obj->periodType = params->periodType;
    obj->prevThreshold = params->prevThreshold;
    obj->synchronous = params->synchronous;

    if (obj->periodType == Timer_PeriodType_MICROSECS) {
        if (!Timer_setPeriodMicroSecs(obj, obj->period)) {
            Error_raise(eb, Timer_E_cannotSupport, obj->period, 0);
        }
    }

    obj->arg = params->arg;
    obj->tickFxn = tickFxn;

    if (params->extFreq.lo) {                   /* (extFreq.hi is ignored) */
        obj->frequency.lo = params->extFreq.lo;
    }

    postInit(obj, eb);

    if (obj->startMode == Timer_StartMode_AUTO) {
        Timer_start(obj);
    }
}

/*
 *  ======== Timer_Instance_finalize ========
 */
Void Timer_Instance_finalize(Timer_Object *obj, Int status)
{
    UInt key;

    key = Hwi_disable();
    Timer_module->availMask |= (0x1 << obj->id);
    Timer_module->handles[obj->id] = NULL;
    Hwi_restore(key);
}

/*
 *  ======== Timer_start ========
 *
 * 1. Hwi_disable()
 * 2. Clear the counter
 * 3. Clear timer interrupt flag
 * 4. Set next compare threshold (per configured period)
 * 5. Enable timer interrupt
 * 6. Start timer
 * 7. Hwi_restore()
 *
 */
Void Timer_start(Timer_Object *obj)
{
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;
    UInt key;

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    key = Hwi_disable();

    /* reset timer counts */
    timer->control |= TIMER_CONTROL_CLEAR;

    /* clear timer interrupt flag */
    timer->cctl_0 &= ~TIMER_COMPARE_INTR_PENDING;

    /* zero previous threshold */
    obj->prevThreshold = 0;

    /* set compare threshold for next interrupt */
    timer->cc_compare_0 = obj->period;

    /* enable capture/compare 0 interrupts */
    timer->cctl_0 |= TIMER_COMPARE_INTR_ENABLE;

    /* start timer */
    timer->control |= TIMER_CONTROL_START;

    Hwi_restore(key);
}

/*
 *  ======== Timer_stop ========
 *
 * 1. Stop timer
 * 2. Disable timer interrupt
 *
 */
Void Timer_stop(Timer_Object *obj)
{
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    /* stop timer */
    timer->control = obj->controlRegInit;

    /* disable capture/compare 0 interrupts */
    timer->cctl_0 &= ~TIMER_COMPARE_INTR_ENABLE;
}

/*
 *  ======== Timer_setPeriod ========
 *
 * 1. Stop timer
 * 2. Set period value in timer obj
 *
 */
Void Timer_setPeriod(Timer_Object *obj, UInt32 period)
{
    Timer_stop(obj);
    obj->period = period;
}

/*
 *  ======== Timer_setPeriodMicroSecs ========
 *
 * 1. Stop timer
 * 2. Compute counts
 * 3. Set new period value in timer obj
 *
 */
Bool Timer_setPeriodMicroSecs(Timer_Object *obj, UInt32 period)
{
    Types_FreqHz freqHz;
    UInt32 counts;
    UInt32 freqKHz;

    Timer_stop(obj);

    Timer_getFreq(obj, &freqHz);
    freqKHz = freqHz.lo / 1000;

    if (checkOverflow(freqKHz, period/1000)) {
        return (FALSE);
    }
    else {
        counts = (freqKHz * period) / 1000;
        obj->period = counts;
        obj->periodType = Timer_PeriodType_COUNTS;
        return(TRUE);
    }
}

/*
 *  ======== Timer_trigger ========
 *
 *  1. stop timer
 *  2. write the period with insts
 *  3. start the timer.
 *
 */
Void Timer_trigger(Timer_Object *obj, UInt32 insts)
{
    UInt key;

    /* follow proper procedure for dynamic period change */
    key = Hwi_disable();

    /* Force SMCLK for sweep timer */
    obj->controlRegInit &= ~0x0100;     /* clear ACLK bit */
    obj->controlRegInit |= 0x0200;      /* enable SMCLK */

    Timer_stop(obj);
    
    Timer_setPeriod(obj, insts);
    Timer_start(obj);
    Hwi_restore(key);
}

/*
 *  ======== Timer_getPeriod ========
 */
UInt32 Timer_getPeriod(Timer_Object *obj)
{
    return(obj->period);
}

/*
 *  ======== Timer_getCount ========
 */
UInt32 Timer_getCount(Timer_Object *obj)
{
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;
    UInt first;
    UInt second;

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    /* if timer's source clock is synchronous to CPU: only read counts once */
    if (obj->synchronous) {
        first = timer->count;
    }

    /* else, must do multiple reads to avoid possible spurious values */
    else {
        /* read twice, expecting equal values, or within read latency */
        do {
            first = timer->count;
            second = timer->count;
        } while ((first != second) && ((second - first) > READ_LATENCY)); 
    }

    return (((UInt32) first) & 0xffff);
}

/*
 *  ======== Timer_oneShotStub ========
 */
Void Timer_oneShotStub(UArg arg)
{
    Timer_Object *obj;
    obj = Timer_module->handles[(UInt)arg];

    /* stop the timer (and disable this interrupt source) */
    Timer_stop(obj);

    /* call the tick function */
    obj->tickFxn(obj->arg);
}

/*
 *  ======== Timer_oneShotNestStub ========
 */
Void Timer_oneShotNestStub(UArg arg)
{
    Timer_Object *obj;
    obj = Timer_module->handles[(UInt)arg];

    /* stop the timer (and disable this interrupt source) */
    Timer_stop(obj);

    /* enable interrupts to allow nesting */ 
    Hwi_enable();            

    /* call the tick function */
    obj->tickFxn(obj->arg);

    /* disable interrupts as unwind the ISR */
    Hwi_disable();           
}

/*
 *  ======== Timer_periodicStub ========
 */
Void Timer_periodicStub(UArg arg)
{
    Timer_Object *obj;
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;

    obj = Timer_module->handles[(UInt)arg];

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    /* save previous threshold value */
    obj->prevThreshold = timer->cc_compare_0;

    /* set compare threshold for next periodic interrupt */
    timer->cc_compare_0 += obj->period;

    /* call the tick function */
    obj->tickFxn(obj->arg);
}

/*
 *  ======== Timer_periodicNestStub ========
 */
Void Timer_periodicNestStub(UArg arg)
{
    Timer_Object *obj;
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;

    obj = Timer_module->handles[(UInt)arg];

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    /* save previous threshold value */
    obj->prevThreshold = timer->cc_compare_0;

    /* set compare threshold for next periodic interrupt */
    timer->cc_compare_0 += obj->period;

    /* allow nesting of other interrupts ... */
    timer->cctl_0 &= ~TIMER_COMPARE_INTR_ENABLE;
    Hwi_enable();

    /* call the tick function */
    obj->tickFxn(obj->arg);

    /* disable interrupts as unwind the ISR */
    Hwi_disable();
    timer->cctl_0 |= TIMER_COMPARE_INTR_ENABLE;
}

/*
 *  ======== Timer_getExpiredCounts ========
 *
 *  This API is used by the TimestampProvider as part of retrieving a timestamp
 *  using a timer and a tick counter. It returns the expired counts since the
 *  last serviced timer interrupt.
 *
 *  This API must be called with interrupts disabled; the TimestampProvider
 *  must disable interrupts while retrieving the tick count and calling this
 *  API.
 *
 *  The TimestampProvider uses a 32-bit timer and 32-bit tick count to track
 *  the timestamp. The tick count either comes from the Clock module or is
 *  stored in the TimestampProvider's module state and incremented by an ISR
 *  when the timer expires.
 * 
 *  For MSP430 we have 16-bit timers, and use a timer compare feature to 
 *  trigger an interrupt upon a specific threshold count being reached.  The 
 *  timer counts can rollover (going thru zero), on the way to reaching the 
 *  next threshold.  We need to  accommodate this rollover as part of 
 *  determining expired counts.
 *
 *  We also need to handle the case where there is a large period value used
 *  for the timer, and the timer is ticking at a fast rate (e.g., the CPU
 *  rate, via an SMCLK selection).  For this case, it is possible that
 *  interrupts are disabled before the timer reaches threshold, and then the
 *  timer reaches the threshold count and asserts an interrupt, and then 
 *  continues to count upwards before it is read in this routine.  If the 
 *  timer rolled past zero, then we need to know that there is an interrupt 
 *  pending, otherwise we'd report a low count, versus the period plus
 *  that low count.
 *
 *  To be sure to catch the interrupt, we sample the interrupt flag, read
 *  the count, and then sample the interrupt flag again:
 *
 *      intrFlag1
 *      count
 *      intrFlag2
 *
 *  If intrFlag1 is set, then we know we've reached the period count, and
 *  need to add it to the reported counts.  If intrFlag2 is set, but 
 *  intrFlag1 wasn't, we know the timer just reached threshold, and simply
 *  report the period count.  
 *
 *  If neither interrupt flag is set, we can then compute the expired counts by
 *  comparing the count to the previous interrupt threshold (saved in the
 *  timer object).  If the current count is greater than or equal to the 
 *  previous threshold value, then we know there has been no counter rollover, 
 *  and the expired counts is simply:
 *
 *      result = count - prevThresh
 *
 *  If the current count is less than the previous threshold, then we know a
 *  counter rollover has occurred since the last ISR.  In this case, the 
 *  expired counts has to include those between the previous threshold and
 *  zero, plus any counts after rolling past zero:
 *
 *      result = (0 - prevTresh) + count
 *
 *  Similar logic to compare the current count to previous threshold can
 *  be used for the case where we know intrFlag1 has been set, and we
 *  need to figure the counts to be added to the period counts.
 *
 */
UInt32 Timer_getExpiredCounts(Timer_Object *obj)
{
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;
    UInt32 result32;
    UInt32 count32;
    UInt32 thresh32;
    UInt32 period32;
    UInt32 prev32;
    Bool intrFlag1;
    Bool intrFlag2;

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    intrFlag1 = timer->cctl_0 & TIMER_COMPARE_INTR_PENDING;
    count32 = Timer_getCount(obj) & 0xffff;
    intrFlag2 = timer->cctl_0 & TIMER_COMPARE_INTR_PENDING;
    prev32 = obj->prevThreshold & 0xffff;

    /* interrupt pending before read count? */
    if (intrFlag1) { 
        thresh32 = timer->cc_compare_0 & 0xffff;  /* threshold for interrupt */
        period32 = Timer_getPeriod(obj) & 0xffff; /* period count */

        /* threshold reached; no wrap thru zero yet */
        if (count32 >= thresh32) { 
            result32 = (count32 - thresh32) + period32;
        }
        /* threshold reached; count has wrapped thru zero */
        else { 
            result32 = (0x10000 - thresh32) + count32 + period32;
        }
    }

    /* new interrupt now pending, when wasn't before read the count */
    else if (intrFlag2) { 
        result32 = Timer_getPeriod(obj) & 0xffff; /* return period count */
    }

    /* interrupt threshold not reached; check if wrapped thru zero */
    else if (count32 >= prev32) {  
        result32 = count32 - prev32;
    }

    /* interrupt threshold not reached; count has wrapped thru zero */
    else { 
        result32 = (0x10000 - prev32) + count32;
    }

    return (result32);
}

/*
 *  ======== Timer_getFreq ========
 */
Void Timer_getFreq(Timer_Object *obj, Types_FreqHz *freq)
{
    freq->lo = obj->frequency.lo;
    freq->hi = 0;
}

/*
 *  ======== Timer_getFunc ========
 */
Timer_FuncPtr Timer_getFunc(Timer_Object *obj, UArg *arg)
{
    *arg = obj->arg;
    return (obj->tickFxn);
}

/*
 *  ======== Timer_setFunc ========
 */
Void Timer_setFunc(Timer_Object *obj, Timer_FuncPtr fxn, UArg arg)
{
    obj->tickFxn = fxn;
    obj->arg = arg;
}

/*
 *  ======== checkOverflow ========
 */
static Bool checkOverflow(UInt32 a, UInt32 b)
{
    return ((b > 0) && (a > Timer_MAX_PERIOD/b));
}

/* ======== initDevice ========
 *
 * 1. Stop timer (set control registers back to default value)
 * 2. Disable timer interrupt
 * 3. Clear any pending interrupt
 * 4. Clear counters
 *
 */
static Void initDevice(Timer_Object *obj)
{
    ti_catalog_msp430_peripherals_timers_TimerRegs *timer;
    UInt key;

    timer = (ti_catalog_msp430_peripherals_timers_TimerRegs *)
        Timer_module->device[obj->id].baseAddr;

    key = Hwi_disable();

    /* stop timer; set default control register */
    timer->control = TIMER_CONTROL_DEFAULT;

    /* clear timer interrupt flag */
    timer->cctl_0 &= ~TIMER_COMPARE_INTR_PENDING;

    /* reset timer counts */
    timer->control |= TIMER_CONTROL_CLEAR;

    Hwi_restore(key);
}

/*
 *  ======== postInit ========
 */
static Int postInit (Timer_Object *obj, Error_Block *eb)
{
    UInt key;

    key = Hwi_disable();

    initDevice(obj);

    Timer_setPeriod(obj, obj->period);

    Hwi_restore(key);

    return (0);
}

/*
 */



/*
 *  @(#) ti.sysbios.family.msp430; 1, 0, 0, 0,215; 5-18-2012 06:05:16; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

