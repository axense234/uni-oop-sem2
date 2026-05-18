#pragma once

#include <QtWidgets>

#include <string>
#include <functional>

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

    void addButton(const QString &buttonText, const MenuGUI *receiver, void (MenuGUI::*method)());
    void intro();

private slots:
    void onDisplayMoviesFromDatabaseAction();
    void onAddMovieToDatabaseAction();
    void onDeleteMovieFromDatabaseAction();
    void onUpdateMovieFromDatabaseAction();
    void onDisplayMovieFromDatabaseAction();

    void onDisplayMoviesFromPlaylistAction();
    void onDisplayMoviesFromPlaylistExternalAction();
    void onDeleteMovieFromPlaylistAction();
    void onHandleUserPlaylistAction();

    void onPlotMoviesFromDatabaseAction();
    void onPlotMoviesFromPlaylistAction();

    void onDisplayMovieGenresAction();
    void onHelpAction();
    void onExitAction();

public:
    QVBoxLayout *layout;

    /**
     * @brief Constructor.
     *
     * @param parent
     */
    MenuGUI(MenuGUIInput &input, const MenuGUIOutput &output, const std::string &repoType, MovieServices &playlist, MovieServices &database);
};