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

    MenuUI ui{input, output, playlistServices, movieServices};
    ui.start();

    return 0;
}