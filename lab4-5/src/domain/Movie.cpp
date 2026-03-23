#include "Movie.h"

#include <string>

Movie::Movie()
{
    this->title = "";
    this->genre = ACTION;
    this->yearOfRelease = 0;
    this->numberOfLikes = 0;
    this->trailer = "";
}

Movie::Movie(int id, const std::string &title, MovieGenre genre, short yearOfRelease, int numberOfLikes, const std::string &trailer)
{
    this->id = id;
    this->title = title;
    this->genre = genre;
    this->yearOfRelease = yearOfRelease;
    this->numberOfLikes = numberOfLikes;
    this->trailer = trailer;
}

int Movie::getId() const
{
    return this->id;
}

std::string Movie::getTitle() const
{
    return this->title;
}

MovieGenre Movie::getGenre() const
{
    return this->genre;
}

short Movie::getYearOfRelease() const
{
    return this->yearOfRelease;
}

int Movie::getNumberOfLikes() const
{
    return this->numberOfLikes;
}

std::string Movie::getTrailer() const
{
    return this->trailer;
}
