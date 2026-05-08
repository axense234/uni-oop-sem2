#pragma once

#include "Engine.h"

class TurboEngine : public Engine
{
public:
    TurboEngine();
    TurboEngine(double basePrice);

    double getPrice() const override;
    std::string toString() override;
};