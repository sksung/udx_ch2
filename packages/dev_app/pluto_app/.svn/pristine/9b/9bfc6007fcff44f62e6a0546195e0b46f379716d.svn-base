// syscommon.h: interface for the common define.
//
//////////////////////////////////////////////////////////////////////
#ifndef _UBX_AVI_H_
#define _UBX_AVI_H_

#ifdef __cplusplus
extern "C"{
#endif

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------
 AVI file format
-----------------------------------------------------------------------------*/
typedef int				BOOL;
typedef long			LONG;
typedef unsigned long 	DWORD;
typedef unsigned short 	WORD;
typedef unsigned char 	BYTE;

typedef DWORD	FOURCC;
typedef WORD	TWOCC;

#define mmioFOURCC( ch0, ch1, ch2, ch3 ) \
	( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |	\
	( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )

#define aviTWOCC(ch0, ch1) ((WORD)(BYTE)(ch0) | ((WORD)(BYTE)(ch1) << 8))

/* form types, list types, and chunk types */
#define formtypeRIFF					mmioFOURCC('R', 'I', 'F', 'F')
#define formtypeLIST					mmioFOURCC('L', 'I', 'S', 'T')
#define formtypeAVI             		mmioFOURCC('A', 'V', 'I', ' ')
#define listtypeAVIHEADER       		mmioFOURCC('h', 'd', 'r', 'l')
#define ckidAVIMAINHDR          		mmioFOURCC('a', 'v', 'i', 'h')
#define listtypeSTREAMHEADER			mmioFOURCC('s', 't', 'r', 'l')
#define ckidSTREAMHEADER        		mmioFOURCC('s', 't', 'r', 'h')
#define ckidSTREAMFORMAT        		mmioFOURCC('s', 't', 'r', 'f')

#define listtypeAVIMOVIE        		mmioFOURCC('m', 'o', 'v', 'i')
#define listtypeAVIRECORD       		mmioFOURCC('r', 'e', 'c', ' ')

#define ckidAVINEWINDEX         		mmioFOURCC('i', 'd', 'x', '1')

/* Basic chunk types */
#define cktypeDIBbits           		aviTWOCC('d', 'b')
#define cktypeDIBcompressed     		aviTWOCC('d', 'c')
#define cktypePALchange         		aviTWOCC('p', 'c')
#define cktypeWAVEbytes         		aviTWOCC('w', 'b')
#define cktypeTEXT						aviTWOCC('t', 'x')

//# avi index dwFlags
#define AVIIF_LIST          			0x00000001L // chunk is a 'LIST'
#define AVIIF_KEYFRAME      			0x00000010L // this frame is a key frame.
#define AVIIF_NOTIME	    			0x00000100L // this frame doesn't take any time
#define AVIIF_COMPUSE       			0x0FFF0000L // these bits are for compressor use

typedef struct {
	FOURCC	ckID;
	DWORD	ckSize;
} CK;

typedef struct {
	FOURCC	ckID;
	DWORD	ckSize;
	DWORD	ckCodec;
} CK_RIFF;

typedef struct {
	FOURCC	ckID;
	DWORD	ckSize;
	DWORD	ckType;
} CK_LIST;

typedef struct {
	unsigned long dwMicroSecPerFrame;
	unsigned long dwMaxBytesPerSec;
	unsigned long dwReserved1;
	unsigned long dwFlags;
	unsigned long dwTotalFrames;
	unsigned long dwInitialFrames;
	unsigned long dwStreams;
	unsigned long dwSuggestedBufferSize;
	unsigned long dwWidth;
	unsigned long dwHeight;
	unsigned long dwScale;
	unsigned long dwRate;
	unsigned long dwStart;
	unsigned long dwLength;
} AVIMainHeader;

//# Header Block
typedef struct {
	CK_RIFF		ck_riff;	// RIFF tag
	CK_LIST		ck_hdrl;	// LIST tag
	CK			ck_avih;	// AVI header
	AVIMainHeader avih;
} AVIHeadBlock;

typedef struct {
	CK_LIST	ck_movi;
	CK		ck_idx1;
} AVITailBlock;

typedef struct {
    DWORD		ckid;
    DWORD		dwFlags;
    DWORD		dwChunkOffset;		// Position of chunk
    DWORD		dwChunkLength;		// Length of chunk
} AVIINDEXENTRY;

//# AVI File Information
typedef struct {
	AVIHeadBlock Head;
	AVITailBlock Tail;

	unsigned long movi_pos;
	unsigned long idx1_pos;
	unsigned long strm_pos;

	AVIINDEXENTRY *idx_entry;
	unsigned long idx_cnt;

	FILE *pFile;
} AVIFile;

/*----------------------------------------------------------------------------
 Jpeg file format
-----------------------------------------------------------------------------*/
typedef struct {
	char mark[2];
	char reserved[5];
	char he[2];
	char wi[2];
} JpegFile;

#ifdef __cplusplus
}
#endif


#endif
