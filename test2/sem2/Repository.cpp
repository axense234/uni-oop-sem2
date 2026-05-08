#include "Repository.h"

void Repository::add(const Song &s)
{
    this->songs.add(s);
}

int Repository::getSize() const
{
    return this->songs.getSize();
}