#pragma once

#include "../domain/Movie.h"
#include "../services/Movie.services.h"

#include <string>

enum Mode
{
    ADMIN,
    USER
};

class MenuUI
{

private:
    Mode mode;

    MovieServices &movieServices;
    const MemoryRepo &database;

public:
    /**
     * @brief Constructor
     *
     */
    MenuUI(const MemoryRepo &db, MovieServices &mS);

    Mode getMode() const;

    /**
     * @brief Starts the menu program.
     *
     */
    void start();

    /**
     * @brief Displays the possible movie genres.
     *
     */
    void genres();

    /**
     * @brief Displays the program intro.
     *
     * @param mode ADMIN or USER
     */
    void intro(Mode mode);

    /**
     * @brief Displays a list of available program commands.
     *
     * @param mode ADMIN or USER
     */
    void help(Mode mode);

    /**
     * @brief Gets a command from the user.
     */
    std::string getUserCommand();

    int getUserMovieId();
    std::string getUserMovieTitle();
    MovieGenre getUserMovieGenre();
    short getUserMovieYearOfRelease();
    int getUserMovieNumberOfLikes();
    std::string getUserMovieTrailer();

    /**
     * @brief Gets the application mode from the user.
     *
     * @return Mode
     */
    Mode getUserMode();

    /**
     * @brief Gets a Movie from the user.
     *
     * @return Movie
     */
    Movie getUserMovie();
    /**
     * @brief Adds a movie.
     *
     */
    void addMovie();

    /**
     * @brief Deletes a movie.
     *
     */
    void deleteMovie();

    /**
     * @brief Updates a movie.
     *
     */
    void updateMovie();

    /**
     * @brief Displays all the movies.
     *
     */
    void displayMovies();

    /**
     * @brief Displays a movie.
     *
     */
    void displayMovie();
};