#pragma once

#include <string>

class Engine
{
protected:
    double basePrice;

public:
    Engine();
    Engine(double BasePrice);

    virtual double getPrice() const;
    virtual std::string toString();
};