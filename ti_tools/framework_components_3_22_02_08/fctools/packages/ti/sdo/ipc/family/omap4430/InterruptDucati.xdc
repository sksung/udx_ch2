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
 *  ======== InterruptDucati.xdc ========
 *
 */
 
import ti.sdo.utils.MultiProc;

/*!
 *  ======== InterruptDucati ======== 
 *  OMAP4430/Ducati IPC interrupt manager
 */

module InterruptDucati inherits ti.sdo.ipc.notifyDrivers.IInterrupt
{
    /* Base address for the Mailbox subsystem */
    config UInt32 mailboxBaseAddr = 0x4A0F4000;

    /* Base address for the Ducati CTRL register */
    config UInt32 ducatiCtrlBaseAddr = 0x40001000;
    
internal: 

    /* Function table */
    struct FxnTable {
        Fxn    func;
        UArg   arg;
    }

    /*! Stub to plug the inter-Ducati hwi */
    Void intShmDucatiStub(UArg arg);
    
    /*! Stub to plug the Mailbox hwi */
    Void intShmMbxStub(UArg arg);
    
    struct Module_State {        
        FxnTable   fxnTable[3];
        UInt       numPlugged;
    };
    
    /*! Statically retrieve procIds to avoid doing this at runtime */    
    config UInt dspProcId   = MultiProc.INVALIDID;
    config UInt hostProcId  = MultiProc.INVALIDID;
    config UInt core0ProcId = MultiProc.INVALIDID;
    config UInt core1ProcId = MultiProc.INVALIDID;
} 
        
/*
 *  @(#) ti.sdo.ipc.family.omap4430; 1, 0, 0, 0,2; 2-11-2012 16:31:01; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

