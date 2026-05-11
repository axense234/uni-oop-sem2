#include "ActionUpdate.h"

ActionUpdate::ActionUpdate(Song oldSong, Song newSong, Repository &repo) : oldSong(oldSong), newSong(newSong), repo(repo) {};

void ActionUpdate::executeUndo()
{
    this->repo.updateSong(newSong.getArtist(), newSong.getTitle(), oldSong);
}

void ActionUpdate::executeRedo()
{
    this->repo.updateSong(oldSong.getArtist(), oldSong.getTitle(), newSong);
}