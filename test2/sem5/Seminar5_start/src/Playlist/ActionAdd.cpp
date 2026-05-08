#include "ActionAdd.h"

ActionAdd::ActionAdd(Song addedSong, Repository &repo) : addedSong(addedSong), repo(repo) {};

void ActionAdd::executeUndo()
{
    this->repo.removeSong(this->addedSong);
}

void ActionAdd::executeRedo()
{
    this->repo.addSong(this->addedSong);
}