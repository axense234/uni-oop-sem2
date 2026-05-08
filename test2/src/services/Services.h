#pragma once

#include "../repo/Repo.h"
#include <string>

class Services
{
private:
    Repo &repo;

public:
    Services(Repo &repo);
    Car getLatestCarAdded();
    std::vector<Car> getCars();
    void addCar(std::string bodyStyle, std::string engineType, int autonomy);
    std::vector<Car> getCarsWithMaxPrice(double maxPrice);
    void writeToFile(std::string filename, std::vector<Car> cars);
};