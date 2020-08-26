// AVIWriter.h: interface for the CAVIWriter class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _AVIWRITER_HH_
#define _AVIWRITER_HH_

#include <fcntl.h>
#include "syscommon.h"
#include "blockbuffer.hh"
#include "aviencoder.hh"


class CAVIWriter
{
public:
	static CAVIWriter* CreateNew();	
	BOOL IsRecord();
	CAVIWriter();// { m_bFileOpen = FALSE; m_pfile = NULL; m_vps = NULL; m_aps = NULL; m_mps = NULL; }
	~CAVIWriter();// { Close(); }


	BOOL Open(const char* pszFilePath, SYSTEM_PARAM* pSystemParam, int encoding);
	
	void Close();

	BOOL WriteVideoData(BYTE* pbyData, int nSize, BOOL isKeyFrame, int nFrameCnt, int isSub);
	BOOL WriteAudioData(BYTE* pbyData, int nSize, int nFrameCnt);
	BOOL WriteMetaData(BYTE* pbyData, int nSize, int nFrameCnt);
	int GetSystemType();

private:
	CBlockBuffer m_BlockBuffer;
	FILE* m_fileExtra;

	BOOL	m_bFileOpen;
	BOOL 	m_bEncoding;
	int		m_nSystemType;
	int		m_nChannelMode;
	int		m_nEnableMeta;
	int		m_nAudioType;
	int		m_nAudioFrameSize;
	BOOL	m_bFirstVideo[MAX_VIDEO_CHANNEL];

	AVISTREAMHEADER m_strvhdr[MAX_VIDEO_CHANNEL];
	AVISTREAMHEADER m_strahdr;	
	AVISTREAMHEADER m_strmhdr;
	AVIFILE* m_pfile;
	AVISTREAM* m_vps[MAX_VIDEO_CHANNEL];
	AVISTREAM* m_aps;
	AVISTREAM* m_mps;
};

#endif // 
