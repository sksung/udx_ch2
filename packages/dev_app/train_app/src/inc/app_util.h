/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_util.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_UTIL_H_
#define _APP_UTIL_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define MAX_FLIST_NUM	1000

#ifndef KB
#define KB	1024
#endif
#ifndef MB
#define MB	(KB*KB)
#endif

#define MAX_SZ_DRIVE	60	//# percent
#define MAX_SZ_PARK		20
#define MAX_SZ_EVENT	14
#define MAX_SZ_IMAGE	 1

typedef struct {
	char path[256];
	char name[256];
} fname_t;

typedef struct {
	int cnt;
	fname_t f[MAX_FLIST_NUM];
} flist_t;

typedef struct {
	unsigned long total;
	unsigned long avail;
	unsigned long used;
} disk_info_t;

typedef struct {
	long drive;
	long park;
	long event;
	long image;
} recdir_sz_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
#if 1
#define app_malloc	util_mem_alloc
#define app_mfree	util_mem_free
#define app_memcpy	util_mem_copy
#else
#define app_malloc	malloc
#define app_mfree	free
#define app_memcpy	memcpy
#endif

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
void *util_mem_alloc(unsigned int msize);
void util_mem_free(void *ptr);
int util_mem_copy(void *pDes, void *pSrc, int size);

flist_t *util_flist_create(char *path, char *filters, int sort);
void util_flist_delete(flist_t *flist);

int util_disk_info(disk_info_t *mp, const char *path);
long util_dir_size(const char *dir_path);
void __time_trace(int param);

#endif	/* _APP_UTIL_H_ */
