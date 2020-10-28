#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <cstring>
#include <iomanip>
#include "MusicFile.h"
#include "VideoMusicFile.h"
#include "Playlist.h"
#include "MediaPlayer.h"
using namespace std;
//const int kMax = 100;


int main() {
	
	MediaPlayer MyPlayer;
	char buffer[100];
	cout << "Welcome to Media Player!\n" << endl;
	do {
		if (MyPlayer.get_playlists()[0].get_size_playlist() == 0) { cout << "Media Player is empty.\n" << endl; }
		else {
			cout << endl;
			MyPlayer.get_playlists()[0].ShowAll();
		}
		cout << "You can type: " << endl;
		cout << "-> <add> to add new media to player" << endl
			<< "-> <show all> to show all media" << endl
			<< "-> <show by name> and a name to search media by name" << endl
			<< "-> <show by artist> and an artist to search media by artist" << endl
			<< "-> <play> and ID to play media" << endl
			<< "-> <remove> and media ID to remove media from player" << endl
			<< "-> <create playlist> and enter a name to create a new playlist" << endl
			<< "-> <playlist add> and a playlist name to add media to playlist" << endl
			<< "-> <playlist remove> and a playlist name to add media to playlist" << endl
			<< "-> <exit> to close Media Player\n" << endl;
		
		cout << ">";
		cin >> buffer;

		if (!strcmp(buffer, "play")) { 
			MyPlayer.Play(); 
		}
		
		else if (!strcmp(buffer, "add")) {
					
			MyPlayer.Add();
			cout << "New media added to media player." << endl;
		

		}
		else if (!strcmp(buffer, "remove")) { int n; cin >> n; MyPlayer.get_playlists()[0].RemoveMedia(n - 1); MyPlayer.get_playlists()[0].ShowAll(); }
		else if (!strcmp(buffer, "show")) {
			cin >> buffer;
			if (!strcmp(buffer, "all")) { MyPlayer.get_playlists()[0].ShowAll(); }
			else {
				cin >> buffer;
				if (!strcmp(buffer, "artist")) { cin.ignore(); cin.getline(buffer, 100); MyPlayer.get_playlists()[0].ShowByArtist(buffer); }
				else if (!strcmp(buffer, "name")) { cin.ignore(); cin.getline(buffer, 100); MyPlayer.get_playlists()[0].ShowByName(buffer); }
			}
		}
		else if (!strcmp(buffer, "create")) { cin >> buffer; MyPlayer.CreatePlaylist(); cout << "New Playlist created." << endl; }
		else if (!strcmp(buffer, "playlist")) {
			cin >> buffer;
			if (!strcmp(buffer, "add")) {
				MyPlayer.AddMediaToPlaylist();
			}
		
			else if (!strcmp(buffer, "remove")) {
				
			}
			else if (!strcmp(buffer, "play")) {  MyPlayer.PlayPlaylist(); }
	    }
	} while (strcmp(buffer, "exit"));
	
	return 0;
}

