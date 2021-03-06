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
 *  @file       ti/sdo/fc/ires/hdvicp/test/ires_algorithm.h 
 *
 *  @brief      Definitions for dummy implementation of the IRES interfaces 
 *              by an algorithm  
 *
 */

#include <ti/xdais/ires.h>
#ifdef _DUCATI
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp2.h>
#else
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp.h>
#endif

#include <ti/sdo/utils/trace/gt.h>
extern GT_Mask ti_sdo_fc_rman_examples_hdvicp;

#define LOWESTPRI   12
#define LOWPRI      13 
#define HIGHPRI     14
#define HIGHESTPRI  15


/*
 * @brief  Number of resources the algorithm will request 
 */
//#define NUM_RESOURCES   2
#define NUM_RESOURCES   1
#define CURTRACE ti_sdo_fc_rman_examples_plugin

/*
 * @brief  Number of memory resources required by IALG implementation 
 */
#define NUM_ALLOC       1

/*
 * @brief   IRES interface of the algorithm object
 */
extern IRES_Fxns DUMALG_TI_IRES;

/*
 * @brief   IALG interface of the algorithm object
 */
extern IALG_Fxns DUMALG_TI_IALG;

/*
 * Context args structure for the HDVICP resource object 
 */
typedef struct BUFALG_TI_CtxtArgs {
    Int size; 
} BUFALG_TI_CtxtArgs;

/*
 *  Extension of the IALG object for the HDVICP object 
 */
typedef struct DUMALG_TI_Obj {
    IALG_Obj                    alg;
#ifdef _DUCATI
    IRES_HDVICP2_Handle         resourceHandles[NUM_RESOURCES];
#else
    IRES_HDVICP_Handle          resourceHandles[NUM_RESOURCES]; 
#endif

    short                       resourceState[NUM_RESOURCES]; 
#ifdef _DUCATI
    IRES_HDVICP2_ProtocolArgs   protocolArgs[NUM_RESOURCES];
#else
    IRES_HDVICP_ProtocolArgs    protocolArgs[NUM_RESOURCES];
#endif
    short                       paRamArray[512];
    IRES_YieldFxn               yieldFxn;
    IRES_YieldArgs              yieldArgs;
    IRES_YieldContext           yieldContext;
    BUFALG_TI_CtxtArgs          contextArgs;
#ifdef _DUCATI
    Int                         hdvicp[NUM_RESOURCES];
#else
    IRES_HDVICP_RequestType     hdvicp[NUM_RESOURCES];
#endif
    Int                         yieldFlag;
    Int                         taskId;
} DUMALG_TI_Obj;

/*
 * Handle to the IALG HDVICP object 
 */
typedef DUMALG_TI_Obj * DUMALG_TI_Handle;

/*
 * Creation paramters for the DUMALG object
 */
typedef struct IDUMALG_Params {
    Int                         size;
#ifdef _DUCATI
    Int                         hdvicp[NUM_RESOURCES];
#else
    IRES_HDVICP_RequestType     hdvicp[NUM_RESOURCES];
#endif
    Int                         yieldFlag;
    Int                         taskId;
} IDUMALG_Params;

/*
 * Paramter values for DUMALG instance objects 
 */
extern IDUMALG_Params IDUMALG_PARAMS;

/*
 * This structure must be first field of all DUMALG instance objects  
 */
typedef struct IDUMALG_Obj {
    struct IDUMALG_Fxns         *fxns;
} IDUMALG_Obj;

typedef IDUMALG_Obj * IDUMALG_Handle;

/*
 * Defines the full set of operations that can be performed on the DUMALG object
 */
typedef struct IDUMALG_Fxns {
    IALG_Fxns                   alg;
    Int                         (* useHDVICP)(IDUMALG_Handle handle,
                                        unsigned int Id, unsigned int Grp);
} IDUMALG_Fxns;

/*
 * Defines TI's implementation of the IDUMALG interface 
 */
extern IDUMALG_Fxns DUMALG_TI_IDUMALG;

Int DUMALG_TI_useHDVICP( IDUMALG_Handle handle, unsigned int Id, unsigned int 
        grp);
/*
 *  @(#) ti.sdo.fc.rman.examples.plugin; 1, 0, 0,3; 4-16-2012 00:02:23; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

