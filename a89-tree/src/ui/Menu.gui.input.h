#pragma once

#include <QtWidgets>

#include "../domain/Movie.h"

#include "Menu.gui.h"

#include <string>

class MenuGUI;

class MenuGUIInput : public QDialog
{
    Q_OBJECT
    friend class MenuGUI;

public:
    MenuGUIInput();

    std::string getMovieTitle() { return this->movieTitle; }
    MovieGenre getMovieGenre() { return this->movieGenre; }
    short getMovieYearOfRelease() { return this->movieYearOfRelease; }
    int getMovieNumberOfLikes() { return this->movieNumberOfLikes; }
    std::string getMovieTrailer() { return this->movieTrailer; }

private slots:
    void onClose();

    void onGetUserMovieSuccess();

private:
    std::string getUserCommand() const;
    bool getUserConfirmation() const;
    std::string getUserMovieTitle() const;
    MovieGenre getUserMovieGenre() const;
    Mode getUserMode() const;
    Movie getUserMovie();

private:
    void clearLayout();

    QVBoxLayout *layout;

    QLineEdit *movieTitleFormControl;
    std::string movieTitle;

    QLineEdit *movieGenreFormControl;
    MovieGenre movieGenre;

    QLineEdit *movieYearOfReleaseFormControl;
    short movieYearOfRelease;

    QLineEdit *movieNumberOfLikesFormControl;
    int movieNumberOfLikes;

    QLineEdit *movieTrailerFormControl;
    std::string movieTrailer;

    QPushButton *okButton;
    QPushButton *cancelButton;
};