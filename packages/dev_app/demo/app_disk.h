/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_disk.h
 * @brief
 */
/*****************************************************************************/

#ifndef _APP_DISK_H_
#define _APP_DISK_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define MAX_FLIST_NUM		2048

#define SORT_NEW_FIRST		1
#define SORT_OLD_FIRST		0

typedef struct {
	char path[256];
	char name[256];
} fname_t;

typedef struct {
	int cnt;
	fname_t f[MAX_FLIST_NUM];
} flist_t;

typedef struct {
	long total;
	long avail;
	long free;
	long used;
} disk_sz_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
flist_t *disk_flist_create(char *path, char *filters, int sort);
void disk_flist_delete(flist_t *flist);

long disk_get_size(disk_sz_t *dsz, const char *path);
long disk_get_dir_sz(const char *path);
void disk_chk_rec_dir(char *dir, int clear);

int disk_check_mount(char *dev);
int disk_sd_format(void);

#endif	/* _APP_DISK_H_ */
