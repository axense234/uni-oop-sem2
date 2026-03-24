#include "DynamicVectorIterator.h"

DynamicVectorIterator::DynamicVectorIterator(const DynamicVector &v) : vector(v)
{
    this->currentIndex = 0;
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