/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
/**
 * @file    app_log.c
 * @brief	log file management with linked-list
 * @author  sksung
 * @section MODIFY history
 *     - 2014.11.25 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
 -----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <glob.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define _GNU_SOURCE
#include <ftw.h>
#include <fnmatch.h>
#include <fts.h>

#include "dev_common.h"

#include "ucx_main.h"
#include "app_set.h"
#include "app_util.h"
#include "app_log.h"
#include "app_dev.h"

/*----------------------------------------------------------------------------
 Definitions and macro
 -----------------------------------------------------------------------------*/
//#define USE_FTS_UTIL

#define LOG_FILE_MAX		(2)

#if LOG_TEST
	#define LOG_MAX_SIZE		(400)
#else
	#define LOG_MAX_SIZE		(500*KB)
#endif


#define LOG_PREFIX			"ulog"
#define LOG_EXT				"log"
#define LOG_ROOT_PATH		"/mmc/log"

#define LOG_MSG_KEY         0x9992

#ifndef SAFE_FREE
#define SAFE_FREE(p) if(NULL != p){free(p);p=NULL;}
#endif

/*----------------------------------------------------------------------------
Declares variables
-----------------------------------------------------------------------------*/
typedef struct {
	log_info_t file_info;

	void* prev;
	void* next;
}app_log_entry_t;

typedef struct {
	app_log_entry_t* 	head;
	app_log_entry_t* 	tail;
}app_log_list_t;

typedef struct {
	OSA_MutexHndl 	mutex_log;
	app_thr_obj 	*lObj;					//# file checking thread

	app_log_list_t 	log_list;

	unsigned int	file_cnt;
	unsigned int	last_idx;
	unsigned int	log_size;
	char last_fname[LOG_NAME_MAX];
	FILE *fd;
}app_log_t;

app_log_t t_log;
app_log_t* ilog;

/*----------------------------------------------------------------------------
Declares a function prototype
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
local function
-----------------------------------------------------------------------------*/
/*****************************************************************************
 * @brief	 filelist create/delete function
 * @section  DESC Description
 *	 - desc
 *****************************************************************************/

static int cmpold(const void * a, const void * b)
{
	log_info_t *a_name = (log_info_t *)a;
	log_info_t *b_name = (log_info_t *)b;

	return (strcmp(a_name->fname, b_name->fname));
}



static int log_file_add(char* path)
{
	if(ilog == NULL)
		return EFAIL;

	struct stat sb;
	log_info_t lInfo;
	app_log_list_t* plist = &ilog->log_list;

	lstat( path, &sb );
	sprintf( lInfo.fname, "%s", path );
	lInfo.size = sb.st_size;	//bytes

	app_log_entry_t* pNew	= app_malloc(sizeof(app_log_entry_t));
	app_log_entry_t* pTail 	= (app_log_entry_t*)plist->tail;

	if(pNew == NULL)
	{
		eprintf("file entry create failed!!\n");
		return EFAIL;
	}

	pNew->prev = NULL;
	pNew->next = NULL;
	pNew->file_info.size = lInfo.size;
	sprintf(pNew->file_info.fname, "%s", lInfo.fname);

	//#--- link process
	if(pTail == NULL)		//# first file
	{
		plist->head = pNew;
		plist->tail = pNew;
	}
	else
	{
		if(pTail->next == NULL)
		{
			pTail->next = pNew;
			pNew->prev = pTail;
		}

		plist->tail = pNew;
	}

	//#--- update total file size & file count
	ilog->file_cnt++;
	ilog->log_size = pNew->file_info.size;

	printf(" [LOG] added %s file\n", plist->tail->file_info.fname);
	printf(" [LOG] %03d files ---------------\n", ilog->file_cnt);

	return SOK;
}

static int log_file_delete( void )
{
	if(ilog == NULL)
		return EFAIL;

	char cmd[CHAR_128]={0,};

	app_log_list_t* plist = &ilog->log_list;

	while( ilog->file_cnt > LOG_FILE_MAX )
	{
		if(plist->head == NULL || plist->head->next == NULL)
			break;

		app_log_entry_t* pTmp = plist->head;

		plist->head 		= (app_log_entry_t*)pTmp->next;
		plist->head->prev	= NULL;
		ilog->file_cnt--;

		sprintf(cmd, "rm -f %s", pTmp->file_info.fname);
		dev_execlp(cmd);
		
		printf(" Delete file : %s \n", pTmp->file_info.fname);

		free(pTmp);
		pTmp = NULL;
		OSA_waitMsecs(1);
	}

	printf(" %03d files ---------------\n", ilog->file_cnt);
	return SOK;
}


static int log_open(int new_file)
{
	int ret = SOK;
	char path[CHAR_128];

	if(ilog->fd){
		fclose(ilog->fd);
		ilog->fd = NULL;
	}

	if(new_file){
		ilog->last_idx++;
	}

	sprintf(ilog->last_fname, "%s_%08d.%s", LOG_PREFIX, ilog->last_idx, LOG_EXT);
	sprintf(path, "%s/%s", LOG_ROOT_PATH, ilog->last_fname);

    ilog->fd = fopen(path, "a");
	if(ilog->fd == NULL){
		eprintf("Log file open failed!!! path: %s\n", path);
		return EFAIL;
	}

	if(new_file){
		log_file_add( path );
	}

	if( ilog->file_cnt > LOG_FILE_MAX )
		log_file_delete();

	printf("@@@@@@@@@@@@@@ LOG File Open [%s] @@@@@@@@@@@@@@\n", path);
	return ret;
}

static void *log_write_main(void *prm)
{
    app_thr_obj *tObj   = (app_thr_obj *)prm;

	ucx_msg_info msg_buf;
    int exit = 0;

	//# msg queue create
    app_cfg->msgqId = msgget(LOG_MSG_KEY, 0);
    if(app_cfg->msgqId < 0){
        app_cfg->msgqId = msgget(LOG_MSG_KEY, IPC_CREAT|0666);
        if(app_cfg->msgqId < 0){
            eprintf("Faled make the MSG KEY for log write!!!\n");
            return NULL;
        }
    }

    printf(" [task] %s start\n", __func__);

    tObj->done 	= 0;

	app_cfg->state.log = 1;

    while(!exit)
    {
		if(msgrcv(app_cfg->msgqId, &msg_buf, sizeof(msg_buf)-sizeof(long), MSG_TYPE_LOG, 0) < 0)
        {
            eprintf("Receive msg failed!!!\n");
            break;
        }

		if( app_cfg->state.mmc_err ) {
			exit = 1;
			continue;
		}

		switch(msg_buf.msgCmd)
		{
			case MSG_LOG_WRITE:
				if(ilog->fd != NULL && app_cfg->state.mmc)
				{
					//# Write Log
					fprintf(ilog->fd, "%s\r\n", msg_buf.msgstr);
					fseek(ilog->fd, 0, SEEK_END);
					ilog->log_size += strlen( msg_buf.msgstr );

					//# size check and open a new file.
					if( LOG_MAX_SIZE <= ilog->log_size ){
						if(log_open(1) != 0){
							exit = 1;
							ilog->fd = NULL;
						}
					}
				}
				break;
			case MSG_LOG_SHUTDOWN:
				if(ilog->fd != NULL)
				{
					//# Write Log and exit!
					fprintf(ilog->fd, "%s\r\n", msg_buf.msgstr);
					exit = 1;
				}
				break;
			case MSG_LOG_EXIT:
				printf("Recv MSG_LOG_EXIT.........\n");
				exit = 1;
				break;
		}
    }

	if(ilog->fd != NULL && app_cfg->state.mmc){
		fclose(ilog->fd);
		ilog->fd = NULL;
		sync();
	}

//	sd_copy_log();

    tObj->done = 1;
	app_cfg->state.log = 0;

    printf(" [task] %s done\n", __func__);
    return NULL;
}


static int get_log_count(char* path, char*filters)
{
	int fcnt = 0;

	glob_t globbuf;
	static char	extPath[255];

	memset(&globbuf, 0, sizeof(glob_t));

	sprintf(extPath, "%s/%s", path, filters);
    if(glob(extPath, GLOB_DOOFFS, NULL, &globbuf) == 0)
   		fcnt = globbuf.gl_pathc;
	else
		eprintf("Not found firmware file: %s\n",path);

	globfree(&globbuf);

	return fcnt;
}

static int log_list_check(char*filters)
{
	FTS *tree;
	FTSENT *node;

	char const *scan[] = {NULL, NULL};
	int fcnt = 0, i = 0;

	if(-1 == access(NAND_ROOT, 0)) {
		eprintf(" Can't create Log path : %s !!!\n", NAND_ROOT);
		return -1;
	 }

    if(-1 == access(LOG_ROOT_PATH, 0)) {
        mkdir(LOG_ROOT_PATH, 0775);
        chmod(LOG_ROOT_PATH, 0775);

		return 0;
    }

	//# get count of log files.
	fcnt = get_log_count(LOG_ROOT_PATH, filters);

	if(fcnt > 0)
	{
		scan[0] = LOG_ROOT_PATH;

		tree = fts_open((char * const *)scan, FTS_NOCHDIR, NULL);
		if (!tree) {
			eprintf("Failed to fts_open\n");
			return EFAIL;
		}

		log_info_t* list;
		list = app_malloc(sizeof(log_info_t)*fcnt);

		//# sort log files
		while ((node = fts_read(tree)))
		{
			if (node->fts_info & FTS_F)
			{
				if (fnmatch(filters, node->fts_name, FNM_CASEFOLD) == 0)
					strcpy(list[i++].fname, node->fts_name);
			}
		}

		if (fts_close(tree)) {
			eprintf("fts_close");
		}

		qsort(list, fcnt, sizeof(log_info_t), cmpold);

		//# Make list
		char path[CHAR_128];
		for( i = 0; i < fcnt; i++ )
		{
			printf("file : %s\n", list[i].fname);
			sprintf(path, "%s/%s", LOG_ROOT_PATH, list[i].fname);
			log_file_add( path );
		}


		//# get last file index
		ilog->last_idx = (unsigned int)atoi( strtok( &list[fcnt-1].fname[5], "." ) );
		ilog->file_cnt = fcnt;

		app_mfree(list);
	}

	return 0;
}



int app_log_start(void)
{
	int status, new_file=0;
    app_thr_obj *tObj;
	char filter[CHAR_64] = {0,};
	
	if( !app_cfg->state.mmc || app_cfg->state.mmc_err )
		return EFAIL;

    printf(" [app] %s start...\n", __func__);

    ilog = &t_log;
    memset(ilog, 0, sizeof(app_log_t));

	//# check exist log files and get last file name and date
	sprintf(filter, "%s_*.%s",LOG_PREFIX, LOG_EXT);
	if(log_list_check(filter) != 0){
		eprintf(" Log file check failed!!! \n");
		return EFAIL;
	}

	if( ilog->file_cnt == 0 )
		new_file = 1;

	//# logfile open and write thread start
	if(log_open(new_file) == 0){
	    status = OSA_mutexCreate(&(ilog->mutex_log));
	    OSA_assert(status == OSA_SOK);

	    //#--- create normal record thread
	    tObj = app_malloc(sizeof(app_thr_obj));
	    if(tObj ==NULL) {
	        eprintf("thread obj malloc fail\n");
	        return EFAIL;
	    }

	    ilog->lObj = tObj;

	    OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	    OSA_thrCreate(&tObj->thr, log_write_main, FXN_TSK_PRI+2, 0, tObj);

		OSA_waitMsecs(500);
	}

    return SOK;
}

void app_log_stop(void)
{
	int status;

    if( ilog == NULL || !app_cfg->state.log )
		return;

    app_thr_obj *tObj;
    tObj = ilog->lObj;

    if(tObj != NULL)
   	{
	   	app_log_write(MSG_LOG_EXIT, "<<<< UCX_MAIN is EXIT >>>>");
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;

	    status = OSA_mutexDelete(&(ilog->mutex_log));
	    OSA_assert(status == OSA_SOK);
   	}

	ilog = NULL;

    printf(" [app] %s done!\n", __func__);
}


void app_log_write(int cmd, char* msg)
{

#if LOG_TEST
	app_log_write_test(cmd, msg);
	return;
#endif

	if(ilog == NULL || !app_cfg->state.log)
		return;

	ucx_msg_info msgBuf;
	int ret;

	OSA_mutexLock(&ilog->mutex_log);
	memset(&msgBuf, 0, sizeof(ucx_msg_info));

    struct tm 	ts;
	time_t		tm1;

	time(&tm1);
	localtime_r((const time_t *)&tm1, &ts);
	char dtime[CHAR_32];

	strftime(dtime, sizeof(dtime), "%Y:%2m:%2d:%2H:%2M:%2S", &ts);

	msgBuf.msgDes	= MSG_TYPE_LOG;
	msgBuf.msgSrc	= MSG_TYPE_UCX;
	msgBuf.msgCmd	= cmd;
	msgBuf.msgParm1 = 0;
	msgBuf.msgParm2 = 0;
	msgBuf.msgParm3 = 0;
	if(msg != NULL)
		sprintf(msgBuf.msgstr, "[%s]	%s", dtime, msg);

	ret = msgsnd(app_cfg->msgqId, &msgBuf, sizeof(ucx_msg_info)-sizeof(long), 0);

	OSA_mutexUnlock(&ilog->mutex_log);
}

void app_log_write_test(int cmd, char* msg)
{
	if(ilog == NULL || !app_cfg->state.log)
		return;

	ucx_msg_info msgBuf;
	int ret;

	OSA_mutexLock(&ilog->mutex_log);
	memset(&msgBuf, 0, sizeof(ucx_msg_info));

    struct tm 	ts;
	time_t		tm1;

	time(&tm1);
	localtime_r((const time_t *)&tm1, &ts);
	char dtime[CHAR_32];

	strftime(dtime, sizeof(dtime), "%Y:%2m:%2d:%2H:%2M:%2S", &ts);

	msgBuf.msgDes	= MSG_TYPE_LOG;
	msgBuf.msgSrc	= MSG_TYPE_UCX;
	msgBuf.msgCmd	= cmd;
	msgBuf.msgParm1 = 0;
	msgBuf.msgParm2 = 0;
	msgBuf.msgParm3 = 0;
	if(msg != NULL)
		sprintf(msgBuf.msgstr, "[%s]	%s", dtime, msg);

	ret = msgsnd(app_cfg->msgqId, &msgBuf, sizeof(ucx_msg_info)-sizeof(long), 0);

	OSA_mutexUnlock(&ilog->mutex_log);

}

