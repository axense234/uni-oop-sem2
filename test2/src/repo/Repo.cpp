#include "Repo.h"

Repo::Repo() {}

void Repo::addCar(Car car)
{
    this->cars.push_back(car);
}