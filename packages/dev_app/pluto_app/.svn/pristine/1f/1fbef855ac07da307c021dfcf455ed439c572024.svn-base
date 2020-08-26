/******************************************************************************
 * UCX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_hotplug.c
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
#include <unistd.h>
#include <fcntl.h>

#include <sys/poll.h>
#include <sys/types.h>
#include <sys/stat.h>

//# remove warning: 'struct mmsghdr' declared inside parameter list
#define __USE_GNU
#include <sys/socket.h>
#include <unistd.h>

#include <linux/types.h>
#include <linux/netlink.h>

#include "ucx_main.h"
#include "app_rec.h"
#include "app_ctrl.h"
#include "app_dev.h"
#include "app_util.h"
#include "app_set.h"

#include "dev_common.h"
#include "dev_gpio.h"
#include "dev_wifi.h"
#include "dev_micom.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
/*
 * 0-> RTL 8188E usb
 * 1-> RTL 8188C usb
 * 2-> RTL 8192C usb
 * 3-> RTL 8821A usb
 * 4-> RTL 8192E usb
 */
#define NETLINK_USB_DEVS_MAX	RTL_USB_MAX_NUM //# 5
#define NETLINK_POLL_TIMEOUT	300
#define NETLINK_GROUP_KERNEL	1

#define NETLINK_USB_PATH		"/sys/bus/usb/devices"

struct usb_session_t {
	int sid;   /* busnum << 8 | devnum */
	int vid;   /* vendor id */
	int pid;   /* product id */
};

typedef struct {
	app_thr_obj *kObj;	    //# kobject netlink object
	app_thr_obj *rtlObj;	//# Wi-Fi detect thread

	struct usb_session_t usb_ss[NETLINK_USB_DEVS_MAX];
	int fd;

} app_netlink_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_netlink_t t_nlink = {.fd = -1,};
static app_netlink_t *inlink = &t_nlink;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/
static const char *netlink_message_parse (const char *buffer, size_t len, const char *key)
{
	size_t keylen = strlen(key);
	size_t offset;

	for (offset = 0 ; offset < len && '\0' != buffer[offset] ; offset += strlen(buffer + offset) + 1) {
		if (0 == strncmp(buffer + offset, key, keylen) &&
		    '=' == buffer[offset + keylen]) {
			return buffer + offset + keylen + 1;
		}
	}

	return NULL;
}

/*----------------------------------------------------------------------------
 netlink read sysfs
-----------------------------------------------------------------------------*/
static int netlink_read_sysfs_attr(const char *devname, const char *attr)
{
	char filename[1024 + 1];
	char buf[256 + 1] = {0,};
	char *r;

	FILE *f;
	int value;

	snprintf(filename, sizeof(filename), "%s/%s/%s", NETLINK_USB_PATH, devname, attr);
	f = fopen(filename, "r");
	if (f == NULL) {
		dprintf("open %s failed\n", filename);
		return -1;
	}
	r = fgets(buf, 255, f);
	fclose(f);

	sscanf(buf, "%x", &value);
	if (value < 0) {
		dprintf("%s contains a negative value\n", filename);
		return -1;
	}

	return value;
}

/*****************************************************************************
* @brief    parse parts of netlink message (get subsystem)
* @section  DESC Description
*   - desc
*****************************************************************************/
static int netlink_subsystem_parse(char *buffer, size_t len, int *subsystem, int *detached)
{
	const char *tmp;

	*detached = 0;
	*subsystem = -1; /* default unknown device */

	tmp = netlink_message_parse((const char *) buffer, len, "ACTION");
	if (tmp == NULL)
		return -1;

	if (strcmp(tmp, "remove") == 0) {
		*detached = 1;
	} else if (strcmp(tmp, "add") != 0) {
//		dprintf("unknown device action %s\n", tmp);
		return -1;
	}

	/* check that this is a usb or mmc message */
	tmp = netlink_message_parse(buffer, len, "SUBSYSTEM");
	if (tmp == NULL)
		/* ignore message */
		return -1;

	if (strcmp(tmp, "mmc") == 0) {
		*subsystem = 0;
		return 0;
	} else if (strcmp(tmp, "usb") != 0) {
//		dprintf("unknown device subsystem %s\n", tmp);
		return -1;
	}
	*subsystem = 1; /* usb */

	return 0;
}

/*****************************************************************************
* @brief    parse parts of netlink message (for usb)
* @section  DESC Description
*   - desc
*****************************************************************************/
static int netlink_usb_get_attribute(char *buffer, size_t len, const char **sys_name,
			       unsigned char *busnum, unsigned char *devaddr)
{
	const char *tmp;
	int i;

	*sys_name = NULL;
	*busnum   = 0;
	*devaddr  = 0;

	tmp = netlink_message_parse(buffer, len, "BUSNUM");
	if (NULL == tmp) {
//		eprintf("Failed to netlink_message_parse(BUSNUM)\n");
		return -1;
	}

	/* 0-> hub, 1-> usb port 1, 2-> usb port 2*/
	*busnum = (unsigned char)(strtoul(tmp, NULL, 10) & 0xff);
	if (*busnum < 0 || *busnum > 2) {
		/* invalid bus number (olny supported bus: 0, 1, 2)*/
//		eprintf("invalid bus number(%d)\n", *busnum);
		return -1;
	}

	tmp = netlink_message_parse(buffer, len, "DEVNUM");
	if (NULL == tmp) {
//		eprintf("Failed to netlink_message_parse(DEVNUM)\n");
		return -1;
	}
	*devaddr = (unsigned char)(strtoul(tmp, NULL, 10) & 0xff);

	tmp = netlink_message_parse(buffer, len, "DEVPATH");
	if (NULL == tmp) {
		eprintf("Failed to netlink_message_parse(DEVPATH)\n");
		return -1;
	}

	for (i = strlen(tmp) - 1 ; i ; --i) {
		if ('/' == tmp[i]) {
			*sys_name = tmp + i + 1;
			break;
		}
	}

	return 0;
}

/*****************************************************************************
* @brief    static int netlink_usb_attach_parse(char *buffer, size_t len)
*****************************************************************************/
static int netlink_usb_detach_parse(char *buffer, size_t len, int *v, int *p)
{
	const char *sys_name = NULL;
	struct usb_session_t *pusb_ss;

	unsigned long session_id = 0;

	unsigned char busnum;
	unsigned char devaddr;

	int i, r;

	r = netlink_usb_get_attribute(buffer, len, &sys_name, &busnum, &devaddr);
	if (r < 0) {
		return -1;
	}

	session_id = (busnum << 8 | devaddr);
	for (i = 0; i < NETLINK_USB_DEVS_MAX; i++) {
		pusb_ss = &inlink->usb_ss[i];

//		printf("pusb_ss->sid %x, session_id %x\n", pusb_ss->sid, session_id);
		if (pusb_ss->sid == session_id) {
			break;
		}
	}

	if (i >= NETLINK_USB_DEVS_MAX) {
		printf("Not found usb session id (det = %lx)!!\n", session_id);
		return -1;
	}

	pusb_ss = &inlink->usb_ss[i];
	pusb_ss->sid = 0; //# clear session.

	*v = pusb_ss->vid; *p = pusb_ss->pid;

	return 0;
}

/*****************************************************************************
* @brief static int netlink_usb_attach_parse(char *buffer, size_t len, int *v, int *p)
*****************************************************************************/
static int netlink_usb_attach_parse(char *buffer, size_t len, int *v, int *p)
{
	const char *sys_name = NULL;
	struct usb_session_t *pusb_ss;

	unsigned long session_id = 0;

	unsigned char busnum;
	unsigned char devaddr;

	int r = 0, i;
	int vendor, product;

#if 0  //# for debugging
	i = 0;
	r = len;
	while (r-- >= 0) {
		fputc(buffer[i++], stdout);
		fflush(stdout);
	}
	fprintf(stdout, "\n");
#endif

	r = netlink_usb_get_attribute(buffer, len, &sys_name, &busnum, &devaddr);
	if (r < 0) {
//		printf("Failed to netlink_usb_get_attribute\n");
		return -1;
	}

	session_id = (busnum << 8 | devaddr);
	/* open idVendor sysfs */
	vendor = netlink_read_sysfs_attr(sys_name, "idVendor");
	if (vendor < 0) {
//		printf("Failed to netlink_read_sysfs_attr(idVendor)\n");
		return -1;
	}

	/* open idProduct sysfs */
	product = netlink_read_sysfs_attr(sys_name, "idProduct");
	if (product < 0) {
		eprintf("Failed to netlink_read_sysfs_attr(idProduct)\n");
		return -1;
	}

	for (i = 0; i < NETLINK_USB_DEVS_MAX; i++) {
		pusb_ss = &inlink->usb_ss[i];

		if (pusb_ss->sid == session_id) {
			dprintf("already founded usb devices.(%x:%x)\n", vendor, product);
			return -1;
		}
	}

	if (vendor == RTL_8188E_VID && product == RTL_8188E_PID) {
		pusb_ss = &inlink->usb_ss[0];
	} else if (vendor == RTL_8188C_VID && product == RTL_8188C_PID) {
		pusb_ss = &inlink->usb_ss[1];
	} else if (vendor == RTL_8192C_VID && product == RTL_8192C_PID) {
		pusb_ss = &inlink->usb_ss[2];
	} else if (vendor == RTL_8821A_VID && product == RTL_8821A_PID) {
		pusb_ss = &inlink->usb_ss[3];
	} else if (vendor == RTL_8192E_VID && product == RTL_8192E_PID) {
		pusb_ss = &inlink->usb_ss[4];
	} else
		/* not supported device. */
		return -1;

	pusb_ss->sid = session_id;
	pusb_ss->vid = vendor;
	pusb_ss->pid = product;

	*v = vendor; *p = product;

//	printf("attached usb session id %x\n", session_id);
	return 0;
}

static int netlink_check_wifi(void)
{
	struct stat sb;
	FILE *f;

	char path[1024 + 1];

	int busnum, value;
	int d_vid, d_pid;

	int r = -1;

	/*
	 * if wi-fi connected, can't detection netlink socket
	 * so manual connection start.
	 */
	busnum = 2; /* default */
	r = dev_wifi_is_exist(&d_vid, &d_pid);
	if (r < 0) {
		return -1;
	}

	memset(path, 0, sizeof(path));
	snprintf(path, sizeof(path), "%s/2-1/devnum", NETLINK_USB_PATH);

	r = stat(path, &sb);
	if (r) {
		busnum = 1;
		memset(path, 0, sizeof(path - 1));
		snprintf(path, sizeof(path), "%s/1-1/devnum", NETLINK_USB_PATH);
		r = stat(path, &sb);
		if (r)
			return -1;
	}

	f = fopen(path, "r");
	if (f != NULL) {
		fscanf(f, "%d", &value);
		fclose(f);

		if ((d_vid == RTL_8188E_VID) && (d_pid == RTL_8188E_PID)) {
			inlink->usb_ss[0].sid = (busnum << 8 | value);
			inlink->usb_ss[0].vid = RTL_8188E_VID;
			inlink->usb_ss[0].pid = RTL_8188E_PID;
		} else if((d_vid == RTL_8188C_VID) && (d_pid == RTL_8188C_PID)) {
			inlink->usb_ss[1].sid = (busnum << 8 | value);
			inlink->usb_ss[1].vid = RTL_8188C_VID;
			inlink->usb_ss[1].pid = RTL_8188C_PID;
		} else if((d_vid == RTL_8192C_VID) && (d_pid == RTL_8192C_PID)) {
			inlink->usb_ss[2].sid = (busnum << 8 | value);
			inlink->usb_ss[2].vid = RTL_8192C_VID;
			inlink->usb_ss[2].pid = RTL_8192C_PID;
		} else if((d_vid == RTL_8821A_VID) && (d_pid == RTL_8821A_PID)) {
			inlink->usb_ss[3].sid = (busnum << 8 | value);
			inlink->usb_ss[3].vid = RTL_8821A_VID;
			inlink->usb_ss[3].pid = RTL_8821A_PID;
		} else if((d_vid == RTL_8192E_VID) && (d_pid == RTL_8192E_PID)) {
			inlink->usb_ss[4].sid = (busnum << 8 | value);
			inlink->usb_ss[4].vid = RTL_8192E_VID;
			inlink->usb_ss[4].pid = RTL_8192E_PID;
		}
	} else {
		r = -1;
	}

	return r;
}

/*****************************************************************************
* @brief    netlink_scan_main function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void *netlink_scan_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;

	struct pollfd pfd;
	struct sockaddr_nl nls;

	char msg[1024] = {0,};

	struct iovec iov = {.iov_base = msg, .iov_len = sizeof(msg)};
	struct msghdr meh = {.msg_iov = &iov, .msg_iovlen = 1,
		.msg_name=&nls, .msg_namelen = sizeof(nls)};

	size_t len;

	int ret, detached;
	int cmd, sub;
	int exit = 0, flags;
	int v = 0, p = 0;

	printf(" [task] %s start...\n", __func__);
	tObj->done = 0;

	sub = 0; detached = 0;

	/* Initialize kernel uevent */
	memset(&nls, 0, sizeof(nls));
	nls.nl_family = AF_NETLINK;
	/* if the destination is in kernel, always 0 */
	nls.nl_pid = 0; /* self pid */
	/* from kernel (-1:0xffffffff, all received groups) */
	nls.nl_groups = NETLINK_GROUP_KERNEL; //# bit mask group..

	/* Open hotplug event netlink socket */
	inlink->fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
	if (inlink->fd < 0) {
		dprintf("netlink scan thread exit!!\n");
		return NULL;
	}

	flags = fcntl(inlink->fd, F_GETFD);
	if (flags < 0) {
		dprintf("fcntl %x\n", flags);
		close(inlink->fd);
		return NULL;
	}

	if (!(flags & FD_CLOEXEC)) {
		fcntl(inlink->fd, F_SETFD, flags | FD_CLOEXEC);
	}

	flags = fcntl(inlink->fd, F_GETFL);
	if (flags < 0) {
		close(inlink->fd);
		return NULL;
	}

	if (!(flags & O_NONBLOCK)) {
		fcntl(inlink->fd, F_SETFL, flags | O_NONBLOCK);
	}

	/* Listen to netlink socket (non-block and close execution) */
	ret = bind(inlink->fd, (void *)&nls, sizeof(struct sockaddr_nl));
	if (ret < 0) {
		dprintf("scan thread exit (ret %d)!!\n", ret);
		close(inlink->fd);
		return NULL;
	}

	pfd.events = POLLIN;
	pfd.revents = 0;
	pfd.fd = inlink->fd;

	if (!netlink_check_wifi()) {
		event_send(inlink->rtlObj, UBX_CMD_RTL_DETECTED, 0, 0);
	}

	while(!exit)
	{
		cmd = tObj->cmd;
        if (cmd == UBX_CMD_STOP) {
            break;
        }

		//# wait event
		ret = poll(&pfd, 1, NETLINK_POLL_TIMEOUT); //# timeout 300ms
		if (ret > 0)
		{
			if (pfd.revents & POLLIN) {
				memset(msg, 0, sizeof(msg));

				//len = recv(inlink->fd, buffer, sizeof(buffer), MSG_DONTWAIT);
				len = recvmsg(inlink->fd, &meh, 0);
				if (len > 32)
				{
					ret = netlink_subsystem_parse(msg, len, &sub, &detached);
					if (!ret)
					{
						#if 0
						dprintf("founded subsystem: usb, removed: %s\n", detached ? "yes" : "no");
						#endif

						if (sub) {
							/* usb parse */
							if (detached) {
								if (netlink_usb_detach_parse(msg, len, &v, &p) == 0)
								{
									if (((v == RTL_8188E_VID) && (p == RTL_8188E_PID)) ||
										((v == RTL_8188C_VID) && (p == RTL_8188C_PID)) ||
										((v == RTL_8192C_VID) && (p == RTL_8192C_PID)) ||
 									    ((v == RTL_8821A_VID) && (p == RTL_8821A_PID)) ||
									    ((v == RTL_8192E_VID) && (p == RTL_8192E_PID))
									   )
									{
										event_send(inlink->rtlObj, UBX_CMD_RTL_REMOVED, 0, 0);
									}
								}
							} else {
								if (netlink_usb_attach_parse(msg, len, &v, &p) == 0)
								{
									if (((v == RTL_8188E_VID) && (p == RTL_8188E_PID)) ||
										((v == RTL_8188C_VID) && (p == RTL_8188C_PID)) ||
										((v == RTL_8192C_VID) && (p == RTL_8192C_PID)) ||
									    ((v == RTL_8821A_VID) && (p == RTL_8821A_PID)) ||
									    ((v == RTL_8192E_VID) && (p == RTL_8192E_PID))
									   )
									{
										event_send(inlink->rtlObj, UBX_CMD_RTL_DETECTED, 0, 0);
									}
								}
							}
						}
					}
				}
			}
		}
		/* for next event : wait */
		OSA_waitMsecs(50);
	}

	if (inlink->fd >= 0) {
		close(inlink->fd);
		inlink->fd = -1;
	}
    tObj->done = 1;

	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
 * @brief    monitor RTL wifi main function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
static void *mon_rtl_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;

	int cmd;
	int exit = 0;

	printf(" [task] %s start...\n", __func__);
	tObj->done = 0;

	while (!exit)
	{
		//# wait cmd
		cmd = event_wait(tObj);
		if (cmd == UBX_CMD_STOP) {
			break;
		}

		switch (cmd)
		{
			case UBX_CMD_RTL_DETECTED:
			{
				if (!app_cfg->state.wifi)
					ctrl_wifi_set(ON);
			}
			break;
			case UBX_CMD_RTL_REMOVED:
			{
				char name[128] = {0,};
				int unload = 0;
				int i, r;

				/* turn off wi-fi..*/
				ctrl_wifi_set(0);

				if (dev_wifi_get_module_state(RTL_8188E_NAME)) {
					strcpy(name, RTL_8188E_NAME);
					unload = 1;
				} else if (dev_wifi_get_module_state(RTL_8188C_NAME)) {
					strcpy(name, RTL_8188C_NAME);
					unload = 1;
				} else if (dev_wifi_get_module_state(RTL_8821A_NAME)) {
					strcpy(name, RTL_8821A_NAME);
					unload = 1;
				} else if (dev_wifi_get_module_state(RTL_8192E_NAME)) {
					strcpy(name, RTL_8192E_NAME);
					unload = 1;
				}
				if (unload) {
	            	dev_wifi_unload((const char *)name);
	            	/* waiting for driver loaded */
					for (i = 20; i < 0; i--) {
						r = dev_wifi_get_module_state(name);
						if (!r)
							break;
						else
							OSA_waitMsecs(100);
					}
	            }
	       	}
			break;
		}
	}
    tObj->done = 1;

	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    Hot Plug thread start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
void app_hotplug_start(void)
{
	app_thr_obj *tObj;

	printf(" [app] %s start...\n", __func__);

	//# create RTL monitor thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if (tObj != NULL)
	{
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, mon_rtl_main, FXN_TSK_PRI, 0, tObj);
		//# resgister thread obj
		inlink->rtlObj = tObj;
	}
	else
	{
		eprintf("%s: RTL monitor thread malloc fail\n", __func__);
	}

	//# create netlink receive thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if (tObj != NULL)
	{
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, netlink_scan_main, FXN_TSK_PRI, 0, tObj);
		//# resgister thread obj
		inlink->kObj = tObj;
	}
	else
	{
		eprintf("%s: Kobject uevent monitor thread malloc fail\n", __func__);
	}
}

void app_hotplug_stop(void)
{
    app_thr_obj *tObj;

	if (inlink == NULL)
		return;

	/* delete RTL monitor object */
	tObj = (app_thr_obj *)inlink->rtlObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}

	/* delete netlink scan object */
    tObj = (app_thr_obj *)inlink->kObj;
    if (tObj != NULL)
    {
    	event_send(tObj, UBX_CMD_STOP, 0, 0);
		while (!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
    }
	inlink = NULL;

    printf(" [app] %s stop done...\n", __func__);
}
