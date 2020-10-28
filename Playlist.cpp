#include "Playlist.h"

Playlist::Playlist()
{
	name_ = new char[10];
	strcpy(name_, "All Media");
	size_playlist_ = 0;
	capacity_playlist_ = 10;
	playlist_files_ = new VideoMusicFile*[capacity_playlist_];
}


Playlist::Playlist(const Playlist & other)
{
	CopyPlaylist(other);
}

Playlist & Playlist::operator=(const Playlist & other)
{
	if (this != &other) {
		DeletePlaylist();
		CopyPlaylist(other);
	}return *this;
}

Playlist::~Playlist()
{
	DeletePlaylist();
}


void Playlist::CopyPlaylist(const Playlist & other)
{
	set_name(other.name_);
	size_playlist_ = other.size_playlist_;
	capacity_playlist_ = other.capacity_playlist_;
	playlist_files_ = new VideoMusicFile*[capacity_playlist_];
	assert(playlist_files_ != NULL);
	
	for (int i = 0; i < size_playlist_; i++) {
		playlist_files_[i] = other.playlist_files_[i];
	}
}

void Playlist::DeletePlaylist()
{
	delete[] name_;
	for (int i = 0; i < size_playlist_; i++) { delete playlist_files_[i]; }
	delete[] playlist_files_;
}



void Playlist::AddMedia(const char* name, const char* artist, const char* duration, const char* audiodata, const char* type, const char* videodata)
{
	
	if (size_playlist_ == capacity_playlist_) {
		capacity_playlist_ *= 2;
		VideoMusicFile** temp = new VideoMusicFile*[capacity_playlist_];
		assert(temp != NULL);
		for (int i = 0; i < size_playlist_; i++) {
			temp[i] = playlist_files_[i];
		}
		delete[] playlist_files_;
		playlist_files_ = new VideoMusicFile*[capacity_playlist_];
		for (int i = 0; i < size_playlist_; i++) {
			playlist_files_[i] = temp[i];
		}
		delete[] temp;
		//VideoMusicFile** temp2 = playlistFiles;
		//playlistFiles = temp;
		//delete temp2;
	}
	if (!strcmp(type, "MP4") || !strcmp(type, "AVI")) {
		
		playlist_files_[size_playlist_] = new VideoMusicFile(name, artist, duration, audiodata, type, videodata);
		
	}
	else if (!strcmp(type, "MP3") || !strcmp(type, "flac")) {
		
		playlist_files_[size_playlist_] = (VideoMusicFile*)(new MusicFile(name, artist, duration, audiodata, type));
			
	}
	
	if (!strcmp(name_, "All Media")) { playlist_files_[size_playlist_]->set_ID(size_playlist_ + 1); cout << playlist_files_[size_playlist_]->get_ID(); }
		size_playlist_++;
	
}

void Playlist::RemoveMedia(int ID)
{	
		//playlistFiles[ind] = NULL;
		for (int i = ID; i < size_playlist_-1 ; i++) {
			playlist_files_[i] = playlist_files_[i + 1];
			
			if (!strcmp(name_, "All Media")) {
				playlist_files_[i]->set_ID(i+1);
			}
		
		}
		
		playlist_files_[size_playlist_-1] = NULL;
		delete playlist_files_[size_playlist_ - 1];
        size_playlist_--;
}



void Playlist::RemoveMediaFromPlaylist(int count, int* ID)
{
	for (int i = 0; i < count; i++) {
          for (int j = 0; j < count; j++) {
		    int k = 0;
		      do {
			    k++;
		          } while (playlist_files_[k]->get_ID() != ID[j]);
				  RemoveMedia(k);
	      }
	

		
	}


}

void Playlist::ShowAll() const
{
	if (!strcmp(name_, "All Media")) {
		cout << setw(3) << "ID" << setw(20) << "Name" << setw(20) << "Artist" << setw(10) << "Duration" << setw(5) << "Type" << endl;
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl;
		for (int i = 0; i < size_playlist_; i++) {
			playlist_files_[i]->Print();
		}
		cout << endl;
	}
	else {
		cout << setw(3) << "#" << setw(10) << "Playlist" << setw(3) << "ID" << setw(20) << "Name" << setw(20) << "Artist" << setw(10) << "Duration" << setw(5) << "Type" << endl;
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl;
		for (int i = 0; i < size_playlist_; i++) {
			cout << setw(3) << i + 1 << setw(10) << name_;
			playlist_files_[i]->Print();
		}
		cout << endl;
	}
}

void Playlist::ShowByArtist(char * artist) const
{
	cout << setw(3) << "ID" << setw(20) << "Name" << setw(20) << "Artist" << setw(10) << "Duration" << setw(5) << "Type" << endl;
	for (int i = 0; i < size_playlist_; i++) {
		if (!strcmp(playlist_files_[i]->get_artist(), artist)) {
			cout << setw(3) << i + 1;
			playlist_files_[i]->Print();
		}
	}
}

void Playlist::ShowByName(const char * name) const
{
	cout << setw(3) << "ID" << setw(20) << "Name" << setw(20) << "Artist" << setw(10) << "Duration" << setw(5) << "Type" << endl;
	for (int i = 0; i < size_playlist_; i++) {
		if (!strcmp(playlist_files_[i]->get_name(), name)) {
			cout << setw(3) << i + 1;
			playlist_files_[i]->Print();
		}
	}
}

void Playlist::NormalPlay() const
{
	for (int i = 0; i < size_playlist_; i++) {
		cout << "Now playing: " << playlist_files_[i]->get_name() << " by " << playlist_files_[i]->get_artist() << endl;
		playlist_files_[i]->PlayFile();
	}
}

void Playlist::ShuffledPlay() const
{
	int* nums = new int[size_playlist_];
	int index = -1;
	for (int i = 0; i < size_playlist_; i++) {
		nums[i] = i;
	}
	for (int i = 0; i < size_playlist_; i++) {
		srand(time(NULL));
		do { index = rand() % size_playlist_; } while (nums[index] == -1);
		cout << "Now playing: " << playlist_files_[index]->get_name() << " by " << playlist_files_[index]->get_artist() << endl;
		playlist_files_[index]->PlayFile();
		nums[index] = -1;
	}
	delete[] nums;
	
}

void Playlist::set_name(char* name)
{
	delete[] name_;
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

int Playlist::get_size_playlist() const
{
	return size_playlist_;
}

char * Playlist::get_name() const
{
	return name_;
}


VideoMusicFile ** Playlist::get_files() const
{
	return playlist_files_;
}

