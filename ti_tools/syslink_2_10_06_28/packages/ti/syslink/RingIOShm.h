/** 
 *  @file   RingIOShm.h
 *
 *  @brief      RingIOShm shared memory based physical transport for
 *              communication with the remote processor.
 *
 *              This file contains the declarations of types and APIs as part
 *              of interface of the RingIOShm shared memory transport.
 *
 *
 */
/* 
 *  ============================================================================
 *
 *  Copyright (c) 2008-2012, Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information: 
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 *  
 */



#ifndef RINGIOSHM_H_
#define RINGIOSHM_H_

#include <ti/ipc/GateMP.h>
#include <ti/syslink/RingIO.h>

#if defined (__cplusplus)
extern "C" {
#endif
/* =============================================================================
 *  All success and failure codes for the module
 * =============================================================================
 */

/*!
 *  @def    RingIOShm_MODULEID
 *  @brief  Unique module ID.
 */
#define RingIOShm_MODULEID               (0x3bff)

/* =============================================================================
 *  All success and failure codes for the module
 * =============================================================================
 */

/*!
 *  @def    RingIOShm_E_INVALIDARG
 *  @brief  Argument passed to a function is invalid.
 */
#define RingIOShm_E_INVALIDARG   RingIO_E_INVALIDARG 

/*!
 *  @def    RingIOShm_E_INVALIDSTATE
 *  @brief  Module is not initialized.
 */
#define RingIOShm_E_INVALIDSTATE RingIO_E_INVALIDSTATE

/*!
 *  @def    RingIOShm_E_BADVERSION
 *  @brief  Versions don't match
 */
#define RingIOShm_E_BADVERSION   RingIO_E_BADVERSION

/*!
 *  @def    RingIOShm_E_FAIL
 *  @brief  General Failure
*/
#define RingIOShm_E_FAIL         RingIO_E_FAIL

/*!
 *  @def    RingIOShm_E_MEMORY
 *  @brief  Memory allocation failed
 */
#define RingIOShm_E_MEMORY       RingIO_E_MEMORY

/*!
 *  @def    RingIOShm_E_OSFAILURE
 *  @brief  Failure in OS call.
 */
#define RingIOShm_E_OSFAILURE    RingIO_E_OSFAILURE

/*!
 *  @def    RingIOShm_E_BUFWRAP
 *  @brief  Indicates that the amount of data requested could not be serviced
 *          due to the ring buffer getting wrapped
 */
#define RingIOShm_E_BUFWRAP      RingIO_E_BUFWRAP

/*!
 *  @def    RingIOShm_E_BUFEMPTY
 *  @brief  Indicates that there is no data in the buffer for reading
 */
#define RingIOShm_E_BUFEMPTY     RingIO_E_BUFEMPTY

/*!
 *  @def    RingIOShm_E_BUFFULL
 *  @brief  Indicates that the buffer is full
 */
#define RingIOShm_E_BUFFULL      RingIO_E_BUFFULL

/*!
 *  @def    RingIOShm_E_PENDINGDATA
 *  @brief  Indicates that there is no attribute at the current,
 *          but attributes are present at a future offset
 */
#define RingIOShm_E_PENDINGDATA  RingIO_E_PENDINGDATA

/*!
 *  @def    RingIOShm_E_VARIABLEATTRIBUTE
 *  @brief  Indicates that attibute get() failed, need to extract
 *          variable length message getv()
 */
#define RingIOShm_E_VARIABLEATTRIBUTE   RingIO_E_VARIABLEATTRIBUTE

/*!
 *  @def    RingIOShm_E_WRONGSTATE
 *  @brief  Indicates that the RingIO is in a wrong state
 */
#define RingIOShm_E_WRONGSTATE          RingIO_E_WRONGSTATE

/*!
 *  @def    RingIOShm_E_INVALIDPROCID
 *  @brief  Indicates that an invalid proc id has been specified
 */
#define RingIOShm_E_INVALIDPROCID    RingIO_E_INVALIDPROCID
/*!
 *  @def    RingIOShm_E_INVALIDCONTEXT
 *  @brief  Indicates that the api is called with wrong handle
 */
#define RingIOShm_E_INVALIDCONTEXT   RingIO_E_INVALIDCONTEXT

/*!
 *  @def    RingIOShm_S_SUCCESS
 *  @brief  Operation successful.
 */
#define RingIOShm_S_SUCCESS        RingIO_S_SUCCESS

/*!
 *  @def    RingIOShm_S_ALREADYSETUP
 *  @brief  The module has been already setup
 */
#define RingIOShm_S_ALREADYSETUP RingIO_S_ALREADYSETUP

/*!
 *  @def    RingIOShm_S_PENDINGATTRIBUTE
 *  @brief  Indicates that either:
 *                        1) The amount of data requested could not be
 *                           serviced due to the presence of an attribute
 *                        2) During an attribute read if another is also present
 *                           at the same offset.
 */
#define RingIOShm_S_PENDINGATTRIBUTE    RingIO_S_PENDINGATTRIBUTE


/* =============================================================================
 * Structures & Enums
 * =============================================================================
 */
/*!
 *  @brief  Structure defining parameters for creating the RingIOShm
 *          instances.
 */
typedef struct RingIOShm_Params_Tag {
     RingIO_Params commonParams;
     /*!< Common create parameters .Same for all the implementations of FrameQ*/
     UInt16     ctrlRegionId;
     /*!< Shared region ID for RingIOShm control structures
      *
      *  The index corresponding to the shared region from which shared memory
      *  will be allocated if ctrlSharedAddr is NULL.
      *  If a valid ctrlSharedAddr is provided, this field is ignored.
      *  Currently only id 0 is supported.
      */
     UInt16     dataRegionId;
     /*!< Shared region ID for RingIOShm data buffer
      *
      *  The index corresponding to the shared region from which shared memory
      *  will be allocated if dataSharedAddr is NULL.
      *  If a valid dataSharedAddr is provided, this field is ignored.
      *  Currently only id 0 is supported.
      */
     UInt16     attrRegionId;
     /*!< Shared region ID for RingIOShm attr buffer
      *
      *  The index corresponding to the shared region from which shared memory
      *  will be allocated if attrSharedAddr is NULL.
      *  If a valid attrSharedAddr is provided, this field is ignored.
      *  Currently only id 0 is supported.
      */
     Ptr         ctrlSharedAddr;
     /*!<  Shared region address for control structure. The shared address
      *    details for control, data and attribute buffers.
      *    a RingIOShm instance.
      *    If this field is NULL, memory equal to that required to allocate that
      *    RingIOShm instance control structure is allocated from heap associated
      *    with ctrlRegionId
      */
     Ptr         dataSharedAddr;
     /*!<  Shared Region Address for data buffer
      *    If this field is NULL, memory equal to (dataSharedAddrSize +
      *    footBufSize)
      *    is allocated from heap associated with dataRegionId
      */
     UInt32      dataSharedAddrSize;
     /*!<  Data Buffer size.  */
     UInt32      footBufSize;
     /*!<  Foot Buffer size.  */
     Ptr         attrSharedAddr;
     /*!<  Shared Region Address for attr buffer
      *    If this field is NULL, memory equal to attrSharedAddrSize
      *    is allocated from heap associated with attrRegionId
      */
     UInt32      attrSharedAddrSize;
     /*!<  Attr Buffer size.  */
     GateMP_Handle gateHandle;
     /*!< Gate for protection.
      *   If gateHandle is NULL:
      *       * If user has called RingIOShm_useModuleDefault
      *         then module wide default GateMP is used.
      *       * If RingIOShm_useModuleDefault is not set
      *         default gate will be used for all instances
      *       * else, If variables GateMP_LocalProtect localProtect and
      *         GateMP_RemoteProtect remoteProtect are set to correct
      *         values, a GateMP is created for the instance.
      */
     GateMP_LocalProtect  localProtect;
     /*!< Local protection level for the module instance.*/
     GateMP_RemoteProtect remoteProtect;
     /*!< Remote protection level for the module instance.*/
     UInt16        remoteProcId;
     /*!< Remote processor id with which the RingIOShm communicates */
} RingIOShm_Params;

#ifndef SYSLINK_BUILDOS_QNX
/*!
 *  @brief  Structure defining config parameters for the RingIOShm module.
 */
typedef struct RingIOShm_Config_Tag {
    UInt32       notifyEventNo;
    /*!<  Notify event number to be used by the Client Notify Manager */
} RingIOShm_Config;
#endif

/* =============================================================================
 * APIs
 * =============================================================================
 */
/*!
 *  @brief      Function to initialize the parameters for the RingIOShm instance.
 *
 *              This function can be called by the application to get their
 *              configuration parameter to RingIOShm_create filled in by the
 *              RingIOShm module with the default parameters.
 *
 *  @param      params   Pointer to the RingIOShm instance params structure in
 *                       which the default params is to be returned.
 *
 *  @retval     None
 *
 *  @sa         RingIOShm_create
 */
Void RingIOShm_Params_init (Void * params);

#ifndef SYSLINK_BUILDOS_QNX
/*!
 *  @brief      Function to get the default configuration for the RingIOShm
 *              module.
 *
 *              This function can be called by the application to get their
 *              configuration parameter to RingIOShm_setup filled in by the
 *              RingIOShm module with the default parameters. If the user does
 *              not wish to make any change in the default parameters, this API
 *              is not required to be called.
 *
 *  @param      cfgParams Pointer to the RingIOShm module configuration structure
 *                        in which the default config is to be returned.
 *
 *  @sa         RingIOShm_setup
 */
Void  RingIOShm_getConfig (RingIOShm_Config * cfgParams);

/*!
 *  @brief      Function to setup the RingIOShm module.
 *
 *              This function sets up the RingIOShm module. This function must
 *              be called before any other instance-level APIs can be invoked.
 *              Module-level configuration needs to be provided to this
 *              function. If the user wishes to change some specific config
 *              parameters, then RingIOShm_getConfig can be called to get the
 *              configuration filled with the default values. After this, only
 *              the required configuration values can be changed. If the user
 *              does not wish to make any change in the default parameters, the
 *              application can simply call RingIOShm with NULL parameters.
 *              The default parameters would get automatically used.
 *
 *  @param      cfgParams   Optional RingIOShm module configuration. If provided as
 *                    NULL, default configuration is used.
 *
 *  @sa         RingIOShm_destroy
 *              NameServer_create
 *              GateMutex_create
 *              Memory_alloc
 */
Int   RingIOShm_setup (const RingIOShm_Config * cfgParams);

/*!
 *  @brief      Function to destroy the RingIOShm module.
 *
 *              Once this function is called, other RingIOShm module APIs, except
 *              for the RingIOShm_getConfig API cannot be called anymore.
 *
 *  @sa         RingIOShm_setup, NameServer_delete, GateMutex_delete
 */
Int   RingIOShm_destroy (Void);
#endif


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* RINGIOSHM_H_ */
