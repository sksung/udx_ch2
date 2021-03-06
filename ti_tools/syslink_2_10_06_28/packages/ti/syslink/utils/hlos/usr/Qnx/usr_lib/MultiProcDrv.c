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
#include "ti/syslink/Std.h"

/* OSAL & Utils headers */
#include <ti/syslink/utils/Trace.h>

/* Module specific header files */
#include <ti/ipc/MultiProc.h>
#include <MultiProcDrvDefs.h>
#include "dcmd_syslink.h"

/* QNX specific header files */
#include <sys/types.h>
#include <sys/ioctl.h>
#include <inttypes.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>



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
#define MULTIPROC_DRIVER_NAME     "/dev/syslinkipc/MultiProc"


/** ============================================================================
 *  Globals
 *  ============================================================================
 */

extern Int32 IpcDrv_handle;

extern Int32 OsalDrv_handle;

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
  
    /*! @retval MultiProc_S_SUCCESS Operation successfully completed. */
    return status;
}


/*!
 *  @brief  Function to invoke the APIs through devctl.
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

	MultiProcDrv_CmdArgs *	cargs	 = (MultiProcDrv_CmdArgs *) args;

    GT_2trace (curTrace, GT_ENTER, "MultiProcDrv_ioctl", cmd, args);

	switch (cmd) {
	
		   case CMD_MULTIPROC_SETUP:
		   {
			   iov_t setup_iov[2];

			   SETIOV( &setup_iov[0], cargs, sizeof(MultiProcDrv_CmdArgs) );
			   SETIOV( &setup_iov[1], cargs->args.setup.config, sizeof(MultiProc_Config) );

			   osStatus = devctlv( IpcDrv_handle, DCMD_MULTIPROC_SETUP, 2, 2, setup_iov, setup_iov, NULL);

				if ( osStatus != 0 ){
					status = MultiProc_E_OSFAILURE;
				}
							 
		   }
		   break;
	
		   case CMD_MULTIPROC_DESTROY:
		   {
			   	osStatus = devctl( IpcDrv_handle, DCMD_MULTIPROC_DESTROY, cargs, sizeof(MultiProcDrv_CmdArgs), NULL);

				if ( osStatus != 0 ){
					status = MultiProc_E_OSFAILURE;
				}
		   }
		   break;
		   case CMD_MULTIPROC_GETCONFIG:
		   {
  				iov_t		multiproc_getconfig_iov[2];

				MultiProc_Config *	save_multiprocconfig = (MultiProc_Config *)cargs->args.getConfig.config;
  
  				SETIOV( &multiproc_getconfig_iov[0], cargs, sizeof(MultiProcDrv_CmdArgs) );
  				SETIOV( &multiproc_getconfig_iov[1], cargs->args.getConfig.config, sizeof(MultiProc_Config) );

				/* the osal_drv handle is used instead of ipcdrv_handle as the ipcdrc_handle is not yet initialized */
				osStatus = devctlv( OsalDrv_handle, DCMD_MULTIPROC_GETCONFIG, 2, 2, multiproc_getconfig_iov, multiproc_getconfig_iov, NULL);

				if ( osStatus != 0 ){
					status = MultiProc_E_OSFAILURE;
    			}
    			else{
    				cargs->args.getConfig.config= (MultiProc_Config *) (save_multiprocconfig);    				
    			}			 
		   }
		   break;
		   case CMD_MULTIPROC_SETLOCALID:
		   		osStatus = devctl( IpcDrv_handle, DCMD_MULTIPROC_SETLOCALID, cargs, sizeof(MultiProcDrv_CmdArgs), NULL);

				if ( osStatus != 0 ){
					status = MultiProc_E_OSFAILURE;
				}	 
		   break;
		   default:
		   {
			   /* This does not impact return status of this function, so retVal
				* comment is not used.
				*/
			   status = MultiProc_E_FAIL;
			   GT_setFailureReason (curTrace,
									GT_4CLASS,
									"MultiProcDrv_ioctl",
									status,
									"Unsupported ioctl command specified");
		   }
		   break;
	
	   }

	
	if ( osStatus != 0 ){
		status = MultiProc_E_OSFAILURE;
	}
    else {
        /* First field in the structure is the API status. */
        status = ((MultiProcDrv_CmdArgs *) cargs)->apiStatus;
    }

    GT_1trace (curTrace, GT_LEAVE, "MultiProcDrv_ioctl", status);

    /*! @retval MultiProc_S_SUCCESS Operation successfully completed. */
    return status;
}



#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
