/* 
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * */
/*
 *  ======== HeapStd.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/Memory.h>
#include "package/internal/HeapStd.xdc.h"

#include <stdlib.h>

/*
 *  ======== HeapStd_Instance_init ========
 *  Initialize the heap object's fields.
 *
 *  If there is not enough RTS heap memory, then fail by raising an error.
 *  The return value is only used by finalize methods which are not defined
 *  for this module.
 */
Int HeapStd_Instance_init(HeapStd_Object *obj, const HeapStd_Params *params,
    Error_Block *eb)
{
    /* Make sure size is non-zero */
    Assert_isTrue((params->size != 0), HeapStd_A_zeroSize);
    
    /* Make sure there is remaining memory in RTS */
    if (module->remainRTSSize < params->size) {
       Error_raise(eb, HeapStd_E_noRTSMemory, 0, 0);
    }
    else {
        module->remainRTSSize -= params->size;
    
        obj->remainSize = params->size;
        obj->startSize  = params->size;
    }

    return (0);        /* return status passed to finalize method */
}

/*
 *  ======== HeapStd_alloc ========
 *  This heap uses the 'C' rts malloc call. 
 *
 *  Only support alignment requests that will be honored by malloc.
 */
Ptr HeapStd_alloc(HeapStd_Object *obj, SizeT size, SizeT align,
                  Error_Block *eb)
{
    Ptr buf;
    IArg key;

    /* Make sure the specified alignment is not too large */
    Assert_isTrue((align <= Memory_getMaxDefaultTypeAlign()),
        HeapStd_A_invalidAlignment);

    /* Determine if there is enough memory */
    key = Gate_enterSystem();
    if ((SizeT)(obj->remainSize) < size) {
        Gate_leaveSystem(key);
        return (NULL);
    }
    obj->remainSize -= size;
    Gate_leaveSystem(key);
    
    /* malloc the buffer! */
    if ((buf = malloc(size)) == NULL) {
        /* Undo the size change in case of a failure */
        key = Gate_enterSystem();
        obj->remainSize += size;
        Gate_leaveSystem(key);
        return (NULL);
    }

    return (buf);
}

/*
 *  ======== HeapStd_free ========
 *  Free the memory back and adjust the remaining free accordingly
 */
Void HeapStd_free(HeapStd_Object *obj, Ptr block, SizeT size)
{
    IArg key;
    
    free(block);
    
    key = Gate_enterSystem();
    
    /* Adjust the remaining size */
    obj->remainSize += size;    
    
    /* Make sure something fishy is not going on */
    Assert_isTrue((obj->remainSize <= obj->startSize),
        HeapStd_A_invalidTotalFreeSize);
    
    Gate_leaveSystem(key);    
}

/*
 *  ======== HeapStd_isBlocking ========
 */
Bool HeapStd_isBlocking(HeapStd_Object *obj)
{
    return (TRUE);
}

/*
 *  ======== HeapStd_getStats ========
 *  Return the stats.
 */
Void HeapStd_getStats(HeapStd_Object *obj, Memory_Stats *stats)
{
    stats->totalSize         = obj->startSize;
    stats->totalFreeSize     = obj->remainSize;
    stats->largestFreeSize   = 0;
}
/*
 *  @(#) xdc.runtime; 2, 1, 0,375; 4-27-2012 14:30:33; /db/ztree/library/trees/xdc/xdc-y25x/src/packages/
 */

