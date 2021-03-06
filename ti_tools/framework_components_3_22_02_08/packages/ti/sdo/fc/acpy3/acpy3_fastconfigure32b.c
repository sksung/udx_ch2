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
 * ======== acpy3_fastconfigure32b.c ========
 * Configure a logical channel efficiently
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#ifndef _ACPY3_CPUCOPY_
#include <ti/sdo/fc/memutils/memutils.h>
#endif

#include "acpy3.h"


#define ACPY3_FASTCONFIGURE32B_IMPLEMENTATION

#ifdef __TI_COMPILER_VERSION__
#pragma CODE_SECTION(ACPY3_fastConfigure32b, ".text:ACPY3_fastConfigure32b")
#endif

extern Registry_Desc ti_sdo_fc_acpy3_desc;

#ifdef __TI_COMPILER_VERSION__
#include "acpy3_fastconfigure32b.h"
#else

#include <ti/xdais/idma3.h>
#include <ti/sdo/fc/acpy3/acpy3_qdma.h>
#include <ti/sdo/fc/acpy3/acpy3_util.h>

/*
 *  ======== ACPY3_fastConfigure32b ========
 */
Void ACPY3_fastConfigure32b(IDMA3_Handle restrict handle,
    ACPY3_ParamField32b fieldId, Uns value, short transferNo)
{
    ACPY3_PaRamRegs * paRamCache;
#ifndef _ACPY3_CPUCOPY_
    UInt32            physVal;
    Int               size;
#endif

    Log_print4(Diags_ENTRY, "[+E] ACPY3_fastConfigure32b> "
            "Enter (handle=0x%x, fieldId=0x%x, value=0x%x, transferNo=%d)",
            (IArg)handle, (IArg)fieldId, (IArg)value, (IArg)transferNo);

    paRamCache = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle, transferNo);

#ifndef _ACPY3_CPUCOPY_
    /* Address fields must be converted to physical address */
    size = 4; /* Otherwise we have to read the registers */
    if ((fieldId == ACPY3_PARAMFIELD_SRCADDR) ||
            (fieldId == ACPY3_PARAMFIELD_DSTADDR)) {
        physVal = (UInt32)MEMUTILS_getPhysicalAddr((Ptr)value);
        *((Uns *)((Uns)paRamCache + fieldId)) = physVal;
    }
    else {
        /* Non-address field */
        *((Uns *)((Uns)paRamCache + fieldId)) = value;
    }
#else
    *((Uns *)((Uns)paRamCache + fieldId)) = value;
#endif

    Log_print0(Diags_EXIT, "[+X] ACPY3_fastConfigure32b> Exit");

}
#endif /* #ifdef __TI_COMPILER_VERSION__ */
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,3; 4-16-2012 00:00:10; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

