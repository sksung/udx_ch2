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
 *  ======== Transformer.xs ========
 */
 
var DriverTypes = null;
var Stream = null;

/* 
 * ======== module$use ========
 */
function module$use()
{
    DriverTypes = xdc.useModule('ti.sdo.io.DriverTypes');
    Stream = xdc.useModule('ti.sdo.io.Stream');
}

/* 
 * ======== instance$static$init ========
 */
function instance$static$init(obj, params)
{
    obj.mode = 0;
    obj.cbFxn = null;
    obj.cbArg = null;
    obj.fxn = params.fxn;
    obj.arg = params.arg;
    obj.drvAdapHdl = false;
    obj.convHandle = null;
}


/*
 *  ======== viewInitBasic ========
 *  Initialize the 'Basic' DriverAdapter instance view.
 */
function viewInitBasic(view, obj)
{    
    var Transformer = xdc.useModule('ti.sdo.io.converters.Transformer');
    var Program = xdc.useModule('xdc.rov.Program');
    var DriverTypes = xdc.useModule('ti.sdo.io.DriverTypes');
    
    view.label = Program.getShortName(obj.$label);
    
    view.lowerConverter = obj.convHandle;
    
    if (obj.mode == DriverTypes.INPUT) {
        view.mode = "INPUT";
    }
    else {
        view.mode = "OUTPUT";
    }

    print("got here");
    view.callbackFxn = Program.lookupAddr(Number(obj.cbFxn));
    //view.callbackArg = "0x" + obj.cbArg.toString(16);
    view.callbackArg =  obj.cbArg;
    
    view.transformFxn = Program.lookupAddr(Number(obj.fxn));
    //view.transformArg = "0x" + obj.arg.toString(16);   
    view.transformArg = obj.arg;
    print("got here too");
}

/*
 *  @(#) ti.sdo.io.converters; 1, 0, 0, 0,2; 2-11-2012 16:30:22; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

