#include "Menu.ui.controller.h"

#include "../repo/Memory.repo.h"
#include "../helpers/Helpers.h"

#include <iostream>

MenuUIController::MenuUIController(MenuUI &u) : ui(u) {}

void MenuUIController::addMovie()
{
    Movie movie = this->ui.getUserMovie();

    if (this->ui.movieServices.addMovie(movie))
    {
        std::cout << "Successfully added a movie to the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not add a movie to the database. >:(" << std::endl;
    }
}

void MenuUIController::deleteMovie()
{
    int movieId = this->ui.getUserMovieId();

    if (this->ui.movieServices.removeMovieById(movieId))
    {
        std::cout << "Successfully removed a movie from the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not remove a movie from the database. >:(" << std::endl;
    }
}

void MenuUIController::updateMovie()
{
    int movieId = this->ui.getUserMovieId();

    Movie foundMovie = this->ui.movieServices.getMovieById(movieId);

    if (foundMovie.getId() == -1)
    {
        std::cout << "Could not find movie by id in the database :>." << std::endl;
        return;
    }

    Movie payload = this->ui.getUserMovie();

    if (this->ui.movieServices.updateMovieById(movieId, payload))
    {
        std::cout << "Successfully updated a movie from the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not update a movie from the database. >:(" << std::endl;
    }
}

void MenuUIController::displayMovies()
{
    MemoryRepoIterator it = this->ui.database.getElemsIterator();

    it.first();
    while (it.valid())
    {
        Movie movie = it.getCurrent();
        std::cout << "Title: " << movie.getTitle() << std::endl;
        std::cout << "Id: " << movie.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(movie.getGenre()) << std::endl;
        std::cout << "Year of Release: " << movie.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << movie.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << movie.getTrailer() << std::endl;
        std::cout << std::endl;

        it.next();
    }
}

void MenuUIController::displayMovie()
{
    int movieId = this->ui.getUserMovieId();

    Movie foundMovie = this->ui.movieServices.getMovieById(movieId);
    if (foundMovie.getId() != -1)
    {
        std::cout << "Title: " << foundMovie.getTitle() << std::endl;
        std::cout << "Id: " << foundMovie.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(foundMovie.getGenre()) << std::endl;
        std::cout << "Year of Release: " << foundMovie.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << foundMovie.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << foundMovie.getTrailer() << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Could not find a movie by id from the database. >:(" << std::endl;
    }
}