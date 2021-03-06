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
 */

/*
 *  ======== setDeviceAliases ========
 */
function setDeviceAliases(settingsTable, aliasTable) 
{
    /* Number of times to call the outer loop */
    var numLoops = 6;

    /* 
     *  Execute the 2nd loop 'numLoops' times to allow aliases of aliases
     *  to be applied to the table
     */
    for (var i = 0; i < numLoops; i++) {
        for (var device in aliasTable) {
            for each (var alias in aliasTable[device]) {
                /* 
                 *  Define the alias only if the alias doesn't already exist
                 *  in the table and if the device does exist in the table.
                 */
                if (settingsTable[alias] == null && 
                    settingsTable[device] != null) {
                    settingsTable[alias] = settingsTable[device];
                }
            }
        }
    }
}

/*
 *  ======== setCatalogAliases ========
 */
function setCatalogAliases(settingsTable, aliasTable) 
{
    for (var catalogName in settingsTable) {
        if (aliasTable[catalogName] != null) {
            var catalogAlias = aliasTable[catalogName];
            if (settingsTable[catalogAlias] == null) {
                settingsTable[catalogAlias] = settingsTable[catalogName];
                continue;
            }
            for (var deviceName in settingsTable[catalogName]) {
                settingsTable[catalogAlias][deviceName] = 
                    settingsTable[catalogName][deviceName];
            }
        }
    }
}

/*
 *  ======== catalogAliases ========
 *  Aliases for catalog 
 */
var catalogAliases = {
    'ti.catalog.arm.cortexm3' : ['ti.catalog.arm'],
}
 
/*
 *  ======== deviceAliases ========
 *  Aliases for devices used in IPC
 */
var deviceAliases = {
    'TMS320C6472'       : ['TMS320CTCI6486'],
    'TMS320C6474'       : ['TMS320CTCI6488'],
    'TMS320DA830'       : ['OMAPL138', 
                           'OMAPL137'],
    'OMAP3530'          : ['TMS320C3430'],
    'TMS320TI816X'      : ['TMS320CDM740', 
                           'TMS320DM8148',
                           'TMS320DM8168', 
                           'TMS320C6A8168', 
                           'TMS320TI811X',
                           'TMS320TI813X',
                           'TMS320TI814X'],
    'TMS320C6678'       : ['TMS320TCI6608', 
                           'Kepler', 
                           'TMS320C6674', 
                           'TMS320C6672'],
    'TMS320C6670'       : ['TMS320TCI6616', 
                           'TMS320CTCI6497', 
                           'TMS320CTCI6498', 
                           'TMS320TCI6618',
                           'TMS320TCI6614',
                           'TMS320C6657'],
}
 
/*
 *  ======== procNames ========
 */
var procNames = {
    'TMS320CDM6446'     : ["DSP", "HOST"],
    'TMS320DA830'       : ["DSP", "HOST"],
    'OMAPL138'          : ["DSP", "HOST"],
    'TMS320TI816X'      : ["DSP", "VIDEO-M3", "VPSS-M3", "HOST"],
    'TMS320TI813X'      : ["VIDEO-M3", "VPSS-M3", "HOST"],
    'TMS320C6A8168'     : ["DSP", "VPSS-M3", "HOST"],
    'TMS320C6670'       : ["CORE0", "CORE1", "CORE2", "CORE3"],
    'TMS320C6657'       : ["CORE0", "CORE1"],
    'TMS320C6672'       : ["CORE0", "CORE1"],
    'TMS320TCI6614'     : ["CORE0", "CORE1", "CORE2", "CORE3", "HOST"],
    'TMS320C6674'       : ["CORE0", "CORE1", "CORE2", "CORE3"],
    'TMS320C6678'       : ["CORE0", "CORE1", "CORE2", "CORE3",
                           "CORE4", "CORE5", "CORE6", "CORE7"],
    'TMS320C6472'       : ["CORE0", "CORE1", "CORE2",
                           "CORE3", "CORE4", "CORE5"],    
    'TMS320C6474'       : ["CORE0", "CORE1", "CORE2"], 
    'OMAP3530'          : ["DSP", "HOST"],
    'OMAP4430'          : ["DSP", "CORE0", "CORE1", "HOST"],
    'Arctic'            : ["DSP", "ARP32"],
    'F28M35x'           : ["M3", "C28"],
};
setDeviceAliases(procNames, deviceAliases);

/*
 *  ======== hostNeedsSlaveData =======
 */
var hostNeedsSlaveData = {
    'TMS320TI816X'      : 1,
    'OMAP3530'          : 1,
    'OMAP4430'          : 1,
    'TMS320CDM6446'     : 1,
    'TMS320DA830'       : 1,
    'OMAPL138'          : 1,
};
setDeviceAliases(hostNeedsSlaveData, deviceAliases);

/*
 *  ======== sr0MemorySetup =======
 *  The devices in this list means these devices have a slave mmu
 *  that needs to be configured by the host before the slave can proceed.
 */
var sr0MemorySetup = {
    'TMS320TI816X'      : 1,
    'OMAP3530'          : 1,
    'OMAP4430'          : 1,
};
setDeviceAliases(sr0MemorySetup, deviceAliases);

/*
 *  ======== hostProcNames =======
 *  The name of the host or master processor.
 */
var hostProcNames = {
    'TMS320CDM6446'     : ["HOST"],
    'TMS320DA830'       : ["HOST"],
    'OMAPL138'          : ["HOST"],
    'TMS320TI816X'      : ["HOST"],
    'OMAP3530'          : ["HOST"],
    'OMAP4430'          : ["HOST"],
    'TMS320C6678'       : ["CORE0"],
    'TMS320C6670'       : ["CORE0"],
    'TMS320C6472'       : ["CORE0"],
    'TMS320C6474'       : ["CORE0"],
    'F28M35x'           : ["M3"],
};
setDeviceAliases(hostProcNames, deviceAliases);

/*
 *  ======== nameServerRemoteDelegates ========
 */
var nameServerRemoteDelegates = {
    'OMAP3530'          : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320CDM6446'     : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320DA830'       : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320TI816X'      : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320C6678'       : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320C6670'       : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320C6472'       : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'TMS320C6474'       : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'OMAP4430'          : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'Arctic'            : { del: 'ti.sdo.ipc.nsremote.NameServerRemoteNotify',},
    'F28M35x'           : { del: 'ti.sdo.ipc.family.f28m35x.NameServerBlock', },
};
setDeviceAliases(nameServerRemoteDelegates, deviceAliases);

/*
 *  ======== notifySetupDelegates ========
 */
var notifySetupDelegates = {
    'OMAP3530'          : { del: 'ti.sdo.ipc.family.omap3530.NotifySetup', },
    'TMS320CDM6446'     : { del: 'ti.sdo.ipc.family.dm6446.NotifySetup', },
    'TMS320DA830'       : { del: 'ti.sdo.ipc.family.da830.NotifySetup', },
    'TMS320TI816X'      : { del: 'ti.sdo.ipc.family.ti81xx.NotifySetup', },
    'TMS320C6678'       : { del: 'ti.sdo.ipc.family.c647x.NotifySetup', },  
    'TMS320C6670'       : { del: 'ti.sdo.ipc.family.c647x.NotifySetup', },  
    'TMS320C6472'       : { del: 'ti.sdo.ipc.family.c647x.NotifySetup', },  
    'TMS320C6474'       : { del: 'ti.sdo.ipc.family.c647x.NotifySetup', },
    'OMAP4430'          : { del: 'ti.sdo.ipc.family.omap4430.NotifySetup', },
    'Arctic'            : { del: 'ti.sdo.ipc.family.arctic.NotifyCircSetup', },
    'F28M35x'           : { del: 'ti.sdo.ipc.notifyDrivers.NotifySetupNull', },
};
setDeviceAliases(notifySetupDelegates, deviceAliases);

/*
 *  ======== messageQSetupDelegates ========
 */
var messageQSetupDelegates = {
    'OMAP3530'          : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },
    'TMS320CDM6446'     : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },
    'TMS320DA830'       : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },
    'TMS320TI816X'      : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },
    'TMS320C6678'       : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },  
    'TMS320C6670'       : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },  
    'TMS320C6472'       : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },  
    'TMS320C6474'       : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },
    'OMAP4430'          : { del: 'ti.sdo.ipc.transports.TransportShmSetup', },
    'Arctic'            : { del: 'ti.sdo.ipc.transports.TransportShmNotifySetup', },
    'F28M35x'           : { del: 'ti.sdo.ipc.transports.TransportNullSetup', },
};
setDeviceAliases(messageQSetupDelegates, deviceAliases);

/*
 *  ======== interruptDelegates ========
 */
var interruptDelegates = {
    'ti.catalog.arm' : {
        'TMS320CDM6446' : { del: 'ti.sdo.ipc.family.dm6446.InterruptArm', },
        'TMS320DA830'   : { del: 'ti.sdo.ipc.family.da830.InterruptArm', },
        'OMAPL138'      : { del: 'ti.sdo.ipc.family.da830.InterruptArm', },
    },
    'ti.catalog.arm.cortexm3' : {
        'TMS320TI816X'  : { del: 'ti.sdo.ipc.family.ti81xx.InterruptDucati', },
        'OMAP4430'      : { del: 'ti.sdo.ipc.family.omap4430.InterruptDucati', },
        'F28M35x'       : { del: 'ti.sdo.ipc.family.f28m35x.InterruptM3', },
    },
    'ti.catalog.arm.cortexa8' : {
        'TMS320TI816X'  : { del: 'ti.sdo.ipc.family.ti81xx.InterruptHost', },
        'OMAP3530'      : { del: 'ti.sdo.ipc.family.omap3530.InterruptHost', },
    },
    'ti.catalog.c6000' : {
        'OMAP3530'      : { del: 'ti.sdo.ipc.family.omap3530.InterruptDsp', },
        'TMS320CDM6446' : { del: 'ti.sdo.ipc.family.dm6446.InterruptDsp', },
        'TMS320DA830'   : { del: 'ti.sdo.ipc.family.da830.InterruptDsp', },
        'OMAPL138'      : { del: 'ti.sdo.ipc.family.da830.InterruptDsp', },
        'TMS320TI816X'  : { del: 'ti.sdo.ipc.family.ti81xx.InterruptDsp', },
        'TMS320C6472'   : { del: 'ti.sdo.ipc.family.c647x.Interrupt', },
        'TMS320C6474'   : { del: 'ti.sdo.ipc.family.c647x.Interrupt', },
        'TMS320C6678'   : { del: 'ti.sdo.ipc.family.c647x.Interrupt', },
        'TMS320C6670'   : { del: 'ti.sdo.ipc.family.c647x.Interrupt', },
        'OMAP4430'      : { del: 'ti.sdo.ipc.family.omap4430.InterruptDsp', },
        'Arctic'        : { del: 'ti.sdo.ipc.family.arctic.InterruptDsp', },
    },
    'ti.catalog.arp32' : {
        'Arctic'       : { del: 'ti.sdo.ipc.family.arctic.InterruptArp32', },
    },
    'ti.catalog.c2800' : {
        'F28M35x'      : { del: 'ti.sdo.ipc.family.f28m35x.InterruptC28', },
    },
};
for (var family in interruptDelegates) {
    setDeviceAliases(interruptDelegates[family], deviceAliases);
}
setCatalogAliases(interruptDelegates, catalogAliases);

/*
 *  ======== spinlockDelegates ========
 */
var spinlockDelegates = {
    'ti.catalog.arm.cortexm3' : {
        'OMAP4430' : {
            baseAddr:   0x4A0F6800,
            numLocks:   32,
        },
        'TMS320TI816X' : {
            baseAddr:   0x480CA800,
            numLocks:   64,
        },
    },
    'ti.catalog.arm.cortexa8' : {
        'TMS320TI816X' : {
            baseAddr:   0x480CA800,
            numLocks:   64,
        },
    },
    'ti.catalog.c6000' : {
        'TMS320TI816X' : {
            baseAddr:   0x080CA800,
            numLocks:   64,
        },
        'OMAP4430' : {
            baseAddr:   0x4A0F6800,
            numLocks:   32,
        },
        'Arctic' : {
            baseAddr:   0x480CA800,
            numLocks:   64,
        },
    },
    'ti.catalog.arp32' : {
        'Arctic' : {
            baseAddr:   0x480CA800,
            numLocks:   64,
        },
    }
}
for (var family in spinlockDelegates) {
    setDeviceAliases(spinlockDelegates[family], deviceAliases);
}
setCatalogAliases(spinlockDelegates, catalogAliases);

/*
 *  ======== hwSemDelegates ========
 */
var hwSemDelegates = {
    'ti.catalog.c6000' : {
        'TMS320C6474' : {
            baseAddr:   0x02B40100,
            queryAddr:  0x02B40300,
            numSems:    32,
        },
        'TMS320C6678' : {
            baseAddr:   0x02640100,
            queryAddr:  0x02640200,
            numSems:    32,
        },
        'TMS320C6670' : {
            baseAddr:   0x02640100,
            queryAddr:  0x02640200,
            numSems:    32,
        },
    },
}
for (var family in hwSemDelegates) {
    setDeviceAliases(hwSemDelegates[family], deviceAliases);
}
setCatalogAliases(hwSemDelegates, catalogAliases);

/*
 *  ======== getGateHWSemSettings ========
 */
function getGateHWSemSettings()
{
    var errorString = "IPC does not have a default GateHWSem" +
                      " delegate for the " + deviceName + " device!";
    var catalogName = Program.cpu.catalogName;
    var deviceName = Program.cpu.deviceName;

    var errStr = "The device " + deviceName +
        " does not support hardware semaphores!";

    try { 
        var hwSemSettings = hwSemDelegates[catalogName][deviceName];
    }
    catch(e) {
        throw new Error(errStr);
    }
    
    if (hwSemSettings == null) {
        throw new Error(errStr);
    }
    
    return (hwSemSettings);
}

/*
 *  ======== getGateHWSpinlockSettings ========
 */
function getGateHWSpinlockSettings()
{
    var errorString = "IPC does not have a default GateHWSpinlock" +
                      " delegate for the " + deviceName + " device!";
    var catalogName = Program.cpu.catalogName;
    var deviceName = Program.cpu.deviceName;
    
    var errStr = "The device " + deviceName +
        " does not support hardware spinlocks!";

    try {
        var spinLockSettings = spinlockDelegates[catalogName][deviceName];
    }
    catch(e) {
        throw new Error(errStr);
    }
    
    if (spinLockSettings == null) {
        throw new Error(errStr);
    }

    return (spinLockSettings);
}

/*
 *  ======== generateSlaveDataForHost ========
 */
function generateSlaveDataForHost()
{
    var retval = hostNeedsSlaveData[Program.cpu.deviceName];
    
    if (retval != null) {
        return (true);
    }

    return (false);
}

/*
 *  ======== getHostProcId ========
 */
function getHostProcId()
{
    var MultiProc = xdc.module("ti.sdo.utils.MultiProc");

    var hostProcName = hostProcNames[Program.cpu.deviceName];
    
    if (hostProcName == null) {
        /* The device doesn't have a core that runs a hlos */
        return (MultiProc.INVALIDID);
    }
    
    /* 
     *  If the device may run a hlos, return the corresponding core's MultiProc
     *  id. MultiProc.INVALIDID will be returned if the core exists but isn't
     *  being used in the application
     */ 
    return(MultiProc.getIdMeta(String(hostProcName)));
}

/*
 *  ======== getIpcSR0Setup ========
 */
function getIpcSR0Setup()
{
    var memorySetup = sr0MemorySetup[Program.cpu.deviceName];
    
    if (memorySetup == null) {
        /* The device has memory available to it */
        return (true);
    }
    else {
        /* The device needs host to enable memory through mmu */
        return (false);
    }
}

/*
 *  ======== getHWGate ========
 */
function getHWGate()
{
    if (Program.cpu.deviceName == "TMS320C6472" ||
        Program.cpu.deviceName == "TMS320CTCI6486") {
        return ('ti.sdo.ipc.gates.GateAAMonitor');
    }

    try {
        this.getGateHWSpinlockSettings();
        return ('ti.sdo.ipc.gates.GateHWSpinlock');
    }
    catch(e) {
    }
    
    try {
        this.getGateHWSemSettings();
        return ('ti.sdo.ipc.gates.GateHWSem');
    }
    catch(e) {
    }

    return('ti.sdo.ipc.gates.GatePeterson');
}

/*
 *  ======== getDefaultInterruptDelegate ========
 */
function getDefaultInterruptDelegate()
{
    var catalogName = Program.cpu.catalogName;
    var deviceName = Program.cpu.deviceName;
 
    var delegate = interruptDelegates[catalogName][deviceName];
    
    if (delegate == null) {
        throw new Error ("IPC does not have a default Interrupt"
            + " delegate for the " + deviceName + " device!");
    }
    
    return (delegate.del);
}

/*
 *  ======== getNameServerRemoteDelegate ========
 */
function getNameServerRemoteDelegate() 
{
    var deviceName = Program.cpu.deviceName;

    var delegate = nameServerRemoteDelegates[deviceName];

    if (delegate == null) {
        delegate = { del: 'ti.sdo.utils.NameServerRemoteNull', };
    }
    
    return (delegate.del);
}

/*
 *  ======== getNotifySetupDelegate ========
 */
function getNotifySetupDelegate() 
{
    var deviceName = Program.cpu.deviceName;
    
    var delegate = notifySetupDelegates[deviceName];
    
    if (delegate == null) {
        throw new Error ("IPC does not have a default NotifySetup"
            + " delegate for the " + deviceName + " device!");
    }
    
    return (delegate.del);
}

/*
 *  ======== getMessageQSetupDelegate ========
 */
function getMessageQSetupDelegate() 
{
    var deviceName = Program.cpu.deviceName;
    
    var delegate = messageQSetupDelegates[deviceName];
    
    if (delegate == null) {
        throw new Error ("IPC does not have a default MessageQ setup"
            + " delegate for the " + deviceName + " device!");
    }
    
    return (delegate.del);
}

/*
 *  ======== procInDevice ========
 */
function procInDevice(procName)
{
    if (procNames[Program.cpu.deviceName] == null) {
        throw("The device (" + Program.cpu.deviceName + 
                       ") isn't supported by IPC");
    }
    
    /* Search through the procNames table */
    for each (name in procNames[Program.cpu.deviceName]) {
        if (name == procName) {
            return (true);
        }
    }
    
    return (false);
}

/*
 *  ======== getDeviceProcNames ========
 */
function getDeviceProcNames()
{
    if (procNames[Program.cpu.deviceName] == null) {
        throw("The device (" + Program.cpu.deviceName + 
                       ") isn't supported by IPC");
    }

    return (procNames[Program.cpu.deviceName]);
}
/*
 *  @(#) ti.sdo.ipc.family; 1, 0, 0, 0,2; 2-11-2012 16:30:31; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

