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
 *  ======== GateMPNull.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>

#include "package/internal/GateMPNull.xdc.h"

/*
 *  ======== GateMPNull_enter ========
 */
extern IArg GateMPNull_enter(GateMPNull_Object *gate)
{
    return (1);
}

/*
 *  ======== GateMPNull_leave ========
 */
Void GateMPNull_leave(GateMPNull_Object *gate, IArg key)
{
//    return (TRUE);
}

/*
 *  ======== GateMPNull_query ========
 */
Bool GateMPNull_query(Int qual)
{
    return (FALSE);
}

/*
 *  ======== GateMPNull_getReferenceCount ========
 */
Int GateMPNull_getReferenceCount(GateMPNull_Object *gate, Error_Block *err)
{
    return (0);
}

/*
 *  @(#) ti.sdo.fc.utils.osal.noOS; 1, 0, 0,3; 4-16-2012 00:02:51; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

