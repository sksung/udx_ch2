/*
 * File : dev_sound.c
 *
 * Copyright (C) 2013 UDWORKs
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
 * this implements a sound hardware library for UBX.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>

#include "dev_common.h"
#include "dev_sound.h"

#define check_range(val, min, max) \
	((val < min) ? (min) : (val > max) ? (max) : (val))

#define convert_prange1(val, min, max) \
	ceil((val) * ((max) - (min)) * 0.01 + (min))

struct volume_ops {
	int (*get_range)(snd_mixer_elem_t *elem, long *min, long *max);
	int (*get)(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t c,
		   long *value);
	int (*set)(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t c,
		   long value, int dir);
};

struct alsa_volume_ops {
	char *vname; /* control name */
	int (*has_volume)(snd_mixer_elem_t *elem);
	int (*get_range)(snd_mixer_elem_t *elem, long *min, long *max);
	int (*get)(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t c,
		   long *value);
	int (*set)(snd_mixer_elem_t *elem, snd_mixer_selem_channel_id_t c,
		   long value);
};

/* capture, playback volume */
static const struct alsa_volume_ops vol_ops[2] = {
	{
		.vname		= "PCM",
		.has_volume = snd_mixer_selem_has_playback_volume,
		.get_range  = snd_mixer_selem_get_playback_volume_range,
		.get	    = snd_mixer_selem_get_playback_volume,
		.set 	    = snd_mixer_selem_set_playback_volume,
	},
	{
		.vname		= "PGA",
		.has_volume = snd_mixer_selem_has_capture_volume,
		.get_range  = snd_mixer_selem_get_capture_volume_range,
		.get        = snd_mixer_selem_get_capture_volume,
		.set        = snd_mixer_selem_set_capture_volume,
	},
};

/* Fuction to convert from volume to percentage. val = volume */
static int convert_prange(int val, int min, int max)
{
	int range = max - min;
	int tmp;

	if (range == 0)
		return 0;

	val -= min;
	tmp = rint((double)val/(double)range * 100);

	return tmp;
}

static inline void *advance(void *p, int incr)
{
    unsigned char *d = p;
    return (d + incr);
}

/* alsa-mixer cset implementation */
static int alsa_mixer_cset(int numid, int value)
{
	int err;

	snd_ctl_t *handle = NULL;
	snd_ctl_elem_info_t *info;
	snd_ctl_elem_id_t *id;
	snd_ctl_elem_value_t *control;

	unsigned int idx, count;
	long tmp, val;
	long min, max;

	snd_ctl_elem_type_t type;

	if (numid <= 0) {
		dev_err("Invalid numid %d\n", numid);
		return -1;
	}

	snd_ctl_elem_info_alloca(&info);
	snd_ctl_elem_id_alloca(&id);
	snd_ctl_elem_value_alloca(&control);

	/* default */
	snd_ctl_elem_id_set_interface(id, SND_CTL_ELEM_IFACE_MIXER);
	snd_ctl_elem_id_set_numid(id, numid);

	if ((err = snd_ctl_open(&handle, "default", 0)) < 0) {
		dev_err("Control open mixer handle\n");
		return err;
	}

	snd_ctl_elem_info_set_id(info, id);
	if ((err = snd_ctl_elem_info(handle, info)) < 0) {
		dev_err("Cannot find the given element from control\n");
		snd_ctl_close(handle);
		return err;
	}

	snd_ctl_elem_info_get_id(info, id);	/* FIXME: Remove it when hctl find works ok !!! */
	type = snd_ctl_elem_info_get_type(info);
	count = snd_ctl_elem_info_get_count(info);
	snd_ctl_elem_value_set_id(control, id);

	//# count = 2 channels (left and right)
	for (idx = 0; idx < count && idx < 128; idx++) {
		switch (type) {
		case SND_CTL_ELEM_TYPE_BOOLEAN:
			tmp = value ? 1:0;
			snd_ctl_elem_value_set_boolean(control, idx, tmp);
			break;
		case SND_CTL_ELEM_TYPE_INTEGER:
			min = snd_ctl_elem_info_get_min(info);
			max = snd_ctl_elem_info_get_max(info);

			val = (long)convert_prange1(value, min, max);
			tmp = check_range(val, min, max);
			snd_ctl_elem_value_set_integer(control, idx, tmp);
			break;
		case SND_CTL_ELEM_TYPE_ENUMERATED:
			min = 0;
			max = snd_ctl_elem_info_get_items(info) - 1;

			tmp = check_range(value, min, max);
			snd_ctl_elem_value_set_enumerated(control, idx, tmp);
			break;
		default:
			break;
		}
	}

	if ((err = snd_ctl_elem_write(handle, control)) < 0) {
		dev_err("Control element write error\n");
		snd_ctl_close(handle);
		return err;
	}

	snd_ctl_close(handle);
	return 0;
}

static int alsa_recover (snd_pcm_t *handle)
{
	int err = 0;

    err = snd_pcm_prepare(handle);
    if (err < 0) {
        dev_err("Failed to prepare handle %p\n", handle);
        return -1;
    }

    return 0;
}

static int alsa_resume(snd_pcm_t *handle)
{
	int ret = 0;

	ret = snd_pcm_resume(handle);
	if (ret < 0) {
		dev_err("Failed. Restarting stream.\n");
        return -1;
	}

	return ret;
}

#if 0
static snd_pcm_sframes_t alsa_get_avail(snd_pcm_t *handle)
{
    snd_pcm_sframes_t avail;

    avail = snd_pcm_avail_update(handle);
    if (avail < 0) {
        if (avail == -EPIPE) {
            if (!alsa_recover(handle)) {
                avail = snd_pcm_avail_update(handle);
            }
        }

        if (avail < 0) {
            dev_err("Could not obtain number of available frames\n");
            return -1;
        }
    }

    return avail;
}
#endif

static void alsa_set_swparams(snd_pcm_t *handle, snd_pcm_uframes_t period,
					snd_pcm_uframes_t start, snd_pcm_uframes_t stop)
{
	snd_pcm_sw_params_t *sw_params;
    int err = 0;

	/* allocated stack */
    snd_pcm_sw_params_alloca(&sw_params);
    err = snd_pcm_sw_params_current(handle, sw_params);
    if (err < 0) {
        dev_err("Failed to get current software parameters\n");
        return;
    }

    snd_pcm_sw_params_set_avail_min(handle, sw_params, period);
    err = snd_pcm_sw_params_set_start_threshold(handle, sw_params, start);
    if (err < 0) {
        dev_err("Failed to set software start threshold to %ld\n", start);
        return;
    }

    err = snd_pcm_sw_params_set_stop_threshold(handle, sw_params, stop);
    if (err < 0) {
        dev_err("Failed to set software stop threshold to %ld\n", stop);
        return;
    }

    err = snd_pcm_sw_params(handle, sw_params);
    if (err < 0) {
        dev_err("Failed to set software parameters\n");
        return;
    }
}

/****************************************************
 * NAME : int dev_snd_open(int in, struct alsa_env *env,
 *					struct alsa_request_params *req)
 *
 * Desc   : Open the alsa sound Hadrdware
 *
 * INPUT  :
 *   PARAMETERS:
 *        int in  : select capture or playback
 *              SND_PLAY   playback
 *              SND_REC    capture (record)
 *
 *        struct alsa_env *env : handle of sound device.
 *
 *        struct alsa_request_params *req : parameters for sound device.
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:
 *            0       succeed
 *            -1      failure
 ****************************************************/
int dev_snd_open(int in, struct alsa_env *env,
					struct alsa_request_params *req)
{
	int err;

	unsigned int freq, nchannels;
	unsigned int period_time, buffer_time;

	snd_pcm_uframes_t buffer_size, period_size;

	/* Name of the PCM device, like plughw:0,0          */
    /* The first number is the number of the soundcard, */
    /* the second number is the number of the device.   */
	char *pcm_name = SND_PCM_NAME;

	/* Handle for the PCM device */
	snd_pcm_t *handle;

	/* This structure contains information about    */
    /* the hardware and can be used to specify the  */
    /* configuration to be used for the PCM stream. */
	snd_pcm_hw_params_t *hw_params;

	freq = req->freq;
	nchannels = req->nchannels;

	/* Open PCM. The last parameter of this function is the mode. */
    /* If this is set to 0, the standard mode is used. */
	err = snd_pcm_open(&handle,
					   pcm_name,
					   in ? SND_PCM_STREAM_CAPTURE : SND_PCM_STREAM_PLAYBACK,
					   0);
	if (err < 0) {
		dev_err("Failed to open `%s':\n", pcm_name);
		return -1;
	}

	snd_pcm_hw_params_alloca(&hw_params);
	/* Init hwparams with full configuration space */
	err = snd_pcm_hw_params_any(handle, hw_params);
	if (err < 0) {
		dev_err("Failed to initialize hardware parameters\n");
		goto err;
	}

	/* Restrict a configuration space to contain only real hardware rates */
	//snd_pcm_hw_params_set_rate_resample(handle, hw_params, 1);
	/* Set access type.*/
	err = snd_pcm_hw_params_set_access(handle, hw_params,
							SND_PCM_ACCESS_RW_INTERLEAVED);
	if (err < 0) {
		dev_err("Failed to set access type\n");
		goto err;
	}
	/* Set sample format */
	err = snd_pcm_hw_params_set_format (handle, hw_params,
							SND_PCM_FORMAT_S16_LE);
	if (err < 0) {
		dev_err("cannot set sample format!\n");
		goto err;
	}
	/* Set sample rate. If the exact rate is not supported */
	/* by the hardware, use nearest possible rate.         */
	err = snd_pcm_hw_params_set_rate_near(handle, hw_params, &freq, 0);
	if (err < 0) {
		dev_err("Failed to set frequency %d\n", req->freq);
		goto err;
	}

	/* Set number of channels */
	err = snd_pcm_hw_params_set_channels_near(handle, hw_params, &nchannels);
	if (err < 0) {
		dev_err("Failed to set number of channels %d\n", req->nchannels);
		goto err;
	}
	if (nchannels != 1 && nchannels != 2) {
        dev_err ("Unsupported channels %d\n", nchannels);
        goto err;
    }

	if (req->buffer_time) {
		/* Set buffer size (in frames). The resulting latency is given by */
    	/* latency = periodsize * periods / (rate * bytes_per_frame)     */
    	/* ex) 16-bit stereo = one frame has a length of four bytes */
		buffer_time = req->buffer_time;

        /* Set number of periods. Periods used to be called fragments. */
        /* buffer size = 2 * periods or 8 * periods (platform specific) */
		/* davinci Buffer size =  8 * periods */
		period_time = (buffer_time / 4);
    } else {
    	snd_pcm_hw_params_get_buffer_time_max(hw_params, &buffer_time, 0);
		if (buffer_time > 500000)
			buffer_time = 500000; /* in microsecond */

		period_time = buffer_time / 4;
    }

    err = snd_pcm_hw_params_set_period_time_near(handle,
        					hw_params, &period_time, 0);
    if (err < 0) {
        dev_err("Failed to set period time to %d\n", period_time);
        goto err;
    }

    err = snd_pcm_hw_params_set_buffer_time_near(handle,
        				hw_params, &buffer_time, 0);
    if (err < 0) {
        dev_err("Failed to set buffer time to %d\n", req->buffer_time);
        goto err;
    }

	/* Apply HW parameter settings to */
    /* PCM device and prepare device  */
    err = snd_pcm_hw_params(handle, hw_params);
	if (err < 0) {
		dev_err("Unable to install hw params\n");
		goto err;
	}

	/* prepare for audio device */
	err = snd_pcm_prepare(handle);
    if (err < 0) {
        dev_err("Could not prepare handle %p\n", handle);
        goto err;
    }

    snd_pcm_hw_params_get_period_size(hw_params, &period_size, 0);
	snd_pcm_hw_params_get_buffer_size(hw_params, &buffer_size);

    if (!in) {
        /* pcm playback */
        alsa_set_swparams(handle, period_size, buffer_size, buffer_size);
    } else {
    	/* pcm capture */
    	alsa_set_swparams(handle, period_size, 1, buffer_size);
	}

    env->nchannels = nchannels;
    env->rate 	   = freq;
    env->periods   = period_size;
    env->pcm_t     = handle;
    if (!in)
    	env->chunk_bytes = period_size << ((nchannels == 2) ? 2 : 1);
    else
    	env->chunk_bytes = buffer_size << ((nchannels == 2) ? 2 : 1);

	return 0;
err:
	dev_snd_close(in, handle);

	return -1;
}

/****************************************************
 * NAME : void dev_snd_close(int in, snd_pcm_t *handle)
 *
 * Desc   : close the alsa sound Hadrdware
 *
 * INPUT  :
 *   PARAMETERS:
 *        int in  : select capture or playback
 *              SND_PLAY   playback
 *              SND_REC    capture (record)
 *
 *        snd_pcm_t *handle : pcm handle for alsa device.
 *
 * OUTPUT :
 *   RETURN : none.
 ****************************************************/
void dev_snd_close(int in, snd_pcm_t *handle)
{
	if (handle) {
		if (!in) {
			snd_pcm_nonblock(handle, 0);
			/* Stop PCM device and drop pending frames */
    		//snd_pcm_drop(pcm_handle);

			/* Stop PCM device after pending frames have been played */
			snd_pcm_drain(handle);
			//snd_pcm_nonblock(handle, 1);
		}
		snd_pcm_hw_free(handle);
		snd_pcm_close(handle);
	}
}

/****************************************************
 * NAME : ssize_t dev_snd_write(struct alsa_env *env,
 *						void *buffer, size_t count)
 *
 * Desc : write pcm sample to alsa device from user buffer.
 *
 * INPUT :
 *   PARAMETERS:
 *        struct alsa_env *env  : handle
 *
 *        void *buffer : buffer for pcm write.
 *
 *        size_t count : the number of pcm samples
 *
 * OUTPUT :
 *   RETURN : the number of samples written.
 *       Type  : int
 *       Values:
 *            0        On error, returned zero.
 *            nonzero  success
 *
 ****************************************************/
ssize_t dev_snd_write(struct alsa_env *env, void *buffer, int size)
{
	snd_pcm_format_t format = SND_PCM_FORMAT_S16_LE;
	snd_pcm_t *handle = (snd_pcm_t *)env->pcm_t;
	unsigned char *data = (unsigned char *)buffer;

	size_t count;

	ssize_t hwshift;
	ssize_t result = 0;

	hwshift = (env->nchannels == 2) ? 2:1;
	/*
	 * size -> the number of bytes for play
	 * count -> the number of samples (1ch ->16bit, 2ch->32bit)
	 */
	count = size >> hwshift;

	if (count < env->periods) {
    	snd_pcm_format_set_silence(format, data + (count << hwshift),
						(env->periods - count) * env->nchannels);
        count = env->periods;
	}

	while (count > 0)
	{
		snd_pcm_sframes_t r;

		r = snd_pcm_writei(handle, data, count);
		if (r == -EAGAIN || (r >= 0 && (size_t)r < count)) {
			//dev_err("pcm write wait(100ms)!!\n");
			snd_pcm_wait(handle, 100);
		} else if (r == -EPIPE) {
			//dev_err("pcm write underrun!!\n");
			if (alsa_recover(handle)) {
				dev_err("Failed to write %d frames\n", count);
				return -1;
			}
			continue;
		} else if (r == -ESTRPIPE) {
			if (alsa_resume(handle)) {
                dev_err("Failed to write %d frames\n", count);
                return -1;
            }
			continue;
		} else if (r < 0) {
			dev_err("write error\n");
			return -1;
		}

		if (r > 0) {
			data = advance(data, r << hwshift);
			result += r;
			count -= r;
		}
	}

	return (result << hwshift);
}

/****************************************************
 * NAME : ssize_t dev_snd_read(struct alsa_env *env,
 *				void *buffer, size_t count)
 *
 * Desc : read from the alsa device.
 *
 * INPUT :
 *   PARAMETERS:
 *        struct alsa_env *env  : handle
 *
 *        void *buffer : buffer for pcm read.
 *
 *        size_t count : the number of pcm samples
 *
 * OUTPUT :
 *   RETURN : the number of samples written.
 *       Type  : int
 *       Values:
 *            0       : On error, returned zero.
 *            nonzero : success
 *
 ****************************************************/
ssize_t dev_snd_read(struct alsa_env *env, void *buffer, int size)
{
	snd_pcm_t *handle = (snd_pcm_t *)env->pcm_t;
	unsigned char *data = (unsigned char *)buffer;

	size_t count;
	ssize_t result = 0, hwshift;

	hwshift = (env->nchannels == 2) ? 2: 1;
	count = size >> hwshift;

	while (count > 0)
	{
		snd_pcm_sframes_t nread;
		nread = snd_pcm_readi(handle, data, count);
		if (nread <= 0)
		{
			switch (nread) {
			case 0:
				dev_err("Failed to read %d frames (read zero)\n", count);
				return -1;

			case -EAGAIN:
				snd_pcm_wait(handle, 100);
				//dev_err("pcm wait (count = %d)!!\n", count);
				break;

			case -EPIPE:
				//dev_err("pcm overrun(count = %d)!!\n", count);
				if (alsa_recover(handle)) {
					dev_err("Failed to read %d frames\n", count);
					return -1;
				}
				break;

			default:
				dev_err("read error\n");
				return -1;
			}
		}

		if (nread > 0) {
			data = advance(data, nread << hwshift);
			result += nread;
			count -= nread;
		}
	}

	return (result << hwshift);
}

/****************************************************
 * NAME : int dev_snd_get_volume(int dir, int *volume)
 *
 * Desc : Get configured sound volume
 *
 * INPUT :
 *   PARAMETERS:
 *        int dir : capture or playback
 *
 *        int *volume : buffer for volume
 *
 * OUTPUT :
 *   RETURN : Error Code.
 *       Type  : int
 *       Values:
 *            0  : success
 *            -1 : failure
 *
 ****************************************************/
int dev_snd_get_volume(int dir, int *volume)
{
	long orig, pmin, pmax;

    snd_mixer_selem_id_t *sid;
    snd_mixer_elem_t* elem;
    snd_mixer_t *handle = NULL;

    snd_mixer_selem_id_alloca(&sid);

    /* set sset, index = 0(fixed) */
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, vol_ops[dir].vname);

    /* mixer open */
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, "default");

    /* mixer basic mode (abstraction mode-> need to mixer option */
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    elem = snd_mixer_find_selem(handle, sid);
	if (!elem) {
		dev_err("Unable to find simple control '%s',%i\n", snd_mixer_selem_id_get_name(sid),
										snd_mixer_selem_id_get_index(sid));
		snd_mixer_close(handle);
		handle = NULL;
		return -1;
	}

	if (!vol_ops[dir].has_volume(elem)) {
		snd_mixer_close(handle);
		return -1;
	}

	vol_ops[dir].get_range(elem, &pmin, &pmax);
	vol_ops[dir].get(elem, 0, &orig);

	/* convert persentage */
	*volume = convert_prange(orig, pmin, pmax);
    snd_mixer_close(handle);

    return 0;
}

/****************************************************
 * NAME : int dev_snd_set_volume(int dir, int volume)
 *
 * Desc : set volume to sound device.
 *
 * INPUT :
 *   PARAMETERS:
 *        int dir : capture or playback
 *
 *        int volume : volume (in percentage, 0~100%)
 *
 * OUTPUT :
 *   RETURN : Error Code.
 *       Type  : int
 *       Values:
 *            0  : success
 *            -1 : failure
 *
 ****************************************************/
int dev_snd_set_volume(int dir, int volume)
{
	long val, pmin, pmax;

    snd_mixer_selem_id_t *sid;
    snd_mixer_elem_t* elem;
    snd_mixer_t *handle = NULL;

    snd_mixer_selem_id_alloca(&sid);

    /* set sset, index = 0(fixed) */
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, vol_ops[dir].vname);

    /* mixer open */
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, "default");

    /* mixer basic mode (abstraction mode-> need to mixer option */
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    elem = snd_mixer_find_selem(handle, sid);
	if (!elem) {
		dev_err("Unable to find simple control '%s',%i\n", snd_mixer_selem_id_get_name(sid),
															snd_mixer_selem_id_get_index(sid));
		snd_mixer_close(handle);
		handle = NULL;
		return -1;
	}

	if (!vol_ops[dir].has_volume(elem)) {
		snd_mixer_close(handle);
		return -1;
	}

	/* get range */
	vol_ops[dir].get_range(elem, &pmin, &pmax);
	val = (long)convert_prange1(volume, pmin, pmax);
	val = check_range(val, pmin, pmax);

	vol_ops[dir].set(elem, 0, val);
	vol_ops[dir].set(elem, 1, val); /* if stereo playback */
    snd_mixer_close(handle);

    return 0;
}

/****************************************************
 * NAME : int dev_snd_set_input_path(int input)
 *
 * Desc : set input path.
 *
 * INPUT :
 *   PARAMETERS:
 *        int input :
 *			  SND_LINE_IN : select Line input path.
 *			  MIC_IN : select mic input path.
 *
 * OUTPUT :
 *   RETURN : none.
 ****************************************************/
void dev_snd_set_input_path(int input)
{
	//# capture switch off
	alsa_mixer_cset(SND_PGA_CAPTURE_SWITCH, SND_SW_OFF);
	alsa_mixer_cset(SND_PGA_RIGHT_LINE1R_SWITCH, SND_SW_OFF);

	if (input == SND_LINE_IN) {
		alsa_mixer_cset(SND_PGA_RIGHT_MIC3R_SWITCH, SND_SW_OFF);
//		alsa_mixer_cset(SND_LEFT_LINE1L_MUX, SND_SW_ON);  //#differential
		alsa_mixer_cset(SND_PGA_LEFT_LINE1L_SWITCH, SND_SW_ON);  //#On
	} else {
		alsa_mixer_cset(SND_PGA_LEFT_LINE1L_SWITCH, SND_SW_OFF);
		alsa_mixer_cset(SND_PGA_RIGHT_MIC3R_SWITCH, SND_SW_ON);
	}

	//# capture switch on
	alsa_mixer_cset(SND_PGA_CAPTURE_SWITCH, SND_SW_ON);
}

/****************************************************
 * NAME : int dev_snd_set_output_path(int output)
 *
 * Desc : set output path.
 *
 * INPUT :
 *   PARAMETERS:
 *        int output :
 *			  SND_SPK2_OUT : select speaker 2 path.
 *			  SND_SPK1_OUT : select speaker 1 path.
 *
 * OUTPUT :
 *   RETURN : none.
 ****************************************************/
void dev_snd_set_output_path(int output)
{
	if (output == SND_SPK2_OUT) {
		alsa_mixer_cset(SND_LINE_PLAY_VOLUME, 100); //#line output volume = min
		alsa_mixer_cset(SND_RIGHT_DAC_MUX, 2); //#DAC_R MUX->HPROUT
		alsa_mixer_cset(SND_LEFT_DAC_MUX, 2);  //#DAC_L MUX->HPLOUT
	}
	else {
		alsa_mixer_cset(SND_LINE_PLAY_VOLUME, 100); //#line output volume = max
		alsa_mixer_cset(SND_RIGHT_DAC_MUX, 1); //#DAC3_R MUX->LINE+
		alsa_mixer_cset(SND_LEFT_DAC_MUX, 1);  //#DAC3_L MUX->LINE-
	}
}
