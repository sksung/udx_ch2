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
 *  @file       ti/sdo/fc/rman/examples/vicp/ires_algorithm.c
 *
 *  @brief      Dummy implementation of the IRES interfaces by an algorithm
 *
 */

#include <xdc/std.h>
#include <string.h>
#include <stdio.h>

#include "ires_algorithm.h"

/*
 * ===== IRES_ALGORITHM_numResourceDescriptors =====
 *
 * Returns number of different resource types the algorithm needs.
 * Part of IRES interface 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int32 IRES_ALGORITHM_numResourceDescriptors(IALG_Handle handle) 
{
    return (NUM_RESOURCES);
}


/*
 * ===== IRES_ALGORITHM_activateResource =====
 *
 * Call to activate particular resource, identified by resourceHandle
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_activateResource(IALG_Handle handle,
        IRES_Handle resourceHandle)
{
    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;
    Int i = 0;

    for (i = 0; i < NUM_RESOURCES; i++) {
        if ((IRES_Handle)algHandle->resourceHandles[i] == resourceHandle) {
            if (algHandle->resourceState[0] == 0) {
                algHandle->resourceState[0] = 1;
                return (IRES_OK);
            }
            else {
                return (IRES_EINIT);
            }

        }
    }
    return (IRES_OK);
}


/*
 * ===== IRES_ALGORITHM_activateAllResources =====
 *
 * Call to activate all resources
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_activateAllResources(IALG_Handle handle)
{
    Int i = 0;
    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        if (algHandle->resourceState[i] == 0) {
            algHandle->resourceState[i] = 1;
        }
        else {
            return (IRES_EINIT);
        }
    }
    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_deactivateResource =====
 *
 * Call to deactivate a resource, identified by resourceHandle
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_deactivateResource(IALG_Handle handle,
        IRES_Handle resourceHandle)
{

    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;
    Int i = 0;

    for (i = 0; i < NUM_RESOURCES; i++) {
        if ((IRES_Handle)algHandle->resourceHandles[i] == resourceHandle) {
            if (algHandle->resourceState[0] == 1) {
                algHandle->resourceState[0] = 0;
                return (IRES_OK);
            }
            else {
                return (IRES_ENORESOURCE);
            }
        }
    }
    return (IRES_OK);
}


/*
 * ===== IRES_ALGORITHM_deactivateAllResources =====
 *
 * Call to deactivate all resources
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_deactivateAllResources(IALG_Handle handle)
{
    Int i = 0;

    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;
    for (i = 0; i < NUM_RESOURCES; i++) {
        if (algHandle->resourceState[i] == 1) {
            algHandle->resourceState[i] = 0;
        }
        else {
            return (IRES_ENORESOURCE);
        }
    }
    return (IRES_OK);
}


/*
 * ===== IRES_ALGORITHM_initResources =====
 *
 * Call to grant algorithm the resources it requested
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_initResources(IALG_Handle handle,
    IRES_ResourceDescriptor * resourceDescriptor, IRES_YieldFxn  yieldFxn,
    IRES_YieldArgs yieldArgs)
{
    Int i = 0;

    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;
    printf("Assigned Resources\n");
    /* Store information about resources received in the alg handle */
    for (i = 0; i < NUM_RESOURCES; i++) {
        algHandle->resourceState[i] = 0;
        algHandle->resourceHandles[i] =
            (IRES_VICP_Handle)resourceDescriptor[i].handle;
        if (0 == algHandle->resourceHandles[i]->ires.persistent) {
            printf("Scratch \n");
        }
        else {
            printf("Persistent \n");
        }

        printf("Resource Handle %d: IMX %d, VLCD %d, SEQ %d\n", i, 
                ((IRES_VICP_Handle)(algHandle->resourceHandles[i]))->
                        assignedIMX,
                ((IRES_VICP_Handle)algHandle->resourceHandles[i])->
                        assignedVLCD,
                ((IRES_VICP_Handle)algHandle->resourceHandles[i])->
                        assignedSEQ);
    }
    return (IRES_OK);
}


/*
 * ===== IRES_ALGORITHM_deinitResources =====
 *
 * Call to free resources that the algorithm had requested 
 * Part of IRES interface 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_deinitResources(IALG_Handle handle,
    IRES_ResourceDescriptor * resourceDescriptor)
{
    Int i = 0;
    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;
    
    for (i = 0; i < NUM_RESOURCES; i++) {
        algHandle->resourceState[i] = 0;
        algHandle->resourceHandles[i] = (IRES_VICP_Handle)NULL;
    }
    return (IRES_OK);
}


/*
 * ===== IRES_ALGORITHM_reinitResources =====
 *
 * Call to change resource holdings of a particular algorithm 
 * Part of IRES interface 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_reinitResources(IALG_Handle handle,
    IRES_ResourceDescriptor * resourceDescriptor,
    IRES_YieldFxn  yieldFxn, IRES_YieldArgs yieldArgs)
{
    Int i = 0;
    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;
    
    for (i = 0; i < NUM_RESOURCES; i++) {
        algHandle->resourceState[i] = 0;
    }

    return (IRES_OK);
}


/*
 * ===== IRES_ALGORITHM_getResourceDescriptors =====
 *
 * Call to query the resource requirements of an algoithm.
 * Once granted the resources, this call will return also the actual resouce
 * handles of the algorithm  
 * Part of IRES interface 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_getResourceDescriptors(IALG_Handle handle, 
    IRES_ResourceDescriptor *resourceDescriptors)
{
    Int i=0;
    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;

    printf("Requesting resources:\n");
    for (i = 0; i < NUM_RESOURCES; i++) {
        resourceDescriptors[i].resourceName = IRES_VICP_PROTOCOLNAME;
        resourceDescriptors[i].revision = &IRES_VICP_PROTOCOLREVISION;
        algHandle->protocolArgs[i].size = sizeof(IRES_VICP_ProtocolArgs);
        algHandle->protocolArgs[i].mode = IRES_SCRATCH; 
        algHandle->protocolArgs[i].requestIMX = 1;
        algHandle->protocolArgs[i].requestVLCD = 1;
        algHandle->protocolArgs[i].requestSEQ = 1;
        resourceDescriptors[i].protocolArgs =
                    (IRES_ProtocolArgs *)&(algHandle->protocolArgs[i]);
        resourceDescriptors[i].handle = 
                (IRES_Handle)algHandle->resourceHandles[i];
        if (IRES_SCRATCH == algHandle->protocolArgs[i].mode) {
            printf("Scratch \n");
        }
        else {
            printf("Persistent \n");
        }
        printf("Resource Descriptor %d: IMX %d, VLCD %d, SEQ %d\n", i, 
                algHandle->protocolArgs[i].requestIMX,
                algHandle->protocolArgs[i].requestVLCD,
                algHandle->protocolArgs[i].requestSEQ);
    }

    return(IRES_OK);
}

/*
 * IRES interface of the algorithm
 */
IRES_Fxns DUMRES_TI_IRES = {
    (void *)&DUMRES_TI_IRES,
    IRES_ALGORITHM_getResourceDescriptors,
    IRES_ALGORITHM_numResourceDescriptors,
    IRES_ALGORITHM_initResources,
    IRES_ALGORITHM_reinitResources,
    IRES_ALGORITHM_deinitResources,
    IRES_ALGORITHM_activateResource,
    IRES_ALGORITHM_activateAllResources,
    IRES_ALGORITHM_deactivateResource,
    IRES_ALGORITHM_deactivateAllResources
};

/*
 * ===== IALG_ALGORITHM_Alloc ======
 *
 * Returns algorithms memory requirements in the memTab structure   
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Alloc(const IALG_Params * params, IALG_Fxns ** fxns, 
    IALG_MemRec memTab[])
{
    memTab[0].size = sizeof(DUMRES_TI_Obj);
    memTab[0].alignment = 4;
    memTab[0].space = IALG_DARAM0;
    memTab[0].attrs = IALG_PERSIST;

    return (NUM_ALLOC);
}


/*
 * ===== IALG_ALGORITHM_Deactivate ======
 *
 * Deactivates the algorithm 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_Deactivate(IALG_Handle handle)
{
    return;
}


/*
 * ===== IALG_ALGORITHM_NumAlloc ======
 *
 * Returns the number of memTab structures required to specify algorithms
 * memory requirements 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_NumAlloc(Void)
{
        return (NUM_ALLOC);
}


/*
 * ===== IALG_ALGORITHM_Control ======
 *
 * Control commands for the algorithm to perform certain tasks 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Control(IALG_Handle handle, IALG_Cmd cmd,
    IALG_Status *status)
{
    IRES_VICP_Properties resourceProperties;
    DUMRES_TI_Handle algHandle = (DUMRES_TI_Handle)handle;

    (*(IRES_Handle)(algHandle->resourceHandles[0])).getStaticProperties(
            (IRES_Handle)algHandle->resourceHandles[0],
                    (IRES_Properties *)&resourceProperties);

    return (0);
}


/*
 * ===== IALG_ALGORITHM_Activate ======
 *
 * Activate the algorithm
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_Activate(IALG_Handle handle)
{
    return;
}

/*
 * ===== IALG_ALGORITHM_Free ======
 *
 * Free the memory allocated to the algorithsm
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Free(IALG_Handle handle, IALG_MemRec * memrec)
{
    DUMRES_TI_Handle alg = (Void *)handle;
    memrec[0].base = alg;
    return (NUM_ALLOC);
}


/*
 * ===== IALG_ALGORITHM_Init ======
 *
 * Initialize the algorithm
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Init(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params)
{
    return 0;
}


/*
 * ===== IALG_ALGORITHM_Moved ======
 *
 * Indicates that the algoirthm has moved in memory, performs initializations
 * as required
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_Moved(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params)
{
    return;
}

IALG_Fxns DUMRES_TI_IALG = {
    (Void *)&DUMRES_TI_IALG,
    IALG_ALGORITHM_Activate,
    IALG_ALGORITHM_Alloc,
    IALG_ALGORITHM_Control,
    IALG_ALGORITHM_Deactivate,
    IALG_ALGORITHM_Free,
    IALG_ALGORITHM_Init,
    IALG_ALGORITHM_Moved,
    IALG_ALGORITHM_NumAlloc
};
/*
 *  @(#) ti.sdo.fc.rman.examples.vicp; 1, 0, 0,3; 4-16-2012 00:02:34; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

