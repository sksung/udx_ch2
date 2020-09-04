/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
  * @file	 app_file.c
  * @brief	 recorded file management with linked-list
  * @author  sksung
  * @section MODIFY history
  * 	- 2014.09.24 : First Created
  */
 /*****************************************************************************/


#ifndef _APP_FILE_H_
#define _APP_FILE_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
 -----------------------------------------------------------------------------*/
#include "ucx_main.h"
/*----------------------------------------------------------------------------
 Definitions and macro
 -----------------------------------------------------------------------------*/
#define FILE_NAME_MAX	(40)

#define FILE_PREFIX		"2HD_"

/*------------------------------------------------
 String Index
 ------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
 -----------------------------------------------------------------------------*/
typedef enum {
	REC_DRIVE=0,
//	REC_EVENT,
 	REC_MAX
}rec_type_e;

typedef struct {
	unsigned int size;
	char fname[FILE_NAME_MAX];
}file_info_t;


/*----------------------------------------------------------------------------
 Declares a	function prototype
 -----------------------------------------------------------------------------*/
int app_file_start(void);
void app_file_stop(void);

int app_file_add(int rec_type, char* file_name);


/*****************************************************************************
 @brief		Get file list for playback
 @param		[IN]rec_type  rec_type_e 
 @param		[IN]descending  0: oldest file first, 1: latest file first
 @param		[OUT]flist    	recorded file list file_info_t structure
 @return	file counts	   
 @remark
 *****************************************************************************/
int app_file_get_list(int rec_type, file_info_t** flist, int descending);
void app_file_free_list(file_info_t** flist);
char* app_file_get_rectype_path(int rec_type);


#endif	/* _APP_FILE_H_ */


