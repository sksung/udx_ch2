/*
 * File : dev_common.c
 *
 * Copyright (C) 2013 UDWORKs
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
 * this implements a common hardware interface for UBX.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <ctype.h>
#include <wait.h>
#include <errno.h>
#include <linux/rtc.h>

#include <asm/types.h>
#include <sys/stat.h>

//# remove warning: 'struct mmsghdr' declared inside parameter list
#define __USE_GNU
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/statfs.h>
#include <sys/time.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <linux/types.h>
#include <linux/netlink.h>

#include "dev_common.h"

#define YEAR	((((__DATE__[7] - '0') * 10 + (__DATE__[8] - '0')) * 10 \
				+ (__DATE__[9] - '0')) * 10 + (__DATE__[10] - '0'))

#define MONTH 	(__DATE__[2] == 'n' ? (__DATE__[1] == 'a' ? 0 : 5) \
			  	:__DATE__[2] == 'b' ? 1 \
			  	:__DATE__[2] == 'r' ? (__DATE__[0] == 'M' ? 2 : 3) \
			  	:__DATE__[2] == 'y' ? 4 \
			  	:__DATE__[2] == 'l' ? 6 \
			  	:__DATE__[2] == 'g' ? 7 \
			  	:__DATE__[2] == 'p' ? 8 \
			  	:__DATE__[2] == 't' ? 9 \
			  	:__DATE__[2] == 'v' ? 10 : 11)

#define DAY		((__DATE__[4] == ' ' ? 0 : __DATE__[4] - '0') * 10 \
				+ (__DATE__[5] - '0'))

/****************************************************
 * NAME : int dev_input_get_bus_num(const char *dev_name)
 ****************************************************/
int dev_input_get_bus_num(const char *dev_name)
{
	FILE *file;

	char buffer[PATH_MAX];
	int find_field = 0;
	char *c;

	file = fopen(INPUT_PROC_PATH, "r");
    if (file == NULL) {
    	dev_err("%s read failed\n", INPUT_PROC_PATH);
       	return -1;
	}

    while (!feof(file)) {
    	memset(buffer, 0, sizeof(buffer));
    	fgets(buffer, sizeof(buffer), file);

    	if (!find_field && strstr(buffer, dev_name) != NULL) {
    		find_field = 1;
    	} else if (find_field) {
    		if (strstr(buffer, "Handlers=") != NULL) {
    			c = strstr(buffer, "event");
    			fclose(file);
    			return atoi(c+strlen("event"));
    		}
    	}
    }
    fclose(file);

    return -1;
}

/****************************************************
 * NAME : void dev_wait_for_msecs(unsigned int msecs)
 ****************************************************/
void dev_wait_for_msecs(unsigned int msecs)
{
  	struct timespec delayTime, elaspedTime;

  	delayTime.tv_sec  = msecs/1000;
  	delayTime.tv_nsec = (msecs%1000)*1000000;

  	nanosleep(&delayTime, &elaspedTime);
}

/****************************************************
 * NAME : int dev_get_board_info(void)
 ****************************************************/
int dev_get_board_info(void)
{
	char buf[256];
	ssize_t nbytes;
	int fd, ret, ver;

    fd = open("/proc/device_version", O_RDONLY);
    if (fd < 0)
    	return -1;

    memset(buf, 0, 256);
    nbytes = read(fd, buf, sizeof(buf) - 1);
    close(fd);

    if (nbytes < 0)
        return -1;

	buf[nbytes] = '\0';

	ret = sscanf(buf, "%d", &ver);
	if (ret <= 0)
		return -1;

    return ver;
}

/****************************************************
 * NAME : int dev_get_udx_info(void)
 ****************************************************/
int dev_get_udx_info(void)
{
	char buf[256];
	ssize_t nbytes;
	int fd, ret, ver;

    fd = open("/proc/udx_version", O_RDONLY);
    if (fd < 0)
    	return -1;

    memset(buf, 0, 256);
    nbytes = read(fd, buf, sizeof(buf) - 1);
    close(fd);

    if (nbytes < 0)
        return -1;

	buf[nbytes] = '\0';

	ret = sscanf(buf, "%d", &ver);
	if (ret <= 0)
		return -1;

    return ver;
}

/****************************************************
 * NAME : int dev_execlp(char *arg)
 ****************************************************/
int dev_execlp(char *arg)
{
    int numArg, i, j, k;
    int len, status;

    char exArg[10][64];
	pid_t chId;

    if (arg[0] == '\0')
        return 0;

    j = 0; 	k = 0;
	len = strlen(arg);

    for (i = 0; i < len; i++) {
        if (arg[i] == ' ') {
		    exArg[j][k] = '\0';
		    j ++; k = 0;
		} else {
		    exArg[j][k] = arg[i];
		    k ++;
		}
	}

    if (exArg[j][k - 1] == '\n') {
	    exArg[j][k - 1] = '\0';
	} else {
	    exArg[j][k] = '\0';
	}

	numArg = j + 1;

	if (numArg > 10) {
	    dev_dbg("The no of arguments are greater than 10" \
	    		"calling standard system function...\n");
	    return (system(arg));
	}

    chId = fork();
	if (chId == 0) {
	    // child process
	    switch (numArg) {
	    case 1:
	        execlp(exArg[0],exArg[0],NULL);
	        break;
	    case 2:
	        execlp(exArg[0],exArg[0],exArg[1],NULL);
	        break;
	    case 3:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],NULL);
	        break;
	    case 4:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],NULL);
	        break;
	    case 5:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               NULL);
	        break;
	    case 6:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],NULL);
	        break;
	    case 7:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],NULL);
	        break;
	    case 8:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],exArg[7],NULL);
	        break;
	    case 9:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],exArg[7],exArg[8],NULL);
	        break;
	    case 10:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],exArg[7],exArg[8],exArg[9],NULL);
	        break;
		}
//        dev_err("execlp failed...\n");
	    return -1;
	} else if(chId < 0) {
		dev_err("Failed to create child process\n");
		return -1;
	} else {
		/* parent process */
		/* wait for the completion of the child process */
		/* 3th option WNOHANG->non-block 0->block */
		if (waitpid(chId, &status, 0) > 0) {
			if (WIFEXITED(status)) {
				dev_dbg("Chiled exited with the code %d\n", WEXITSTATUS(status));
				return WEXITSTATUS(status);
			} else
				dev_err("Child terminated abnormally..\n");
		}
	}

    return 0;
}

/****************************************************
 * NAME : int dev_mmc_format(void)
 ****************************************************/
int dev_mmc_format(void)
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

/****************************************************
 * NAME : int dev_check_mount(const char *mount_point)
 ****************************************************/
int dev_check_mount(const char *mount_point)
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

/*
 * lsusb. (format)
 * Bus 001 Device 003: ID 1c9e:7801
 */
/****************************************************
 * NAME : int dev_usb_is_exist(int usb_v, int usb_p)
 ****************************************************/
int dev_usb_is_exist(int usb_v, int usb_p)
{
	FILE *lsusbfs;

	char cmd[128] = {0,};
	char buffer[256] = {0,};

	char vendor[5];
	char product[5];

	char *save_ptr;

	vendor[4] = 0;
	snprintf(vendor, sizeof(vendor), "%04x", usb_v);

	product[4] = 0;
	snprintf(product, sizeof(product), "%04x", usb_p);

	snprintf(cmd, sizeof(cmd), "/usr/bin/lsusb");
	lsusbfs = popen(cmd, "r");
	if (lsusbfs == NULL) {
		dev_err("couldn't access %s\n", cmd);
		return 0;
	}

	while (fgets(buffer, 255, lsusbfs) != NULL) {
		char *v, *p;
		/* %*s->discard input */
		memset(cmd, 0, sizeof(cmd));
		sscanf(buffer, "%*s%*s%*s%*s%*s%s", cmd);
		/* splite ":" */
		if (cmd != NULL) {
			v = strtok_r(cmd, ":", &save_ptr);
			p = strtok_r(NULL, ":", &save_ptr);

			if ((strncmp(v, vendor, 4) == 0) &&
				(strncmp(p, product, 4) == 0))
			{
				pclose(lsusbfs);
				return 1; //# founded usb
			}
		}
	}
	pclose(lsusbfs);

	return 0;
}


/******************************************************
 * NAME : int dev_rtc_set_time(struct tm set_tm)
 ******************************************************/
int dev_rtc_set_time(struct tm set_tm)
{
	int fd = -1, ret;

	fd = open("/dev/rtc0", O_RDONLY);
	if (fd < 0) {
		dev_err("Failed to open /dev/rtc0 device.\n");
		return fd;
	}

	ret = ioctl(fd, RTC_SET_TIME, &set_tm);
	if (ret < 0) {
		dev_err("Failed to ioctl (RTC_SET_TIME)!\n");
	}
	close(fd);

	return ret;
}
