#pragma once

#include <string>

class Duration
{
private:
    int minutes;
    int seconds;

public:
    Duration(int minutes = 0, int seconds = 0);
};

class Song
{
private:
    std::string artist;
    std::string title;
    Duration duration;
    std::string link;

public:
    Song();
    Song(const std::string &artist, const std::string &title, int minutes, int seconds, const std::string &link);

    std::string getArtist() const;
    std::string getTitle() const;
};