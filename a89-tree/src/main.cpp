#include <iostream>
#include <string>

#include <QtWidgets>

#include "exceptions/RepoException.h"

#include "repo/TextFile.repo.h"
#include "repo/CSV.repo.h"
#include "repo/HTML.repo.h"

#include "ui/Menu.gui.input.h"
#include "ui/Menu.gui.output.h"
#include "ui/Menu.gui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TextFileRepo *repoUsedForDatabase = nullptr;
    TextFileRepo *repoUsedForPlaylist = nullptr;

    std::string repoDir = "C:/Users/axense/Desktop/Coding/workspace/cpp/uni-oop-sem2/a89-tree/src/repo/data";
    std::string outputDir = "C:/Users/axense/Desktop/Coding/workspace/cpp/uni-oop-sem2/a89-tree/src/repo/output";

    std::cout << repoDir << std::endl;

    QStringList modes = {"CSV", "HTML"};
    QString selectedMode = QInputDialog::getItem(nullptr,
                                                 "Select Output Mode (CSV or HTML)",
                                                 "Choose output format:",
                                                 modes, 0, false);

    if (selectedMode.isEmpty())
    {
        return 0;
    }

    std::string outputMode = selectedMode.toStdString();

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
        return 1;
    }

    MovieServices databaseServices{*repoUsedForDatabase};
    MovieServices playlistServices{*repoUsedForPlaylist};

    MenuGUIInput input;
    MenuGUIOutput output;

    MenuGUI window(input, output, outputMode, playlistServices, databaseServices);
    window.show();

    int result = app.exec();

    delete repoUsedForDatabase;
    delete repoUsedForPlaylist;

    return result;
}