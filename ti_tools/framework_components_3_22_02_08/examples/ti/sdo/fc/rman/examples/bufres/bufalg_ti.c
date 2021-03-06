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
 *  ======== bufalg_ti.c ========
 *  Implementation of the BUFALG_TI.h interface; TI's implementation
 *  of the IBUFALG interface.
 */

#pragma CODE_SECTION(BUFALG_TI_alloc, ".text:algAlloc")
#pragma CODE_SECTION(BUFALG_TI_free, ".text:algFree")
#pragma CODE_SECTION(BUFALG_TI_initObj, ".text:algInit")
#pragma CODE_SECTION(BUFALG_TI_init, ".text:init")
#pragma CODE_SECTION(BUFALG_TI_exit, ".text:exit")

#include <xdc/std.h>

#include <ti/xdais/ialg.h>
#include <ti/xdais/ires.h>

/*
 * As this file uses the BUFRES_PROTOCOL definitions, define this before
 * including "bufres.h"
 */
#define ti_sdo_fc_rman_examples_bufres_BUFRES_ENABLEPROTOCOLREV
#include <ti/sdo/fc/ires/bufres/bufres.h>

#include "bufalg_ti_priv.h"
#include "bufalg_ti.h"

/* IRES Function Declarations */
static IRES_Status BUFALG_TI_activateRes(IALG_Handle handle, IRES_Handle res);
static IRES_Status BUFALG_TI_activateAllRes(IALG_Handle handle);
static IRES_Status BUFALG_TI_deactivateRes(IALG_Handle handle,IRES_Handle res);
static IRES_Status BUFALG_TI_deactivateAllRes(IALG_Handle handle);
static Int BUFALG_TI_numResources(IALG_Handle handle);
static IRES_Status BUFALG_TI_getResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc);
static IRES_Status BUFALG_TI_initResources(IALG_Handle h,
        IRES_ResourceDescriptor * desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs);
static IRES_Status BUFALG_TI_deInitResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc);
static IRES_Status BUFALG_TI_reInitResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc,
        IRES_YieldFxn  yieldFxn, IRES_YieldArgs yieldArgs);

/*
 *  ======== BUFALG_TI_IRES ========
 */
IRES_Fxns BUFALG_TI_IRES = {
    &BUFALG_TI_IRES,
    BUFALG_TI_getResources,
    BUFALG_TI_numResources,
    BUFALG_TI_initResources,
    BUFALG_TI_reInitResources,
    BUFALG_TI_deInitResources,
    BUFALG_TI_activateRes,
    BUFALG_TI_activateAllRes,
    BUFALG_TI_deactivateRes,
    BUFALG_TI_deactivateAllRes
};

/*
 *  ======== BUFALG_PARAMS ========
 *  This structure defines the default creation parameters.
 */
IBUFALG_Params IBUFALG_PARAMS = {
    sizeof(IBUFALG_Params),
};


/*
 *  ======== BUFALG_TI_activate ========
 *  Fills the scratch buffers.
 */
/* ARGSUSED */
Void BUFALG_TI_activate(IALG_Handle handle)
{
//    BUFALG_TI_Obj     *alg = (Void *)handle;
}

/*
 *  ======== BUFALG_TI_alloc ========
 *  Return a table of memory descriptors that describe the memory needed
 *  to construct a BUFALG_TI_Obj structure.
 */
/* ARGSUSED */
Int BUFALG_TI_alloc(const IALG_Params *algParams, IALG_Fxns **fxns,
                  IALG_MemRec memTab[])
{
    const   IBUFALG_Params *params = (Void *)algParams;

    if (params == NULL) {
        params = &IBUFALG_PARAMS; /* set default parameters */
    }

    /* Request memory for BUFALG object */
    memTab[0].size = sizeof(BUFALG_TI_Obj);
    memTab[0].alignment = 0;
    memTab[0].space = IALG_DARAM0;
    memTab[0].attrs = IALG_PERSIST;

    return (NUMALLOC);
}

/*
 *  ======== BUFALG_TI_control ========
 *  Execute a control operation.
 */
/* ARGSUSED */
Int BUFALG_TI_control(IALG_Handle handle, IALG_Cmd cmd,
        IALG_Status * status)
{
    return (1);
}

/*
 *  ======== BUFALG_TI_deactivate ========
 *  Checks that the scratch buffers still hold the correct values.
 */
/* ARGSUSED */
Void BUFALG_TI_deactivate(IALG_Handle handle)
{
//    BUFALG_TI_Obj *alg = (Void *)handle;
}

/*
 *  ======== BUFALG_TI_exit ========
 *  Exit the module as a whole.
 */
Void BUFALG_TI_exit(Void)
{
}

/*
 *  ======== BUFALG_TI_free ========
 *  Return a table of memory pointers that should be freed.  Note that
 *  this should include *all* memory requested in the alloc operation above.
 */
Int BUFALG_TI_free(IALG_Handle handle, IALG_MemRec memTab[])
{
    BUFALG_TI_Obj   *alg = (Void *)handle;
    Int             n;

   /* Get the memory attributes for the BUFALG object */
    n = BUFALG_TI_alloc(NULL, NULL, memTab);

    /* Set the memory bases */
    memTab[0].base = alg;

    return (n);
}

/*
 *  ======== BUFALG_TI_init ========
 *  Initialize the module as a whole.
 */
Void BUFALG_TI_init(Void)
{
}

/*
 *  ======== BUFALG_TI_initObj ========
 *  Initialize the memory allocated for our instance.
 */
/* ARGSUSED */
Int BUFALG_TI_initObj(IALG_Handle handle, const IALG_MemRec memTab[],
        IALG_Handle p, const IALG_Params *algParams)
{
    BUFALG_TI_Obj  *alg = (Void *)handle;
    Int             i;

    /* Initialize args for requesting resources */
    for (i = 0; i < NUMRES; i++) {
        alg->args[i].iresArgs.size = sizeof(BUFRES_Args);
        alg->args[i].length = 0x20;
        alg->args[i].align = 0;
    }

    return (IALG_EOK);
}

/*
 *  ======== BUFALG_TI_numAlloc ========
 *  Return the maximum number memory blocks needed.
 */
Int BUFALG_TI_numAlloc(Void)
{
    return (NUMALLOC);
}

/*
 * ======== IRES_Fxns and other IRES stuff ========
 */

/*
 *  ======== BUFALG_TI_activateRes ========
 */
static IRES_Status BUFALG_TI_activateRes(IALG_Handle handle, IRES_Handle res)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)handle;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        if ((IRES_Handle)alg->res[i] == res) {
            /* Found it */
            break;
        }
    }

    if ((i < NUMRES) && (alg->resActive[i] == FALSE)) {
        /* Do whatever needs to be done before we start using this resource */
        alg->resActive[i] = TRUE;
        return (IRES_OK);
    }
    else {
        /* The resource was not found or was already active */
        return (IRES_ENORESOURCE);
    }
}


/*
 *  ======== BUFALG_TI_activateAllRes ========
 */
static IRES_Status BUFALG_TI_activateAllRes(IALG_Handle handle)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)handle;
    Int            i;
    IRES_Status    retVal;

    /* Activate all resources */
    for (i = 0; i < NUMRES; i++) {
        retVal = BUFALG_TI_activateRes(handle, (IRES_Handle)alg->res[i]);
        if (retVal != IRES_OK) {
            return (retVal);
        }
    }
    return (IRES_OK);
}

/*
 *  ======== BUFALG_TI_deactivateRes ========
 */
static IRES_Status BUFALG_TI_deactivateRes(IALG_Handle handle, IRES_Handle res)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)handle;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        if ((IRES_Handle)alg->res[i] == res) {
            /* Found it */
            break;
        }
    }

    if ((i < NUMRES) && (alg->resActive[i] == TRUE)) {
        /* Do what needs to be done when done using this resource */
        alg->resActive[i] = FALSE;
        return (IRES_OK);
    }
    else {
        /* The resource was not found or was already active */
        return (IRES_ENORESOURCE);
    }
}

/*
 *  ======== BUFALG_TI_deactivateAllRes ========
 */
static IRES_Status BUFALG_TI_deactivateAllRes(IALG_Handle handle)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)handle;
    Int            i;
    IRES_Status    retVal;
    IRES_Status    status = IRES_OK;

    for (i = 0; i < NUMRES; i++) {
        retVal = BUFALG_TI_deactivateRes(handle, (IRES_Handle)alg->res[i]);
        if (retVal != IRES_OK) {
            status = retVal;
        }
    }

    return (status);
}

/*
 *  ======== BUFALG_TI_numResources ========
 */
/* ARGSUSED */
static Int BUFALG_TI_numResources(IALG_Handle handle)
{
    return (NUMRES);
}

/*
 *  ======== BUFALG_TI_getResources ========
 */
static IRES_Status BUFALG_TI_getResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)h;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        desc[i].resourceName = BUFRES_PROTOCOLNAME;
        desc[i].revision = &BUFRES_PROTOCOLVERSION;
        desc[i].protocolArgs = (IRES_ProtocolArgs *)&(alg->args[i]);
        desc[i].protocolArgs->mode = IRES_SCRATCH;

        if (alg != NULL) {
            desc[i].handle = (IRES_Handle)(alg->res[i]);
        }
        else {
            desc[i].handle = NULL;
        }
    }
    //desc[1].resourceName = "JUNK";

    return (IRES_OK);
}

/*
 *  ======== BUFALG_TI_initResources ========
 */
static IRES_Status BUFALG_TI_initResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)h;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        alg->res[i] = (BUFRES_Handle)desc[i].handle;
    }

    alg->yieldFxn = yieldFxn;
    alg->yieldArgs = yieldArgs;

    return (IRES_OK);
}

/*
 *  ======== BUFALG_TI_deInitResources ========
 */
/* ARGSUSED */
static IRES_Status BUFALG_TI_deInitResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)h;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        alg->resActive[i] = FALSE;
                alg->res[i] = NULL;
/*              desc[i].handle = NULL;    Don't do this*/
    }

    return (IRES_OK);
}

/*
 *  ======== BUFALG_TI_reInitResources ========
 */
static IRES_Status BUFALG_TI_reInitResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc,
        IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs)
{
    BUFALG_TI_Obj  *alg = (BUFALG_TI_Obj *)handle;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        alg->yieldFxn = yieldFxn;
        alg->yieldArgs = yieldArgs;
        alg->res[i] = (BUFRES_Handle)desc[i].handle;
        alg->resActive[i] = FALSE;
    }
    return (IRES_OK);
}

/*
 *  Other IBUFALG functions.
 */

/*
 *  ======== BUFALG_TI_useBufs ========
 */
/* ARGSUSED */
Int BUFALG_TI_useBufs(IBUFALG_Handle alg)
{
    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.bufres; 1, 0, 0,3; 4-16-2012 00:02:08; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

