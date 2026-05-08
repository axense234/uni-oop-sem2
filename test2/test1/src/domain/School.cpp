#include "School.h"

School::School(std::string name, std::pair<float, float> address, std::string dateOfVisit)
{
    this->name = name;
    this->address = address;
    this->dateOfVisit = dateOfVisit;
}

std::string School::getName()
{
    return this->name;
}

std::string School::getDateOfVisit()
{
    return this->dateOfVisit;
}

std::pair<float, float> School::getAddress()
{
    return this->address;
}