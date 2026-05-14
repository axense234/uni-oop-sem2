#pragma once

#include <QtWidgets>

#include <string>

#include "../domain/Movie.h"
#include "../services/Movie.services.h"

#include "Mode.h"
#include "Menu.gui.h"

class MenuGUIInput;
class MenuGUIOutput;

class MenuGUI : public QMainWindow
{
    Q_OBJECT

private:
    Mode mode;

    MenuGUIInput &input;
    const MenuGUIOutput &output;
    const std::string &repoUsed;

    MovieServices &playlistServices;
    MovieServices &databaseServices;

private slots:
    void onDisplayMoviesFromDatabaseAction();
    void onAddMovieToDatabaseAction();
    void onDeleteMovieFromDatabaseAction();
    void onUpdateMovieFromDatabaseAction();
    void onDisplayMovieFromDatabaseAction();

    void onDisplayMoviesFromPlaylistAction();
    void onDeleteMovieFromPlaylistAction();
    void onHandleUserPlaylistAction();

    void onDisplayMovieGenresAction();
    void onHelpAction();
    void onExitAction();

public:
    QVBoxLayout *layout;
    QListWidget *itemsList;

    /**
     * @brief Constructor.
     *
     * @param parent
     */
    MenuGUI(MenuGUIInput &input, const MenuGUIOutput &output, const std::string &repoType, MovieServices &playlist, MovieServices &database);
};