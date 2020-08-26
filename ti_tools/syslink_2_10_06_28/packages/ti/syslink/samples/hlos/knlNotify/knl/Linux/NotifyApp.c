/*
 *  @file   NotifyApp.c
 *
 *  @brief      Sample application for notify in kernel
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

#include <linux/spinlock.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <asm/pgtable.h>

/* linux headers */
#include <syslink/multiproc.h>
#include <syslink/notify.h>

#include "Std.h"
#include "SysLinkSamples.h"
#include "NotifyApp.h"

#include <linux/types.h>

/* Module level headers */
#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */

#define Osal_printf   printk


/** ============================================================================

 *  Globals
 *  ============================================================================
 */

/*!
 *  @brief  Received event count for remote notifications.
 */
UInt32 NotifyApp_recvEventCount [MULTIPROC_MAXPROCESSORS] [NOTIFYAPP_NUMEVENTS];

extern UInt16  NotifyApp_numProcs;
extern UInt16  NotifyApp_procId   [MULTIPROC_MAXPROCESSORS];
extern Bool    NotifyApp_runAll;

UInt32 SysLogging_UserCallbackCount = 0;

/** ============================================================================
 *  Functions
 *  ============================================================================
 */
Void
NotifyApp_rtosInfocallback (UInt16       procId,
                            UInt16       lineId,
                            UInt32       eventNo,
                            Void *       arg,
                            UInt32       payload)
{
    Osal_printf ("Number of RTOS-side received/sent events:\n"
             "    procId: [%d]\n"
             "    Number of events: [%d]\n",
             procId,
             payload);

    if (payload != (NOTIFYAPP_NUMEVENTS * NOTIFYAPP_NUM_TRANSFERS)) {
        Osal_printf ("*****Failure on RTOS-side*****\n"
                 "    Expected num events: [%d]\n"
                 "    Received num events: [%d]\n",
                 (NOTIFYAPP_NUMEVENTS * NOTIFYAPP_NUM_TRANSFERS),
                 payload);
    }
//    OsalSemaphore_post ((OsalSemaphore_Handle) arg);
}


/*!
 *  @brief  Callback function for receiving events.
 *
 *  @param  procId  Processor ID from which the event is received
 *  @param  eventNo Event number received
 *  @param  arg     Argument associated with the event number
 *  @param  payload Payload received with the event
 *
 *  @sa     NotifyApp_execute
 */
Void
NotifyApp_callback (UInt16       procId,
                    UInt16       lineId,
                    UInt32       eventNo,
                    Void *       arg,
                    UInt32       payload)
{
    UInt32 eventCount;

    SysLogging_UserCallbackCount++;

    NotifyApp_recvEventCount [procId][eventNo - NOTIFYAPP_EVENT_NO]++;
    eventCount = NotifyApp_recvEventCount[procId][eventNo - NOTIFYAPP_EVENT_NO];


    if ((eventCount % NOTIFY_PRINT_COUNT) == 0) {
        Osal_printf ("Received %d events for event ID %d "
                     "from processor %d\n",
                     eventCount,
                     eventNo,
                     procId);
    }

    /* Verify received parameters and flag if error. */
    if (procId >= multiproc_get_num_processors()) {
        Osal_printf ("*****Data integrity mismatch*****\n"
                 "    Expected procId: < [%d]\n"
                 "    Received procId: [%d]\n",
                 multiproc_get_num_processors(),
                 procId);
    }
    else if (lineId != NOTIFYAPP_LINEID) {
        Osal_printf ("*****Data integrity mismatch*****\n"
                 "    Expected lineId: [%d]\n"
                 "    Received lineId: [%d]\n",
                 NOTIFYAPP_LINEID,
                 lineId);
    }
    else if (   (eventNo < NOTIFYAPP_EVENT_NO)
             || (eventNo >= (NOTIFYAPP_EVENT_NO + NOTIFYAPP_NUMEVENTS))) {
        Osal_printf ("*****Data integrity mismatch*****\n"
                 "    Expected eventNo: between [%d] & [%d]\n"
                 "    Received eventNo: [%d]\n",
                 NOTIFYAPP_EVENT_NO,
                 NOTIFYAPP_EVENT_NO + NOTIFYAPP_NUMEVENTS - 1,
                 eventNo);
    }
    else if ((UInt32) arg != NOTIFYAPP_ARGVALUE) {
        Osal_printf ("*****Data integrity mismatch*****\n"
                 "    Expected arg: [0x%x]\n"
                 "    Received arg: [0x%x]\n",
                 NOTIFYAPP_ARGVALUE,
                 (unsigned int)arg);
    }
    else if (payload != (eventCount - 1)) {
        Osal_printf ("*****Data integrity mismatch*****\n"
                 "    Event ID:         [%d]\n"
                 "    Expected payload: [%d]\n"
                 "    Received payload: [%d]\n",
                 eventNo,
                 (eventCount - 1),
                 payload);
    }
}


/*!
 *  @brief  Function to execute the startup for NotifyApp sample application
 *
 *  @sa     NotifyApp_callback
 */
Int
NotifyApp_startup (Void)
{
    Int32                status  = 0;
    /* Consider all processors including host processor for notify */
    UInt32               maxProcessors = multiproc_get_num_processors ();
    UInt32               i;
    UInt32               eventId;

    Osal_printf ("Entered NotifyApp_startup. Number of processors: %d\n",
                 multiproc_get_num_processors());

    /* Execute common startup functionality for all sample applications */
    SysLinkSamples_startup ();

    /* Set the slaves to run the application with. */
    status = SysLinkSamples_setToRunProcIds (NotifyApp_numProcs,
                                             NotifyApp_procId,
                                             NotifyApp_runAll);

#if !defined(__KERNEL__)
    for (i = 0 ; i < NotifyApp_numProcs ; i++) {
        if (SysLinkSamples_toRunProcId (NotifyApp_procId [i])) {
            Osal_printf ("Loading and starting procId [%d] with [%s]\n",
                         NotifyApp_procId [i],
                         NotifyApp_filePath [i]);
            status = ProcMgrApp_startup (NotifyApp_procId [i],
                                         NotifyApp_bootMode,
                                         NotifyApp_filePath [i],
                                         NotifyApp_resetVector[i]);
            Osal_printf ("ProcMgrApp_startup status [%d]\n", status);
        }
    }
#endif /* if !defined(__KERNEL__) */

    if (status >= 0) {
        /* Register for events from local as well as remote processors */
        for (i = 0; (i < maxProcessors) && (status >= 0) ; i++) {
            if ((SysLinkSamples_toRunProcId (i)) || (i == multiproc_self ())) {
                if (i != multiproc_self ()) {
                    /* Register event to receive information from RTOS-side */
                    status = notify_register_event (i,
                               NOTIFYAPP_LINEID,
                               (NOTIFYAPP_RTOSINFO_EVENT_NO + i),
                               (notify_fn_notify_cbck) NotifyApp_rtosInfocallback,
                               NULL);
                }
                for (eventId = 0 ; eventId < NOTIFYAPP_NUMEVENTS ; eventId++) {
                    NotifyApp_recvEventCount [i][eventId] = 1;
                    status = notify_register_event (i,
                                       NOTIFYAPP_LINEID,
                                       (NOTIFYAPP_EVENT_NO + eventId),
                                       (notify_fn_notify_cbck) NotifyApp_callback,
                                       (Ptr) NOTIFYAPP_ARGVALUE);
                    if (status < 0) {
                        Osal_printf ("Error in notify_register_event %d"
                                     " status [0x%x] for processor %d\n",
                                     eventId,
                                     status,
                                     i);
                    }
                    else {
                        Osal_printf ("Registered event number %d with"
                                     " Notify module for processor %d\n",
                                     (NOTIFYAPP_EVENT_NO + eventId),
                                     i);
                    }
                }
            }
        }
    }

    Osal_printf ("Leaving NotifyApp_startup. Status [0x%x]\n", status);

    return(status);
}


/*!
 *  @brief  Function to execute the NotifyApp sample application
 *
 *  @sa     NotifyApp_callback
 */
Int
NotifyApp_execute (Void)
{
    Int32  status  = 0;
    /* Consider all processors including host processor for notify */
    UInt32 maxProcessors = multiproc_get_num_processors ();
    UInt32 i = 0;
    UInt32 j;
    UInt16 procId;

    Osal_printf ("Entered NotifyApp_execute\n");

    for (procId = 0; (procId < maxProcessors) && (status >= 0) ; procId++) {
        if (   (SysLinkSamples_toRunProcId (procId))
            || (procId == multiproc_self ())) {
            Osal_printf ("\nSending events to procId %d\n", procId);
            for (i = 1 ; i <= NOTIFYAPP_NUM_TRANSFERS ; i++) {
                for (j = 0 ; j < NOTIFYAPP_NUMEVENTS ; j++) {
                    do {
                        status = notify_send_event (procId,
                                                    NOTIFYAPP_LINEID,
                                                   (NOTIFYAPP_EVENT_NO + j),
                                                   i,
                                                   TRUE);
                    } while (    (status == NOTIFY_E_NOTINITIALIZED)
                              || (status == NOTIFY_E_EVTNOTREGISTERED)
                              || (status == NOTIFY_E_EVTDISABLED));

                    if (status < 0) {
                        Osal_printf ("Error in notify_send_event for processor %d"
                                     "Status [0x%x]\n",
                                     procId,
                                     status);
                        break;
                    }
                    else {
                        if ((i % NOTIFY_PRINT_COUNT) == 0) {
                            Osal_printf ("Sent %d events to event ID %d to "
                                         "processor %d\n",
                                         i,
                                         NOTIFYAPP_EVENT_NO + j,
                                         procId);
                        }
                    }
                }
            }
        }
    }

    Osal_printf ("Leaving NotifyApp_execute\n");

    return(0);
}


/*!
 *  @brief  Function to execute the shutdown for NotifyApp sample application
 *
 *  @sa     NotifyApp_callback
 */
Int
NotifyApp_shutdown (Void)
{
    Int32  status = 0;
    UInt32 maxProcessors = multiproc_get_num_processors ();
    UInt32 i;
    UInt32 eventId;

    Osal_printf ("Entered NotifyApp_shutdown\n");

    Osal_printf ("Total notifications received: %d\n",
                 SysLogging_UserCallbackCount);

    /* Unregister for events from local as well as remote processors */
    for (i = 0; (i < maxProcessors) ; i++) {
        if ((SysLinkSamples_toRunProcId (i)) || (i == multiproc_self ())) {
            if (i != multiproc_self ()) {
                /* Unregister event to receive information from RTOS-side */
                status = notify_unregister_event (i,
                           NOTIFYAPP_LINEID,
                           (NOTIFYAPP_RTOSINFO_EVENT_NO + i),
                           (notify_fn_notify_cbck) NotifyApp_rtosInfocallback,
                           NULL);
            }
            for (eventId = 0 ; eventId < NOTIFYAPP_NUMEVENTS ; eventId++) {
                status = notify_unregister_event (i,
                                     NOTIFYAPP_LINEID,
                                     (NOTIFYAPP_EVENT_NO + eventId),
                                     (notify_fn_notify_cbck)NotifyApp_callback,
                                     (Ptr) NOTIFYAPP_ARGVALUE);
                if (status < 0) {
                    Osal_printf ("Error in notify_unregister_event %d"
                                 " status [0x%x] for processor %d\n",
                                 eventId,
                                 status,
                                 i);
                }
                else {
                    Osal_printf ("Unregistered event number %d with"
                                 " Notify module for processor %d\n",
                                 (NOTIFYAPP_EVENT_NO + eventId),
                                 i);
                }
            }
        }
    }

    Osal_printf ("Leaving NotifyApp_shutdown\n");

    return(0);

}
