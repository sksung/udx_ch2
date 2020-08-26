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
//#define FREC_TEST

#define FILE_NAME_MAX			(50)

/*------------------------------------------------
 String Index
 ------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
 -----------------------------------------------------------------------------*/
typedef enum {
	REC_DRIVE=0,
	REC_EVENT,
	REC_PARKING,
	REC_MAX
}rec_type_e;

typedef struct {
	char fname[FILE_NAME_MAX];		//# avi file name
	unsigned long 	fsize;			//# avi file size
	unsigned int 	del;			//# 1: delete done, 0: file exist
}frec_info_t;

/*----------------------------------------------------------------------------
 Declares a	function prototype
 -----------------------------------------------------------------------------*/
int app_file_start(void);
void app_file_stop(void);

int app_get_dir_name(char* rec_path);
int	app_file_update(char* file_name, int close);

int app_file_get_list( frec_info_t** flist, int descending );
void app_file_free_list(frec_info_t** flist);
char* app_file_get_dir_path(char* fname, int descending);

#endif	/* _APP_FILE_H_ */


