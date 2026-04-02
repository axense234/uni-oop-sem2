#pragma once

#include "../domain/School.h"
#include "../services/School.services.h"

#include <string>
#include <utility>

class MenuUI
{
private:
    SchoolServices &services;
    MemoryRepo &repo;

public:
    MenuUI(SchoolServices &services, MemoryRepo &repo);

    std::string getUserCommand();

    School getUserSchool();

    void displaySchools();

    std::pair<float, float> getUserHomeAddress();

    /**
     * @brief Shows the closest 3 schools by given home address.
     *
     * @param address The address.
     */
    void showClosestSchoolsByAddress(std::pair<float, float> address);

    void start();
};