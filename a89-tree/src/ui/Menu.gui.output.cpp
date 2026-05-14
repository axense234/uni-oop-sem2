#include "Menu.gui.output.h"

#include "../helpers/Helpers.h"

MenuGUIOutput::MenuGUIOutput() {}

void MenuGUIOutput::genres() const
{
    QDialog *newWindow = new QDialog(nullptr);
    newWindow->resize(400, 300);
    QListWidget *list = new QListWidget(newWindow);
    QVBoxLayout *layout = new QVBoxLayout(newWindow);
    layout->addWidget(list);
    newWindow->setWindowTitle("Movie Genres");
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    QListWidgetItem *genresTitle = new QListWidgetItem();
    genresTitle->setText("Possible Movie Genres");
    genresTitle->setFont(QFont("Arial", 16, QFont::Bold));
    list->addItem(genresTitle);

    std::vector<MovieGenre> genres = {
        ACTION,
        ADVENTURE,
        ANIMATION,
        BIOGRAPHY,
        COMEDY,
        CRIME,
        DOCUMENTARY,
        DRAMA,
        FAMILY,
        FANTASY,
        HISTORY,
        HORROR,
        MUSIC,
        MYSTERY,
        ROMANCE,
        SCIFI,
        SPORT,
        WAR,
        WESTERN};

    for (const MovieGenre &genre : genres)
    {
        list->addItem((Helpers::convertGivenMovieGenreToString(genre)).c_str());
    }

    int optimalWidth = list->sizeHintForColumn(0) + 50;
    int optimalHeight = list->sizeHintForRow(0) * list->count();
    newWindow->resize(optimalWidth, optimalHeight);
    newWindow->show();
}

void MenuGUIOutput::intro(QListWidget *itemsList, Mode mode) const
{

    itemsList->clear();
    itemsList->show();

    QListWidgetItem *introTitle = new QListWidgetItem();
    introTitle->setText("Movies Application GUI");
    introTitle->setFont(QFont("Arial", 16, QFont::Bold));
    itemsList->addItem(introTitle);

    QListWidgetItem *ctaTitle = new QListWidgetItem();
    ctaTitle->setText("access the navigation bar commands");
    ctaTitle->setFont(QFont("Arial", 14, QFont::Bold));
    itemsList->addItem(ctaTitle);

    QListWidgetItem *helpTitle = new QListWidgetItem();
    helpTitle->setText("use the help command from the Util section for help");
    helpTitle->setFont(QFont("Arial", 14, QFont::Bold));
    itemsList->addItem(helpTitle);
}

void MenuGUIOutput::help(Mode mode) const
{

    QDialog *newWindow = new QDialog(nullptr);
    newWindow->resize(400, 300);
    QListWidget *list = new QListWidget(newWindow);
    QVBoxLayout *layout = new QVBoxLayout(newWindow);
    layout->addWidget(list);
    newWindow->setWindowTitle("Help");
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    if (mode == ADMIN)
    {
        QListWidgetItem *adminCommandsTitle = new QListWidgetItem();
        adminCommandsTitle->setText("Admin Only Commands");
        adminCommandsTitle->setFont(QFont("Arial", 14, QFont::Bold));
        list->addItem(adminCommandsTitle);

        list->addItem(QString("%1 = %2").arg("movies").arg("Displays all the Movies in the database."));
        list->addItem(QString("%1 = %2").arg("add").arg("Adds a given Movie to the database."));
        list->addItem(QString("%1 = %2").arg("remove").arg("Removes a Movie from the database using an id."));
        list->addItem(QString("%1 = %2").arg("update").arg("Updates a Movie from the database by id, using a payload."));
        list->addItem(QString("%1 = %2").arg("find").arg("Finds a Movie from the database by id and displays it."));
    }

    QListWidgetItem *userCommandsTitle = new QListWidgetItem();
    userCommandsTitle->setText("User Commands");
    userCommandsTitle->setFont(QFont("Arial", 14, QFont::Bold));
    list->addItem(userCommandsTitle);

    list->addItem(QString("%1 = %2").arg("playlist").arg("Displays all the Movies in the user's playlist."));
    list->addItem(QString("%1 = %2").arg("playlist-external").arg("Displays all the Movies in the user's playlist externally depending on the chosen output type."));
    list->addItem(QString("%1 = %2").arg("playlist-delete").arg("Removes a Movie from the user playlist using a movie name."));
    list->addItem(QString("%1 = %2").arg("scroll").arg("Scrolls through the Movies of the Database allowing the user to add a certain movie to the playlist if they desire so."));

    QListWidgetItem *utilCommandsTitle = new QListWidgetItem();
    utilCommandsTitle->setText("Util Commands");
    utilCommandsTitle->setFont(QFont("Arial", 14, QFont::Bold));
    list->addItem(utilCommandsTitle);

    list->addItem(QString("%1 = %2").arg("genres").arg("Displays the possible movie genre values."));
    list->addItem(QString("%1 = %2").arg("help").arg("Helps a random person in the world. Be careful."));
    list->addItem(QString("%1 = %2").arg("exit").arg("Exits the program."));

    int optimalWidth = list->sizeHintForColumn(0) + 50;
    int optimalHeight = list->sizeHintForRow(0) * list->count() + 50;
    newWindow->resize(optimalWidth, optimalHeight);
    newWindow->show();
}

void MenuGUIOutput::displayGivenMovie(const Movie &movie) const
{
    QDialog *newWindow = new QDialog(nullptr);
    newWindow->resize(400, 300);
    QListWidget *list = new QListWidget(newWindow);
    QVBoxLayout *layout = new QVBoxLayout(newWindow);
    layout->addWidget(list);
    newWindow->setWindowTitle(QString::fromStdString(movie.getTitle()));
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    QListWidgetItem *movieTitle = new QListWidgetItem();
    movieTitle->setText(QString::fromStdString(movie.getTitle()));
    movieTitle->setFont(QFont("Arial", 16, QFont::Bold));
    list->addItem(movieTitle);

    QListWidgetItem *movieGenre = new QListWidgetItem();
    movieGenre->setText(QString::fromStdString(Helpers::convertGivenMovieGenreToString(movie.getGenre())));
    movieGenre->setFont(QFont("Arial", 14));
    list->addItem(movieGenre);

    QListWidgetItem *movieYOR = new QListWidgetItem();
    movieYOR->setText(QString::fromStdString(std::to_string(movie.getYearOfRelease())));
    movieYOR->setFont(QFont("Arial", 14));
    list->addItem(movieYOR);

    QListWidgetItem *movieNbLikes = new QListWidgetItem();
    movieNbLikes->setText(QString::fromStdString(std::to_string(movie.getNumberOfLikes())));
    movieNbLikes->setFont(QFont("Arial", 14));
    list->addItem(movieNbLikes);

    QListWidgetItem *movieTrailer = new QListWidgetItem();
    movieTrailer->setText(QString::fromStdString(movie.getTrailer()));
    movieTrailer->setFont(QFont("Arial", 14));
    list->addItem(movieTrailer);

    int optimalWidth = list->sizeHintForColumn(0) + 50;
    int optimalHeight = list->sizeHintForRow(0) * list->count() + 50;
    newWindow->resize(optimalWidth, optimalHeight);
    newWindow->show();
}

void MenuGUIOutput::displayDatabaseMovies(std::vector<Movie> movies) const
{
    QDialog *newWindow = new QDialog(nullptr);
    newWindow->resize(600, 400);
    QListWidget *list = new QListWidget(newWindow);
    QVBoxLayout *layout = new QVBoxLayout(newWindow);
    layout->addWidget(list);
    newWindow->setWindowTitle("Database Movies");
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    for (const Movie &movie : movies)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(movie.getQString());
        item->setFont(QFont("Arial", 12));
        list->addItem(item);
    }

    int optimalWidth = list->sizeHintForColumn(0) + 50;
    int optimalHeight = list->sizeHintForRow(0) * list->count() + 50;
    newWindow->resize(optimalWidth, optimalHeight);
    newWindow->show();
}

void MenuGUIOutput::displayPlaylistMovies(std::vector<Movie> movies) const
{
    QDialog *newWindow = new QDialog(nullptr);
    newWindow->resize(600, 400);
    QListWidget *list = new QListWidget(newWindow);
    QVBoxLayout *layout = new QVBoxLayout(newWindow);
    layout->addWidget(list);
    newWindow->setWindowTitle("Playlist Movies");
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    for (const Movie &movie : movies)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(movie.getQString());
        item->setFont(QFont("Arial", 12));
        list->addItem(item);
    }

    int optimalWidth = list->sizeHintForColumn(0) + 50;
    int optimalHeight = list->sizeHintForRow(0) * list->count() + 50;
    newWindow->resize(optimalWidth, optimalHeight);
    newWindow->show();
}