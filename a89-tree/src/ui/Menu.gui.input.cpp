#include "Menu.gui.input.h"

#include "../helpers/Helpers.h"

#include <iostream>
#include <limits>

MenuGUIInput::MenuGUIInput() : QDialog(nullptr)
{
    this->setModal(true);
    this->resize(300, 300);
    this->layout = new QVBoxLayout(this);
    this->layout->setAlignment(Qt::AlignTop);

    this->setupButtonsLayout();
};

void MenuGUIInput::clearLayout()
{
    this->clearFormControlState();

    while (this->layout->count() > 2)
    {
        QLayoutItem *item = this->layout->takeAt(0);
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }

    movieTitleFormControl = nullptr;
    movieGenreFormControl = nullptr;
    movieYearOfReleaseFormControl = nullptr;
    movieNumberOfLikesFormControl = nullptr;
    movieTrailerFormControl = nullptr;
};

std::string MenuGUIInput::getUserCommand() {}

bool MenuGUIInput::getUserConfirmation() {}

std::string MenuGUIInput::getUserMovieTitle()
{
    this->clearLayout();
    this->clearFormControlState();

    this->addFormControl("Movie Title:", this->movieTitleFormControl);

    this->disconnect(this->confirmationButton, nullptr, this, nullptr);
    this->disconnect(this->cancelButton, nullptr, this, nullptr);
    this->connect(this->confirmationButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserMovieTitleSuccess);
    this->connect(this->cancelButton, &QPushButton::clicked, this, &MenuGUIInput::onClose);

    if (this->exec() == QDialog::Accepted)
    {
        return this->movieTitle;
    }
    else
    {
        throw std::runtime_error("Cancel.");
    }
}

void MenuGUIInput::onGetUserMovieTitleSuccess()
{
    this->movieTitle = movieTitleFormControl->text().toStdString();
    this->accept();
}

MovieGenre MenuGUIInput::getUserMovieGenre() {}

Mode MenuGUIInput::getUserMode() {}

Movie MenuGUIInput::getUserMovie()
{

    this->clearLayout();
    this->clearFormControlState();

    this->addFormControl("Movie Title:", this->movieTitleFormControl);
    this->addFormControl("Movie Genre:", this->movieGenreFormControl);
    this->addFormControl("Movie Year of Release:", this->movieYearOfReleaseFormControl);
    this->addFormControl("Movie Number of Likes:", this->movieNumberOfLikesFormControl);
    this->addFormControl("Movie Trailer:", this->movieTrailerFormControl);

    this->disconnect(this->confirmationButton, nullptr, this, nullptr);
    this->disconnect(this->cancelButton, nullptr, this, nullptr);
    this->connect(this->confirmationButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserMovieSuccess);
    this->connect(this->cancelButton, &QPushButton::clicked, this, &MenuGUIInput::onClose);

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
        throw std::runtime_error("Cancel.");
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

void MenuGUIInput::clearFormControlState()
{
    this->movieTitle = "";
    this->movieGenre = ACTION;
    this->movieYearOfRelease = 0;
    this->movieNumberOfLikes = 0;
    this->movieTrailer = "";
}

void MenuGUIInput::setupButtonsLayout()
{
    this->confirmationButton = new QPushButton("Ok", this);
    this->cancelButton = new QPushButton("Cancel", this);

    this->buttonsLayout = new QHBoxLayout();
    this->buttonsLayout->addWidget(confirmationButton);
    this->buttonsLayout->addWidget(cancelButton);

    this->layout->addStretch();
    this->layout->addLayout(this->buttonsLayout);
}

void MenuGUIInput::addFormControl(const QString &labelText, QLineEdit *&control)
{
    int insertPosition = this->layout->count() - 2;
    QLabel *label = new QLabel(labelText, this);
    control = new QLineEdit(this);

    this->layout->insertWidget(insertPosition, label);
    this->layout->insertWidget(insertPosition + 1, control);
}