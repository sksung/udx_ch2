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
 *  ======== Settings.xs ========
 *
 */

var settings = {
    device: {
        "TMS320CDM6446": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.timer64.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.dm6446.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C64P", "ti.targets.elf.C64P" ] 
        },
        "TMS320CDM6437": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.timer64.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.dm6437.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C64P", "ti.targets.elf.C64P" ] 
        },
        "TMS320CTCI6482": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.timer64.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.tci6482.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C64P", "ti.targets.elf.C64P" ] 

        },
        "TMS320CTCI6488": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.timer64.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.tci6488.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C64P", "ti.targets.elf.C64P" ] 
        },
        "TMS320C6670": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.timer64.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.tci6488.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c66.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.elf.C66" ] 
        },
        "TMS320DA830": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.timer64.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.primus.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C674", "ti.targets.elf.C674" ]
        },
        "TMS320C3430": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.gptimer.Timer",
            timerSupportDelegate : "ti.sysbios.family.c64p.omap3430.TimerSupport",
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C64P", "ti.targets.elf.C64P" ] 
        },
        "OMAP4430": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.dmtimer.Timer",
            /* dmtimer picks its own timerSupport Delegate */
            timerSupportDelegate : null, 
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.hal.unicache.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.elf.C64T" ]
        },
        "TMS320TI816X": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.dmtimer.Timer",
            /* dmtimer picks its own timerSupport Delegate */
            timerSupportDelegate : null, 
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c64p.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.C674", "ti.targets.elf.C674" ]
        },
        "Vayu": {
            hwiDelegate : "ti.sysbios.family.c64p.Hwi",
            timerDelegate : "ti.sysbios.timers.dmtimer.Timer",
            /* dmtimer picks its own timerSupport Delegate */
            timerSupportDelegate : null, 
            timestampDelegate : "ti.sysbios.family.c64p.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c62.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c62.IntrinsicsSupport",
            cacheDelegate : "ti.sysbios.family.c66.Cache",
            clockTickPeriod : 1000,
            targets : [ "ti.targets.elf.C66" ]
        },
    }
}

settings.device["TMS320CDM415"]   = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM420"]   = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM421"]   = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM425"]   = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM426"]   = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM6441"]  = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM6443"]  = settings.device["TMS320CDM6446"];
settings.device["TMS320CDM6467"]  = settings.device["TMS320CDM6446"];

settings.device["TMS320C6421"]    = settings.device["TMS320CDM6437"];
settings.device["TMS320C6424"]    = settings.device["TMS320CDM6437"];
settings.device["TMS320CDM6431"]  = settings.device["TMS320CDM6437"];
settings.device["TMS320CDM6433"]  = settings.device["TMS320CDM6437"];
settings.device["TMS320CDM6435"]  = settings.device["TMS320CDM6437"];

settings.device["TMS320C6452"]    = settings.device["TMS320CTCI6482"];
settings.device["TMS320C6454"]    = settings.device["TMS320CTCI6482"];
settings.device["TMS320C6455"]    = settings.device["TMS320CTCI6482"];
settings.device["TMS320CDM647"]   = settings.device["TMS320CTCI6482"];
settings.device["TMS320CDM648"]   = settings.device["TMS320CTCI6482"];
settings.device["TMS320C6457"]    = settings.device["TMS320CTCI6482"];
settings.device["TMS320CTCI6484"] = settings.device["TMS320CTCI6482"];

settings.device["TMS320C6474"]    = settings.device["TMS320CTCI6488"];
settings.device["TMS320C6472"]    = settings.device["TMS320CTCI6488"];
settings.device["TMS320CTCI6486"] = settings.device["TMS320CTCI6488"];
settings.device["TMS320CTCI6487"] = settings.device["TMS320CTCI6488"];
settings.device["TMS320TCI6485"]  = settings.device["TMS320CTCI6488"];
settings.device["TMS320TCI6489"]  = settings.device["TMS320CTCI6488"];

settings.device["Kepler"]         = settings.device["TMS320C6670"];
settings.device["TMS320TCI6634"]  = settings.device["TMS320C6670"];
settings.device["TMS320TCI6636"]  = settings.device["TMS320C6670"];
settings.device["TMS320TCI6638"]  = settings.device["TMS320C6670"];
settings.device["TMS320TCI6608"]  = settings.device["TMS320C6670"];
settings.device["TMS320TCI6614"]  = settings.device["TMS320C6670"];
settings.device["TMS320TCI6616"]  = settings.device["TMS320C6670"];
settings.device["TMS320TCI6618"]  = settings.device["TMS320C6670"];
settings.device["TMS320C6654"]    = settings.device["TMS320C6670"];
settings.device["TMS320C6655"]    = settings.device["TMS320C6670"];
settings.device["TMS320C6657"]    = settings.device["TMS320C6670"];
settings.device["TMS320C6671"]    = settings.device["TMS320C6670"];
settings.device["TMS320C6672"]    = settings.device["TMS320C6670"];
settings.device["TMS320C6674"]    = settings.device["TMS320C6670"];
settings.device["TMS320C6678"]    = settings.device["TMS320C6670"];

settings.device["TMS320C2430"]    = settings.device["TMS320C3430"];
settings.device["OMAP2431"]       = settings.device["TMS320C3430"];
settings.device["OMAP2530"]       = settings.device["TMS320C3430"];
settings.device["OMAP2531"]       = settings.device["TMS320C3430"];
settings.device["OMAP3425"]       = settings.device["TMS320C3430"];
settings.device["OMAP3525"]       = settings.device["TMS320C3430"];
settings.device["OMAP3530"]       = settings.device["TMS320C3430"];

settings.device["Tesla"]          = settings.device["OMAP4430"];
settings.device["OMAP5430"]       = settings.device["OMAP4430"];
settings.device["TMS320CDM740"]   = settings.device["TMS320TI816X"];
settings.device["TMS320C6A8149"]  = settings.device["TMS320TI816X"];
settings.device["TMS320C6A8168"]  = settings.device["TMS320TI816X"];
settings.device["TMS320TI811X"]   = settings.device["TMS320TI816X"];
settings.device["TMS320TI814X"]   = settings.device["TMS320TI816X"];
settings.device["TMS320DM8148"]   = settings.device["TMS320TI816X"];
settings.device["TMS320DM8168"]   = settings.device["TMS320TI816X"];
settings.device["Arctic"]         = settings.device["TMS320TI816X"];

settings.device["TMS320DA802"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA803"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA804"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA805"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA807"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA808"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA810"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA828"]    = settings.device["TMS320DA830"];
settings.device["TMS320C6747"]    = settings.device["TMS320DA830"];
settings.device["TMS320C6745"]    = settings.device["TMS320DA830"];
settings.device["TMS320C6743"]    = settings.device["TMS320DA830"];
settings.device["OMAPL137"]       = settings.device["TMS320DA830"];

settings.device["OMAPL108"]       = settings.device["TMS320DA830"];
settings.device["OMAPL118"]       = settings.device["TMS320DA830"];
settings.device["OMAPL138"]       = settings.device["TMS320DA830"];
settings.device["TMS320DA840"]    = settings.device["TMS320DA830"];
settings.device["TMS320DA850"]    = settings.device["TMS320DA830"];
settings.device["TMS320C6742"]    = settings.device["TMS320DA830"];
settings.device["TMS320C6746"]    = settings.device["TMS320DA830"];
settings.device["TMS320C6748"]    = settings.device["TMS320DA830"];

/*
 *  ======== deviceSupportCheck ========
 *  Check validity of device
 */
function deviceSupportCheck() 
{
    for (device in settings.device) {
        if (device == Program.cpu.deviceName) {
            return;
        }
    }
    print("The " + Program.cpu.deviceName + " device is not currently supported.");
    print("The following devices are supported for the " + Program.build.target.name + " target:");
    for (device in settings.device) {
        print("\t" + device);
    }
    throw new Error ("Unsupported device!");
}

/*
 *  ======== getDefaultHwiDelegate ========
 */
function getDefaultHwiDelegate()
{
    deviceSupportCheck();
    return (settings.device[Program.cpu.deviceName].hwiDelegate);
}

/*
 *  ======== getDefaultTimerDelegate ========
 */
function getDefaultTimerDelegate()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].timerDelegate);
}

/*
 *  ======== getDefaultTimerSupportDelegate ========
 */
function getDefaultTimerSupportDelegate()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].timerSupportDelegate);
}

/*
 *  ======== getDefaultTimestampDelegate ========
 */
function getDefaultTimestampDelegate()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].timestampDelegate);
}

/*
 *  ======== getDefaultTaskSupportDelegate ========
 */
function getDefaultTaskSupportDelegate()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].taskSupportDelegate);
}

/*
 *  ======== getDefaultIntrinsicsSupportDelegate ========
 */
function getDefaultIntrinsicsSupportDelegate()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].intrinsicsSupportDelegate);
}

/*
 *  ======== getDefaultCacheDelegate ========
 */
function getDefaultCacheDelegate()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].cacheDelegate);
}

/*
 *  ======== getDefaultClockTickPeriod ========
 */
function getDefaultClockTickPeriod()
{
    deviceSupportCheck();
    return(settings.device[Program.cpu.deviceName].clockTickPeriod);
}

/*
 *  ======== getDefaultBootModule ========
 */
function getDefaultBootModule()
{
    return (null);
}

/*
 *  ======== getDefaultMmuModule ========
 */
function getDefaultMmuModule()
{
    return (null);
}

/*
 *  ======== getFamilySettingsXml ========
 */
function getFamilySettingsXml()
{
    return("family/c64p/Settings.xml");
}
/*
 *  @(#) ti.sysbios.family.c64p; 2, 0, 0, 0,555; 5-18-2012 06:04:49; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

