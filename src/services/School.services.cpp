#include "School.services.h"

SchoolServices::SchoolServices(MemoryRepo &repo) : repo(repo)
{
}

bool SchoolServices::addSchool(School school)
{
    try
    {
        this->repo.store(school);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}