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
    DynamicVectorIterator(const DynamicVector &v, int initialIndex);

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid();

    DynamicVectorIterator operator++();
    DynamicVectorIterator operator++(int);
    TElem &operator*();
    bool operator!=(DynamicVectorIterator comparable);
};