/*
 * dev_key.h
 *
 * Copyright (C) 2013 UDWORKs.
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
 * touch and gpio-keys Hardware library interface definitions.
 */
#ifndef _DEV_KEY_H_
#define _DEV_KEY_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void dev_key_flush(void);
int dev_key_state_read(int type, int code);
int dev_key_read(int *longkey, int timeout);
int dev_key_init(void);
void dev_key_exit(void);
int dev_tsc_init(int wi, int he, char *file);
void dev_tsc_exit(void);
void dev_tsc_flush(void);
int dev_tsc_read(int *x, int *y, int timeout);
void dev_tsc_calibarate(int xo, int yo, char *file);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _DEV_KEY_H_ */
