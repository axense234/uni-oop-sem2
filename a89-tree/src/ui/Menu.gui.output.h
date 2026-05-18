#pragma once

#include "Menu.ui.h"

#include <string>

#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QDialog>
#include <QPushButton>

class MenuGUI;

class MenuGUIOutput
{
    friend class MenuGUI;

private:
    void genres() const;
    void help(Mode mode) const;

    QDialog *displayGivenMovie(const Movie &movie) const;
    void displayDatabaseMovies(std::vector<Movie>) const;
    void displayPlaylistMovies(std::vector<Movie>) const;
    void plotMovies(std::vector<Movie>) const;

    void displayResponse(const std::string &response) const;

public:
    MenuGUIOutput();
};