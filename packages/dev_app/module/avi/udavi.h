// syscommon.h: interface for the common define.
//
//////////////////////////////////////////////////////////////////////
#ifndef _UDAVI_H_
#define _UDAVI_H_

#ifdef __cplusplus
extern "C"{
#endif

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define LIBAVI_ERROR	(-1)
#define LIBAVI_SUCCESS	(0)

typedef enum
{
    SYSTEM_TYPE_VIDEO,				//Video Only
    SYSTEM_TYPE_AUDIO_VIDEO,		//Audio + Video
} enumDVR_SYSTEM_TYPE;

typedef enum
{
    CHANNEL_MODE_SINGLE,			//1Channel Video
    CHANNEL_MODE_SUBPIC,			//2Channels Video with sub pic
} enumDVR_CHANNEL_MODE;

typedef enum
{
    DATA_TYPE_VIDEO_MAIN,
    DATA_TYPE_VIDEO_SUB,
    DATA_TYPE_AUDIO,
    DATA_TYPE_META,
    DATA_TYPE_MAX
} enumDVR_DATA_TYPE;

typedef enum {
	NSDVR_PICTURE_TYPE_I,
	NSDVR_PICTURE_TYPE_P,
	NSDVR_PICTURE_TYPE_B,
} enumNSDVR_PICTURE_TYPE;

typedef enum
{
    ENCODING_UNKNOWN=0,

    /* Video */
    ENCODING_MPEG4=1,
    ENCODING_JPEG,
    ENCODING_H264,

    /* Audio */
    ENCODING_PCM=32,
    ENCODING_ULAW,
    ENCODING_ALAW,
    ENCODING_ADPCM,
    ENCODING_G721,
    ENCODING_G723,
    ENCODING_MP3,
} enumDVR_ENCODING_TYPE;

typedef struct tag_AVI_SYSTEM_PARAM
{
	// System information
	unsigned long	uSystemType;
	unsigned long	uChannelMode;
	int				nEnableMeta;

	// Video information
	unsigned long	uVideoType;
	int				nMainWidth;
	int				nMainHeight;
	int				nSubWidth;
	int				nSubHeight;
	double			fFrameRate;

	// Audio information
	int				nAudioType;			//Audio encoding type
	int				nAudioChannel;		//1: momo, 2: stereo
	int				nSamplesPerSec;		//8KHz, 16KHz, ...
	int				nAudioBitRate;		//96Kbps, 128Kbps,...
	int				nAudioFrameSize;
	int				nAudioBitPerSample;	//8bit, 16bit,...

	// Meta information
	int				nMetaFps;

} AVI_SYSTEM_PARAM;

typedef struct tag_AVI_FRAME_PARAM {

	char *buf;
	int size;

	int channel;
	int data_type;		//0: video_main, 1: video_sub, 2: audio
	int iskey_frame;
	int time_sec;
	int time_usec;

} AVI_FRAME_PARAM;


/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
void* LIBAVI_createAvi(char* filePullPath, AVI_SYSTEM_PARAM* pAviPrm, int encoding);
int LIBAVI_write_frame(void* handlAvi, AVI_FRAME_PARAM* pframePrm);
int LIBAVI_closeAvi(void* handlAvi);

int LIBAVI_recoverFile(char* filePullPath);
char* LIBAVI_recoverGetErrMsg();

#ifdef __cplusplus
}
#endif


#endif // !defined(AFX_BLOCKBUFFER_H__0CF63682_769F_4CF8_B3F4_A0D61958E7A0__INCLUDED_)
