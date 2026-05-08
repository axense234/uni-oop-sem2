#pragma once

#include <vector>

#include "../domain/School.h"

class SchoolServices;
class HelpersTests;

class MemoryRepo
{
    friend class SchoolServices;
    friend class HelpersTests;

private:
    std::vector<School> data;

public:
    MemoryRepo();
    /**
     * @brief Adds a School instance to the repo.
     *
     * @param school School.
     */
    void store(School school);

    std::vector<School> &getData();
};