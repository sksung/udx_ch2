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

#ifndef _LINUX_ADC101_H__
#define _LINUX_ADC101_H__

#include <linux/ioctl.h>
#include <linux/types.h>

#define	ADC_IOCTL_BASE			'A'


#define	ADCIOC_SETDEBOUNCE      _IOWR(ADC_IOCTL_BASE, 0, int)
#define	ADCIOC_GETDEBOUNCE      _IOR(ADC_IOCTL_BASE, 1, int)
#define	ADCIOC_SETLEVEL			_IOWR(ADC_IOCTL_BASE, 2, int)
#define	ADCIOC_GETLEVEL			_IOR(ADC_IOCTL_BASE, 3, int)
#define	ADCIOC_SETINTERVAL		_IOWR(ADC_IOCTL_BASE, 4, int)
#define	ADCIOC_GETINTERVAL		_IOR(ADC_IOCTL_BASE, 5, int)

#endif  /* _LINUX_ADC101_H__ */
