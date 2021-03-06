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
/** ===========================================================================
 *  @file       Ipc.h
 *
 *  @brief      Ipc Manager.
 *
 *  This module is primarily used to configure IPC, synchronize processors, and
 *  initialize the IPC runtime.  The memory for SharedRegion zero must be valid 
 *  before Ipc_start() can be called.  Ipc_start() must be called before any
 *  other IPC APIs are used.
 *
 *  The Ipc header should be included in an application as follows:
 *  @code
 *  #include <ti/ipc/Ipc.h>
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_ipc_Ipc__include
#define ti_ipc_Ipc__include

#if defined (__cplusplus)
extern "C" {
#endif

/* =============================================================================
 *  All success and failure codes for the module
 * =============================================================================
 */

/*!
 *  @def    Ipc_S_BUSY
 *  @brief  The resource is still in use
 */
#define Ipc_S_BUSY              2

/*!
 *  @def    Ipc_S_ALREADYSETUP
 *  @brief  The module has been already setup
 */
#define Ipc_S_ALREADYSETUP      1

/*!
 *  @def    Ipc_S_SUCCESS
 *  @brief  Operation is successful.
 */
#define Ipc_S_SUCCESS           0

/*!
 *  @def    Ipc_E_FAIL
 *  @brief  Generic failure.
 */
#define Ipc_E_FAIL             -1

/*!
 *  @def    Ipc_E_INVALIDARG
 *  @brief  Argument passed to function is invalid.
 */
#define Ipc_E_INVALIDARG       -2

/*!
 *  @def    Ipc_E_MEMORY
 *  @brief  Operation resulted in memory failure.
 */
#define Ipc_E_MEMORY           -3

/*!
 *  @def    Ipc_E_ALREADYEXISTS
 *  @brief  The specified entity already exists.
 */
#define Ipc_E_ALREADYEXISTS    -4

/*!
 *  @def    Ipc_E_NOTFOUND
 *  @brief  Unable to find the specified entity.
 */
#define Ipc_E_NOTFOUND         -5

/*!
 *  @def    Ipc_E_TIMEOUT
 *  @brief  Operation timed out.
 */
#define Ipc_E_TIMEOUT          -6 

/*!
 *  @def    Ipc_E_INVALIDSTATE
 *  @brief  Module is not initialized or in an invalid state.
 */
#define Ipc_E_INVALIDSTATE     -7

/*!
 *  @def    Ipc_E_OSFAILURE
 *  @brief  A failure occurred in an OS-specific call
 */
#define Ipc_E_OSFAILURE        -8

/*!
 *  @def    Ipc_E_RESOURCE
 *  @brief  Specified resource is not available
 */
#define Ipc_E_RESOURCE         -9

/*!
 *  @def    Ipc_E_RESTART
 *  @brief  Operation was interrupted. Please restart the operation
 */
#define Ipc_E_RESTART          -10

/*!
 *  @def    Ipc_E_NOTREADY
 *  @brief  Operation was not ready.
 */
#define Ipc_E_NOTREADY         -11


/* =============================================================================
 *  Ipc Module-wide Functions
 * =============================================================================
 */

/*!
 *  @brief      Attach to remote processor
 *
 *  This function uses shared memory to synchronize self with the remote
 *  processor.  Both processors must call this function to attach to each
 *  other.  Ipc_start() must be called before calling Ipc_attach().
 *  A processor must attach to the owner of SharedRegion zero before
 *  it can successfully attach to another processor.  Attempting to
 *  attach to another processor first returns #Ipc_E_FAIL.
 *
 *  This function opens the default GateMP and SharedRegion zero heap.
 *  The Notify, NameServerRemoteNotify, and MessageQ transport
 *  instances are created for communicating with the specified remote
 *  processor in SharedRegion zero heap.  The user's Ipc attach function
 *  is called.
 *
 *  For BIOS, this function should be called within a 'while' loop
 *  within a Task.  A Task_sleep() or Task_yield() should be called
 *  within the loop to allow other threads in the system to execute. 
 *  This function needs to be called in a loop because the remote
 *  processor may not be in a ready state.
 *
 *  Note:  For BIOS, if the config parameter Ipc.procSync is set to
 *  Ipc.ProcSync_ALL, there is no need to call this function as it is
 *  internally called by Ipc_start().
 *
 *  @code
 *  while (Ipc_attach(remoteProcId) < 0) {
 *      Task_sleep(1);
 *  }
 *  @endcode
 *
 *  @param      remoteProcId  remote processor's MultiProc id
 *
 *  @return     Status
 *              - #Ipc_S_SUCCESS: attach was successful
 *              - #Ipc_S_ALREADYSETUP: already attached
 *              - #Ipc_E_MEMORY: operation failed due to a memory error
 *              - #Ipc_E_FAIL: General failure
 *              - #Ipc_E_NOTREADY: remote processor not ready
 *
 *  @sa         Ipc_detach Ipc_isAttached
 */
Int Ipc_attach(UInt16 remoteProcId);

/*!
 *  @brief      Detach from the remote processor
 *
 *  A processor must detach from all other processors before it can
 *  successfully detach from the owner of SharedRegion zero.  Attempting to
 *  detach from the owner of SharedRegion zero first returns #Ipc_E_FAIL.
 *
 *  If a processor successfully attached to a remote processor 'N' times,
 *  it must call Ipc_detach 'N' times to be completely detached.  
 *  Ipc_detach returns #Ipc_S_BUSY for the first 'N - 1' times its called.  
 *  Ipc_detach returns #Ipc_S_SUCCESS, if successful, on the 'N' time its 
 *  called.  If called on a remote processor that is detached, #Ipc_S_SUCCESS
 *  is returned.
 *
 *  This function should be called within a loop to make sure the processor
 *  successfully detached from the remote processor.
 *  If called from the processor with the bigger procId, this function closes
 *  the instances created for communicating with the specified remote processor.  
 *  If called from the processor with the smaller procId, this function returns
 *  Ipc_E_NOTREADY while the processor with the bigger procId has not finished
 *  detaching.  Once the processor with the bigger procId is finished detaching,
 *  this function deletes the instances created for communicating with the
 *  specified remote processor.  
 *
 *  For BIOS, this function should be called within a 'while' loop in a Task
 *  because the slave may have to wait for the master to detach.  Furthermore,
 *  a Task_sleep() or Task_yield() should be called within the same 'while'
 *  loop to allow other threads in the system to execute.
 *
 *  @code
 *  while (TRUE) {
 *      status = Ipc_detach(remoteProcId);
 *      if (status == Ipc_E_NOTREADY) {
 *          Task_sleep(1);
 *      }
 *      else if (status < 0) {
 *          System_printf("Ipc_detach failed \n");
 *          break;
 *      }
 *      else {
 *          break;
 *      }
 *  }
 *  @endcode
 *
 *  @param      remoteProcId  remote processor's MultiProc id
 *
 *  @return     Status
 *              - #Ipc_S_SUCCESS: operation was successful
 *              - #Ipc_S_BUSY: attach count != 0
 *              - #Ipc_E_FAIL: operation failed
 *              - #Ipc_E_NOTREADY: processor not ready to detach
 *
 *  @sa         Ipc_attach Ipc_isAttached
 */
Int Ipc_detach(UInt16 remoteProcId);

/*!
 *  @brief      Query whether attached to a remote processor
 *
 *  Returns TRUE if attached to a remote processor and FALSE otherwise.  If 
 *  remoteProcId == MultiProc_self(), FALSE is always returned. 
 *
 *  @param      remoteProcId  remote processor's MultiProc id
 *
 *  @return     TRUE if attached, FALSE if not attached
 *
 *  @sa         Ipc_attach Ipc_detach
 */
Bool Ipc_isAttached(UInt16 remoteProcId);

/*!
 *  @brief      Reads the config entry from the config area.
 *
 *  For more information about this API, refer to the documentation for 
 *  #Ipc_writeConfig
 *
 *  @param      remoteProcId  remote processor's MultiProc id
 *  @param      tag           tag to identify a config entry
 *  @param      cfg           address where the entry will be copied
 *  @param      size          size of config entry
 *
 *  @return     Status
 *              - #Ipc_S_SUCCESS: operation was successful
 *              - #Ipc_E_FAIL: operation failed
 *
 *  @sa         Ipc_writeConfig
 */
Int Ipc_readConfig(UInt16 remoteProcId, UInt32 tag, Ptr cfg, SizeT size);

/*!
 *  @brief      Reserves memory, creates default GateMP and HeapMemMP
 *
 *  This function needs to be called before Ipc_attach().  It should
 *  only be called once, unless the return value is #Ipc_E_NOTREADY.
 *  This indicates that either the SharedRegion zero is not valid or
 *  has not been setup yet so Ipc_start may be called again. Once
 *  sucessfully started, subsequent calls returns #Ipc_S_ALREADYSETUP.
 *
 *  Ipc reserves some shared memory in SharedRegion zero for synchronization.
 *  GateMP reserves some shared memory for managing the gates and for the
 *  default GateMP.  The same amount of memory must be reserved by each
 *  processor, but only the owner of SharedRegion zero clears the reserved 
 *  memory and creates the default GateMP. The default heap for each
 *  SharedRegion is created by the owner of each SharedRegion.
 *
 *  Note:  For BIOS, if the config parameter Ipc.procSync is set to
 *  Ipc.ProcSync_ALL, this function calls Ipc_attach() internally.
 *
 *  @return     Status
 *              - #Ipc_S_SUCCESS: operation was successful
 *              - #Ipc_S_ALREADYSETUP: already successfully called
 *              - #Ipc_E_NOTREADY: shared memory is not ready
 *              - #Ipc_E_FAIL: operation failed
 */
Int Ipc_start(Void);

/*!
 *  @brief      Resets the Ipc state
 *
 *  This function should be called only once and only after detaching
 *  from all processors.  Once called, Ipc is placed back to
 *  the same state as it was before Ipc_start() was called.
 *
 *  @return     Status
 *              - #Ipc_S_SUCCESS: operation was successful
 */
Int Ipc_stop(Void);

/*!
 *  @brief      Writes the config entry to the config area.
 *
 *  The #Ipc_writeConfig and #Ipc_readConfig APIs are used to pass configuration
 *  information from one core to another.  This 'information' is passed via 
 *  a pointer to shared memory with a given size and is identified via a unique
 *  tag.  A typical use case of this API would be passing 
 *  configuration information from a Slave core to the Host at startup-time. 
 *  For example, if MessageQ is used, this information 
 *  might include the queue name, message heap sizes, etc.
 *
 *  The APIs will write into SharedRegion 0 (SR0) and will use the tag 
 *  to uniquely identify the structure (cfg) and size written into SR0 which 
 *  both sides must agree on.
 *
 *  @param      remoteProcId  remote processor's MultiProc id
 *  @param      tag           tag to identify a config entry
 *  @param      cfg           address where the entry will be copied
 *  @param      size          size of config entry
 *
 *  @return     Status
 *              - #Ipc_S_SUCCESS: if operation was successful
 *              - #Ipc_E_FAIL: if operation failed
 *
 *  @sa         Ipc_readConfig
 */
Int Ipc_writeConfig(UInt16 remoteProcId, UInt32 tag, Ptr cfg, SizeT size);

#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* ti_ipc_Ipc__include */

/*
 */

/*
 *  @(#) ti.ipc; 1, 0, 0, 0,2; 2-11-2012 16:30:15; /db/vtree/library/trees/ipc/ipc-h27/src/ xlibrary

 */

