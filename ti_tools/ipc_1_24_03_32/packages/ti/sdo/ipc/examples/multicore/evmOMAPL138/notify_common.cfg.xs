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
 *  The SysStd System provider is a good one to use for debugging 
 *  but does not have the best performance. Use xdc.runtime.SysMin
 *  for better performance.
 */
var System      = xdc.useModule('xdc.runtime.System');
var SysStd      = xdc.useModule('xdc.runtime.SysStd');
System.SupportProxy = SysStd;

/* Modules explicitly used in the application */
var Notify      = xdc.useModule('ti.sdo.ipc.Notify');
var Ipc         = xdc.useModule('ti.sdo.ipc.Ipc');
var BIOS        = xdc.useModule('ti.sysbios.BIOS');
var MultiProc   = xdc.useModule('ti.sdo.utils.MultiProc');

/* Task that does the notify sending */
var Task = xdc.useModule('ti.sysbios.knl.Task');
var tsk0 = Task.create('&tsk0_func');
tsk0.instance.name = "tsk0";

/* Create a semaphore with count 0 */
var Semaphore   = xdc.useModule('ti.sysbios.knl.Semaphore');
Program.global.semHandle = Semaphore.create(0);

/* To avoid wasting shared memory for MessageQ transports */
for (var i=0; i < MultiProc.numProcessors; i++) {
    Ipc.setEntryMeta({
        remoteProcId: i,
        setupMessageQ: false,
    });
}

/* Synchronize all processors (this will be done in Ipc_start) */
Ipc.procSync = Ipc.ProcSync_ALL;

/* 
 * Configure NotifySetup for da830 to use the 2nd interrupt line
 * This is required for the Notify example
 */
var NotifySetup = xdc.useModule('ti.sdo.ipc.family.da830.NotifySetup');

/* This particular example takes advantage of 2 interrupt lines */
NotifySetup.useSecondLine = true;

/* Shared Memory Map */
var SHAREDMEM           = 0xC2000000;
var SHAREDMEMSIZE       = 0x00020000;

/* 
 *  Need to define the shared region. The IPC modules use this
 *  to make portable pointers. All processors need to add this
 *  call with their base address of the shared memory region.
 *  If the processor cannot access the memory, do not add it.
 */ 
var SharedRegion = xdc.useModule('ti.sdo.ipc.SharedRegion');
SharedRegion.setEntryMeta(0,
    { base: SHAREDMEM, 
      len:  SHAREDMEMSIZE,
      ownerProcId: 0,
      isValid: true,
      name: "shared_mem",
    });
/*
 *  @(#) ti.sdo.ipc.examples.multicore.evmOMAPL138; 1, 0, 0, 0,1; 5-22-2012 16:36:17; /db/vtree/library/trees/ipc/ipc-h32/src/ xlibrary

 */

