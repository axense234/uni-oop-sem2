#pragma once

#include "DynamicVector.h"

class DynamicVectorIterator
{

    friend class DynamicVector<TElem, TElemId, TElemIdentifier>;

private:
    const DynamicVector<TElem, TElemId, TElemIdentifier> &vector;
    int currentIndex;

    /**
     * @brief Constructor.
     *
     * @param v DynamicVector reference.
     */
    DynamicVectorIterator(const DynamicVector<TElem, TElemId, TElemIdentifier> &v, int initialIndex);

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid();

    DynamicVectorIterator &operator++();
    DynamicVectorIterator operator++(int);
    TElem &operator*();
    bool operator!=(DynamicVectorIterator comparable);
};