#pragma once

#include "../repo/Memory.repo.h"
#include "../domain/Movie.h"
#include "../repo/Repo.repo.h"
#include "../exceptions/MovieServicesException.h"
#include "../exceptions/RepoException.h"

#include <optional>

class MenuUI;
class HelpersTests;

class MovieServices
{
    friend class MenuUI;
    friend class HelpersTests;

private:
    Repo<TElem, TElemId, TElemField> &repo;

public:
    /**
     * @brief Constructor.
     *
     * @param repo reference to a repo
     */
    MovieServices(Repo<TElem, TElemId, TElemField> &repo);

    /**
     * @brief Adds a movie to the repository.
     *
     * @param movie Movie to be added.
     * @throw MovieServicesException if a movie with the same title already exists -> TODO
     * @throw RepoException if the repository failed to add the movie
     */
    void addMovie(Movie movie) noexcept(false);

    /**
     * @brief Removes a movie from the repository by id.
     *
     * @param id Id of the movie.
     * @throw RepoException if the repository failed to remove the movie
     */
    void removeMovieById(int id) noexcept(false);

    /**
     * @brief Updates a movie in the repository by id and given payload.
     *
     * @param id Id of the movie.
     * @param payload Update Movie object.
     * @throw RepoException if elem couldnt be found in the repo or couldn't be updated
     */
    void updateMovieById(int id, Movie payload) noexcept(false);

    /**
     * @brief Finds and returns a movie by given id.
     *
     * @param id int
     * @throw RepoException if movie couldn't be found by id
     * @return Movie found movie
     */
    Movie getMovieById(int id) const noexcept(false);

    /**
     * @brief Finds and returns a movie by given title.
     *
     * @param title given title
     * @throw RepoException if movie couldn't be found by title
     * @return Movie found movie
     */
    Movie getMovieByTitle(std::string name) const noexcept(false);

    /**
     * @brief Filters repo movies by genre and returns a copy of those movies.
     *
     * @param genre Genre
     * @return std::vector<TElem> copy
     */
    std::vector<TElem> filterMoviesByGenre(MovieGenre genre = EMPTY) const noexcept;

    /**
     * @brief Returns an unmodifiable reference to the elems in the repo.
     */
    std::vector<TElem> &getElems() const noexcept;
};