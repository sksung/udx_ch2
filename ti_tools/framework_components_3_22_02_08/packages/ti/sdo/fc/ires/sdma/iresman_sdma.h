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
/**
 *  @file       ti/sdo/fc/ires/sdma/iresman_sdma.h
 *
 *  @brief      IRESMAN SDMA specific Resource Manager Definitions -
 *              SDMA specific resource manager implementation
 *
 */

/**
 *  @addtogroup ti_sdo_fc_ires_sdma_IRESMAN_SDMA IRESMAN SDMA -
 *              SDMA specific Resource Manager and corresponding
 *              IRES Protocol Implementation
 */

#ifndef ti_sdo_fc_ires_sdma_IRESMAN_SDMA_
#define ti_sdo_fc_ires_sdma_IRESMAN_SDMA_

/** @ingroup ti_sdo_fc_ires_sdma_IRESMAN_SDMA */
/*@{*/

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/sdo/fc/ires/iresman.h>

/**
 * @brief        Initialization arguments for the SDMA specific resource
 *               manager
 */
typedef struct IRESMAN_SdmaParams {

    /**
     * The base configuration information
     */
    IRESMAN_Params baseConfig;

} IRESMAN_SdmaParams;

/**
 *  @brief        Function to return the name of the protocol
 *  @retval       String name identifying the protocol
 */
String IRESMAN_SDMA_getProtocolName();

/**
 *  @brief        Function to return the revision of the protocol
 *  @retval       Revision identifying the protocol
 */
IRES_ProtocolRevision * IRESMAN_SDMA_getProtocolRevision();

/**
 *  @brief        Function to initialize the device specific resource manager
 *                implementation
 *  @param[in]    initArgs           Initialization arguments that may be
 *                                   interpreted by the device specific
 *                                   implementation
 *  @retval       IRES_Status        IRES_OK         Success
 *                                   IRES_EEXISTS    Already initialized
 *                                   IRES_EFAIL      Error
 *
 */
IRES_Status IRESMAN_SDMA_init( IRESMAN_Params * initArgs);

/**
 *  @brief        Function called when RESMAN is no longer needed. Use it to
 *                free memory allocated etc
 *  @retval       IRES_Status        IRES_OK         Success
 *                                   IRES_ENOINIT    Not initialized
 *                                   IRES_EFAIL      Error
 */
IRES_Status IRESMAN_SDMA_exit();

/**
 *  @brief        Function that returns the IRES_Handle to the resource
 *                requested using the IRES_ResourceProtocolArgs.
 *
 *  @param[in]    algHandle          Handle of the algorithm acquiring the
 *                                   resources
 *  @param[in]    resDesc            Arguments to be interpreted by the
 *                                   IRES_Manager implementation to determine
 *                                   which actual physical resources to obtain
 *  @param[in]    scratchGroupId     Group Id required if scratch resources are
 *                                   requested, -1 otherwise
 *  @param[out]   status             Status of this call
 *
 *  @retval       IRES_Handle        Valid handle corresponding to the resource
 *                                   requested on success, or NULL on error.
 */
IRES_Handle IRESMAN_SDMA_getHandles(IALG_Handle algHandle,
        IRES_ResourceDescriptor *resDesc, Int scratchGroupId,
        IRES_Status *status);

/**
 *  @brief        Frees handles back to the resource pool
 *
 *  @param[in]    algHandle          Handle of the algorithm releasing the
 *                                   resources
 *  @param[in]    algResourceHandle  Handle that is to be released
 *  @param[in]    resDesc            Arguments that help determine which
 *                                   resources to free
 *  @param[in]    scratchGroupId     Group Id required if scratch resources are
 *                                   requested, -1 otherwise
 *
 *  @retval       IRES_Status        IRES_OK     Success
 *                                   IRES_EFAIL  Failure
 */
IRES_Status IRESMAN_SDMA_freeHandle(IALG_Handle algHandle,
        IRES_Handle algResourceHandle, IRES_ResourceDescriptor * resDesc,
        Int scratchGroupId);

/**
 *  @brief       Memory allocation functions for all of RMANs
 *               and other IRES protocol's memory requirements
 */
extern __FAR__ IRESMAN_PersistentAllocFxn _RMAN_allocPersistent;

/**
 *  @brief       Memory free functions for all of RMANs
 *               and other IRES protocol's memory requirements
 */
extern __FAR__ IRESMAN_PersistentFreeFxn _RMAN_freePersistent;

/**
 * @brief        IRES RESMAN implementation for SDMA
 */
extern IRESMAN_Fxns IRESMAN_SDMA;


#ifdef __cplusplus
}
#endif /* extern "C" */

/*@}*/ /** @ingroup */

#endif  /* ti_sdo_fc_ires_sdma_IRESMAN_SDMA_ */
/*
 *  @(#) ti.sdo.fc.ires.sdma; 1, 0, 0,3; 4-16-2012 00:01:40; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

