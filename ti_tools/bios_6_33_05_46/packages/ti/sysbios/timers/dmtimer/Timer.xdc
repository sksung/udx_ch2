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
 *  ======== Timer.xdc ========
 *
 *
 */

package ti.sysbios.timers.dmtimer;

import xdc.rov.ViewInfo;

import xdc.runtime.Assert;
import xdc.runtime.Error;
import xdc.runtime.Types;
import ti.sysbios.interfaces.ITimer;
import ti.sysbios.hal.Hwi;

/*!
 *  ======== Timer ========
 *  Timer Peripheral Manager.
 *
 *  This Timer module manages the Dual Mode timer (dmtimer) peripherals
 *  available on the ARM and C6000 devices (see
 *  {@link ./doc-files/TimerTables.html Timer Mapping Tables} for supported
 *  device information).
 *
 *  The dmtimer Timer module supports the timer in 'one shot', 'continuous',
 *  and 'dynamic' modes.
 *
 *  In 'one shot' mode, a timer function will "fire" (run) when the timer period
 *  expires (counts up to zero). In 'one shot' mode this will only happen
 *  once.  
 *
 *  In 'continuous' mode, the specified timer function will "fire" every
 *  time the period expires, throughout the lifetime of the program.  When the
 *  period expires in 'continuous mode', the period is then reset to its
 *  original value and then begins counting up to zero again.  At this point
 *  the timer function will fire again and the cycle repeats itself.
 *
 *  In 'dynamic' mode, the specified timer function will "fire" every
 *  time the period expires.  But the period of the timer can be changed 
 *  dynamically, to correspond to the next tick interrupt needed from the
 *  timer.  The timer will continually count upwards, and the timer's compare 
 *  mode is used to generate an interrupt when a specific threshold count is
 *  reached.  This mode is used by the SYS/BIOS Clock module, for implementing
 *  dynamic tick suppression, which reduces the number of interrupts from the 
 *  timer to the minimum required for currently scheduled timeouts.
 *
 *  @p(html)
 *  <h3> Calling Context </h3>
 *  <table border="1" cellpadding="3">
 *    <colgroup span="1"></colgroup> <colgroup span="5" align="center">
 *  </colgroup>
 *
 *    <tr><th> Function                 </th><th>  Hwi   </th><th>  Swi   </th>
 *  <th>  Task  </th><th>  Main  </th><th>  Startup  </th></tr>
 *    <!--                                                          -->
 *    <tr><td> {@link #getNumTimers}            </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getStatus}               </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #Params_init}             </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #construct}               </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #create}                  </td><td>   N    </td>
 *  <td>   N    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #delete}                  </td><td>   N    </td>
 *  <td>   N    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #destruct}                </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getCount}                </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   N    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getFreq}                 </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getFunc}                 </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getPeriod}               </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #reconfig}                </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #setFunc}                 </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #setPeriod}               </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #setPeriodMicroSecs}      </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #start}                   </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   N    </td><td>   N    </td></tr>
 *    <tr><td> {@link #stop}                    </td><td>   Y    </td>
 *  <td>   Y    </td><td>   Y    </td><td>   N    </td><td>   N    </td></tr>
 *    <tr><td colspan="6"> Definitions: <br />
 *       <ul>
 *         <li> <b>Hwi</b>: API is callable from a Hwi thread. </li>
 *         <li> <b>Swi</b>: API is callable from a Swi thread. </li>
 *         <li> <b>Task</b>: API is callable from a Task thread. </li>
 *         <li> <b>Main</b>: API is callable during any of these phases: </li>
 *           <ul>
 *             <li> In your module startup after this module is started 
 *  (e.g. Timer_Module_startupDone() returns TRUE). </li>
 *             <li> During xdc.runtime.Startup.lastFxns. </li>
 *             <li> During main().</li>
 *             <li> During BIOS.startupFxns.</li>
 *           </ul>
 *         <li> <b>Startup</b>: API is callable during any of these phases:</li>
 *           <ul>
 *             <li> During xdc.runtime.Startup.firstFxns.</li>
 *             <li> In your module startup before this module is started 
 *  (e.g. Timer_Module_startupDone() returns FALSE).</li>
 *           </ul>
 *       </ul>
 *    </td></tr>
 *
 *  </table>
 *  @p
 *
 *  @p(html)
 *  <h3> Timer Mapping Tables </h3>
 *  <p>
 *  The Timer module allows the user to use and configure the various timers
 *  that exist on a particular device.  This is achieved by specifying a timer
 *  ID when calling {@link ti.sysbios.hal.Timer#Timer_create}. 
 *  However, the timer ID
 *  specified may not always map to that timer; for example, specifying an ID
 *  value of 1 does not necessarily mean that this will map to "GPTimer1".
 *  These tables are provided to show which timers map to which timer IDs.
 *  </p>
 *  {@link ./doc-files/TimerTables.html Timer Mapping Tables}
 *  @p
 */
@InstanceFinalize       /* To cleanup */
@InstanceInitError      /* To report unavailability of timer */
@ModuleStartup          /* to configure static timers */

module Timer inherits ti.sysbios.interfaces.ITimer
{
    /*! override supportsDynamic - this Timer does support RunMode_DYNAMIC */
    override metaonly config Bool supportsDynamic = true;

    /*! Max value of Timer period for PeriodType_COUNTS*/
    const UInt MAX_PERIOD = 0xffffffff;

    /*! L4 interface Configuration Register (TIOCP_CFG). */
    struct TiocpCfg {
        Bits8 idlemode;  /*! 0=force-idle;1=no-idle;2=Smart-idle;3=Smart-idle */
        Bits8 emufree;   /*! 0=counter frozen; 1=counter free-running */
        Bits8 softreset; /*! 0=normal mode; 1=soft reset */
    };

    /*! Interrupt Enable Register (TIER). */
    struct Tier {
        Bits8 mat_it_ena;  /*! Enable match interrupt */
        Bits8 ovf_it_ena;  /*! Enable overflow interrupt */
        Bits8 tcar_it_ena; /*! Enable capture interrupt */
    };

    /*! WakepUp Enable Register (TWER). */
    struct Twer {
        Bits8 mat_wup_ena;  /*! Enable match wake-up */
        Bits8 ovf_wup_ena;  /*! Enable overflow wake-up */
        Bits8 tcar_wup_ena; /*! Enable capture wake-up */
    };

    /*! Control Register (TCLR). */
    struct Tclr {
        Bits32 ptv; /*! Trigger output mode */
        Bits8 pre;  /*! Prescalar enable */
        Bits8 ce;   /*! Compare enable */
        Bits8 scpwm;/*! Pulse-width modulation */
        Bits16 tcm; /*! Transition capture mode */
        Bits16 trg; /*! Trigger output mode */
        Bits8 pt;   /*! Pulse or toggle select bit */
        Bits8 captmode; /*! Capture mode select bit */
        Bits8 gpocfg; /*! PWM output/event detection input pin */
    };

    /*! L4 Interface Synchronization Control Register (TSICR). */
    struct Tsicr {
        Bits8 sft;    /*! Reset software functional registers */
        Bits8 posted; /*! Posted mode selection */
    };

    /*! Timer Settings. */
    metaonly struct TimerSetting {
        Bool master;    /*! specifies whether this is the master */
        Ptr baseAddr;   /*! specify the base address  */
        Int intNum;     /*! specify which interrupt vector */
        String name;    /*! specify the timer name */
    };

    /*!
     *  ======== BasicView ========
     *  @_nodoc
     */
    metaonly struct BasicView {
        Ptr         halTimerHandle;
        String      label;
        UInt        id;
        String      name;
        String      startMode;
        String      runMode;
        UInt        period;
        String      periodType;
        UInt        intNum;
        String      tickFxn[];
        UArg        arg;
        String      extFreqLow;
        String      extFreqHigh;
        String      hwiHandle;
    };


    /*!
     *  ======== ModuleView ========
     *  @_nodoc
     */
    metaonly struct ModuleView {
        String          availMask;      /* avaliable 32-bit timer halves */
        String intFrequency;    /* internal frequency in Hz */
    }

    /*!
     *  ======== rovViewInfo ========
     *  @_nodoc
     */
    @Facet
    metaonly config ViewInfo.Instance rovViewInfo = 
        ViewInfo.create({
            viewMap: [
            [
                'Basic',
                {
                    type: ViewInfo.INSTANCE,
                    viewInitFxn: 'viewInitBasic',
                    structName: 'BasicView'
                }
            ],
            [
                'Module',
                {
                    type: ViewInfo.MODULE,
                    viewInitFxn: 'viewInitModule',
                    structName: 'ModuleView'
                }
            ],
            ]
        });

    /*!
     *  Assert raised when statically created timer is not available
     */
    config xdc.runtime.Assert.Id A_notAvailable = {
        msg: "A_notAvailable: statically created timer not available"
    };

    /*!
     *  Error raised when timer id specified is not supported.
     */
    config Error.Id E_invalidTimer = {
        msg: "E_invalidTimer: Invalid Timer Id %d"
    };

    /*!
     *  Error raised when timer requested is in use
     */
    config Error.Id E_notAvailable  = {
        msg: "E_notAvailable: Timer not available %d"
    };

    /*!
     *  Error raised when period requested is not supported
     */
    config Error.Id E_cannotSupport = {
        msg: "E_cannotSupport: Timer cannot support requested period %d"
    };
    
    /*!
     *  Error raised when timer frequency does not match expected frequency
     *
     *  BIOS does not configure the DMTimer clock source and expects this
     *  configuration to be performed via a GEL script or on the host OS.  This
     *  error is raised if BIOS detects a mismatch between {@link #intFreq} and
     *  the actual operating frequency.  The check is performed by comparing
     *  the timestamp operating frequency with the DMTimer frequency.
     * 
     *  To change the expected timer frequency to match the actual operating 
     *  frequency, use the following example configuration:
     *  @p(code)
     *      var Timer = xdc.useModule('ti.sysbios.timers.dmtimer.Timer');
     *      Timer.intFreq.lo = 20000000; //For 20Mhz
     *      Timer.intFreq.hi = 0;
     *  @p
     *
     *  This check can be skipped by setting {@link #checkFrequency} to FALSE.
     */
    config Error.Id E_freqMismatch  = {
        msg: "E_freqMismatch: Frequency mismatch: Expected %d Hz, actual: %d Hz.  You need to modify Timer.intFreq.lo to match the actual frequency."
    };

    /*!
     *  ======== anyMask ========
     *  Available mask to be used when select = Timer_ANY. 
     *
     *  Default value is device specific.
     */
    config Bits32 anyMask;

    /*!
     *  ======== checkFrequency ========
     *  Whether to check the timer operating frequency at startup
     *
     *  When this flag is set to 'TRUE', the Timer module will verify that the
     *  operating frequency equals the frequency at which BIOS expects the 
     *  timers to operate.  This check is performed by checking the timer count
     *  rate against the {@link xdc.runtime.Timestamp} count rate.
     */
    config Bool checkFrequency = true;

    /*!
     *  ======== timerSettings ========
     *  Global Control configuration for each physical timer.
     */
    metaonly config TimerSetting timerSettings[] = [];
    
    /*!
     *  ======== intFreq ========
     *  Default internal timer input clock frequency.
     */
    metaonly config Types.FreqHz intFreq = {lo: 0, hi: 0};
    
    /*!
     *  ======== stub  ========
     *  @_nodoc
     *  Timer requires acknowledgement
     *
     *  @param(arg)     timer object passed in as argument.
     */
    @DirectCall
    Void stub(UArg arg);

    /*!
     *  ======== dynStub  ========
     *  @_nodoc
     *  Acknowledges timer interrupt and sets next threshold for interrupt.
     *
     *  @param(arg)     timer object passed in as argument.
     */
    @DirectCall
    Void dynStub(UArg arg);

    /*!
     *  ======== setAvailMask ========
     *  @_nodoc
     *  Sets dmtimer anyMask.
     *
     *  @param(arg) new anyMask is passed in as argument.
     */
    Void setAvailMask(UArg arg);                                      

instance:

    /*! 
     *  ======== tiocpCfg ========
     *  Initial Timer TIOCP_CFG Register bit settings.
     *
     *  For a detailed description of this timer register, please
     *  refer to your device's Technical Reference Manual.
     */
    config TiocpCfg tiocpCfg = {idlemode: 0, emufree: 0, softreset: 1};

    /*! 
     *  ======== tier ========
     *  Initial Timer IRQSTATUS_SET Register bit settings.
     *
     *  For a detailed description of this timer register, please
     *  refer to your device's Technical Reference Manual.
     */
    config Tier tier = {mat_it_ena: 0, ovf_it_ena: 1, tcar_it_ena: 0};

    /*! 
     *  ======== twer ========
     *  Initial Timer IRQ Wakeup Enable Register bit settings.
     *
     *  For a detailed description of this timer register, please
     *  refer to your device's Technical Reference Manual.
     */
    config Twer twer = {mat_wup_ena: 0, ovf_wup_ena: 0, tcar_wup_ena: 0};

    /*! 
     *  ======== tclr ========
     *  Initial Timer Control Register bit settings.
     *
     *  For a detailed description of this timer register, please
     *  refer to your device's Technical Reference Manual.
     */
    config Tclr tclr = {ptv: 0, pre: 0, ce: 0, scpwm: 0, tcm: 0, trg: 0,
        pt: 0, captmode: 0, gpocfg: 0};
    
    /*! 
     *  ======== tsicr ========
     *  Initial Timer Synchronous Interface Control Register bit settings.
     *
     *  For a detailed description of this timer register, please
     *  refer to your device's Technical Reference Manual.
     */
    config Tsicr tsicr = {sft: 0, posted: 1};

    /*! 
     *  ======== tmar ========
     *  Initial Timer Match Register setting.
     *
     *  For a detailed description of this timer register, please
     *  refer to your device's Technical Reference Manual.
     */
    config UInt32 tmar = 0;

    /*! 
     *  ======== intNum ========
     *  Hwi interrupt number to be used by Timer.
     */
    config Int intNum = -1;

    /*! Hwi Params for Hwi Object. Default is null. */
    config Hwi.Params *hwiParams = null;

    /*!
     *  ======== reconfig ========
     *  Used to modify static timer instances at runtime.
     *
     *  @param(timerParams)     timer Params
     *  @param(tickFxn)         functions that runs when timer expires
     */
    @DirectCall
    Void reconfig(FuncPtr tickFxn, const Params *timerParams, Error.Block *eb);

    /*!
     *  ======== getRollovers  ========
     *  @_nodoc
     *  Returns the total number of timer rollovers since the timer was 
     *  started.  This API is used internally for implementing timestamping 
     *  when the timer is shared with Clock, and running with RunMode_DYNAMIC.
     *  It has no other intended purpose.
     *
     *  @b(returns)     number of rollovers since timer was started
     */
    @DirectCall
    UInt32 getRollovers();

    /*!
     *  ======== enableTimestamping  ========
     *  @_nodoc
     *  Enables the timer to be used for timestamping purposes.  This API is 
     *  used internally for enabling timestamping when the timer is shared with
     *  Clock, and running with RunMode_DYNAMIC. It has no other intended 
     *  purpose.
     *
     */
    @DirectCall
    Void enableTimestamping();
    

internal:   /* not for client use */
    

    /*! Device-specific Timer implementation. */
    proxy TimerSupportProxy inherits ti.sysbios.interfaces.ITimerSupport;

    /*!
     *  ======== startupNeeded ========
     *  This flag is use to prevent Timer_startup code (includes postInit(),
     *  deviceConfig(), initDevice() to be brought in un-necessarily.
     */
    config Bool startupNeeded = false;

    /*! Information about timer */
    struct TimerDevice {
        UInt intNum;
        UInt eventId;
        Ptr  baseAddr;
    };

    /*!
     *  ======== numTimerDevices ========
     *  The number of logical timers on a device.
     */
    config Int numTimerDevices;

    /*!
     *  ======== spinLoop ========
     *  used by trigger function.
     */
    Void spinLoop(UInt count);
    
    /*!
     *  ======== checkFreq ========
     *  Used to verify that the DMTimer is operating at the right frequency.
     */
    Void checkFreq(Timer.Object *obj);

    /*! Instance state structure */
    struct Instance_State {
        Bool                    staticInst;     /* statically created or not */
        Int                     id;             /* logical timer id. */
        UInt                    tiocpCfg;
        UInt                    tmar;
        UInt                    tier;
        UInt                    twer;
        UInt                    tclr;
        UInt                    tsicr;
        ITimer.RunMode          runMode;        /* timer mode */
        ITimer.StartMode        startMode;      /* timer mode */
        UInt                    period;         /* period */
        ITimer.PeriodType       periodType;     /* type (microsecs, inst) */
        UInt                    intNum;         /* intr num */
        UArg                    arg;            /* isrFxn arg */
        Hwi.FuncPtr             tickFxn;        /* Timer fxn plugged into Hwi */
        Types.FreqHz            extFreq;        /* ext freq */
        Hwi.Handle              hwi;            /* hwi inst */
        UInt                    prevThreshold;  /* previous interrupt thresh */
        UInt                    rollovers;      /* total timer rollovers */
    }

    /*! Module state structure */
    struct Module_State {
        Bits32          availMask;      /* avaliable 32-bit timer halves */
        Types.FreqHz    intFreq;        /* internal frequency in Hz */
        TimerDevice     device[];       /* timer device information */
        Handle          handles[];      /* handles based on logical id */
        Bool            firstInit;
    }
}
/*
 *  @(#) ti.sysbios.timers.dmtimer; 2, 0, 0, 0,258; 5-18-2012 06:06:12; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

