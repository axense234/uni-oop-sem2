#pragma once

#include <QtWidgets>

#include "../domain/Movie.h"
#include "../exceptions/MenuGUIException.h"

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
    void onGetUserMovieGenreSuccess();
    void onGetUserConfirmationSuccess();
    void onGetUserConfirmationFail();

private:
    std::string getUserCommand();
    bool getUserConfirmation(const std::string &label);
    std::string getUserMovieTitle();
    MovieGenre getUserMovieGenre();
    Mode getUserMode();
    /**
     * @brief Gets a movie from the user through the gui.
     *
     * @exception MenuGUIException is thrown if user cancels the process
     * @return Movie
     */
    Movie getUserMovie() noexcept(false);

private:
    void clearLayout();
    void clearFormControlState();

    void setupButtonsLayout();
    void addFormControl(const QString &labelText, QLineEdit *&control);
    void addLabel(const QString &labelText);

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

    bool userConfirmation;

    QHBoxLayout *buttonsLayout;
    QPushButton *confirmationButton;
    QPushButton *cancelButton;
};