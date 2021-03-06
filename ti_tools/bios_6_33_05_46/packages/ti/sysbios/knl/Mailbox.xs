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
 *  ======== Mailbox.xs ========
 *
 */

var Queue = null;
var Semaphore = null;
var Mailbox = null;
var Memory = null;
var HeapBuf = null;

/*
 *  ======== module$use ========
 */
function module$use()
{
    Mailbox = this;
    Queue = xdc.useModule("ti.sysbios.knl.Queue");
    Semaphore = xdc.useModule("ti.sysbios.knl.Semaphore");

    /* 
     * Pulling in Event should be conditioned on Semaphore.supportsEvents
     * but this causes linker issues. 
     */
    Event = xdc.useModule("ti.sysbios.knl.Event");
    Memory = xdc.useModule("xdc.runtime.Memory");
    xdc.useModule("xdc.runtime.Assert");
}

/*
 *  ======== instance$static$init ========
 */
function instance$static$init(obj, msgSize, numMsgs, params)
{
    if (msgSize == 0) {
        Mailbox.$logFatal("Message size (msgSize) must be non-zero.", this);
    }
    if (numMsgs == 0) {
        Mailbox.$logFatal("Number of messages (numMsgs) must be non-zero.",
            this);
    }

    obj.heap = null;
    obj.msgSize = msgSize;
    obj.numMsgs = numMsgs;
    obj.buf = params.buf;
    obj.numFreeMsgs = numMsgs;

    Queue.construct(obj.dataQue);
    Queue.construct(obj.freeQue);
    
    if (obj.buf == null) {
        var Memory = xdc.module('xdc.runtime.Memory');
        var align = Memory.getMaxDefaultTypeAlignMeta();
        var blockSize = (msgSize + Mailbox.MbxElem.$sizeof() + 
                        (align - 1)) & ~(align - 1);
        
        obj.allocBuf.length = blockSize * numMsgs;
        
        /*  
         *  The following will place a memory buffer into section name.
         *  This buffer is the memory that this instance will manage. 
         */
        Memory.staticPlace(obj.allocBuf, align, params.sectionName);
    }
    else {
        obj.allocBuf.length = 0;
    }
    
    if (params.readerEvent != null) {
        if (params.readerEventId == 0) {
            Mailbox.$logFatal("readerEventId must not be zero.", this,
                "readerEvent");
        }
    }      
    if (params.writerEvent != null) {
        if (params.writerEventId == 0) {
            Mailbox.$logFatal("writerEventId must not be zero.", this,
                "writerEvent");
        }
    }
    
    var semParams = new Semaphore.Params();
    semParams.event = params.readerEvent;
    semParams.eventId = params.readerEventId;

    Semaphore.construct(obj.dataSem, 0, semParams);
    
    semParams.event = params.writerEvent;
    semParams.eventId = params.writerEventId;
    Semaphore.construct(obj.freeSem, numMsgs, semParams);
}

/*
 *  ======== viewInitBasic ========
 *  Initialize the 'Basic' Mailbox instance view.
 */
function viewInitBasic(view, obj)
{
    view.label = Program.getShortName(obj.$label);

    view.msgSize    = obj.msgSize;
    view.numMsgs    = obj.numMsgs;
}

/*
 *  ======== viewInitDetailed ========
 *  Initialize the 'Detailed' Mailbox instance view.
 */
function viewInitDetailed(view, obj)
{

    /* first get the Basic view: */
    viewInitBasic(view, obj);

    try {
        var dataQView = Program.scanObjectView('ti.sysbios.knl.Queue',
                obj.dataQue, 'Basic');
    }
    catch (e) {
        view.$status["curNumMsgs"] = "Error: Problem scanning Mailbox messages: " 
            + e.toString();
        return;
    }

    /* scan the Semaphore instance dataSem so this instance will appear */
    try {
        var dataSemView = Program.scanObjectView('ti.sysbios.knl.Semaphore',
                obj.dataSem, 'Basic');
    }
    catch (e) {
        view.$status["pendQueue"] = "Error: Problem scanning Mailbox_pend Q: "
            + e.toString();
        return;
    }

    /* scan the Semaphore instance freeSem so this instance will appear */
    try {
        var freeSemView = Program.scanObjectView('ti.sysbios.knl.Semaphore',
                obj.freeSem, 'Basic');
    }
    catch (e) {
        view.$status["postQueue"] = "Error: Problem scanning Mailbox_post Q: "
            + e.toString();
        return;
    }

    /* the number of free slots is just the number of free msgs. */
    view.freeSlots = obj.numFreeMsgs;

    view.curNumMsgs = dataQView.elems.length;

    view.pendQueue  = dataSemView.pendedTasks;
    view.postQueue = freeSemView.pendedTasks;
}
/*
 *  @(#) ti.sysbios.knl; 2, 0, 0, 0,552; 5-18-2012 06:05:53; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

