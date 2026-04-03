#include "Playlist.services.h"

#include <vector>
#include <algorithm>
#include <iterator>
#include <optional>

PlaylistServices::PlaylistServices(MemoryRepo &r) : repo(r) {}

bool PlaylistServices::addMovie(Movie movie)
{
    movie.setId(this->repo.size() + 1);
    return this->repo.add(movie);
}

bool PlaylistServices::removeMovieById(int id)
{
    return this->repo.removeById(id);
}

bool PlaylistServices::updateMovieById(int id, Movie payload)
{

    Movie foundMovie = this->repo.getElemById(id);

    if (foundMovie.getId() == -1)
    {
        return false;
    }

    payload.setId(id);
    return this->repo.updateById(id, payload);
}

Movie PlaylistServices::getMovieById(int id)
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
