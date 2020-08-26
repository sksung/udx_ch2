/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
/**
 * @file	app_cap.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 *      - 2013.08.20 Modified by sksung
 */
/*****************************************************************************/

#ifndef _APP_CAP_H_
#define _APP_CAP_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
 -----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
 -----------------------------------------------------------------------------*/
#define MAX_STREAM_NUM		3000//30*15

typedef struct {
	int d_type;
	int ch;
	char *buf;
	int offset;		//# gmem offset
	int b_size;
	int img_w;
	int img_h;
	int is_key;
	int t_sec;
	int t_msec;

	int end;
} stream_info_t;

typedef struct {
	int process;
	int max_num;
	int cur_num;
	int read_num;
	int num_ch;

	stream_info_t ifr[MAX_STREAM_NUM];
} g_mem_info_t;

/*----------------------------------------------------------------------------
 Declares variables
 -----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
 -----------------------------------------------------------------------------*/
int app_capt_start();
void app_capt_stop(void);

void app_aud_capt_ctrl(int enable);

int init_g_mem(void);
void exit_g_mem(void);
void* app_get_gmem(void);
int get_g_mem_phyaddr(void);
int get_g_mem_size(void);
void app_capt_buff_reset(void);
int cap_video_detect(void);

#ifdef FOR_CAM_TEST
//# for cam test
void app_cap_test_idx(int* eq, int* pe);
void app_cap_del_serdes_ini(void);
#endif

#endif	/* _APP_CAP_H_ */
