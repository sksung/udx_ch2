/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /*
 * @file        app_fcommand.h
 * @brief
 * @author      hwjun
 * @section     MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_FCOMMAND_H_
#define _APP_FCOMMAND_H_

/*----------------------------------------------------------------------------
 Defines referenced     header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define CMD_DEVICE_REQ                  (0x0000)
#define CMD_DEVICE_RES                  (0x1111)

#define CMD_CONNECT_USER                (0x1000)
#define CMD_CONNECT_USER_RES            (0x1010)
#define CMD_USERKEY_REQ      	        (0x1001)
#define CMD_USERKEY_RES       		(0x1002)
#define CMD_USERAUTH_REQ                (0x1011)
#define CMD_USERAUTH_RES                (0x1012)
#define CMD_USERCONFIRM_REQ             (0x1021)
#define CMD_USERCONFIRM_RES	        (0x1022)
#define CMD_CLIENT_KICKOUT              (0x1101)

#define CMD_PLAYLISTPARAM_REQ 		(0x2001)
#define CMD_PLAYLISTPARAM_RES		(0x2002)
#define CMD_DISPLAYPARAM_REQ		(0x2011)
#define CMD_DISPLAYPARAM_RES		(0x2012)
#define CMD_AUDIOPARAM_REQ		(0x2021)
#define CMD_AUDIOPARAM_RES		(0x2022)
#define CMD_QUALITYPARAM_REQ		(0x2031)
#define CMD_QUALITYPARAM_RES		(0x2032)

#define CMD_CAMBRIGHTPARAM_REQ          (0x2033)
#define CMD_CAMBRIGHTPARAM_RES          (0x2034)

#define CMD_SYSTEMPARAM_REQ		(0x2041)
#define CMD_SYSTEMPARAM_RES		(0x2042)
#define CMD_INFOPARAM_REQ		(0x2051)
#define CMD_INFOPARAM_RES		(0x2052)
#define CMD_TIMESETPARAM_REQ		(0x2061)
#define CMD_TIMESETPARAM_RES		(0x2062)
#define CMD_SDPARAM_REQ	 		(0x2071)
#define CMD_SDPARAM_RES			(0x2072)
#define CMD_SENSORPARAM_REQ		(0x2081)
#define CMD_SENSORPARAM_RES		(0x2082)
#define CMD_OPERATEPARAM_REQ		(0x2091)
#define CMD_OPERATEPARAM_RES		(0x2092)
#define CMD_INDICATORPARAM_REQ		(0x20A1)
#define CMD_INDICATORPARAM_RES		(0x20A2)
#define CMD_USERPARAM_REQ		(0x20B1)
#define CMD_USERPARAM_RES		(0x20B2)
#define CMD_RECDURPARAM_REQ             (0x2100)
#define CMD_RECDURPARAM_RES             (0x2101)

#define CMD_RECDURCFG_REQ               (0x3100)
#define CMD_RECDURCFG_RES               (0x3101)
#define CMD_DISPLAYCFG_REQ		(0x3001)
#define CMD_DISPLAYCFG_RES		(0x3002)
#define CMD_AUDIOCFG_REQ		(0x3011)
#define CMD_AUDIOCFG_RES		(0x3012)
#define CMD_QUALITYCFG_REQ		(0x3021)
#define CMD_QUALITYCFG_RES		(0x3022)

#define CMD_CAMBRIGHTCFG_REQ            (0x3023)
#define CMD_CAMBRIGHTCFG_RES            (0x3024)

#define CMD_SYSTEMCFG_REQ		(0x3031)
#define CMD_SYSTEMCFG_RES		(0x3032)
#define CMD_TIMESETCFG_REQ		(0x3041)
#define CMD_TIMESETCFG_RES		(0x3042)
#define CMD_SDCFG_REQ			(0x3051)
#define CMD_SDCFG_RES			(0x3052)
#define CMD_SDSTATUS_REQ                (0x3053)
#define CMD_SDSTATUS_RES                (0x3054)
#define CMD_CONNECT_INFO_REQ            (0x3055)
#define CMD_CONNECT_INFO_RES            (0x3056)
#define CMD_CAMSTATUS_REQ               (0x3057)
#define CMD_CAMSTATUS_RES               (0x3058)

#define CMD_SENSORCFG_REQ		(0x3061)
#define CMD_SENSORCFG_RES		(0x3062)
#define CMD_OPERATECFG_REQ		(0x3071)
#define CMD_OPERATECFG_RES		(0x3072)
#define CMD_WIFICFG_REQ 		(0x3081)
#define CMD_WIFICFG_RES	        	(0x3082)
#define CMD_USERCFG_REQ			(0x3091)
#define CMD_USERCFG_RES			(0x3092)

#define CMD_AVISTREAM_REQ		(0x4001)
#define CMD_AVISTREAM_DATA		(0x4002)
#define CMD_AVISTREAM_ERROR		(0x4003) 
#define CMD_AVISTREAM_STOP              (0x4004)

#define CMD_LOGLIST_REQ                 (0x4005)
#define CMD_LOGLIST_RES                 (0x4006)

#define CMD_LOGFILE_REQ                 (0x4007)
#define CMD_LOGFILE_RES                 (0x4008)    
#define CMD_LOGFILE_ERR                 (0x4009)


#define CMD_DBTDATA			(0x5001)

#define CMD_SYSTEM_RESET                (0x7001)
#define CMD_INVALID_MSG                 (0x7002)
#define CMD_HLSCHANNEL_SET		(0x7003) 
#define CMD_HLSCHANNEL_RES		(0x7004)

#define CMD_LOCATION_REQ                (0x9001)
#define CMD_LOCATION_RES                (0x9002)

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a     function prototype
-----------------------------------------------------------------------------*/

#endif /*  _APP_FCOMMAND_H_ */
