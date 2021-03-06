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
 *  ======== HeapMem.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Startup.h>

#include "package/internal/HeapMem.xdc.h"

/*
 *  ======== HeapMem_init ========
 */
Void HeapMem_init()
{
    Int i;
    HeapMem_Object *obj;

    /* 
     * HeapMem inherits from IHeap. Is part of runtime.
     * Will be called during first pass.
     * All APIs need to be ready after first pass. 
     */

    for (i = 0; i < HeapMem_Object_count(); i++) {
        obj = HeapMem_Object_get(NULL, i);

        /* 
         * Some targets don't support the align directive (28x, Linux) and 
         * the buffer must be aligned at runtime. The best solution is to
         * simply perform the below math on all targets. 
         *
         * On targets that don't support the align directive, the static
         * create code will pad the buffer with enough extra space to align
         * the buffer. That way, the HeapMem size remains valid (there's
         * at least that much space) and does not have to be adjusted here.
         */
        obj->buf = (Char *)(((Memory_Size)(obj->buf) + (obj->align - 1)) &
                            ~(obj->align - 1));
        
        /* Place the initial header */
        HeapMem_restore(obj);
    }
}

/*
 *  ======== HeapMem_Instance_init ========
 */
Void HeapMem_Instance_init(HeapMem_Object *obj, const HeapMem_Params *params)
{
    Memory_Size offset;
    
    /*
     *  Check minimum required alignment. If the buffer is not aligned,
     *  force the alignment. This reduces the size of the buffer.     
     */
    obj->buf = params->buf;
    obj->head.size = params->size;
    if (offset = (Memory_Size)(obj->buf) & HeapMem_reqAlignMask) {
        /* Not nicely aligned */
        offset = HeapMem_reqAlign - offset;

        /* Add the offset to make buf aligned */
        obj->buf += offset;

        /* Reduce size by the offset */
        obj->head.size -= offset;
    }

    /* Verify the buffer is large enough */
    Assert_isTrue((obj->head.size >= HeapMem_reqAlign), 
                  HeapMem_A_heapSize);
    
    /* Make sure the size is a multiple of HeapMem_reqAlign */
    obj->head.size = (obj->head.size / HeapMem_reqAlign) * HeapMem_reqAlign;
    
    /* Place the initial header */
    HeapMem_restore(obj);
}

/*
 *  ======== HeapMem_restore ========
 *  The buffer should have the properly alignment at this
 *  point (either from instance$static$init in HeapMem.xs or
 *  from the above HeapMem_Instance_init).
 */
Void HeapMem_restore(HeapMem_Object *obj)
{
    HeapMem_Header *begHeader;

    /*
     * Fill in the top of the memory block
     * next: pointer will be NULL (end of the list)
     * size: size of this block
     */
    begHeader = (HeapMem_Header *)(obj->buf);
    begHeader->next = NULL;
    begHeader->size = obj->head.size;

    obj->head.next = begHeader;
}


/*
 *  ======== HeapMem_alloc ========
 *  HeapMem is implemented such that all of the memory and blocks it works
 *  with have an alignment that is a multiple of the header size and have a
 *  size which is a multiple of the header size. Maintaining this requirement
 *  throughout the implementation ensures that there are never any odd
 *  alignments or odd block sizes to deal with.
 *
 *  Specifically:
 *  The buffer managed by HeapMem:
 *    1. Is aligned on a multiple of sizeof(HeapMem_Header)
 *    2. Has an adjusted size that is a multiple of sizeof(HeapMem_Header)
 *  All blocks on the freelist:
 *    1. Are aligned on a multiple of sizeof(HeapMem_Header)
 *    2. Have a size that is a multiple of sizeof(HeapMem_Header)
 *  All allocated blocks:
 *    1. Are aligned on a multiple of sizeof(HeapMem_Header)
 *    2. Have a size that is a multiple of sizeof(HeapMem_Header)
 *
 */
Ptr HeapMem_alloc(HeapMem_Object *obj, SizeT reqSize,
                    SizeT reqAlign, Error_Block *eb)
{
    IArg key;
    HeapMem_Header *prevHeader, *newHeader, *curHeader;
    Char *allocAddr;
    Memory_Size curSize, adjSize;
    SizeT remainSize; /* free memory after allocated memory      */
    SizeT adjAlign, offset;

    /* Assert that requested align is a power of 2 */
    Assert_isTrue(((reqAlign & (reqAlign - 1)) == 0), HeapMem_A_align);
    
    adjSize = (Memory_Size)reqSize;
    
    /* Make size requested a multiple of Memory_Header */
    if ((offset = (adjSize & HeapMem_reqAlignMask)) != 0) {
        adjSize = adjSize + (HeapMem_reqAlign - offset);
    }
    
    /* Assert that requested block size is non-zero */
    Assert_isTrue((adjSize != 0), HeapMem_A_zeroBlock);

    /*
     *  Make sure the alignment is at least as large as the sizeof
     *  HeapMem_Header.
     *  Note: adjAlign must be a power of 2 (by function constraint) and
     *  Header size is also a power of 2,
     */
    adjAlign = reqAlign;
    if (adjAlign & HeapMem_reqAlignMask) {
        /* adjAlign is less than Header size */
        adjAlign = HeapMem_reqAlign;
    }

    key = Gate_enterModule();

    /* 
     *  The block will be allocated from curHeader. Maintain a pointer to
     *  prevHeader so prevHeader->next can be updated after the alloc.
     */
    prevHeader  = &obj->head;
    curHeader = prevHeader->next;

    /* Loop over the free list. */
    while (curHeader != NULL) {

        curSize = curHeader->size;

        /*
         *  Determine the offset from the beginning to make sure
         *  the alignment request is honored.
         */
        offset = (Memory_Size)curHeader & (adjAlign - 1);
        if (offset) {
            offset = adjAlign - offset;
        }
        
        /* Internal Assert that offset is a multiple of header size */
        Assert_isTrue(((offset & HeapMem_reqAlignMask) == 0), NULL);

        /* big enough? */
        if (curSize >= (adjSize + offset)) {

            /* Set the pointer that will be returned. Alloc from front */
            allocAddr = (Char *)((Memory_Size)curHeader + offset);

            /*
             *  Determine the remaining memory after the allocated block.
             *  Note: this cannot be negative because of above comparison.
             */
            remainSize = curSize - adjSize - offset;
            
            /* Internal Assert that remainSize is a multiple of header size */
            Assert_isTrue(((remainSize & HeapMem_reqAlignMask) == 0), NULL);
            
            /*
             *  If there is memory at the beginning (due to alignment
             *  requirements), maintain it in the list.
             *
             *  offset and remainSize must be multiples of
             *  sizeof(HeapMem_Header). Therefore the address of the newHeader
             *  below must be a multiple of the sizeof(HeapMem_Header), thus
             *  maintaining the requirement.
             */
            if (offset) {

                /* Adjust the curHeader size accordingly */
                curHeader->size = offset;

                /*
                 *  If there is remaining memory, add into the free list.
                 *  Note: no need to coalesce and we have HeapMem locked so
                 *        it is safe.
                 */
                if (remainSize) {
                    newHeader = (HeapMem_Header *)
                        ((Memory_Size)allocAddr + adjSize);
                    newHeader->next = curHeader->next;
                    newHeader->size = remainSize;
                    curHeader->next = newHeader;
                }
            }
            else {
                /*
                 *  If there is any remaining, link it in,
                 *  else point to the next free block.
                 *  Note: no need to coalesce and we have HeapMem locked so
                 *        it is safe.
                 */
                if (remainSize) {
                    newHeader = (HeapMem_Header *)
                        ((Memory_Size)allocAddr + adjSize);
                    newHeader->next  = curHeader->next;
                    newHeader->size  = remainSize;
                    prevHeader->next = newHeader;
                }
                else {
                    prevHeader->next = curHeader->next;
                }
            }

            Gate_leaveModule(key);
                                    
            /* Success, return the allocated memory */
            return ((Ptr)allocAddr);
        }
        else {
            prevHeader = curHeader;
            curHeader = curHeader->next;
        }
    }

    Gate_leaveModule(key);
    
    Error_raise(eb, HeapMem_E_memory, (IArg)obj, (IArg)reqSize);

    return (NULL);
}

/*
 *  ======== HeapMem_free ========
 */
Void HeapMem_free(HeapMem_Object *obj, Ptr addr, SizeT size)
{
    IArg key;
    HeapMem_Header *curHeader, *newHeader, *nextHeader;
    SizeT offset;
    
    /* Make sure the addr is aligned properly */
    Assert_isTrue((((UArg)addr & HeapMem_reqAlignMask) == 0), 
                  HeapMem_A_invalidFree);

    /* obj->head never changes, doesn't need Gate protection. */
    curHeader = &obj->head;

    /* Restore size to actual allocated size */
    if ((offset = size & HeapMem_reqAlignMask) != 0) {
        size += HeapMem_reqAlign - offset;
    }
    
    key = Gate_enterModule();

    newHeader = (HeapMem_Header *)addr;
    nextHeader = curHeader->next;

    /* 
     *  Make sure the entire buffer is in the range of the heap.
     *  Note the obj->head.size never changes
     */
    Assert_isTrue((((UArg)newHeader >= (UArg)(obj->buf)) && 
                   ((UArg)newHeader + size <= 
                    (UArg)(obj->buf) + obj->head.size)),
                   HeapMem_A_invalidFree);

    /* Go down freelist and find right place for buf */
    while (nextHeader != NULL && nextHeader < newHeader) {
        /* Make sure the addr is not in this free block */
        Assert_isTrue(((UArg)newHeader >= (UArg)nextHeader + nextHeader->size),
                       HeapMem_A_invalidFree);
        curHeader = nextHeader;
        nextHeader = nextHeader->next;        
    }

    newHeader->next = nextHeader;
    newHeader->size = size;
    curHeader->next = newHeader;

    /* Join contiguous free blocks */    
    if (nextHeader != NULL) {
        /*
         *  Verify the free size is not overlapping. Not all cases are 
         *  detectable, but it is worth a shot. Note: only do this
         *  assert if nextHeader is non-NULL.
         */
        Assert_isTrue((((UArg)newHeader + size) <= (UArg)nextHeader), 
                      HeapMem_A_invalidFree);

        /* Join with upper block */
        if (((Memory_Size)newHeader + size) == (Memory_Size)nextHeader) {
            newHeader->next = nextHeader->next;
            newHeader->size += nextHeader->size;
        }
    }
    /*
     *  Join with lower block. Make sure to check to see if not the
     *  first block.
     */
    if ((curHeader != &obj->head) &&
        (((Memory_Size)curHeader + curHeader->size) == (Memory_Size)newHeader)) {
        curHeader->next = newHeader->next;
        curHeader->size += newHeader->size;
    }
    
    Gate_leaveModule(key);
}

/*
 *  ======== HeapMem_isBlocking ========
 */
Bool HeapMem_isBlocking(HeapMem_Object *obj)
{
    return (Gate_canBlock());    
}

/*
 *  ======== HeapMem_getStats ========
 */
Void HeapMem_getStats(HeapMem_Object *obj, Memory_Stats *stats)
{
    IArg key;
    HeapMem_Header *curHeader;

    stats->totalSize         = obj->head.size;
    stats->totalFreeSize     = 0;                   /* determined later */
    stats->largestFreeSize   = 0;                   /* determined later */

    key = Gate_enterModule();
    
    curHeader = obj->head.next;
    
    while (curHeader != NULL) {
        stats->totalFreeSize += curHeader->size;
        if (stats->largestFreeSize < curHeader->size) {
            stats->largestFreeSize = curHeader->size;
        }
        curHeader = curHeader->next;
    }

    Gate_leaveModule(key);

    return;
}

/*
 *  ======== HeapMem_getExtendedStats ========
 */
Void HeapMem_getExtendedStats(HeapMem_Object *obj, HeapMem_ExtendedStats *stats)
{
    stats->buf   = obj->buf;
    stats->size  = obj->head.size;

    return;
}

/*
 *  ======== HeapMem_enter ========
 *  Enter the HeapMem module's gate.
 */
IArg HeapMem_enter()
{
    return (Gate_enterModule());
}

/*
 *  ======== HeapMem_leave ========
 *  Leave the HeapMem module's gate.
 */
Void HeapMem_leave(IArg key)
{
    Gate_leaveModule(key);
}

/*
 */
/*
 *  @(#) ti.sysbios.heaps; 2, 0, 0, 0,552; 5-18-2012 06:05:44; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

