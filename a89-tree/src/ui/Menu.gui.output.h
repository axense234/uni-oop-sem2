#pragma once

#include "Menu.ui.h"

#include <string>

#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>

class MenuGUI;

class MenuGUIOutput
{
    friend class MenuGUI;

private:
    void genres(QListWidget *itemsList) const;
    void intro(QListWidget *itemsList, Mode mode) const;
    void help(QListWidget *itemsList, Mode mode) const;

public:
    MenuGUIOutput();
};