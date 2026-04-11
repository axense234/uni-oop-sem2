#include <iostream>

#include "ui/Menu.ui.input.h"
#include "ui/Menu.ui.output.h"
#include "ui/Menu.ui.h"

int main()
{

    MemoryRepo database;
    MovieServices databaseServices{database};

    MemoryRepo playlist;
    MovieServices playlistServices{playlist};

    MenuUIInput input;
    MenuUIOutput output;

    MenuUI ui{input, output, playlistServices, databaseServices};
    ui.start();

    return 0;
}