#pragma once

#include "DynamicVector.h"

class DynamicVectorIterator
{

    friend class DynamicVector;

private:
    const DynamicVector &vector;
    int currentIndex;

    /**
     * @brief Constructor.
     *
     * @param v DynamicVector reference.
     */
    DynamicVectorIterator(const DynamicVector &v);

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid();
};