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
 * 
 */
/*
 *  ======== ThreadSupport.xdc ========
 */

import xdc.runtime.Assert;
import xdc.runtime.Diags;
import xdc.runtime.Error;
import xdc.runtime.Log;
import xdc.runtime.knl.IThreadSupport;

@ModuleStartup          /* need to initialize the pthread_key_t */
@InstanceInitError      /* because initialization can fail */
@InstanceFinalize       /* have to Thread_Proxy_delete(sem) on delete */
module ThreadSupport inherits IThreadSupport
{
    config Error.Id E_priority = {
        msg: "E_priority: Thread priority is invalid %d"
    };

    config Assert.Id A_POSIX_Error = {
        msg: "A_POSIX_Error: a POSIX function returned failure"
    };

    config Error.Id E_POSIX_Error = {
        msg: "E_POSIX_Error: a POSIX function returned failure, errno is %d"
    };

    config Log.Event L_start = {
        mask: Diags.LIFECYCLE,
        msg: "<-- start: (%p)"
    };

    config Log.Event L_finish = {
        mask: Diags.LIFECYCLE,
        msg: "--> finish: (%p)"
    };

    config Log.Event L_join = {
        mask: Diags.LIFECYCLE,
        msg: "--> join: (%p)"
    };

internal:


    const Int PRI_FAILURE = 4;
    const Int SETUP_FAILURE = 3; /*! return code for Instance_init */
    const Int ALLOC_FAILURE = 2; /*! return code for Instance_init */
    const Int POSIX_FAILURE = 1; /*! return code for Instance_init */

    struct Instance_State {
        Ptr tls; /*! store env parameter */
        RunFxn startFxn; /*! store fxn parameter */
        IArg startFxnArg; /*! store arg parameter */
        SizeT stackSize; /*! store stackSize parameter */
        //pthread_t* tid;
        void* tid; /*! pointer to a pthread_t - can't use pthread_t* because we
                       can't see pthread.h */
        Ptr stackBase; /*! pointer to near the top of the stack */
        Int staticOsPri;
    }

    struct Module_State {
         Int lowestPriority;
         Int belowNormalPriority;
         Int normalPriority;
         Int aboveNormalPriority;
         Int highestPriority;
    };
}
/*
 *  @(#) ti.sdo.xdcruntime.linux; 1, 0, 0,1; 2-15-2012 07:45:02; /db/atree/library/trees/osal/osal-e09/src/ xlibrary

 */

