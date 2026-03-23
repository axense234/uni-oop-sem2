#pragma once

#include "../ui/Menu.ui.h"

class MenuUIController
{

    friend class MenuUI;

private:
    MenuUI &ui;

    MenuUIController(MenuUI &u);

public:
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
};