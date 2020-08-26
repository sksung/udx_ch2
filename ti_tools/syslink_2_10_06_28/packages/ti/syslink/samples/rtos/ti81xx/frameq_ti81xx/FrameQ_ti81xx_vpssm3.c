/*
 *  @file   FrameQ_ti81xx_vpssm3.c
 *
 *  @brief      Sample application for FrameQ. Shows the API calling sequence
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


#include <xdc/std.h>
#include <string.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Assert.h>

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/gates/GateMutex.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>

#include <ti/ipc/SharedRegion.h>
#include <ti/ipc/NameServer.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/ipc/Ipc.h>


#include <ti/syslink/SysLink.h>

/* Shim layer includes */
#include <ti/syslink/FrameQ.h>
#include <ti/syslink/FrameQ_ShMem.h>
#include <ti/syslink/FrameQBufMgr_ShMem.h>
#include <ti/syslink/FrameQBufMgr.h>

#include "FrameQ_sample.h"

/*  ------------------------To get globals from .cfg Header ******************/
#include <xdc/cfg/global.h>

#include <ti/sysbios/hal/ammu/AMMU.h>

#define IPC_BUFFER_ALIGN(x, y) (UInt32)((UInt32)((x + y - 1) / y) * y)

Void tsk_func(UArg arg0, UArg arg1);
Void tsk_WriterFunc(UArg arg0, UArg arg1);
Void tsk_ReaderFunc(UArg arg0, UArg arg1);

//#define TRACE_FRAME_READ
//#define TRACE_FRAME_WRITES

static WriterTaskInfo wrTaskInfo;
static ReaderTaskInfo rdTaskInfo;

/* Call back function for reader FrameQ */
Void APP_readerFrameQCallback_m3d(FrameQ_Handle handle, Ptr arg, FrameQ_NotifyMsg msg)
{
    Semaphore_post((Semaphore_Object*)arg);
}

/* Call back function for writer FrameQ.
 * Call back will be invoked by FrameQBufMgr when free buffers are available
 */
Void APP_writerFrameQCallback_m3d(FrameQBufMgr_Handle handle, Ptr arg, FrameQ_NotifyMsg msg)
{
    Semaphore_post((Semaphore_Object*)arg);
}

Void APPNotify_callbackFxn (UInt16 procId,
                            UInt16 lineNo,
                            UInt32 eventNo,
                            UArg   arg,
                            UInt32 payload)
{
    Semaphore_post((Semaphore_Object*)arg);
}

Char   tempStr[80];

Int32 APP_ipcInit()
{
    Int32                       status = 0;
//    UInt16                      localProcId;
    UInt16                      remoteProcId;
    /*
     *  Need to define the shared region. The IPC modules use this
     *  to make portable pointers. All processors need to add this
     *  same call with their base address of the shared memory region.
     *  If the processor cannot access the memory, do not add it.
     */
    /* Need to zero out the shared memory only if initSharedMemory is set to
     * 1 in cfg file
     */
    if (ipcWithHOST == 1) {
        remoteProcId = MultiProc_getId("HOST");
        do {
            status = Ipc_attach(remoteProcId);
        } while (status < 0);

    }

    if (ipcWithDSP == 1) {
        remoteProcId = MultiProc_getId("DSP");
        do {
            status = Ipc_attach(remoteProcId);
        } while (status < 0);
    }

    if (ipcWithVIDEOM3 == 1) {
        remoteProcId = MultiProc_getId("VIDEO-M3");
        do {
            status = Ipc_attach(remoteProcId);
        } while (status < 0);
    }


    return (status);

}


int main()
{
    Task_Handle             tskHandle;
    Task_Params             tskParams;
    Int32                   status;

    Task_Params_init(&tskParams);
    tskParams.stackSize = 0x2000;
    tskHandle = Task_create (tsk_func,
                             &tskParams,
                             NULL);
    if (tskHandle == NULL) {
        System_printf ( "ERROR: Failed to crate task tsk0_func \n");
    }


    status = Ipc_start();
    if (status < 0) {
        System_printf ( "ERROR: Ipc_start Failed status 0x%x \n",status);
    }
    BIOS_start();
    return (0);
}


/*
 *  ======== tsk_func ========
 *  Calls the  FrameQ  setup API.and Spwans tasks to talk to M3Vido and VPSSM3
 */
Void tsk_func(UArg arg0, UArg arg1)
{
    Task_Handle             tskWriterHandle;
    Task_Handle             tskReaderHandle;
    Task_Params             tskParams;
    Int32                   status;


    System_printf ("Entered tsk_func()\n");
    
    SysLink_setup();

    status = APP_ipcInit();

    if (status < 0) {
       System_printf ( "ERROR: APP_ipcInit Failed \n");
       return;
    }

    /* Spawn the tasks */
    if(ipcWithDSP== 1) {
        /* Create the task  to produce frames to DSP */
        Task_Params_init(&tskParams);
        tskParams.stackSize = 0x2000;
        strcpy(wrTaskInfo.frmQBufMgrname,FRAMEQBUFMGR_INST3_NAME);
        strcpy(wrTaskInfo.frmQName,FRAMEQ_INST3_NAME);
        /* let tasks create it internally */
        wrTaskInfo.semHandle = NULL;
        tskParams.arg1 = (UArg)&wrTaskInfo;
        tskWriterHandle = Task_create (tsk_WriterFunc,
                                       &tskParams,
                                       NULL);
        if (tskWriterHandle == NULL) {
            System_printf ( "ERROR: Failed to crate task tsk_WriterFunc \n");
        }
    }

    if(ipcWithVIDEOM3== 1) {
        /* Create a task to retrieve frames from Video */
        Task_Params_init(&tskParams);
#if defined SYSLINK_USE_TILER
        tskParams.stackSize = 0x20000;
#else
        tskParams.stackSize = 0x4000;
#endif
        strcpy(rdTaskInfo.frmQBufMgrname,FRAMEQBUFMGR_INST2_NAME);
        strcpy(rdTaskInfo.frmQName,FRAMEQ_INST2_NAME);
        /* let tasks create it internally */
        rdTaskInfo.semHandle = NULL;

        tskParams.arg0 = (UArg)&rdTaskInfo;
        tskReaderHandle = Task_create (tsk_ReaderFunc,
                                       &tskParams,
                                       NULL);
        if (tskReaderHandle == NULL) {
            System_printf ( "ERROR: Failed to crate task tsk_WriterFunc \n");
        }
    }

    System_printf ("Leave tsk_func()\n");
}


/*
 *  ======== tsk_WriterFunc ========
 */
Void tsk_WriterFunc(UArg arg0, UArg arg1)
{
    Int32                   status          = 0;
    UInt32                  i               = 0;
    FrameQBufMgr_Handle     bufMgrHandle;
    FrameQBufMgr_ShMem_Params instParams;
    FrameQ_ShMem_Params     frmQInstParams;
    FrameQ_Handle           frmQCrehandle;
    FrameQ_Handle           frmQWriterhandle;
    Uint32                  bufMgrId;
    FrameQ_Frame           frame         = NULL;
    UInt32                  j;
    UInt8                   *frmBuf;
    UInt32                  frmCnt;
    Semaphore_Params        semParams;
    Error_Block             eb;
    UInt32                  headerBufChunkSize;
    UInt32                  frmBufChunkSize;
    UInt32                  lBaseHeaderSize;
    UInt32                  k;
    FrameQ_NotifyParams     frmQNotifyParams;
    FrameQ_ShMem_OpenParams frmQOpenParams;
    WriterTaskInfo          *taskInfo = &wrTaskInfo;
//    WriterTaskInfo          *taskInfo = arg0;

    System_printf ("Entered tsk_WriterFunc()\n");
    Error_init (&eb);
    /* Create Binary Semaphore for FramQ notifications*/
    Semaphore_Params_init (&semParams);
    semParams.mode = Semaphore_Mode_COUNTING;
    taskInfo->semHandle = Semaphore_create (0, &semParams, &eb);
    if (taskInfo->semHandle == NULL) {
        Error_check (&eb);
        System_printf ("Failed to Create the semaphore exiting ....%s: %d :\n",
                       __FILE__, __LINE__);
        return;
    }
    Notify_registerEvent(MultiProc_getId ("DSP"),
                         0,
                        APPNOTIFY_EVENT_NO ,
                        APPNotify_callbackFxn,
                        (UArg) taskInfo->semHandle);
   /* Get the default values for the FrameQBufMgr instance params */
    FrameQBufMgr_ShMem_Params_init(&instParams);

    /* Set the create paramters common to all the implementations */

    /* Assign the string pointer of the instance name */
    instParams.commonCreateParams.size = sizeof(FrameQBufMgr_ShMem_Params);
    instParams.commonCreateParams.name = taskInfo->frmQBufMgrname;
    /* Set the ShMem implementation  for this FrameQBufMgr instance */
    instParams.commonCreateParams.ctrlInterfaceType =
                                                     FrameQBufMgr_INTERFACE_SHAREDMEM;
    instParams.headerInterfaceType =
                                                     FrameQBufMgr_HDRINTERFACE_SHAREDMEM;
#if defined(TILER)
    instParams.bufInterfaceType = FrameQBufMgr_INTERFACE_TILERMEM;
#else
    instParams.bufInterfaceType = FrameQBufMgr_INTERFACE_SHAREDMEM ;
#endif

    /*Set the ShMem specific paramters */

    /* Configure it for one free frame pool */
    instParams.numFreeFramePools = 1u;

    for (i = 0; i < instParams.numFreeFramePools; i++) {
        /* How many frames in this pool */
        instParams.numFreeFramesInPool[i] = 10;
        /* How many extra header buffers in this pool
         * For dup purposes.
         */
        instParams.numFreeHeaderBufsInPool[i] = 5u;

        /* How many frame buffers  frame should contain.
         */
        instParams.numFrameBufsInFrame[i] = 1u;

        /* Calculate the base frame header size for the frame containing
         * instParams.numFrameBufsInFrame[i].
         */
         lBaseHeaderSize =
              FrameQBufMgr_getBaseHeaderSize(instParams.numFrameBufsInFrame[i]);

         /* Align base header size to cache aligend */
        instParams.frameHeaderBufSize[i] = IPC_BUFFER_ALIGN(lBaseHeaderSize,
                                            SharedRegion_getCacheLineSize(
                                                      SHAREDREG_1_ENTRYID));
        /* What are the sizes of frame buffers */

#if defined(TILER)
        for (k = 0; k < instParams.numFrameBufsInFrame[i]; k++) {
            instParams.frameBufParams[i][k].pixelFormat  = PIXEL_FMT_8BIT;
            instParams.frameBufParams[i][k].width        = 8;
            instParams.frameBufParams[i][k].height       = 8;
            //instParams.frameBuf[i][k].stride       = 4096;
       }
#else
       for (k = 0; k < instParams.numFrameBufsInFrame[i]; k++) {
            instParams.frameBufParams[i][k].size = IPC_BUFFER_ALIGN(
                                                   1024u,
                                          SharedRegion_getCacheLineSize(
                                                      SHAREDREG_1_ENTRYID));
        }
#endif

    }
    /* Pass the shared region id  to allocate internal shared control structures
     * using shared region that is cache enable flag set to TRUE
     * because we need cache operations between VPSSM3 and DSP
     */
    instParams.regionId = SHAREDREG_0_ENTRYID;
    /* Pass the shared region id  to allocate frame Headers.
     * using shared region that is cache enable flag set to TRUE
     * because we need cache operations between VPSSM3 and DSP
     */
    instParams.hdrBuf_regionId = SHAREDREG_0_ENTRYID;
    /* Pass the shared region id  to allocate frame Frame buffers.
     * using shared region that is cache enable flag set to TRUE
     * because we need cache operations between VPSSM3 and DSP
     */
    instParams.frmBuf_regionId = SHAREDREG_0_ENTRYID;


    instParams.localProtect    = APP_INST_LOCALPROTECTION;
    instParams.remoteProtect   = GateMP_RemoteProtect_SYSTEM;

    /* Get the caller processor id */
    instParams.cpuAccessFlags   = (
                                FrameQBufMgr_FRAMEBUF0_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF1_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF2_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF3_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF4_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF5_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF6_CPUACCESS |
                                FrameQBufMgr_FRAMEBUF7_CPUACCESS);


    instParams.sharedAddrSize = FrameQBufMgr_ShMem_sharedMemReq (
                                                           &instParams,
                                                           &headerBufChunkSize,
                                                           &frmBufChunkSize);
    System_printf ("Required memory for FrameQ bufMgr is  \n"
                   " For Control structure:[0x%x]\n"
                   " For Frame Headers    :[0x%x]\n"
                   " For Frame Buffers    :[0x%x]\n",
                    instParams.sharedAddrSize,
                    headerBufChunkSize,
                    frmBufChunkSize);
    instParams.numNotifyEntries = 1;/* Only one client( FrameQ writer) is going
                                     * to use notifications of FrameQBufMgr
                                     */
    do {
        bufMgrHandle =  FrameQBufMgr_create(&instParams);
        if (bufMgrHandle == NULL) {
            System_printf ("FrameQBufMgr_create  failed for %s \n",
                           instParams.commonCreateParams.name);
        }
    } while (bufMgrHandle == NULL);

    System_printf ("Created FrameQBufMgr %s:bufMgrHandle 0x%x\n",
                   taskInfo->frmQBufMgrname,
                   bufMgrHandle);
    /* Get id for the  bufMgrHandle */
    bufMgrId = FrameQBufMgr_getId (bufMgrHandle);
    System_printf ("VPSSM3 writer bufMgrId 0x%x\n", bufMgrId);


    /**************** FrameQ instance creation **********************/
    /* Get the default values for the FrameQ instance params */
    FrameQ_ShMem_Params_init(&frmQInstParams);

    frmQInstParams.commonCreateParams.name = taskInfo->frmQName;
    frmQInstParams.commonCreateParams.size = sizeof(FrameQ_ShMem_Params);
    frmQInstParams.commonCreateParams.ctrlInterfaceType =
                                                     FrameQ_INTERFACE_SHAREDMEM;
    /* Set it for  only one reader */
    frmQInstParams.numReaders = 1; /* Set it for one reader  */
    frmQInstParams.numQueues  = 1; /* Set it for one queue for reader*/
    frmQInstParams.cpuAccessFlags = (FrameQ_FRAMEBUF0_CPUACCESS |
                                     FrameQ_FRAMEBUF1_CPUACCESS |
                                     FrameQ_FRAMEBUF2_CPUACCESS |
                                     FrameQ_FRAMEBUF3_CPUACCESS |
                                     FrameQ_FRAMEBUF4_CPUACCESS |
                                     FrameQ_FRAMEBUF5_CPUACCESS |
                                     FrameQ_FRAMEBUF6_CPUACCESS |
                                     FrameQ_FRAMEBUF7_CPUACCESS);

    frmQInstParams.localProtect  = APP_INST_LOCALPROTECTION;
    frmQInstParams.remoteProtect = GateMP_RemoteProtect_SYSTEM;
    /* Pass the name of the FrameQBufMgr  to be used in this FrameQ*/
    frmQInstParams.frameQBufMgrName = taskInfo->frmQBufMgrname;

    frmQInstParams.sharedAddrSize = FrameQ_ShMem_sharedMemReq (&frmQInstParams);
    System_printf ("Required Memory for FrameQ :[0x%x] \n",
                    FrameQ_ShMem_sharedMemReq (&frmQInstParams));

    /* Pass the shared region id  to allocate internal shared control structures
     * using shared region that is cache enable flag set to TRUE
     * because we need cache operations between VPSSM3 and DSP
     */
    frmQInstParams.regionId = SHAREDREG_0_ENTRYID;
    do {
        frmQCrehandle = FrameQ_create (&frmQInstParams);
        if (frmQCrehandle == NULL) {
            System_printf ("FrameQ_create  failed for %s \n",
                           frmQInstParams.commonCreateParams.name);
        }
    } while (frmQCrehandle == NULL);

    if (frmQCrehandle != NULL) {
        System_printf ("Created FrameQ  %s \n",taskInfo->frmQName);
    }
   /**************** Open FrameQ instance in write mode  **********************/
    /* Open using name */
    frmQOpenParams.commonOpenParams.name = taskInfo->frmQName;
    frmQOpenParams.commonOpenParams.openMode = FrameQ_MODE_WRITER;
    frmQOpenParams.commonOpenParams.cpuAccessFlags = (
                                            FrameQ_FRAMEBUF0_CPUACCESS |
                                            FrameQ_FRAMEBUF1_CPUACCESS |
                                            FrameQ_FRAMEBUF2_CPUACCESS |
                                            FrameQ_FRAMEBUF3_CPUACCESS |
                                            FrameQ_FRAMEBUF4_CPUACCESS |
                                            FrameQ_FRAMEBUF5_CPUACCESS |
                                            FrameQ_FRAMEBUF6_CPUACCESS |
                                            FrameQ_FRAMEBUF7_CPUACCESS);

    do {
        status = FrameQ_open (&frmQOpenParams, &frmQWriterhandle);
        if (status < 0){
            System_printf ("ERROR:FrameQ_open instance failed for writer."
                           "status: 0x%x \n",
                           status);

        }
        else {
             System_printf ("FrameQ_open  success for writer."
                            "status: 0x%x\n",
                            status);
        }

    } while ((frmQWriterhandle == NULL) || (status < 0));

    status = FrameQ_getNumFreeFrames(frmQWriterhandle, &i);
    if  (status >= 0) {
        System_printf ("FrameQ writer:NumBer of Free Fraemes available"
                       "to allocate %d\n", i);
    }
    /* Sending synchonization notification */
    status = Notify_sendEvent(MultiProc_getId ("DSP"),
                              0,
                              APPNOTIFY_EVENT_NO,
                              0,
                              TRUE);
    if  (status >= 0) {
        System_printf ("FrameQ writer:Sent Synchronizatioon notification"
                   "from FrameQReader on DSP\n");
    }

    Error_print(&eb);
    Error_init(&eb);
  /* Register call back fucntion   with the FrameQ for free frames */
    frmQNotifyParams.notifyType = FrameQ_NOTIFICATION_ONCE;
    frmQNotifyParams.cbFxnPtr    =(FrameQ_NotifyFunc)APP_writerFrameQCallback_m3d;
    frmQNotifyParams.watermark = 1; /* Water mark one free frame */
    frmQNotifyParams.cbContext = taskInfo->semHandle; /*Context pointer */
    frmQNotifyParams.cbClientHandle = frmQWriterhandle;

   /* Register call back fucntion   with the FrameQbufMgr created */
    status = FrameQ_registerNotifier (frmQWriterhandle, &frmQNotifyParams);
    if (status < 0) {
     System_printf ("ERROR: Failed to register call back with FrameQ writer"
                    "For free buffers.status: 0x%x\n",
                    status);
    }
    /* Send force notification to reader client */
    do {
        status = FrameQ_sendNotify (frmQWriterhandle,
                                    APP_FRAMEQ_FORCE_NOTIFCATION_MSG);
        if (status < 0) {
             System_printf ("ERROR: Failed to send force notification to reader"
                            "status: 0x%x\n",
                             status);
            /* Sleep for a while before trying again. */
            Task_sleep (10);
        }
        else {
            System_printf ("FrameQ Writer: Sent force notification to reader"
                           "status: 0x%x\n",
                            status);
        }

    }
    while (status < 0);


   /* Allocate frame by writer */
    for (i = 0; i <  ITER_COUNT; i++) {
        /* Input frame pointer to  First Alloc call   should be set to NULL.
         * If alloc fails due  insufficient buffers. Successive alloc calls
         * should pass the same frame  pointer that is just returned from the
         * previous call.
         * This allows alloc to fully cook the frame with frame header and frame
         * buffer.
         */
        do {
            status = FrameQ_alloc (frmQWriterhandle,&frame);
            if (status < 0) {
#if defined TRACE_FRAME_WRITES
                System_printf ("FrameQWriter:FrameQ_alloc Failed."
                               "Waiting for Notification.After itercount %d.\n",
                               i);
#endif
                Semaphore_pend(taskInfo->semHandle, BIOS_WAIT_FOREVER);
#if defined TRACE_FRAME_WRITES
                System_printf ("FrameQWriter:Got notification...\n");
#endif
            }
       } while (status < 0);
#if defined TRACE_FRAME_WRITES
       System_printf ("FrameQWriter:FrameQ_alloc succesful. "
                      "status:0x%08x:IterCount %d\n",
                      status,
                      i);
#endif
       if (frame != NULL){
             /* Process the retrieved frame here */
#if defined TRACE_FRAME_WRITES
            System_printf ("Frame Address          :0x%x\n",frame);
#endif
            frmCnt = FrameQ_getNumFrameBuffers (frame);
#if defined TRACE_FRAME_WRITES
            System_printf ("Number Of Frame Buffers:%d\n",frmCnt );
#endif

            for (j = 0; j < frmCnt; j++) {
                frmBuf = FrameQ_getFrameBuffer(frame, j);
#if defined TRACE_FRAME_WRITES
                System_printf ("FrameBuffer Address :0x%x\n",(UInt32)frmBuf);
                 /* Here populte the frame extended header and frame buffers */
                  System_printf ("FrameBuffer size :0x%x\n",
                                 FrameQ_getFrameBufSize(frame, j) );
#endif
                  status = FrameQ_setFrameBufDataStartOffset (frame ,j, 0);
                  status = FrameQ_setFrameBufValidSize(frame , j, 4);
                  frmBuf[0] = 0x2A;
                  frmBuf[1] = 0x2B;
                  frmBuf[2] = 0x2C;
                  frmBuf[3] = 0x2D;
            }
            /* Free the frame  */
            if (frame != NULL) {
                 /* Put the frame in to FrameQ */
                 status = FrameQ_put (frmQWriterhandle, frame);
           }
        }
        if (((i % 100) == 0) && (i > 0)) {
           System_printf ("FrameQWriter:Transferred %d frames \n", i);
        }
    }
    if (i == ITER_COUNT) {
       System_printf ("FrameQWriter:Transferred %d frames \n", i);
    }
    /* Wait for  Reader to consume all the frames */
    do {
       status = FrameQ_getNumFrames(frmQWriterhandle, &frmCnt);
    } while (frmCnt != 0);

   /* Close the  FrameQ handles */
    status = FrameQ_close (&frmQWriterhandle);

    /* Delete is force ful. So wait for the other side to finish up */
    Semaphore_pend( taskInfo->semHandle, BIOS_WAIT_FOREVER);
    System_printf("\n******APPNotify_callbackFxn. *****\n");

     /* Delete FrameQ */
    FrameQ_delete (&frmQCrehandle);

    /* Delete the FrameQ BufMgr instance */
    FrameQBufMgr_delete (&bufMgrHandle);

    System_printf ("Leave tsk_WriterFunc()\n");
}

/* Reader task  retrieves frames from VIDEOM3*/
Void tsk_ReaderFunc(UArg arg0, UArg arg1)
{
    Int32                   status        = 0;
    UInt32                  i             = 0;
    /* FrameQBufMgr instance params */
    FrameQ_Handle           frmQReaderHandle;
#if defined TRACE_FRAME_READ
    UInt8                   *frmbuf;
    UInt32                  frmCnt;
    UInt32                  j;
#endif
    FrameQ_Frame            outFrame;
    Semaphore_Params        semParams;
    Error_Block             eb;
    ReaderTaskInfo          *taskInfo = &rdTaskInfo;
    FrameQ_ShMem_OpenParams frmQOpenParams;
    FrameQ_NotifyParams     frmQNotifyParams;

//  ReaderTaskInfo          *taskInfo = arg0;

    Error_init (&eb);
    System_printf ( " Entered tsk_ReaderFunc\n");

    /* Create Binary Semaphore for FramQ notifications*/
    Semaphore_Params_init (&semParams);
    semParams.mode = Semaphore_Mode_COUNTING;
    taskInfo->semHandle = Semaphore_create (0, &semParams, &eb);
    if (taskInfo->semHandle == NULL) {
        Error_check (&eb);
        System_printf ("Failed to Create the semaphore exiting ....%s: %d :\n",
                       __FILE__, __LINE__);
        return;
    }
    Notify_registerEvent(MultiProc_getId ("VIDEO-M3"),
                         0,
                         APPNOTIFY_EVENT_NO ,
                         APPNotify_callbackFxn,
                        (UArg) taskInfo->semHandle);
    /* Retrieve frame from FrameQ */
    System_printf ("FrameQReader:Waiting for Synchronizatioon notification"
                   "from FrameQ writer on VIDEOM3\n");
    Semaphore_pend(taskInfo->semHandle, BIOS_WAIT_FOREVER);
    System_printf ("FrameQReader:Got Synchronizatioon notification from FrameQ "
                   "writer on VIDEOM3\n");

    /**************** Open FrameQ instance in Read  mode  **********************/
    /* Allocate frmQInstParams.sharedAddrSize memory from shared region for this
     * instance
     */
    frmQOpenParams.commonOpenParams.name = taskInfo->frmQName;
    frmQOpenParams.commonOpenParams.openMode = FrameQ_MODE_READER;
    frmQOpenParams.commonOpenParams.cpuAccessFlags = (
                                            FrameQ_FRAMEBUF0_CPUACCESS |
                                            FrameQ_FRAMEBUF1_CPUACCESS |
                                            FrameQ_FRAMEBUF2_CPUACCESS |
                                            FrameQ_FRAMEBUF3_CPUACCESS |
                                            FrameQ_FRAMEBUF4_CPUACCESS |
                                            FrameQ_FRAMEBUF5_CPUACCESS |
                                            FrameQ_FRAMEBUF6_CPUACCESS |
                                            FrameQ_FRAMEBUF7_CPUACCESS);
    do {
        status  = FrameQ_open (&frmQOpenParams,&frmQReaderHandle);
        if ((frmQReaderHandle == NULL)|| (status < 0)){
            System_printf ("ERROR:Failed to open FrameQ in Read mode."
                           "status 0x%x\n",
                           status);
       }
    } while (frmQReaderHandle == NULL);

    if (frmQReaderHandle != NULL){
        System_printf ("Opened FrameQ in Read mode\n");
    }

    frmQNotifyParams.notifyType = FrameQ_NOTIFICATION_ONCE;
    frmQNotifyParams.cbFxnPtr   =
                                (FrameQ_NotifyFunc)APP_readerFrameQCallback_m3d;
    frmQNotifyParams.watermark = 1; /* Water mark one frame */
    frmQNotifyParams.cbContext = taskInfo->semHandle; /*Context pointer */
    frmQNotifyParams.cbClientHandle = frmQReaderHandle;
    status = FrameQ_registerNotifier (
                                      frmQReaderHandle,&frmQNotifyParams);
    /* Retrieve frame from FrameQ */
    System_printf ("FrameQReader:Waiting for Force notification from FrameQ "
                   "writer\n");
    Semaphore_pend(taskInfo->semHandle, BIOS_WAIT_FOREVER);
    System_printf ("FrameQReader:Got Force notification from FrameQ "
                   "writer\n");

  /* Retrieve frame from FrameQ */
    for (i = 0; i <  ITER_COUNT; i++) {
        do {
            status = FrameQ_get (frmQReaderHandle, &outFrame );
            if (status < 0) {
#if defined TRACE_FRAME_READ
                System_printf ("FrameQReader:FrameQ_get Failed."
                               "Waiting for Notification...\n");
#endif
                Semaphore_pend(taskInfo->semHandle, BIOS_WAIT_FOREVER);
#if defined TRACE_FRAME_READ
                System_printf ("FrameQReader:Got notification...\n");
#endif
            }

       } while ((status < 0));
#if defined TRACE_FRAME_READ
       System_printf ("FrameQ Reader:FrameQ_get succesful."
                      "status:0x%08x:IterCount %d\n",
                      status,
                      i);
#endif
       if (outFrame != NULL){
             /* Process the retrieved frame here */
#if defined TRACE_FRAME_READ
            System_printf ("Frame Address          :0x%x\n",outFrame);
            frmCnt = FrameQ_getNumFrameBuffers (outFrame);
            System_printf ("Number Of Frame Buffers:%d\n",frmCnt );
            for (j = 0; j < frmCnt; j++) {
                frmbuf = FrameQ_getFrameBuffer(outFrame, j);
                System_printf ("FrameBuffer Address :0x%x\n",frmbuf);
                System_printf ("FrameBuffer Byte  0 val:0x%x\n",frmbuf[0]);
                System_printf ("FrameBuffer Byte  1 val:0x%x\n",frmbuf[1]);
                System_printf ("FrameBuffer Byte  2 val:0x%x\n",frmbuf[2]);
                System_printf ("FrameBuffer Byte  3 val:0x%x\n",frmbuf[3]);

            }
#endif
            /* Free the frame  */
            status = FrameQ_free (frmQReaderHandle, outFrame );
        }
        if (((i % 100) == 0) && (i > 0)) {
           System_printf ("FrameQReader:Received %d frames \n", i);
        }
    }
    if (i == ITER_COUNT) {
       System_printf ("FrameQReader:Received %d frames \n", i);
    }
    status = FrameQ_close (&frmQReaderHandle);
    if (status >= 0) {
        System_printf ("FrameQ_close successful. status :0x%x\n",status);
    }
    else {
        System_printf ("FrameQ_close failed.status :0x%x\n",status);
    }

    status = Notify_sendEvent(MultiProc_getId ("VIDEO-M3"),
                              0,
                              APPNOTIFY_EVENT_NO,
                              0,
                              TRUE);
    if (status >= 0) {
        System_printf ("Notify_sendEvent for synchronization to Video is "
                       "successful. status :0x%x\n",
                       status);
    }
    else {
        System_printf ("Notify_sendEvent for synchronization to Video is "
                       "Failed.status :0x%x\n",
                       status);
    }
    System_printf ( " Leaving tsk_ReaderFunc ...\n");
}


Void clearAmmu()
{
    AMMU_mmu.MAINT = 0x00;
}

