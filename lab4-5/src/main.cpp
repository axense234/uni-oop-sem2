#include <iostream>

#include "ui/Menu.ui.input.h"
#include "ui/Menu.ui.output.h"
#include "ui/Menu.ui.h"

int main()
{

    MemoryRepo database;
    MovieServices movieServices{database};

    MemoryRepo playlist;
    PlaylistServices playlistServices{playlist};

    MenuUIInput input;
    MenuUIOutput output;

    // todo: make it so the ui doesnt use the database

    MenuUI ui{input, output, database, playlistServices, movieServices};
    ui.start();

    return 0;
}