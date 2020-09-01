/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_process.c
 * @brief
 * @author  hwjun
 * @section MODIFY history
 *    - 2013.09.23 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
  Defines referenced header files
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
//# remove warning: 'struct mmsghdr' declared inside parameter list
#define __USE_GNU
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/param.h>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#include <errno.h>
#include <err.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/kernel.h>
#include <asm/types.h>
#include <netdb.h>
#include <dirent.h>
#include <sys/stat.h>
#include <app_encrypt.h>
#include <app_process.h>
#include <app_fcommand.h>
#include <app_rawsock.h>
#include <app_sockdef.h>

#include "ti_venc.h"
#include "ucx_main.h"
#include "app_set.h"
#include "app_file.h"
#include "app_ctrl.h"
#include "app_cap.h"
#include "app_snd.h"
#include "app_dev.h"

//#include "app_hls.h"
#include "app_process.h"
#include "app_micom_main.h"
#include "app_sockio.h"
#include "ubx_avi.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

SYSTEM_INFO SystemInfo ;


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

const int DEVICERES_SIZE = sizeof(DEVICERES) ;
const int USERKEYRES_SIZE = sizeof(USERKEYRES) ;
const int USERAUTHRES_SIZE = sizeof(USERAUTHRES) ;
const int USERCONFIRMRES_SIZE = sizeof(COMRESPACKET) ;
const int DISPLAYPARAMRES_SIZE = sizeof(DISPLAYPARAMRES) ;
const int PLAYLISTPARAMRES_SIZE = sizeof(COMRESPACKET) ;
const int AUDIOPARAMRES_SIZE = sizeof(AUDIOPARAMRES) ;
const int QUALITYPARAMRES_SIZE = sizeof(QUALITYPARAMRES) ;
const int CAMBRIGHTPARAMRES_SIZE = sizeof(CAMBRIGHTPARAMRES) ;
const int SYSTEMPARAMRES_SIZE = sizeof(SYSTEMPARAMRES) ;
const int INFOPARAMRES_SIZE = sizeof(INFOPARAMRES) ;
const int TIMESETPARAMRES_SIZE = sizeof(TIMESETPARAMRES) ;
const int SDPARAMRES_SIZE = sizeof(SDPARAMRES) ;
const int SENSORPARAMRES_SIZE = sizeof(SENSORPARAMRES) ;
const int OPERATEPARAMRES_SIZE = sizeof(OPERATEPARAMRES) ;
const int INDICATORPARAMRES_SIZE = sizeof(INDICATORPARAMRES) ;
const int USERPARAMRES_SIZE = sizeof(USERPARAMRES) ;
const int ISPPARAMRES_SIZE = sizeof(COMRESPACKET) ;

const int DISPLAYCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int AUDIOCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int QUALITYCFGRES_SIZE = sizeof(QUALITYCFGRES) ;
const int CAMBRIGHTCFGRES_SIZE = sizeof(CAMBRIGHTCFGRES) ;

const int SYSTEMCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int TIMESETCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int SDCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int SENSORCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int OPERATECFGRES_SIZE = sizeof(COMRESPACKET) ;
const int WIFICFGRES_SIZE = sizeof(COMRESPACKET) ;
const int USERCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int ISPCFGRES_SIZE = sizeof(COMRESPACKET) ;
const int AVISTREAMERR_SIZE = sizeof(COMRESPACKET) ;
const int AVISTREAMDATA_SIZE = sizeof(AVISTREAMDATA) ;
const int HLSCHANNELRES_SIZE = sizeof(COMRESPACKET) ;


struct timeval rtv ;
char m_SendBuffer[MAXUSER][MAXBUFF] ;
unsigned long Pretime = 0, Curtime = 0;
int curpos = 1 ;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

#define STR_SIZE 	32
#define FILECNT		100
#define PACKETSIZE	20480

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/
int delay_func(int sec, int usec)
{

    struct  timeval  wait;
    fd_set  readfds;
    int     rc;


    FD_ZERO(&readfds);
    wait.tv_sec = sec;
    wait.tv_usec = usec;
    rc = 0;
    rc = select(1 , (fd_set *)&readfds, (fd_set *)0, (fd_set *)0, (struct timeval *)&wait);
    return rc ;
}

void init_UCX_ST_SET()
{
//    pSet = (UCX_ST_SET*)malloc(sizeof(UCX_ST_SET));
//    pState = (UCX_ST_DEV_STATE*)malloc(sizeof(UCX_ST_SET)) ;
}

void free_UCX_ST_SET()
{
//    free(pSet) ;
//    free(pState) ;
}

void connect_control()
{
    struct timeval tv ;

    if(app_cfg->set_state == SETTING_REMOTE)
    {
		if(Pretime != 0)
		{
		    gettimeofday(&tv, NULL) ;
	        Curtime = (unsigned long)(tv.tv_sec % 10000u) ;

		    if(Curtime - Pretime > 30)
		    {
				app_cfg->set_state = SETTING_NONE;
				CloseAllChannel() ;
	            Curtime = 0 ;
	            Pretime = 0 ;
		    }
		}
    }
}

void devicereq(int channel, char* data, int len)
{
    DEVICERES Deviceres ;
    int sendlen = 0 ;

printf("reached devicereq.......\n") ;

    Deviceres.identifier = htons(IDENTIFIER) ;
    Deviceres.cmd = htons(CMD_DEVICE_RES) ;
    Deviceres.length = htons(DEVICERES_SIZE) ;
    Deviceres.result = htons(IDENTIFIER) ;

    memcpy(m_SendBuffer[channel], &Deviceres, DEVICERES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], DEVICERES_SIZE, 0) ;
    memset(m_SendBuffer[channel], MAXBUFF, 0) ;
#ifdef NETWORK_DEBUG
    DEBUG_PRI("deviceres packet sendlen = %d\n",sendlen) ;
#endif
}

void userkeyreq(int channel, char* data, int len)
{
    struct timeval tv ;

    USERKEYREQ *Userkeyreq ;
    USERKEYRES Userkeyres ;

    int sendlen = 0 ;

    Userkeyreq = (USERKEYREQ *)data ;

    Userkeyres.identifier = htons(IDENTIFIER) ;
    Userkeyres.cmd = htons(CMD_USERKEY_RES) ;
    Userkeyres.length = htons(USERKEYRES_SIZE) ;
    Userkeyres.status = Userkeyreq->status ;

    if(ntohs(Userkeyreq->status) == 0x00)
    {
    	if(app_cfg->set_state == SETTING_NONE || app_cfg->set_state == SETTING_REMOTE)
    	{
		    app_cfg->set_state = SETTING_REMOTE;
    	    Userkeyres.result = htons(0x00) ;
		    gettimeofday(&tv, NULL) ;
            Pretime = (unsigned long)(tv.tv_sec % 10000u) ;
    	}
    	else
    	{
    	    Userkeyres.result = htons(0x01) ;
    	}
    }
    else
    {
		app_cfg->set_state = SETTING_NONE;
    	Userkeyres.result = htons(0x00) ;
    }
    memcpy(m_SendBuffer[channel], &Userkeyres, USERKEYRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], USERKEYRES_SIZE, 0) ;
    memset(m_SendBuffer[channel], MAXBUFF, 0) ;
#ifdef NETWORK_DEBUG
    DEBUG_PRI("userkeyres packet sendlen = %d, status = %d, result = %d\n",sendlen,app_cfg->set_state, ntohs(Userkeyres.result)) ;
#endif
}



void userauthreq(int channel, char *data, int len)
{
    USERAUTHREQ *Userauthreq ;
    USERAUTHRES Userauthres ;

    int sendlen;
    unsigned char id[USER_SIZE], passwd[USER_SIZE], outputid[USER_SIZE], outputpasswd[USER_SIZE] ;

    memset(id, 0, USER_SIZE) ;
    memset(passwd, 0, USER_SIZE) ;
    memset(outputid, 0, USER_SIZE) ;
    memset(outputpasswd, 0, USER_SIZE) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("userauthreq packet receive length = %d\n",len) ;
#endif
    Userauthreq = (USERAUTHREQ *)data ;
/*
    idlength = ntohs(Userauthreq->idlength) ;
    passwdlength = ntohs(Userauthreq->passwdlength) ;

    memcpy(id, &Userauthreq->id, idlength) ;
    memcpy(passwd, &data[6+idlength], passwdlength) ;

    outputidlength = ss_decrypt(SystemInfo.Privatekey[channel], SystemInfo.Modnumber[channel], (unsigned char *)id, (unsigned long)idlength, outputid, (unsigned long)USER_SIZE) ;
*/
//  skip compare id, passwd..

    Userauthres.identifier = htons(IDENTIFIER) ;
    Userauthres.cmd = htons(CMD_USERAUTH_RES) ;
    Userauthres.length = htons(USERAUTHRES_SIZE) ;
    Userauthres.result = htons(ACCEPTED) ;  // REJECTED
    Userauthres.chaccess = htons(255) ;

    memcpy(m_SendBuffer[channel], &Userauthres, USERAUTHRES_SIZE) ;
    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], USERAUTHRES_SIZE, 0) ;
#ifdef NETWORK_DEBUG
    DEBUG_PRI("userauthres packet sendlen = %d\n",sendlen) ;
#endif
    memset(m_SendBuffer[channel], MAXBUFF, 0) ;
}


void userconfirmreq(int channel, char*data, int len)
{
    int sendlen = 0 ;

//    USERCONFIRMREQ  *Userconfirmreq ;
    COMRESPACKET Userconfirmres ;

//    Userconfirmreq = (USERCONFIRMREQ *)data ;

    Userconfirmres.identifier = htons(IDENTIFIER) ;
    Userconfirmres.cmd = htons(CMD_USERCONFIRM_RES) ;
    Userconfirmres.length = htons(USERCONFIRMRES_SIZE) ;
    Userconfirmres.result = htons(TRUE) ;

    memcpy(m_SendBuffer[channel], &Userconfirmres, USERCONFIRMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], USERCONFIRMRES_SIZE, 0) ;
#ifdef NETWORK_DEBUG
    DEBUG_PRI("contorl user confirmres.. packet sendlen = %d\n",sendlen) ;
#endif

}


void playlistparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("playlistparamreq packet receive...\n") ;
#endif

    int sendlen = 0,  i = 0, j = 0, cnt = 0;  // constant rec
   	file_info_t *pinfo=NULL ;

    // count = from avi_count....

    PLAYLISTPARAMREQ  *Playlistparamreq ;
    PLAYLISTPARAMRES  Playlistparamres ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    Playlistparamreq = (PLAYLISTPARAMREQ *)data ;


	cnt = app_file_get_list(ntohs(Playlistparamreq->rec_type), &pinfo, ON);;

//    printf("total pinfo->file_cnt = %d\n",cnt) ;

    Playlistparamres.identifier = htons(IDENTIFIER) ;
    Playlistparamres.cmd = htons(CMD_PLAYLISTPARAM_RES) ;
    Playlistparamres.length = htons(PLAYLISTPARAMRES_SIZE + 6 + cnt*STRING_SIZE) ;
    Playlistparamres.rec_type = Playlistparamreq->rec_type ;
    Playlistparamres.total_count = htons(cnt) ;
    Playlistparamres.file_count = htons(cnt) ;

    if(cnt != 0)
    {
    	Playlistparamres.result = htons(0x00) ;
		if(ntohs(Playlistparamreq->option) == 0x00)
		{
		    curpos = 1 ;
		    if(cnt < FILECNT)
		    {
	    		Playlistparamres.length = htons(PLAYLISTPARAMRES_SIZE + 6 + cnt*STRING_SIZE) ;
    	        Playlistparamres.file_count = htons(cnt) ;
                for(i = 0; i < cnt ; i++)
                {
		            strncpy(&Playlistparamres.filename[i * STRING_SIZE], pinfo[i].fname, STRING_SIZE) ;
//		            printf("no = %d  fileName = %s\n",i + 1, pinfo[i].fname) ;
                }
		    }
		    else
		    {
	    		Playlistparamres.length = htons(PLAYLISTPARAMRES_SIZE + 6 + FILECNT*STRING_SIZE) ;
	   	        Playlistparamres.file_count = htons(FILECNT) ;
                for(i = 0; i < FILECNT*curpos ; i++)
                {
		            strncpy(&Playlistparamres.filename[i * STRING_SIZE], pinfo[i].fname, STRING_SIZE) ;
//		            printf("no = %d  fileName = %s\n",i + 1, pinfo[i].fname) ;
                }
		    }
        }
		else
		{
		    if(cnt < FILECNT * curpos)
		    {
				Playlistparamres.result = htons(0x01) ; // there is no next files
	    		Playlistparamres.length = htons(PLAYLISTPARAMRES_SIZE + 6) ;
	            Playlistparamres.file_count = htons(0) ;
				printf("There is no next 100 files curpos = %d......\n",curpos) ;
		    }
		    else
		    {
				if(FILECNT*(curpos + 1) < cnt)
				{
	    		    Playlistparamres.length 	= htons(PLAYLISTPARAMRES_SIZE + 6 + FILECNT*STRING_SIZE) ;
    	            Playlistparamres.file_count = htons(FILECNT) ;
				    for(i = FILECNT*curpos ; i < FILECNT*(curpos + 1)  ; i++)
				    {
				        strncpy(&Playlistparamres.filename[j * STRING_SIZE], pinfo[i].fname, STRING_SIZE) ;
//                        printf("no = %d  fileName = %s\n",i + 1, pinfo[i].fname) ;
						j++ ;
				    }
				    curpos += 1 ;
				}
				else
				{
	    		    Playlistparamres.length = htons(PLAYLISTPARAMRES_SIZE + 6 + (cnt-FILECNT*curpos)*STRING_SIZE) ;
				    Playlistparamres.file_count = htons(cnt - FILECNT*curpos) ;
				    for(i = FILECNT*curpos ; i < cnt ; i++)
				    {
				        strncpy(&Playlistparamres.filename[j * STRING_SIZE], pinfo[i].fname, STRING_SIZE) ;
//                        printf("no = %d  fileName = %s\n",i + 1, pinfo[i].fname) ;
						j++ ;
				    }

				}
		    }
		}
    }
    else
    {
        Playlistparamres.result = htons(0x01) ;
    }

	memcpy(m_SendBuffer[channel], &Playlistparamres, ntohs(Playlistparamres.length)) ;
    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], ntohs(Playlistparamres.length) , 0) ;

	app_file_free_list(&pinfo);

#ifdef NETWORK_DEBUG
    DEBUG_PRI("playlistparamres.. packet sendlen = %d\n",sendlen) ;
#endif


}

void displayparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("displayparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    DISPLAYPARAMRES Displayparamres ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;
//    UCXLIB_getSetPrm(pSet);

    Displayparamres.identifier 		= htons(IDENTIFIER) ;
    Displayparamres.cmd 			= htons(CMD_DISPLAYPARAM_RES) ;
    Displayparamres.length 			= htons(DISPLAYPARAMRES_SIZE) ;
    Displayparamres.brightness 		= htons(3) ;
    Displayparamres.screen_savetime = htons(2) ;
    Displayparamres.mirroring 		= htons(app_set->lcd.sub_mirror) ;

    printf("app_set->lcd.sub_mirror = %d\n",app_set->lcd.sub_mirror) ;

    memcpy(m_SendBuffer[channel], &Displayparamres, DISPLAYPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], DISPLAYPARAMRES_SIZE, 0) ;
#ifdef NETWORK_DEBUG
    DEBUG_PRI("displayparamres.. packet sendlen = %d\n",sendlen) ;
#endif


}


void audioparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("audioparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    AUDIOPARAMRES Audioparamres ;

    Audioparamres.identifier  = htons(IDENTIFIER) ;
    Audioparamres.cmd         = htons(CMD_AUDIOPARAM_RES) ;
    Audioparamres.length      = htons(AUDIOPARAMRES_SIZE) ;
    Audioparamres.mic         = htons(app_set->aud.mic_on) ;
    Audioparamres.guide_voice = htons(app_set->aud.snd_on) ;
    Audioparamres.volume      = htons(3) ;

    memcpy(m_SendBuffer[channel], &Audioparamres, AUDIOPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], AUDIOPARAMRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("audioparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}


void qualityparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("qualityparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    QUALITYPARAMREQ *Qualityparamreq ;
    QUALITYPARAMRES Qualityparamres ;

    Qualityparamreq = (QUALITYPARAMREQ *)data ;

    Qualityparamres.identifier   = htons(IDENTIFIER) ;
    Qualityparamres.cmd          = htons(CMD_QUALITYPARAM_RES) ;
    Qualityparamres.length       = htons(QUALITYPARAMRES_SIZE) ;
    Qualityparamres.mode = Qualityparamreq->mode ;

    if(!ntohs(Qualityparamreq->mode))
    {
    	Qualityparamres.bitrate      = htons(app_set->ch[0].quality) ;
    	Qualityparamres.framerate    = htons(app_set->ch[0].framerate) ;
    }
    else
    {
    	Qualityparamres.bitrate      = htons(app_set->ch_prk[0].quality) ;
    	Qualityparamres.framerate    = htons(app_set->ch_prk[0].framerate) ;
    }
printf("mode = %d\n",ntohs(Qualityparamreq->mode)) ;
printf("bitrate = %d\n",app_set->ch[0].quality) ;
printf("framerate = %d\n",app_set->ch[0].framerate) ;

    memcpy(m_SendBuffer[channel], &Qualityparamres, QUALITYPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], QUALITYPARAMRES_SIZE, 0 ) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("qualityparamres.. packet sendlen = %d\n",sendlen) ;
#endif
}


void cambrightparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("brightparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    CAMBRIGHTPARAMRES Cambrightparamres ;

    Cambrightparamres.identifier = htons(IDENTIFIER) ;
    Cambrightparamres.cmd = htons(CMD_CAMBRIGHTPARAM_RES) ;
    Cambrightparamres.length = htons(CAMBRIGHTPARAMRES_SIZE) ;
    Cambrightparamres.Frontbrightness = htons(app_set->cam.front_bright) ;
    Cambrightparamres.Rearbrightness = htons(app_set->cam.rear_bright) ;

    memcpy(m_SendBuffer[channel], &Cambrightparamres, CAMBRIGHTPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], QUALITYPARAMRES_SIZE, 0 ) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("cambrightparamres.. packet sendlen = %d\n",sendlen) ;
#endif
}

void systemparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("systemparamreq packet receive...\n") ;
#endif

    int sendlen=0;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    SYSTEMPARAMRES Systemparamres ;

    Systemparamres.identifier = htons(IDENTIFIER) ;
    Systemparamres.cmd	      = htons(CMD_SYSTEMPARAM_RES) ;
    Systemparamres.length     = htons(SYSTEMPARAMRES_SIZE) ;

    Systemparamres.wifiset  	= htons(app_cfg->state.wifi) ;
    Systemparamres.language   	= htons(app_set->lang) ; // temp source korean

    memcpy(m_SendBuffer[channel], &Systemparamres, SYSTEMPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], SYSTEMPARAMRES_SIZE, 0 ) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("systemparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}

void infoparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("infoparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    INFOPARAMRES Infoparamres ;

    Infoparamres.identifier   = htons(IDENTIFIER) ;
    Infoparamres.cmd          = htons(CMD_INFOPARAM_RES) ;
    Infoparamres.length       = htons(INFOPARAMRES_SIZE) ;
    strncpy(Infoparamres.HWver, app_set->info.hw_ver, STR_SIZE) ;
    strncpy(Infoparamres.SWver, app_set->info.sw_ver, STR_SIZE) ;
    strncpy(Infoparamres.Product, app_set->info.model, STR_SIZE) ;
    strncpy(Infoparamres.ModelNo, app_set->info.pname, STR_SIZE) ;
    strncpy(Infoparamres.SSID, app_set->net.ssid, STR_SIZE) ;
    strncpy(Infoparamres.Passwd, app_set->net.pwd, CHAR_16) ;


    memcpy(m_SendBuffer[channel], &Infoparamres, INFOPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], INFOPARAMRES_SIZE, 0 ) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("infoparamres.. packet sendlen = %d\n",sendlen) ;
#endif


}


void timesetparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("timesetparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    TIMESETPARAMRES Timesetparamres ;

    time_t cur_time ;
    struct tm date;

    time(&cur_time) ;
    localtime_r(&cur_time, &date) ;

    Timesetparamres.identifier  = htons(IDENTIFIER) ;
    Timesetparamres.cmd		= htons(CMD_TIMESETPARAM_RES) ;
    Timesetparamres.length	= htons(TIMESETPARAMRES_SIZE) ;
    Timesetparamres.year	= htons(date.tm_year + 1900) ;
    Timesetparamres.month	= htons(date.tm_mon + 1) ;
    Timesetparamres.day 	= htons(date.tm_mday) ;
    Timesetparamres.hour	= htons(date.tm_hour) ;
    Timesetparamres.minute	= htons(date.tm_min) ;
    Timesetparamres.second	= htons(date.tm_sec) ;

    memcpy(m_SendBuffer[channel], &Timesetparamres, TIMESETPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], TIMESETPARAMRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("timesetparamres.. packet sendlen = %d\n",sendlen) ;
#endif


}

void sdparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("sdparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    SDPARAMRES Sdparamres ;

    Sdparamres.identifier   = htons(IDENTIFIER) ;
    Sdparamres.cmd          = htons(CMD_SDPARAM_RES) ;
    Sdparamres.length       = htons(SDPARAMRES_SIZE) ;
    Sdparamres.format_cycle = htons(app_set->fdur.weeks) ;

    memcpy(m_SendBuffer[channel], &Sdparamres, SDPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], SDPARAMRES_SIZE, 0 ) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("sdparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}

void sensorparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("sensorparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;
 
    SENSORPARAMRES Sensorparamres ;

    Sensorparamres.identifier 			= htons(IDENTIFIER) ;
    Sensorparamres.cmd        			= htons(CMD_SENSORPARAM_RES) ;
    Sensorparamres.length     			= htons(SENSORPARAMRES_SIZE) ;
    Sensorparamres.shock_sensitivity 	= htons(app_set->wd.gsn) ;
    Sensorparamres.motion_sensitivity 	= htons(app_set->wd.motion) ;
    Sensorparamres.sensing_parking_mode = htons(app_set->wd.auto_park) ;

    memcpy(m_SendBuffer[channel], &Sensorparamres, SENSORPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], SENSORPARAMRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("sensorparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}

void operateparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("operateparamreq packet receive...\n") ;
#endif

    int sendlen = 0, retval = 0, volttype = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    OPERATEPARAMRES Operateparamres ;

    Operateparamres.identifier 			= htons(IDENTIFIER) ;
    Operateparamres.cmd        			= htons(CMD_OPERATEPARAM_RES) ;
    Operateparamres.length     			= htons(OPERATEPARAMRES_SIZE) ;
    Operateparamres.bettery_safetime 	= htons(app_set->wd.bat_safe) ;
    Operateparamres.temperature 		= htons(app_set->wd.temp) ;

    retval = app_dev_get_volt_val();
    if(retval >= VOLT_24V_MIN)
		volttype = VOLT_LEVEL_24V ;
    else
        volttype = VOLT_LEVEL_12V ;

    Operateparamres.voltage_type 		= htons(volttype) ;
    Operateparamres.operate_voltage 	= htons(app_set->wd.volt) ;


    memcpy(m_SendBuffer[channel], &Operateparamres, OPERATEPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], OPERATEPARAMRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("operateparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}

void indicatorparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("indicatorparamreq packet receive...\n") ;
#endif

    int sendlen = 0;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    INDICATORPARAMRES Indicatorparamres ;

    Indicatorparamres.identifier    = htons(IDENTIFIER) ;
    Indicatorparamres.cmd	    	= htons(CMD_INDICATORPARAM_RES) ;
    Indicatorparamres.length	    = htons(INDICATORPARAMRES_SIZE) ;
    Indicatorparamres.state_rec     = htons(app_cfg->state.rec) ;
    Indicatorparamres.state_mmc     = htons(app_cfg->state.mmc) ;
    Indicatorparamres.state_gps     = htons(app_cfg->state.gps) ;
    Indicatorparamres.state_wifi    = htons(app_cfg->state.wifi) ;
    Indicatorparamres.state_mic     = htons(app_cfg->state.mic) ;
//    Indicatorparamres.state_speaker = htons(app_cfg->state.snd) ;
    Indicatorparamres.state_speaker = htons(0) ;


    memcpy(m_SendBuffer[channel], &Indicatorparamres, INDICATORPARAMRES_SIZE) ;
    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], INDICATORPARAMRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("indicatorparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}


void userparamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("userparamreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    gettimeofday(&rtv, NULL) ;
    Pretime = (unsigned long)(rtv.tv_sec % 10000u) ;

    USERPARAMRES Userparamres ;

    Userparamres.identifier = htons(IDENTIFIER) ;
    Userparamres.cmd        = htons(CMD_USERPARAM_RES) ;
    Userparamres.length     = htons(USERPARAMRES_SIZE) ;

    strncpy(Userparamres.userid, "test", USER_SIZE) ;
    strncpy(Userparamres.userpasswd, "test", USER_SIZE) ;
    Userparamres.channelaccess = htons(255) ;
    Userparamres.controlaccess = htonl(255) ;

    memcpy(m_SendBuffer[channel], &Userparamres, USERPARAMRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], USERPARAMRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("userparamres.. packet sendlen = %d\n",sendlen) ;
#endif

}



void displaycfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("displaycfgreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    DISPLAYCFGREQ *Displaycfgreq ;
    COMRESPACKET Displaycfgres ;

    Displaycfgreq = (DISPLAYCFGREQ *)data ;

	if(MIRROR_MAX > ntohs(Displaycfgreq->mirroring)
		&& ntohs(Displaycfgreq->mirroring) >= MIRROR_VH){
		app_set->lcd.sub_mirror = ntohs(Displaycfgreq->mirroring);
		ctrl_hdcam_mirror(1, app_set->lcd.sub_mirror);
        ubx_change_setting() ;
	}

   // setting function
    Displaycfgres.identifier = htons(IDENTIFIER) ;
    Displaycfgres.cmd	     = htons(CMD_DISPLAYCFG_RES) ;
    Displaycfgres.length     = htons(DISPLAYCFGRES_SIZE) ;
    Displaycfgres.result     = htons(CFGRES_OK) ;

    memcpy(m_SendBuffer[channel], &Displaycfgres, DISPLAYCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], DISPLAYCFGRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("displaycfgres.. packet sendlen = %d\n",sendlen) ;
#endif
}

void audiocfgreq(int channel, char *data, int len)
{
	int retval = 0 ;
#ifdef NETWORK_DEBUG

    DEBUG_PRI("audiocfgreq packet receive...\n") ;
#endif
    int sendlen = 0 ;
    AUDIOCFGREQ *Audiocfgreq ;
    COMRESPACKET Audiocfgres ;

    Audiocfgreq = (AUDIOCFGREQ *)data ;

	app_aud_capt_ctrl( ntohs(Audiocfgreq->mic)) ;
    retval = app_snd_enable_live( ntohs(Audiocfgreq->guide_voice)) ;

    Audiocfgres.identifier = htons(IDENTIFIER) ;
    Audiocfgres.cmd        = htons(CMD_AUDIOCFG_RES) ;
    Audiocfgres.length     = htons(AUDIOCFGRES_SIZE) ;

    ubx_change_setting() ;
    if(retval == SOK)
        Audiocfgres.result     = htons(CFGRES_OK) ; // success.
    else
        Audiocfgres.result     = htons(CFGRES_NOCHANGE) ; // fail.

    memcpy(m_SendBuffer[channel], &Audiocfgres, AUDIOCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], AUDIOCFGRES_SIZE, 0) ;


#ifdef NETWORK_DEBUG
    DEBUG_PRI("audiocfgres packet sendlen = %d\n",sendlen) ;
#endif
}

void qualitycfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("qualitycfgreq packet receive...\n") ;
#endif

    int sendlen = 0, retval = 0, mode ;

    QUALITYCFGREQ *Qualitycfgreq ;
    QUALITYCFGRES Qualitycfgres ;

    Qualitycfgreq = (QUALITYCFGREQ *)data ;

    mode = ntohs(Qualitycfgreq->mode) ;

    printf("qualitycfgreq mode = %d\n",mode) ;

    retval = ctrl_set_enc_prm(mode, ntohs(Qualitycfgreq->framerate), ntohs(Qualitycfgreq->bitrate)) ;
    ubx_change_setting() ;
	 
    Qualitycfgres.identifier = htons(IDENTIFIER) ;
    Qualitycfgres.cmd        = htons(CMD_QUALITYCFG_RES) ;
    Qualitycfgres.length     = htons(QUALITYCFGRES_SIZE) ;
    Qualitycfgres.mode	     = htons(mode) ;

    if(retval == SOK)
    	Qualitycfgres.result     = htons(CFGRES_OK) ;
    else
    	Qualitycfgres.result     = htons(CFGRES_NOCHANGE) ;

    memcpy(m_SendBuffer[channel], &Qualitycfgres, QUALITYCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], QUALITYCFGRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("qualitycfgres packes sendlen = %d\n",sendlen) ;
#endif

}

void cambrightcfgreq(int channel, char *data, int len)
{

#ifdef NETWORK_DEBUG
    DEBUG_PRI("cambrightcfgreq packet receive...\n") ;
#endif

    int sendlen = 0 ;

    CAMBRIGHTCFGREQ *Cambrightcfgreq ;
    CAMBRIGHTCFGRES Cambrightcfgres ;

    Cambrightcfgreq = (CAMBRIGHTCFGREQ *)data ;

    printf("cambrightcfgreq->Frontbrightness = %d\n",ntohs(Cambrightcfgreq->Frontbrightness)) ;
    printf("cambrightcfgreq->Rearbrightness = %d\n",ntohs(Cambrightcfgreq->Rearbrightness)) ;

    ctrl_hdcam_brightness(0, ntohs(Cambrightcfgreq->Frontbrightness)) ;
    app_set->cam.front_bright = ntohs(Cambrightcfgreq->Frontbrightness) ;
    ctrl_hdcam_brightness(1, ntohs(Cambrightcfgreq->Rearbrightness)) ;
    app_set->cam.rear_bright = ntohs(Cambrightcfgreq->Rearbrightness) ;

    ubx_change_setting() ; 
    Cambrightcfgres.identifier = htons(IDENTIFIER) ;
    Cambrightcfgres.cmd        = htons(CMD_CAMBRIGHTCFG_RES) ;
    Cambrightcfgres.length     = htons(CAMBRIGHTCFGRES_SIZE) ;
    Cambrightcfgres.result     = htons(CFGRES_OK) ;

    memcpy(m_SendBuffer[channel], &Cambrightcfgres, CAMBRIGHTCFGRES_SIZE) ;
    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], CAMBRIGHTCFGRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("cambrightcfgres packes sendlen = %d\n",sendlen) ;
#endif

} 


void systemcfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("systemcfgreq packet receive...\n") ;
#endif

    int sendlen = 0, retval = 0 ;

    SYSTEMCFGREQ *Systemcfgreq ;
    COMRESPACKET Systemcfgres ;

    Systemcfgreq = (SYSTEMCFGREQ *)data ;

    if(ntohs(Systemcfgreq->fwupdate)){
    	//retval = ctrl_upgrade();
		//if(retval == SOK)
			//dev_system_reboot();
   	}

    if(ntohs(Systemcfgreq->initial)){
	    ubx_set_default();
	    OSA_waitMsecs(100);

        ubx_write_setting();
	    dev_system_reboot(REBOOT_NORMAL);
   	}

	if(app_set->net.use_wifi != ntohs(Systemcfgreq->wifiset)){
		app_set->net.use_wifi = ntohs(Systemcfgreq->wifiset);
	    retval = ctrl_wifi_set(app_set->net.use_wifi);
	}


 	app_set->lang = ntohs(Systemcfgreq->language);
    ubx_change_setting() ;

    Systemcfgres.identifier = htons(IDENTIFIER) ;
    Systemcfgres.cmd        = htons(CMD_SYSTEMCFG_RES) ;
    Systemcfgres.length     = htons(SYSTEMCFGRES_SIZE) ;

    if(retval == SOK)
    	Systemcfgres.result     = htons(CFGRES_OK) ;
    else
    	Systemcfgres.result     = htons(CFGRES_NOCHANGE) ;

    memcpy(m_SendBuffer[channel], &Systemcfgres, SYSTEMCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], SYSTEMCFGRES_SIZE, 0) ;

    sleep(5) ;

	retval = ctrl_wifi_set(app_set->net.use_wifi);

#ifdef NETWORK_DEBUG
    DEBUG_PRI("systemcfgres packes sendlen = %d\n",sendlen) ;
#endif
}


void timesetcfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("timesetcfgreq packet receive...\n") ;
#endif
    int sendlen = 0, retval = 0 ;

    TIMESETCFGREQ *Timesetcfgreq ;
    COMRESPACKET Timesetcfgres ;

    Timesetcfgreq = (TIMESETCFGREQ *)data ;

    retval = ctrl_time_set(ntohs(Timesetcfgreq->year), ntohs(Timesetcfgreq->month), ntohs(Timesetcfgreq->day),
    			ntohs(Timesetcfgreq->hour), ntohs(Timesetcfgreq->minute), ntohs(Timesetcfgreq->second), 0) ;

    Timesetcfgres.identifier = htons(IDENTIFIER) ;
    Timesetcfgres.cmd        = htons(CMD_TIMESETCFG_RES);
    Timesetcfgres.length     = htons(TIMESETCFGRES_SIZE) ;

    if(retval == SOK)
	{
	    Timesetcfgres.result	= htons(CFGRES_OK) ;
	    app_cfg->state.tsync 	= 0;
		
   	}
    else
	{
	    Timesetcfgres.result     = htons(CFGRES_NOCHANGE) ;
   	}

    memcpy(m_SendBuffer[channel], &Timesetcfgres, TIMESETCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], TIMESETCFGRES_SIZE, 0) ;


#ifdef NETWORK_DEBUG
    DEBUG_PRI("timesetcfgres packet sendlen = %d\n",sendlen) ;
#endif
}

void sdcfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("sdcfgreq packet receive...\n") ;
#endif
    int sendlen = 0, retval = EFAIL, ret = 0 ;

    SDCFGREQ *Sdcfgreq ;
    COMRESPACKET Sdcfgres ;

    Sdcfgreq = (SDCFGREQ *)data ;

    if(ntohs(Sdcfgreq->format))
    {
        system_buzzer(SYSTEM_OPER);
		ret = ctrl_sd_format() ;
    	if(ret == SOK)
            dev_system_reboot(REBOOT_NORMAL);
        else
            app_cfg->state.sd_buzzer = 1;
    }
    else if(ntohs(Sdcfgreq->format_cycle) >= SD_FORMAT_OFF
		&& ntohs(Sdcfgreq->format_cycle) < SD_FORMAT_MAX)
	{
	    app_set->fdur.weeks=ntohs(Sdcfgreq->format_cycle);
        set_format_dur();
        ubx_change_setting() ;
		retval = SOK;
   	}

    Sdcfgres.identifier = htons(IDENTIFIER) ;
    Sdcfgres.cmd        = htons(CMD_SDCFG_RES) ;
    Sdcfgres.length     = htons(SDCFGRES_SIZE) ;

    if(retval == SOK)
    	Sdcfgres.result     = htons(CFGRES_OK) ;
    else
    	Sdcfgres.result     = htons(CFGRES_NOCHANGE) ;

    memcpy(m_SendBuffer[channel], &Sdcfgres, SDCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], SDCFGRES_SIZE, 0) ;


#ifdef NETWORK_DEBUG
    DEBUG_PRI("sdcfgregs.. packet sendlen = %d\n",sendlen) ;
#endif
}


void sensorcfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("sensorcfgreq packet receive...\n") ;
#endif
    int sendlen = 0, retval = EFAIL ;

    SENSORCFGREQ *Sensorcfgreq ;
    COMRESPACKET Sensorcfgres ;

    Sensorcfgreq = (SENSORCFGREQ *)data ;

	if(GSN_IDX_MAX > ntohs(Sensorcfgreq->shock_sensitivity)
		&& ntohs(Sensorcfgreq->shock_sensitivity) >= GSN_IDX_01){
		app_set->wd.gsn = ntohs(Sensorcfgreq->shock_sensitivity);
		retval = SOK;
	}

	if(MOTION_IDX_MAX > ntohs(Sensorcfgreq->motion_sensitivity)
		&& ntohs(Sensorcfgreq->motion_sensitivity) >= MOTION_IDX_OFF){
		app_set->wd.motion = ntohs(Sensorcfgreq->motion_sensitivity);
		retval = SOK;
	}

	if(AUTOPARK_MAX > ntohs(Sensorcfgreq->sensing_parking_mode)
		&& ntohs(Sensorcfgreq->sensing_parking_mode) >= AUTOPARK_OFF){
		app_set->wd.auto_park = ntohs(Sensorcfgreq->sensing_parking_mode);
		app_cfg->apark_time = get_auto_prk_val(app_set->wd.auto_park);
		retval = SOK;
	}
    ubx_change_setting() ;
    
    Sensorcfgres.identifier = htons(IDENTIFIER) ;
    Sensorcfgres.cmd        = htons(CMD_SENSORCFG_RES) ;
    Sensorcfgres.length     = htons(SENSORCFGRES_SIZE) ;

    if(retval == SOK)
    	Sensorcfgres.result     = htons(CFGRES_OK) ;
    else
    	Sensorcfgres.result     = htons(CFGRES_NOCHANGE) ;

    memcpy(m_SendBuffer[channel], &Sensorcfgres, SENSORCFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], SENSORCFGRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("sensor cfgres packes sendlen = %d\n",sendlen) ;
#endif
}


void operatecfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("operatecfgreq packet receive...\n") ;
#endif
    int sendlen = 0, retval = EFAIL;

    OPERATECFGREQ *Operatecfgreq ;
    COMRESPACKET Operatecfgres ;

    Operatecfgreq = (OPERATECFGREQ *)data ;

	if(BAT_SAFE_MAX > ntohs(Operatecfgreq->bettery_safetime)
		&& ntohs(Operatecfgreq->bettery_safetime) >= BAT_SAFE_OFF){
		app_set->wd.bat_safe = ntohs(Operatecfgreq->bettery_safetime);
		app_cfg->bsafe_time = get_bat_safe_val(app_set->wd.bat_safe);
		retval = SOK;
	}

	if(TEMP_IDX_MAX > ntohs(Operatecfgreq->temperature)
		&& ntohs(Operatecfgreq->temperature) >= TEMP_IDX_1){
		app_set->wd.temp = ntohs(Operatecfgreq->temperature);
		app_cfg->temp_high 	= get_temp_val(app_set->wd.temp);
		retval = SOK;
	}


	if(VOLT_IDX_MAX > ntohs(Operatecfgreq->operate_voltage)
		&& ntohs(Operatecfgreq->operate_voltage) >= VOLT_IDX_1){
		app_set->wd.volt = ntohs(Operatecfgreq->operate_voltage);
		retval = SOK;
	}

    ubx_change_setting() ;
    Operatecfgres.identifier = htons(IDENTIFIER) ;
    Operatecfgres.cmd        = htons(CMD_OPERATECFG_RES) ;
    Operatecfgres.length     = htons(OPERATECFGRES_SIZE) ;
    

    if(retval == SOK)
    	Operatecfgres.result     = htons(CFGRES_OK) ;
    else
    	Operatecfgres.result     = htons(CFGRES_NOCHANGE) ;

    memcpy(m_SendBuffer[channel], &Operatecfgres, OPERATECFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], OPERATECFGRES_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("operatecfgres packes sendlen = %d\n",sendlen) ;
#endif
}


void wificfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("wificfgreq packet receive...\n") ;
#endif
    int sendlen = 0, retssid = 0, retpasswd = 0, retval = EFAIL;

    WIFICFGREQ *Wificfgreq ;
    COMRESPACKET   Wificfgres ;

    Wificfgreq = (WIFICFGREQ *)data ;

	if(((Wificfgreq->SSID != NULL) && strlen(Wificfgreq->SSID) < CHAR_32)
		&& (strcmp(Wificfgreq->SSID, app_set->net.ssid)!=0)){
		sprintf(app_set->net.ssid,"%s", Wificfgreq->SSID);
        retssid = SOK ;
	}
    else
    {
        retssid = EFAIL ;
    }

	if((strlen(Wificfgreq->PASSWD) < CHAR_16 && strlen(Wificfgreq->PASSWD) >= CHAR_8)
		&& (strcmp(Wificfgreq->PASSWD, app_set->net.pwd)!=0)){
		sprintf(app_set->net.pwd, "%s", Wificfgreq->PASSWD);
        retpasswd = SOK ;
	}
    else
    {
        retpasswd = EFAIL ;
    }

    if(retssid || retpasswd)
        retval = SOK ;
    

    ctrl_wifi_set(0);

    Wificfgres.identifier = htons(IDENTIFIER) ;
    Wificfgres.cmd        = htons(CMD_WIFICFG_RES) ;
    Wificfgres.length     = htons(WIFICFGRES_SIZE) ;

    if(retval == SOK)
    {
        ubx_change_setting() ;
        sync() ;
        Wificfgres.result     = htons(CFGRES_OK) ;
    }
    else
    {
        Wificfgres.result     = htons(CFGRES_NOCHANGE) ;
    }
    memcpy(m_SendBuffer[channel], &Wificfgres, WIFICFGRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], WIFICFGRES_SIZE, 0) ;

    ctrl_wifi_set(1) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("wificfgres packet sendlen = %d\n",sendlen) ;
#endif

}

void usercfgreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("usercfgreq packet receive...\n") ;
#endif
    int sendlen = 0 ;

    USERCFGREQ *Usercfgreq ;
    COMRESPACKET Usercfgres ;

    Usercfgreq = (USERCFGREQ *)data ;

    Usercfgres.identifier = htons(IDENTIFIER) ;
    Usercfgres.cmd        = htons(CMD_USERCFG_RES) ;
    Usercfgres.length     = htons(USERCFGRES_SIZE) ;
    Usercfgres.result     = htons(CFGRES_OK) ;

    memcpy(m_SendBuffer[channel], &Usercfgres, USERCFGRES_SIZE) ;
    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], USERCFGRES_SIZE, 0) ;


#ifdef NETWORK_DEBUG
    DEBUG_PRI("usercfgres packet sendlen = %d\n",sendlen) ;
#endif
}

void dbtdata(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("dbtdata packet receive...\n") ;
#endif
    int Realbitrate, Net_bandwidth, bitrate_idx, framerate_idx, Cpu_load, Memory_usage;
    int total_memory = 0, mem_usage = 0 ;

    DBTDATA *Dbtdata ;
    Dbtdata = (DBTDATA *)data ;

//    UCXLIB_getSetPrm(pSet);

	printf("bitrate = %d\n",app_set->ch[0].quality) ;
	printf("framerate = %d\n",app_set->ch[0].framerate) ;

    bitrate_idx 	= app_set->ch[ntohs(Dbtdata->Curchannel)].quality ;
    framerate_idx 	= app_set->ch[ntohs(Dbtdata->Curchannel)].framerate;
    Realbitrate 	= get_bitrate_val(bitrate_idx, app_set->ch[ntohs(Dbtdata->Curchannel)].resol) ;
    Net_bandwidth 	= ntohs(Dbtdata->Net_bandwidth) ;

    Cpu_load 		= ntohs(Dbtdata->Cpuload) ;
    mem_usage 		= ntohs(Dbtdata->Mem_usage) ;
    total_memory 	= ntohs(Dbtdata->Mem_size) ;
    Memory_usage 	= (mem_usage * 100)/total_memory ;

    printf("Memory_usage = %d\n",Memory_usage) ;
/*
    if(Realbitrate > Net_bandwidth)
    {
        if(Realbitrate - Net_bandwidth > Net_bandwidth/5)  // over the Gap 20% of Net_bandwidth
        {
	    if(bitrate_idx < QUALITY_LOW) // 2
    	    	UCXLIB_setBitrate(bitrate_idx++) ;
            else
            {
	    	if(framerate_idx < FRAMERATE_15)
            	    UCXLIB_setFramerate(framerate_idx++) ;
	    }
	}
    }
    else
    {
        if(Net_bandwidth - Realbitrate > Net_bandwidth/5)  // over the Gap 20% of Net_bandwidth
	{
	    if(bitrate_idx > QUALITY_HIGH) // 0
                UCXLIB_setBitrate(bitrate_idx--) ;
            else
            {
                if(framerate_idx > FRAMERATE_30)
                    UCXLIB_setFramerate(framerate_idx--) ;
            }
	}
    }

    if(Cpu_load > 0 && Cpu_load <= 33)
    {
	if(bitrate_idx > QUALITY_HIGH) // 0
            UCXLIB_setBitrate(bitrate_idx--) ;
        else
        {
            if(framerate_idx > FRAMERATE_30)
                UCXLIB_setFramerate(framerate_idx--) ;
	}
    }
    if(Cpu_load > 33 && Cpu_load <= 66)
    {
	if(bitrate_idx > QUALITY_HIGH) // 2
    	    UCXLIB_setBitrate(bitrate_idx--) ;
        else
        {
	    if(framerate_idx > FRAMERATE_30)
            	UCXLIB_setFramerate(framerate_idx--) ;
	}
    }
    if(Cpu_load > 67 && Cpu_load <= 100)
    {
	if(bitrate_idx < QUALITY_LOW) // 2
    	    UCXLIB_setBitrate(bitrate_idx++) ;
        else
        {
	    if(framerate_idx < FRAMERATE_15)
            	UCXLIB_setFramerate(framerate_idx++) ;
	}
    }


    if(Memory_usage > 0 && Memory_usage <= 33)
    {
	if(bitrate_idx > QUALITY_HIGH) // 0
            UCXLIB_setBitrate(bitrate_idx--) ;
        else
        {
            if(framerate_idx > FRAMERATE_30)
                UCXLIB_setFramerate(framerate_idx--) ;
	}
    }
    if(Memory_usage > 33 && Memory_usage <= 66)
    {
	if(bitrate_idx > QUALITY_HIGH) // 2
    	    UCXLIB_setBitrate(bitrate_idx--) ;
        else
        {
	    if(framerate_idx > FRAMERATE_30)
            	UCXLIB_setFramerate(framerate_idx--) ;
	}
    }
    if(Memory_usage > 67 && Memory_usage <= 100)
    {
	if(bitrate_idx < QUALITY_LOW) // 2
    	    UCXLIB_setBitrate(bitrate_idx++) ;
        else
        {
	    if(framerate_idx < FRAMERATE_15)
            	UCXLIB_setFramerate(framerate_idx++) ;
	}
    }
*/

    printf("Dbtdata->Cpuclock = %d\n",ntohs(Dbtdata->Cpuclock)) ;
    printf("Dbtdata->Cpuload = %d\n",ntohs(Dbtdata->Cpuload)) ;
    printf("Dbtdata->Mem_size = %d\n",ntohs(Dbtdata->Mem_size)) ; // total
    printf("Dbtdata->Mem_usage = %d\n",ntohs(Dbtdata->Mem_usage)) ;
    printf("Dbtdata->Net_bandwidth = %d\n",ntohs(Dbtdata->Net_bandwidth)) ;
    printf("Dbtdata->Resolution = %d\n",ntohs(Dbtdata->Resolution)) ;

}

void avistreamreq(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("avistreamreq packet receive...\n") ;
#endif
    int sendlen = 0, filecnt = 0, last_size = 0, stream_size, i = 0 ;
    long filesize ;

    FILE *favi ;
    struct timeval tv ;

    char file_path[STRING_SIZE * 4] ;

    AVISTREAMREQ *Avistreamreq ;
    AVISTREAMDATA Avistreamdata;

    COMRESPACKET Avistreamerror ;

    Avistreamreq = (AVISTREAMREQ *)data ;

    switch(ntohs(Avistreamreq->rectype))
    {
		case REC_EVENT:
            sprintf(file_path, "%s/%s", DIR_REC_EVENT, Avistreamreq->filename);
            break;
        default:
            sprintf(file_path, "%s/%s", DIR_REC_DRIVE, Avistreamreq->filename);
            break;
    }

    gettimeofday(&tv, NULL) ;
    Pretime = (unsigned long)(tv.tv_sec % 10000u) ;

    favi = fopen(file_path, "rb") ;
    printf("avi file %s open..\n",file_path) ;

    if(favi == NULL)
    {
		Avistreamerror.identifier 	= htons(IDENTIFIER) ;
		Avistreamerror.cmd 			= htons(CMD_AVISTREAM_ERROR) ;
		Avistreamerror.length 		= htons(AVISTREAMERR_SIZE) ;
		Avistreamerror.result 		= htons(0x01) ; // there is no stream

        memcpy(m_SendBuffer[channel], &Avistreamerror, AVISTREAMERR_SIZE) ;

        sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], AVISTREAMERR_SIZE, 0) ;

#ifdef NETWORK_DEBUG
    DEBUG_PRI("avistream error packet sendlen = %d\n",sendlen) ;
#endif

    }
    else
    {
	fseek( favi, 0L , SEEK_END );
	filesize = ftell(favi);
	fseek(favi, (off_t)0, SEEK_SET) ;
	filecnt = filesize/PACKETSIZE + 1 ;
printf("avi file total size = %ld, fragment count = %d\n",filesize, filecnt) ;
	last_size = filesize % PACKETSIZE ;

	stream_size = PACKETSIZE ;

        for(i = 0 ; i < filecnt; i++)
	{
	    if(i == filecnt - 1)
		stream_size = last_size ;

	    Avistreamdata.identifier = htons(IDENTIFIER) ;
	    Avistreamdata.cmd	 = htons(CMD_AVISTREAM_DATA) ;
	    Avistreamdata.length	 = htons(AVISTREAMDATA_SIZE + stream_size ) ;
            Avistreamdata.FragmentNo  = htons(filecnt) ;
	    Avistreamdata.FragmentIdx = htons(i) ;

	    memcpy(m_SendBuffer[channel], &Avistreamdata, AVISTREAMDATA_SIZE) ;
	    fread(&m_SendBuffer[channel][AVISTREAMDATA_SIZE], stream_size, 1, favi) ;
//	    fread(Readbuffer, stream_size, 1, favi) ;
//	    memcpy(&m_SendBuffer[channel][AVISTREAMDATA_SIZE], Readbuffer, stream_size) ;
            sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], AVISTREAMDATA_SIZE + stream_size, 0);
//	    printf("frag no = %d, sendlen = %d\n",i, sendlen) ;
	    usleep(5000) ;
	}
        fclose(favi) ;
    }
}


void systemreset(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("systemresetreq packet receive...\n") ;
#endif

    dev_system_reboot(REBOOT_NORMAL);

}

void hlssetchannel(int channel, char *data, int len)
{
#ifdef NETWORK_DEBUG
    DEBUG_PRI("ispcfgreq packet receive...\n") ;
#endif
    int sendlen = 0 ;

    HLSCHANNEL *Hlschannel ;
    COMRESPACKET Hlschannelres ;

    Hlschannel = (HLSCHANNEL *)data ;

    //hls_setchannel(ntohs(Hlschannel->channel)) ;

    Hlschannelres.identifier = htons(IDENTIFIER) ;
    Hlschannelres.cmd        = htons(CMD_HLSCHANNEL_RES) ;
    Hlschannelres.length     = htons(HLSCHANNELRES_SIZE) ;
    Hlschannelres.result     = htons(CFGRES_OK) ;

    memcpy(m_SendBuffer[channel], &Hlschannelres, HLSCHANNELRES_SIZE) ;

    sendlen = send(SystemInfo.Channel[channel], m_SendBuffer[channel], HLSCHANNELRES_SIZE, 0) ;


#ifdef NETWORK_DEBUG
    DEBUG_PRI("hlschannelres packet sendlen = %d\n",sendlen) ;
#endif
}



