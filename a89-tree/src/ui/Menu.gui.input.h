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
    void onGetUserMovieTitleSuccess();

private:
    std::string getUserCommand();
    bool getUserConfirmation();
    std::string getUserMovieTitle();
    MovieGenre getUserMovieGenre();
    Mode getUserMode();
    Movie getUserMovie();

private:
    void clearLayout();
    void clearFormControlState();

    void setupButtonsLayout();
    void addFormControl(const QString &labelText, QLineEdit *&control);

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

    QHBoxLayout *buttonsLayout;
    QPushButton *confirmationButton;
    QPushButton *cancelButton;
};