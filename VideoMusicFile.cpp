#include "VideoMusicFile.h"

VideoMusicFile::VideoMusicFile(const char * name, const char * artist, const char * duration, const char * audiodata, const char* type, const char* videodata) : MusicFile(name, artist, duration, audiodata, type)
{
	set_videodata(videodata);
}

VideoMusicFile::VideoMusicFile(const VideoMusicFile & other) : MusicFile(other)
{
	set_videodata(other.videodata_);
}

VideoMusicFile & VideoMusicFile::operator=(const VideoMusicFile & other)
{
	if (this != &other) {
		MusicFile::operator=(other);
		delete[] videodata_;
		set_videodata(other.videodata_);
	}
	return *this;
}

VideoMusicFile::~VideoMusicFile()
{
	delete[] videodata_;
}


void VideoMusicFile::PlayMP4() const
{
	PlayMP3();
	int videodata_len = strlen(videodata_);
	for (int i = videodata_len - 1; i >= 0; i--) {
		int j = videodata_len - i;
		if (j % 3 != 0) { cout << videodata_[i]; }

	}
	cout << endl;

}

void VideoMusicFile::PlayAVI() const
{
	int videodata_len = strlen(videodata_);
	for (int i = videodata_len - 1; i >= 0; i--) {
		cout << videodata_[i];
	}
	cout << endl;
	PlayFlac();
}
void VideoMusicFile::PlayFile() const
{
	if (!strcmp(type_, "MP4")) { PlayMP4(); }
	else if (!strcmp(type_, "AVI")) { PlayAVI(); }
	
}

char * VideoMusicFile::get_videodata() const
{
	return videodata_;
}

void VideoMusicFile::set_videodata(const char * videodata)
{
	videodata_ = new char[strlen(videodata) + 1];
	assert(videodata_ != NULL);
	strcpy(videodata_, videodata);
}
