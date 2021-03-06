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
 *  ======== lck.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <ti/bios/support/Lck.h>

#include <ti/bios/include/std.h>
#include <ti/bios/include/lck.h>


LCK_Handle LCK_create(LCK_Attrs *attrs)
{
    Error_Block eb;

    Error_init(&eb);

    return ((LCK_Handle)Lck_create(NULL, &eb));
}

Void LCK_delete(LCK_Handle lck)
{
    Lck_Handle handle = (Lck_Handle)lck;

    Lck_delete(&handle);
}

Bool LCK_pend(LCK_Handle lck, Uns timeout)
{
    return (Lck_pend((Lck_Handle)lck, timeout));
}

Void LCK_post(LCK_Handle lck)
{
    Lck_post((Lck_Handle)lck);
}

/*! Revision history
 *! =================
 *! 26-Jul-2007 jv      create an error block.
 */
/*
 *  @(#) ti.bios; 5, 6, 0,546; 5-18-2012 06:03:24; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

