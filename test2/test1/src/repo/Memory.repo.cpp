#include "Memory.repo.h"
#include <iostream>

#include <exception>

MemoryRepo::MemoryRepo() {}

void MemoryRepo::store(School school)
{
    for (School &curr : this->data)
    {
        if (curr.getName() == school.getName() && curr.getAddress().first == school.getAddress().first && curr.getAddress().second == school.getAddress().second)
        {
            throw std::exception();
        }
    }

    this->data.push_back(school);
}

std::vector<School> &MemoryRepo::getData()
{
    return this->data;
}