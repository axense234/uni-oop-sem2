#pragma once

#include <string>

#include "Engine.h"

class Car
{
private:
    std::string engineType;
    std::string bodyStyle;

    Engine engine;

    double basePrice;

public:
    std::string getEngineType() const;
    std::string getBodyStyle() const;
    double getBasePrice() const;

    Car(std::string engineType, std::string bodyStyle, int autonomy);
    double computePrice() const;
};