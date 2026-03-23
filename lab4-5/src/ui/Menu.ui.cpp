#include "Menu.ui.h"
#include "../helpers/Helpers.h"
#include "../controllers/Menu.ui.controller.h"

#include <iostream>

MenuUI::MenuUI()
{
    this->mode = ADMIN;
}

Mode MenuUI::getMode() const
{
    return this->mode;
}

void MenuUI::genres()
{
    std::cout << "possible movie genres" << std::endl;
    std::cout << "=======================================" << std::endl;

    std::cout << "ACTION ADVENTURE ANIMATION BIOGRAPHY" << std::endl;
    std::cout << "COMEDY CRIME DOCUMENTARY DRAMA" << std::endl;
    std::cout << "FAMILY FANTASY HISTORY HORROR" << std::endl;
    std::cout << "MUSIC MYSTERY ROMANCE SCIFI" << std::endl;
    std::cout << "SPORT WAR EASTERN and that's all" << std::endl;

    std::cout << std::endl;
}

void MenuUI::intro(Mode mode)
{
    std::cout << "Movies Application Console Interface Thing" << std::endl;
    std::cout << "type \"help\" for available commands " << std::endl;

    if (mode == ADMIN)
    {
        std::cout << "authorization: ADMIN" << std::endl;
    }
    else if (mode == USER)
    {
        std::cout << "authorization: USER" << std::endl;
    }
    std::cout << std::endl;
}

void MenuUI::help(Mode mode)
{
    if (mode == ADMIN)
    {
        std::cout << "admin only commands" << std::endl;
        std::cout << "=======================================" << std::endl;
        std::cout << "movies: Displays all the Movies in the database" << std::endl;
        std::cout << "add: Adds a given Movie to the database" << std::endl;
        std::cout << "remove: Removes a Movie from the database using an id." << std::endl;
        std::cout << "update: Updates a Movie from the database by id, using a payload" << std::endl;
    }

    std::cout << "public commands" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "genres: Displays the possible movie genre values." << std::endl;
    std::cout << "help: Helps a random person in the world. Be careful." << std::endl;
    std::cout << "exit: Exits the program. Or does it?" << std::endl;

    std::cout << std::endl;
}

Mode MenuUI::getUserMode()
{
    std::string rawMode;

    while (true)
    {
        std::cout << "Mode (ADMIN or USER): ";
        if (std::cin >> rawMode)
        {
            try
            {
                Mode mode;
                if (rawMode == "ADMIN")
                {
                    mode = ADMIN;
                }
                else if (rawMode == "USER")
                {
                    mode = USER;
                }
                else
                {
                    throw std::exception();
                }

                return mode;
            }
            catch (const std::exception &e)
            {
            }
        }

        std::cin.clear();
        std::cout << "Please provide a valid mode." << std::endl;
    }
}

std::string MenuUI::getUserCommand()
{
    std::string command;

    while (true)
    {
        if (std::cin >> command)
        {
            return command;
        }

        std::cin.clear();
        std::cout << "Please provide a valid command (see \"help\" for more): ";
    }
}

int MenuUI::getUserMovieId()
{
    int id;

    while (true)
    {

        std::cout << "Movie Id (int): ";
        if (std::cin >> id)
        {
            return id;
        }

        std::cin.clear();
        std::cout << "Please provide a valid Movie Id." << std::endl;
    }
}

std::string MenuUI::getUserMovieTitle()
{
    std::string title;

    while (true)
    {

        std::cout << "Movie Title (string): ";
        if (std::cin >> title)
        {
            return title;
        }

        std::cin.clear();
        std::cout << "Please provide a valid Movie Title." << std::endl;
    }
}

MovieGenre MenuUI::getUserMovieGenre()
{
    std::string rawGenre;

    while (true)
    {
        std::cout << "Movie Genre (genre, see \"genres\" for help): ";
        if (std::cin >> rawGenre)
        {
            try
            {
                MovieGenre genre = Helpers::convertGivenStringToMovieGenre(rawGenre);
                return genre;
            }
            catch (const std::exception &e)
            {
            }
        }

        std::cin.clear();
        std::cout << "Please provide a valid Movie genre." << std::endl;
    }
}

short MenuUI::getUserMovieYearOfRelease()
{
    short yor;

    while (true)
    {
        std::cout << "Movie Year of Release (short): ";
        if (std::cin >> yor && yor <= 2026 && yor >= 0)
        {
            return yor;
        }

        std::cin.clear();
        std::cout << "Please provide a valid year of release." << std::endl;
    }
}

int MenuUI::getUserMovieNumberOfLikes()
{
    int nbLikes;

    while (true)
    {
        std::cout << "Movie Number of Likes (int): ";
        if (std::cin >> nbLikes && nbLikes >= 0)
        {
            return nbLikes;
        }

        std::cin.clear();
        std::cout << "Please provide a valid number of likes." << std::endl;
    }
}

std::string MenuUI::getUserMovieTrailer()
{
    std::string trailer;

    while (true)
    {

        std::cout << "Movie Trailer (string): ";
        if (std::cin >> trailer)
        {
            return trailer;
        }

        std::cin.clear();
        std::cout << "Please provide a valid Movie Trailer." << std::endl;
    }
}

Movie MenuUI::getUserMovie()
{
    Movie movie;

    std::cout << "Movie: " << std::endl;
    movie.setTitle(this->getUserMovieTitle());
    movie.setGenre(this->getUserMovieGenre());
    movie.setYearOfRelease(this->getUserMovieYearOfRelease());
    movie.setNumberOfLikes(this->getUserMovieNumberOfLikes());
    movie.setTrailer(this->getUserMovieTrailer());

    return movie;
}

void MenuUI::start()
{
    Mode appMode = this->getUserMode();
    this->intro(appMode);
    MenuUIController controller = this->controller();

    while (true)
    {
        std::string command = this->getUserCommand();

        if (command == "movies" && appMode == ADMIN)
        {
            controller.displayMovies();
        }
        else if (command == "add" && appMode == ADMIN)
        {
            controller.addMovie();
        }
        else if (command == "remove" && appMode == ADMIN)
        {
            controller.deleteMovie();
        }
        else if (command == "update" && appMode == ADMIN)
        {
            controller.updateMovie();
        }
        else if (command == "genres")
        {
            this->genres();
        }
        else if (command == "help")
        {
            this->help(appMode);
        }
        else if (command == "exit")
        {
            std::cout << "???" << std::endl;
            exit(1);
        }
        else
        {
            std::cout << "invalid command, use help" << std::endl;
            continue;
        }
    }
}

MenuUIController MenuUI::controller()
{
    return MenuUIController(*this);
}
