/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_util.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#include <sys/vfs.h>
#include <sys/types.h>

#define _GNU_SOURCE
#include <ftw.h>
#include <fnmatch.h>
#include <fts.h>

#include "dev_common.h"
#include "ucx_main.h"
#include "app_util.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define BLOCK_SIZE  512
#define CHK_STR_NUM	17

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    util mem_alloc/free function
* @section  DESC Description
*   - desc
*****************************************************************************/
void *util_mem_alloc(unsigned int msize)
{
	void *ptr;

	//--- memory alloc ------------------------------------
	ptr = malloc (msize);

	return ptr;
}

void util_mem_free(void *ptr)
{
	//--- memory free ------------------------------------
	free (ptr);
}

/*****************************************************************************
* @brief    util memory copy function
* @section  DESC Description
*   - desc
*****************************************************************************/
int util_mem_copy(void *pDes, void *pSrc, int size)
{
    if (pDes == NULL || pSrc == NULL){
        return -1;
    }

	memcpy(pDes, pSrc, size);

    return 0;
}

/*****************************************************************************
* @brief    filelist create/delete function
* @section  DESC Description
*   - desc
*****************************************************************************/
static int cmpnew(const void * a, const void * b)
{
	fname_t *a_name = (fname_t *)a;
	fname_t *b_name = (fname_t *)b;

	return -(strcmp(a_name->name, b_name->name));
}

static int cmpold(const void * a, const void * b)
{
	fname_t *a_name = (fname_t *)a;
	fname_t *b_name = (fname_t *)b;

	return (strcmp(a_name->name, b_name->name));
}

flist_t *util_flist_create(char *path, char *filters, int sort)
{
	FTS *tree;
	FTSENT *node;
	flist_t *list;
	char const *scan[] = {NULL, NULL};

	scan[0] = path;
	tree = fts_open((char * const *)scan, FTS_NOCHDIR, NULL);
    if (!tree) {
        eprintf("Failed to fts_open\n");
        return NULL;
    }

    list = malloc(sizeof(flist_t));
    list->cnt = 0;

    while ((node = fts_read(tree)))
    {
        if (node->fts_info & FTS_F)
        {
            if (fnmatch(filters, node->fts_name, FNM_CASEFOLD) == 0)
            {
            	strcpy(list->f[list->cnt].path, node->fts_path);
            	strcpy(list->f[list->cnt].name, node->fts_name);
            	//dprintf("path: %s, name: %s\n", node->fts_path, node->fts_name);
            	list->cnt++;
            }
        }
        if(list->cnt > MAX_FLIST_NUM-1)
        	break;
    }

    if (fts_close(tree)) {
        eprintf("fts_close");
        if(list != NULL)
			free(list);
        return NULL;
    }

    if(sort)	//# new first
    	qsort(list->f, list->cnt, sizeof(fname_t), cmpnew);
    else
    	qsort(list->f, list->cnt, sizeof(fname_t), cmpold);

	return list;
}

void util_flist_delete(flist_t *flist)
{
	if(flist != NULL)
		free(flist);
}

static int get_file_path(char *path, char *file, char *filters, int first)
{
	FTS *tree;
	FTSENT *node;
	char const *scan[] = {NULL, NULL};
	char tmp[256];
	int flag=1;

	scan[0] = path;
	tree = fts_open((char * const *)scan, FTS_NOCHDIR, NULL);
    if (!tree) {
        eprintf("Failed to fts_open\n");
        return -1;
    }

    while ((node = fts_read(tree)))
    {
        if (node->fts_info & FTS_F)
        {
            if (fnmatch(filters, node->fts_name, FNM_CASEFOLD) == 0)
            {
            	if(flag) {
            		strcpy(tmp, node->fts_name);
            		flag = 0;
            		continue;
            	}

            	if(first) {
            		if(strncmp(tmp, node->fts_name, CHK_STR_NUM) < 0)
	        			strcpy(tmp, node->fts_name);
            	}
            	else {
	        		if(strncmp(tmp, node->fts_name, CHK_STR_NUM) > 0)
	        			strcpy(tmp, node->fts_name);
	        	}
            }
        }
    }

	sprintf(file, "%s/%s", path, tmp);

    if (fts_close(tree)) {
        eprintf("fts_close");
        return -1;
    }

    return 0;
}

/*****************************************************************************
* @brief    util disk info function
* @section  DESC Description
*   - desc
*****************************************************************************/
int util_disk_info(disk_info_t *idisk, const char *path)
{
	struct statfs lstatfs;

	if(statfs(path, &lstatfs) != 0) {
		eprintf("%s fault\n", path);
		return -1;
	}

	idisk->total = lstatfs.f_blocks * (lstatfs.f_bsize/KB);
	idisk->avail = lstatfs.f_bavail * (lstatfs.f_bsize/KB);
	idisk->used = idisk->total - (lstatfs.f_bfree * (lstatfs.f_bsize/KB));

	return 0;
}

/*****************************************************************************
* @brief    util get_dir_size function
* @section  DESC Description
*   - desc
*****************************************************************************/
long util_dir_size(const char *path)
{
	struct stat sb;
	unsigned long sum;

	DIR *dir;
	struct dirent *entry;
	char newfile[128];

	if(lstat(path, &sb) != 0) {
		eprintf("%s fault\n", path);
		return -1;
	}

	sum = sb.st_blocks;
	dir = opendir(path);
	while ((entry = readdir(dir)))
	{
		if (entry->d_type == DT_DIR)
			continue;
		sprintf(newfile, "%s/%s", path, entry->d_name);
		lstat(newfile, &sb);
		sum += sb.st_blocks;
	}
	closedir(dir);

	return (long)((sum/1024)*BLOCK_SIZE);
}

/*****************************************************************************
* @brief    time trace function
* @section  DESC Description
*   - desc  calculate the crc value
*****************************************************************************/
static unsigned long btime=0;
void __time_trace(int param)
{
	unsigned long pass_time;

	if(param) {
		btime = OSA_getCurTimeInMsec();
	}
	else {
		pass_time = OSA_getCurTimeInMsec() - btime;
		printf("---- %ld ms\n", pass_time);
		btime += pass_time;
	}
}
