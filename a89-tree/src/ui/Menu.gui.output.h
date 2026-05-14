#pragma once

#include "Menu.ui.h"

#include <string>

#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QDialog>

class MenuGUI;

class MenuGUIOutput
{
    friend class MenuGUI;

private:
    void genres() const;
    void intro(QListWidget *itemsList, Mode mode) const;
    void help(Mode mode) const;

    void displayGivenMovie(const Movie &movie) const;
    void displayDatabaseMovies(std::vector<Movie>) const;
    void displayPlaylistMovies(std::vector<Movie>) const;

public:
    MenuGUIOutput();
};