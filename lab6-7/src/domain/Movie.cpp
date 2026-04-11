#include "Movie.h"
#include "../helpers/Helpers.h"

#include <string>
#include <iostream>

Movie::Movie()
{
    this->id = -1;
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

std::string Movie::getCSV() const
{
    return std::to_string(this->id) + "," + this->title + "," + Helpers::convertGivenMovieGenreToString(this->genre) + "," + std::to_string(this->yearOfRelease) + "," + std::to_string(this->numberOfLikes) + "," + this->trailer;
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

void Movie::setTitle(const std::string &title)
{
    this->title = title;
}

void Movie::setTrailer(const std::string &trailer)
{
    this->trailer = trailer;
}

void Movie::setGenre(MovieGenre genre)
{
    this->genre = genre;
}

void Movie::setYearOfRelease(short yor)
{
    this->yearOfRelease = yor;
}

void Movie::setNumberOfLikes(int nbLikes)
{
    this->numberOfLikes = nbLikes;
}

void Movie::setId(int id)
{
    this->id = id;
}

std::ostream &operator<<(std::ostream &stream, const Movie &m)
{
    stream << m.getCSV();
    return stream;
}
std::istream &operator>>(std::istream &stream, Movie &m)
{
    std::string idStr, title, genreStr, yearStr, likesStr, trailer;

    std::getline(stream, idStr, ',');
    std::getline(stream, title, ',');
    std::getline(stream, genreStr, ',');
    std::getline(stream, yearStr, ',');
    std::getline(stream, likesStr, ',');
    std::getline(stream, trailer);

    m.setId(std::stoi(idStr));
    m.setTitle(title);
    m.setGenre(Helpers::convertGivenStringToMovieGenre(genreStr));
    m.setYearOfRelease(std::stoi(yearStr));
    m.setNumberOfLikes(std::stoi(likesStr));
    m.setTrailer(trailer);

    return stream;
}