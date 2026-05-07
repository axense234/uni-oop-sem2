#include "TurboEngine.h"

TurboEngine::TurboEngine()
{
    Engine();
}

TurboEngine::TurboEngine(double basePrice) : Engine(basePrice)
{
}

double TurboEngine::getPrice() const
{
    return this->basePrice + 100;
}

std::string TurboEngine::toString()
{
    return "todo";
}