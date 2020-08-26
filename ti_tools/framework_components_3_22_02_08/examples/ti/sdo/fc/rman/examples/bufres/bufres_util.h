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
 *  ======== bufres_util.h ========
 *  Utility functions for BUFRES resource manager functions.
 */

#ifndef ti_sdo_fc_rman_examples_bufres_BUFRES_UTIL_H_
#define ti_sdo_fc_rman_examples_bufres_BUFRES_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/sdo/fc/ires/iresman.h>

#include <ti/sdo/fc/ires/bufres/bufres.h>

extern IRES_Status BUFRES_init(BUFRES_Params *args);
extern IRES_Status BUFRES_exit();
extern BUFRES_Handle BUFRES_get(IALG_Handle alg, IRES_ResourceDescriptor *args,
        Int scratchId, IRES_Status *pStatus);
extern IRES_Status BUFRES_free(IALG_Handle alg, BUFRES_Handle res,
        IRES_ResourceDescriptor *args, Int scratchId);
extern Void BUFRES_getStaticProps(BUFRES_Handle res, BUFRES_Props *props);

#ifdef __cplusplus
}
#endif

#endif
/*
 *  @(#) ti.sdo.fc.rman.examples.bufres; 1, 0, 0,3; 4-16-2012 00:02:09; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

