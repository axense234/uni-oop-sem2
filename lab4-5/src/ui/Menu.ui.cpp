#include "Menu.ui.h"
#include "Menu.ui.input.h"
#include "Menu.ui.output.h"
#include "../helpers/Helpers.h"

#include <iostream>

MenuUI::MenuUI(const MenuUIInput &input, const MenuUIOutput &output, const MemoryRepo &db, PlaylistServices &playlist, MovieServices &mS) : input(input), output(output), database(db), playlistServices(playlist), movieServices(mS)
{
    this->mode = ADMIN;
}

Mode MenuUI::getMode() const
{
    return this->mode;
}

void MenuUI::addMovie()
{
    Movie movie = this->input.getUserMovie();

    if (this->movieServices.addMovie(movie))
    {
        std::cout << "Successfully added a movie to the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not add a movie to the database. >:(" << std::endl;
    }
}

void MenuUI::deleteMovie()
{
    int movieId = this->input.getUserMovieId();

    if (this->movieServices.removeMovieById(movieId))
    {
        std::cout << "Successfully removed a movie from the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not remove a movie from the database. >:(" << std::endl;
    }
}

void MenuUI::updateMovie()
{
    int movieId = this->input.getUserMovieId();

    Movie foundMovie = this->movieServices.getMovieById(movieId);

    if (foundMovie.getId() == -1)
    {
        std::cout << "Could not find movie by id in the database :>." << std::endl;
        return;
    }

    Movie payload = this->input.getUserMovie();

    if (this->movieServices.updateMovieById(movieId, payload))
    {
        std::cout << "Successfully updated a movie from the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not update a movie from the database. >:(" << std::endl;
    }
}

void MenuUI::displayMovies()
{
    std::pair<DynamicVectorIterator, DynamicVectorIterator> iterators = this->database.iterators();

    while (iterators.first != iterators.second)
    {
        Movie movie = iterators.first.getCurrent();
        std::cout << "Title: " << movie.getTitle() << std::endl;
        std::cout << "Id: " << movie.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(movie.getGenre()) << std::endl;
        std::cout << "Year of Release: " << movie.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << movie.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << movie.getTrailer() << std::endl;
        std::cout << std::endl;

        iterators.first++;
    }
}

void MenuUI::displayMovie()
{
    int movieId = this->input.getUserMovieId();

    Movie foundMovie = this->movieServices.getMovieById(movieId);
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

void MenuUI::start()
{
    Mode appMode = this->input.getUserMode();
    this->output.intro(appMode);

    Helpers::insertTenMovieEntriesInTheDatabase(this->movieServices);

    while (true)
    {
        std::string command = this->input.getUserCommand();

        if (command == "movies" && appMode == ADMIN)
        {
            this->displayMovies();
        }
        else if (command == "add" && appMode == ADMIN)
        {
            this->addMovie();
        }
        else if (command == "remove" && appMode == ADMIN)
        {
            this->deleteMovie();
        }
        else if (command == "update" && appMode == ADMIN)
        {
            this->updateMovie();
        }
        else if (command == "find" && appMode == ADMIN)
        {
            this->displayMovie();
        }
        else if (command == "genres")
        {
            this->output.genres();
        }
        else if (command == "help")
        {
            this->output.help(appMode);
        }
        else if (command == "exit")
        {
            std::cout << "Exited the program." << std::endl;
            exit(1);
        }
        else
        {
            std::cout << "invalid command, use help" << std::endl;
            continue;
        }
    }
}
