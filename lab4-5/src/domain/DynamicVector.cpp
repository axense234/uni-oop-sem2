#include "DynamicVector.h"
#include "DynamicVectorIterator.h"

#include <exception>

DynamicVector::DynamicVector(int capacity, int factor)
{
    this->capacity = capacity;
    this->factor = factor;
    this->size = 0;

    this->elems = new TElem[this->capacity];
}

TElem DynamicVector::getElemById(TElemId id)
{
    for (int i = 0; i < this->size; ++i)
    {
        if (this->elems[i].getId() == id)
        {
            return this->elems[i];
        }
    }

    throw std::exception();
}

DynamicVector::DynamicVector(const DynamicVector &vector)
{
    this->size = vector.size;
    this->capacity = vector.capacity;

    this->elems = new TElem[vector.capacity];

    for (int i = 0; i < vector.size; i++)
    {
        this->elems[i] = vector.elems[i];
    }
}

DynamicVector &DynamicVector::operator=(const DynamicVector &vector)
{
    this->size = vector.size;
    this->capacity = vector.capacity;

    delete[] this->elems;
    this->elems = new TElem[this->capacity];

    for (int i = 0; i < vector.size; i++)
    {
        this->elems[i] = vector.elems[i];
    }

    return *this;
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
    int newCapacity = this->capacity * (this->factor > 1 ? this->factor : 2);
    this->capacity = newCapacity;

    TElem *aux = new TElem[this->capacity];

    for (int i = 0; i < this->size; ++i)
    {
        aux[i] = this->elems[i];
    }

    delete[] this->elems;
    this->elems = aux;
}

void DynamicVector::add(const TElem &elem)
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
    if (this->size == 0)
    {
        throw std::exception();
    }

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

void DynamicVector::clear()
{
    this->size = 0;
}

DynamicVectorIterator DynamicVector::iterator() const
{
    return DynamicVectorIterator(*this);
}