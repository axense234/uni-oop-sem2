#include "ActionRemove.h"

ActionRemove::ActionRemove(Song deletedSong, Repository &repo) : deletedSong(deletedSong), repo(repo) {};

void ActionRemove::executeUndo()
{
    this->repo.addSong(this->deletedSong);
}

void ActionRemove::executeRedo()
{
    this->repo.removeSong(this->deletedSong);
}