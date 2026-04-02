#include "PlayList.h"

PlayList::PlayList()
{
	this->current = 0;
}

void PlayList::add(const Song &song)
{
	this->songs.add(song);
}

Song PlayList::getCurrentSong()
{
	if (this->current == this->songs.getSize())
		this->current = 0;
	return this->songs[this->current];
}

void PlayList::next()
{
	if (this->songs.getSize() == 0)
		return;
	this->current++;
	Song currentSong = this->getCurrentSong();
}

bool PlayList::isEmpty()
{
	return this->songs.getSize() == 0;
}