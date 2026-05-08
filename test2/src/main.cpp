#include <iostream>
using namespace std;

#include "repo/Repo.h"
#include "services/Services.h"
#include "ui/MenuUI.h"

int main()
{
    Repo repo = Repo{};
    Services services = Services{repo};
    MenuUI ui = MenuUI{services};

    ui.start();

    return 0;
}