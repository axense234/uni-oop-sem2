#include "PlayList.h"

PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::add(const Song &song)
{
	this->songs.push_back(song);
}

Song PlayList::getCurrentSong()
{
	if ((size_t)this->current == this->songs.size())
		this->current = 0;
	return this->songs[this->current];
	return Song{};
}

void PlayList::play()
{
	if (this->songs.size() == 0)
		return;
	this->current = 0;
	Song currentSong = this->getCurrentSong();
}

void PlayList::next()
{
	if (this->songs.size() == 0)
		return;
	this->current++;
	Song currentSong = this->getCurrentSong();
}

bool PlayList::isEmpty()
{
	return this->songs.size() == 0;
}