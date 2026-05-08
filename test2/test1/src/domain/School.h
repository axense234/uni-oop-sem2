#pragma once

#include <string>
#include <utility>

class School
{
private:
    std::string name;
    std::pair<float, float> address;
    std::string dateOfVisit;

public:
    /**
     * @brief Construct a new School object.
     *
     * @param name
     * @param address
     * @param dateOfVisit
     */
    School(std::string name, std::pair<float, float> address, std::string dateOfVisit);

    std::string getName();
    std::pair<float, float> getAddress();
    std::string getDateOfVisit();
};