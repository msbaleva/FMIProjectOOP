#ifndef MEDIAPLAYER_MEDIAPLAYER_MUSICFILE_H_
#define MEDIAPLAYER_MEDIAPLAYER_MUSICFILE_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
using namespace std;

class MusicFile {
protected:
	int ID_;
	char* name_;
	char* artist_;
	char* duration_;
	char* audiodata_;
	char* type_;
    void CopyFile(const MusicFile&);
	void DeleteFile();
public:
	MusicFile(const char* = "", const char* = "", const char* = "", const char* = "", const char* = "");
	MusicFile(const MusicFile&);
	MusicFile& operator=(const MusicFile&);
	virtual ~MusicFile();
	
	void PlayMP3() const;
	void PlayFlac() const;
	virtual void PlayFile() const;
	int get_ID() const;
	char* get_name() const;
	char* get_artist() const;
	char* get_duration() const;
	char* get_audiodata() const;
	char* get_type() const;
	void set_ID(int);
	void set_name(const char*);
	void set_artist(const char*);
	void set_duration(const char*);
	void set_audiodata(const char* audiodata);
	void set_type(const char*);
	void Print() const;
	

};



#endif