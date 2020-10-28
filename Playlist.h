#ifndef MEDIAPLAYER_MEDIAPLAYER_PLAYLIST_H_
#define MEDIAPLAYER_MEDIAPLAYER_PLAYLIST_H_
#include "MusicFile.h"
#include "VideoMusicFile.h"
#include <stdlib.h> 
#include <time.h>


class Playlist {
private:
	char* name_;
	int size_playlist_;
	int capacity_playlist_;
	VideoMusicFile** playlist_files_;
    void CopyPlaylist(const Playlist&);
	void DeletePlaylist();
public:
	
	Playlist();
	//Playlist(const char* = "", int = 0, VideoMusicFile** = 0);
	Playlist(const Playlist&);
	Playlist& operator=(const Playlist&);
	~Playlist();

    char*get_name() const;
	void set_name(char*);
	int get_size_playlist() const;
	VideoMusicFile** get_files() const;
	void AddMedia(const char*, const char*, const char*, const char*, const char*, const char*);
	void RemoveMedia(int);
	void RemoveMediaFromPlaylist(int, int*);
	void ShowAll() const;
	void ShowByArtist(char*) const;
	void ShowByName(const char*) const;
	void NormalPlay() const;
	void ShuffledPlay() const;
	
	
};



#endif