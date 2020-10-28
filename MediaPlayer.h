#ifndef MEDIAPLAYER_MEDIAPLAYER_MEDIAPLAYER_H_
#define MEDIAPLAYER_MEDIAPLAYER_MEDIPLAYER_H_
#include "MusicFile.h"
#include "VideoMusicFile.h"
#include "Playlist.h"

const int kMax = 100;

class MediaPlayer {
private:
	Playlist* playlists_;
	int size_player_;
	int capacity_player_;
	void CopyPlayer(const MediaPlayer&);
	void DeletePlayer();
public:
	MediaPlayer();
	MediaPlayer(const MediaPlayer&);
	MediaPlayer& operator=(const MediaPlayer&);
	~MediaPlayer();
	
	void AddPlaylist(char*);
	Playlist* get_playlists() const;

	void Play();
	void Add();
	void CreatePlaylist();
	//void playAll();
	void PlayPlaylist();
	void AddMediaToPlaylist();
	
};



#endif
