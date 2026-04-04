#include "Movie.services.h"
#include "../domain/DynamicVectorIterator.h"

#include <utility>
#include <iostream>

std::pair<DynamicVectorIterator, DynamicVectorIterator> MovieServices::iterators() const
{
    return this->repo.iterators();
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

DynamicVector<TElem, TElemId, TElemIdentifier> MovieServices::filterMoviesByGenre(MovieGenre genre)
{

    // note for future self, enums dont really work with the ! operator which took me too long to figure out
    if (genre == EMPTY)
    {
        return this->repo.elements;
    }

    std::pair<DynamicVectorIterator, DynamicVectorIterator> iterators = this->repo.iterators();

    DynamicVector<TElem, TElemId, TElemIdentifier> filteredMovies;

    while (iterators.first != iterators.second)
    {
        Movie curr = *iterators.first;
        if (curr.getGenre() == genre)
        {
            filteredMovies.add(curr);
        }
        ++iterators.first;
    }

    return filteredMovies;
}