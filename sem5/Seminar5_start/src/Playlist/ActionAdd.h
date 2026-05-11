#pragma once

#include "Action.h"
#include "Song.h"
#include "Repository.h"

class ActionAdd : public Action
{
private:
    Song addedSong;
    Repository &repo;

public:
    ActionAdd(Song addedSong, Repository &repo);
    void executeUndo() override;
    void executeRedo() override;
};
