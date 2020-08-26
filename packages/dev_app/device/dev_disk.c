/*
 * File : dev_disk.c
 *
 * Copyright (C) 2014 UDWORKs
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/mount.h>

#include <errno.h>		/* ERANGE */
#include <blkid.h>

#include "dev_common.h"
#include "dev_disk.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define MMC_BLK_NAME	"mmcblk"
#define MMC_MB			(1024*1024)

static const char *proc_part_path = "/proc/partitions";

/****************************************************
 * local function
 ****************************************************/
static int mmc_is_inserted(void)
{
	FILE *procfs;

	char buf[256] = {0,};
	char dev[128] = {0,};

	procfs = fopen(proc_part_path, "r");
	if (procfs == NULL) {
		dev_err("%s open failed\n", proc_part_path);
		return 0;
	}

	while (fgets(buf, 255, procfs)) {
		/* %*s->discard input */
		sscanf(buf, "%*s%*s%*s%s", dev);
		/* dev = mmcblk0 -> -1*/
		if (strncmp(dev, MMC_BLK_NAME, strlen(dev)-1) == 0) {
			fclose(procfs);
			return 1;
		}
		dev_dbg("dev %s(=%s)\n", dev, MMC_BLK_NAME);
	}
	fclose(procfs);

	return 0;
}

static int mmc_get_minor(void)
{
	DIR *mmcdir;
	char sysdir[256] = {0,};

	int minor = 0;

	/* find mmcblk* minor */
	for (minor = 0; minor <= 256; minor++) {
		snprintf(sysdir, sizeof(sysdir), "/sys/block/mmcblk%d/", minor);
		if (access(sysdir, F_OK) == 0)
			break;
	}
	if (minor >= 256) {
		dev_dbg("couldn't find mmcblk**\n");
		return -1;
	}

	mmcdir = opendir(sysdir);
	if (mmcdir == NULL) {
		dev_dbg("invalid mmcblkid %s\n", sysdir);
		return -1;
	}
	closedir(mmcdir);

	return minor;
}

/****************************************************
 * NAME : int dev_disk_mmc_part_check_info(const char *blk_path,
 *					struct mmc_part_info *part_info)
 *
 ****************************************************/
int dev_disk_mmc_part_check_info(const char *blk_path,
					struct mmc_part_info *part_info)
{
	blkid_probe pr;
	blkid_partlist ls;
	blkid_partition par;

	int nparts;
	int ret = 0;

	if (part_info == NULL || !mmc_is_inserted()) {
		dev_err("sd card is not inserted\n");
		return -1;
	}

	pr = blkid_new_probe_from_filename(blk_path);
	if (!pr) {
		dev_err("%s: faild to create a new libblkid probe", blk_path);
		return -1;
	}

	part_info->part_no = 0;
	part_info->part_type = 0;

	/* Binary interface */
	ls = blkid_probe_get_partitions(pr);
	/*
	 * List partitions
	 */
	nparts = blkid_partlist_numof_partitions(ls);
	/* not supported multi partitions */
	if (!nparts) {
		part_info->part_no = 0;
		goto done;
	}

#if 0
	/* %j -> C99 intmax_t */
	printf("size: %jd\n", blkid_probe_get_size(pr));
#endif

	par = blkid_partlist_get_partition(ls, 0); //# fixed 0
	part_info->part_no = nparts;
	part_info->part_type = blkid_partition_get_type(par);
	part_info->part_size = (unsigned long)(blkid_probe_get_size(pr) / MMC_MB);

done:
	blkid_free_probe(pr);

	return ret;
}

/****************************************************
 * NAME : int dev_disk_mmc_part_unmount(const char *target_path)
 ****************************************************/
int dev_disk_mmc_part_unmount(const char *target_path)
{
	char cmd[512] = {};
	FILE *file = NULL;

#if 0
	snprintf(cmd, sizeof(cmd), "fuser -mk %s", target_path);
	file = popen(cmd, "r");
	if (file == NULL) {
		dev_err("couldn't exec %s\n", cmd);
		return -1;
	}
	pclose(file);
#endif

	//# Todo : fuser or lsof check??
	/* if device busy condition */
	memset(cmd, 0, sizeof(cmd));
	snprintf(cmd, sizeof(cmd), "umount %s", target_path);
	file = popen(cmd, "r");
	if (file == NULL) {
		dev_err("couldn't exec %s\n", cmd);
		return -1;
	}
	pclose(file);

	return 0;
}

/****************************************************
 * NAME : int dev_disk_mmc_part_delete(int part_no)
 ****************************************************/
int dev_disk_mmc_part_delete(int part_no)
{
	char cmd[512] = {};
	FILE *file = NULL;

	snprintf(cmd, sizeof(cmd), "parted -s %s rm %d",
						MMC_BLK_DEV_NAME, part_no);

	file = popen(cmd, "r");
	if (file == NULL) {
		dev_err("couldn't exec %s\n", cmd);
		return -1;
	}
	pclose(file);

	return 0;
}

/****************************************************
 * NAME : int dev_disk_mmc_part_create(void)
 ****************************************************/
int dev_disk_mmc_part_create(void)
{
	char cmd[512] = {0,};
	FILE *file = NULL;

	snprintf(cmd, sizeof(cmd), "parted -s %s -- mkpart primary fat32 2048s -1s",
							   MMC_BLK_DEV_NAME);

	file = popen(cmd, "r");
	if (file == NULL) {
		dev_dbg("couldn't exec %s\n", cmd);
		return -1;
	}
	pclose(file);

	return 0;
}

/****************************************************
 * NAME : int dev_disk_mmc_part_format(void)
 ****************************************************/
int dev_disk_mmc_part_format(unsigned long size)
{
	FILE *file = NULL;
	int blkid = 0;

	char buffer[256] = {0,};

	blkid = mmc_get_minor();
	if (blkid < 0) {
		dev_err("couldn't find mmc partition\n");
		return -1;
	}

	snprintf(buffer, sizeof(buffer), "/dev/mmcblk%d", blkid);
	if (dev_disk_check_mount(MMC_MOUNT_POINT))
		dev_disk_mmc_part_unmount(buffer);

	memset(buffer, 0, sizeof(buffer));

	if (size >= MMC_SIZE_128GB)
		/* sector size 512B, 64KB sector per cluster */
		snprintf(buffer, sizeof(buffer), "mkfs.fat -s 128 -F 32 /dev/mmcblk%dp1", blkid);
	else
		/* sector size 512B, 32KB sector per cluster */
		snprintf(buffer, sizeof(buffer), "mkfs.fat -s 64 -F 32 /dev/mmcblk%dp1", blkid);

	file = popen(buffer, "r");
	if (file == NULL) {
		dev_err("couldn't run %s\n", buffer);
		return -1;
	}
	pclose(file);

	return blkid;
}

/*******************************************************
 * NAME : int dev_disk_mmc_part_set_bootsector(int part_no, int on)
 *******************************************************/
int dev_disk_mmc_part_set_bootsector(int part_no, int on)
{
	char cmd[512] = {0,};
	FILE *file = NULL;

	snprintf(cmd, sizeof(cmd), "parted -s %s -- set %d boot %s",
							   MMC_BLK_DEV_NAME, part_no, on?"on":"off");

	file = popen(cmd, "r");
	if (file == NULL) {
		dev_dbg("couldn't exec %s\n", cmd);
		return -1;
	}
	pclose(file);

	return 0;
}

/*******************************************************
 * NAME : int dev_disk_mmc_part_set_lba_mode(int part_no, int on)
 *******************************************************/
int dev_disk_mmc_part_set_lba_mode(int part_no, int on)
{
	char cmd[512] = {0,};
	FILE *file = NULL;

	snprintf(cmd, sizeof(cmd), "parted -s %s -- set %d lba %s",
							   MMC_BLK_DEV_NAME, part_no, on?"on":"off");

	file = popen(cmd, "r");
	if (file == NULL) {
		dev_dbg("couldn't exec %s\n", cmd);
		return -1;
	}
	pclose(file);

	return 0;
}

/****************************************************
 * NAME : int dev_disk_check_mount(const char *mount_point)
 ****************************************************/
int dev_disk_check_mount(const char *mount_point)
{
	FILE *procfs = NULL;

	char line[256 + 1] = {0,};
	char proc_name[256 + 1] = {0,};

	int found = 0, length;

	procfs = fopen(MOUNT_PROC_PATH, "r");
	if (procfs == NULL) {
		dev_err("couldn't open %s\n", MOUNT_PROC_PATH);
		return 0; //# assume device is not mount.
	}

	length = strlen(mount_point);
	while (fgets (line, 256, procfs)) {
		sscanf(line, "%*s%s", proc_name);
		if (strncmp(proc_name, mount_point, length) == 0) {
		    found = 1;
		    break; //# founded
		}
	}
    fclose(procfs);

	return (found ? 1: 0);
}

/****************************************************
 * NAME : int dev_disk_check_mount_ex(const char *mount_point)
 ****************************************************/
int dev_disk_check_mount_ex(const char *mount_point, const char *mount_path)
{
	FILE *procfs = NULL;

	char line[256 + 1] = {0,};
	char m_name[256 + 1] = {0,};
	char m_path[256 + 1] = {0,};

	int found = 0;

	procfs = fopen(MOUNT_PROC_PATH, "r");
	if (procfs == NULL) {
		dev_err("couldn't open %s\n", MOUNT_PROC_PATH);
		return 0; //# assume device is not mount.
	}

	while (fgets (line, 256, procfs)) {
		sscanf(line, "%s %s", m_name, m_path);
		if (m_name[0] == mount_point[0] && m_name[1] == mount_point[1] && m_name[2] == mount_point[2]) {
		    found = 1;
			sprintf(mount_path, "%s", m_path);
		    break; //# founded
		}
	}
	
    fclose(procfs);

	return (found ? 1: 0);
}



