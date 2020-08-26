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
#include <dirent.h>
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


#define UFS_HDR					(0x2818)

#define UFS_EXT					"ufs"


#define AVAIL_PER				(5)
#define DIR_PER		     	    (95)

#ifdef FREC_TEST
#define MAX_REC_TIME			(130) 			//# 30sec
#else
#define HOURS72					(60*60*24*3)
#define MAX_REC_TIME			(HOURS72+(60*60))	//# 72+1 hours
#endif

//#define EVENT_DIR_PER         (20)
//#define PARKING_DIR_PER		(25)

#define FILE_LIST_CYCLE         (100)

#ifdef FREC_TEST
#define FILE_LIST_CHECK_TIME    (10*1000)   //10 SEC
#else
#define FILE_LIST_CHECK_TIME    (60*1000)   //1min
#endif

#define CHK_STR_NUM				(17)
#define PREPIX_NUM				(6)

#ifdef FREC_TEST
#define MAX_FREC_CNT			(10)
#else
#define MAX_FREC_CNT			(1000)
#endif
#define MAX_DIR_CNT				(1000)

#define REC_CREATE				(0)
#define REC_CLOSE				(1)

#define DEL_SIZE				(0)
#define DEL_TIME				(1)

#ifndef SAFE_FREE
#define SAFE_FREE(p) if(NULL != p){free(p);p=NULL;}
#endif

/*----------------------------------------------------------------------------
Declares variables
-----------------------------------------------------------------------------*/

typedef struct {
	unsigned int hdr;					//# UFS HDR
	unsigned int fcnt;					//# file count
	unsigned int didx;					//# next delete index
	unsigned long tsize;					//# total file size (KB)
	frec_info_t flist[MAX_FREC_CNT];	//# recorded file info. (MAX 1000)
	
}ufs_info_t;

typedef struct {
	char dir_name[CHAR_16];
}dir_info_t;

typedef struct {
	dir_info_t dir;

	void* prev;
	void* next;
}app_dir_entry_t;

typedef struct {
	app_dir_entry_t* 	head;
	app_dir_entry_t* 	tail;

}app_dir_list_t;

typedef struct {
	int				dir_cnt;			//# dir_cnt;	
	unsigned long 	ft_size;			//# total file size (KB)
	unsigned long	sa_size;			//# storage available size (KB)
	unsigned long	start_sec;			//# recorded time first
	unsigned long	end_sec;			//# recorded time end
	char 			start_dir[CHAR_16];	//# first dir name
	char 			cur_dir[CHAR_16];	//# latest dir name... recording dir.	
}stor_info_t;

typedef struct {
	OSA_MutexHndl 	mutex_file;
	app_thr_obj		*fObj;					//# file checking thread

	rec_storage_e	root_idx;				//# HDD or MMC 
	stor_info_t		storage;
	int				find_start_sec;			//# finded first recorded time(sec)
}app_file_t;


app_dir_list_t ilist;

app_file_t t_file;
app_file_t* ifile;

static char* rec_root[REC_STOR_MAX]={DIR_REC, DIR_REC_MMC};

/*----------------------------------------------------------------------------
Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
local function
-----------------------------------------------------------------------------*/
static int cmpold(const void * a, const void * b)
{
	dir_info_t *a_name = (dir_info_t *)a;
	dir_info_t *b_name = (dir_info_t *)b;

	return (strcmp(a_name->dir_name, b_name->dir_name));
}

static unsigned long get_file_size(char* dir_name, char* fname)
{
	struct stat sb;
	char fpath[CHAR_128] = {0,};
	sprintf(fpath, "%s/%s/%s", rec_root[ifile->root_idx], dir_name, fname);
	lstat(fpath, &sb);

	return (unsigned long)(sb.st_size/KB);
}

static int access_file(char* dir_name, char* fname)
{
	int ret = SOK;
	char fpath[CHAR_128] = {0,};
	sprintf(fpath, "%s/%s/%s", rec_root[ifile->root_idx], dir_name, fname);
	if(-1 == access(fpath, 0)) 
		ret = EFAIL;

	return ret;
}

static unsigned long get_recorded_sec(char* fname)
{
	char* token, *last;
	char pname[255] = {0,};
	char rec_time[3][10] = {};
	int token_cnt=0;

	sprintf(pname, "%s", fname);

	//# parsing fname ex) N_20160412_125900_1ch.udf
	token = strtok_r(pname, "_", &last);
	while(token!=NULL){
		strcpy(rec_time[token_cnt], token);
		token = strtok_r(NULL, "_", &last);
		token_cnt++;
	}


	//# Make time
	struct tm ts;
	char date[5] = {0,};
	//# year
	memset(date, 0, 5);
	strncpy(date, rec_time[1], 4);
	ts.tm_year = atoi(date)-1900;
	//# month
	memset(date, 0, 5);
	strncpy(date, rec_time[1]+4, 2);
	ts.tm_mon = atoi(date)-1;
	//# day
	memset(date, 0, 5);
	strncpy(date, rec_time[1]+6, 2);
	ts.tm_mday = atoi(date);
	//# hour
	memset(date, 0, 5);
	strncpy(date, rec_time[2], 2);
	ts.tm_hour = atoi(date);
	//# min
	memset(date, 0, 5);
	strncpy(date, rec_time[2]+2, 2);
	ts.tm_min = atoi(date);
	//# sec
	memset(date, 0, 5);
	strncpy(date, rec_time[2]+4, 2);
	ts.tm_sec = atoi(date);

#if 0
	printf("@@@@@@@@%s@@@@@@@@@@\n", __func__);
	printf("Recorded date: %d/%d/%d_%d:%d:%d \n", ts.tm_year+1900, ts.tm_mon+1, ts.tm_mday, ts.tm_hour, ts.tm_min, ts.tm_sec);
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#endif	
	
	return mktime(&ts);
}


static int set_next_start_dir(void)
{
	app_dir_list_t* plist = &ilist;

	if(plist->head != NULL || plist->head->next != NULL)
	{
		char rec_path[CHAR_32] 	= {0, };
		char cmd[CHAR_128] 		= {0, };
		
		app_dir_entry_t* pTmp = plist->head;

		plist->head			= (app_dir_entry_t*)pTmp->next;
		plist->head->prev	= NULL;

		//# Delete dir.
		if(pTmp){
			free(pTmp);
			pTmp = NULL;
		}

		sprintf(rec_path, "%s/%s/", rec_root[ifile->root_idx], ifile->storage.start_dir);
		sprintf(cmd, "rm -Rf %s", rec_path);
		dev_execlp(cmd);
				
		ifile->storage.dir_cnt--;
		printf(" [File] Deleted Start Dir: %s\n", rec_path);
		
		//# Set next start dir
		sprintf(ifile->storage.start_dir, "%s", plist->head->dir.dir_name);
		printf(" [File] Next Start Dir: %s \n", ifile->storage.start_dir);


		//# update delete rec time
		FILE* fd;
		int i;
		ufs_info_t ufs;
		char ufs_path[CHAR_64] = {0,};

		memset(&ufs, 0, sizeof(ufs_info_t));
		
		sprintf(ufs_path, "%s/%s/%s.%s", rec_root[ifile->root_idx], ifile->storage.start_dir, ifile->storage.start_dir, UFS_EXT);
		if(access(ufs_path, 0) == -1){
			sprintf(cmd, "[%s] File not exist : %s ", __func__, ufs_path);
			app_log_write( MSG_LOG_WRITE, cmd );
			eprintf("%s \n", cmd);
			return -1;
		}
		
		if(!OPEN_RDWR(fd, ufs_path)){
			sprintf(cmd, "[%s] UFS file open fail!!! ", __func__);
			app_log_write( MSG_LOG_WRITE, cmd );
			eprintf("%s \n", cmd);
			return -1;
		}
	
		//# dfs headr check
		if(!READ_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
			sprintf(cmd, "[%s] UFS file read fail!!! ", __func__);
			app_log_write( MSG_LOG_WRITE, cmd );
			eprintf("%s \n", cmd);
			CLOSE(fd);
			return -1;
		}
		
		if(ufs.hdr != UFS_HDR){
			eprintf("Invalid UFS Format!! \n");
			CLOSE(fd);
			return -1;
		}
	
		//# update total file size if file size zero.
		if(ufs.fcnt > 0){
			for(i = 0; i < ufs.fcnt; i++){
				//# set up recorded time that is first delelte.
				if(ifile->find_start_sec == 0 && ufs.flist[i].del == 0){
					ifile->find_start_sec = 1;				
					ifile->storage.start_sec = get_recorded_sec(ufs.flist[i].fname);
					break;
				}
			}
		}

		CLOSE(fd);
	}

	return 0;
}

static int file_delete(int del_type)
{
	if(ifile == NULL)
		return EFAIL;

	if(ifile->storage.dir_cnt == 0)
		return EFAIL;


	OSA_mutexLock(&ifile->mutex_file);

	int ret = SOK;
	FILE* fd;
	ufs_info_t ufs;
	char rec_path[CHAR_32] = {0,};
	char ufs_path[CHAR_64] = {0,};
	char avi_path[CHAR_64] = {0,};
	char cmd[CHAR_128] = {0,};
	
	//# recording path
	sprintf(rec_path, "%s/%s/", rec_root[ifile->root_idx], ifile->storage.start_dir);

	//# Open ufs file
	sprintf(ufs_path, "%s/%s.%s", rec_path, ifile->storage.start_dir, UFS_EXT);
	if(!OPEN_RDWR(fd, ufs_path)){
		sprintf(cmd, "[%s] %s Open Faild!!!", __func__, ufs_path);
		app_log_write( MSG_LOG_WRITE, cmd );
		eprintf("%s \n", cmd);
		ret = EFAIL;
		goto del_err;
	}

	memset(&ufs, 0, sizeof(ufs_info_t));
	if(!READ_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
		sprintf(cmd, "[%s] %s Read Faild!!!", __func__, ufs_path);
		app_log_write( MSG_LOG_WRITE, cmd );
		eprintf("%s \n", cmd);
		ret = EFAIL;
		goto del_err;
	}

	if(ufs.hdr != UFS_HDR){
		eprintf("Invalid UFS Format!! \n");
		ret = EFAIL;
		goto del_err;
	}

	//# delete file
	if(ufs.fcnt > 0)
	{
		if(del_type == DEL_SIZE)
		{
			while( (ifile->storage.sa_size < ifile->storage.ft_size) && !app_cfg->state.pwroff )
			{
				sprintf(avi_path, "%s/%s", rec_path, ufs.flist[ufs.didx].fname);
				remove(avi_path);

				printf(" [File] Delete file: [%d]%s, size(storage,file): (%ld, %ld)\n", 
						ufs.didx, avi_path, ifile->storage.sa_size, ifile->storage.ft_size);

				if(ufs.flist[ufs.didx].fsize <= 0)
					ufs.flist[ufs.didx].fsize = get_file_size(ifile->storage.start_dir, ufs.flist[ufs.didx].fname);
				
				ifile->storage.ft_size -= ufs.flist[ufs.didx].fsize;
				ufs.tsize -= ufs.flist[ufs.didx].fsize;
				ufs.flist[ufs.didx].del = 1;
				ufs.didx++;
				
				if(ufs.didx+1 >= MAX_FREC_CNT)
					break;
				
				//# update first file rec time
				if(strlen(ufs.flist[ufs.didx].fname) > 0){
					ifile->storage.start_sec = get_recorded_sec(ufs.flist[ufs.didx].fname);
				}
				else{
					ifile->find_start_sec = 0;
					ifile->storage.start_sec = 0;
				}
			}
		}
		else	//# DEL_TIME
		{
			while( (ifile->storage.end_sec - ifile->storage.start_sec > MAX_REC_TIME) && !app_cfg->state.pwroff )
			{
				if(ufs.flist[ufs.didx].del == 0)
				{
					if(ufs.flist[ufs.didx].fsize <= 0)
						ufs.flist[ufs.didx].fsize = get_file_size(ifile->storage.start_dir, ufs.flist[ufs.didx].fname);
				
					sprintf(avi_path, "%s/%s", rec_path, ufs.flist[ufs.didx].fname);
					remove(avi_path);
					
					printf(" [File] Delete file: [%d]%s, size(storage,file): (%ld, %ld)\n", 
							ufs.didx, avi_path, ifile->storage.sa_size, ifile->storage.ft_size);
					
					ifile->storage.ft_size -= ufs.flist[ufs.didx].fsize;
					ufs.tsize -= ufs.flist[ufs.didx].fsize;
					ufs.flist[ufs.didx].del = 1;
				}
				
				ufs.didx++;
				if(ufs.didx+1 >= MAX_FREC_CNT)
					break;
				
				//# update first file rec time
				if(strlen(ufs.flist[ufs.didx].fname) > 0){
					ifile->storage.start_sec = get_recorded_sec(ufs.flist[ufs.didx].fname);
				}
				else{
					ifile->find_start_sec = 0;
					ifile->storage.start_sec = 0;

					break;
				}
			}		
		}
	}

	LSEEK_SET(fd, 0);
	if(!WRITE_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
		eprintf("%s Write Faild!! \n", ufs_path);
		ret = EFAIL;		
	}

del_err:
	SAFE_CLOSE(fd);

	if(ufs.didx+1 >= MAX_FREC_CNT){	//# All file deleted then, delete dir and move to next dir...
		ifile->find_start_sec 		= 0;
		ifile->storage.start_sec 	= 0;
		set_next_start_dir();
	}
	

	OSA_mutexUnlock(&ifile->mutex_file);

	return ret;
}



static void* file_check_main(void* prm)
{
    app_thr_obj *tObj   = (app_thr_obj *)prm;

    int cmd, f_cycle, exit = 0;

    printf(" [task] %s start\n", __func__);

    f_cycle 	= 0;
    tObj->done 	= 0;

    while(!exit)
    {
    	app_cfg->wd_flags |= WD_FILE;

        cmd = tObj->cmd;
        if(cmd == UBX_CMD_STOP)
            break;

		if(ifile->root_idx < REC_STOR_MAX && app_cfg->state.cap && !app_cfg->state.pwroff)
		{
			//# per 1 min
	        if((f_cycle!=0) && ((f_cycle % FILE_LIST_CHECK_TIME) == 0) && app_cfg->state.rec)
	        {
	            f_cycle = 0;
	            if(app_cfg->state.hdd || app_cfg->state.mmc){
					if(ifile->storage.sa_size <= ifile->storage.ft_size)	//# storage size over
						file_delete(DEL_SIZE);
#ifdef USE_3DAY_REC
					if(ifile->storage.end_sec > 0 && ifile->storage.start_sec > 0)
					{
						if(ifile->storage.end_sec - ifile->storage.start_sec > MAX_REC_TIME)
						{	//# recording time over
							file_delete(DEL_TIME);
							if(ifile->storage.start_sec > 0)
							{
								struct tm ts;
								char cmd[CHAR_128]={0,};
								localtime_r((const time_t *)&ifile->storage.start_sec, &ts);
								sprintf(cmd, " Del Start: %d/%d/%d_%d:%d:%d", 
										ts.tm_year+1900, ts.tm_mon+1, ts.tm_mday, ts.tm_hour, ts.tm_min, ts.tm_sec);
								app_log_write( MSG_LOG_WRITE, cmd );
								printf("%s \n", cmd);
							}							
						}
					}
#endif					
	           	}
	        }
		}

        OSA_waitMsecs(FILE_LIST_CYCLE);
        f_cycle += FILE_LIST_CYCLE;
    }

    tObj->done = 1;

    printf(" [task] %s done\n", __func__);
    return NULL;
}



static void dir_list_delete_all(void)
{
	app_dir_list_t* plist = &ilist;

	if(plist->head != NULL)
	{
		app_dir_entry_t* pNext;
		app_dir_entry_t* pCurr = plist->head;

		while(pCurr != NULL)
		{
			pNext = pCurr->next;
			app_mfree(pCurr);
			pCurr = pNext;
		}
	}
}



static int make_dir_list(dir_info_t* pdir)
{
	if(ifile == NULL)
		return EFAIL;

	app_dir_list_t* plist = &ilist;

	app_dir_entry_t* pNew	= app_malloc(sizeof(app_dir_entry_t));
	app_dir_entry_t* pTail 	= (app_dir_entry_t*)plist->tail;

	if(pNew == NULL)
	{
		eprintf("file entry create failed!!\n");
		OSA_mutexUnlock(&ifile->mutex_file);
		return EFAIL;
	}

	pNew->prev = NULL;
	pNew->next = NULL;
	strncpy(pNew->dir.dir_name, pdir->dir_name, CHAR_16);

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

	//#--- update dir count & start, cur dir info
	ifile->storage.dir_cnt++;
	if(ifile->storage.dir_cnt == 1) 
		sprintf(ifile->storage.start_dir, "%s", plist->tail->dir.dir_name);

	//# update cur_dir name...
	sprintf(ifile->storage.cur_dir, "%s", plist->tail->dir.dir_name);
	
	return SOK;
}


static int read_dir_info(dir_info_t* pdir, int first_dir)
{
	FILE *fd;
	ufs_info_t ufs;
	char ufs_path[CHAR_64] = {0,};

	sprintf(ufs_path, "%s/%s/%s.%s", rec_root[ifile->root_idx], pdir->dir_name, pdir->dir_name, UFS_EXT);
//	printf(" [File] Read %s...\n", ufs_path);
	
	if(access(ufs_path, 0) == -1){
		eprintf("File not exist : %s \n", ufs_path);
		return -1;
	}
	
	if(!OPEN_RDWR(fd, ufs_path)){
		eprintf("UFS file open fail!!\n ");
		return -1;
	}

	//# dfs headr check
	memset(&ufs, 0, sizeof(ufs_info_t));
	if(!READ_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
		eprintf("UFS file read fail!!\n ");
		CLOSE(fd);
		return -1;
	}
	
	if(ufs.hdr != UFS_HDR){
		eprintf("Invalid UFS Format!! \n");
		CLOSE(fd);
		return -1;
	}

	//# update total file size if file size zero.
	if(ufs.fcnt > 0)
	{
		int i;
		if(first_dir)
		{
			ufs.didx	= MAX_FREC_CNT;
			ufs.tsize 	= 0;
			for(i = 0; i < ufs.fcnt; i++)
			{
				if(access_file(pdir->dir_name, ufs.flist[i].fname) == SOK){
					ufs.flist[i].fsize = get_file_size(pdir->dir_name, ufs.flist[i].fname);
					ufs.flist[i].del = 0;					
					ufs.tsize += ufs.flist[i].fsize;	//# update total file size
					
					//next delete file idx update.
					if(ufs.didx == MAX_FREC_CNT)	
						ufs.didx = i;
				}
				else{ 	//# file is deleted!!
					ufs.flist[i].del = 1;
				}
				
				//# set up recorded time that is first delelte.
				if(ifile->find_start_sec == 0 && ufs.flist[i].del == 0){
					ifile->find_start_sec = 1;				
					ifile->storage.start_sec = get_recorded_sec(ufs.flist[i].fname);
				}
			}		
		}
		else
		{
			for(i = 0; i < ufs.fcnt; i++)
			{
				if(!ufs.flist[i].del && ufs.flist[i].fsize == 0){	//# file size is zero!!
					ufs.flist[i].fsize = get_file_size(pdir->dir_name, ufs.flist[i].fname);
					ufs.tsize += ufs.flist[i].fsize;	//# update total file size							
				}
				
				//# set up recorded time that is first delelte.
				if(ifile->find_start_sec == 0 && ufs.flist[i].del == 0){
					ifile->find_start_sec = 1;				
					ifile->storage.start_sec = get_recorded_sec(ufs.flist[i].fname);
				}
			}
		}
	}

	LSEEK_SET(fd, 0);

	WRITE_PTSZ(fd, &ufs, sizeof(ufs_info_t));
	CLOSE(fd);

	ifile->storage.ft_size += ufs.tsize;
	return 0;
}

static int create_new_dir(int dir_idx, char* file_name)
{
	int ret = 0;
	FILE* fd;
	dir_info_t new_dir;
	ufs_info_t ufs;
	
	char dir_path[CHAR_64] = {0,};
	char ufs_path[CHAR_64] = {0,};
	
	memset(&new_dir, 0, sizeof(dir_info_t));
	memset(&ufs, 0, sizeof(ufs_info_t));

	sprintf(new_dir.dir_name, "%08d", dir_idx);
	sprintf(dir_path, "%s/%s", rec_root[ifile->root_idx], new_dir.dir_name);

	if(access(dir_path, 0) == 0) {
		eprintf(" %s dir is exist!!!\n", new_dir.dir_name);
		return EFAIL;
    }

	//# make new dir
	mkdir(dir_path, 0775);
	chmod(dir_path, 0775);


	//# init udf file...
	sprintf(ufs_path, "%s/%s/%s.%s", rec_root[ifile->root_idx], new_dir.dir_name, new_dir.dir_name, UFS_EXT);
	if(!OPEN_CREATE(fd, ufs_path)){
		eprintf("%s create failed!!!\n", ufs_path);
		return EFAIL;
	}

	ufs.hdr = UFS_HDR;	//# UFS Header code

	if(file_name){
		//write file name, fcnt
		sprintf(ufs.flist[ufs.fcnt].fname, "%s", file_name);
		ufs.fcnt++;
		printf(" [File] Create File[%d]: %s\n", ufs.fcnt, file_name);		
	}


	if(!WRITE_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
		CLOSE(fd);
		eprintf("%s Write Faild!! \n", ufs_path);
		return EFAIL;		
	}
	
	CLOSE(fd);
	ret = make_dir_list(&new_dir);
	
	printf(" [File] added dir : %s =====\n", ifile->storage.cur_dir);
	printf(" [File] %d dir ---------------\n", ifile->storage.dir_cnt);
	
	return ret;
}

static int dir_scan(void)
{
	int i=0, dcnt=0, first=0;
	struct stat sb;
	struct dirent *entry;
	DIR *dir;

	if(lstat(rec_root[ifile->root_idx], &sb) != 0) {
		eprintf("%s fault\n", rec_root[ifile->root_idx]);
		return EFAIL;
	}

	dir_info_t tdir[MAX_DIR_CNT];
	memset(tdir, 0, sizeof(dir_info_t)*MAX_DIR_CNT);

	dir = opendir(rec_root[ifile->root_idx]);
	while((entry = readdir(dir)))
	{
		if(entry->d_type == DT_DIR && (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) )
			continue;

		sprintf(tdir[dcnt].dir_name, "%s", entry->d_name);
		dcnt++;		
	}
	closedir(dir);

	qsort(tdir, dcnt, sizeof(dir_info_t), cmpold);

	//# read dir info & make dir list
	if(dcnt){
		for(i = 0; i < dcnt; i++){
			first = 0;
			app_cfg->wd_flags = WD_FSCAN;
			if(i == 0) first = 1;
			if(read_dir_info( &tdir[i], first )== 0)
				make_dir_list(&tdir[i]);
		}
	}

//	printf(" [FILE] Total File Size: %ld(KB)\n", ifile->storage.ft_size);

	return 0;
}

static void check_rec_dir()
{
	//# record directory init ---
	if(app_cfg->state.hdd){
    	if(-1 == access(DIR_REC, 0)) {
    		mkdir(DIR_REC, 0775);
    		chmod(DIR_REC, 0775);
    	}
    }
	
    if(app_cfg->state.mmc){
        if(-1 == access(DIR_REC_MMC, 0)) {
    		mkdir(DIR_REC_MMC, 0775);
    		chmod(DIR_REC_MMC, 0775);
    	}
    }
}


int app_file_start(void)
{
	int status;
    app_thr_obj *tObj;
	char msg[255];
	
    ifile = &t_file;
    memset(ifile, 0, sizeof(app_file_t));
	ifile->root_idx = REC_STOR_MAX;

    printf(" [app] %s start...\n", __func__);    

	//# Set recording storage (HDD or SD)
	if( app_cfg->state.hdd )
		ifile->root_idx = REC_HDD;
	else if( app_cfg->state.mmc )
		ifile->root_idx = REC_SD;

	if(ifile->root_idx == REC_STOR_MAX)	{//Empty All Storage!!
		eprintf(" Storage not detected!!!\n");
		goto run_file_main;
//		return EFAIL;
	}

    //# record directory init ---
    check_rec_dir(0);

	app_log_write( MSG_LOG_WRITE, "[APP_FILE] Start file scanning...");

	disk_info_t idisk;
	if(util_disk_info(&idisk, rec_root[ifile->root_idx]) != 0){
		eprintf("Get disk size fail!!");
		sprintf(msg, "[APP_FILE] !!! Get disk size failed !!! - %s", rec_root[ifile->root_idx]);
		app_log_write( MSG_LOG_WRITE, msg );

		app_cfg->state.mmc_sz 		= 1;
        app_cfg->state.sd_buzzer 	= 1;
	}

	ifile->storage.sa_size = ((unsigned long long)idisk.total*DIR_PER)/100;	//# Used 95% size of disk total size.

	if(!app_cfg->state.mmc_sz){
		app_cfg->wd_flags = WD_FSCAN;

		//# dir scan...
		dir_scan();
		
		//# Create new dir, if empty rec dir
		if(ifile->storage.dir_cnt == 0){
			create_new_dir(1, NULL);	//# start index 1
		}

		pwr_led_run( ON );
		app_cfg->wd_flags = 0;

		if(abs(ifile->storage.sa_size - ifile->storage.ft_size) > idisk.avail){
			sprintf(msg, "[APP_FILE] !!! Not enough SD storage(%s)-total: %ld, avail: %ld, file: %ld (KB)\n", 
					rec_root[ifile->root_idx], ifile->storage.sa_size, idisk.avail, ifile->storage.ft_size);
			app_log_write( MSG_LOG_WRITE, msg );
			
			eprintf("!!! Not enough SD storage(%s)-total: %ld, avail: %ld, file: %ld (KB)\n", 
					rec_root[ifile->root_idx], ifile->storage.sa_size, idisk.avail, ifile->storage.ft_size);
			
			app_cfg->state.mmc_sz 		= 1;
            app_cfg->state.sd_buzzer 	= 1;
			app_cfg->state.secu_on 		= 1;
		}

		sprintf(msg, ">>>>>>> [%s] Storage Status <<<<<<<",rec_root[ifile->root_idx]);
		app_log_write( MSG_LOG_WRITE, msg );
		printf("%s \n", msg);

		sprintf(msg, " 95%% DiskSize : %ld(KB)", ifile->storage.sa_size);
		app_log_write( MSG_LOG_WRITE, msg );
		printf("%s \n", msg);
		
		sprintf(msg, " File TotSize  : %ld(KB)", ifile->storage.ft_size);
		app_log_write( MSG_LOG_WRITE, msg );
		printf("%s \n", msg);

		sprintf(msg, " StartDir : %s", ifile->storage.start_dir);
		app_log_write( MSG_LOG_WRITE, msg );
		printf("%s \n", msg);

		sprintf(msg, " CurDir   : %s", ifile->storage.cur_dir);
		app_log_write( MSG_LOG_WRITE, msg );
		printf("%s \n", msg);

		if(ifile->storage.start_sec > 0){
			struct tm ts;
			localtime_r((const time_t *)&ifile->storage.start_sec, &ts);
			sprintf(msg, " Del Start: %d/%d/%d_%d:%d:%d", 
						ts.tm_year+1900, ts.tm_mon+1, ts.tm_mday, ts.tm_hour, ts.tm_min, ts.tm_sec);
			app_log_write( MSG_LOG_WRITE, msg );
			printf("%s \n", msg);
		}

		printf("==============================\n");		
	}

#ifdef FREC_TEST
//		ifile->storage.sa_size = (150*KB);
#endif


run_file_main:

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

		dir_list_delete_all();

		ifile = NULL;
    }

    printf(" [app] %s done!\n", __func__);
}

int app_get_dir_name(char* rec_path)
{
	int ret = EFAIL;
	if(ifile->storage.dir_cnt > 0 && strlen(ifile->storage.cur_dir) > 0 ){
		sprintf(rec_path, "%s/%s", rec_root[ifile->root_idx], ifile->storage.cur_dir);
		ret = SOK;
	}

	return ret;
}

int	app_file_update(char* file_name, int close)
{
	int new_dir = 0;
	
	if(ifile == NULL)
		return EFAIL;

	if(ifile->storage.dir_cnt == 0)
		return EFAIL;

	OSA_mutexLock(&ifile->mutex_file);

	int ret = SOK;
	FILE* fd;
	ufs_info_t ufs;
	char ufs_path[CHAR_64] = {0,};
	

	sprintf(ufs_path, "%s/%s/%s.%s", rec_root[ifile->root_idx], ifile->storage.cur_dir, ifile->storage.cur_dir, UFS_EXT);
	if(!OPEN_RDWR(fd, ufs_path)){
		eprintf("%s Open Faild!!!\n", ufs_path);
		ret = EFAIL;
		goto update_err;
	}

	memset(&ufs, 0, sizeof(ufs_info_t));
	if(!READ_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
		eprintf("%s Read Faild!!!\n", ufs_path);
		ret = EFAIL;
		goto update_err;
	}

	if(ufs.hdr != UFS_HDR){
		eprintf("Invalid UFS Format!! \n");
		ret = EFAIL;
		goto update_err;
	}

	//# New dir create if same MAX_FREC_CNT
	if(!close && (ufs.fcnt+1) >= MAX_FREC_CNT){
		new_dir = 1;
		goto update_err;
	}

	if(!close){		//# file opened... add file name
		//write file name, fcnt
		sprintf(ufs.flist[ufs.fcnt].fname, "%s", file_name);
        ufs.flist[ufs.fcnt].fsize = 0; //don't list show current file
		printf(" [File] Create File[%d]: %s\n", ufs.fcnt, file_name);
		ufs.fcnt++;		
	}
	else{			//# file closed... update file size
		ufs.flist[ufs.fcnt-1].fsize = get_file_size(ifile->storage.cur_dir, file_name);
		ufs.tsize += ufs.flist[ufs.fcnt-1].fsize;
		ifile->storage.ft_size += ufs.flist[ufs.fcnt-1].fsize;
		
		printf(" [File] Update File[%d]: %s[%ld KB] \n", ufs.fcnt, file_name, ufs.flist[ufs.fcnt-1].fsize);
		printf(" [FILE] Size(storage,file): %ld(KB), %ld(KB)\n", ifile->storage.sa_size, ifile->storage.ft_size);
	}
	
	LSEEK_SET(fd, 0);

	if(!WRITE_PTSZ(fd, &ufs, sizeof(ufs_info_t))){
		eprintf("%s Write Faild!! \n", ufs_path);
		ret = EFAIL;		
	}

update_err:
	SAFE_CLOSE(fd);

	if(new_dir){
		int dir_num = 0;
		dir_num = (unsigned int)atoi(ifile->storage.cur_dir);
		create_new_dir(dir_num+1, file_name);
	}

	unsigned long trec = 0;
	trec = get_recorded_sec(file_name);
	
	//# update first file rec time if first dir, first file
	if(!ifile->find_start_sec){
		ifile->storage.start_sec = trec;
		ifile->find_start_sec = 1;

		if(ifile->storage.start_sec > 0){
			struct tm ts;
			char msg[CHAR_128]={0,};
			localtime_r((const time_t *)&ifile->storage.start_sec, &ts);
			sprintf(msg, " Del Start: %d/%d/%d_%d:%d:%d", 
						ts.tm_year+1900, ts.tm_mon+1, ts.tm_mday, ts.tm_hour, ts.tm_min, ts.tm_sec);
			app_log_write( MSG_LOG_WRITE, msg );
			printf("%s \n", msg);
		}		
	}
	
	//# update end file rec time
	ifile->storage.end_sec = trec;
	
	OSA_mutexUnlock(&ifile->mutex_file);

	return ret;
}


static int read_vod_info(dir_info_t* pdir, ufs_info_t* pufs)
{
	FILE *fd;
	ufs_info_t ufs;
	char ufs_path[CHAR_64] = {0,};
	char dir_path[CHAR_64] = {0,};

	sprintf(dir_path, "%s/%s", rec_root[ifile->root_idx], pdir->dir_name);
	sprintf(ufs_path, "%s/%s.%s", dir_path, pdir->dir_name, UFS_EXT);
	printf(" [File] Read %s...\n", ufs_path);
	
	if(access(ufs_path, 0) == -1){
		eprintf("File not exist : %s \n", ufs_path);
		return -1;
	}
	
	if(!OPEN_RDWR(fd, ufs_path)){
		eprintf("UFS file open fail!!\n ");
		return -1;
	}

	//# dfs headr check
	memset(&ufs, 0, sizeof(ufs_info_t));
	if(!READ_PTSZ(fd, pufs, sizeof(ufs_info_t))){
		eprintf("UFS file read fail!!\n ");
		CLOSE(fd);
		return -1;
	}
	
	if(pufs->hdr != UFS_HDR){
		eprintf("Invalid UFS Format!! \n");
		CLOSE(fd);
		return -1;
	}

	CLOSE(fd);

	return 0;
}

static int app_file_folder_cnt()
{
    int folder_cnt=0;
    char dir_path[CHAR_64] = {0,};
    sprintf(dir_path, "%s", rec_root[ifile->root_idx]);
    struct dirent *dir_ent;
    DIR  *dp;

    if ((dp = opendir(dir_path)) == NULL)
    {
        return folder_cnt;
    }

    while ((dir_ent = readdir(dp)) != NULL)
    {
        if (strcmp(dir_ent->d_name, ".") == 0 || strcmp(dir_ent->d_name, "..") == 0)
            continue;

        ++folder_cnt;
    }

    printf("Folder Count = %d\n", folder_cnt);
    closedir(dp);    

    return folder_cnt;
}

int app_file_get_list( frec_info_t** flist, int descending )
{
    int folder_cnt=app_file_folder_cnt();
    
	if (ifile == NULL) return 0;
	if(ifile->storage.dir_cnt == 0) return 0;    
    if(folder_cnt == 0) return 0;

	int dir_idx = 0, frec_cnt = 0, frec_idx = 0;
	int d,f;
	ufs_info_t* ufs_info=malloc(sizeof(ufs_info_t)*folder_cnt);
	app_dir_list_t* plist = &ilist;

	app_dir_entry_t* pNext;
	app_dir_entry_t* pCurr;

	//memset(&ufs_info, 0, sizeof(ufs_info));

//	if(!descending) //ascending
	{	
		pCurr = plist->head;
		while(pCurr != NULL)
		{
			pNext = pCurr->next;

			//# read ufs_info file
			read_vod_info(&pCurr->dir, &ufs_info[dir_idx]);
			frec_cnt += ufs_info[dir_idx].fcnt;
			dir_idx++;
			
			pCurr = pNext;
		}	
	}
#if 0 
	else{				//descending
		pCurr = plist->tail;
		while(pCurr != NULL)
		{
			pNext = pCurr->prev;

			//# read ufs_info file
			read_vod_info(&pCurr->dir, &ufs_info[dir_idx]);
			frec_cnt += ufs_info[dir_idx].fcnt;
			dir_idx++;
			
			pCurr = pNext;
		}	
	}
#endif
	if(frec_cnt == 0) return 0;

	*flist = (frec_info_t*)app_malloc(sizeof(frec_info_t)*frec_cnt);

	//# File list-up
	if(!descending){
		for(d = 0; d < dir_idx; d++)
		{
			for(f = 0; f < ufs_info[d].fcnt; f++)
			{
				if(ufs_info[d].flist[f].del == 0 && ufs_info[d].flist[f].fsize > 0){
					sprintf( (*flist)[frec_idx].fname, "%s.avi", strtok( ufs_info[d].flist[f].fname, "." ));
					(*flist)[frec_idx].fsize = ufs_info[d].flist[f].fsize;
					frec_idx++;
				}
			}
		}
	}
	else{
		for(d = dir_idx-1; d >= 0; d--)
		{
			for(f = ufs_info[d].fcnt-1; f >= 0 ; f--)
			{
				if(ufs_info[d].flist[f].del == 0 && ufs_info[d].flist[f].fsize > 0){
					sprintf( (*flist)[frec_idx].fname, "%s.avi", strtok( ufs_info[d].flist[f].fname, "." ));
					(*flist)[frec_idx].fsize = ufs_info[d].flist[f].fsize;
					frec_idx++;
				}
			}
		}		
	}

    free(ufs_info);

	return frec_idx;
}

void app_file_free_list(frec_info_t** flist)
{
	if(*flist != NULL){
		app_mfree(*flist);
		*flist = NULL;
	}
}

char* app_file_get_dir_path(char* fname, int descending )
{
	if (ifile == NULL) return NULL;
	if(ifile->storage.dir_cnt == 0) return NULL;

	int f;
	static char dir_path[CHAR_64] = {0,};
	
	ufs_info_t ufs_info;

	app_dir_list_t* plist = &ilist;
	app_dir_entry_t* pNext;
	app_dir_entry_t* pCurr;

	if(!descending) //ascending
	{	
		pCurr = plist->head;
		while(pCurr != NULL)
		{
			pNext = pCurr->next;

			//# read ufs_info file
			read_vod_info(&pCurr->dir, &ufs_info);
			for(f = 0; f < ufs_info.fcnt; f++){
				if( (ufs_info.flist[f].del == 0) && (strcmp( fname, ufs_info.flist[f].fname ) == 0)){
					sprintf(dir_path, "%s/%s", rec_root[ifile->root_idx], pCurr->dir.dir_name);
					goto find_path;		
				}
			}

			pCurr = pNext;
		}	
	}
	else{				//descending
		pCurr = plist->tail;
		while(pCurr != NULL)
		{
			pNext = pCurr->prev;

			//# read ufs_info file
			read_vod_info(&pCurr->dir, &ufs_info);
			for(f = ufs_info.fcnt-1; f >= 0; f--){
				if( (ufs_info.flist[f].del == 0) && (strcmp( fname, ufs_info.flist[f].fname ) == 0)){
					sprintf(dir_path, "%s/%s", rec_root[ifile->root_idx], pCurr->dir.dir_name);
					goto find_path;		
				}
			}
			
			pCurr = pNext;
		}	
	}


find_path:
	
	return dir_path;
}


int get_root_idx(void)
{
	int ret = EFAIL;

	if(ifile)
		ret = ifile->root_idx;

	return ret;
}



