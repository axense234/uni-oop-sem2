#pragma once

#include "../../src/domain/Movie.h"

class MovieTests
{
private:
    Movie movie;

public:
    /**
     * @brief Constructor.
     *
     */
    MovieTests();

    void testProperties();
};