#pragma once

#include "Menu.ui.h"

#include <string>

class MenuGUI;

class MenuGUIOutput
{
    friend class MenuGUI;

private:
    /**
     * @brief Displays the possible movie genres.
     *
     */
    void genres() const;

    /**
     * @brief Displays the program intro.
     *
     * @param mode ADMIN or USER
     */
    void intro(Mode mode) const;

    /**
     * @brief Displays a list of available program commands.
     *
     * @param mode ADMIN or USER
     */
    void help(Mode mode) const;

public:
    /**
     * @brief Constructor.
     *
     */
    MenuGUIOutput();
};