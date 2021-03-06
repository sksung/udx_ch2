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

/* Task that does the notification sending/receiving */
var Task       = xdc.useModule('ti.sysbios.knl.Task');
var tsk0 = Task.create('&tsk0_func');
tsk0.instance.name = "tsk0";

var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');

/*
 *  Get the list of names that the build device supports.
 */
var nameList = MultiProc.getDeviceProcNames();
MultiProc.setConfig(Program.global.coreName, nameList);


var MessageQ                = xdc.useModule('ti.sdo.ipc.MessageQ');  
var Ipc                     = xdc.useModule('ti.sdo.ipc.Ipc');
var HeapBufMP               = xdc.useModule('ti.sdo.ipc.heaps.HeapBufMP');
var BIOS                    = xdc.useModule('ti.sysbios.BIOS');
BIOS.heapSize = 0x8000;

/* Synchronize all processors (this will be done in Ipc_start) */
Ipc.procSync = Ipc.ProcSync_ALL;

/* Configuration required because HOST is not being used */
Ipc.sr0MemorySetup = true;
/*
 *  @(#) ti.sdo.ipc.examples.multicore.evmC6A8149; 1, 0, 0, 0,1; 5-22-2012 16:36:06; /db/vtree/library/trees/ipc/ipc-h32/src/ xlibrary

 */

