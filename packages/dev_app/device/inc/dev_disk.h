/*
 * dev_disk.h
 *
 * Copyright (C) 2014 UDWORKs.
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
#ifndef _DEV_DISK_H_
#define _DEV_DISK_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MMC_SDHC_HIGH_SIZE		32768  //# 32GB
#define MMC_SIZE_64GB			65536  //#
#define MMC_SIZE_128GB			131072 //#

#define MMC_MOUNT_POINT			"/mmc"
#define MMC_BLK_DEV_NAME		"/dev/mmcblk0"
#define MMC_PART_NAME			"/dev/mmcblk0p1"

#define MMC_PART_TYPE_EXFAT		0x7
#define MMC_PART_TYPE_FAT32		0xc

struct mmc_part_info {
	int part_no;
	int part_type;
	unsigned long part_size; //# MB unit.
};

/*
 * Declare Function Prototype.
 */
int dev_disk_mmc_part_check_info(const char *blk_path,
					struct mmc_part_info *part_info);
int dev_disk_mmc_part_unmount(const char *target_path);
int dev_disk_mmc_part_delete(int part_no);
int dev_disk_mmc_part_create(void);
int dev_disk_mmc_part_format(unsigned long size);
int dev_disk_mmc_part_set_bootsector(int part_no, int on);
int dev_disk_mmc_part_set_lba_mode(int part_no, int on);

int dev_disk_check_mount(const char *mount_point);
int dev_disk_check_mount_ex(const char *mount_point, const char *mount_path);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _DEV_DISK_H_ */
