// AVIEncoder.cpp: implementation of the CAVIEncoder class.
//
//////////////////////////////////////////////////////////////////////
#include <inttypes.h>
#include <iostream>
#include <limits.h>
#include <assert.h>

#include <stdio.h>
#include "syscommon.h"
#include "mmsystem.h"
#include "aviwriter.hh"
#include "avirecover.hh"
#include "udavi.h"

void* LIBAVI_createAvi(char* filePullPath, AVI_SYSTEM_PARAM* pAviPrm, int encoding)
{

	CAVIWriter* pWriter;

	pWriter = CAVIWriter::CreateNew();

	if(pWriter != NULL)
	{
		SYSTEM_PARAM sysParm;

		sysParm.nMainWidth 	= pAviPrm->nMainWidth;
		sysParm.nMainHeight = pAviPrm->nMainHeight;
		sysParm.nSubWidth	= pAviPrm->nSubWidth;
		sysParm.nSubHeight	= pAviPrm->nSubHeight;
		sysParm.fFrameRate 	= pAviPrm->fFrameRate;

		sysParm.nAudioBitRate 		= pAviPrm->nAudioBitRate;
		sysParm.nAudioChannel 		= pAviPrm->nAudioChannel;
		sysParm.nAudioBitPerSample 	= pAviPrm->nAudioBitPerSample;
		sysParm.nAudioFrameSize 	= pAviPrm->nAudioFrameSize;
		sysParm.nSamplesPerSec 		= pAviPrm->nSamplesPerSec;

		sysParm.nEnableMeta			= pAviPrm->nEnableMeta;
		sysParm.nMetaFps			= pAviPrm->nMetaFps;

		switch(pAviPrm->uSystemType)
		{
			case SYSTEM_TYPE_VIDEO:
				sysParm.uSystemType = IME6400_ET_VIDEO;
			break;
			case SYSTEM_TYPE_AUDIO_VIDEO:
				sysParm.uSystemType = IME6400_ET_SYSTEM;
			default:
				sysParm.uSystemType = IME6400_ET_SYSTEM;
			break;
		}

		switch(pAviPrm->uChannelMode)
		{
			case CHANNEL_MODE_SINGLE:
				sysParm.uChannelMode = IME6400_CM_SINGLE;
			break;
			case CHANNEL_MODE_SUBPIC:
				sysParm.uChannelMode = IME6400_CM_SUBPIC;
			break;
			default:
				sysParm.uChannelMode = IME6400_CM_SINGLE;
			break;
		}

		switch(pAviPrm->uVideoType)
		{
			case ENCODING_MPEG4:
				sysParm.uVideoType = IME6400_SD_MPEG4;
			break;
			case ENCODING_H264:
				sysParm.uVideoType = IME6400_SD_H264;
			break;
			default:
				sysParm.uVideoType = IME6400_SD_H264;
			break;
		}

		switch(pAviPrm->nAudioType)
		{
			case ENCODING_ADPCM:
				sysParm.nAudioType = IME6400_AM_ADPCM;
			break;
			case ENCODING_ULAW:
				sysParm.nAudioType = IME6400_AM_MULAW;
			break;
			default:
				sysParm.nAudioType = IME6400_AM_MULAW;
			break;
		}

		if(pWriter->Open(filePullPath, &sysParm, encoding) != LIBAVI_SUCCESS){
			delete pWriter;
			pWriter = NULL;
		}
	}

	return pWriter;
}

int LIBAVI_write_frame(void* handlAvi, AVI_FRAME_PARAM* pframePrm)
{
	CAVIWriter* pWriter = (CAVIWriter*)handlAvi;

	if(pWriter != NULL)
	{
		if(pframePrm->data_type <= DATA_TYPE_VIDEO_SUB)
			pWriter->WriteVideoData((BYTE*)pframePrm->buf, pframePrm->size, pframePrm->iskey_frame, 1, pframePrm->data_type);
		if(pframePrm->data_type == DATA_TYPE_AUDIO && pWriter->GetSystemType() == IME6400_ET_SYSTEM)
			pWriter->WriteAudioData((BYTE*)pframePrm->buf, pframePrm->size, 1);
		if(pframePrm->data_type == DATA_TYPE_META)
			pWriter->WriteMetaData((BYTE*)pframePrm->buf, pframePrm->size, 1);
	}

	return LIBAVI_SUCCESS;
}

int LIBAVI_closeAvi(void* handlAvi)
{
	CAVIWriter* pWriter = (CAVIWriter*)handlAvi;

	if(pWriter != NULL)
	{
		pWriter->Close();
		delete pWriter;
		pWriter = NULL;
	}

	return LIBAVI_SUCCESS;
}


int LIBAVI_recoverFile(char* filePullPath)
{
	return AVIrcStart(filePullPath);
}

char* LIBAVI_recoverGetErrMsg()
{
	return AVIrcGetErrMsg();
}



