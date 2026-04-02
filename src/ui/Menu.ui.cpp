#include "Menu.ui.h"
#include <iostream>
#include <algorithm>

MenuUI::MenuUI(SchoolServices &services, MemoryRepo &repo) : services(services), repo(repo) {}

std::string MenuUI::getUserCommand()
{
    std::string command;
    std::cin >> command;
    return command;
}

School MenuUI::getUserSchool()
{
    std::string name;
    std::cout << "Name: ";
    std::cin >> name;

    std::pair<float, float> address;
    std::cout << "Address(float, float): ";
    std::cin >> address.first >> address.second;

    std::string dateOfVisit;
    std::cout << "Date of visit: ";
    std::cin >> dateOfVisit;

    School school = School(name, address, dateOfVisit);
    return school;
}

std::pair<float, float> MenuUI::getUserHomeAddress()
{
    std::pair<float, float> address;
    std::cout << "Address(float, float): ";
    std::cin >> address.first >> address.second;
    return address;
}

void MenuUI::displaySchools()
{
    std::vector<School> &schools = this->repo.getData();

    for (School &curr : schools)
    {
        std::cout << curr.getName() << std::endl;
        std::cout << curr.getAddress().first << ", " << curr.getAddress().second << std::endl;
        std::cout << curr.getDateOfVisit() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MenuUI::start()
{
    std::cout << "Schools Manager" << std::endl;
    std::cout << "===================" << std::endl;

    School first = School("Avram_iancu", std::pair<float, float>(96.77, 23.60), "15.04.2022");
    School second = School("Georgecosbuc", std::pair<float, float>(66.77, 23.60), "15.04.2022");
    School third = School("Alexandru_Valida", std::pair<float, float>(16.77, 23.60), "15.04.2022");
    School fourth = School("romulus_guga", std::pair<float, float>(36.77, 23.60), "15.04.2022");
    School fifth = School("transilvania", std::pair<float, float>(26.77, 23.60), "15.04.2022");

    this->services.addSchool(first);
    this->services.addSchool(second);
    this->services.addSchool(third);
    this->services.addSchool(fourth);
    this->services.addSchool(fifth);

    while (true)
    {
        std::string command = getUserCommand();

        if (command == "add")
        {
            School school = getUserSchool();
            if (this->services.addSchool(school))
            {
                std::cout << "Successfully added school." << std::endl;
            }
            else
            {
                std::cout << "School was NOT successfully added :(.";
            }
        }
        else if (command == "closest")
        {
            std::pair<float, float> address = getUserHomeAddress();
            this->showClosestSchoolsByAddress(address);
        }
        else if (command == "show")
        {
            this->displaySchools();
        }
        else if (command == "exit")
        {
            std::cout << "Exiting..." << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }
}

void MenuUI::showClosestSchoolsByAddress(std::pair<float, float> address)
{
    std::vector<School> &schools = this->repo.getData();
    std::vector<School> matchedSchools;

    std::sort(schools.begin(), schools.end(), [](School &first, School &second)
              { return first.getName() < second.getName(); });

    int count = 0;
    for (School &curr : schools)
    {
        if (count == 3)
        {
            break;
        }

        std::cout << curr.getName() << std::endl;
        std::cout << curr.getAddress().first << ", " << curr.getAddress().second << std::endl;
        std::cout << curr.getDateOfVisit() << std::endl;
        count++;
    }
    std::cout << std::endl;
}
