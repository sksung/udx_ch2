/*
 * File : app_udev.c
 *
 * Copyright (C) 2015 UDWORKs
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
 */

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <app_main.h>
#include <app_udev.h>

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define FXN_UDEV_THR_PRI		(FXN_THR_PRI_DEFAULT + 1)
#define UDEV_LS_CMD				"/usr/bin/lsusb"

#define RTL_USB_MAX_NUM			4

#define RTL_8188E_VID			0x0bda
#define RTL_8188E_PID			0x8179

#define RTL_8188C_VID			0x0bda
#define RTL_8188C_PID			0x8176

#define RTL_8821A_VID			0x0bda
#define RTL_8821A_PID			0xA811

#define RTL_8192E_VID			0x0bda
#define RTL_8192E_PID			0x818B

/* Wi-Fi Module Path */
#define RTL_8188E_PATH			"/lib/modules/8188eu.ko"
#define RTL_8188C_PATH			"/lib/modules/8192cu.ko"
#define RTL_8821A_PATH			"/lib/modules/8821au.ko"
#define RTL_8192E_PATH			"/lib/modules/8192eu.ko"

/* Wi-Fi Module name */
#define RTL_8188E_NAME			"8188eu"
#define RTL_8188C_NAME			"8192cu"
#define RTL_8821A_NAME			"8821au"
#define RTL_8192E_NAME			"8192eu"

#define PROC_MODULE_FNAME		"/proc/modules"

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
typedef struct {
	app_thr_obj *uObj;

} app_udev_data_t;

struct rtl_usb_list_t {
	int d_vid;
	int d_pid;
};

static struct rtl_usb_list_t rtl_list[RTL_USB_MAX_NUM] = {
	{
		.d_vid = RTL_8188E_VID,
		.d_pid = RTL_8188E_PID,
	},
	{
		.d_vid = RTL_8188C_VID,
		.d_pid = RTL_8188C_PID,
	},
	{
		.d_vid = RTL_8821A_VID,
		.d_pid = RTL_8821A_PID,
	},
	{
		.d_vid = RTL_8192E_VID,
		.d_pid = RTL_8192E_PID,
	}
};

static app_udev_data_t app_udev_data;
static app_udev_data_t *app_udev_pdata = &app_udev_data;

/*****************************************************************************
* @brief    get usb wi-fi connection status.
* @section  DESC Description
*   - desc
*****************************************************************************/
static int udev_get_state(int udev_vid, int udev_pid)
{
	FILE *lsfs;

	char cmd[128] = {0,};
	char buf[256] = {0,};

	char vid[5];
	char pid[5];
	int r = 0;

	char *sptr;

	vid[4] = '\0';
	snprintf(vid, sizeof(vid), "%04x", udev_vid);

	pid[4] = '\0';
	snprintf(pid, sizeof(pid), "%04x", udev_pid);

	lsfs = popen(UDEV_LS_CMD, "r");
	if (lsfs != NULL) {
		while (fgets(buf, 255, lsfs) != NULL) {
			char *v, *p;
			/* %*s->discard input */
			memset(cmd, 0, sizeof(cmd));
			sscanf(buf, "%*s%*s%*s%*s%*s%s", cmd);
			/* splite ":" */
			if (cmd != NULL) {
				v = strtok_r(cmd, ":", &sptr);
				p = strtok_r(NULL, ":", &sptr);

				if ((strncmp(v, vid, 4) == 0) &&
					(strncmp(p, pid, 4) == 0))
				{
					r = 1; //# founded usb
					break;
				}
			}
		}
	} else {
		eprintf("couldn't open %s command\n", UDEV_LS_CMD);
	}
	pclose(lsfs);

	return r;
}

static int udev_get_module_state(const char *module_name)
{
	char lbuf[256] = {0,};
    FILE *proc;

	size_t length = 0;
	int res = 0;

	if (module_name == NULL)
		return res;

    if ((proc = fopen(PROC_MODULE_FNAME, "r")) == NULL) {
        eprintf("Could not open %s\n", PROC_MODULE_FNAME);
        return res;
    }

	length = strlen(module_name);
    while ((fgets(lbuf, sizeof(lbuf), proc)) != NULL) {
        if (strncmp(lbuf, module_name, length) == 0) {
            res = 1; //# find module name.
            break;
        }
    }
    fclose(proc);

    return res;
}

static int udev_driver_load(const char *path, const char *name)
{
	char buf[256] = {};
	int r, cnt;

	FILE *f = NULL;

	/* load driver */
	snprintf(buf, sizeof(buf), "/sbin/insmod %s", path);
	f = popen(buf, "w");
	if (f == NULL) {
		eprintf("couln't execute /sbin/insmod!!\n");
		return -1;
	}
	pclose(f);

	/* waiting for driver loaded */
	cnt = 20; /* max 2sec */
	do {
		r = udev_get_module_state(name);
		THR_waitmsecs(100);
		cnt--;
	} while ((r == 0) && (cnt > 0));

	if (cnt <= 0) {
		eprintf("Failed to loading %s driver!!\n", name);
		return -1;
	}

	return 0;
}

static void udev_driver_unload(const char *name)
{
	char buf[256] = {};
	FILE *f = NULL;

	int r, cnt;

	/* unload driver */
	snprintf(buf, sizeof(buf), "/sbin/rmmod %s", name);
  	f = popen(buf, "w");
	if (f == NULL) {
		eprintf("couln't execute /sbin/rmmod!!\n");
		return;
	}
	pclose(f);

	/* waiting for driver loaded */
	cnt = 10; /* max 1sec */
	do {
		r = udev_get_module_state(name);
		THR_waitmsecs(100);
		cnt--;
	} while ((r > 0) && (cnt > 0));

	if (cnt <= 0) {
		eprintf("Failed to unloading wi-fi driver!!\n");
	}
}

static void udev_driver_enable(int enable)
{
	char buf[256] = {0,};
	FILE *f = NULL;

	if (enable)
		snprintf(buf, sizeof(buf), "/sbin/ifconfig wlan0 up");
	else
		snprintf(buf, sizeof(buf), "/sbin/ifconfig 0.0.0.0 down");

	f = popen(buf, "w");
	if (f != NULL)
		pclose(f);
}

/*****************************************************************************
* @brief   usb poll thread main function.
*   - desc
*****************************************************************************/
static void *app_udev_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	struct rtl_usb_list_t *plist;

	char path[128] = {0,};
	char name[128] = {0,};
	char cmd;

	int exit = 0;

	printf(" [task] %s start\n", __func__);

	tObj->active = 1;
	while (!exit)
	{
		int i, r;

		cmd = tObj->cmd;
		if (cmd == APP_CMD_STOP) {
			exit = 1;
			break;
		}

		plist = rtl_list;
		for (i = 0; i < (sizeof(rtl_list) / sizeof(struct rtl_usb_list_t)); i++, plist++) {
			r = udev_get_state(plist->d_vid, plist->d_pid);
			if (r > 0) {
				//# dprintf("detected Wi-Fi dev[%x, %x]\n", plist->d_vid, plist->d_pid);
				break;
			}
		}

		if (r > 0)
		{
			if (!app_cfg->ste.bit.udev) {
				/* module unload state */
				memset(path, '\0', sizeof(path));
				memset(name, '\0', sizeof(name));

				if ((plist->d_vid == RTL_8188E_VID) && (plist->d_pid == RTL_8188E_PID)) {
					strcpy(path, RTL_8188E_PATH);
					strcpy(name, RTL_8188E_NAME);
				} else if ((plist->d_vid == RTL_8188C_VID) && (plist->d_pid == RTL_8188C_PID)) {
					strcpy(path, RTL_8188C_PATH);
					strcpy(name, RTL_8188C_NAME);
				} else if ((plist->d_vid == RTL_8192E_VID) && (plist->d_pid == RTL_8192E_PID)) {
					strcpy(path, RTL_8192E_PATH);
					strcpy(name, RTL_8192E_NAME);
				} else {
					strcpy(path, RTL_8821A_PATH);
					strcpy(name, RTL_8821A_NAME);
				}

				r = udev_get_module_state(name);
				if (!r) {
					r = udev_driver_load(path, name); /* module load */
				} else {
					r = 0; /* already done module loading!! */
				}

				if (!r) {
					/* success */
					if (!app_cfg->ste.bit.wifi_on) {
						/* if-up wlan0 */
						udev_driver_enable(1);
						app_cfg->ste.bit.wifi_on = 1;
					}
				} else {
					/* module loading failure */
					app_cfg->ste.bit.wifi_on = 0;
				}

				app_cfg->ste.bit.udev = 1; /* don't clear udev flag */
			} else {
				/* TODO: this case is error state or Wi-Fi run state.. */
			}
		} else {
			if (app_cfg->ste.bit.udev) {
				/* required stop Wi-Fi and module unload */
				if (app_cfg->ste.bit.wifi_on) {
					/* TODO */
					udev_driver_enable(0);
					app_cfg->ste.bit.wifi_on = 0;
				}

//				udev_driver_unload(RTL_8188E_NAME);
				app_cfg->ste.bit.udev = 0;
			}
		}

//		dprintf("current usb %s!\n", app_cfg->ste.bit.udev ? "inserted":"removed");
		/* for next event */
		THR_waitmsecs(300);
	}

	tObj->active = 0;

	printf(" [app ] %s exit\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    initialize for poll usb device.
* @section  [desc]
*****************************************************************************/
int app_udev_init(void)
{
	struct sched_param schedprm;
	app_thr_obj *tObj;

	pthread_attr_t tattr;
	pthread_mutexattr_t muattr;
  	pthread_condattr_t cond_attr;

	THR_semHndl *pSem;

	int r = FXN_ERR_UDEV_INIT;

	tObj = (app_thr_obj *)malloc(sizeof(app_thr_obj));
	if (tObj != NULL) {
		pSem = &tObj->sem;

		/* mutex and thread create */
		pthread_mutexattr_init(&muattr);
  		pthread_condattr_init(&cond_attr);

  		pthread_mutex_init(&pSem->lock, &muattr);
  		pthread_cond_init(&pSem->cond, &cond_attr);

  		pSem->count = 0;
  		pSem->maxCount = MAX_PENDING_SEM_CNT;

		pthread_condattr_destroy(&cond_attr);
 	 	pthread_mutexattr_destroy(&muattr);

		/* initialize thread attributes structure */
	  	pthread_attr_init(&tattr);
	  	pthread_attr_setinheritsched(&tattr, PTHREAD_EXPLICIT_SCHED);
	  	pthread_attr_setschedpolicy(&tattr, SCHED_FIFO);

	  	schedprm.sched_priority = FXN_UDEV_THR_PRI;
	  	pthread_attr_setschedparam(&tattr, &schedprm);

		r = pthread_create(&tObj->thr.hndl, &tattr,
						app_udev_main, (void *)tObj);
		pthread_attr_destroy(&tattr);

		if (!r) {
			//# resgister thread obj
			app_udev_pdata->uObj = tObj;
		} else {
			eprintf("Couldn't Create thread [ret = %d]!\n", r);
			r = -1;
		}
	} else {
		eprintf("Failed to alloc app udev obj!!\n");
	}

	if (r < 0)
		r = FXN_ERR_UDEV_INIT;

	return r;
}

/*****************************************************************************
* @brief    deinitialize for poll usb device.
* @section  [desc]
*****************************************************************************/
int app_udev_exit(void)
{
	app_thr_obj *tObj;
	THR_semHndl *pSem;
  	void *rVal;
	int r = -1;

  	if (app_udev_pdata == NULL)
  		return r;

	/* delete usb monitor object */
	tObj = (app_thr_obj *)app_udev_pdata->uObj;
	if (tObj != NULL) {
		THR_event_send(tObj, APP_CMD_STOP, 0, 0);
		while (tObj->active) {
			THR_waitmsecs(20);
		}

		pSem = &tObj->sem;
		pthread_cond_destroy(&pSem->cond);
	  	pthread_mutex_destroy(&pSem->lock);

	  	r |= pthread_cancel(tObj->thr.hndl);
	  	r |= pthread_join(tObj->thr.hndl, &rVal);

		free(tObj);
		tObj = NULL;
	}

	return r;
}
