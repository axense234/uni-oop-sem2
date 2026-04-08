#include "DynamicVector.h"
#include "DynamicVectorIterator.h"

#include <exception>
#include <string>
#include <iostream>

template <typename TElem, typename TElemId, typename TElemIdentifier>
DynamicVector<TElem, TElemId, TElemIdentifier>::DynamicVector(int capacity, int factor)
{
    this->capacity = capacity;
    this->factor = factor;
    this->size = 0;

    this->elems = new TElem[this->capacity];
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
TElem DynamicVector<TElem, TElemId, TElemIdentifier>::getElemById(TElemId id)
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

template <typename TElem, typename TElemId, typename TElemIdentifier>
TElem DynamicVector<TElem, TElemId, TElemIdentifier>::getElemByIdentifier(TElemIdentifier identifier)
{
    for (int i = 0; i < this->size; ++i)
    {
        if (this->elems[i].getTitle() == identifier)
        {
            return this->elems[i];
        }
    }

    throw std::exception();
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
DynamicVector<TElem, TElemId, TElemIdentifier>::DynamicVector(const DynamicVector &vector)
{
    this->size = vector.size;
    this->capacity = vector.capacity;

    this->elems = new TElem[vector.capacity];

    for (int i = 0; i < vector.size; i++)
    {
        this->elems[i] = vector.elems[i];
    }
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
DynamicVector<TElem, TElemId, TElemIdentifier> &DynamicVector<TElem, TElemId, TElemIdentifier>::operator=(const DynamicVector &vector)
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

template <typename TElem, typename TElemId, typename TElemIdentifier>
DynamicVector<TElem, TElemId, TElemIdentifier>::~DynamicVector()
{
    delete[] this->elems;
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
int DynamicVector<TElem, TElemId, TElemIdentifier>::length() const
{
    return this->size;
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
void DynamicVector<TElem, TElemId, TElemIdentifier>::resize()
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

template <typename TElem, typename TElemId, typename TElemIdentifier>
void DynamicVector<TElem, TElemId, TElemIdentifier>::add(const TElem &elem)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->elems[this->size] = elem;
    this->size++;
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
void DynamicVector<TElem, TElemId, TElemIdentifier>::remove(TElemId id)
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

template <typename TElem, typename TElemId, typename TElemIdentifier>
void DynamicVector<TElem, TElemId, TElemIdentifier>::clear()
{
    this->size = 0;
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
DynamicVectorIterator DynamicVector<TElem, TElemId, TElemIdentifier>::begin() const
{
    DynamicVectorIterator it = DynamicVectorIterator(*this, 0);
    return it;
}

template <typename TElem, typename TElemId, typename TElemIdentifier>
DynamicVectorIterator DynamicVector<TElem, TElemId, TElemIdentifier>::end() const
{
    DynamicVectorIterator it = DynamicVectorIterator(*this, this->size);
    return it;
}

// we either do this or move the methods in the .h file and remove the cpp file
template class DynamicVector<Movie, int, std::string>;