#include "Movie.tests.h"
#include <iostream>
#include <string>

using namespace std;

void MovieTests::testDefaultConstructor()
{
    cout << "Testing default constructor..." << endl;

    Movie movie;

    assert(movie.getId() == -1);
    assert(movie.getTitle() == "");
    assert(movie.getGenre() == ACTION);
    assert(movie.getYearOfRelease() == 0);
    assert(movie.getNumberOfLikes() == 0);
    assert(movie.getTrailer() == "");

    cout << "Default constructor test passed" << endl;
}

void MovieTests::testParameterizedConstructor()
{
    cout << "Testing parameterized constructor..." << endl;

    Movie movie(1, "Inception", SCIFI, 2010, 1000, "https://youtube.com/inception");

    assert(movie.getId() == 1);
    assert(movie.getTitle() == "Inception");
    assert(movie.getGenre() == SCIFI);
    assert(movie.getYearOfRelease() == 2010);
    assert(movie.getNumberOfLikes() == 1000);
    assert(movie.getTrailer() == "https://youtube.com/inception");

    Movie movie2(2, "The Godfather", CRIME, 1972, 2000, "https://youtube.com/godfather");
    assert(movie2.getGenre() == CRIME);
    assert(movie2.getYearOfRelease() == 1972);

    cout << "Parameterized constructor test passed" << endl;
}

void MovieTests::testGetters()
{
    cout << "Testing getters..." << endl;

    Movie movie(5, "Toy Story", ANIMATION, 1995, 1500, "https://youtube.com/toystory");

    assert(movie.getId() == 5);
    assert(movie.getTitle() == "Toy Story");
    assert(movie.getGenre() == ANIMATION);
    assert(movie.getYearOfRelease() == 1995);
    assert(movie.getNumberOfLikes() == 1500);
    assert(movie.getTrailer() == "https://youtube.com/toystory");

    cout << "Getters test passed" << endl;
}

void MovieTests::testSetters()
{
    cout << "Testing setters..." << endl;

    Movie movie;

    movie.setTitle("Pulp Fiction");
    assert(movie.getTitle() == "Pulp Fiction");

    movie.setGenre(CRIME);
    assert(movie.getGenre() == CRIME);

    movie.setYearOfRelease(1994);
    assert(movie.getYearOfRelease() == 1994);

    movie.setNumberOfLikes(2500);
    assert(movie.getNumberOfLikes() == 2500);

    movie.setTrailer("https://youtube.com/pulpfiction");
    assert(movie.getTrailer() == "https://youtube.com/pulpfiction");

    movie.setTitle("The Dark Knight");
    movie.setGenre(ACTION);
    movie.setYearOfRelease(2008);
    movie.setNumberOfLikes(5000);

    assert(movie.getTitle() == "The Dark Knight");
    assert(movie.getGenre() == ACTION);
    assert(movie.getYearOfRelease() == 2008);
    assert(movie.getNumberOfLikes() == 5000);

    cout << "Setters test passed" << endl;
}

void MovieTests::testIdManipulation()
{
    cout << "Testing ID manipulation..." << endl;

    Movie movie(10, "Fight Club", DRAMA, 1999, 3000, "https://youtube.com/fightclub");

    assert(movie.getId() == 10);

    cout << "ID manipulation test passed" << endl;
}

void MovieTests::testAllGenres()
{
    cout << "Testing all movie genres..." << endl;

    MovieGenre genres[] = {
        ACTION, ADVENTURE, ANIMATION, BIOGRAPHY, COMEDY, CRIME,
        DOCUMENTARY, DRAMA, FAMILY, FANTASY, HISTORY, HORROR,
        MUSIC, MYSTERY, ROMANCE, SCIFI, SPORT, WAR, WESTERN};

    string genreNames[] = {
        "ACTION", "ADVENTURE", "ANIMATION", "BIOGRAPHY", "COMEDY", "CRIME",
        "DOCUMENTARY", "DRAMA", "FAMILY", "FANTASY", "HISTORY", "HORROR",
        "MUSIC", "MYSTERY", "ROMANCE", "SCIFI", "SPORT", "WAR", "WESTERN"};

    for (int i = 0; i < 19; i++)
    {
        Movie movie(i + 1, "Test Movie", genres[i], 2020, 100, "https://test.com");
        assert(movie.getGenre() == genres[i]);
        cout << "  Genre " << genreNames[i] << " works" << endl;
    }

    cout << "All genres test passed" << endl;
}

void MovieTests::testStringHandling()
{
    cout << "Testing string handling..." << endl;

    Movie movie1(1, "", ACTION, 2020, 0, "");
    assert(movie1.getTitle() == "");
    assert(movie1.getTrailer() == "");

    string longTitle = "This is a very long movie title that should be handled correctly by the class";
    string longTrailer = "https://youtube.com/verylongurlthatshouldbehandledcorrectlybytheclass";

    Movie movie2(2, longTitle, COMEDY, 2020, 100, longTrailer);
    assert(movie2.getTitle() == longTitle);
    assert(movie2.getTrailer() == longTrailer);

    Movie movie3(3, "Movie!@#$%^&*()", HORROR, 2020, 100, "https://test.com?q=!@#$");
    assert(movie3.getTitle() == "Movie!@#$%^&*()");

    movie3.setTitle("New Title");
    assert(movie3.getTitle() == "New Title");

    movie3.setTrailer("https://newtrailer.com");
    assert(movie3.getTrailer() == "https://newtrailer.com");

    cout << "String handling test passed" << endl;
}

void MovieTests::testEdgeCases()
{
    cout << "Testing edge cases..." << endl;

    Movie movie1(2147483647, "Max ID", ACTION, 32767, 2147483647, "https://test.com");
    assert(movie1.getId() == 2147483647);
    assert(movie1.getYearOfRelease() == 32767);
    assert(movie1.getNumberOfLikes() == 2147483647);

    Movie movie2(-1, "Negative ID", ACTION, -2020, -100, "https://test.com");
    assert(movie2.getId() == -1);
    assert(movie2.getYearOfRelease() == -2020);
    assert(movie2.getNumberOfLikes() == -100);

    Movie movie3(0, "Zero Values", ACTION, 0, 0, "https://test.com");
    assert(movie3.getId() == 0);
    assert(movie3.getYearOfRelease() == 0);
    assert(movie3.getNumberOfLikes() == 0);

    cout << "Edge cases test passed" << endl;
}

void MovieTests::testConstCorrectness()
{
    cout << "Testing const correctness..." << endl;

    const Movie movie(100, "Const Movie", DRAMA, 2020, 500, "https://const.com");

    assert(movie.getId() == 100);
    assert(movie.getTitle() == "Const Movie");
    assert(movie.getGenre() == DRAMA);
    assert(movie.getYearOfRelease() == 2020);
    assert(movie.getNumberOfLikes() == 500);
    assert(movie.getTrailer() == "https://const.com");

    cout << "Const correctness test passed" << endl;
}

void MovieTests::runAllMovieTests()
{

    testDefaultConstructor();
    testParameterizedConstructor();
    testGetters();
    testSetters();
    testIdManipulation();
    testAllGenres();
    testStringHandling();
    testEdgeCases();
    testConstCorrectness();
}