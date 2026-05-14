#include "Menu.gui.input.h"

#include "../helpers/Helpers.h"

#include <iostream>
#include <limits>

MenuGUIInput::MenuGUIInput() : QDialog(nullptr)
{
    setModal(true);
    resize(300, 300);
    this->layout = new QVBoxLayout(this);
};

void MenuGUIInput::clearLayout()
{
    while (QLayoutItem *item = this->layout->takeAt(0))
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}

std::string MenuGUIInput::getUserCommand() const {}

bool MenuGUIInput::getUserConfirmation() const {}

std::string MenuGUIInput::getUserMovieTitle() const {}

MovieGenre MenuGUIInput::getUserMovieGenre() const {}

Mode MenuGUIInput::getUserMode() const {}

Movie MenuGUIInput::getUserMovie()
{

    this->clearLayout();
    setWindowTitle("Add Movie");

    QLabel *movieTitleLabel = new QLabel("Movie Title:", this);
    this->movieTitleFormControl = new QLineEdit(this);
    this->layout->addWidget(movieTitleLabel);
    this->layout->addWidget(movieTitleFormControl);

    QLabel *movieGenreLabel = new QLabel("Movie Genre:", this);
    this->movieGenreFormControl = new QLineEdit(this);
    this->layout->addWidget(movieGenreLabel);
    this->layout->addWidget(movieGenreFormControl);

    QLabel *movieYearOfReleaseLabel = new QLabel("Movie Year of Release:", this);
    this->movieYearOfReleaseFormControl = new QLineEdit(this);
    this->layout->addWidget(movieYearOfReleaseLabel);
    this->layout->addWidget(movieYearOfReleaseFormControl);

    QLabel *movieNumberOfLikesLabel = new QLabel("Movie Number of Likes:", this);
    this->movieNumberOfLikesFormControl = new QLineEdit(this);
    this->layout->addWidget(movieNumberOfLikesLabel);
    this->layout->addWidget(movieNumberOfLikesFormControl);

    QLabel *movieTrailerLabel = new QLabel("Movie Trailer:", this);
    this->movieTrailerFormControl = new QLineEdit(this);
    this->layout->addWidget(movieTrailerLabel);
    this->layout->addWidget(movieTrailerFormControl);

    this->okButton = new QPushButton("OK");
    this->cancelButton = new QPushButton("Cancel");

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserMovieSuccess);
    connect(cancelButton, &QPushButton::clicked, this, &MenuGUIInput::onClose);

    if (this->exec() == QDialog::Accepted)
    {
        return Movie{
            -1,
            this->movieTitle,
            this->movieGenre,
            this->movieYearOfRelease,
            this->movieNumberOfLikes,
            this->movieTrailer};
    }
    else
    {
        throw std::runtime_error("User cancelled");
    }
}

void MenuGUIInput::onClose()
{
    this->reject();
}

void MenuGUIInput::onGetUserMovieSuccess()
{
    this->movieTitle = movieTitleFormControl->text().toStdString();
    this->movieGenre = Helpers::convertGivenStringToMovieGenre(movieGenreFormControl->text().toStdString());
    this->movieYearOfRelease = movieYearOfReleaseFormControl->text().toShort();
    this->movieNumberOfLikes = movieNumberOfLikesFormControl->text().toInt();
    this->movieTrailer = movieTrailerFormControl->text().toStdString();
    this->accept();
}