#include "Movie.services.h"
#include "../repo/Memory.repo.h"

#include <utility>
#include <iostream>
#include <algorithm>

std::vector<TElem> &MovieServices::elems() const
{
    return this->repo.elements;
}

MovieServices::MovieServices(MemoryRepo &r) : repo(r) {}

bool MovieServices::addMovie(Movie movie)
{
    movie.setId(this->repo.size() + 1);
    return this->repo.add(movie);
}

bool MovieServices::removeMovieById(int id)
{
    return this->repo.removeById(id);
}

bool MovieServices::updateMovieById(int id, Movie payload)
{

    Movie foundMovie = this->repo.getElemById(id);

    if (foundMovie.getId() == -1)
    {
        return false;
    }

    payload.setId(id);
    return this->repo.updateById(id, payload);
}

Movie MovieServices::getMovieById(int id)
{
    try
    {
        return this->repo.getElemById(id);
    }
    catch (const std::exception &e)
    {
        return Movie{};
    }
}

Movie MovieServices::getMovieByTitle(std::string title)
{
    try
    {
        return this->repo.getElemByTitle(title);
    }
    catch (const std::exception &e)
    {
        return Movie{};
    }
}

std::vector<TElem> MovieServices::filterMoviesByGenre(MovieGenre genre) const
{

    if (genre == EMPTY)
    {
        return this->repo.elements;
    }

    std::vector<TElem> filteredElems;
    std::copy_if(this->repo.elements.begin(), this->repo.elements.end(), std::back_inserter(filteredElems), [&](const TElem elem)
                 { return elem.getGenre() == genre; });

    return filteredElems;
}