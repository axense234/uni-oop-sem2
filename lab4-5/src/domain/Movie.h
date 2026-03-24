#pragma once

#include <string>

enum MovieGenre
{
    ACTION,
    ADVENTURE,
    ANIMATION,
    BIOGRAPHY,
    COMEDY,
    CRIME,
    DOCUMENTARY,
    DRAMA,
    FAMILY,
    FANTASY,
    HISTORY,
    HORROR,
    MUSIC,
    MYSTERY,
    ROMANCE,
    SCIFI,
    SPORT,
    WAR,
    WESTERN
};

// forward dec
class DynamicVector;
class MovieServices;

class Movie
{

    friend class DynamicVector;
    friend class MovieServices;

private:
    int id;
    std::string title;
    MovieGenre genre;
    short yearOfRelease;
    int numberOfLikes;
    std::string trailer;

    void setId(int id);

public:
    /**
     * @brief Default constructor.
     *
     */
    Movie();
    /**
     * @brief Constructor.
     *
     * @param id Id of the movie. Must be unique. int
     * @param title Title of movie. std::string
     * @param genre Genre of movie. MovieGenre
     * @param yearOfRelease Year of release. short
     * @param numberOfLikes Number of likes. int
     * @param trailer Trailer, link to an online resource. std::string
     */
    Movie(int id, const std::string &title, MovieGenre genre, short yearOfRelease, int numberOfLikes, const std::string &trailer);

    int getId() const;
    std::string getTitle() const;
    MovieGenre getGenre() const;
    short getYearOfRelease() const;
    int getNumberOfLikes() const;
    std::string getTrailer() const;

    void setTitle(const std::string &title);
    void setGenre(MovieGenre genre);
    void setYearOfRelease(short yor);
    void setNumberOfLikes(int nbLikes);
    void setTrailer(const std::string &trailer);
};