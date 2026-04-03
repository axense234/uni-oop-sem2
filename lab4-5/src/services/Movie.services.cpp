#include "Movie.services.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <optional>

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

DynamicVector MovieServices::filterMoviesByGenre(std::optional<MovieGenre> genre = std::nullopt)
{

    if (!genre)
    {
        return this->repo.elements;
    }

    std::pair<DynamicVectorIterator, DynamicVectorIterator> iterators = this->repo.iterators();

    DynamicVector filteredMovies;

    std::copy_if(
        iterators.first,
        iterators.second,
        std::back_inserter(filteredMovies),
        [&](const TElem &first)
        { return first.getGenre() == genre.value(); });

    return filteredMovies;
}