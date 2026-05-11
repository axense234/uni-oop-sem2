#pragma once

#include "Action.h"
#include "Song.h"
#include "Repository.h"

class ActionRemove : public Action
{
private:
    Song deletedSong;
    Repository &repo;

public:
    ActionRemove(Song addedSong, Repository &repo);
    void executeUndo() override;
    void executeRedo() override;
};
