#include "Menu.gui.output.h"
#include "Menu.gui.input.h"
#include "Menu.gui.h"

#include "../helpers/Helpers.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenuBar>

#include <iostream>
#include <string>

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
    QAction *displayMoviesFromPlaylistExternalAction = new QAction("&Display Movies from Playlist Externally");
    QAction *deleteMovieFromPlaylistAction = new QAction("&Delete Movie from Playlist");
    QAction *handleUserPlaylistAction = new QAction("&Handle User Playlist");
    QAction *plotMoviesFromDatabaseAction = new QAction("&Plot Database Movies");
    QAction *plotMoviesFromPlaylistAction = new QAction("&Plot Playlist Movies");

    userMenu->addAction(displayMoviesFromPlaylistAction);
    userMenu->addAction(displayMoviesFromPlaylistExternalAction);
    userMenu->addAction(deleteMovieFromPlaylistAction);
    userMenu->addAction(handleUserPlaylistAction);
    userMenu->addAction(plotMoviesFromDatabaseAction);
    userMenu->addAction(plotMoviesFromPlaylistAction);

    connect(displayMoviesFromPlaylistAction, &QAction::triggered, this, &MenuGUI::onDisplayMoviesFromPlaylistAction);
    connect(displayMoviesFromPlaylistExternalAction, &QAction::triggered, this, &MenuGUI::onDisplayMoviesFromPlaylistExternalAction);
    connect(deleteMovieFromPlaylistAction, &QAction::triggered, this, &MenuGUI::onDeleteMovieFromPlaylistAction);
    connect(handleUserPlaylistAction, &QAction::triggered, this, &MenuGUI::onHandleUserPlaylistAction);
    connect(plotMoviesFromDatabaseAction, &QAction::triggered, this, &MenuGUI::onPlotMoviesFromDatabaseAction);
    connect(plotMoviesFromPlaylistAction, &QAction::triggered, this, &MenuGUI::onPlotMoviesFromPlaylistAction);

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

    // intro
    this->intro();

    // settings
    setWindowTitle("Movies App");
}

void MenuGUI::onDisplayMoviesFromDatabaseAction()
{

    std::vector<Movie> movies = this->databaseServices.getElems();

    if (movies.size() <= 0)
    {
        this->output.displayResponse("No movies in database to display.");
    }
    else
    {
        this->output.displayDatabaseMovies(movies);
    }
}

void MenuGUI::onPlotMoviesFromDatabaseAction()
{

    std::vector<Movie> movies = this->databaseServices.getElems();

    if (movies.size() <= 0)
    {
        this->output.displayResponse("No movies in database to display.");
    }
    else
    {
        this->output.plotMovies(movies);
    }
}

void MenuGUI::onPlotMoviesFromPlaylistAction()
{

    std::vector<Movie> movies = this->playlistServices.getElems();

    if (movies.size() <= 0)
    {
        this->output.displayResponse("No movies in database to display.");
    }
    else
    {
        this->output.plotMovies(movies);
    }
}

void MenuGUI::onAddMovieToDatabaseAction()
{
    try
    {
        this->input.setWindowTitle("Add Movie to Database");
        Movie newMovie = this->input.getUserMovie();
        this->databaseServices.addMovie(newMovie);
        this->output.displayResponse("Successfully added movie.");
    }
    catch (const MovieServicesException &e)
    {
        this->output.displayResponse(std::string(e.what()));
    }
    catch (const RepoException &e)
    {
        this->output.displayResponse(std::string(e.what()));
    }
    catch (const MenuGUIException &e)
    {
        this->input.close();
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

        this->output.displayResponse("Successfully deleted movie.");
    }
    catch (const RepoException &e)
    {
        this->output.displayResponse(std::string(e.what()));
    }
    catch (const MenuGUIException &e)
    {
        this->input.close();
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

        this->output.displayResponse("Successfully updated movie.");
    }
    catch (const RepoException &e)
    {
        this->output.displayResponse(std::string(e.what()));
    }
    catch (const MenuGUIException &e)
    {
        this->input.close();
    }
}

void MenuGUI::onDisplayMovieFromDatabaseAction()
{
    try
    {
        this->input.setWindowTitle("Display Movie from Database | Movie Title");
        std::string movieTitle = this->input.getUserMovieTitle();

        Movie foundMovie = this->databaseServices.getMovieByTitle(movieTitle);

        this->output.displayGivenMovie(foundMovie);
    }
    catch (const RepoException &e)
    {
        this->output.displayResponse(std::string(e.what()));
    }
    catch (const MenuGUIException &e)
    {
        this->input.close();
    }
}

void MenuGUI::onDisplayMoviesFromPlaylistAction()
{
    std::vector<Movie> movies = this->playlistServices.getElems();

    if (movies.size() <= 0)
    {
        this->output.displayResponse("No movies in playlist to display.");
    }
    else
    {
        this->output.displayPlaylistMovies(movies);
    }
}

void MenuGUI::onDeleteMovieFromPlaylistAction()
{
    try
    {
        this->input.setWindowTitle("Delete Movie from Playlist");
        std::string movieTitle = this->input.getUserMovieTitle();

        Movie foundMovie = this->playlistServices.getMovieByTitle(movieTitle);

        this->playlistServices.removeMovieById(foundMovie.getId());

        this->output.displayResponse("Successfully deleted movie from playlist.");
    }
    catch (const RepoException &e)
    {
        this->output.displayResponse(std::string(e.what()));
    }
    catch (const MenuGUIException &e)
    {
        this->input.close();
    }
}

void MenuGUI::onHandleUserPlaylistAction()
{
    try
    {
        this->input.setWindowTitle("Playlist Scroll | Movie Genre");
        MovieGenre movieGenre = this->input.getUserMovieGenre();

        std::vector<TElem> filteredMovies = this->databaseServices.filterMoviesByGenre(movieGenre);

        if (filteredMovies.size() == 0)
        {
            this->output.displayResponse("No movies in database to display.");
            return;
        }

        auto currentIt = filteredMovies.begin();

        while (true)
        {
            // circular thingie
            if (currentIt == filteredMovies.end())
            {
                currentIt = filteredMovies.begin();
            }

            Movie currentMovie = *currentIt;

            // display the current movie, this time through a gui window
            QDialog *movieWindow = this->output.displayGivenMovie(currentMovie);

            // open the movie url in the browser
            Helpers::openURL(currentMovie.getTrailer());

            // user confirmation
            this->input.setWindowTitle("Playlist Scroll | Add Movie");
            bool confirmation = this->input.getUserConfirmation("Add Movie to the Playlist?");

            if (confirmation)
            {
                try
                {
                    this->playlistServices.addMovie(currentMovie, true);
                    currentIt++;

                    this->output.displayResponse("Successfully added movie to playlist.");
                }
                catch (const MovieServicesException &e)
                {
                    this->output.displayResponse(std::string(e.what()));
                }
                catch (const RepoException &e)
                {
                    this->output.displayResponse(std::string(e.what()));
                }
                movieWindow->close();
            }
            else
            {
                // the user can either stop scrolling or move on to the next movie
                this->input.setWindowTitle("Playlist Scroll | Continue Confirmation");
                bool continueConfirmation = this->input.getUserConfirmation("Next?");

                if (!continueConfirmation)
                {
                    movieWindow->close();
                    break;
                }

                currentIt++;
                movieWindow->close();
            }
        }
    }
    catch (const std::exception &e)
    {
        // i forgot whyh i put this here and i wont bother removing it
        std::cerr << e.what() << '\n';
    }
}

void MenuGUI::onDisplayMovieGenresAction()
{
    this->output.genres();
}

void MenuGUI::onHelpAction()
{
    this->output.help(this->mode);
}

void MenuGUI::onDisplayMoviesFromPlaylistExternalAction()
{
    std::vector<Movie> movies = this->playlistServices.getElems();

    if (this->repoUsed == "CSV")
    {
        Helpers::openFileInNotepad(this->playlistServices.repo.getOutputFilePath());
    }
    else if (this->repoUsed == "HTML")
    {
        Helpers::openFileInBrowser(this->playlistServices.repo.getOutputFilePath());
    }
}

void MenuGUI::onExitAction()
{
    close();
}

void MenuGUI::addButton(const QString &buttonText, const MenuGUI *receiver, void (MenuGUI::*method)())
{
    QPushButton *button = new QPushButton(buttonText);
    button->setFixedWidth(button->sizeHint().width());
    this->layout->addStretch();
    this->layout->addWidget(button);
    this->layout->addStretch();
    QObject::connect(button, &QPushButton::clicked, receiver, method);
}

void MenuGUI::intro()
{
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(0.8 * 16);

    QLabel *label = new QLabel("Movies Application GUI");
    label->setFont(QFont("Arial", 16, QFont::Bold));
    layout->addWidget(label);

    if (mode == ADMIN)
    {

        QLabel *adminTitleLabel = new QLabel("Admin Only Commands");
        adminTitleLabel->setFont(QFont("Arial", 16, QFont::Bold));
        layout->addWidget(adminTitleLabel);

        addButton("movies", this, &MenuGUI::onDisplayMoviesFromDatabaseAction);
        addButton("add", this, &MenuGUI::onAddMovieToDatabaseAction);
        addButton("remove", this, &MenuGUI::onDeleteMovieFromDatabaseAction);
        addButton("update", this, &MenuGUI::onUpdateMovieFromDatabaseAction);
        addButton("find", this, &MenuGUI::onDisplayMovieFromDatabaseAction);
    }

    QLabel *userTitlelabel = new QLabel("User Only Commands");
    userTitlelabel->setFont(QFont("Arial", 16, QFont::Bold));
    layout->addWidget(userTitlelabel);

    addButton("playlist", this, &MenuGUI::onDisplayMoviesFromPlaylistAction);
    addButton("playlist-external", this, &MenuGUI::onDisplayMoviesFromPlaylistExternalAction);
    addButton("playlist-delete", this, &MenuGUI::onDeleteMovieFromPlaylistAction);
    addButton("scroll", this, &MenuGUI::onHandleUserPlaylistAction);
    addButton("plot-database", this, &MenuGUI::onPlotMoviesFromDatabaseAction);
    addButton("plot-playlist", this, &MenuGUI::onPlotMoviesFromPlaylistAction);

    QLabel *utilComands = new QLabel("Utility Commands");
    utilComands->setFont(QFont("Arial", 16, QFont::Bold));
    layout->addWidget(utilComands);

    addButton("genres", this, &MenuGUI::onDisplayMovieGenresAction);
    addButton("help", this, &MenuGUI::onHelpAction);
    addButton("exit", this, &MenuGUI::onExitAction);
}