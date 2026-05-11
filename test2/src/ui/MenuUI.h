#pragma once

#include <iostream>

#include "../services/Services.h"

class MenuUI
{
private:
    Services &services;

public:
    MenuUI(Services &services);
    void start();
};