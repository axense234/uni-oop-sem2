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

bool MenuGUIInput::getUserConfirmation(const std::string &label)
{
    this->clearLayout();
    this->clearFormControlState();

    this->addLabel(QString::fromStdString(label));

    this->disconnect(this->confirmationButton, nullptr, this, nullptr);
    this->disconnect(this->cancelButton, nullptr, this, nullptr);
    this->connect(this->confirmationButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserConfirmationSuccess);
    this->connect(this->cancelButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserConfirmationFail);

    int optimalHeight = this->layout->sizeHint().height();
    this->resize(300, optimalHeight);

    if (this->exec() == QDialog::Accepted)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MenuGUIInput::onGetUserConfirmationSuccess()
{
    this->userConfirmation = true;
    this->accept();
}

void MenuGUIInput::onGetUserConfirmationFail()
{
    this->userConfirmation = false;
    this->reject();
}

std::string MenuGUIInput::getUserMovieTitle()
{
    this->clearLayout();
    this->clearFormControlState();

    this->addFormControl("Movie Title:", this->movieTitleFormControl);

    this->disconnect(this->confirmationButton, nullptr, this, nullptr);
    this->disconnect(this->cancelButton, nullptr, this, nullptr);
    this->connect(this->confirmationButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserMovieTitleSuccess);
    this->connect(this->cancelButton, &QPushButton::clicked, this, &MenuGUIInput::onClose);

    int optimalHeight = this->layout->sizeHint().height();
    this->resize(300, optimalHeight);

    if (this->exec() == QDialog::Accepted)
    {
        return this->movieTitle;
    }
    else
    {
        throw MenuGUIException("User cancel.");
    }
}

void MenuGUIInput::onGetUserMovieTitleSuccess()
{
    this->movieTitle = movieTitleFormControl->text().toStdString();
    this->accept();
}

MovieGenre MenuGUIInput::getUserMovieGenre()
{
    this->clearLayout();
    this->clearFormControlState();

    this->addFormControl("Movie Genre:", this->movieGenreFormControl);

    this->disconnect(this->confirmationButton, nullptr, this, nullptr);
    this->disconnect(this->cancelButton, nullptr, this, nullptr);
    this->connect(this->confirmationButton, &QPushButton::clicked, this, &MenuGUIInput::onGetUserMovieGenreSuccess);
    this->connect(this->cancelButton, &QPushButton::clicked, this, &MenuGUIInput::onClose);

    int optimalHeight = this->layout->sizeHint().height();
    this->resize(300, optimalHeight);

    if (this->exec() == QDialog::Accepted)
    {
        return this->movieGenre;
    }
    else
    {
        throw MenuGUIException("User cancel.");
    }
}

void MenuGUIInput::onGetUserMovieGenreSuccess()
{
    this->movieGenre = Helpers::convertGivenStringToMovieGenre(movieGenreFormControl->text().toStdString());
    this->accept();
}

Mode MenuGUIInput::getUserMode() {}

Movie MenuGUIInput::getUserMovie() noexcept(false)
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

    int optimalHeight = this->layout->sizeHint().height();
    this->resize(300, optimalHeight);

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
        throw MenuGUIException("User cancel.");
    }
}

void MenuGUIInput::onClose()
{
    this->reject();
}

void MenuGUIInput::onGetUserMovieSuccess()
{
    try
    {
        this->movieTitle = movieTitleFormControl->text().toStdString();
        this->movieGenre = Helpers::convertGivenStringToMovieGenre(movieGenreFormControl->text().toStdString());
        this->movieYearOfRelease = movieYearOfReleaseFormControl->text().toShort();
        this->movieNumberOfLikes = movieNumberOfLikesFormControl->text().toInt();
        this->movieTrailer = movieTrailerFormControl->text().toStdString();
        this->accept();
    }
    catch (const std::exception &e)
    {
        QMessageBox::critical(this, "Input Error", "Invalid input detected.");
    }
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

void MenuGUIInput::addLabel(const QString &labelText)
{
    int insertPosition = this->layout->count() - 2;
    QLabel *label = new QLabel(labelText, this);
    label->setFont(QFont("Arial", 14, QFont::Bold));

    this->layout->insertWidget(insertPosition, label);
}