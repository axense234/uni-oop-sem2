#pragma once

#include <QtWidgets>

#include <string>

#include "../domain/Movie.h"
#include "../services/Movie.services.h"
#include "Menu.ui.h"

class MenuUIInput;
class MenuUIOutput;

class MenuGUI : public QMainWindow, public MenuUI
{
    Q_OBJECT

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
    MenuGUI(const MenuUIInput &input, const MenuUIOutput &output, const std::string &repoType, MovieServices &playlist, MovieServices &database);
};