#include "Memory.repo.h"
#include "../exceptions/RepoException.h"

#include <vector>
#include <algorithm>
#include <any>

const std::vector<TElem> &MemoryRepo::getElems() const noexcept(false)
{
    return this->elements;
}

std::vector<TElem> &MemoryRepo::getElems() noexcept(false)
{
    return this->elements;
}

MemoryRepo::MemoryRepo()
{
    this->elements = std::vector<TElem>{};
}

void MemoryRepo::add(const TElem &elem)
{
    try
    {
        this->elements.push_back(elem);
    }
    catch (const std::exception &e)
    {
        throw RepoException("Add operation failed.");
    }
}

void MemoryRepo::remove(TElemId id)
{

    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               { return elem.getId() == id; });

    // if we didnt find the elem we throw exception
    if (elemIt == this->elements.end())
    {
        throw RepoException("Remove operation failed, couldn't find elem to remove.");
    }

    this->elements.erase(elemIt);
}

void MemoryRepo::update(TElemId id, TElem payload)
{

    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               { return elem.getId() == id; });

    // if we didnt find the elem we throw exception
    if (elemIt == this->elements.end())
    {
        throw RepoException("Update operation failed, couldn't find elem to remove.");
    }

    *elemIt = payload;
}

int MemoryRepo::getSize() const noexcept
{
    return this->elements.size();
}

TElem &MemoryRepo::getElemByField(TElemField field, std::any value) noexcept(false)
{
    auto elemIt = std::find_if(this->elements.begin(), this->elements.end(),
                               [&](const TElem &elem)
                               {
                                   auto idPtr = std::any_cast<int>(&value);
                                   auto titlePtr = std::any_cast<std::string>(&value);
                                   auto genrePtr = std::any_cast<MovieGenre>(&value);
                                   auto nbLikesPtr = std::any_cast<int>(&value);
                                   auto yorPtr = std::any_cast<short>(&value);
                                   auto trailerPtr = std::any_cast<std::string>(&value);

                                   switch (field)
                                   {
                                   case ID:
                                       if (idPtr == nullptr)
                                       {
                                           throw RepoException("Field expected an int and was left disappointed.");
                                       }
                                       return elem.getId() == *idPtr;

                                   case TITLE:
                                       if (titlePtr == nullptr)
                                       {
                                           throw RepoException("Field expected an std::string and was left disappointed.");
                                       }
                                       return elem.getTitle() == *titlePtr;

                                   case GENRE:
                                       if (genrePtr == nullptr)
                                       {
                                           throw RepoException("Field expected a MovieGenre and was left disappointed.");
                                       }
                                       return elem.getGenre() == *genrePtr;

                                   case YEAR_OF_RELEASE:
                                       if (yorPtr == nullptr)
                                       {
                                           throw RepoException("Field expected a short and was left disappointed.");
                                       }
                                       return elem.getYearOfRelease() == *yorPtr;

                                   case NUMBER_OF_LIKES:
                                       if (nbLikesPtr == nullptr)
                                       {
                                           throw RepoException("Field expected an int and was left disappointed.");
                                       }
                                       return elem.getNumberOfLikes() == *nbLikesPtr;

                                   case TRAILER:
                                       if (trailerPtr == nullptr)
                                       {
                                           throw RepoException("Field expected an std::string and was left disappointed.");
                                       }
                                       return elem.getTrailer() == *trailerPtr;

                                   default:
                                       throw RepoException("Field doesn't exist.");
                                   }
                               });

    if (elemIt == this->elements.end())
    {
        throw RepoException("Couldn't find element.");
    }

    return *elemIt;
}