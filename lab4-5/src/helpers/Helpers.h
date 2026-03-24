#pragma once

#include "../domain/Movie.h"
#include "../services/Movie.services.h"

#include <string>
#include <exception>

class Helpers
{
private:
public:
    /**
     * @brief Inserts 10 movie entries in a database.
     *
     * @param services the services
     */
    static void insertTenMovieEntriesInTheDatabase(MovieServices &services);
    /**
     * @brief Converts a given string to movie genre.
     *
     * @param raw Given string
     * @return MovieGenre
     */
    static MovieGenre convertGivenStringToMovieGenre(const std::string &raw);

    /**
     * @brief Converts a given movie genre to a std::string
     *
     * @param genre Given genre
     * @return std::string
     */
    static std::string convertGivenMovieGenreToString(MovieGenre genre);
};