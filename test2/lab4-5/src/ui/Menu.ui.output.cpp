#include "Menu.ui.output.h"

#include <iostream>

MenuUIOutput::MenuUIOutput() {}

void MenuUIOutput::genres() const
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

void MenuUIOutput::intro(Mode mode) const
{
    std::cout << std::endl;
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

void MenuUIOutput::help(Mode mode) const
{
    if (mode == ADMIN)
    {
        std::cout << "admin only commands" << std::endl;
        std::cout << "=======================================" << std::endl;
        std::cout << "movies: Displays all the Movies in the database" << std::endl;
        std::cout << "add: Adds a given Movie to the database" << std::endl;
        std::cout << "remove: Removes a Movie from the database using an id." << std::endl;
        std::cout << "update: Updates a Movie from the database by id, using a payload" << std::endl;
        std::cout << "find: Finds a Movie from the database by id and displays it." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "user commands" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "playlist: Displays all the Movies in the user's playlist." << std::endl;
    std::cout << "playlist-delete: Removes a Movie from the user playlist using a movie name." << std::endl;
    std::cout << "scroll: Scrolls through the Movies of the Database allowing the user to add a certain movie to the playlist if they desire so." << std::endl;

    std::cout << std::endl;
    std::cout << "public commands" << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << "genres: Displays the possible movie genre values." << std::endl;
    std::cout << "help: Helps a random person in the world. Be careful." << std::endl;
    std::cout << "exit: Exits the program. Or does it?" << std::endl;

    std::cout << std::endl;
}
