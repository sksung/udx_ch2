/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_snd.c
 * @brief	application sound thread
 * @device	[in] aic3x
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include "dev_sound.h"

#include "app_comm.h"
#include "app_main.h"
#include "app_dev.h"
#include "app_ctrl.h"
#include "app_rec.h"
#include "app_snd.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define REC_FILE			DIR_REC"/test.wav"
#define PLAY_FILE			DIR_REC"/test.wav"

typedef struct {
	struct alsa_env env;
	unsigned char *si_buf;
	char *pcm_buf;
	int si_size;
} snd_data_t;

typedef struct {
	app_thr_obj cObj;		//# sound in thread
	app_thr_obj pObj;		//# sound out thread
} app_snd_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_snd_t snd_obj;
static app_snd_t *isnd=&snd_obj;

static FILE *fout=NULL;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/
struct wav_header {
	char chunk_id[4];
	unsigned int chunk_size;
	char format[4];
	char subchunk1_id[4];
	unsigned int subchunk1_size;
	unsigned short int audio_format;
	unsigned short int channels;
	unsigned int sample_rate;
	unsigned int byte_range;
	unsigned short int block_align;
	unsigned short int bits_per_sample;
	char subchunk2_id[4];
	unsigned int subchunk2_size;
};

static void wav_init(void)
{
	struct wav_header header;

	if(fout == NULL) {
		return;
	}

	/* init wave header */
	memcpy(header.chunk_id,"RIFF",4);
	header.chunk_size = 0; 					/* Total File size */
	memcpy(header.format, "WAVE",4);
	memcpy(header.subchunk1_id, "fmt ", 4);	/* FMT sub-chunk start */
	header.subchunk1_size = 16;				/* current file pointer */
	header.audio_format = 1;				/* PCM wave format -> 1 wav format */
	header.channels = 1;
	header.sample_rate = SND_PCM_SRATE;
	header.bits_per_sample = 16;
	header.block_align = header.channels * header.bits_per_sample / 8;	/* byte per sample */
	header.byte_range = header.sample_rate * header.block_align;		/* byte per second */
	memcpy(header.subchunk2_id, "data", 4);
	header.subchunk2_size = 0;				/* Data size */

	fwrite(&header, sizeof(struct wav_header), 1, fout);
}

static void wav_close(void)
{
	unsigned int chunk_size;

	chunk_size = ftell(fout) - 8;
	fseek(fout, 4, SEEK_SET);
	fwrite(&chunk_size, sizeof(int), 1, fout);
}

static int wav_get_pcm(void)
{
	int pcm_size;

	fseek(fout, 0, SEEK_END);
	pcm_size = ftell(fout) - sizeof(struct wav_header);
	fseek(fout, sizeof(struct wav_header), SEEK_SET);

	return pcm_size;
}

static void file_open(char *filename, int write)
{
	if(write) {
		fout = fopen(filename, "wb");
	} else {
		fout = fopen(filename, "rb");
	}
	if(fout == NULL) {
		eprintf("file open!\n");
		return;
	}
	dprintf("file open : %s\n", filename);

	wav_init();
}

static void file_close(void)
{
	if(fout != NULL) {
		wav_close();
		fclose(fout);
	}
}

static void file_write(void *addr, int size)
{
	if(fout == NULL) {
		return;
	}

	fwrite(addr, 1, size, fout);
}

static int file_read(void *addr, int size)
{
	if(fout == NULL) {
		return 0;
	}

	return fread(addr, 1, size, fout);
}

/*----------------------------------------------------------------------------
 snd input average
-----------------------------------------------------------------------------*/
static int snd_average(short *pcm, int size, int offset)
{
	int av, i, sum=0;

	size /= 2;
	for (i=0; i<size; i++) {
		sum += abs(*pcm++ - offset);
	}

	av = (sum / size);
	dprintf("av %d\n", av);

	return av;
}

/*****************************************************************************
* @brief    sound capture thread function
* @section  [desc]
*****************************************************************************/
static void *THR_snd_cap(void *prm)
{
	app_thr_obj *tObj = &isnd->cObj;
	int exit=0;

	static snd_data_t snd_in_data;
	struct alsa_env *env = &snd_in_data.env;
	struct alsa_request_params params;
	int ret;

	aprintf("enter...\n");
	tObj->active = 1;

	memset(&params, 0, sizeof(struct alsa_request_params));

	dev_snd_set_input_path(SND_MIC_IN);
	dev_snd_set_volume(SND_VOLUME_C, 60);

	params.freq = 16000;
	params.nchannels = 1;
	params.buffer_time = 125 * 1000; /* miscrosecond unit */

	ret = dev_snd_open(SND_REC, env, &params);
	if(ret < 0) {
		eprintf("snd capture device init\n");
		return NULL;
	}

	snd_in_data.si_size = env->chunk_bytes;
	snd_in_data.si_buf = malloc(snd_in_data.si_size);
	if(snd_in_data.si_buf==NULL) {
		eprintf("snd buffer malloc\n");
		return NULL;
	}

	file_open(REC_FILE, 1);

	while(!exit)
	{
		if(tObj->cmd == APP_CMD_EXIT) {
			break;
		}

		ret = dev_snd_read(env, snd_in_data.si_buf, snd_in_data.si_size);;
		if(ret > 0) {
			//snd_average((short *)snd_in_data.si_buf, ret, 370);
			file_write(snd_in_data.si_buf, ret);
		}
	}

	file_close();
	free(snd_in_data.si_buf);

	dev_snd_close(SND_REC, env->pcm_t);

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    snd thread start/stop function
* @section  [desc]
*****************************************************************************/
int snd_cap_start(void)
{
	app_thr_obj *tObj;

	memset(isnd, 0, sizeof(app_snd_t));

	//#--- create sound play thread
	tObj = &isnd->cObj;
	if(thread_create(tObj, THR_snd_cap, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return -1;
	}

	return 0;
}

void snd_cap_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop thread
	tObj = &isnd->cObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);

	dprintf("...done!\n");
}

/*****************************************************************************
* @brief    sound demo function
* @section  [desc]
*****************************************************************************/
const char menu_snd[] = {
	"\r\n -------------"
	"\r\n Sound Menu"
	"\r\n -------------"
	"\r\n 0: exit"
	"\r\n%s1: snd rec"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_snd(void)
{
	int done = 0;
	char cmd = 0;
	int ste_cap=0;

	while (!done)
	{
		printf(menu_snd, ste_cap?"*":" ");
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
			{
				ste_cap = 1 - ste_cap;
				if(ste_cap) {
					snd_cap_start();
				} else {
					snd_cap_stop();
				}
				break;
			}
		}
	}

	if(ste_cap) {
		snd_cap_stop();
	}

	return 0;
}
