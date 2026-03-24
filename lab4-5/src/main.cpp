#include <iostream>

#include "ui/Menu.ui.h"

int main()
{

    MemoryRepo repo;
    MovieServices movieServices{repo};
    MenuUI ui{repo, movieServices};
    ui.start();

    return 0;
}