#pragma once

#include "Engine.h"

class ElectricEngine : public Engine
{
private:
    int autonomy;

public:
    ElectricEngine(int autonomy);
    ElectricEngine(double basePrice, int autonomy);

    double getPrice() const override;
    std::string toString() override;
};