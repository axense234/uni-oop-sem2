#include "Repository.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

void Repository::addSong(const Song &s)
{
	this->songs.push_back(s);
}

Song Repository::findByArtistAndTitle(const std::string &artist, const std::string &title)
{
	std::vector<Song>::iterator it = std::find_if(this->songs.begin(), this->songs.end(), [&](Song curr) noexcept
												  { return curr.getArtist() == artist && curr.getTitle() == title; });

	if (it != this->songs.end())
	{
		return *it;
	}

	return Song{};
}