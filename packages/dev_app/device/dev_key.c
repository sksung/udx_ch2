/*
 * File : dev_key.c
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
 * this implements a key-event hardware library for UBX.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <poll.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>

#include <linux/input.h>
#include <osa.h>

#include "dev_common.h"
#include "dev_key.h"

#define TSC_DEV_NAME 	"/dev/input/touchscreen0"
#define KEY_DEV_NAME 	"gpio-keys"

#define GESTURE_CNT		5
#define GESTURE_VAL		50

static int kbd_fd = -1;
static int tsc_fd = -1;

static int active = 0;

//# touch data
typedef struct {
	int xmin;
	int xmax;
	int ymin;
	int ymax;
} ts_data_t;

static int ts_wi, ts_he;
static ts_data_t ts_off;

/*****************************************************************************
* @brief    key function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void input_flush(int fd)
{
	struct timeval tv;
	struct input_event ev;

    fd_set fdset;
    int nfds;

    while (1) {
        FD_ZERO(&fdset);
        FD_SET(fd, &fdset);

        tv.tv_sec = 0;
        tv.tv_usec = 0;

        nfds = select(fd + 1, &fdset, NULL, NULL, &tv);
        if (nfds == 0)
        	break;

		if (read(fd, &ev, sizeof(struct input_event)) < 0)
			break;
    }
}

/****************************************************
 * NAME : void dev_key_flush(void)
 *
 * Desc : flush input-subsystem buffer
 *
 ****************************************************/
void dev_key_flush(void)
{
	input_flush(kbd_fd);
}

/****************************************************
 * NAME : int dev_key_state_read(int type, int code)
 *
 * Desc   : Get current key state.
 *
 * INPUT  :
 *   PARAMETERS:
 *         int type : event type. (EV_SW, EV_KEY etc...)
 *         int code : event code.
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values: 0        nothing
 *               1        detected event
 *               -1       invalid type or code.
 ****************************************************/
int dev_key_state_read(int type, int code)
{
	int ret;
	char state[KEY_MAX > SW_MAX ? KEY_MAX:SW_MAX];
	int cmd = (type == EV_KEY) ? EVIOCGKEY(KEY_MAX):EVIOCGSW(SW_MAX);

	ret = ioctl(kbd_fd, cmd, state);
	if (ret == -1) {
		dev_err("ioctl failed!\n");
		return -1;
	}

	return TEST_BIT(code, state);
}

/****************************************************
 * NAME : int dev_key_read(int *longkey, int timeout)
 *
 * Desc   : Get current key code from input-core.
 *
 * INPUT  :
 *   PARAMETERS:
 *         int *longkey : buffer for key code.
 *         int timeout : timeout (-1 forever)
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:    0          event not present. (nothing)
 *            nonzero( > 0)    event key code
 *                 -1          invalid type or code.
 ****************************************************/
int dev_key_read(int *longkey, int timeout)
{
	struct pollfd e_poll;
	struct input_event ev;

	unsigned int bTime = 0;

	int res = 0;
	int ret = 0;

	if (kbd_fd < 0)
		return -1;

	memset((void *)&e_poll, 0, sizeof(struct pollfd));
	e_poll.fd     = kbd_fd;
	e_poll.events = POLLIN | POLLERR;
	e_poll.revents = 0;

	do {
		res = poll(&e_poll, 1, timeout);
		if (res < 0) {
			dev_err("poll() failed!..exit\n");
			return -1;
		}
		if (res == 0) {
			/* timeout failed!! */
			return -1;
		}
		if (e_poll.revents & POLLERR)
        	/* poll error!! */
        	return -1;

		if (e_poll.revents & POLLIN) {
			/* received events */
			res = read(kbd_fd, &ev, sizeof(struct input_event));
			if (res < (int) sizeof(struct input_event)) {
				//dev_err("error reading\n");
				return -1;
			}

			if (ev.code == KEY_RESERVED) {
				/* invalid key */
				return -1;
			}

			if (ev.type == EV_KEY && ev.value == 0) {
				if (active) {
					dev_dbg("key released\n");
					*longkey = 0; active = 0;
					return (int)ev.code;
				}
			} else if (ev.type == EV_KEY && ev.value == 1) {
				bTime = OSA_getCurTimeInMsec();
				active = 1;
			} else if (ev.type == EV_KEY && ev.value == 2) {
				if (bTime) {
					if ((OSA_getCurTimeInMsec() - bTime) > 1000) {
						*longkey = 1; active = 0;
						return (int)ev.code;
					}
				}
			} else
				/* To ignore press or repeat */
				continue;
		}
	} while(ret == 0);

	return (-1);
}

/****************************************************
 * NAME : int dev_key_init(void)
 *
 * Desc   : initialize key.
 *
 * INPUT  :
 *   PARAMETERS:
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:    0    succeed.
 *                 -1    failure.
 ****************************************************/
int dev_key_init(void)
{
	char input_path[256] = {};
	int num, ret;

	if (kbd_fd >= 0)
		return -1; /* not supported multi-process */

	num = dev_input_get_bus_num(KEY_DEV_NAME);
	if (num < 0) {
		dev_err("invalid device name %s\n", KEY_DEV_NAME);
		return -1;
	}
	sprintf(input_path, "/dev/input/event%d", num);

	/* blocking mode */
	ret = open(input_path, O_RDONLY);
	if (ret < 0) {
		dev_err("Failed to open %s device.\n", input_path);
		return -1;
	}
	kbd_fd = ret;

	return 0;
}

/****************************************************
 * NAME : void dev_key_exit(void)
 *
 * Desc   : Deinitialize key Hardware.
 *
 * INPUT  :
 *   PARAMETERS : none.
 *
 * OUTPUT :
 *   RETURN : none
 ****************************************************/
void dev_key_exit(void)
{
	if (kbd_fd >= 0) {
		close(kbd_fd);
		kbd_fd = -1;
	}
}

/****************************************************
 * NAME : int dev_tsc_init(int wi, int he)
 *
 * Desc   : Initialize the Touch Device.
 *
 * INPUT  :
 *   PARAMETERS:
 *        int wi : screen width.
 *        int he : screen height.
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values: 0(succeed) -1(failure)
 ****************************************************/
int dev_tsc_init(int wi, int he, char *file)
{
	char name[256] = "Unknown";
	FILE *fset;

	if ((tsc_fd = open(TSC_DEV_NAME, O_RDONLY)) < 0) {
		dev_err("Failed to open %s device.\n", TSC_DEV_NAME);
		tsc_fd = -1;
		return -1;
	}

	ioctl(tsc_fd, EVIOCGNAME(sizeof(name)), name);

	ts_wi = wi;
	ts_he = he;

	//# default x, y offset
	ts_off.xmin = 130;
	ts_off.xmax = 3920;
	ts_off.ymin = 17;
	ts_off.ymax = 3800;

	if(file == NULL)
		return 0;

	if(-1 != access(file, 0))
	{
		fset = fopen(file, "rb");
		fread(&ts_off, sizeof(ts_data_t), 1, fset);
		fclose(fset);
	}

	return 0;
}

/****************************************************
 * NAME : void dev_tsc_exit(void)
 *
 * Desc   : Deinitialize the Touch Device.
 *
 * INPUT  :
 *   PARAMETERS: none
 *
 * OUTPUT :
 *   RETURN : none.
 ****************************************************/
void dev_tsc_exit(void)
{
	if (tsc_fd >= 0) {
		close(tsc_fd);
		tsc_fd = -1;
	}
}

/****************************************************
 * NAME : void dev_tsc_flush(void)
 *
 * Desc   : flush the buffer data.
 *
 * INPUT  :
 *   PARAMETERS: none
 *
 * OUTPUT :
 *   RETURN : none.
 ****************************************************/
void dev_tsc_flush(void)
{
	input_flush(tsc_fd);
}

/****************************************************
 * NAME : int dev_tsc_read(int *x, int *y, int timeout)
 *
 * Desc : Get x and y coordinates of position on screen.
 *
 * INPUT  :
 *   PARAMETERS:
 *       int *x  : buffer for x position.
 *       int *y  : buffer for y position.
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:
 *               0   succeed
 *              -1   failure
 ****************************************************/
int dev_tsc_read(int *x, int *y, int timeout)
{
	struct pollfd e_poll;
	struct input_event ev;

	int rd = 0;
	int tx=0, ty=0, realx=0, realy=0, press=0;

    int xpcnt=0, xncnt=0, ypcnt=0, yncnt=0, tmpx=0, tmpy=0;

	/* couldn't read tsc device */
	if (tsc_fd < 0)
		return -1;

	e_poll.fd     = tsc_fd;
	e_poll.events = POLLIN | POLLERR;
	e_poll.revents = 0;

	while (1)
	{
		int res = 0;
		res = poll(&e_poll, 1, timeout);
		if (res < 0) {
			dev_err("poll() failed!..exit\n");
			return -1;
		}
		if (res == 0) {
			/* timeout failed!! */
			return -1;
		}
		if (e_poll.revents & POLLERR)
        	/* poll error!! */
        	return -1;

        if (e_poll.revents & POLLIN) {
			/* received events */
			rd = read(tsc_fd, &ev, sizeof(struct input_event));
			if (rd < (int) sizeof(struct input_event)) {
				//dev_err("touch: error for reading!!\n");
				return -1;
			}

			if (ev.type == EV_ABS) {
				if (ev.code == 0)
					tx = ev.value;
				else if(ev.code == 1)
					ty = ev.value;
				else if(ev.code == 24)
					press = ev.value;

			} else if (ev.type == EV_SYN) {
				if (tmpx == 0)
					tmpx = tx;
				else {
					if ((tmpx-tx) > GESTURE_VAL)
						xpcnt++;
					else if((tx-tmpx) > GESTURE_VAL)
						xncnt++;
					tmpx = tx;
				}

				if (tmpy == 0)
					tmpy = ty;
				else {
					if ((ty-tmpy) > GESTURE_VAL)
						ypcnt++;
					else if ((tmpy-ty) > GESTURE_VAL)
						yncnt++;
					tmpy = ty;
				}
			}
			else if(ev.type == EV_KEY)
			{
				if (ev.code == BTN_TOUCH /*&& press > 60*/) {
					if ((tx == 0) || (ty == 0))
						continue;

					realx = ((tx-ts_off.xmin)*ts_he)/(ts_off.xmax-ts_off.xmin);
					realy = ((ty-ts_off.ymin)*ts_wi)/(ts_off.ymax-ts_off.ymin);

					if (realx < 0)
						realx = 0;
					if (realx > ts_he)
						realx = ts_he;
					if (realy < 0)
						realy = 0;
					if (realy > ts_wi)
						realy = ts_wi;

					*x = ts_he - realx;
					*y = realy;

					if ((xpcnt > GESTURE_CNT) && (ypcnt < GESTURE_CNT && yncnt < GESTURE_CNT))
						return 1;
					if ((xncnt > GESTURE_CNT) && (ypcnt < GESTURE_CNT && yncnt < GESTURE_CNT))
						return 2;
					if ((ypcnt > GESTURE_CNT) && (xpcnt < GESTURE_CNT && xncnt < GESTURE_CNT))
						return 3;
					if ((yncnt > GESTURE_CNT) && (xpcnt < GESTURE_CNT && xncnt < GESTURE_CNT))
						return 4;
					if ((xncnt > GESTURE_CNT && xpcnt < GESTURE_CNT) &&
						(ypcnt > GESTURE_CNT && yncnt < GESTURE_CNT))
						return 5;
					if (xpcnt > 2 || xncnt > 2 || ypcnt > 2 || yncnt > 2)
						return -1;

					break;
				}
			}
		}
	}

	return 0;
}

void dev_tsc_calibarate(int xo, int yo, char *file)
{
	FILE *fset;
	int gradex, gradey;

	gradex = (ts_off.xmax-ts_off.xmin)/ts_wi;
	gradey = (ts_off.ymax-ts_off.ymin)/ts_he;

	ts_off.xmin += -(gradex*xo);
	ts_off.xmax += -(gradex*xo);
	ts_off.ymin += (gradey*yo);
	ts_off.ymax += (gradey*yo);

	if(file == NULL)
		return;

	fset = fopen(file, "wb");
	chmod(file, 0775);
	fwrite(&ts_off, 1, sizeof(ts_data_t), fset);
	fclose(fset);
}
