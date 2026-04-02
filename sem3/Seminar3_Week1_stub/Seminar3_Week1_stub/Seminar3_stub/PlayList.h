#pragma once
#include "DynamicVector.h"
#include "Song.h"

class PlayList
{
private:
	DynamicVector<Song> songs;
	int current;

public:
	PlayList();

	// Adds a song to the playlist.
	void add(const Song &song);

	// Returns the song that is currently playing.
	Song getCurrentSong();

	// Plays the next song in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();
};
