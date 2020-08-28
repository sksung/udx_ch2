/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_util.c
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

#include "app_tzone.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
time_zone_info_t tz_list[] = {
	{-12,	0,	"(UTC-12:00)   International Date Line West"},
	{-11,	0,	"(UTC-11:00)   Coordinated Universal Time-11"},
	{-11,	0,	"(UTC-11:00)   Samoa"},
	{-10,	0,	"(UTC-10:00)   Hawaii"},
	{-9,	0,	"(UTC-09:00)   Alaska"},
	{-8,	0,	"(UTC-08:00)   Baja California"},
	{-8,	0,	"(UTC-08:00)   Pacific Time (US & Canada)"},
	{-7,	0,	"(UTC-07:00)   Arizona"},
	{-7,	0,	"(UTC-07:00)   Chihuahua, La Paz, Mazatlan"},
	{-7,	0,	"(UTC-07:00)   Mountain Time (US & Canada)"},
	{-6,	0,	"(UTC-06:00)   Central America"},
	{-6,	0,	"(UTC-06:00)   Central Time (US & Canada)"},
	{-6,	0,	"(UTC-06:00)   Guadalajara, Mexico City"},
	{-6,	0,	"(UTC-06:00)   Monterrey, Saskatchewan"},
	{-5,	0,	"(UTC-05:00)   Bogota, Lima, Quito"},
	{-5,	0,	"(UTC-05:00)   Eastern Time (US & Canada)"},
	{-5,	0,	"(UTC-05:00)   Indiana(East)"},
	{-4,  -30,	"(UTC-04:30)   Caracas"},
	{-4,	0,	"(UTC-04:00)   Asuncion"},
	{-4,	0,	"(UTC-04:00)   Atlantic Time (Canada)"},
	{-4,	0,	"(UTC-04:00)   Cuiaba"},
	{-4,	0,	"(UTC-04:00)   Georgetown, La Paz, Manaus"},
	{-4,	0,	"(UTC-04:00)   San Juan, Santiago"},
	{-3,  -30,	"(UTC-03:30)   Newfoundland"},
	{-3,	0,	"(UTC-03:00)   Brasilia"},
	{-3,	0,	"(UTC-03:00)   Buenos Aires"},
	{-3,	0,	"(UTC-03:00)   Cayenne, Fortaleza"},
	{-3,	0,	"(UTC-03:00)   Greenland"},
	{-3,	0,	"(UTC-03:00)   Montevideo"},
	{-2,	0,	"(UTC-02:00)   Coordinated Universal Time-02"},
	{-2,	0,	"(UTC-02:00)   Mid-Atlantic"},
	{-1,	0,	"(UTC-01:00)   Azores"},
	{-1,	0,	"(UTC-01:00)   Cape Verde Is."},
	{0, 	0,	"(UTC) 	       Casablanca"},
	{0, 	0,	"(UTC) 		   Coordinated Universal Time"},
	{0, 	0,	"(UTC) 		   Dublin, Edinburgh, Lisbon, London"},
	{0, 	0,	"(UTC) 		   Monrovia, Reykjavik"},
	{1, 	0,	"(UTC+01:00)   Amsterdam, Berlin, Bern"},
	{1, 	0,	"(UTC+01:00)   Rome, Stockholm, Vienna"},
	{1, 	0,	"(UTC+01:00)   Belgrade, Bratislava, Budapest"},
	{1, 	0,	"(UTC+01:00)   Ljubljana, Prague"},
	{1, 	0,	"(UTC+01:00)   Brussels, Copenhagen, Madrid, Paris"},
	{1, 	0,	"(UTC+01:00)   Sarajevo, Skopje, Warsaw, Zagreb"},
	{1, 	0,	"(UTC+01:00)   West Central Africa"},
	{1, 	0,	"(UTC+01:00)   Windhoek"},
	{2, 	0,	"(UTC+02:00)   Amman"},
	{2, 	0,	"(UTC+02:00)   Athens,Bucharest, Istanbul"},
	{2, 	0,	"(UTC+02:00)   Beirut"},
	{2, 	0,	"(UTC+02:00)   Cairo"},
	{2, 	0,	"(UTC+02:00)   Damascus"},
	{2, 	0,	"(UTC+02:00)   Harare, Pretoria"},
	{2, 	0,	"(UTC+02:00)   Helsinki, Kyiv, Riga"},
	{2, 	0,	"(UTC+02:00)   Sofia, Tallinn, Vilnius"},
	{2, 	0,	"(UTC+02:00)   Jerusalem"},
	{2, 	0,	"(UTC+02:00)   Minsk"},
	{3, 	0,	"(UTC+03:00)   Baghdad"},
	{3, 	0,	"(UTC+03:00)   Kuwait, Riyadh"},
	{3, 	0,	"(UTC+03:00)   Moscow, St.Petersburg, Volgograd"},
	{3, 	0,	"(UTC+03:00)   Nairobi"},
	{3,    30,	"(UTC+03:30)   Tehran"},
	{4, 	0,	"(UTC+04:00)   Abu Dhabi, Muscat"},
	{4, 	0,	"(UTC+04:00)   Baku"},
	{4, 	0,	"(UTC+04:00)   Port Louis"},
	{4, 	0,	"(UTC+04:00)   Tbilisi"},
	{4, 	0,	"(UTC+04:00)   Yerevan"},
	{4,    30,	"(UTC+04:30)   Kabul"},
	{5, 	0,	"(UTC+05:00)   Ekaterinburg"},
	{5, 	0,	"(UTC+05:00)   Islamabad, Karachi"},
	{5, 	0,	"(UTC+05:00)   Tashkent"},
	{5,    30,	"(UTC+05:30)   Chennai, Kolkata, Mumbai"},
	{5,    30,	"(UTC+05:30)   New Delhi, Sri Jayawardenepura"},
	{5,    45,	"(UTC+05:45)   Kathmandu"},
	{6, 	0,	"(UTC+06:00)   Astana"},
	{6, 	0,	"(UTC+06:00)   Dhaka"},
	{6, 	0,	"(UTC+06:00)   Novosibirsk"},
	{6,    30,	"(UTC+06:30)   Yangon (Rangoon)"},
	{7, 	0,	"(UTC+07:00)   Bangkok, Hanoi, Jakarta"},
	{7, 	0,	"(UTC+07:00)   Krasnoyarsk"},
	{8, 	0,	"(UTC+08:00)   Beijing, Chongqing, Hong Kong"},
	{8, 	0,	"(UTC+08:00)   Urumqi, Irkutsk"},
	{8, 	0,	"(UTC+08:00)   Kuala Lumpur, Singapore"},
	{8, 	0,	"(UTC+08:00)   Perth"},
	{8, 	0,	"(UTC+08:00)   Taipei"},
	{8, 	0,	"(UTC+08:00)   Ulaanbaatar"},
	{9, 	0,	"(UTC+09:00)   Osaka, Sapporo, Tokyo"},
	{9, 	0,	"(UTC+09:00)   Seoul"},
	{9, 	0,	"(UTC+09:00)   Yakutsk"},
	{9,    30,	"(UTC+09:30)   Adelaide"},
	{9,    30,	"(UTC+09:30)   Darwin"},
	{10,	0,	"(UTC+10:00)   Brisbane"},
	{10,	0,	"(UTC+10:00)   Canberra, Melbourne, Sydney"},
	{10,	0,	"(UTC+10:00)   Guam, Port Moresby"},
	{10,	0,	"(UTC+10:00)   Hobart"},
	{10,	0,	"(UTC+10:00)   Vladivostok"},
	{11,	0,	"(UTC+11:00)   Magadan"},
	{11,	0,	"(UTC+11:00)   Solomon Is., New Caledonia"},
	{12,	0,	"(UTC+12:00)   Auckland, Wellington"},
	{12,	0,	"(UTC+12:00)   Coordinated Universal Time+12"},
	{12,	0,	"(UTC+12:00)   Fiji"},
	{13,	0,	"(UTC+13:00)   Nuku'alofa"},
};

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    get timezone hour, minute function
* @section  DESC Description
*   - desc
*****************************************************************************/
void get_time_zone(int idx, int *h, int *m)
{
	if(idx >= MAX_TZ_LIST || idx < 0){
		idx = DEFAULT_TZ_IDX;
	}	
	
	*h = tz_list[idx].tz_h;
	*m = tz_list[idx].tz_m;   
}


