/*
 * Copyright (C) UDWORKs, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307, USA
 */

#ifndef _LINUX_DM81XX_DVR_IO_H__
#define _LINUX_DM81XX_DVR_IO_H__

#include <linux/ioctl.h>
#include <linux/types.h>

#define	DVRIO_IOCTL_BASE		'g'

#define DVRIO_IRQ_NONE			0
#define DVRIO_IRQ_RISING		1
#define DVRIO_IRQ_FALLING		2
#define DVRIO_IRQ_BOTH			3

typedef struct {
	unsigned int gpio;
	unsigned int val;			//# default value in case output
	unsigned int dir;			//# 0:input, 1:output
	unsigned int trigger;		//# 0:none, 1:falling, 2:rising
	unsigned int active_low;	//# 1:low_active, 0:high_active
} dvrio_t;

typedef struct {
	struct timeval time;
	
	unsigned int gpio;
	unsigned int val;
} gpio_event_t;


//# ioctl command
#define DVRIO_CMD_INIT		_IOW(DVRIO_IOCTL_BASE, 1, dvrio_t)
#define DVRIO_CMD_CHG_IRQ	_IOW(DVRIO_IOCTL_BASE, 2, dvrio_t)
#define DVRIO_CMD_RD		_IOR(DVRIO_IOCTL_BASE, 3, dvrio_t)
#define DVRIO_CMD_DEINIT	_IOW(DVRIO_IOCTL_BASE, 4, dvrio_t)

#endif  /* _LINUX_DM81XX_DVR_IO_H__ */
