#pragma once

#include "Song.h"

typedef Song TElem;

class DynamicArray
{
private:
    int size, capacity;
    TElem *elems;

public:
    DynamicArray(int capacity = 5);
    DynamicArray(const DynamicArray &arr);
    DynamicArray &operator=(const DynamicArray &arr);
    ~DynamicArray();

    int getSize() const;
    int getCapacity() const;

    TElem *getElems() const;
    TElem getElemByIndex(int index) const;

    void add(TElem elem);

private:
    void resize(int factor = 2);
};