#include <iostream>
#include <string>

#include "repo/Repo.repo.h"
#include "repo/TextFile.repo.h"
#include "ui/Menu.ui.input.h"
#include "ui/Menu.ui.output.h"
#include "ui/Menu.ui.h"

int main(int argc, char *argv[])
{

    // argv[1] == repo used, ex: memory, textfile
    // argv[2] == location, ex: src/repo/data

    if (argc > 1 && argv[1] && argv[2])
    {
        std::cout << "Everything looks good." << std::endl;
    }
    else
    {
        std::cout << "Arguments are bad." << std::endl;
        return 1;
    }

    Repo<Movie, int, MovieField> *repoUsedForDatabase = nullptr;
    Repo<Movie, int, MovieField> *repoUsedForPlaylist = nullptr;

    std::string repoType = argv[1];
    std::string repoDir = argv[2];

    if (repoType == "memory")
    {
        repoUsedForDatabase = new MemoryRepo{};
        repoUsedForPlaylist = new MemoryRepo{};
    }
    else if (repoType == "textfile")
    {
        repoUsedForDatabase = new TextFileRepo{repoDir + "/movies.txt"};
        repoUsedForPlaylist = new TextFileRepo{repoDir + "/playlist.txt"};
    }
    else
    {
        std::cout << "Invalid repo type: " << repoType << std::endl;
        return 1;
    }

    MovieServices databaseServices{*repoUsedForDatabase};
    MovieServices playlistServices{*repoUsedForPlaylist};

    MenuUIInput input;
    MenuUIOutput output;

    MenuUI ui{input, output, playlistServices, databaseServices};
    ui.start();

    delete repoUsedForDatabase;
    delete repoUsedForPlaylist;

    return 0;
}