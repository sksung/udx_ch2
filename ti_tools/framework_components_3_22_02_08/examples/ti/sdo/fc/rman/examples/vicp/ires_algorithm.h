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
 *  @file       ti/sdo/fc/rman/examples/vicp/ires_algorithm.h
 *
 *  @brief      Definitions for dummy implementation of the IRES interfaces
 *              by an algorithm
 *
 */

#include <ti/xdais/ires.h>
#include <ti/sdo/fc/ires/vicp/ires_vicp.h>

/*
 * @brief  Number of resources the algorithm will request
 */
#define NUM_RESOURCES   2

/*
 * @brief  Number of memory resources required by IALG implementation
 */
#define NUM_ALLOC       1

/*
 * @brief   IRES interface of the algorithm object
 */
extern IRES_Fxns DUMRES_TI_IRES;

/*
 * @brief   IALG interface of the algorithm object
 */
extern IALG_Fxns DUMRES_TI_IALG;

/*
 *  Implementation of the IALG interface for BUFALG
 */
typedef struct DUMRES_TI_Obj {
    IALG_Obj                alg;
    IRES_VICP_Handle   resourceHandles[NUM_RESOURCES];
    short                   resourceState[NUM_RESOURCES];
    IRES_VICP_ProtocolArgs protocolArgs[NUM_RESOURCES];
    short                   paRamArray[512];
} DUMRES_TI_Obj;

typedef DUMRES_TI_Obj * DUMRES_TI_Handle;
/*
 *  @(#) ti.sdo.fc.rman.examples.vicp; 1, 0, 0,3; 4-16-2012 00:02:34; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

