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

/*
 *  ======== TimestampProvider.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Startup.h>
#include <xdc/runtime/Types.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/family/arm/m3/Hwi.h>

#include <ti/sysbios/family/arm/ducati/Core.h>
#include <ti/sysbios/family/arm/ducati/CTM.h>

#include "package/internal/TimestampProvider.xdc.h"

/*
 *  ======== TimestampProvider_Module_startup ========
 */
Int TimestampProvider_Module_startup( Int phase )
{
    UInt hwiKey;
    UInt32 ctcr;

    /* configure and enable the counters if they aren't already */
    if ((CTM_ctm.CTGNBL[0] & 0x14) != 0x14) {
        hwiKey = Hwi_disable();

        CTM_ctm.CTCNTL |= 1;    /* enable the CTM */

        /* program the counter to use the configured inpsel */
        ctcr = (TimestampProvider_inpsel << 16) | 0x4;

        CTM_ctm.CTCR[2] = ctcr; /* enable Chain mode */
        CTM_ctm.CTCR[3] = ctcr; /* enable Chain mode */
        CTM_ctm.CTCR[4] = ctcr; /* enable Chain mode */
        CTM_ctm.CTCR[5] = ctcr; /* enable Chain mode */

        CTM_ctm.CTGRST[0] |= 0x3c; /* reset counters 2,3,4,5 syncronously */
        CTM_ctm.CTGNBL[0] |= 0x14; /* enable counters 2,4 syncronously */

        Hwi_restore(hwiKey);
    }
    return Startup_DONE;
}

/*
 *  ======== TimestampProvider_get32 ========
 */
Bits32 TimestampProvider_get32()
{
    UInt hwiKey;
    volatile UInt32 hi;
    UInt32 lo;

    hwiKey = Hwi_disable();
    if (Core_id == 0) {
        hi = CTM_ctm.CTCNTR[3]; /* read hi part to update lo shadow */
        lo = CTM_ctm.CTCNTR[2]; /* return lo shadow */
    }
    else {
        hi = CTM_ctm.CTCNTR[5]; /* read hi part to update lo shadow */
        lo = CTM_ctm.CTCNTR[4]; /* return lo shadow */
    }
    Hwi_restore(hwiKey);

    return lo;
}

/*
 *  ======== TimestampProvider_get64 ========
 */
Void TimestampProvider_get64(Types_Timestamp64 *result)
{
    UInt hwiKey;

    hwiKey = Hwi_disable();
    if (Core_id == 0) {
        result->hi = CTM_ctm.CTCNTR[3]; /* read hi part to update lo shadow */
        result->lo = CTM_ctm.CTCNTR[2]; /* read lo shadow */
    }
    else {
        result->hi = CTM_ctm.CTCNTR[5]; /* read hi part to update lo shadow */
        result->lo = CTM_ctm.CTCNTR[4]; /* read lo shadow */
    }
    Hwi_restore(hwiKey);
}

/*
 *  ======== TimestampProvider_getFreq ========
 */
Void TimestampProvider_getFreq(Types_FreqHz *freq)
{
    Int32 lo;

    BIOS_getCpuFreq(freq);

    /* CTM freq is 2x CPU clock */ 

    lo = (Int32)freq->lo;

    freq->lo <<= 1;
    freq->hi <<= 1;

    if (lo < 0) {
        freq->hi |= 1;
    }
}

/*
 */
/*
 *  @(#) ti.sysbios.family.arm.ducati; 2, 0, 0, 0,302; 5-18-2012 06:04:13; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

