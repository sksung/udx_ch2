/*
 * UBX remote controller keytable
 *
 * Copyright (C) 2014 UDWORKS Inc.
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <media/rc-map.h>
#include <linux/module.h>

static struct rc_map_table ubx[] = {
	/* Key codes for the UBX remote */
	{ 0x100804, KEY_RECORD },
	{ 0x100807, KEY_COMPOSE },  //# FUNC KEY
	{ 0x10080e, KEY_MUTE },     //# sound on/off
	{ 0x10084c, KEY_KP1 },      //# DVR_ID[1]
	{ 0x10084d, KEY_KP2 },      //# DVR_ID[2]
	{ 0x10084e, KEY_KP3 },      //# DVR_ID[3]
	{ 0x10084f, KEY_KP4 },      //# DVR_ID[4]
	{ 0x100801, KEY_ZOOMIN },   //# Z+
	{ 0x100805, KEY_ZOOMOUT },  //# Z-
	{ 0x100803, KEY_SEARCH },   //# search
	{ 0x10080a, KEY_SWITCHVIDEOMODE },   //# multi-window
	{ 0x100809, KEY_KBDILLUMUP },     //# IRIS+
	{ 0x100808, KEY_KBDILLUMDOWN },   //# IRIS-
	{ 0x100800, KEY_CAMERA },   	  //# PTZ
	{ 0x100818, KEY_CYCLEWINDOWS },   //# screen-divide
	{ 0x10080b, KEY_STOP },   		//# stop
	{ 0x10080d, KEY_PLAYPAUSE },   	//# toggle (play-pause)
	{ 0x100811, KEY_FORWARD },   	//# NEXT-FILE
	{ 0x10081b, KEY_EJECTCD },   	//# eject
	{ 0x100812, KEY_UP },   		//# up
	{ 0x100813, KEY_DOWN },   		//# down
	{ 0x100814, KEY_LEFT },   		//# left
	{ 0x100816, KEY_RIGHT },   		//# right
	{ 0x100815, KEY_ENTER },   		//# enter
	{ 0x10080c, KEY_VOLUMEUP },   			//# ??
	{ 0x100810, KEY_VOLUMEDOWN },   		//# ??
	{ 0x10081a, KEY_SCROLLUP },   			//# ??
	{ 0x100819, KEY_SCROLLDOWN },   		//# ??
	{ 0x10081c, KEY_1 },
	{ 0x10081d, KEY_2 },
	{ 0x10081e, KEY_3 },
	{ 0x10081f, KEY_4 },
	{ 0x100840, KEY_5 },
	{ 0x100841, KEY_6 },
	{ 0x100842, KEY_7 },
	{ 0x100843, KEY_8 },
	{ 0x100844, KEY_9 },
	{ 0x100845, KEY_F1 },
	{ 0x100846, KEY_F2 },
	{ 0x100847, KEY_F3 },
	{ 0x100848, KEY_F4 },
	{ 0x100849, KEY_F5 },
	{ 0x10084a, KEY_F6 },
	{ 0x10084b, KEY_F7 }  //#44
};

static struct rc_map_list ubx_map = {
	.map = {
		.scan    = ubx,
		.size    = ARRAY_SIZE(ubx),
		.rc_type = RC_TYPE_NEC,
		.name    = RC_MAP_UBX,
	}
};

static int __init init_rc_map_ubx(void)
{
	return rc_map_register(&ubx_map);
}

static void __exit exit_rc_map_ubx(void)
{
	rc_map_unregister(&ubx_map);
}

module_init(init_rc_map_ubx)
module_exit(exit_rc_map_ubx)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("UDWORKS");
