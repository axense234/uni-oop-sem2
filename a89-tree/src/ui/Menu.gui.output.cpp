#include "Menu.gui.output.h"

#include "../helpers/Helpers.h"

MenuGUIOutput::MenuGUIOutput() {}

void MenuGUIOutput::genres(QListWidget *itemsList) const
{
    try
    {
        itemsList->clear();
        itemsList->show();

        QListWidgetItem *genresTitle = new QListWidgetItem();
        genresTitle->setText("Possible Movie Genres");
        genresTitle->setFont(QFont("Arial", 16, QFont::Bold));
        itemsList->addItem(genresTitle);

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
            WESTERN,
            EMPTY};

        for (const MovieGenre &genre : genres)
        {
            itemsList->addItem(Helpers::convertGivenMovieGenreToString(genre).c_str());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
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

void MenuGUIOutput::help(QListWidget *itemsList, Mode mode) const
{

    itemsList->clear();
    itemsList->show();

    if (mode == ADMIN)
    {
        QListWidgetItem *adminCommandsTitle = new QListWidgetItem();
        adminCommandsTitle->setText("Admin Only Commands");
        adminCommandsTitle->setFont(QFont("Arial", 14, QFont::Bold));
        itemsList->addItem(adminCommandsTitle);

        itemsList->addItem(QString("%1 = %2").arg("movies").arg("Displays all the Movies in the database."));
        itemsList->addItem(QString("%1 = %2").arg("add").arg("Adds a given Movie to the database."));
        itemsList->addItem(QString("%1 = %2").arg("remove").arg("Removes a Movie from the database using an id."));
        itemsList->addItem(QString("%1 = %2").arg("update").arg("Updates a Movie from the database by id, using a payload."));
        itemsList->addItem(QString("%1 = %2").arg("find").arg("Finds a Movie from the database by id and displays it."));
    }

    QListWidgetItem *userCommandsTitle = new QListWidgetItem();
    userCommandsTitle->setText("User Commands");
    userCommandsTitle->setFont(QFont("Arial", 14, QFont::Bold));
    itemsList->addItem(userCommandsTitle);

    itemsList->addItem(QString("%1 = %2").arg("playlist").arg("Displays all the Movies in the user's playlist."));
    itemsList->addItem(QString("%1 = %2").arg("playlist-external").arg("Displays all the Movies in the user's playlist externally depending on the chosen output type."));
    itemsList->addItem(QString("%1 = %2").arg("playlist-delete").arg("Removes a Movie from the user playlist using a movie name."));
    itemsList->addItem(QString("%1 = %2").arg("scroll").arg("Scrolls through the Movies of the Database allowing the user to add a certain movie to the playlist if they desire so."));

    QListWidgetItem *utilCommandsTitle = new QListWidgetItem();
    utilCommandsTitle->setText("Util Commands");
    utilCommandsTitle->setFont(QFont("Arial", 14, QFont::Bold));
    itemsList->addItem(utilCommandsTitle);

    itemsList->addItem(QString("%1 = %2").arg("genres").arg("Displays the possible movie genre values."));
    itemsList->addItem(QString("%1 = %2").arg("help").arg("Helps a random person in the world. Be careful."));
    itemsList->addItem(QString("%1 = %2").arg("exit").arg("Exits the program."));
}
