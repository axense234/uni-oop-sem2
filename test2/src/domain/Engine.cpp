#include "Engine.h"

Engine::Engine()
{
    this->basePrice = 3000;
}

Engine::Engine(double basePrice)
{
    this->basePrice = basePrice;
}

double Engine::getPrice() const
{
    return this->basePrice;
}

std::string Engine::toString()
{
    return "todo";
}