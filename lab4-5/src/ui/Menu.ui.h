#pragma once

#include "../domain/Movie.h"
#include "../services/Movie.services.h"
#include "../services/Playlist.services.h"

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

    const MenuUIOutput &output;
    const MenuUIInput &input;
    MovieServices &movieServices;
    PlaylistServices &playlistServices;
    const MemoryRepo &database;

public:
    /**
     * @brief Constructor
     *
     */
    MenuUI(const MenuUIInput &input, const MenuUIOutput &output, const MemoryRepo &db, PlaylistServices &playlist, MovieServices &mS);

    /**
     * @brief Getter
     *
     * @return Mode
     */
    Mode getMode() const;

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

    /**
     * @brief Starts the menu program.
     *
     */
    void start();
};