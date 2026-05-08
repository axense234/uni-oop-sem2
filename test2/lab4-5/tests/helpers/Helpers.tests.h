#pragma once

#include "../../src/helpers/Helpers.h"
#include "../../src/services/Movie.services.h"

class HelpersTests
{
private:
    MovieServices *createTestServices();

public:
    void testConvertGivenStringToMovieGenre();
    void testConvertGivenStringToMovieGenreInvalid();
    void testConvertGivenMovieGenreToString();
    void testConvertGivenMovieGenreToStringInvalid();
    void testInsertTenMovieEntriesInTheDatabase();
    void testOpenURL();

    void runAllHelpersTests();
};
