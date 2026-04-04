#include "Menu.ui.h"
#include "Menu.ui.input.h"
#include "Menu.ui.output.h"
#include "../helpers/Helpers.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

MenuUI::MenuUI(const MenuUIInput &input, const MenuUIOutput &output, PlaylistServices &playlist, MovieServices &mS) : input(input), output(output), playlistServices(playlist), movieServices(mS)
{
    this->mode = ADMIN;
}

Mode MenuUI::getMode() const
{
    return this->mode;
}

void MenuUI::addMovieToDatabase()
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

void MenuUI::deleteMovieFromDatabase()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    // find the movie
    Movie foundMovie = this->movieServices.getMovieByTitle(movieTitle);

    if (foundMovie.getId() == -1)
    {
        std::cout << "Couldn't find the movie to remove it." << std::endl;
        return;
    }

    if (this->movieServices.removeMovieById(foundMovie.getId()))
    {
        std::cout << "Successfully removed a movie from the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not remove a movie from the database. >:(" << std::endl;
    }
}

void MenuUI::deleteMovieFromPlaylist()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    // find the movie
    Movie foundMovie = this->movieServices.getMovieByTitle(movieTitle);

    if (foundMovie.getId() == -1)
    {
        std::cout << "Couldn't find the movie to remove it." << std::endl;
        return;
    }

    // deleting from the playlist
    if (this->playlistServices.removeMovieById(foundMovie.getId()))
    {
        std::cout << "Successfully removed a movie from the playlist. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not remove a movie from the playlist. >:(" << std::endl;
    }

    // asking the user if they liked the movie
    std::cout << "Liked the movie?: " << std::endl;
    bool confirmation = this->input.getUserConfirmation();

    // liking the movie in the database
    if (confirmation)
    {
        Movie payload = foundMovie;
        payload.setNumberOfLikes(foundMovie.getNumberOfLikes() + 1);
        this->movieServices.updateMovieById(foundMovie.getId(), payload);
    }
}

void MenuUI::updateMovieFromDatabase()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    // find the movie
    Movie foundMovie = this->movieServices.getMovieByTitle(movieTitle);

    if (foundMovie.getId() == -1)
    {
        std::cout << "Couldn't find the movie to remove it." << std::endl;
        return;
    }

    Movie payload = this->input.getUserMovie();

    if (this->movieServices.updateMovieById(foundMovie.getId(), payload))
    {
        std::cout << "Successfully updated a movie from the database. :)" << std::endl;
    }
    else
    {
        std::cout << "Could not update a movie from the database. >:(" << std::endl;
    }
}

void MenuUI::displayMoviesFromDatabase()
{
    std::pair<DynamicVectorIterator, DynamicVectorIterator> iterators = this->movieServices.iterators();

    int count = 0;
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
        count++;
    }

    if (count == 0)
    {
        std::cout << "no movies in the database to display" << std::endl;
    }
}

void MenuUI::displayMoviesFromPlaylist()
{
    std::pair<DynamicVectorIterator, DynamicVectorIterator> iterators = this->playlistServices.iterators();

    int count = 0;
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
        count++;
    }

    if (count == 0)
    {
        std::cout << "no movies in the playlist to display" << std::endl;
    }
}

void MenuUI::displayMovieFromDatabase()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    // find the movie
    Movie foundMovie = this->movieServices.getMovieByTitle(movieTitle);

    if (foundMovie.getId() == -1)
    {
        std::cout << "Couldn't find the movie to remove it." << std::endl;
        return;
    }

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

void MenuUI::handleUserPlaylist()
{
    std::pair<DynamicVectorIterator, DynamicVectorIterator> iterators = this->movieServices.iterators();
    DynamicVectorIterator usedIterator = iterators.first;

    if (this->movieServices.repo.size() == 0)
    {
        std::cout << "no movies in the database to scroll through" << std::endl;
    }

    while (true)
    {
        // circular thingie
        if (!usedIterator.valid())
        {
            usedIterator.first();
        }

        // display the current movie
        Movie movie = usedIterator.getCurrent();
        std::cout << "Title: " << movie.getTitle() << std::endl;
        std::cout << "Id: " << movie.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(movie.getGenre()) << std::endl;
        std::cout << "Year of Release: " << movie.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << movie.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << movie.getTrailer() << std::endl;
        std::cout << "Opening the trailer......." << std::endl;
        std::cout << std::endl;

        // sleep for like 1 second
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // we open up the url in the browser
        Helpers::openURL(movie.getTrailer());

        // now we see if the user liked the trailer
        std::cout << "Did you like the trailer and want to add the movie to the playlist?" << std::endl;
        bool confirmation = this->input.getUserConfirmation();

        if (confirmation)
        {
            this->playlistServices.addMovie(movie);

            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        else
        {
            // the user can either stop scrolling or move on to the next movie
            std::cout << "Next?" << std::endl;
            bool continueConfirmation = this->input.getUserConfirmation();

            if (!continueConfirmation)
                return;

            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        usedIterator++;
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

        // ADMIN
        if (command == "movies" && appMode == ADMIN)
        {
            this->displayMoviesFromDatabase();
        }
        else if (command == "add" && appMode == ADMIN)
        {
            this->addMovieToDatabase();
        }
        else if (command == "remove" && appMode == ADMIN)
        {
            this->deleteMovieFromDatabase();
        }
        else if (command == "update" && appMode == ADMIN)
        {
            this->updateMovieFromDatabase();
        }
        else if (command == "find" && appMode == ADMIN)
        {
            this->displayMovieFromDatabase();
        }
        // USER
        else if (command == "playlist")
        {
            this->displayMoviesFromPlaylist();
        }
        else if (command == "playlist-delete")
        {
            this->deleteMovieFromPlaylist();
        }
        else if (command == "scroll")
        {
            this->handleUserPlaylist();
        }
        // UTIL
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
