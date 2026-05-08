#pragma once

#include "../domain/Car.h"

#include <vector>

class Repo
{
public:
    Repo();
    std::vector<Car> cars;

    void addCar(Car car);
};