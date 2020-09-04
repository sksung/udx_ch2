/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
/**
 * @file    app_file.c
 * @brief	recorded file management with linked-list
 * @author  sksung
 * @section MODIFY history
 *     - 2014.09.24 : First Created
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
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <glob.h>
#include <time.h>

#define _GNU_SOURCE
#include <ftw.h>
#include <fnmatch.h>
#include <fts.h>

#include "dev_common.h"

#include "ucx_main.h"
#include "app_set.h"
#include "app_util.h"
#include "app_file.h"
#include "app_dev.h"

/*----------------------------------------------------------------------------
 Definitions and macro
 -----------------------------------------------------------------------------*/
//#define USE_FTS_UTIL

#define DRIVE_DIR_PER     	    (95)
#define EVENT_DIR_PER           (5)

#define FILE_LIST_CYCLE         (100)
#define FILE_LIST_CHECK_TIME    (60*1000)   //1min

#define CHK_STR_NUM				(17)
#define PREPIX_NUM				0//(6)

#ifndef SAFE_FREE
#define SAFE_FREE(p) if(NULL != p){free(p);p=NULL;}
#endif

/*----------------------------------------------------------------------------
Declares variables
-----------------------------------------------------------------------------*/
typedef struct {
	file_info_t file_info;

	void* prev;
	void* next;
}app_file_entry_t;


typedef struct {
	app_file_entry_t* 	head;
	app_file_entry_t* 	tail;

	unsigned long 		tot_size;
	unsigned int		file_cnt;
}app_file_list_t;


typedef struct {
	unsigned long disk_avail;			//# available size in SD (KB)
	unsigned long size_max[REC_MAX];	//# threshold size
	OSA_MutexHndl mutex_file;
	app_thr_obj *fObj;					//# file checking thread
}app_file_t;

app_file_list_t ilist[REC_MAX];

app_file_t t_file;
app_file_t* ifile;

static char* rec_type_path[REC_MAX]={DIR_REC_DRIVE, DIR_REC_EVENT};

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
static int cmpfname(const void * a, const void * b)
{
	file_info_t *a_name = (file_info_t *)a;
	file_info_t *b_name = (file_info_t *)b;

	return -(strcmp(a_name->fname, b_name->fname));
}

static int cmpnew(const void * a, const void * b)
{
	file_info_t *a_name = (file_info_t *)a;
	file_info_t *b_name = (file_info_t *)b;

	return -(strcmp(a_name->fname, b_name->fname));
}

static int cmpold(const void * a, const void * b)
{
	file_info_t *a_name = (file_info_t *)a;
	file_info_t *b_name = (file_info_t *)b;

	return (strcmp(a_name->fname, b_name->fname));
}

static int get_threshold_size(app_file_t* pInfo)
{
	int ret = EFAIL;

	if( app_cfg->state.mmc_err )
		return EFAIL;
		

    printf("\n");
	printf("==============================================================\n");
	printf("			    GET DISK SIZE INFORMATION 		         \n");
	printf("==============================================================\n");
	printf("   TOT-SIZE 		 NOR-SZIE		  EVT-SIZE           \n");
	printf("==============================================================\n");
	


	disk_info_t idisk;
	ret = util_disk_info(&idisk, DIR_DISK);

	if(ret != EFAIL)
	{
		//#--- Save threshold size
		pInfo->size_max[REC_DRIVE]		= ((unsigned long long)idisk.total*DRIVE_DIR_PER)/100;
//		pInfo->size_max[REC_EVENT] 		= ((unsigned long long)idisk.total*EVENT_DIR_PER)/100;  
		
		pInfo->disk_avail				= idisk.avail;
		ret = SOK;
	}

    printf("     %ldGb			 %ldGB\n",
		   (idisk.total/1024)/1024,
		   (pInfo->size_max[REC_DRIVE]/1024)/1024);
//		   (pInfo->size_max[REC_EVENT]/1024)/1024);
	printf("===============================================================\n");
	printf("\n");	

	return ret;

}

static int file_delete(int rec_type, unsigned long used_size)
{
	if(rec_type >= REC_DRIVE && rec_type < REC_MAX)
	{
		char path[CHAR_128], cmd[CHAR_128];
		unsigned long tot_size;

		OSA_mutexLock(&ifile->mutex_file);

		app_file_list_t* plist = &ilist[rec_type];

        tot_size = plist->tot_size;

		while(ifile->size_max[rec_type] <= tot_size)
		{
			if(plist->head == NULL || plist->head->next == NULL)
				break;

			app_file_entry_t* pTmp = plist->head;

			plist->head 		= (app_file_entry_t*)pTmp->next;
			plist->head->prev	= NULL;
			plist->tot_size 	-= pTmp->file_info.size;
			plist->file_cnt--;

            tot_size = plist->tot_size;

			sprintf(path, "%s/%s", rec_type_path[rec_type], pTmp->file_info.fname);
			sprintf(cmd, "rm -f %s", path);

			dev_execlp(cmd);

			free(pTmp);
			pTmp = NULL;
			OSA_waitMsecs(1);
			printf(" Delete file : %s \n", path);
		}

		OSA_mutexUnlock(&ifile->mutex_file);
		printf(" %03d files ---------------\n", plist->file_cnt);
	}

	return SOK;
}

static int file_add(int rec_type, file_info_t* pInfo)
{
	int ret = EFAIL;
	if(ifile != NULL)
	{
		OSA_mutexLock(&ifile->mutex_file);
		app_file_list_t* plist = &ilist[rec_type];

		app_file_entry_t* pNew 	= app_malloc(sizeof(app_file_entry_t));
		app_file_entry_t* pTail = (app_file_entry_t*)plist->tail;

		if(pNew == NULL)
		{
			eprintf("file entry create failed!!\n");
			OSA_mutexUnlock(&ifile->mutex_file);

			return EFAIL;
		}

		pNew->prev = NULL;
		pNew->next = NULL;
		pNew->file_info.size = pInfo->size;
		sprintf(pNew->file_info.fname, "%s", pInfo->fname);

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
		plist->file_cnt++;
		plist->tot_size += pNew->file_info.size;
//		printf(" added %s file\n", plist->tail->file_info.fname);
//		printf(" %03d files ---------------\n", plist->file_cnt);
		OSA_mutexUnlock(&ifile->mutex_file);

		ret = SOK;
	}

	return ret;
}

static void* file_check_main(void* prm)
{
    app_thr_obj *tObj   = (app_thr_obj *)prm;

    int cmd, f_cycle, exit = 0;
	int ret = 0;
	char msg[CHAR_128] = {0,};
	
    printf(" [task] %s start\n", __func__);

    f_cycle 	= 0;
    tObj->done 	= 0;

    while(!exit)
    {
    	app_cfg->wd_flags |= WD_FILE;

        cmd = tObj->cmd;
        if(cmd == UBX_CMD_STOP)
            break;

		if( app_cfg->state.mmc && !app_cfg->state.mmc_err )
		{
	        if((f_cycle!=0) && ((f_cycle % FILE_LIST_CHECK_TIME) == 0) && app_cfg->state.rec)
	        {
	            f_cycle = 0;
				
				if(app_cfg->state.mmc)
				{
					if(ifile->size_max[REC_DRIVE] <= ilist[REC_DRIVE].tot_size)
						file_delete(REC_DRIVE, 0); 					   
				
//					if(ifile->size_max[REC_EVENT] <= ilist[REC_EVENT].tot_size)
//						file_delete(REC_EVENT, 0);  
				}
#if 0				
				else
				{
					disk_info_t idisk;
					ret = util_disk_info(&idisk, DIR_DISK);
					if(ret != EFAIL)
					{
						printf("#### Check Used Disk Size.... [ %ld / %ld ] \n", idisk.used, ifile->size_max[REC_EVENT]);
						if(ifile->size_max[REC_EVENT] <= idisk.used)
							file_delete(REC_EVENT, idisk.used);
					}
					else
					{
						eprintf("Get disk size fail!!");
						sprintf(msg, "[APP_FILE] !!! Get disk size failed !!! - %s", DIR_DISK);
						app_log_write( MSG_LOG_WRITE, msg );

						app_cfg->state.mmc_sz 		= 1;
				        app_cfg->state.sd_buzzer 	= 1;
						app_cfg->state.mmc_err		= 1;
						app_rec_stop();
						continue;
					}
				}
#endif				
	        }
		}

        OSA_waitMsecs(FILE_LIST_CYCLE);
        f_cycle += FILE_LIST_CYCLE;
    }

    tObj->done = 1;

    printf(" [task] %s done\n", __func__);
    return NULL;
}

static int file_list_create(int rec_type, char*filters)
{
	FTS *tree;
	FTSENT *node;
    int add_cnt=0;

	file_info_t *list;
	char const *scan[] = {NULL, NULL};
	char msg[CHAR_128] = {0,};
	char list_tmp[FILE_NAME_MAX] = {0,};
	
	int fcnt = 0, i = 0;
    time_t start_t, end_t;


	glob_t globbuf;
	static char	extPath[255];

	memset(&globbuf, 0, sizeof(glob_t));

	sprintf(extPath, "%s/%s", rec_type_path[rec_type], filters);
    if(glob(extPath, GLOB_DOOFFS, NULL, &globbuf) == 0)
   		fcnt = globbuf.gl_pathc;
	else
		eprintf("Not found firmware file: %s\n",rec_type_path[rec_type]);
    
	sprintf(msg, "[APP_FILE] %s total cnt = %d ", rec_type_path[rec_type], fcnt);
	app_log_write( MSG_LOG_WRITE, msg );
	printf("%s\n", msg);

	if(fcnt > 0)
	{
		time(&start_t);
		app_watchdog_keep_alive();	
		list = app_malloc(sizeof(file_info_t)*fcnt);	
        for(i=0; i<fcnt; i++){
            strtok(globbuf.gl_pathv[i], "/");
            strtok(NULL, "/");
            strtok(NULL, "/");
            sprintf(list_tmp, "%s", strtok(NULL, "/"));
            
            strcpy(list[i].fname, list_tmp);
        }       

        app_watchdog_keep_alive();
		qsort(list, fcnt, sizeof(file_info_t), cmpold);

		for(i = 0; i < fcnt; i++){
			if( i%50 == 0 ){
				app_cfg->wd_flags = WD_FSCAN;
            }  
           
			app_file_add(rec_type, list[i].fname);
        }
        time(&end_t);
        printf("sec = %f\n", difftime(end_t, start_t));

		app_mfree(list);
	}

    globfree(&globbuf);

	return 0;
}

static void file_list_delete_all(void)
{
	int i;

	for(i = 0; i < REC_MAX; i++)
	{
		app_file_list_t* plist = &ilist[i];

		if(plist->head != NULL && plist->file_cnt > 0)
		{
			app_file_entry_t* pNext;
			app_file_entry_t* pCurr = plist->head;

			while(pCurr != NULL)
			{
				pNext = pCurr->next;
				app_mfree(pCurr);
				pCurr = pNext;
			}
		}
	}
}

int app_file_get_list(int rec_type, file_info_t** flist, int descending)
{
	int fcnt = 0;
	app_file_list_t* plist;
	plist = &ilist[rec_type];

	if(plist->head != NULL && plist->file_cnt > 0)
	{
		printf("file count: %d\n", plist->file_cnt);
		*flist = (file_info_t*)app_malloc(sizeof(file_info_t)*plist->file_cnt);

		if(descending)	//latest file first
		{
			app_file_entry_t* pTmp = plist->tail;
			while(pTmp->prev != NULL)
			{
				(*flist)[fcnt].size = pTmp->file_info.size;
				sprintf((*flist)[fcnt].fname,"%s", pTmp->file_info.fname);

				fcnt++;
				pTmp = pTmp->prev;
			}

			(*flist)[fcnt].size = pTmp->file_info.size;
			sprintf((*flist)[fcnt].fname,"%s", pTmp->file_info.fname);
			fcnt++;
		}
		else
		{
			app_file_entry_t* pTmp = plist->head;
			while(pTmp->next != NULL)
			{
				(*flist)[fcnt].size = pTmp->file_info.size;
				sprintf((*flist)[fcnt].fname,"%s", pTmp->file_info.fname);

				fcnt++;
				pTmp = pTmp->next;
			}

			(*flist)[fcnt].size = pTmp->file_info.size;
			sprintf((*flist)[fcnt].fname,"%s", pTmp->file_info.fname);
			fcnt++;
		}
	}	


	return fcnt;
}

void app_file_free_list(file_info_t** flist)
{
	if(*flist != NULL){
		app_mfree(*flist);
		*flist = NULL;
	}
}

int app_file_add(int rec_type, char* file_name)
{
	int ret = EFAIL;
	if(app_cfg->state.mmc && (rec_type >= REC_DRIVE && rec_type < REC_MAX))
	{
		struct stat sb;
		char path[CHAR_128];
		sprintf(path, "%s/%s", rec_type_path[rec_type], file_name);
		lstat(path, &sb);

		file_info_t fInfo;
		fInfo.size = sb.st_size/KB;
		sprintf(fInfo.fname, "%s", file_name);

		ret = file_add(rec_type, &fInfo);
	}

	return ret;
}

int app_file_start(void)
{
	int status, i;
    app_thr_obj *tObj;
	char msg[CHAR_128];
    int del=0;
    int ste=0;
	
    ifile = &t_file;
    memset(ifile, 0, sizeof(app_file_t));
	memset(ilist, 0, sizeof(app_file_list_t)*REC_MAX);

    printf(" [app] %s start...\n", __func__);    
	app_log_write( MSG_LOG_WRITE, "[APP_FILE] Start file scanning...");
	
	//#--- Set threshold size each recording directory
	if(get_threshold_size(ifile) == EFAIL){
		sprintf(msg, "[APP_FILE] !!! Get threshold size failed !!!");
		app_log_write( MSG_LOG_WRITE, msg );
		
		app_cfg->state.mmc_sz 		= 1;
        app_cfg->state.sd_buzzer 	= 1;
	}

	//#--- create linked-list
	if(!app_cfg->state.mmc_sz)
	{
//		app_watchdog_keep_alive();
		app_cfg->wd_flags = WD_FSCAN;

		unsigned long part_avail = 0;
		for(i = 0; i < REC_MAX; i++){
            file_list_create(i, "*.avi");
		}

		if(ifile->size_max[REC_DRIVE] <= ilist[REC_DRIVE].tot_size){
			app_cfg->wd_flags = WD_FSCAN;
			file_delete(REC_DRIVE, ilist[REC_DRIVE].tot_size);
            del = 1;
        }
/*
		if(ifile->size_max[REC_EVENT] <= ilist[REC_EVENT].tot_size){
			app_cfg->wd_flags = WD_FSCAN;
			file_delete(REC_EVENT, ilist[REC_EVENT].tot_size);
            del = 1;
        }		
*/
        if(del){
            disk_info_t idisk;
        	ste = util_disk_info(&idisk, DIR_DISK);

        	if(ste != EFAIL){
                ifile->disk_avail = idisk.avail;
            }
        }

        for(i = 0; i < REC_MAX; i++){
		    part_avail += ifile->size_max[i]-ilist[i].tot_size;
		}       

		pwr_led_run( ON );
		app_cfg->wd_flags = 0;

		if(ifile->disk_avail < part_avail)
		{
			sprintf(msg, "[APP_FILE] !!! Not enough SD storage !!!");
			app_log_write( MSG_LOG_WRITE, msg );
			printf("%s\n", msg);
			
			app_cfg->state.mmc_sz 		= 1;
            app_cfg->state.sd_buzzer 	= 1;
			app_cfg->state.secu_on 		= 1;
		}
	}

    status = OSA_mutexCreate(&(ifile->mutex_file));
    OSA_assert(status == OSA_SOK);

    //#--- create normal record thread
    tObj = app_malloc(sizeof(app_thr_obj));
    if(tObj ==NULL) {
        eprintf("thread obj malloc fail\n");
        return EFAIL;
    }

    ifile->fObj = tObj;

    OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
    OSA_thrCreate(&tObj->thr, file_check_main, FXN_TSK_PRI+2, 0, tObj);

	app_log_write( MSG_LOG_WRITE, "[APP_FILE] File scanning done...");
    return SOK;
}

void app_file_stop(void)
{
	int status;
    if(ifile != NULL)
    {
        app_thr_obj *tObj;
        tObj = ifile->fObj;

        if(tObj != NULL)
       	{
			event_send(tObj, UBX_CMD_STOP, 0, 0);
			while(!tObj->done)
				OSA_waitMsecs(20);

			OSA_semDelete(&tObj->sem);
			OSA_thrDelete(&tObj->thr);

			app_mfree(tObj);
			tObj = NULL;

		    status = OSA_mutexDelete(&(ifile->mutex_file));
		    OSA_assert(status == OSA_SOK);
       	}

		ifile = NULL;
    }

    printf(" [app] %s done!\n", __func__);
}

char* app_file_get_rectype_path(int rec_type)
{
	if(rec_type >= REC_DRIVE && rec_type < REC_MAX)
		return rec_type_path[rec_type];

	return NULL;
}
