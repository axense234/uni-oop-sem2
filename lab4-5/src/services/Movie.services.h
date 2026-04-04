#pragma once

#include "../repo/Memory.repo.h"
#include "../domain/Movie.h"

#include <optional>

class MovieServices
{
private:
    MemoryRepo &repo;

public:
    /**
     * @brief Constructor.
     *
     * @param repo reference to a repo
     */
    MovieServices(MemoryRepo &repo);

    /**
     * @brief Adds a movie to the repository.
     *
     * @param movie Movie to be added.
     */
    bool addMovie(Movie movie);

    /**
     * @brief Removes a movie from the repository by id.
     *
     * @param id Id of the movie.
     */
    bool removeMovieById(int id);

    /**
     * @brief Updates a movie in the repository by id and given payload.
     *
     * @param id Id of the movie.
     * @param payload Update Movie object.
     */
    bool updateMovieById(int id, Movie payload);

    /**
     * @brief Finds and returns a movie by given id.
     *
     * @param id int
     * @return Found Movie or Default Movie (with id = -1)
     */
    Movie getMovieById(int id);

    /**
     * @brief Filters database movies by genre and returns a copy of those movies.
     *
     * @param genre Gnere
     * @return Movie* Copy
     */
    DynamicVector filterMoviesByGenre(std::optional<MovieGenre> genre = std::nullopt);
};