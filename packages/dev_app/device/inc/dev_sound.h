/*
 * dev_sound.h
 *
 * Copyright (C) 2013 UDWORKs.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * sound Hardware library interface definitions.
 */

#ifndef _DEV_SOUND_H_
#define _DEV_SOUND_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <alsa/asoundlib.h>

#define SND_PCM_NAME		"plughw:0,0"

#define SND_VOLUME_P		0 /* playback volume */
#define SND_VOLUME_C		1 /* capture  volume */

#define SND_LINE_IN			0
#define SND_MIC_IN			1

#define SND_SPK1_OUT		0
#define SND_SPK2_OUT		1

#define SND_SW_OFF			0
#define SND_SW_ON			1

#define SND_HEADER_SIZE		0x200//0x2C

#define SND_REC				1
#define SND_PLAY			0

#define SND_PGA_CAPTURE_SWITCH			38 //boolean
#define SND_LINE_PLAY_VOLUME			40

#define SND_RIGHT_LINE1L_MUX			85 //single-ended or differential
#define SND_PGA_RIGHT_LINE1R_SWITCH		86 //not connected
#define SND_PGA_RIGHT_MIC3R_SWITCH		90 //connected to MIC

#define SND_LEFT_LINE1L_MUX				93 //single-ended or differential
#define SND_PGA_LEFT_LINE1L_SWITCH		94 //connected to LINE

#define SND_RIGHT_DAC_MUX				100
#define SND_LEFT_DAC_MUX				102

struct alsa_request_params {
    int freq; 			/* sampling frequency */
    int nchannels;		/* number of channels */

    unsigned int buffer_time; /* time for one buffer */
};

struct alsa_env {
	snd_pcm_t *pcm_t;

	snd_pcm_uframes_t periods;	/* number of periods per buffer */

	int nchannels;				/* number of pcm channels */
	int rate;					/* pcm sampling rate */
	int chunk_bytes;
};

int dev_snd_open(int in, struct alsa_env *env,
					struct alsa_request_params *req);
void dev_snd_close(int in, snd_pcm_t *handle);
ssize_t dev_snd_write(struct alsa_env *env, void *buffer, int size);
ssize_t dev_snd_read(struct alsa_env *env, void *buffer, int size);
int dev_snd_get_volume(int dir, int *volume);
int dev_snd_set_volume(int dir, int volume);
void dev_snd_set_input_path(int input);
void dev_snd_set_output_path(int output);

#ifdef __cplusplus
}
#endif	/* __cplusplus */
#endif //# _DEV_SOUND_H_

