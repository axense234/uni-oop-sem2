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
    connect(deleteMovieFromDatabaseAction, &QAction::triggered, this, &MenuGUI::onDeleteMovieFromDatabaseAction);
    connect(updateMovieFromDatabaseAction, &QAction::triggered, this, &MenuGUI::onUpdateMovieFromDatabaseAction);
    connect(displayMovieFromDatabaseAction, &QAction::triggered, this, &MenuGUI::onDisplayMovieFromDatabaseAction);

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

    std::vector<Movie> movies = this->databaseServices.getElems();

    if (movies.size() <= 0)
    {
        // error window
    }
    else
    {
        this->output.displayDatabaseMovies(movies);
    }
}

void MenuGUI::onAddMovieToDatabaseAction()
{
    try
    {
        this->input.setWindowTitle("Add Movie to Database");
        Movie newMovie = this->input.getUserMovie();
        this->databaseServices.addMovie(newMovie);
    }
    catch (const std::exception &e)
    {
        std::cerr << "something went wrong during movie addition" << '\n';
    }
}

void MenuGUI::onDeleteMovieFromDatabaseAction()
{
    try
    {
        this->input.setWindowTitle("Delete Movie from Database");
        std::string movieTitle = this->input.getUserMovieTitle();

        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);

        this->databaseServices.removeMovieById(foundMovie.getId());
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "something went wrong during movie deletion" << '\n';
    }
}

void MenuGUI::onUpdateMovieFromDatabaseAction()
{
    try
    {
        this->input.setWindowTitle("Update Movie from Database | Movie Title");
        std::string movieTitle = this->input.getUserMovieTitle();

        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);

        this->input.setWindowTitle("Update Movie From Database | Payload");
        Movie newMovie = this->input.getUserMovie();

        this->databaseServices.updateMovieById(foundMovie.getId(), newMovie);
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "something went wrong during movie update" << '\n';
    }
}

void MenuGUI::onDisplayMovieFromDatabaseAction()
{
    this->itemsList->clear();
    this->itemsList->show();

    try
    {
        this->input.setWindowTitle("Display Movie from Database | Movie Title");
        std::string movieTitle = this->input.getUserMovieTitle();

        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);

        this->output.displayGivenMovie(foundMovie);
    }
    catch (const RepoException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "something went wrong during movie update" << '\n';
    }
}

void MenuGUI::onDisplayMoviesFromPlaylistAction()
{
    std::vector<Movie> movies = this->playlistServices.getElems();

    if (movies.size() <= 0)
    {
        // error window
    }
    else
    {
        this->output.displayPlaylistMovies(movies);
    }
}

void MenuGUI::onDeleteMovieFromPlaylistAction() {}

void MenuGUI::onHandleUserPlaylistAction() {}

void MenuGUI::onDisplayMovieGenresAction()
{
    this->output.genres();
}

void MenuGUI::onHelpAction()
{
    this->output.help(this->mode);
}

void MenuGUI::onExitAction()
{
    close();
}