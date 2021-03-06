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
 *  ======== mySem.c ========
 */

#include <ti/bios/include/std.h>
#include <ti/sdo/fc/rman/rman.h>

typedef struct Sem_Obj {
    Int sem;
} Sem_Obj;

static Sem_Obj mySem= { 0xC0FFEE };
static Bool pending = FALSE;

/* ARGSUSED */
RMAN_SemHandle mySemCreate(Int key, Int count)
{
    if (1 != count) {
        return NULL;
    }
    mySem.sem = key;
    return (Void *)&mySem;
}

/* ARGSUSED */
Void mySemDelete(RMAN_SemHandle sem)
{
   mySem.sem = 0xC0FFEE;
}

/* ARGSUSED */
Int mySemPend(RMAN_SemHandle sem, unsigned int timeout)
{
    if ((sem != &mySem) || (pending != FALSE)) {
        return -1;
    }
    else {
       pending = TRUE;
    }
        return 0;
}

/* ARGSUSED */
Void mySemPost(RMAN_SemHandle sem)
{
    pending = FALSE;
}
/*
 *  @(#) ti.sdo.fc.rman.examples.dummyEdma3; 1, 0, 0,3; 4-16-2012 00:02:16; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

