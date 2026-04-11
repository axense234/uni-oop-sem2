#pragma once

#include "../domain/Movie.h"
#include "../services/Movie.services.h"

#include <string>

class MenuUIInput;
class MenuUIOutput;

enum Mode
{
    ADMIN,
    USER
};

class MenuUI
{

private:
    Mode mode;

    const MenuUIInput &input;
    const MenuUIOutput &output;
    MovieServices &playlistServices;
    MovieServices &databaseServices;

public:
    /**
     * @brief Constructor
     *
     */
    MenuUI(const MenuUIInput &input, const MenuUIOutput &output, MovieServices &playlist, MovieServices &database);

    /**
     * @brief Getter
     *
     * @return Mode
     */
    Mode getMode() const;

    /**
     * @brief Adds a movie to the database.
     *
     */
    void addMovieToDatabase();

    /**
     * @brief Deletes a movie from the database.
     *
     */
    void deleteMovieFromDatabase();

    /**
     * @brief Deletes a user movie from the playlist.
     *
     */
    void deleteMovieFromPlaylist();

    /**
     * @brief Updates a movie from the database.
     *
     */
    void updateMovieFromDatabase();

    /**
     * @brief Displays all the movies in the database.
     *
     */
    void displayMoviesFromDatabase();

    /**
     * @brief Displays all the movies in the user's playlist.
     *
     */
    void displayMoviesFromPlaylist();

    /**
     * @brief Displays a movie from the database.
     *
     */
    void displayMovieFromDatabase();

    /**
     * @brief Cycles through the database movies one movie at a time, displaying it's contents.
     * @brief Automatically opens up the shown movie trailer in the user's default browser.
     * @brief The user then can choose to either add the movie to the watch list, or continue viewing the next.
     *
     */
    void handleUserPlaylist();

    /**
     * @brief Starts the menu program.
     *
     */
    void start();
};