#include "DynamicVector.h"
#include <exception>

DynamicVector::DynamicVector(int capacity, int factor)
{
    this->capacity = capacity;
    this->factor = factor;
    this->size = 0;

    this->elems = new TElem[capacity];
}

DynamicVector::~DynamicVector()
{
    delete[] this->elems;
}

int DynamicVector::length() const
{
    return this->size;
}

void DynamicVector::resize()
{

    this->capacity = this->capacity * this->factor;

    TElem *aux = new TElem[this->capacity];

    for (int i = 0; i < this->size; ++i)
    {
        aux[i] = this->elems[i];
    }

    delete[] this->elems;

    this->elems = aux;
}

void DynamicVector::add(TElem elem)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->elems[this->size] = elem;
    this->size++;
}

void DynamicVector::remove(TElemId id)
{
    int foundIndex = -1;
    for (int i = 0; i < this->size; ++i)
    {

        if (this->elems[i].getId() == id)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        throw std::exception();
    }

    for (int i = foundIndex; i < this->size - 1; ++i)
    {
        this->elems[i] = this->elems[i + 1];
    }
    this->size--;
}