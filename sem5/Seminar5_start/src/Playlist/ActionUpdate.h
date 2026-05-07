#pragma once

#include "Action.h"
#include "Song.h"
#include "Repository.h"

class ActionUpdate : public Action
{
private:
    Song oldSong;
    Song newSong;
    Repository &repo;

public:
    ActionUpdate(Song oldSong, Song newSong, Repository &repo);
    void executeUndo() override;
    void executeRedo() override;
};
