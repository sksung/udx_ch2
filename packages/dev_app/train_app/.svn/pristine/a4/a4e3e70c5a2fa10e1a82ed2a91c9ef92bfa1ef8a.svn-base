/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_sound.c
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

#include "dev_sound.h"

#include "ucx_main.h"
#include "app_snd.h"
#include "app_set.h"
#include "app_util.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

typedef struct {
	app_thr_obj *sObj;		//# sound out thread

	struct alsa_env env_in;
	struct alsa_env env_out;

	unsigned char *so_buf;	//# use remain data less than chunk_byte
	int so_size;
	int so_init;

	unsigned char *si_buf;
	int si_size;
} app_snd_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_snd_t t_snd;
static app_snd_t *isnd=&t_snd;
/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 sound out device
-----------------------------------------------------------------------------*/
static int snd_out_init(int ch, int freq)
{
	int ret;
	struct alsa_env *env = &isnd->env_out;
	struct alsa_request_params params;

	if(isnd->so_init) {
		dprintf("sound out device init already\n");
		return SOK;
	}

	isnd->so_init = 1;

	//# sound out device init
	memset(&params, 0, sizeof(struct alsa_request_params));
	params.freq = freq;
	params.nchannels = ch;
	/* 1s->16000, 250ms->4000 samples */
	/* if stereo sound, 1 frame = 2 samples = 4bytes (Left/Right) */
	/* if mono sound, 1 frame = 1 samples = 2bytes */
	params.buffer_time = 250000;	/* 250ms -> miscrosecond unit */

	ret = dev_snd_open(SND_PLAY, env, &params);
	if (ret < 0) {
		eprintf("sound out device open fail\n");
		isnd->so_init = 0;
		return EFAIL;
	}

	isnd->so_size = env->chunk_bytes;
	isnd->so_buf = app_malloc(isnd->so_size);
	if(isnd->so_buf == NULL)
		return EMEM;

	return SOK;
}

static void snd_out_exit(void)
{
	struct alsa_env *env = &isnd->env_out;

	OSA_waitMsecs(100);		//# ???

	if(isnd->so_buf != NULL)
		app_mfree(isnd->so_buf);

	dev_snd_close(SND_PLAY, env->pcm_t);

	isnd->so_init = 0;
}

static int snd_out_write(unsigned char *buf, int data_size)
{
	struct alsa_env *env = &isnd->env_out;
	int chunk_byte = isnd->so_size, w_size;
	int ret;

	while(data_size > 0)
	{
		if(data_size < chunk_byte) {
			w_size = data_size;
			app_memcpy(isnd->so_buf, buf, w_size);
			buf = (unsigned char *)isnd->so_buf;
		}
		else {
			w_size = chunk_byte;
		}

		ret = dev_snd_write(env, buf, w_size);
		if(ret < 0)
			return EFAIL;

		buf += w_size;
		data_size -= w_size;
	}

	return SOK;
}

/*----------------------------------------------------------------------------
 sound in device
-----------------------------------------------------------------------------*/
static int snd_in_init(int ch, int samplerate, int ms)
{
	struct alsa_env *env = &isnd->env_in;
	struct alsa_request_params params;
	int ret = 0;

	//# audio in device.
	memset(&params, 0, sizeof(struct alsa_request_params));
	params.freq = samplerate;
	params.nchannels = ch;
	params.buffer_time = ms * 1000; /* miscrosecond unit */

	ret = dev_snd_open(SND_REC, env, &params);
	if (ret < 0) {
		eprintf("cannot open audio device\n");
		return EFAIL;
	}

	dev_snd_set_volume(SND_VOLUME_C, 50);	//# set default volume 80%

	isnd->si_size = env->chunk_bytes;
	isnd->si_buf = app_malloc(isnd->si_size);
	if(isnd->si_buf == NULL)
		return EMEM;

	return SOK;
}

static void snd_in_exit(void)
{
	struct alsa_env *env = &isnd->env_in;

	if(isnd->si_buf != NULL)
		app_mfree(isnd->si_buf);

	dev_snd_close(SND_REC, env->pcm_t);
}

static int snd_in_read(void)
{
	struct alsa_env *env = &isnd->env_in;
	int read_sz;

	read_sz = dev_snd_read(env, isnd->si_buf, isnd->si_size);
	if(read_sz != isnd->si_size) {
		eprintf("sound read\n");
		return EFAIL;
	}

	return SOK;
}

/*----------------------------------------------------------------------------
 sound out task
-----------------------------------------------------------------------------*/

static void *sound_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int cmd, exit=0;
	snd_info_t *iwav;
	int ret;

	printf(" [task] %s start\n", __func__);
	tObj->done = 0;

	while(!exit)
	{
		//# wait cmd
		cmd = event_wait(tObj);
		if(cmd == UBX_CMD_STOP) {
			break;
		}

		iwav = get_snd_db(tObj->param0);
		if(iwav == NULL){
			eprintf(" Not exist sound data!!\n");
			continue;
		}
		ret = snd_out_init(iwav->ch, iwav->sr);
		if(ret < 0){
			eprintf("Failed snd_out_init()!!\n");
			break;
		}

		ret = snd_out_write(iwav->p, iwav->sz);
		if(ret < 0){
			eprintf("Failed snd_out_write()!!\n");
			break;
		}

		snd_out_exit();
	}

	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    buzzer out On/Off
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_snd_enable_live(int enable)
{
	if(app_set->aud.snd_on != enable)
	{
		if(enable == ON){
			app_set->aud.snd_on = ON;
		}
		else{
			app_set->aud.snd_on = OFF;
		}
	}

	return 0;
}

/*****************************************************************************
* @brief    audio codec function
* @section  DESC Description
*   - desc
*****************************************************************************/
static int alg_ulaw_encode(unsigned short *dst, unsigned short *src, Int32 bufsize)
{
    int i, isNegative;
    short data;
    short nOut;
    short lowByte = 1;
    int outputSize = bufsize / 2;

    for (i=0; i<outputSize; i++)
    {
        data = *(src + i);
        data >>= 2;
        isNegative = (data < 0 ? 1 : 0);

        if (isNegative)
            data = -data;

        if (data <= 1) 			nOut = (char) data;
        else if (data <= 31) 	nOut = ((data - 1) >> 1) + 1;
        else if (data <= 95)	nOut = ((data - 31) >> 2) + 16;
        else if (data <= 223)	nOut = ((data - 95) >> 3) + 32;
        else if (data <= 479)	nOut = ((data - 223) >> 4) + 48;
        else if (data <= 991)	nOut = ((data - 479) >> 5) + 64;
        else if (data <= 2015)	nOut = ((data - 991) >> 6) + 80;
        else if (data <= 4063)	nOut = ((data - 2015) >> 7) + 96;
        else if (data <= 7903)	nOut = ((data - 4063) >> 8) + 112;
        else 					nOut = 127;

        if (isNegative) {
            nOut = 127 - nOut;
        } else {
            nOut = 255 - nOut;
        }

        // Pack the bytes in a word
        if (lowByte)
            *(dst + (i >> 1)) = (nOut & 0x00FF);
        else
            *(dst + (i >> 1)) |= ((nOut << 8) & 0xFF00);

        lowByte ^= 0x1;
    }

	return (outputSize);
}

static int alg_ulaw_decode(unsigned char *dst, unsigned char *src, Int32 bufsize)
{
    int i, isNegative;
    unsigned char input;
    unsigned short nOut;

    for (i=0; i<bufsize; i++)
    {
	    input = *src++;
		isNegative = ((input & 0x80) == 0);
		if (isNegative)
		  nOut = 127 - input;
		else
		  nOut = 255 - input;

		if (nOut < 2)			nOut *= 2;
		else if (nOut < 16)		nOut= ((nOut - 1) << 1) +1 + 1;
		else if (nOut < 32)		nOut= ((nOut - 16) << 2) +2 + 31;
		else if (nOut < 48)		nOut= ((nOut - 32) << 3) +4 + 95;
		else if (nOut < 64)		nOut= ((nOut - 48) << 4) +8 + 223;
		else if (nOut < 80)		nOut= ((nOut - 64) << 5) +16 + 479;
		else if (nOut < 96)		nOut= ((nOut - 80) << 6) +32 + 991;
		else if (nOut < 112)	nOut= ((nOut - 96) << 7) +64 + 2015;
		else					nOut= ((nOut - 112) << 8) +128 + 4063;

		if (isNegative)
		  nOut= - nOut;
		nOut <<= 2;

		*dst++ = (nOut & 0xff);
		*dst++ = (nOut >> 8);
	}

	return bufsize;
}

/*****************************************************************************
* @brief    audio capture/play function
* @section  DESC Description
*   - desc
*****************************************************************************/
/*----------------------------------------------------------------------------
 audio capture function
-----------------------------------------------------------------------------*/
int app_aud_capt_init(int buf_time)
{
	int ret;

	ret = snd_in_init(1, AUD_SAMPLE_LATE, buf_time);
	if(ret < 0)
		return ret;

	return isnd->si_size/2;		//# encoder bufsize 1/2 when G711
}

int app_aud_capt_exit(void)
{
	snd_in_exit();

	return SOK;
}

int app_aud_capt(unsigned char *buf)
{
	int ret, buf_size = 0;

	ret = snd_in_read();
	if(ret < 0)
		return ret;

	//# AUD_CODEC_G711
	buf_size = alg_ulaw_encode((unsigned short *)buf, (unsigned short *)isnd->si_buf, isnd->si_size);

	return buf_size;			//# encoding data size
}

/*****************************************************************************
* @brief    sound out thread init/exit function
* @section  DESC Description
*   - desc
*****************************************************************************/
void app_snd_init(void)
{
	app_thr_obj *tObj;

	isnd->so_init = 0;

	//# set default device
	dev_snd_set_input_path(SND_MIC_IN);	//# SND_LINE_IN/SND_MIC_IN
}

void app_snd_exit(void)
{
	dprintf("...done\n");
}


