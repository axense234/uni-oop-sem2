#include <iostream>
#include <string>

#include "exceptions/RepoException.h"
#include "helpers/RepoOutput.h"
#include "repo/Repo.repo.h"
#include "repo/TextFile.repo.h"
#include "repo/CSV.repo.h"
#include "repo/HTML.repo.h"
#include "ui/Menu.ui.input.h"
#include "ui/Menu.ui.output.h"
#include "ui/Menu.ui.h"

int main()
{

    // Repo<Movie, int, MovieField> *repoUsedForDatabase = nullptr;
    // Repo<Movie, int, MovieField> *repoUsedForPlaylist = nullptr;

    TextFileRepo *repoUsedForDatabase = nullptr;
    TextFileRepo *repoUsedForPlaylist = nullptr;

    std::string outputMode;
    std::string outputDir = "src/repo/output";
    std::string repoDir = "src/repo/data";

    while (true)
    {
        std::cout << "Output Mode (CSV or HTML): ";
        if (std::cin >> outputMode)
        {
            if (outputMode == "CSV" || outputMode == "HTML")
            {
                break;
            }
        }

        std::cin.clear();
        std::cout << "CSV or HTML\n";
    }

    try
    {
        if (outputMode == "CSV")
        {
            repoUsedForDatabase = new CSVRepo{repoDir + "/movies.txt", outputDir + "/movies.csv"};
            repoUsedForPlaylist = new CSVRepo{repoDir + "/playlist.txt", outputDir + "/playlist.csv"};
        }
        else if (outputMode == "HTML")
        {
            repoUsedForDatabase = new HTMLRepo{repoDir + "/movies.txt", outputDir + "/movies.html"};
            repoUsedForPlaylist = new HTMLRepo{repoDir + "/playlist.txt", outputDir + "/playlist.html"};
        }
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << '\n';
    }

    MovieServices databaseServices{*repoUsedForDatabase};
    MovieServices playlistServices{*repoUsedForPlaylist};

    MenuUIInput input;
    MenuUIOutput output;

    MenuUI ui{input, output, outputMode, playlistServices, databaseServices};
    ui.start();

    delete repoUsedForDatabase;
    delete repoUsedForPlaylist;

    return 0;
}