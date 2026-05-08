#pragma once
#include "../../src/domain/Movie.h"
#include <cassert>
#include <iostream>
#include <string>

class MovieTests
{
private:
    void testDefaultConstructor();
    void testParameterizedConstructor();
    void testGetters();
    void testSetters();
    void testIdManipulation();
    void testAllGenres();
    void testStringHandling();
    void testEdgeCases();
    void testConstCorrectness();

public:
    void runAllMovieTests();
};