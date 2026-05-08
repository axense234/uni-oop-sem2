#include "DynamicArray.h"

DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity;
    this->size = 0;

    this->elems = new TElem[capacity];
}

DynamicArray::DynamicArray(const DynamicArray &arr)
{
    this->size = arr.size;
    this->capacity = arr.capacity;

    this->elems = new TElem[arr.capacity];

    for (int i = 0; i < arr.size; i++)
    {
        this->elems[i] = arr.elems[i];
    }
}

DynamicArray &DynamicArray::operator=(const DynamicArray &arr)
{
    this->size = arr.size;
    this->capacity = arr.capacity;

    delete[] this->elems;
    this->elems = new TElem[this->capacity];

    for (int i = 0; i < arr.size; i++)
    {
        this->elems[i] = arr.elems[i];
    }

    return *this;
}

DynamicArray::~DynamicArray()
{
    delete[] this->elems;
}

int DynamicArray::getSize() const
{
    return this->size;
}

int DynamicArray::getCapacity() const
{
    return this->capacity;
}

TElem *DynamicArray::getElems() const
{
    return this->elems;
}

TElem DynamicArray::getElemByIndex(int index) const
{

    return this->elems[index];
}

void DynamicArray::resize(int factor)
{

    this->capacity = this->capacity * factor;

    TElem *aux = new TElem[this->capacity];

    for (int i = 0; i < this->size; ++i)
    {
        aux[i] = this->elems[i];
    }

    delete[] this->elems;

    this->elems = aux;
}

void DynamicArray::add(TElem elem)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->elems[this->size] = elem;
    this->size++;
}