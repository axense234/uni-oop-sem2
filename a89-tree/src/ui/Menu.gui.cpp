#include "Menu.gui.output.h"
#include "Menu.gui.input.h"
#include "Menu.gui.h"

#include "../helpers/Helpers.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenuBar>

MenuGUI::MenuGUI(MenuGUIInput &input, const MenuGUIOutput &output, const std::string &repoType, MovieServices &playlist, MovieServices &database) : input(input), output(output), repoUsed(repoType), playlistServices(playlist), databaseServices(database)
{
    this->mode = ADMIN;

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
    connect(addMovieToDatabaseAction, &QAction::triggered, this, &MenuGUI::onAddMovieToDatabaseAction);

    // user
    QMenu *userMenu = menuBar->addMenu("&User");

    QAction *displayMoviesFromPlaylistAction = new QAction("&Display Movies from Playlist");
    QAction *deleteMovieFromPlaylistAction = new QAction("&Delete Movie from Playlist");
    QAction *handleUserPlaylistAction = new QAction("&Handle User Playlist");

    userMenu->addAction(displayMoviesFromPlaylistAction);
    userMenu->addAction(deleteMovieFromPlaylistAction);
    userMenu->addAction(handleUserPlaylistAction);

    connect(displayMoviesFromPlaylistAction, &QAction::triggered, this, &MenuGUI::onDisplayMoviesFromPlaylistAction);

    // util
    QMenu *utilMenu = menuBar->addMenu("&Util");

    QAction *displayMovieGenresAction = new QAction("&Display Movie Genres");
    QAction *helpAction = new QAction("&Help");
    QAction *exitAction = new QAction("&Exit");

    utilMenu->addAction(displayMovieGenresAction);
    utilMenu->addAction(helpAction);
    utilMenu->addAction(exitAction);

    connect(displayMovieGenresAction, &QAction::triggered, this, &MenuGUI::onDisplayMovieGenresAction);
    connect(helpAction, &QAction::triggered, this, &MenuGUI::onHelpAction);
    connect(exitAction, &QAction::triggered, this, &MenuGUI::onExitAction);

    // components
    this->layout = new QVBoxLayout(central);

    this->itemsList = new QListWidget(this);
    this->layout->addWidget(this->itemsList);
    this->itemsList->hide();

    // intro
    this->output.intro(this->itemsList, this->mode);

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

void MenuGUI::onAddMovieToDatabaseAction()
{
    try
    {
        Movie newMovie = this->input.getUserMovie();
        this->databaseServices.addMovie(newMovie);
    }
    catch (const std::exception &e)
    {
        std::cerr << "error somewhere" << '\n';
    }
}

void MenuGUI::onDeleteMovieFromDatabaseAction() {}

void MenuGUI::onUpdateMovieFromDatabaseAction() {}

void MenuGUI::onDisplayMovieFromDatabaseAction() {}

void MenuGUI::onDisplayMoviesFromPlaylistAction()
{
    this->itemsList->clear();
    this->itemsList->show();

    std::vector<TElem> movies = this->playlistServices.getElems();

    for (const Movie &movie : movies)
    {
        this->itemsList->addItem(movie.getQString());
    }
}

void MenuGUI::onDeleteMovieFromPlaylistAction() {}

void MenuGUI::onHandleUserPlaylistAction() {}

void MenuGUI::onDisplayMovieGenresAction()
{
    this->output.genres(this->itemsList);
}

void MenuGUI::onHelpAction()
{
    this->output.help(this->itemsList, this->mode);
}

void MenuGUI::onExitAction()
{
    close();
}