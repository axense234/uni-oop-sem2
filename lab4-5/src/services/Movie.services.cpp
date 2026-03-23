#include "Movie.services.h"

MovieServices::MovieServices(MemoryRepo &r) : repo(r) {}

bool MovieServices::addMovie(Movie movie)
{
    return this->repo.add(movie);
}

bool MovieServices::removeMovieById(int id)
{
    return this->repo.removeById(id);
}

bool MovieServices::updateMovieById(int id, Movie payload)
{
    return this->repo.updateById(id, payload);
}