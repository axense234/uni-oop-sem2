#include <iostream>
#include <string>

#include "ui/Menu.ui.input.h"
#include "ui/Menu.ui.output.h"
#include "ui/Menu.ui.h"
#include "repo/TextFile.repo.h"

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        std::cout << "Everything looks good." << std::endl;
    }
    else
    {
        std::cout << "Arguments are bad." << std::endl;
        return 1;
    }

    // let argv[2] be a directory where data is stored
    std::string dir = argv[2];

    TextFileRepo database{dir + "/movies.txt"};
    MovieServices databaseServices{database};

    TextFileRepo playlist{dir + "/playlist.txt"};
    MovieServices playlistServices{playlist};

    MenuUIInput input;
    MenuUIOutput output;

    MenuUI ui{input, output, playlistServices, databaseServices};
    ui.start();

    return 0;
}