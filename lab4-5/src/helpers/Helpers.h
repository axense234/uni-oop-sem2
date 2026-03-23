#pragma once

#include "../domain/Movie.h"

#include <string>
#include <exception>

class Helpers
{
private:
public:
    /**
     * @brief Converts a given string to movie genre.
     *
     * @param raw Given string
     * @return MovieGenre
     */
    static MovieGenre convertGivenStringToMovieGenre(const std::string &raw);
};