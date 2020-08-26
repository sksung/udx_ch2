/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_process.h
 * @brief
 * @author  hwjun
 * @section MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_PROCESS_H_
#define _APP_PROCESS_H_

/*----------------------------------------------------------------------------
  Defines referenced header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Definitions and macro
-----------------------------------------------------------------------------*/

#define ACCEPTED        0x0001
#define REJECTED        0xffff 
#define STRING_SIZE	32
#define USER_SIZE	12

#define CFGRES_OK            0x3001
#define CFGRES_NOCHANGE      0x3002
#define CFGRES_ERR_INVALID   0x3010
#define CFGRES_ERR_NOAUTH    0x3020
#define CFGRES_ERR_SYSTEM    0x3030

#pragma pack(1)
typedef struct TAG_DEVICEREQ
{
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
} DEVICEREQ ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_DEVICERES
{
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
        unsigned short result ;
} DEVICERES ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_USERKEYREQ
{
	unsigned short status ;
} USERKEYREQ ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_USERKEYRES
{
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short status ;
	unsigned short result ;
} USERKEYRES ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_USERAUTHREQ
{
        unsigned short idlength ;
        unsigned short passwdlength ;
        char id[USER_SIZE] ;
        char passwd[USER_SIZE] ;
} USERAUTHREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_USERAUTHRES
{
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
        unsigned short result ;
        unsigned short chaccess ;
        unsigned short authvalue ;
        unsigned long conaccess ;
} USERAUTHRES ;
#pragma pack()

typedef struct TAG_USERCONFIRMREQ
{
        unsigned short authvalue ;
} USERCONFIRMREQ ;

#pragma pack(1)
typedef struct TAG_USERCONFIRMRES
{
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
        unsigned short result ;
} USERCONFIRMRES ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_SERVERBUSY 
{
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
} SERVERBUSY ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_COMRESPACKET {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
        unsigned short result ;
} COMRESPACKET ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_COMREQPACKET {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
} COMREQPACKET ;
#pragma pack()

	
#pragma pack(1)
typedef struct TAG_PLAYLISTPARAMREQ {
	unsigned short rec_type ;
	unsigned short option ;
} PLAYLISTPARAMREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_PLAYLISTPARAMRES {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short result ;
	unsigned short rec_type ;
	unsigned short total_count ;
	unsigned short file_count ;
	char 	       filename[STRING_SIZE * 100] ;
} PLAYLISTPARAMRES ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_DISPLAYPARAMRES {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short brightness ;
	unsigned short screen_savetime ;
	unsigned short mirroring ;
} DISPLAYPARAMRES ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_AUDIOPARAMRES {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short mic ;
	unsigned short guide_voice ;
	unsigned short volume ;
} AUDIOPARAMRES ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_QUALITYPARAMREQ {
	unsigned short mode ;
} QUALITYPARAMREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_QUALITYPARAMRES {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short mode ;
        unsigned short bitrate ;
        unsigned short framerate ;
} QUALITYPARAMRES ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_CAMBRIGHTPARAMRES {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short Frontbrightness ;
	unsigned short Rearbrightness ;
} CAMBRIGHTPARAMRES ;
#pragma pack()
 

#pragma pack(1) 
typedef struct TAG_SYSTEMPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short wifiset ;
	unsigned short language ;
} SYSTEMPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_INFOPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	char HWver[STRING_SIZE] ;
	char SWver[STRING_SIZE] ;
	char Product[STRING_SIZE] ;
	char ModelNo[STRING_SIZE] ;
	char SSID[STRING_SIZE] ;
	char Passwd[16] ;
} INFOPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_TIMESETPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short year ;
	unsigned short month ;
	unsigned short day ;
	unsigned short hour ;
	unsigned short minute ;
	unsigned short second ;
} TIMESETPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_SDPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short format_cycle ;
} SDPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_SENSORPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short shock_sensitivity ;
	unsigned short motion_sensitivity ;
        unsigned short sensing_parking_mode ;
} SENSORPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_OPERATEPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short bettery_safetime ;
	unsigned short temperature ;
        unsigned short voltage_type ;
        unsigned short operate_voltage ;
} OPERATEPARAMRES ;
#pragma pack()

#pragma pack(1) 
typedef struct TAG_INDICATORPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short state_rec ;
	unsigned short state_mmc ;
        unsigned short state_gps ;
        unsigned short state_wifi ;
        unsigned short state_mic ;
        unsigned short state_speaker ;
} INDICATORPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_USERPARAMRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	char userid[USER_SIZE] ;
	char userpasswd[USER_SIZE] ;
	unsigned short channelaccess ;
        unsigned long controlaccess ;
} USERPARAMRES ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_DISPLAYCFGREQ {
	unsigned short brightness ;
	unsigned short screen_savetime ;
	unsigned short mirroring ;
} DISPLAYCFGREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_AUDIOCFGREQ {
        unsigned short mic ;
        unsigned short guide_voice ;
        unsigned short volume ;
} AUDIOCFGREQ ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_QUALITYCFGREQ {
	unsigned short mode ;
        unsigned short bitrate ;
        unsigned short framerate ;
} QUALITYCFGREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_QUALITYCFGRES {
	unsigned short identifier ;
	unsigned short cmd ;
	unsigned short length ;
	unsigned short mode ;
	unsigned short result ;
} QUALITYCFGRES ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_CAMBRIGHTCFGREQ {
        unsigned short Frontbrightness ;
        unsigned short Rearbrightness ;
} CAMBRIGHTCFGREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_CAMBRIGHTCFGRES {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short result ;
} CAMBRIGHTCFGRES ;
#pragma pack()

#pragma pack(1) 
typedef struct TAG_SYSTEMCFGREQ {
	unsigned short fwupdate ;
	unsigned short initial ;
	unsigned short wifiset ;
	unsigned short language ;
} SYSTEMCFGREQ ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_TIMESETCFGREQ {
        unsigned short year ;
        unsigned short month ;
        unsigned short day ;
        unsigned short hour ;
        unsigned short minute ;
        unsigned short second ;
} TIMESETCFGREQ ;
#pragma pack()

#pragma pack(1)
typedef struct TAG_SDCFGREQ {
	unsigned short format ;
        unsigned short format_cycle ;
} SDCFGREQ ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_SENSORCFGREQ {
	unsigned short shock_sensitivity ;
	unsigned short motion_sensitivity ;
        unsigned short sensing_parking_mode ;
} SENSORCFGREQ ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_OPERATECFGREQ {
	unsigned short bettery_safetime ;
	unsigned short temperature ;
        unsigned short operate_voltage ;
} OPERATECFGREQ ;
#pragma pack()


#pragma pack(1) 
typedef struct TAG_WIFICFGREQ {
	char SSID[STRING_SIZE] ;
	char PASSWD[16] ;
} WIFICFGREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_USERCFGREQ {
        char userid[USER_SIZE] ;
        char userpasswd[USER_SIZE] ;
        unsigned short channelaccess ;
        unsigned long controlaccess ;
} USERCFGREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_DBTDATA {
	unsigned short Curchannel ;
        unsigned short Ostype ;
	unsigned short Cpuclock ;
	unsigned short Cpuload ;
	unsigned short Mem_size ;
	unsigned short Mem_usage ;
	unsigned short Net_bandwidth ;
	unsigned short Resolution ;	
} DBTDATA ;



#pragma pack(1)
typedef struct TAG_AVISTREAMREQ {
	unsigned short rectype ;
	char filename[STRING_SIZE] ;
} AVISTREAMREQ ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_AVISTREAMDATA {
        unsigned short identifier ;
        unsigned short cmd ;
        unsigned short length ;
	unsigned short FragmentNo ;
        unsigned short FragmentIdx ;
} AVISTREAMDATA ;
#pragma pack()


#pragma pack(1)
typedef struct TAG_HLSCHANNEL {
	unsigned short channel ;
} HLSCHANNEL ;
#pragma pack()

	

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a     function prototype
-----------------------------------------------------------------------------*/

void init_UCX_ST_SET(void);
void free_UCX_ST_SET(void);

void connect_control(void) ;

void devicereq( int, char*, int) ;
void userkeyreq( int, char*, int) ;
void userauthreq( int, char*, int) ;
void userconfirmreq( int, char*, int) ;

void playlistparamreq(int, char*, int) ;
void displayparamreq(int, char*, int) ;
void audioparamreq(int, char*, int) ;
void qualityparamreq(int, char*, int) ;

void cambrightparamreq(int, char*, int) ;

void systemparamreq(int, char*, int) ;
void infoparamreq(int, char*, int) ;
void timesetparamreq(int, char*, int) ;
void sdparamreq(int, char*, int) ;
void sensorparamreq(int, char*, int) ;
void operateparamreq(int, char*, int) ;
void indicatorparamreq(int, char*, int) ;
void userparamreq(int, char*, int) ;

void displaycfgreq(int, char*, int) ;
void audiocfgreq(int, char*, int) ;
void qualitycfgreq(int, char*, int) ;
void systemcfgreq(int, char*, int) ;

void cambrightcfgreq(int, char*, int) ;

void timesetcfgreq(int, char*, int) ;
void sdcfgreq(int, char*, int) ;
void sensorcfgreq(int, char*, int) ;
void operatecfgreq(int, char*, int) ;
void wificfgreq(int, char*, int) ;
void usercfgreq(int, char*, int) ;
void avistreamreq(int, char*, int) ;


void dbtdata(int, char*, int) ;
void systemreset(int, char*, int) ;
void invalidmsg(int, char*, int) ;
void hlssetchannel(int, char*, int) ;

#endif // _APP_PROCESS_H
