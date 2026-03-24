#include "Memory.repo.h"
#include "../domain/DynamicVectorIterator.h"

DynamicVectorIterator MemoryRepo::getElemsIterator() const
{
    return this->elements.iterator();
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

MemoryRepo::MemoryRepo()
{
    this->elements = DynamicVector{5, 2};
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