#include "Car.h"
#include "Engine.h"
#include "TurboEngine.h"
#include "ElectricEngine.h"

#include <string>

Car::Car(std::string engineType, std::string bodyStyle, int autonomy)
{
    this->engineType = engineType;
    this->bodyStyle = bodyStyle;

    this->basePrice = bodyStyle == "Sedan" ? 8000 : 9000;

    if (engineType == "Turbo")
    {
        this->engine = TurboEngine();
    }
    else if (engineType == "Electric")
    {
        this->engine = ElectricEngine(autonomy);
    }
}

double Car::computePrice() const
{
    return this->basePrice + this->engine.getPrice();
}

std::string Car::getBodyStyle() const
{
    return this->bodyStyle;
}

std::string Car::getEngineType() const
{
    return this->engineType;
}

double Car::getBasePrice() const
{
    return this->basePrice;
}