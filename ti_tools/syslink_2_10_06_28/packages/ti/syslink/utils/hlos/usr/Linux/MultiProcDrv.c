/*
 *  @file   MultiProcDrv.c
 *
 *  @brief     Driver for MultiProc on HLOS side
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

/* OSAL & Utils headers */
#include <ti/syslink/utils/Trace.h>

/* Module specific header files */
#include <ti/ipc/MultiProc.h>
#include <MultiProcDrvDefs.h>

/* Linux specific header files */
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */


/** ============================================================================
 *  Macros and types
 *  ============================================================================
 */
/*!
 *  @brief  Driver name for MultiProc.
 */
#define MULTIPROC_DRIVER_NAME     "/dev/syslinkipc_MultiProc"


/** ============================================================================
 *  Globals
 *  ============================================================================
 */
/*!
 *  @brief  Driver handle for MultiProc in this process.
 */
static Int32 MultiProcDrv_handle = 0;

/*!
 *  @brief  Reference count for the driver handle.
 */
static UInt32 MultiProcDrv_refCount = 0;



/** ============================================================================
 *  Functions
 *  ============================================================================
 */
/*!
 *  @brief  Function to open the MultiProc driver.
 *
 *  @sa     MultiProcDrv_close
 */
Int
MultiProcDrv_open (Void)
{
    Int status      = MultiProc_S_SUCCESS;
    int osStatus    = 0;

    GT_0trace (curTrace, GT_ENTER, "MultiProcDrv_open");

    if (MultiProcDrv_refCount == 0) {
        /* TBD: Protection for refCount. */
        MultiProcDrv_refCount++;

        MultiProcDrv_handle = open (MULTIPROC_DRIVER_NAME,
                                             O_SYNC | O_RDWR);
        if (MultiProcDrv_handle < 0) {
            perror (MULTIPROC_DRIVER_NAME);
            /*! @retval MultiProc_E_OSFAILURE
             *          Failed to open MultiProc driver with OS
             */
            status = MultiProc_E_OSFAILURE;
            GT_setFailureReason (curTrace,
                                 GT_4CLASS,
                                 "MultiProcDrv_open",
                                 status,
                                 "Failed to open MultiProc driver"
                                 " with OS!");
        }
        else {
            osStatus = fcntl (MultiProcDrv_handle,
                              F_SETFD,
                              FD_CLOEXEC);
            if (osStatus != 0) {
                /*! @retval MultiProc_E_OSFAILURE
                 *          Failed to set file descriptor flags
                 */
                status = MultiProc_E_OSFAILURE;
                GT_setFailureReason (curTrace,
                                     GT_4CLASS,
                                     "MultiProcDrv_open",
                                     status,
                                     "Failed to set file descriptor flags!");
            }
        }
    }
    else {
        MultiProcDrv_refCount++;
    }


    GT_1trace (curTrace, GT_LEAVE, "MultiProcDrv_open", status);

    /*! @retval MultiProc_S_SUCCESS Operation successfully completed. */
    return status;
}


/*!
 *  @brief  Function to close the MultiProc driver.
 *
 *  @sa     MultiProcDrv_open
 */
Int
MultiProcDrv_close (Void)
{
    Int status      = MultiProc_S_SUCCESS;
    int osStatus    = 0;

    GT_0trace (curTrace, GT_ENTER, "MultiProcDrv_close");

    /* TBD: Protection for refCount. */
    MultiProcDrv_refCount--;
    if (MultiProcDrv_refCount == 0) {
        osStatus = close (MultiProcDrv_handle);
        if (osStatus != 0) {
            perror ("MultiProc driver close: ");
            /*! @retval MultiProc_E_OSFAILURE Failed to open
             *          MultiProc driver with OS
             */
            status = MultiProc_E_OSFAILURE;
            GT_setFailureReason (curTrace,
                                 GT_4CLASS,
                                 "MultiProcDrv_close",
                                 status,
                                 "Failed to close MultiProc driver"
                                 " with OS!");
        }
        else {
            MultiProcDrv_handle = 0;
        }
    }

    GT_1trace (curTrace, GT_LEAVE, "MultiProcDrv_close", status);

    /*! @retval MultiProc_S_SUCCESS Operation successfully completed. */
    return status;
}


/*!
 *  @brief  Function to invoke the APIs through ioctl.
 *
 *  @param  cmd     Command for driver ioctl
 *  @param  args    Arguments for the ioctl command
 *
 *  @sa
 */
Int
MultiProcDrv_ioctl (UInt32 cmd, Ptr args)
{
    Int status      = MultiProc_S_SUCCESS;
    int osStatus    = 0;

    GT_2trace (curTrace, GT_ENTER, "MultiProcDrv_ioctl", cmd, args);

    osStatus = ioctl (MultiProcDrv_handle, cmd, args);
    if (osStatus < 0) {
    /*! @retval MultiProc_E_OSFAILURE Driver ioctl failed */
        status = MultiProc_E_OSFAILURE;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "MultiProcDrv_ioctl",
                             status,
                             "Driver ioctl failed!");
    }
    else {
        /* First field in the structure is the API status. */
        status = ((MultiProcDrv_CmdArgs *) args)->apiStatus;
    }

    GT_1trace (curTrace, GT_LEAVE, "MultiProcDrv_ioctl", status);

    /*! @retval MultiProc_S_SUCCESS Operation successfully completed. */
    return status;
}



#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
