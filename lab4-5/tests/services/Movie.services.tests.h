#pragma once
#include "../../src/services/Movie.services.h"
#include "../../src/domain/Movie.h"
#include <cassert>
#include <iostream>
#include <string>

class MovieServicesTests
{
private:
    Movie createTestMovie(int id, const std::string &title, MovieGenre genre, short year, int likes, const std::string &trailer);

    void testConstructor();
    void testAddMovie();
    void testAddMultipleMovies();
    void testAddMovieAutoId();
    void testRemoveMovieById();
    void testRemoveNonExistentMovie();
    void testUpdateMovieById();
    void testGetMovieById();
    void testGetNonExistentMovie();
    void testSequentialOperations();
    void testIdAutoIncrement();

public:
    void runAllMovieServicesTests();
};