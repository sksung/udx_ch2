/*
 *  @file   OsalKfile.c
 *
 *  @brief      Linux kernel File operation interface implementation.
 *
 *              This abstracts the file operation interface in the Kernel
 *              code. All the usual operations like open, close, read, write,
 *              seek and tell are supported.
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

/* OSAL and kernel utils */
#include <OsalKfile.h>
#include <ti/syslink/utils/Trace.h>
#include <ti/syslink/utils/Memory.h>

/* Linux specific header files */
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>


#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 * =============================================================================
 */
/*!
 *  @brief   Definition of the OsalKfile object used by all OsalKfile functions.
 */
typedef struct OsalKfile_Object_tag {
    UInt32        signature; /*!<  Signature of the OsalKfile_Object object.*/
    struct file * fileDesc;  /*!< File descriptor pointer */
    Char *        fileName;  /*!< Name of the file used */
    UInt32        size;      /*!< Size of the file */
    UInt32        curPos;    /*!< Current position of file read pointer */
} OsalKfile_Object;


/* =============================================================================
 *  APIs
 * =============================================================================
 */
/*!
 *  @brief      Opens the specified file and returns the file object.
 *
 *  @param      fileName    The file to be operated upon.
 *  @param      fileMode    Mode with which the file will be operated.
 *  @param      fileHandle  Return parameter: The file object.
 *
 *  @sa         OsalKfile_close, Memory_alloc
 */
Int
OsalKfile_open (String             fileName,
                Char *             fileMode,
                OsalKfile_Handle * fileHandle)
{
    Int                 status      = OSALKFILE_SUCCESS;
    struct file *       fileDesc    = NULL;
    OsalKfile_Object *  fileObject  = NULL;
    mm_segment_t        fs;

    GT_3trace (curTrace, GT_ENTER, "OsalKfile_open",
               fileName, fileMode, fileHandle);

    GT_assert (curTrace, (fileName != NULL));
    GT_assert (curTrace, (fileMode != NULL));
    GT_assert (curTrace, (fileHandle != NULL));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (fileName == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument
                                           fileName. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_open",
                             status,
                             "NULL provided for argument fileName");
    }
    else if (fileMode == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument
                                           fileMode. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_open",
                             status,
                             "NULL provided for argument fileMode");
    }
    else if (fileMode [0] != 'r') {
        /*! @retval OSALKFILE_E_INVALIDARG Only read 'r' mode is supported. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_open",
                             status,
                             "Only read 'r' mode is supported.");
    }
    else if (fileHandle == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument
                                           fileHandle. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_open",
                             status,
                             "NULL provided for argument fileHandle");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        *fileHandle = NULL;
        fileObject = Memory_alloc (NULL, sizeof (OsalKfile_Object), 0, NULL);
#if !defined(SYSLINK_BUILD_OPTIMIZE)
        if (fileObject == NULL) {
            /*! @retval OSALKFILE_E_MEMORY Failed to allocate memory for
                                           OsalKfile object. */
            status = OSALKFILE_E_MEMORY;
            GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_open",
                             status,
                             "Failed to allocate memory for OsalKfile object.");
        }
        else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
            fs = get_fs ();
            set_fs (KERNEL_DS);

            fileDesc = filp_open (fileName, O_RDONLY, 0) ;
#if !defined(SYSLINK_BUILD_OPTIMIZE)
            if (   (IS_ERR (fileDesc))
                || (fileDesc == NULL)
                || (fileDesc->f_op == NULL)
                || (fileDesc->f_op->read == NULL)) {
                /*! @retval OSALKFILE_E_FILEOPEN Failed to open file. */
                status = OSALKFILE_E_FILEOPEN;
                GT_setFailureReason (curTrace,
                                     GT_4CLASS,
                                     "Kfile_Open",
                                     status,
                                     "Failed to open file.");
            }
            else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
                fileObject->fileDesc = fileDesc;
                fileObject->fileName = fileName;
                fileObject->curPos = 0;

                *fileHandle = (OsalKfile_Handle) fileObject;

                /* Get the file size  */
                fileDesc->f_pos = 0u;

                if (fileDesc->f_op->llseek != NULL) {
                    fileObject->size =
                                fileDesc->f_op->llseek (fileDesc, 0, SEEK_END);
                    fileDesc->f_op->llseek (fileDesc, 0, SEEK_SET);
                }
                else {
                    fileObject->size = default_llseek (fileDesc,0,SEEK_END);
                    default_llseek (fileDesc, 0, SEEK_SET);
                }
#if !defined(SYSLINK_BUILD_OPTIMIZE)
            }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

            /* If the function call failed then free the object allocated
             * earlier.
             */
            if (status < 0) {
                Memory_free (NULL, fileObject, sizeof (OsalKfile_Object));
                *fileHandle = NULL;
            }
            set_fs (fs);
#if !defined(SYSLINK_BUILD_OPTIMIZE)
        }
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace (curTrace, GT_LEAVE, "OsalKfile_open", status);

    /*! @retval OSALKFILE_SUCCESS Operation successfully completed. */
    return status;
}

/*!
 *  @brief      Closes the file represented by the specified file handle.
 *
 *  @param      fileHandle  File handle
 *
 *  @sa         OsalKfile_open, Memory_free
 */
Int
OsalKfile_close (OsalKfile_Handle * fileHandle)
{
    Int                 status      = OSALKFILE_SUCCESS;
    OsalKfile_Object *  fileObject  = NULL;
    mm_segment_t        fs;

    GT_1trace (curTrace, GT_ENTER, "OsalKfile_close", fileHandle);

    GT_assert (curTrace, (fileHandle != NULL));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (fileHandle == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument
                                           fileHandle. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_close",
                             status,
                             "NULL provided for argument fileHandle");
    }
    else if (*fileHandle == NULL) {
        /*! @retval OSALKFILE_E_HANDLE NULL file handle provided. */
        status = OSALKFILE_E_HANDLE;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_close",
                             status,
                             "NULL file handle provided.");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        fileObject = (OsalKfile_Object *) *fileHandle;
        fs = get_fs();
        set_fs (KERNEL_DS);
        filp_close (fileObject->fileDesc, NULL);
        set_fs (fs);
        Memory_free (NULL, fileObject, sizeof(OsalKfile_Object));

        /* Reset user's file handle pointer. */
        *fileHandle = NULL;
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace (curTrace, GT_LEAVE, "OsalKfile_close", status);

    /*! @retval OSALKFILE_SUCCESS Operation successfully completed. */
    return status;
}

/*!
 *  @brief      Reads the block of data from current position in the file.
 *
 *              Reads a specified number of items of specified size
 *              bytes from file to a buffer.
 *
 *  @param      fileHandle  File handle
 *  @param      buffer      Working buffer which will be populated with the read
 *                          data.
 *  @param      size        Size to be read from the file handle.
 *  @param      count       Number of the size elements to be read.
 *
 *  @sa         OsalKfile_seek, OsalKfile_tell
 */
Int
OsalKfile_read (OsalKfile_Handle fileHandle,
                Char *           buffer,
                UInt32           size,
                UInt32           count)
{
    Int                 status      = OSALKFILE_SUCCESS;
    UInt32              bytesRead   = 0;
    OsalKfile_Object*   fileObject  = (OsalKfile_Object*) fileHandle;
    mm_segment_t        fs;

    GT_4trace(curTrace, GT_ENTER,
        "--> OsalKfile_read: handle=0x%x, buffer=0x%x, size=%d, count=%d",
        fileHandle, buffer, size, count);

    GT_assert (curTrace, (fileHandle != NULL));
    GT_assert (curTrace, (buffer != NULL));
    GT_assert (curTrace, (size != 0));
    GT_assert (curTrace, (count != 0));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (fileHandle == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument
                                           fileHandle. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_read",
                             status,
                             "NULL provided for argument fileHandle");
    }
    else if (buffer == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument buffer. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_read",
                             status,
                             "NULL provided for argument buffer.");
    }
    else if (size == 0) {
        /*! @retval OSALKFILE_E_INVALIDARG Zero provided for size argument. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_read",
                             status,
                             "Zero provided for size argument.");
    }
    else if (count == 0) {
        /*! @retval OSALKFILE_E_INVALIDARG Zero provided for count argument. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_read",
                             status,
                             "Zero provided for count argument.");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        fileObject = (OsalKfile_Object*) fileHandle;
        if ((fileObject->curPos + (size * count)) > fileObject->size) {
            /*! @retval OSALKFILE_E_OUTOFRANGE Specified operation goes out of
                                               range of the file. */
            status = OSALKFILE_E_OUTOFRANGE ;
            GT_setFailureReason (curTrace,
                          GT_4CLASS,
                          "OsalKfile_read",
                          status,
                          "Specified operation goes out of range of the file.");
        }
        else {
            /* read from file */
            fs = get_fs ();
            set_fs (KERNEL_DS);

            bytesRead = fileObject->fileDesc->f_op->read (fileObject->fileDesc,
                                                buffer,
                                                (size * count),
                                                &(fileObject->fileDesc->f_pos));
            set_fs (fs);
            if (bytesRead >= 0) {
                fileObject->curPos += bytesRead;
                GT_assert (curTrace, ((bytesRead / size) == (UInt32) count));
            }
#if !defined(SYSLINK_BUILD_OPTIMIZE)
            else {
                /*! @retval OSALKFILE_E_FILEREAD Failed to read from the file */
                status = OSALKFILE_E_FILEREAD;
                GT_setFailureReason (curTrace,
                                     GT_4CLASS,
                                     "OsalKfile_read",
                                     status,
                                     "Failed to read from the file.");
            }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        }
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace(curTrace, GT_LEAVE, "<-- OsalKfile_read: 0x%x", status);

    /*! @retval OSALKFILE_SUCCESS Operation successfully completed. */
    return status;
}


/*!
 *  @brief      Repositions the file pointer according to specified arguments.
 *
 *  @param      Kernel file handle.
 *  @param      offset position from where to begin the seek.
 *  @param      pos start, end or any random location to begin seek.
 *
 *  @sa         OsalKfile_read, OsalKfile_tell
 */
Int
OsalKfile_seek (OsalKfile_Handle fileHandle,
                Int32            offset,
                OsalKfile_Pos    pos)
{
    Int                 status      = OSALKFILE_SUCCESS;
    struct file *       fileDesc    = NULL;
    OsalKfile_Object *  fileObject  = NULL;
    mm_segment_t        fs;

    GT_3trace (curTrace, GT_ENTER, "OsalKfile_seek", fileHandle, offset, pos);

    GT_assert (curTrace, (fileHandle != NULL));
    GT_assert (curTrace, (pos < OsalKfile_Pos_EndValue));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (fileHandle == NULL) {
        /*! @retval OSALKFILE_E_INVALIDARG NULL provided for argument
                                           fileHandle. */
        status = OSALKFILE_E_INVALIDARG;
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_seek",
                             status,
                             "NULL provided for argument fileHandle");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        fileObject = (OsalKfile_Object* ) fileHandle;
        fs = get_fs ();
        set_fs (get_ds ());

        fileDesc = fileObject->fileDesc;
        switch (pos) {
            case OsalKfile_Pos_SeekSet:
            {
                if ((offset < 0) || (offset > fileObject->size)) {
                    /*! @retval OSALKFILE_E_OUTOFRANGE offset is out of range
                                             for seek from the specified pos */
                    status = OSALKFILE_E_OUTOFRANGE;
                    GT_setFailureReason (curTrace,
                                         GT_4CLASS,
                                         "OsalKfile_seek",
                                         status,
                                         "offset is out of range for"
                                         " seek from the specified pos");
                }
                else {
                    if (fileDesc->f_op->llseek != NULL) {
                        /* This may be the case if yaffs2 file system is used.*/
                        fileObject->curPos = fileDesc->f_op->llseek (fileDesc,
                                                                     offset,
                                                                     SEEK_SET);
                    }
                    else {
                        fileObject->curPos = default_llseek (fileDesc,
                                                             offset,
                                                             SEEK_SET);
                    }
                }
            }
            break;

            case OsalKfile_Pos_SeekCur:
            {
                if (   ((fileObject->curPos + offset) > fileObject->size)
                    || ((fileObject->curPos + offset) < 0)) {
                    /*! @retval OSALKFILE_E_OUTOFRANGE offset is out of range
                                             for seek from the specified pos */
                    status = OSALKFILE_E_OUTOFRANGE;
                    GT_setFailureReason (curTrace,
                                         GT_4CLASS,
                                         "OsalKfile_seek",
                                         status,
                                         "offset is out of range for"
                                         " seek from the specified pos");
                }
                else {
                    if (fileDesc->f_op->llseek != NULL) {
                        /* This may be the case if yaffs2 file system is used.*/
                        fileObject->curPos = fileDesc->f_op->llseek (fileDesc,
                                                                     offset,
                                                                     SEEK_CUR);
                    }
                    else {
                        fileObject->curPos = default_llseek (fileDesc,
                                                             offset,
                                                             SEEK_CUR);
                    }
                }
            }
            break;

            case OsalKfile_Pos_SeekEnd:
            {
                /* A negative offset indicates offset from the end of file.
                 * Check that the specified offset is not beyond
                 * the bounds of the file.
                 */
                if ((-offset < 0) || (-offset > fileObject->size)) {
                    /*! @retval OSALKFILE_E_OUTOFRANGE offset is out of range
                                             for seek from the specified pos */
                    status = OSALKFILE_E_OUTOFRANGE;
                    GT_setFailureReason (curTrace,
                                         GT_4CLASS,
                                         "OsalKfile_seek",
                                         status,
                                         "offset is out of range for"
                                         " seek from the specified pos");
                }
                else {
                    if (fileDesc->f_op->llseek != NULL) {
                        /* This may be the case if yaffs2 file system is used.*/
                        fileObject->curPos = fileDesc->f_op->llseek (fileDesc,
                                                                     offset,
                                                                     SEEK_END);
                    }
                    else {
                        fileObject->curPos = default_llseek (fileDesc,
                                                             offset,
                                                             SEEK_END);
                    }
                }
            }
            break;

            default:
            {
                /*! @retval OSALKFILE_E_INVALIDARG Invalid value provided for
                                                   argument pos. */
                status = OSALKFILE_E_INVALIDARG;
                GT_setFailureReason (curTrace,
                                    GT_4CLASS,
                                    "OsalKfile_seek",
                                    status,
                                    "Invalid value provided for argument pos.");
            }
            break;
        }
        set_fs (fs);
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace (curTrace, GT_LEAVE, "OsalKfile_seek", status);

    /*! @retval OSALKFILE_SUCCESS Operation successfully completed. */
    return status;
}

/*!
 *  @brief      Returns the current file pointer position for the specified
 *              file handle.
 *
 *  @param      fileHandle  Kernel file handle.
 *
 *  @sa         OsalKfile_read, OsalKfile_seek
 */
UInt32
OsalKfile_tell (OsalKfile_Handle fileHandle)
{
    OsalKfile_Object *  fileObject  = NULL;
    UInt32              posValue    = 0u;

    GT_1trace (curTrace, GT_ENTER, "OsalKfile_tell", fileHandle);

    GT_assert (curTrace, (fileHandle != NULL));

#if !defined(SYSLINK_BUILD_OPTIMIZE)
    if (fileHandle == NULL) {
        GT_setFailureReason (curTrace,
                             GT_4CLASS,
                             "OsalKfile_seek",
                             OSALKFILE_E_INVALIDARG,
                             "NULL provided for argument fileHandle");
    }
    else {
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */
        fileObject = (OsalKfile_Object*) fileHandle;

        posValue = fileObject->curPos;

        GT_assert (GT_1CLASS, (posValue == fileObject->fileDesc->f_pos));
#if !defined(SYSLINK_BUILD_OPTIMIZE)
    }
#endif /* #if !defined(SYSLINK_BUILD_OPTIMIZE) */

    GT_1trace(curTrace, GT_LEAVE,"OsalKfile_tell",posValue );

    /* !< @retval File-position Current file pointer position in file.*/
    return posValue;
}


#if defined (__cplusplus)
}
#endif /* defined (_cplusplus)*/
