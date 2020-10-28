#include "MusicFile.h"


MusicFile::MusicFile(const char * name, const char * artist, const char * duration, const char * audiodata, const char* type)
{
	set_ID(0);
	set_name(name);
	set_artist(artist);
	set_duration(duration);
	set_audiodata(audiodata);
	set_type(type);	
}

MusicFile::MusicFile(const MusicFile & other)
{
	CopyFile(other);
}

MusicFile & MusicFile::operator=(const MusicFile & other)
{
	if (this != &other) {
		DeleteFile();
		CopyFile(other);
	}
	return *this;
}



MusicFile::~MusicFile()
{
	DeleteFile();
}

void MusicFile::CopyFile(const MusicFile & other)
{
	set_ID(other.ID_);
	set_name(other.name_);
	set_artist(other.artist_);
	set_duration(other.duration_);
	set_audiodata(other.audiodata_);
	set_type(other.type_);
}

void MusicFile::DeleteFile()
{
	delete[] name_;
	delete[] artist_;
	delete[] duration_;
	delete[] audiodata_;
	delete[] type_;
}



void MusicFile::PlayMP3() const
{
	int audiodata_len = strlen(audiodata_);
	for (int i = audiodata_len - 1; i >= 0; i--) {
		int j = audiodata_len - i;
		if (j % 3 != 0) { cout << audiodata_[i]; }

	}
	cout << endl;
}

void MusicFile::PlayFlac() const
{
	int audiodata_len = strlen(audiodata_);
	for (int i = audiodata_len - 1; i >= 0; i--) {
		cout << audiodata_[i];
	}
	cout << endl;
}

void MusicFile::PlayFile() const
{
	if (!strcmp(type_, "MP3")) { PlayMP3(); }
	else if (!strcmp(type_, "flac")) { PlayFlac(); }
}

int MusicFile::get_ID() const
{
	return ID_;
}

char* MusicFile::get_name() const
{
	return name_;
}

char* MusicFile::get_artist() const
{
	return artist_;
}

char * MusicFile::get_duration() const
{
	return duration_;
}

char * MusicFile::get_audiodata() const
{
	return audiodata_;
}

char* MusicFile::get_type() const
{
	return type_;
}


void MusicFile::set_ID(int ID)
{
	ID_ = ID;
}

void MusicFile::set_name(const char * name)
{
	name_ = new char[strlen(name) + 1];
	assert(name_ != NULL);
	strcpy(name_, name);
}

void MusicFile::set_artist(const char * artist)
{
	artist_ = new char[strlen(artist) + 1];
	assert(artist_ != NULL);
	strcpy(artist_, artist);
}

void MusicFile::set_duration(const char * duration)
{
	duration_ = new char[strlen(duration) + 1];
	assert(duration_ != NULL);
	strcpy(duration_, duration);
}

void MusicFile::set_audiodata(const char * audiodata)
{
	audiodata_ = new char[strlen(audiodata) + 1];
	assert(audiodata_ != NULL);
	strcpy(audiodata_, audiodata);
}

void MusicFile::set_type(const char * type)
{
	type_ = new char[strlen(type) + 1];
	assert(type_ != NULL);
	strcpy(type_, type);
}

void MusicFile::Print() const
{
	cout << setw(3) << ID_ << setw(20) << name_ << setw(20) << artist_ << setw(10) << duration_ << setw(5) << type_ << endl;	
}


