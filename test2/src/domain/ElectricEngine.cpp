#include "ElectricEngine.h"

ElectricEngine::ElectricEngine(int autonomy) : Engine::Engine()
{
    this->autonomy = autonomy;
};

ElectricEngine::ElectricEngine(double basePrice, int autonomy) : Engine(basePrice)
{
    this->autonomy = autonomy;
};

double ElectricEngine::getPrice() const
{
    return this->basePrice + this->autonomy * 0.01;
}

std::string ElectricEngine::toString()
{
    return "todo";
}