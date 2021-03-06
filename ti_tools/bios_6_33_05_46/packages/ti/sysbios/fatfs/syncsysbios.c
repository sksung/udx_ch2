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
 * ======== syncsysbios.c ========
 *
 * Synchronization support for FatFS using SYS/BIOS
 */

#include <xdc/std.h>
#include <ti/sysbios/knl/Semaphore.h>

#include "ff.h"

typedef int BOOL;

#if _FS_REENTRANT

/*------------------------------------------------------------------------
 * Create a Synchronization Object for a Volume

 * This function is called in f_mount function to create a new
   synchronization object, such as semaphore and mutex. When a FALSE is
  returned, the f_mount function fails with FR_INT_ERR.

  returns: TRUE: Function succeeded, FALSE:Could not create due to any error 
*/

BOOL ff_cre_syncobj (
        BYTE vol,        /* Corresponding logical drive being processed */
        _SYNC_t *sobj    /* Pointer to return the created sync object */
)
{
    BOOL ret;

    *sobj = (UINT)Semaphore_create(1, NULL, NULL);
    ret = (*sobj != NULL) ? TRUE : FALSE;

    return ret;
}



/*------------------------------------------------------------------------*/
/* Delete a Synchronization Object                                        */
/*------------------------------------------------------------------------*/
/* This function is called in f_mount function to delete a synchronization
/  object that created with ff_cre_syncobj function. When a FALSE is
/  returned, the f_mount function fails with FR_INT_ERR.
/  returns: TRUE: Function succeeded, FALSE: Could not delete due to any error
*/

BOOL ff_del_syncobj (
        _SYNC_t sobj  /* Sync object tied to the logical drive to be deleted */
)
{
    Semaphore_delete((Semaphore_Handle *)&sobj);

    return TRUE;
}



/*------------------------------------------------------------------------*/
/* Request Grant to Access the Volume                                     */
/*------------------------------------------------------------------------*/
/* This function is called on entering file functions to lock the volume.
/  When a FALSE is returned, the file function fails with FR_TIMEOUT.
/
/  returns:  TRUE: Got a grant to access the volume, FALSE: Could not get a
/            grant
*/

BOOL ff_req_grant (
        _SYNC_t sobj        /* Sync object to wait */
)
{
    return Semaphore_pend((Semaphore_Handle)sobj, _FS_TIMEOUT);
}



/*------------------------------------------------------------------------*/
/* Release Grant to Access the Volume                                     */
/*------------------------------------------------------------------------*/
/* This function is called on leaving file functions to unlock the volume.
*/

void ff_rel_grant (
        _SYNC_t sobj        /* Sync object to be signaled */
)
{
    Semaphore_post((Semaphore_Handle)sobj);
}


#else

#error This file is not needed in this configuration.

#endif
/*
 *  @(#) ti.sysbios.fatfs; 1, 0, 0,233; 5-18-2012 06:06:43; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

