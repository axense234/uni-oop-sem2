#include <iostream>

#include "repo/Memory.repo.h"
#include "services/School.services.h"
#include "ui/Menu.ui.h"

using namespace std;

int main()
{
    MemoryRepo repo;
    SchoolServices services(repo);
    MenuUI ui(services, repo);

    ui.start();

    return 0;
}