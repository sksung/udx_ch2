/*
 *  @file   MessageQDrv.c
 *
 *  @brief      OS-specific implementation of MessageQ driver for Qnx
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
#include <ti/ipc/MessageQ.h>
#include <MessageQDrvDefs.h>

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
 *  @brief  Driver name for MessageQ.
 */
#define MESSAGEQ_DRIVER_NAME     "/dev/syslinkipc/MessageQ"


/** ============================================================================
 *  Globals
 *  ============================================================================
 */
/*!
 *  @brief  Driver handle for MessageQ in this process.
 */
/*!
 *  @brief  Reference count for the driver handle.
 */
extern Int32 IpcDrv_handle;

extern Int32 OsalDrv_handle;

/** ============================================================================
 *  Functions
 *  ============================================================================
 */
/*!
 *  @brief  Function to open the MessageQ driver.
 *
 *  @sa     MessageQDrv_close
 */
Int
MessageQDrv_open (Void)
{
    Int status      = MessageQ_S_SUCCESS;
   
    return status;
}


/*!
 *  @brief  Function to close the MessageQ driver.
 *
 *  @sa     MessageQDrv_open
 */
Int
MessageQDrv_close (Void)
{
    Int status      = MessageQ_S_SUCCESS;
   
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
MessageQDrv_ioctl (UInt32 cmd, Ptr args)
{
    Int status      = MessageQ_S_SUCCESS;
    int osStatus    = -1;

    GT_2trace (curTrace, GT_ENTER, "MessageQDrv_ioctl", cmd, args);

	switch (cmd) {
		
		  case CMD_MESSAGEQ_PUT:
		  {
				osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_PUT, args, sizeof(MessageQDrv_CmdArgs), NULL);
				}
		  break;
	
		  case CMD_MESSAGEQ_GET:
		  {
			osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_GET, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_COUNT:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_COUNT, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_ALLOC:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_ALLOC, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_FREE:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_FREE, args, sizeof(MessageQDrv_CmdArgs), NULL);
		  }
		  break;
	
		  case CMD_MESSAGEQ_PARAMS_INIT :
		  {
			  MessageQDrv_CmdArgs *cargs = (MessageQDrv_CmdArgs *)args;
			  iov_t	mqparamsinit_iov[2];

			  SETIOV( &mqparamsinit_iov[0], cargs, sizeof(MessageQDrv_CmdArgs) );
			  SETIOV( &mqparamsinit_iov[1], cargs->args.ParamsInit.params, sizeof(MessageQ_Params) );
				// send 1 iov, return 2 iov
			  osStatus = devctlv( IpcDrv_handle, DCMD_MESSAGEQ_PARAMS_INIT, 1, 2, mqparamsinit_iov, mqparamsinit_iov, NULL);
		  }
		  break;
	
		  case CMD_MESSAGEQ_CREATE:
		  {			  
			  MessageQDrv_CmdArgs *cargs = (MessageQDrv_CmdArgs *)args;
			  iov_t	mqcreate_iov[3];
			  int i = 0;

			  SETIOV( &mqcreate_iov[i], cargs, sizeof(MessageQDrv_CmdArgs) );
			  i++;
			  if (cargs->args.create.params) {
			      SETIOV( &mqcreate_iov[i], cargs->args.create.params, sizeof(MessageQ_Params) );
			      i++;
			  }
			  if (cargs->args.create.name) {
			      SETIOV( &mqcreate_iov[i], cargs->args.create.name, sizeof(char) * cargs->args.create.nameLen );
			      i++;
			  }

			  // send i iov, return 1 iov
		      osStatus = devctlv( IpcDrv_handle, DCMD_MESSAGEQ_CREATE, i, 1, mqcreate_iov, mqcreate_iov, NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_DELETE:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_DELETE, args, sizeof(MessageQDrv_CmdArgs), NULL);
		  }
		  break;
	
		  case CMD_MESSAGEQ_OPEN:
		  {
			  MessageQDrv_CmdArgs *cargs = (MessageQDrv_CmdArgs *)args;
			  iov_t	mqopen_iov[2];

			  SETIOV( &mqopen_iov[0], cargs, sizeof(MessageQDrv_CmdArgs) );
			  SETIOV( &mqopen_iov[1], cargs->args.open.name, sizeof(char) * cargs->args.open.nameLen );
				// send 2 iov, return 1 iov
			  osStatus = devctlv( IpcDrv_handle, DCMD_MESSAGEQ_OPEN, 2, 1, mqopen_iov, mqopen_iov, NULL);
			  }
		  break;
	
		  case CMD_MESSAGEQ_CLOSE:
		  {
		  	osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_CLOSE, args, sizeof(MessageQDrv_CmdArgs), NULL);
				}
		  break;
	
		  case CMD_MESSAGEQ_UNBLOCK:
		  {
			  osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_UNBLOCK, args, sizeof(MessageQDrv_CmdArgs), NULL);
		  }
		  break;
	
		  case CMD_MESSAGEQ_GETCONFIG:
		  {
			  MessageQDrv_CmdArgs *cargs = (MessageQDrv_CmdArgs *)args;
			  iov_t	mqgetconfig_iov[2];

			  SETIOV( &mqgetconfig_iov[0], cargs, sizeof(MessageQDrv_CmdArgs) );
			  SETIOV( &mqgetconfig_iov[1], cargs->args.getConfig.config, sizeof(MessageQ_Config) );
				// send one iov, get back 2 iov
				/* the osal_drv handle is used instead of ipcdrv_handle as the ipcdrc_handle is not yet initialized */
			  osStatus = devctlv( OsalDrv_handle, DCMD_MESSAGEQ_GETCONFIG, 1, 2, mqgetconfig_iov, mqgetconfig_iov, NULL);
		  }
		  break;
	
		  case CMD_MESSAGEQ_SETUP:
		  {
			  MessageQDrv_CmdArgs *cargs = (MessageQDrv_CmdArgs *)args;
			  iov_t	mqsetup_iov[2];

			  SETIOV( &mqsetup_iov[0], cargs, sizeof(MessageQDrv_CmdArgs) );
			  SETIOV( &mqsetup_iov[1], cargs->args.setup.config, sizeof(MessageQ_Config) );
				// send 2 iov, get back 1 iov
			  osStatus = devctlv( IpcDrv_handle, DCMD_MESSAGEQ_SETUP, 2, 1, mqsetup_iov, mqsetup_iov, NULL);
				}
		  break;
	
		  case CMD_MESSAGEQ_DESTROY:
		  {
				osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_DESTROY, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_REGISTERHEAP:
		  {
			  osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_REGISTERHEAP, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_UNREGISTERHEAP:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_UNREGISTERHEAP, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_SHAREDMEMREQ:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_SHAREDMEMREQ, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_ATTACH:
		  {
			 osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_ATTACH, args, sizeof(MessageQDrv_CmdArgs), NULL);
		}
		  break;
	
		  case CMD_MESSAGEQ_DETACH:
		  {
			  osStatus = devctl( IpcDrv_handle, DCMD_MESSAGEQ_DETACH, args, sizeof(MessageQDrv_CmdArgs), NULL);
		  }
		  break;
	
		  default:
		  {
			  /* This does not impact return status of this function, so retVal
			   * comment is not used.
			   */
			  status = MessageQ_E_INVALIDARG;
			  GT_setFailureReason (curTrace,
								   GT_4CLASS,
								   "MessageQDrv_ioctl",
								   status,
								   "Unsupported ioctl command specified");
		  }
		  break;
	  }


    if (osStatus != 0) {
        /*! @retval MessageQ_E_OSFAILURE Driver ioctl failed */
        status = MessageQ_E_OSFAILURE;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "MessageQDrv_ioctl",
                             status,
                             "Driver ioctl failed!");
    }
    else {
        /* First field in the structure is the API status. */
        status = ((MessageQDrv_CmdArgs *) args)->apiStatus;
    }

    GT_1trace (curTrace, GT_LEAVE, "MessageQDrv_ioctl", status);

    /*! @retval MessageQ_S_SUCCESS Operation successfully completed. */
    return status;
}



#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
