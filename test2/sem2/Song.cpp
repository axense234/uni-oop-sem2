#include "Song.h"

Duration::Duration(int minutes, int seconds)
{
    this->minutes = minutes;
    this->seconds = seconds;
}

Song::Song(const std::string &artist, const std::string &title, int minutes, int seconds, const std::string &link)
{
    this->artist = artist;
    this->title = title;
    // this->duration = Duration(minutes, seconds);
    this->duration = Duration{minutes, seconds};
    this->link = link;
}

Song::Song()
{
    this->artist = "";
    this->title = "";
    this->link = "";

    Duration d{};
    this->duration = d;
}

std::string Song::getArtist() const
{
    return this->artist;
}

std::string Song::getTitle() const
{
    return this->title;
}