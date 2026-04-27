#include "Menu.ui.h"
#include "Menu.ui.input.h"
#include "Menu.ui.output.h"
#include "../helpers/Helpers.h"
#include "../exceptions/MovieServicesException.h"
#include "../exceptions/RepoException.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

MenuUI::MenuUI(const MenuUIInput &input, const MenuUIOutput &output, MovieServices &playlist, MovieServices &database) : input(input), output(output), playlistServices(playlist), databaseServices(database)
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
    try
    {
        this->databaseServices.addMovie(movie);
        std::cout << "Successfully added a movie to the database. :)" << std::endl;
    }
    catch (const MovieServicesException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void MenuUI::deleteMovieFromDatabase()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    try
    {
        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);
        this->databaseServices.removeMovieById(foundMovie.getId());
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void MenuUI::deleteMovieFromPlaylist()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    try
    {
        Movie foundMovie = this->playlistServices.getMovieByTitle(movieTitle);
        this->playlistServices.removeMovieById(foundMovie.getId());

        // asking the user if they liked the movie
        std::cout << "Liked the movie?: " << std::endl;
        bool confirmation = this->input.getUserConfirmation();

        // liking the movie in the database
        if (confirmation)
        {
            Movie payload = foundMovie;
            payload.setNumberOfLikes(foundMovie.getNumberOfLikes() + 1);
            this->databaseServices.updateMovieById(foundMovie.getId(), payload);
        }
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void MenuUI::updateMovieFromDatabase()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    try
    {
        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);
        Movie payload = this->input.getUserMovie();
        this->databaseServices.updateMovieById(foundMovie.getId(), payload);
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void MenuUI::displayMoviesFromDatabase()
{
    std::vector<TElem> movies = this->databaseServices.getElems();

    if (movies.size() == 0)
    {
        std::cout << "no movies in the database to display" << std::endl;
        return;
    }

    for (const TElem &elem : movies)
    {
        std::cout << "Title: " << elem.getTitle() << std::endl;
        std::cout << "Id: " << elem.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(elem.getGenre()) << std::endl;
        std::cout << "Year of Release: " << elem.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << elem.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << elem.getTrailer() << std::endl;
        std::cout << std::endl;
    }
}

void MenuUI::displayMoviesFromPlaylist()
{
    std::vector<TElem> movies = this->playlistServices.getElems();

    if (movies.size() == 0)
    {
        std::cout << "no movies in the playlist to display" << std::endl;
        return;
    }

    for (const TElem &elem : movies)
    {
        std::cout << "Title: " << elem.getTitle() << std::endl;
        std::cout << "Id: " << elem.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(elem.getGenre()) << std::endl;
        std::cout << "Year of Release: " << elem.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << elem.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << elem.getTrailer() << std::endl;
        std::cout << std::endl;
    }
}

void MenuUI::displayMovieFromDatabase()
{
    std::string movieTitle = this->input.getUserMovieTitle();

    try
    {
        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);

        std::cout << "Title: " << foundMovie.getTitle() << std::endl;
        std::cout << "Id: " << foundMovie.getId() << std::endl;
        std::cout << "Genre: " << Helpers::convertGivenMovieGenreToString(foundMovie.getGenre()) << std::endl;
        std::cout << "Year of Release: " << foundMovie.getYearOfRelease() << std::endl;
        std::cout << "Number of Likes: " << foundMovie.getNumberOfLikes() << std::endl;
        std::cout << "Trailer: " << foundMovie.getTrailer() << std::endl;
        std::cout << std::endl;
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void MenuUI::handleUserPlaylist()
{
    MovieGenre givenGenre = this->input.getUserMovieGenre();
    std::vector<TElem> filteredMovies = this->databaseServices.filterMoviesByGenre(givenGenre);

    if (filteredMovies.size() == 0)
    {
        std::cout << "no movies in the database to scroll through matched given genre" << std::endl;
        return;
    }

    auto currentIt = filteredMovies.begin();

    while (true)
    {
        // circular thingie
        if (currentIt == filteredMovies.end())
        {
            currentIt = filteredMovies.begin();
        }

        // display the current movie
        Movie movie = *currentIt;

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

            try
            {
                this->playlistServices.addMovie(movie);
                currentIt++;
                std::cout << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            catch (const MovieServicesException &e)
            {
                std::cerr << e.what() << '\n';
                break;
            }
            catch (const RepoException &e)
            {
                std::cerr << e.what() << '\n';
                break;
            }
        }
        else
        {
            // the user can either stop scrolling or move on to the next movie
            std::cout << "Next?" << std::endl;
            bool continueConfirmation = this->input.getUserConfirmation();

            if (!continueConfirmation)
                return;

            currentIt++;
            std::cout << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void MenuUI::start()
{
    Mode appMode = this->input.getUserMode();
    this->output.intro(appMode);

    if (this->databaseServices.getElems().size() == 0)
    {
        Helpers::insertTenMovieEntriesInTheDatabase(this->databaseServices);
    }

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
