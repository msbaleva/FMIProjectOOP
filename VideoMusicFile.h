#ifndef MEDIAPLAYER_MEDIAPLAYER_VIDEOMUSICFILE_H_
#define MEDIAPLAYER_MEDIAPLAYER_VIDEOMUSICFILE_H_
#include "MusicFile.h"

class VideoMusicFile : public MusicFile {
private:
	char* videodata_;
public:
	VideoMusicFile(const char* = "", const char* = "", const char* = "", const char* = "", const char* = "", const char* = "");
	VideoMusicFile(const VideoMusicFile&);
	VideoMusicFile& operator=(const VideoMusicFile&);
	~VideoMusicFile();
	void PlayMP4() const;
	void PlayAVI() const;
	void PlayFile() const;
	char* get_videodata() const;
	void set_videodata(const char*);


};


#endif