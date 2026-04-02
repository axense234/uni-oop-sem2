#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

void Controller::addSongToRepository(const std::string &artist, const std::string &title, double minutes, double seconds, const std::string &source)
{
	Song s{artist, title, Duration{minutes, seconds}, source};
	this->repo.addSong(s);
}

void Controller::addSongToPlaylist(const Song &song)
{
	this->playlist.push_back(song);
}

void Controller::addAllSongsByArtistToPlaylist(const std::string &artist)
{
	// get all the songs from the repository
	std::vector<Song> songs = this->repo.getSongs();

	// use STL algorithms and lambdas
	std::copy_if(
		songs.begin(),
		songs.end(),
		std::back_inserter(this->playlist),
		[&](Song curr)
		{ return curr.getArtist() == artist; });
}