#include "DynamicVectorIterator.h"

DynamicVectorIterator::DynamicVectorIterator(const DynamicVector &v, int initialIndex) : vector(v)
{
    this->currentIndex = initialIndex || 0;
}

bool DynamicVectorIterator::valid()
{
    return this->currentIndex < this->vector.size;
}

void DynamicVectorIterator::first()
{
    this->currentIndex = 0;
}

void DynamicVectorIterator::next()
{
    if (this->valid())
    {
        this->currentIndex++;
    }
}

TElem DynamicVectorIterator::getCurrent()
{
    return this->vector.elems[this->currentIndex];
}

DynamicVectorIterator DynamicVectorIterator::operator++()
{
    this->currentIndex++;
    return *this;
}
DynamicVectorIterator DynamicVectorIterator::operator++(int)
{
    DynamicVectorIterator aux = *this;
    this->currentIndex++;
    return aux;
}
TElem &DynamicVectorIterator::operator*()
{
    return this->vector.elems[this->currentIndex];
}

bool DynamicVectorIterator::operator!=(DynamicVectorIterator comparable)
{
    return this->currentIndex != comparable.currentIndex;
}