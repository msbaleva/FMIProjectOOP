#include "MediaPlayer.h"
#include <string>

MediaPlayer::MediaPlayer()
{
	size_player_ = 1;
	capacity_player_ = 10;
	playlists_ = new Playlist[capacity_player_];
	
}

MediaPlayer::MediaPlayer(const MediaPlayer & other)
{
	CopyPlayer(other);
}

MediaPlayer & MediaPlayer::operator=(const MediaPlayer & other)
{
	if (this!=&other) {
		DeletePlayer();
		CopyPlayer(other);
	}return *this;
}

MediaPlayer::~MediaPlayer()
{
	DeletePlayer();
}

void MediaPlayer::CopyPlayer(const MediaPlayer & other)
{
	
	size_player_ = other.size_player_;
	capacity_player_ = other.capacity_player_;
	playlists_ = new Playlist[capacity_player_];
	assert(playlists_ != NULL);

	for (int i = 0; i < size_player_; i++) {
		playlists_[i] = other.playlists_[i];
	}
}

void MediaPlayer::DeletePlayer()
{
	delete[] playlists_;
}

void MediaPlayer::AddPlaylist(char * name)
{
	if (size_player_ == capacity_player_) {
		capacity_player_ = 2 * capacity_player_;
		Playlist* temp = new Playlist[capacity_player_];
		assert(temp != NULL);
		for (int i = 0; i < size_player_; i++) {
			temp[i] = playlists_[i];
		}
		delete[] playlists_;
		playlists_ = new Playlist[capacity_player_];
		for (int i = 0; i < size_player_; i++) {
			playlists_[i] = temp[i];
		}
		delete[] temp;
		//Playlist* tmp_ = playlists;
		//playlists = temp_arr_;
		//delete tmp_;
	}
	playlists_[size_player_].set_name(name);
	size_player_++;
}

Playlist * MediaPlayer::get_playlists() const
{
	return playlists_;
}

void MediaPlayer::Play()
{
	char ch[10];
	cin >> ch;
	if (!strcmp(ch, "all")) {
		cout << "Would you like to play normal or shuffled?" << endl << ">";
		cin >> ch;
		if (!strcmp(ch, "normal")) { playlists_[0].NormalPlay(); }
		if (!strcmp(ch, "shuffled")) { playlists_[0].ShuffledPlay(); }
	}
	else {
		int num = 0;
		num = stoi(ch, 0,10);
		playlists_[0].get_files()[num - 1]->PlayFile();
	}
}
void MediaPlayer::PlayPlaylist() {
	char buffer[100];
	char ch[10];
	int i;
	cin.ignore();
	cin.getline(buffer, 100, '\n');
	for (i = 0; i < size_player_; i++) {
		
		if (!strcmp(playlists_[i].get_name(),buffer)) {break; }
	}
	cout << "Would you like to play normal or shuffled?" << endl << ">";
	cin >> ch;
	if (!strcmp(ch, "normal")) { playlists_[i].NormalPlay(); }
	if (!strcmp(ch, "shuffled")) { playlists_[i].ShuffledPlay(); }
}

void MediaPlayer::Add()
{
	char name[kMax];
	char artist[kMax];
	char duration[kMax];
	char audiodata[kMax];
	char type[kMax];
	char videodata[kMax];
	cout << "Enter media name: " << endl << ">";
	cin.clear();
	cin.ignore();
	cin.getline(name, 100, '\n');
	cout << "Enter artist: " << endl << ">";
	cin.getline(artist, 100, '\n');
	cout << "Enter duration: " << endl << ">";
	cin.getline(duration, 100, '\n');
	cout << "Enter audio data: " << endl << ">";
	cin.getline(audiodata, 100, '\n');
	cout << "Enter media type: " << endl << ">";
	cin.getline(type, 100, '\n');
	while (!(!strcmp(type, "MP4") || !strcmp(type, "AVI")  || !strcmp(type, "MP3") || !strcmp(type, "flac")))
	{ cout << "You have entered a new type of file. How would you like to decode it?" << endl << ">as ";
	    cin.getline(type, 100, '\n');
	} 
	if (!strcmp(type, "MP4") || !strcmp(type, "AVI")) {
		cout << "Enter video data: " << endl << ">";
		cin.getline(videodata, 100, '\n');
		playlists_[0].AddMedia(name, artist, duration, audiodata, type, videodata);

	}
	else if (!strcmp(type, "MP3") || !strcmp(type, "flac")) {
		playlists_[0].AddMedia(name, artist, duration, audiodata, type, "");
	}
	

}

void MediaPlayer::AddMediaToPlaylist()
{
	char list[100];
	cin.ignore();
	cin.getline(list, 100, '\n');
	char ch[10];
	int i;
	for (i = 0; i < size_player_; i++) {

		if (!strcmp(playlists_[i].get_name(), list)) { break; }
	}
	cout << "Enter ID of the files you want to add to your playlist:" << endl;
	int id;
	do { cin >> id; 
	if (!strcmp(playlists_[0].get_files()[id]->get_type(), "MP4") || !strcmp(playlists_[0].get_files()[id]->get_type(), "AVI")) {
		playlists_[i].AddMedia(playlists_[0].get_files()[id]->get_name(), playlists_[0].get_files()[id]->get_artist(), playlists_[0].get_files()[id]->get_duration(), playlists_[0].get_files()[id]->get_audiodata(), playlists_[0].get_files()[id]->get_type(), playlists_[0].get_files()[id]->get_videodata());
	}
	else if (!strcmp(playlists_[0].get_files()[id]->get_type(), "MP3") || !strcmp(playlists_[0].get_files()[id]->get_type(), "flac")) {
		playlists_[i].AddMedia(playlists_[0].get_files()[id]->get_name(), playlists_[0].get_files()[id]->get_artist(), playlists_[0].get_files()[id]->get_duration(), playlists_[0].get_files()[id]->get_audiodata(), playlists_[0].get_files()[id]->get_type(),"");
	}
	 } 
	while (id = !'.');
}
void MediaPlayer::CreatePlaylist()
{
	char name[kMax];
	cin.getline(name, 100, '\n'); 
	AddPlaylist(name);
}
