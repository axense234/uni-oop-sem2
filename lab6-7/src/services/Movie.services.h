#pragma once

#include "../repo/Memory.repo.h"
#include "../domain/Movie.h"

#include <optional>

class MenuUI;
class HelpersTests;

class MovieServices
{
    friend class MenuUI;
    friend class HelpersTests;

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
     * @brief Finds and returns a movie by given title.
     *
     * @param title given title
     * @return Found Movie or Default Movie (with id = -1)
     */
    Movie getMovieByTitle(std::string name);

    /**
     * @brief Filters repo movies by genre and returns a copy of those movies.
     *
     * @param genre Genre
     * @return std::vector<TElem> copy
     */
    std::vector<TElem> filterMoviesByGenre(MovieGenre genre = EMPTY) const;

    /**
     * @brief Returns an unmodifiable copy of the elems in the repo.
     */
    std::vector<TElem> elems() const;
};