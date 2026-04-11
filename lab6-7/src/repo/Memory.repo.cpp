#include "Memory.repo.h"
#include <vector>
#include <algorithm>

TElem MemoryRepo::getElemById(TElemId id)
{
    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               { return elem.getId() == id; });

    if (elemIt == this->elements.end())
    {
        throw std::exception();
    }

    return *elemIt;
}

TElem MemoryRepo::getElemByTitle(TElemIdentifier identifier)
{
    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               { return elem.getTitle() == identifier; });

    if (elemIt == this->elements.end())
    {
        throw std::exception();
    }

    return *elemIt;
}

MemoryRepo::MemoryRepo()
{
    this->elements = std::vector<TElem>{};
}

bool MemoryRepo::add(TElem elem)
{
    try
    {
        this->elements.push_back(elem);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool MemoryRepo::removeById(TElemId id)
{

    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               { return elem.getId() == id; });

    // if we didnt find the elem we
    if (elemIt == this->elements.end())
    {
        return false;
    }

    // easy
    this->elements.erase(elemIt);

    return true;
}

bool MemoryRepo::updateById(TElemId id, TElem payload)
{

    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               { return elem.getId() == id; });

    // if we didnt find the elem we
    if (elemIt == this->elements.end())
    {
        return false;
    }

    // again very easy
    *elemIt = payload;

    return true;
}

int MemoryRepo::size()
{
    return this->elements.size();
}