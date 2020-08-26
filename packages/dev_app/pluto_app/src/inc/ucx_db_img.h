/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    img_db.h
 * @brief
 * @author  phoong
 * @section MODIFY history
 */
/*****************************************************************************/
#if !defined (_IMG_DB_H_)
#define _IMG_DB_H_

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

typedef enum {
	IMG_FW_DONE,
	IMG_FW_UPDATE,
	IMG_UDLOGO_TV,

	IMG_DB_MAX
} img_db_e;

typedef struct {
	unsigned short *p;
	int w;
	int h;
} img_info_t;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

img_info_t *get_img_db(int img_idx);

#endif	//_IMG_DB_H_
