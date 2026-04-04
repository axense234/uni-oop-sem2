#include "Helpers.tests.h"
#include <iostream>
#include <cassert>
#include <exception>

using namespace std;

MovieServices *HelpersTests::createTestServices()
{
    MemoryRepo *database = new MemoryRepo();
    return new MovieServices(*database);
}

void HelpersTests::testConvertGivenStringToMovieGenre()
{
    cout << "Testing convertGivenStringToMovieGenre()..." << endl;

    assert(Helpers::convertGivenStringToMovieGenre("ACTION") == ACTION);
    assert(Helpers::convertGivenStringToMovieGenre("ADVENTURE") == ADVENTURE);
    assert(Helpers::convertGivenStringToMovieGenre("ANIMATION") == ANIMATION);
    assert(Helpers::convertGivenStringToMovieGenre("BIOGRAPHY") == BIOGRAPHY);
    assert(Helpers::convertGivenStringToMovieGenre("COMEDY") == COMEDY);
    assert(Helpers::convertGivenStringToMovieGenre("CRIME") == CRIME);
    assert(Helpers::convertGivenStringToMovieGenre("DOCUMENTARY") == DOCUMENTARY);
    assert(Helpers::convertGivenStringToMovieGenre("DRAMA") == DRAMA);
    assert(Helpers::convertGivenStringToMovieGenre("FAMILY") == FAMILY);
    assert(Helpers::convertGivenStringToMovieGenre("FANTASY") == FANTASY);
    assert(Helpers::convertGivenStringToMovieGenre("HISTORY") == HISTORY);
    assert(Helpers::convertGivenStringToMovieGenre("HORROR") == HORROR);
    assert(Helpers::convertGivenStringToMovieGenre("MUSIC") == MUSIC);
    assert(Helpers::convertGivenStringToMovieGenre("MYSTERY") == MYSTERY);
    assert(Helpers::convertGivenStringToMovieGenre("ROMANCE") == ROMANCE);
    assert(Helpers::convertGivenStringToMovieGenre("SCIFI") == SCIFI);
    assert(Helpers::convertGivenStringToMovieGenre("SPORT") == SPORT);
    assert(Helpers::convertGivenStringToMovieGenre("WAR") == WAR);
    assert(Helpers::convertGivenStringToMovieGenre("WESTERN") == WESTERN);

    cout << "convertGivenStringToMovieGenre() test passed" << endl;
}

void HelpersTests::testConvertGivenStringToMovieGenreInvalid()
{
    cout << "Testing convertGivenStringToMovieGenre() with invalid input..." << endl;

    bool exceptionThrown = false;
    try
    {
        Helpers::convertGivenStringToMovieGenre("INVALID_GENRE");
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try
    {
        Helpers::convertGivenStringToMovieGenre("");
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try
    {
        Helpers::convertGivenStringToMovieGenre("action");
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    cout << "convertGivenStringToMovieGenre() with invalid input test passed" << endl;
}

void HelpersTests::testConvertGivenMovieGenreToString()
{
    cout << "Testing convertGivenMovieGenreToString()..." << endl;

    assert(Helpers::convertGivenMovieGenreToString(ACTION) == "ACTION");
    assert(Helpers::convertGivenMovieGenreToString(ADVENTURE) == "ADVENTURE");
    assert(Helpers::convertGivenMovieGenreToString(ANIMATION) == "ANIMATION");
    assert(Helpers::convertGivenMovieGenreToString(BIOGRAPHY) == "BIOGRAPHY");
    assert(Helpers::convertGivenMovieGenreToString(COMEDY) == "COMEDY");
    assert(Helpers::convertGivenMovieGenreToString(CRIME) == "CRIME");
    assert(Helpers::convertGivenMovieGenreToString(DOCUMENTARY) == "DOCUMENTARY");
    assert(Helpers::convertGivenMovieGenreToString(DRAMA) == "DRAMA");
    assert(Helpers::convertGivenMovieGenreToString(FAMILY) == "FAMILY");
    assert(Helpers::convertGivenMovieGenreToString(FANTASY) == "FANTASY");
    assert(Helpers::convertGivenMovieGenreToString(HISTORY) == "HISTORY");
    assert(Helpers::convertGivenMovieGenreToString(HORROR) == "HORROR");
    assert(Helpers::convertGivenMovieGenreToString(MUSIC) == "MUSIC");
    assert(Helpers::convertGivenMovieGenreToString(MYSTERY) == "MYSTERY");
    assert(Helpers::convertGivenMovieGenreToString(ROMANCE) == "ROMANCE");
    assert(Helpers::convertGivenMovieGenreToString(SCIFI) == "SCIFI");
    assert(Helpers::convertGivenMovieGenreToString(SPORT) == "SPORT");
    assert(Helpers::convertGivenMovieGenreToString(WAR) == "WAR");
    assert(Helpers::convertGivenMovieGenreToString(WESTERN) == "WESTERN");

    cout << "convertGivenMovieGenreToString() test passed" << endl;
}

void HelpersTests::testConvertGivenMovieGenreToStringInvalid()
{
    cout << "Testing convertGivenMovieGenreToString() with invalid genre..." << endl;

    bool exceptionThrown = false;
    try
    {
        Helpers::convertGivenMovieGenreToString(static_cast<MovieGenre>(-1));
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try
    {
        Helpers::convertGivenMovieGenreToString(static_cast<MovieGenre>(100));
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    cout << "convertGivenMovieGenreToString() with invalid genre test passed" << endl;
}

void HelpersTests::testInsertTenMovieEntriesInTheDatabase()
{
    cout << "Testing insertTenMovieEntriesInTheDatabase()..." << endl;

    MovieServices *services = createTestServices();

    assert(services->repo.size() == 0);

    Helpers::insertTenMovieEntriesInTheDatabase(*services);

    assert(services->repo.size() == 10);

    Movie movie1 = services->repo.getElemById(1);
    assert(movie1.getId() == 1);
    assert(movie1.getTitle() == "The Shawshank Redemption");
    assert(movie1.getGenre() == HORROR);

    Movie movie5 = services->repo.getElemById(5);
    assert(movie5.getId() == 5);
    assert(movie5.getTitle() == "The Dark Knight");
    assert(movie5.getGenre() == ADVENTURE);

    Movie movie10 = services->repo.getElemById(10);
    assert(movie10.getId() == 10);
    assert(movie10.getTitle() == "Interstellar");
    assert(movie10.getGenre() == ADVENTURE);

    bool exceptionThrown = false;
    try
    {
        services->repo.getElemById(11);
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    delete services;

    cout << "insertTenMovieEntriesInTheDatabase() test passed" << endl;
}
void HelpersTests::testOpenURL()
{
    cout << "Testing openURL()..." << endl;

    cout << "  Note: This test actually opens browser windows" << endl;
    cout << "  Testing with valid URL..." << endl;

    try
    {
        Helpers::openURL("https://www.google.com");
        cout << "  Valid URL test completed (browser should have opened)" << endl;
    }
    catch (exception &)
    {
        cout << "  Valid URL test failed" << endl;
        assert(false);
    }

    cout << "  Testing with empty URL..." << endl;

    try
    {
        Helpers::openURL("");
        cout << "  Empty URL test completed" << endl;
    }
    catch (exception &)
    {
        cout << "  Empty URL test completed (exception caught)" << endl;
    }

    cout << "  Testing with invalid URL format..." << endl;

    try
    {
        Helpers::openURL("not a valid url");
        cout << "  Invalid URL test completed" << endl;
    }
    catch (exception &)
    {
        cout << "  Invalid URL test completed (exception caught)" << endl;
    }

    cout << "openURL() test passed" << endl;
    cout << "  Warning: Manual verification may be needed for browser opening" << endl;
}

void HelpersTests::runAllHelpersTests()
{
    testConvertGivenStringToMovieGenre();
    testConvertGivenStringToMovieGenreInvalid();
    testConvertGivenMovieGenreToString();
    testConvertGivenMovieGenreToStringInvalid();
    testInsertTenMovieEntriesInTheDatabase();
    testOpenURL();
}