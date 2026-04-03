#include "Playlist.services.tests.h"
#include <exception>

using namespace std;

Movie PlaylistServicesTests::createTestMovie(int id, const string &title, MovieGenre genre, short year, int likes, const string &trailer)
{
    return Movie(id, title, genre, year, likes, trailer);
}

void PlaylistServicesTests::testConstructor()
{
    cout << "Testing PlaylistServicesTests constructor..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    assert(services.getMovieById(1).getId() == -1);

    cout << "PlaylistServicesTests constructor test passed" << endl;
}

void PlaylistServicesTests::testAddMovie()
{
    cout << "Testing addMovie()..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(0, "Inception", SCIFI, 2010, 1000, "trailer1");

    bool result = services.addMovie(m1);
    assert(result == true);

    Movie found = services.getMovieById(1);
    assert(found.getId() == 1);
    assert(found.getTitle() == "Inception");
    assert(found.getGenre() == SCIFI);
    assert(found.getYearOfRelease() == 2010);
    assert(found.getNumberOfLikes() == 1000);

    cout << "addMovie() test passed" << endl;
}

void PlaylistServicesTests::testAddMultipleMovies()
{
    cout << "Testing addMovie() with multiple movies..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(0, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(0, "The Matrix", SCIFI, 1999, 2000, "trailer2");
    Movie m3 = createTestMovie(0, "Interstellar", SCIFI, 2014, 1500, "trailer3");

    bool result1 = services.addMovie(m1);
    bool result2 = services.addMovie(m2);
    bool result3 = services.addMovie(m3);

    assert(result1 == true);
    assert(result2 == true);
    assert(result3 == true);

    Movie found1 = services.getMovieById(1);
    Movie found2 = services.getMovieById(2);
    Movie found3 = services.getMovieById(3);

    assert(found1.getTitle() == "Inception");
    assert(found2.getTitle() == "The Matrix");
    assert(found3.getTitle() == "Interstellar");

    cout << "addMovie() with multiple movies test passed" << endl;
}

void PlaylistServicesTests::testAddMovieAutoId()
{
    cout << "Testing addMovie() auto-increment ID..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    for (int i = 1; i <= 10; i++)
    {
        Movie movie = createTestMovie(0, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        bool result = services.addMovie(movie);
        assert(result == true);

        Movie found = services.getMovieById(i);
        assert(found.getId() == i);
        assert(found.getTitle() == "Movie" + to_string(i));
    }

    cout << "addMovie() auto-increment ID test passed" << endl;
}

void PlaylistServicesTests::testRemoveMovieById()
{
    cout << "Testing removeMovieById()..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(0, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(0, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    services.addMovie(m1);
    services.addMovie(m2);

    bool result = services.removeMovieById(1);
    assert(result == true);

    Movie found = services.getMovieById(1);
    assert(found.getId() == -1);

    Movie found2 = services.getMovieById(2);
    assert(found2.getId() == 2);

    cout << "removeMovieById() test passed" << endl;
}

void PlaylistServicesTests::testRemoveNonExistentMovie()
{
    cout << "Testing removeMovieById() with non-existent ID..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(0, "Inception", SCIFI, 2010, 1000, "trailer1");
    services.addMovie(m1);

    bool result = services.removeMovieById(999);
    assert(result == false);

    Movie found = services.getMovieById(1);
    assert(found.getId() == 1);

    cout << "removeMovieById() with non-existent ID test passed" << endl;
}

void PlaylistServicesTests::testUpdateMovieById()
{
    cout << "Testing updateMovieById()..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie original = createTestMovie(0, "Original Title", ACTION, 2020, 100, "original_trailer");
    services.addMovie(original);
}

void PlaylistServicesTests::testGetMovieById()
{
    cout << "Testing getMovieById()..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(0, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(0, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    services.addMovie(m1);
    services.addMovie(m2);

    Movie found1 = services.getMovieById(1);
    assert(found1.getId() == 1);
    assert(found1.getTitle() == "Inception");

    Movie found2 = services.getMovieById(2);
    assert(found2.getId() == 2);
    assert(found2.getTitle() == "The Matrix");

    cout << "getMovieById() test passed" << endl;
}

void PlaylistServicesTests::testGetNonExistentMovie()
{
    cout << "Testing getMovieById() with non-existent ID..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(0, "Inception", SCIFI, 2010, 1000, "trailer1");
    services.addMovie(m1);

    Movie found = services.getMovieById(999);
    assert(found.getId() == -1);
    assert(found.getTitle() == "");

    cout << "getMovieById() with non-existent ID test passed" << endl;
}

void PlaylistServicesTests::testSequentialOperations()
{
    cout << "Testing sequential operations..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    for (int i = 1; i <= 20; i++)
    {
        Movie movie = createTestMovie(0, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        services.addMovie(movie);
    }
    assert(services.getMovieById(20).getId() == 20);

    for (int i = 5; i <= 15; i++)
    {
        services.removeMovieById(i);
    }
    assert(services.getMovieById(5).getId() == -1);
    assert(services.getMovieById(15).getId() == -1);
    assert(services.getMovieById(4).getId() == 4);
    assert(services.getMovieById(16).getId() == 16);

    for (int i = 1; i <= 4; i++)
    {
        Movie updated = createTestMovie(0, "Updated Movie" + to_string(i), COMEDY, 2022, i * 500, "updated_trailer" + to_string(i));
        services.updateMovieById(i, updated);
    }

    Movie found1 = services.getMovieById(1);
    assert(found1.getTitle() == "Updated Movie1");
    assert(found1.getGenre() == COMEDY);

    Movie found4 = services.getMovieById(4);
    assert(found4.getTitle() == "Updated Movie4");

    for (int i = 1; i <= 20; i++)
    {
        services.removeMovieById(i);
    }
    assert(services.getMovieById(1).getId() == -1);
    assert(services.getMovieById(20).getId() == -1);

    cout << "Sequential operations test passed" << endl;
}

void PlaylistServicesTests::testIdAutoIncrement()
{
    cout << "Testing ID auto-increment across operations..." << endl;

    MemoryRepo repo;
    MovieServices services(repo);

    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    Movie m2 = createTestMovie(2, "Movie2", COMEDY, 2021, 200, "trailer2");
    Movie m3 = createTestMovie(3, "Movie3", DRAMA, 2022, 300, "trailer3");

    services.addMovie(m1);
    assert(services.getMovieById(1).getId() == 1);

    services.addMovie(m2);
    assert(services.getMovieById(2).getId() == 2);

    services.removeMovieById(2);
    assert(services.getMovieById(2).getId() == -1);

    services.removeMovieById(1);
    services.addMovie(m1);

    cout << "ID auto-increment test passed" << endl;
}

void PlaylistServicesTests::runAllPlaylistServicesTests()
{

    testConstructor();
    testAddMovie();
    testAddMultipleMovies();
    testAddMovieAutoId();
    testRemoveMovieById();
    testRemoveNonExistentMovie();
    testUpdateMovieById();
    testGetMovieById();
    testGetNonExistentMovie();
    testSequentialOperations();
    testIdAutoIncrement();
}