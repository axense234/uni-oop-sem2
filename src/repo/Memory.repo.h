#pragma once

#include <vector>

#include "../domain/School.h"

class SchoolServices;

class MemoryRepo
{
    friend class SchoolServices;

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