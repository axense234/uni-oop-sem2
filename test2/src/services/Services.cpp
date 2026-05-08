#include "Services.h"
#include "../domain/Car.h"
#include "../domain/TurboEngine.h"
#include "../domain/ElectricEngine.h"

Services::Services(Repo &repo) : repo(repo) {};

void Services::addCar(std::string bodyStyle, std::string engineType, int autonomy)
{
    Car newCar = Car{engineType, bodyStyle, autonomy};
    this->repo.addCar(newCar);
}

std::vector<Car> Services::getCars()
{
    return this->repo.cars;
}

Car Services::getLatestCarAdded()
{
    return this->repo.cars.back();
}