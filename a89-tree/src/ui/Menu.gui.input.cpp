#include "Menu.gui.input.h"

#include "../helpers/Helpers.h"

#include <iostream>
#include <limits>

MenuGUIInput::MenuGUIInput() {};

std::string MenuGUIInput::getUserCommand() const {}

bool MenuGUIInput::getUserConfirmation() const {}

int MenuGUIInput::getUserMovieId() const {}

std::string MenuGUIInput::getUserMovieTitle() const {}

MovieGenre MenuGUIInput::getUserMovieGenre() const {}

short MenuGUIInput::getUserMovieYearOfRelease() const {}

int MenuGUIInput::getUserMovieNumberOfLikes() const {}

std::string MenuGUIInput::getUserMovieTrailer() const {}

Mode MenuGUIInput::getUserMode() const {}

Movie MenuGUIInput::getUserMovie() const {}
