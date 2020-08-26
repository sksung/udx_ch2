/*
 * ASoC driver for TI 81XX UD Video Recoder platform.
 *
 * Based on davinci-evm.c
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/timer.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/clk.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/soc.h>
#include <sound/soc-dapm.h>

#include <asm/dma.h>
#include <asm/mach-types.h>

#include <plat/asp.h>
#include <asm/hardware/edma.h>

#include "../codecs/tlv320aic3x.h"

#include "davinci-pcm.h"
#include "davinci-i2s.h"
#include "davinci-mcasp.h"

#ifdef CONFIG_SND_SOC_TVP5158AUDIO
#define AUDIO_FORMAT (SND_SOC_DAIFMT_I2S | \
		SND_SOC_DAIFMT_CBM_CFM | SND_SOC_DAIFMT_NB_IF)
#else
#define AUDIO_FORMAT (SND_SOC_DAIFMT_DSP_B | \
		SND_SOC_DAIFMT_CBM_CFM | SND_SOC_DAIFMT_IB_NF)
#endif

static int ud_soc_hw_params(struct snd_pcm_substream *substream,
			 struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
#if 0
	struct davinci_audio_dev *dev;
#endif
	unsigned int sysclk;
	int ret = 0;

#if 1
	/* TI811x use McASP2_AUX 20MHz */
	sysclk = 20000000;
#else
	dev = snd_soc_dai_get_drvdata(cpu_dai);
	sysclk = clk_get_rate(dev->clk);
#endif

#ifndef CONFIG_SND_SOC_TVP5158AUDIO
	ret = snd_soc_dai_set_fmt(codec_dai, AUDIO_FORMAT);
	if (ret < 0)
		return ret;
#endif

	/* set cpu DAI configuration */
	ret = snd_soc_dai_set_fmt(cpu_dai, AUDIO_FORMAT);
	if (ret < 0)
		return ret;

#ifndef CONFIG_SND_SOC_TVP5158AUDIO
	ret = snd_soc_dai_set_sysclk(codec_dai, 0, sysclk, SND_SOC_CLOCK_OUT);
	if (ret < 0)
		return ret;
#endif

	return 0;
}

static struct snd_soc_ops ud_soc_ops = {
	.hw_params = ud_soc_hw_params,
};

/* davinci-evm machine dapm widgets */
static const struct snd_soc_dapm_widget aic3x_dapm_widgets[] = {
	SND_SOC_DAPM_HP("Headphone Jack", NULL),
	SND_SOC_DAPM_LINE("Line Out", NULL),
	SND_SOC_DAPM_MIC("Mic Jack", NULL),
	SND_SOC_DAPM_LINE("Line In", NULL),
};

static const struct snd_soc_dapm_route audio_map[] = {
	/* Headphone connected to HPLOUT, HPROUT */
	{"Headphone Jack", NULL, "HPLOUT"},
	{"Headphone Jack", NULL, "HPROUT"},

	/* Line Out connected to LLOUT, RLOUT */
	{"Line Out", NULL, "LLOUT"},
	{"Line Out", NULL, "RLOUT"},

	/* Mic connected to (MIC3R) */
	{"MIC3R", NULL, "Mic Bias 2.5V"},
	{"Mic Bias 2.5V", NULL, "Mic Jack"},
};

static int ud_aic3x_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_codec *codec = rtd->codec;

	/* Add specific widgets */
	snd_soc_dapm_new_controls(codec, aic3x_dapm_widgets,
				  ARRAY_SIZE(aic3x_dapm_widgets));

	/* Set up davinci-evm specific audio path audio_map */
	snd_soc_dapm_add_routes(codec, audio_map, ARRAY_SIZE(audio_map));

	/* not connected */
	snd_soc_dapm_disable_pin(codec, "MONO_LOUT");
	snd_soc_dapm_enable_pin(codec, "HPLCOM");
	snd_soc_dapm_enable_pin(codec, "HPRCOM");

	/* always connected */
	snd_soc_dapm_enable_pin(codec, "Headphone Jack");
	snd_soc_dapm_enable_pin(codec, "Line Out");

	snd_soc_dapm_enable_pin(codec, "Mic Jack");

	snd_soc_dapm_sync(codec);

	return 0;
}

static struct snd_soc_dai_link ud_mcasp_dai[] = {
	{
		.name = "TLV320AIC3X",
		.stream_name = "AIC3X",
		.cpu_dai_name= "davinci-mcasp.1",
		.codec_dai_name = "tlv320aic3x-hifi",
		.codec_name = "tlv320aic3x-codec.1-0018",
		.platform_name = "davinci-pcm-audio",
		.init = ud_aic3x_init,
		.ops = &ud_soc_ops,
	},
#ifdef CONFIG_SND_SOC_TVP5158AUDIO
	{
		.name = "TVP5158AUDIO",
		.stream_name = "TVP-PCM",
		.cpu_dai_name= "davinci-mcasp.0",
		.codec_dai_name = "tvp5158-hifi",
		.platform_name ="davinci-pcm-audio",
		.codec_name = "tvp5158-audio",
		.ops = &ud_soc_ops,
	}
#endif
};

static struct snd_soc_card ud_mcasp_card[] = {
	{
		.name = "ASOC_UD",
		.dai_link = ud_mcasp_dai,
		.num_links = ARRAY_SIZE(ud_mcasp_dai),
	}
};

static struct platform_device *soc_pdev;

static int __init ud_soc_init(void)
{
	int ret;

	soc_pdev = platform_device_alloc("soc-audio", 0);
	if (!soc_pdev)
		return -ENOMEM;

	platform_set_drvdata(soc_pdev, ud_mcasp_card);
	ret = platform_device_add(soc_pdev);
	if (ret) {
		printk(KERN_ERR "Can't add soc platform device\n");
		platform_device_put(soc_pdev);
		return ret;
	}

	return ret;
}

static void __exit ud_soc_exit(void)
{
	platform_device_unregister(soc_pdev);
}

module_init(ud_soc_init);
module_exit(ud_soc_exit);

MODULE_AUTHOR("UDWORKs");
MODULE_DESCRIPTION("TI81XX UD ASoC driver");
MODULE_LICENSE("GPL");
