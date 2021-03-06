/*
 *  @file   OsalMutex.c
 *
 *  @brief      Linux kernel Mutex interface implementation.
 *
 *              Kernel Mutex control provided at the kernel
 *              level with the help of Mutex objects. Interface do not
 *              contain much of the state informations and are independent.
 *
 *
 *  ============================================================================
 *
 *  Copyright (c) 2008-2012, Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information: 
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 *  
 */



/* Standard headers */
#include <ti/syslink/Std.h>

/* OSAL and utils headers */
#include <OsalMutex.h>
#include <ti/syslink/utils/Trace.h>
#include <ti/syslink/utils/Memory.h>
#include <ti/syslink/utils/Gate.h>

/* Linux specific header files */
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mutex.h>


#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 * =============================================================================
 */
#define NESTED_ENTER  1
#define FIRST_ENTER   0
/*!
 *  @brief   Defines object to encapsulate the Mutex.
 *           The definition is OS/platform specific.
 */
typedef struct OsalMutex_Object_tag {
    struct mutex   lock; /*!< OS specific mutex lock */
    OsalMutex_Type type; /*!< Type of mutex. */
    Ptr    owner;
    UInt32 nested;
    wait_queue_head_t   list; /*!< thread waiting queue for this lock */
} OsalMutex_Object;


/* =============================================================================
 * APIs
 * =============================================================================
 */
/*!
 *  @brief      Creates an instance of Mutex object.
 *
 *  @param      type Type of mutex.
 *
 *  @sa         OsalMutex_delete, Memory_alloc
 */
OsalMutex_Handle
OsalMutex_create (OsalMutex_Type type)
{
    OsalMutex_Object *  mutexObj = NULL;

    GT_1trace (curTrace, GT_ENTER, "OsalMutex_create", type);

    GT_assert (curTrace, (type < OsalMutex_Type_EndValue));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (type >= OsalMutex_Type_EndValue) {
        /*! @retval NULL Invalid value provided for argument type. */
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalMutex_create",
                             OSALMUTEX_E_INVALIDARG,
                             "Invalid value provided for argument type.");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        mutexObj = Memory_calloc (NULL, sizeof (OsalMutex_Object), 0, NULL);
#if !defined(SYSLINK_BUILD_OPTIMIZE)
        if (mutexObj == NULL) {
            /*! @retval NULL Failed to allocate memory for Mutex object. */
            GT_setFailureReason (curTrace,
                                 GT_4CLASS,
                                 "OsalIsr_create",
                                 OSALMUTEX_E_MEMORY,
                                 "Failed to allocate memory for Mutex object.");
        }
        else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
            mutex_init (&(mutexObj->lock));
            mutexObj->type = type;
            mutexObj->owner = NULL;
            mutexObj->nested = 0;
	        init_waitqueue_head (&mutexObj->list);
#if !defined(SYSLINK_BUILD_OPTIMIZE)
        }
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace (curTrace, GT_LEAVE, "OsalMutex_create", mutexObj);

    /*! @retval Mutex-handle Operation successfully completed. */
    return (OsalMutex_Handle) mutexObj;
}


/*!
 *  @brief      Deletes an instance of Mutex object.
 *
 *  @param      mutexHandle   Mutex object handle which needs to be deleted.
 *
 *  @sa         OsalMutex_create, Memory_free
 */
Int
OsalMutex_delete (OsalMutex_Handle * mutexHandle)
{
    Int status = OSALMUTEX_SUCCESS;

    GT_1trace (curTrace, GT_ENTER, "OsalMutex_delete", mutexHandle);

    GT_assert (curTrace, (mutexHandle != NULL));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (mutexHandle == NULL) {
        /*! @retval OSALMUTEX_E_INVALIDARG NULL provided for argument
                                           mutexHandle.*/
        status = OSALMUTEX_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalMutex_delete",
                             status,
                             "NULL provided for argument mutexHandle");
    }
    else if (*mutexHandle == NULL) {
        /*! @retval OSALMUTEX_E_HANDLE NULL Mutex handle provided. */
        status = OSALMUTEX_E_HANDLE;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalMutex_delete",
                             status,
                             "NULL Mutex handle provided.");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        Memory_free (NULL, *mutexHandle, sizeof (OsalMutex_Object));
        *mutexHandle = NULL;
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace (curTrace, GT_LEAVE, "OsalMutex_delete", status);

    /*! @retval OSALMUTEX_SUCCESS Operation successfully completed. */
    return status;
}


/*!
 *  @brief      Acquire/lock the Mutex object.
 *
 *              This function acquires the critical section identified by this
 *              mutex handle. Once this function is successfully entered,
 *              further calls to OsalMutex_enter shall block till the critical
 *              section has been released by the caller.
 *
 *  @param      mutexHandle   Mutex object handle to be acquired.
 *
 *  @sa         OsalMutex_leave
 */
IArg
OsalMutex_enter (OsalMutex_Handle mutexHandle)
{
    IArg                key;
    OsalMutex_Object *  mutexObj = (OsalMutex_Object*) mutexHandle;
    Bool                blocked = FALSE;
//    UInt32              status = 0;
    UInt32              osStatus = 0;
    UInt32              timeoutVal  = 1000;

    GT_1trace (curTrace, GT_ENTER, "OsalMutex_enter", mutexHandle);

    GT_assert (curTrace, (mutexHandle != NULL));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (mutexHandle == NULL) {
        /* Function does not return status. */
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalMutex_enter",
                             OSALMUTEX_E_HANDLE,
                             "NULL Mutex handle provided.");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
again:
        key = Gate_enterSystem ();
        if (mutexObj->owner == NULL) {
            mutexObj->owner = (Ptr) current->pid;
            mutexObj->nested = 0;
        }
        else {
            if (mutexObj->owner == (Ptr)current->pid) {
                mutexObj->nested++;
			 }
	    else
                blocked = TRUE;
        }
        Gate_leaveSystem (key);

        if (!blocked && mutexObj->nested)
            return (IArg)mutexObj->nested;

        if (blocked) {
            /*
             * any thread that tries to acquire this lock is added
             * to wait list
             */
            DECLARE_WAITQUEUE (wait, current);
            add_wait_queue_exclusive (&mutexObj->list, &wait);
            set_current_state (TASK_INTERRUPTIBLE);
            osStatus = schedule_timeout (timeoutVal);

            if (osStatus && signal_pending (current)) {
                /* What to return here ?? */
                remove_wait_queue (&mutexObj->list, &wait);
                return (IArg)FIRST_ENTER;
            }
            blocked = FALSE;
            remove_wait_queue (&mutexObj->list, &wait);
            goto again;
        }

        if (   (mutexObj->type == OsalMutex_Type_Interruptible)) {
            if (mutex_lock_interruptible (&(mutexObj->lock)) != 0) {
                /* TBD: How can we return -ERESTARTSYS? */
            }
        }
        else {
            if (mutexObj->nested == 0) {
                mutex_lock (&(mutexObj->lock));
            }
        }
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_0trace(curTrace, GT_LEAVE, "OsalMutex_enter");

    /*! @retval 0 Operation successfully completed. */
    return (IArg )mutexObj->nested;
}

/*!
 *  @brief      Leave/unlock the Mutex object.
 *
 *              This function releases the critical section identified by this
 *              mutex handle. The completion of this function shall make the
 *              critical section available to any other threads that may be
 *              waiting to acquire it. This also wakes up any thread that is
 *              that is waiting for acquiring the lock
 *
 *  @param      mutexHandle   Mutex object handle to be released.
 *  @param      key           Key received from the corresponding enter call.
 *
 *  @sa         OsalMutex_enter
 */
Void
OsalMutex_leave (OsalMutex_Handle mutexHandle, IArg   key)
{
//    Bool nested = TRUE;
    IArg _key;

    OsalMutex_Object * mutexObj = (OsalMutex_Object*) mutexHandle;

    GT_2trace (curTrace, GT_ENTER, "OsalMutex_leave", mutexHandle, key);

    GT_assert (curTrace, (mutexHandle != NULL));
    /* key can be 0, so not checked. */

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (mutexHandle == NULL) {
        /* Void function, so not setting status. */
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalMutex_leave",
                             OSALMUTEX_E_HANDLE,
                             "NULL Mutex handle provided.");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        _key = Gate_enterSystem ();
        if (key == FIRST_ENTER) {
            mutexObj->owner = NULL;
            mutexObj->nested = 0;
        }
        Gate_leaveSystem (_key);

        if (key == FIRST_ENTER) {
            mutex_unlock (&(mutexObj->lock));
			/* wake up waiting threads */
            wake_up_interruptible (&(mutexObj->list));
        }
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_0trace (curTrace, GT_LEAVE, "OsalMutex_leave");
}


#if defined (__cplusplus)
}
#endif /* defined (_cplusplus)*/
