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
/*000*/	{-12,	0,	"(UTC-12:00)   International Date Line West"},
/*001*/	{-11,	0,	"(UTC-11:00)   Coordinated Universal Time-11"},
/*002*/	{-11,	0,	"(UTC-11:00)   Samoa"},
/*003*/	{-10,	0,	"(UTC-10:00)   Hawaii"},
/*004*/	{-9,	0,	"(UTC-09:00)   Alaska"},
/*005*/	{-8,	0,	"(UTC-08:00)   Baja California"},
/*006*/	{-8,	0,	"(UTC-08:00)   Pacific Time (US & Canada)"},
/*007*/	{-7,	0,	"(UTC-07:00)   Arizona"},
/*008*/	{-7,	0,	"(UTC-07:00)   Chihuahua, La Paz, Mazatlan"},
/*009*/	{-7,	0,	"(UTC-07:00)   Mountain Time (US & Canada)"},
/*010*/	{-6,	0,	"(UTC-06:00)   Central America"},
/*011*/	{-6,	0,	"(UTC-06:00)   Central Time (US & Canada)"},
/*012*/	{-6,	0,	"(UTC-06:00)   Guadalajara, Mexico City"},
/*013*/	{-6,	0,	"(UTC-06:00)   Monterrey, Saskatchewan"},
/*014*/	{-5,	0,	"(UTC-05:00)   Bogota, Lima, Quito"},
/*015*/	{-5,	0,	"(UTC-05:00)   Eastern Time (US & Canada)"},
/*016*/	{-5,	0,	"(UTC-05:00)   Indiana(East)"},
/*017*/	{-4,  -30,	"(UTC-04:30)   Caracas"},
/*018*/	{-4,	0,	"(UTC-04:00)   Asuncion"},
/*019*/	{-4,	0,	"(UTC-04:00)   Atlantic Time (Canada)"},
/*020*/	{-4,	0,	"(UTC-04:00)   Cuiaba"},
/*021*/	{-4,	0,	"(UTC-04:00)   Georgetown, La Paz, Manaus"},
/*022*/	{-4,	0,	"(UTC-04:00)   San Juan, Santiago"},
/*023*/	{-3,  -30,	"(UTC-03:30)   Newfoundland"},
/*024*/	{-3,	0,	"(UTC-03:00)   Brasilia"},
/*025*/	{-3,	0,	"(UTC-03:00)   Buenos Aires"},
/*026*/	{-3,	0,	"(UTC-03:00)   Cayenne, Fortaleza"},
/*027*/	{-3,	0,	"(UTC-03:00)   Greenland"},
/*028*/	{-3,	0,	"(UTC-03:00)   Montevideo"},
/*029*/	{-2,	0,	"(UTC-02:00)   Coordinated Universal Time-02"},
/*030*/	{-2,	0,	"(UTC-02:00)   Mid-Atlantic"},
/*031*/	{-1,	0,	"(UTC-01:00)   Azores"},
/*032*/	{-1,	0,	"(UTC-01:00)   Cape Verde Is."},
/*033*/	{0, 	0,	"(UTC) 	       Casablanca"},
/*034*/	{0, 	0,	"(UTC) 		   Coordinated Universal Time"},
/*035*/	{0, 	0,	"(UTC) 		   Dublin, Edinburgh, Lisbon, London"},
/*036*/	{0, 	0,	"(UTC) 		   Monrovia, Reykjavik"},
/*037*/	{1, 	0,	"(UTC+01:00)   Amsterdam, Berlin, Bern"},
/*038*/	{1, 	0,	"(UTC+01:00)   Rome, Stockholm, Vienna"},
/*039*/	{1, 	0,	"(UTC+01:00)   Belgrade, Bratislava, Budapest"},
/*040*/	{1, 	0,	"(UTC+01:00)   Ljubljana, Prague"},
/*041*/	{1, 	0,	"(UTC+01:00)   Brussels, Copenhagen, Madrid, Paris"},
/*042*/	{1, 	0,	"(UTC+01:00)   Sarajevo, Skopje, Warsaw, Zagreb"},
/*043*/	{1, 	0,	"(UTC+01:00)   West Central Africa"},
/*044*/	{1, 	0,	"(UTC+01:00)   Windhoek"},
/*045*/	{2, 	0,	"(UTC+02:00)   Amman"},
/*046*/	{2, 	0,	"(UTC+02:00)   Athens,Bucharest, Istanbul"},
/*047*/	{2, 	0,	"(UTC+02:00)   Beirut"},
/*048*/	{2, 	0,	"(UTC+02:00)   Cairo"},
/*049*/	{2, 	0,	"(UTC+02:00)   Damascus"},
/*050*/	{2, 	0,	"(UTC+02:00)   Harare, Pretoria"},
/*051*/	{2, 	0,	"(UTC+02:00)   Helsinki, Kyiv, Riga"},
/*052*/	{2, 	0,	"(UTC+02:00)   Sofia, Tallinn, Vilnius"},
/*053*/	{2, 	0,	"(UTC+02:00)   Jerusalem"},
/*054*/	{2, 	0,	"(UTC+02:00)   Minsk"},
/*055*/	{3, 	0,	"(UTC+03:00)   Baghdad"},
/*056*/	{3, 	0,	"(UTC+03:00)   Kuwait, Riyadh"},
/*057*/	{3, 	0,	"(UTC+03:00)   Moscow, St.Petersburg, Volgograd"},
/*058*/	{3, 	0,	"(UTC+03:00)   Nairobi"},
/*059*/	{3,    30,	"(UTC+03:30)   Tehran"},
/*060*/	{4, 	0,	"(UTC+04:00)   Abu Dhabi, Muscat"},
/*061*/	{4, 	0,	"(UTC+04:00)   Baku"},
/*062*/	{4, 	0,	"(UTC+04:00)   Port Louis"},
/*063*/	{4, 	0,	"(UTC+04:00)   Tbilisi"},
/*064*/	{4, 	0,	"(UTC+04:00)   Yerevan"},
/*065*/	{4,    30,	"(UTC+04:30)   Kabul"},
/*066*/	{5, 	0,	"(UTC+05:00)   Ekaterinburg"},
/*067*/	{5, 	0,	"(UTC+05:00)   Islamabad, Karachi"},
/*068*/	{5, 	0,	"(UTC+05:00)   Tashkent"},
/*069*/	{5,    30,	"(UTC+05:30)   Chennai, Kolkata, Mumbai"},
/*070*/	{5,    30,	"(UTC+05:30)   New Delhi, Sri Jayawardenepura"},
/*071*/	{5,    45,	"(UTC+05:45)   Kathmandu"},
/*072*/	{6, 	0,	"(UTC+06:00)   Astana"},
/*073*/	{6, 	0,	"(UTC+06:00)   Dhaka"},
/*074*/	{6, 	0,	"(UTC+06:00)   Novosibirsk"},
/*075*/	{6,    30,	"(UTC+06:30)   Yangon (Rangoon)"},
/*076*/	{7, 	0,	"(UTC+07:00)   Bangkok, Hanoi, Jakarta"},
/*077*/	{7, 	0,	"(UTC+07:00)   Krasnoyarsk"},
/*078*/	{8, 	0,	"(UTC+08:00)   Beijing, Chongqing, Hong Kong"},
/*079*/	{8, 	0,	"(UTC+08:00)   Urumqi, Irkutsk"},
/*080*/	{8, 	0,	"(UTC+08:00)   Kuala Lumpur, Singapore"},
/*081*/	{8, 	0,	"(UTC+08:00)   Perth"},
/*082*/	{8, 	0,	"(UTC+08:00)   Taipei"},
/*083*/	{8, 	0,	"(UTC+08:00)   Ulaanbaatar"},
/*084*/	{9, 	0,	"(UTC+09:00)   Osaka, Sapporo, Tokyo"},
/*085*/	{9, 	0,	"(UTC+09:00)   Seoul"},
/*086*/	{9, 	0,	"(UTC+09:00)   Yakutsk"},
/*087*/	{9,    30,	"(UTC+09:30)   Adelaide"},
/*088*/	{9,    30,	"(UTC+09:30)   Darwin"},
/*089*/	{10,	0,	"(UTC+10:00)   Brisbane"},
/*090*/	{10,	0,	"(UTC+10:00)   Canberra, Melbourne, Sydney"},
/*091*/	{10,	0,	"(UTC+10:00)   Guam, Port Moresby"},
/*092*/	{10,	0,	"(UTC+10:00)   Hobart"},
/*093*/	{10,	0,	"(UTC+10:00)   Vladivostok"},
/*094*/	{11,	0,	"(UTC+11:00)   Magadan"},
/*095*/	{11,	0,	"(UTC+11:00)   Solomon Is., New Caledonia"},
/*096*/	{12,	0,	"(UTC+12:00)   Auckland, Wellington"},
/*097*/	{12,	0,	"(UTC+12:00)   Coordinated Universal Time+12"},
/*098*/	{12,	0,	"(UTC+12:00)   Fiji"},
/*099*/	{13,	0,	"(UTC+13:00)   Nuku'alofa"},
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


