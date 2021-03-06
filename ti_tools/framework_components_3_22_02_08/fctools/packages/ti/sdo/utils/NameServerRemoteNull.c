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
 *  ======== NameServerRemoteNull.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/knl/ISync.h>

#include <ti/ipc/NameServer.h>

#include "package/internal/NameServerRemoteNull.xdc.h"


/*
 *************************************************************************
 *                       Instance functions
 *************************************************************************
 */
Void NameServerRemoteNull_Instance_init(NameServerRemoteNull_Object *obj,
        UInt16 remoteProcId,
        const NameServerRemoteNull_Params *params)
{
}

/*
 *************************************************************************
 *                       Module functions
 *************************************************************************
 */

 /*
 *  ======== NameServerRemoteNull_attach ========
 */
Int NameServerRemoteNull_attach(UInt16 remoteProcId, Ptr sharedAddr)
{
    return (NameServer_E_FAIL);
}

/*
 *  ======== NameServerRemoteNull_detach ========
 */
Int NameServerRemoteNull_detach(UInt16 remoteProcId)
{
    return (NameServer_E_FAIL);
}

/*
 *  ======== NameServerRemoteNull_get ========
 */
Int NameServerRemoteNull_get(NameServerRemoteNull_Object *obj,
                        String instanceName,
                        String name,
                        Ptr value,
                        UInt32 *valueLen,
                        ISync_Handle syncHandle,
                        Error_Block *eb)
{
    return (NameServer_E_FAIL);
}

/*
 *  ======== NameServerRemoteNull_sharedMemReq ========
 */
SizeT NameServerRemoteNull_sharedMemReq(Ptr sharedAddr)
{
    return (0);
}
/*
 *  @(#) ti.sdo.utils; 1, 0, 0, 0,2; 2-11-2012 16:31:30; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

