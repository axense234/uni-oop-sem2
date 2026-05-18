#include "Movie.services.h"
#include "../repo/Memory.repo.h"

#include <utility>
#include <iostream>
#include <algorithm>

std::vector<TElem> &MovieServices::getElems() const noexcept
{
    return this->repo.getElems();
}

MovieServices::MovieServices(Repo<TElem, TElemId, TElemField> &r) : repo(r) {}

void MovieServices::addMovie(Movie movie, bool bypassUniqueConstraint) noexcept(false)
{
    // unique constraint
    try
    {
        Movie foundMovie = this->repo.getElemByField(TITLE, movie.getTitle());

        if (!bypassUniqueConstraint)
        {
            throw MovieServicesException("A movie with the same title already exists.");
        }
    }
    catch (const RepoException &e)
    {
        movie.setId(this->repo.getSize() + 1);
        this->repo.add(movie);
    }
}

void MovieServices::removeMovieById(int id) noexcept(false)
{
    return this->repo.remove(id);
}

void MovieServices::updateMovieById(int id, Movie payload) noexcept(false)
{

    Movie foundMovie = this->repo.getElemByField(ID, id);
    payload.setId(id);
    this->repo.update(id, payload);
}

Movie MovieServices::getMovieById(int id) const noexcept(false)
{
    try
    {
        return this->repo.getElemByField(ID, id);
    }
    catch (const std::exception &e)
    {
        return Movie{};
    }
}

Movie MovieServices::getMovieByTitle(std::string title) const noexcept(false)
{
    try
    {
        return this->repo.getElemByField(TITLE, title);
    }
    catch (const std::exception &e)
    {
        throw RepoException("Couldnt find movie.");
    }
}

std::vector<TElem> MovieServices::filterMoviesByGenre(MovieGenre genre) const noexcept
{

    if (genre == EMPTY)
    {
        return this->repo.getElems();
    }

    std::vector<TElem> filteredElems;
    std::copy_if(this->repo.getElems().begin(), this->repo.getElems().end(), std::back_inserter(filteredElems), [&](const TElem elem)
                 { return elem.getGenre() == genre; });

    return filteredElems;
}