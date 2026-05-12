#include "Menu.gui.h"

#include "../helpers/Helpers.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenuBar>

MenuGUI::MenuGUI(const MenuUIInput &input, const MenuUIOutput &output, const std::string &repoType, MovieServices &playlist, MovieServices &database) : MenuUI(input, output, repoType, playlist, database), QMainWindow(nullptr)
{

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QMenuBar *menuBar = this->menuBar();

    // admin
    QMenu *adminMenu = menuBar->addMenu("&Admin");

    QAction *displayMoviesFromDatabaseAction = new QAction("&Display Movies from Database");
    QAction *addMovieToDatabaseAction = new QAction("&Add Movie to Database");
    QAction *deleteMovieFromDatabaseAction = new QAction("&Delete Movie from Database");
    QAction *updateMovieFromDatabaseAction = new QAction("&Update Movie from Database");
    QAction *displayMovieFromDatabaseAction = new QAction("&Display Movie from Database");

    adminMenu->addAction(displayMoviesFromDatabaseAction);
    adminMenu->addAction(addMovieToDatabaseAction);
    adminMenu->addAction(deleteMovieFromDatabaseAction);
    adminMenu->addAction(updateMovieFromDatabaseAction);
    adminMenu->addAction(displayMovieFromDatabaseAction);

    connect(displayMoviesFromDatabaseAction, &QAction::triggered, this, &MenuGUI::onDisplayMoviesFromDatabaseAction);

    // user
    QMenu *userMenu = menuBar->addMenu("&User");

    QAction *displayMoviesFromPlaylistAction = new QAction("&Display Movies from Playlist");
    QAction *deleteMovieFromPlaylistAction = new QAction("&Delete Movie from Playlist");
    QAction *handleUserPlaylistAction = new QAction("&Handle User Playlist");

    userMenu->addAction(displayMoviesFromPlaylistAction);
    userMenu->addAction(deleteMovieFromDatabaseAction);
    userMenu->addAction(handleUserPlaylistAction);

    // util
    QMenu *utilMenu = menuBar->addMenu("&Util");

    QAction *displayMovieGenresAction = new QAction("&Display Movie Genres");
    QAction *helpAction = new QAction("&Help");
    QAction *exitAction = new QAction("&Exit");

    utilMenu->addAction(displayMovieGenresAction);
    utilMenu->addAction(helpAction);
    utilMenu->addAction(exitAction);

    connect(exitAction, &QAction::triggered, this, &MenuGUI::onExitAction);

    // components
    this->layout = new QVBoxLayout(central);

    this->itemsList = new QListWidget(this);
    this->layout->addWidget(this->itemsList);
    this->itemsList->hide();

    // settings
    setWindowTitle("Movies App");
    resize(900, 450);
}

void MenuGUI::onDisplayMoviesFromDatabaseAction()
{
    this->itemsList->clear();
    this->itemsList->show();

    std::vector<TElem> movies = this->databaseServices.getElems();

    for (const Movie &movie : movies)
    {
        this->itemsList->addItem(movie.getQString());
    }
}

void MenuGUI::onAddMovieToDatabaseAction() {}

void MenuGUI::onDeleteMovieFromDatabaseAction() {}

void MenuGUI::onUpdateMovieFromDatabaseAction() {}

void MenuGUI::onDisplayMovieFromDatabaseAction() {}

void MenuGUI::onDisplayMoviesFromPlaylistAction() {}

void MenuGUI::onDeleteMovieFromPlaylistAction() {}

void MenuGUI::onHandleUserPlaylistAction() {}

void MenuGUI::onDisplayMovieGenresAction() {}

void MenuGUI::onHelpAction() {}

void MenuGUI::onExitAction()
{
    close();
}