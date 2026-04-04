#include "Memory.repo.h"
#include "../domain/DynamicVectorIterator.h"

std::pair<DynamicVectorIterator, DynamicVectorIterator> MemoryRepo::iterators() const
{
    return std::pair<DynamicVectorIterator, DynamicVectorIterator>{this->elements.begin(), this->elements.end()};
}

TElem MemoryRepo::getElemById(TElemId id)
{
    try
    {
        TElem foundElem = this->elements.getElemById(id);
        return foundElem;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}

TElem MemoryRepo::getElemByTitle(TElemIdentifier identifier)
{
    try
    {
        TElem foundElem = this->elements.getElemByIdentifier(identifier);
        return foundElem;
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}

MemoryRepo::MemoryRepo()
{
    this->elements = DynamicVector<TElem, TElemId, TElemIdentifier>{5, 2};
}

bool MemoryRepo::add(TElem elem)
{
    try
    {
        this->elements.add(elem);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool MemoryRepo::removeById(TElemId id)
{

    try
    {
        this->elements.remove(id);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool MemoryRepo::updateById(TElemId id, TElem payload)
{
    try
    {
        this->elements.remove(id);
        this->elements.add(payload);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

int MemoryRepo::size()
{
    return this->elements.size;
}