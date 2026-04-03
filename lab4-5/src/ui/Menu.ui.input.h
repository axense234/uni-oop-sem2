#pragma once

#include "../domain/Movie.h"
#include "../ui/Menu.ui.h"

#include <string>

class MenuUI;

class MenuUIInput
{
    friend class MenuUI;

private:
    /**
     * @brief Gets a command from the user.
     */
    std::string getUserCommand() const;

    /**
     * @brief Gets a movie id from the user.
     *
     * @return int
     */
    int getUserMovieId() const;
    /**
     * @brief Gets a movie title from the user.
     *
     * @return std::string
     */
    std::string getUserMovieTitle() const;
    /**
     * @brief Gets a movie genre from the user.
     *
     * @return MovieGenre
     */
    MovieGenre getUserMovieGenre() const;
    /**
     * @brief Gets a movie year of release from the user.
     *
     * @return short
     */
    short getUserMovieYearOfRelease() const;
    /**
     * @brief Gets a movie number of likes from the user.
     *
     * @return int
     */
    int getUserMovieNumberOfLikes() const;
    /**
     * @brief Gets a movie trailer from the user.
     *
     * @return std::string
     */
    std::string getUserMovieTrailer() const;

    /**
     * @brief Gets the application mode from the user.
     *
     * @return Mode
     */
    Mode getUserMode() const;

    /**
     * @brief Gets a Movie from the user.
     *
     * @return Movie
     */
    Movie getUserMovie() const;

public:
    /**
     * @brief Constructor.
     *
     */
    MenuUIInput();
};