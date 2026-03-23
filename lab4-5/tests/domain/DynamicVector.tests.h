#pragma once

#include "../../src/domain/DynamicVector.h"

class DynamicVectorTests
{
private:
    DynamicVector dynamicVector;

public:
    /**
     * @brief Constructor
     */
    DynamicVectorTests();

    void testAdd();

    void testRemove();
};