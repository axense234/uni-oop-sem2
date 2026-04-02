#pragma once

#include "../domain/School.h"
#include "../repo/Memory.repo.h"

class SchoolServices
{
private:
    MemoryRepo &repo;

    /**
     * @brief Construct a new School Services object.
     *
     * @param repo
     */

public:
    SchoolServices(MemoryRepo &repo);

    /**
     * @brief Adds a school to the repo.
     *
     * @param school
     * @return true If add wass success.
     * @return false If add was not success.
     */
    bool addSchool(School school);
};