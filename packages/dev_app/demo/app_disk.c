/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_disk.c
 * @brief   disk/file management routine
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <dirent.h>
#include <sys/stat.h>
#include <sys/vfs.h>
#include <sys/types.h>

#define _GNU_SOURCE
#include <ftw.h>
#include <fnmatch.h>
#include <fts.h>

#include "dev_common.h"

#include "app_comm.h"
#include "app_main.h"
#include "app_rec.h"
#include "app_disk.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define PROC_MOUNTS		"/proc/mounts"

#define BLOCK_SIZE  	512
#define CHK_STR_NUM		17

typedef struct {
	app_thr_obj nObj;		//# thread

	unsigned long disk_size;
} app_disk_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_disk_t disk_obj;
static app_disk_t *idsk=&disk_obj;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    file list create/delete function
* @section  [desc]
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

flist_t *disk_flist_create(char *path, char *filters, int sort)
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

void disk_flist_delete(flist_t *flist)
{
	if(flist != NULL)
		free(flist);
}

/*----------------------------------------------------------------------------
 get file list of directory
-----------------------------------------------------------------------------*/
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
	        	//dprintf("%s, %s\n", tmp, node->fts_name);
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
* @brief    get disk size function
* @section  [return] disk total size (KB)
*****************************************************************************/
long disk_get_size(disk_sz_t *dsz, const char *path)
{
	struct statfs lstatfs;
	long total;

	if(statfs(path, &lstatfs) != 0) {
		eprintf("%s fail\n", path);
		return -1;
	}

	if(dsz != NULL) {
		total =
		dsz->total = (lstatfs.f_blocks * (lstatfs.f_bsize/KB))/KB;
		dsz->avail = (lstatfs.f_bavail * (lstatfs.f_bsize/KB))/KB;
		dsz->free = (lstatfs.f_bfree * (lstatfs.f_bsize/KB))/KB;
		dsz->used = dsz->total - dsz->free;
		dprintf("%s, total %ld, avail %ld, free %ld, used %ld\n", path, dsz->total, dsz->avail, dsz->free, dsz->used);
	} else {
		total = (lstatfs.f_blocks * (lstatfs.f_bsize/KB))/KB;
	}

	return total;
}

/*****************************************************************************
* @brief    get_dir_size function
* @section  [desc]
*****************************************************************************/
long disk_get_dir_sz(const char *path)
{
	struct stat sb;
	long sum;

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

	//dprintf("%s sum %ld, size %ld KB\n", path, sum, (sum/1024)*BLOCK_SIZE);

	return (long)(((sum/1024)*BLOCK_SIZE)/KB);
}

/*****************************************************************************
* @brief    check record directory function
* @section  [desc]
*****************************************************************************/
void disk_chk_rec_dir(char *dir, int clear)
{
	if(clear)	//# for delete all recorded files
	{
		char cmd[128];
		dprintf("---------- delete all recorded filses ----------\n");
		sprintf(cmd, "rm -rf %s", dir);
		util_sys_exec(cmd);
	}

	//# record directory init ---
	if(-1 == access(dir, 0)) {
		mkdir(DIR_REC, 0775);
		chmod(DIR_REC, 0775);
		sync();
	}

	//# init disk size & rec direcotry size
	idsk->disk_size = disk_get_size(NULL, DIR_DISK);
	dprintf("disk total size = %ld KB\n", idsk->disk_size);
}

/*****************************************************************************
* @brief    check mount function
* @section  [return] 1: mount disk, 0:no mount
*****************************************************************************/
int disk_check_mount(char *dev)
{
	FILE *fp;
	int detect=0;
	char line[512], devname[128];

	fp = fopen(PROC_MOUNTS, "r");
	if (fp == NULL) {
		eprintf("cannot open %s\n", PROC_MOUNTS);
		return detect;
	}

	while (fgets(line, sizeof(line), fp))
	{
		sscanf(line, "%s", devname);
		if(!strncmp(devname, dev, strlen(dev)-1)) {
			detect = 1;
			break;
		}
	}

	fclose(fp);

	return detect;
}

/****************************************************
 * NAME : int dev_mmc_format(void)
 ****************************************************/
static int mmc_format(void)
{
	DIR *mmcdir;

	char sysdir[256] = {0,};
	int minor;

	/* find mmcblk* minor */
	for (minor = 0; minor <= 256; minor++) {
		snprintf(sysdir, sizeof(sysdir), "/sys/block/mmcblk%d/", minor);
		if (access(sysdir, F_OK) == 0)
			break;
	}
	if (minor >= 256) {
		dev_err("couldn't find mmcblk**\n");
		return -1;
	}

	/* fixme: one more try?? */
	mmcdir = opendir(sysdir);
	if (mmcdir == NULL) {
		dev_dbg("invalid mmcblkid %s\n", sysdir);
		return -1;
	}
	closedir(mmcdir);

	memset(sysdir, 0, sizeof(sysdir));
	snprintf(sysdir, sizeof(sysdir),
				"/sbin/mkfs.fat /dev/mmcblk%d""p1 -s 64 -F 32\n", minor);

	/* if device busy condition */
	dev_execlp("/bin/umount /mmc");
	/* fat format execute */
	dev_execlp(sysdir);

	return minor;
}

/*****************************************************************************
* @brief    sd card format function
* @section  DESC Description
*   - desc
*****************************************************************************/
int disk_sd_format(void)
{
	char cmd[256] = {0,};
	int blkid = 0;

	printf("/*--- SD card Format start --------------------------*/\n");
	sleep(1);

	/* force umount */
	blkid = mmc_format();
	if (blkid < 0) {
		eprintf("Failed to format sdcard\n");
		/* todo: return or reboot?? */
		return -1;
	}

	/* writing config files */
	snprintf(cmd, sizeof(cmd),
			"/bin/mount -t vfat /dev/mmcblk%d""p1 /mmc", blkid);
	util_sys_exec(cmd);
	sleep(1);

	disk_chk_rec_dir(DIR_REC, 0);	//# record directory create
	sync();

	sleep(1);
	printf("/*--- done ------------------------------------------*/\n");

	return 0;
}
