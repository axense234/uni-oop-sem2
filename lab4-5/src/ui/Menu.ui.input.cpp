#include "Menu.ui.input.h"
#include "../helpers/Helpers.h"

#include <iostream>

MenuUIInput::MenuUIInput() {}

Mode MenuUIInput::getUserMode() const
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

std::string MenuUIInput::getUserCommand() const
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

bool MenuUIInput::getUserConfirmation() const
{
    char command;

    while (true)
    {
        std::cout << "Y/N: ";
        if (std::cin >> command && (command == 'Y' || command == 'N' || command == 'y' || command == 'n'))
        {
            if (command == 'Y' || command == 'y')
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        std::cin.clear();
        std::cout << "What?";
    }
}

int MenuUIInput::getUserMovieId() const
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

std::string MenuUIInput::getUserMovieTitle() const
{
    std::string title;

    while (true)
    {

        std::cout << "Movie Title (string): ";
        if (std::getline(std::cin, title) && !title.empty())
        {
            return title;
        }

        std::cin.clear();
        std::cout << "Please provide a valid Movie Title." << std::endl;
    }
}

MovieGenre MenuUIInput::getUserMovieGenre() const
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

short MenuUIInput::getUserMovieYearOfRelease() const
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

int MenuUIInput::getUserMovieNumberOfLikes() const
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

std::string MenuUIInput::getUserMovieTrailer() const
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

Movie MenuUIInput::getUserMovie() const
{
    Movie movie;

    std::cout << "MOVIE" << std::endl;
    movie.setTitle(this->getUserMovieTitle());
    movie.setGenre(this->getUserMovieGenre());
    movie.setYearOfRelease(this->getUserMovieYearOfRelease());
    movie.setNumberOfLikes(this->getUserMovieNumberOfLikes());
    movie.setTrailer(this->getUserMovieTrailer());

    return movie;
}