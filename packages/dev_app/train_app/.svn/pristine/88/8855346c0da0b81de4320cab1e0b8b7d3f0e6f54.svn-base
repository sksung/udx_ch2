/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_msghandler.c
 * @brief
 * @author  hwjun
 * @section MODIFY history
 *     - 2013.09.23 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <app_fcommand.h>
#include <app_message.h>
#include <app_msghandler.h>
#include <app_process.h>

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

#define MSG_MAP(msg,func) msgfunc[(msg)]=(func);
#define MSG_MAP_SRV(msg,func) msgfunc_srv[(msg)]=(func);


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

void (*msgfunc [MAXCOMMANDS])(int channel, char* data, int len) ;
void (*msgfunc_srv [MAXCOMMANDS])(char* data, int len) ;

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
 * @brief    message init function
 * @section  DESC Description
 *      - desc
 *****************************************************************************/


void msginit (void)
{
    int i ;

//    Intialize the message handler map
    for (i = 0; i < MAXCOMMANDS; i++)
    {
        msgfunc [i] = NULL ;
        msgfunc_srv [i] = NULL ;
    }

    MSG_MAP (CMD_CONNECT_USER, connect_user) 
    MSG_MAP (CMD_DEVICE_REQ, devicereq)
    MSG_MAP (CMD_USERKEY_REQ, userkeyreq)
    MSG_MAP (CMD_USERAUTH_REQ, userauthreq)
    MSG_MAP (CMD_USERCONFIRM_REQ, userconfirmreq)
    MSG_MAP (CMD_PLAYLISTPARAM_REQ, playlistparamreq)
    MSG_MAP (CMD_DISPLAYPARAM_REQ, displayparamreq)
    MSG_MAP (CMD_AUDIOPARAM_REQ, audioparamreq)
    MSG_MAP (CMD_QUALITYPARAM_REQ, qualityparamreq)

    MSG_MAP (CMD_CAMBRIGHTPARAM_REQ, cambrightparamreq) 
    MSG_MAP (CMD_SYSTEMPARAM_REQ, systemparamreq)
    MSG_MAP (CMD_INFOPARAM_REQ, infoparamreq) 
    MSG_MAP (CMD_TIMESETPARAM_REQ, timesetparamreq)
    MSG_MAP (CMD_SDPARAM_REQ, sdparamreq)
    MSG_MAP (CMD_SENSORPARAM_REQ, sensorparamreq)
    MSG_MAP (CMD_OPERATEPARAM_REQ, operateparamreq)
    MSG_MAP (CMD_INDICATORPARAM_REQ, indicatorparamreq)
    MSG_MAP (CMD_USERPARAM_REQ, userparamreq)
    MSG_MAP (CMD_RECDURPARAM_REQ, recdurparamreq)

    MSG_MAP (CMD_RECDURCFG_REQ, recdurcfgreq)
    MSG_MAP (CMD_DISPLAYCFG_REQ, displaycfgreq)
    MSG_MAP (CMD_AUDIOCFG_REQ, audiocfgreq)
    MSG_MAP (CMD_QUALITYCFG_REQ, qualitycfgreq)

    MSG_MAP (CMD_CAMBRIGHTCFG_REQ, cambrightcfgreq) 

    MSG_MAP (CMD_SYSTEMCFG_REQ, systemcfgreq)
    MSG_MAP (CMD_TIMESETCFG_REQ, timesetcfgreq)
    MSG_MAP (CMD_SDCFG_REQ, sdcfgreq)

    MSG_MAP (CMD_SDSTATUS_REQ, sdstatusreq)
    MSG_MAP (CMD_CONNECT_INFO_REQ, connect_info_req)
    MSG_MAP (CMD_CAMSTATUS_REQ, camstatusreq)

    MSG_MAP (CMD_LOGLIST_REQ, loglistreq) 
    MSG_MAP (CMD_LOGFILE_REQ, logfilereq)

    MSG_MAP (CMD_SENSORCFG_REQ, sensorcfgreq)
    MSG_MAP (CMD_OPERATECFG_REQ, operatecfgreq)
    MSG_MAP (CMD_WIFICFG_REQ, wificfgreq)
    MSG_MAP (CMD_USERCFG_REQ, usercfgreq)
    MSG_MAP (CMD_AVISTREAM_REQ, avistreamreq)

    MSG_MAP (CMD_DBTDATA, dbtdata)
    MSG_MAP (CMD_SYSTEM_RESET, systemreset)
    MSG_MAP (CMD_HLSCHANNEL_SET, hlssetchannel)


}


