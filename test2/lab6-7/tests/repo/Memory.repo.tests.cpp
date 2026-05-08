#include "Memory.repo.tests.h"
#include <exception>

using namespace std;

Movie MemoryRepoTests::createTestMovie(int id, const string &title, MovieGenre genre, short year, int likes, const string &trailer)
{
    return Movie(id, title, genre, year, likes, trailer);
}

void MemoryRepoTests::testConstructor()
{
    cout << "Testing MemoryRepo constructor..." << endl;

    MemoryRepo repo;
    assert(repo.size() == 0);

    cout << "MemoryRepo constructor test passed" << endl;
}

void MemoryRepoTests::testAdd()
{
    cout << "Testing add()..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(2, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    bool result1 = repo.add(m1);
    assert(result1 == true);
    assert(repo.size() == 1);

    bool result2 = repo.add(m2);
    assert(result2 == true);
    assert(repo.size() == 2);

    cout << "add() test passed" << endl;
}

void MemoryRepoTests::testAddDuplicate()
{
    cout << "Testing add() with duplicate ID..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(1, "Inception 2", ACTION, 2020, 2000, "trailer2");

    bool result1 = repo.add(m1);
    assert(result1 == true);
    assert(repo.size() == 1);

    bool result2 = repo.add(m2);
    assert(result2 == true);
    assert(repo.size() == 2);

    cout << "add() with duplicate ID test passed" << endl;
}

void MemoryRepoTests::testRemoveById()
{
    cout << "Testing removeById()..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    Movie m2 = createTestMovie(2, "Movie2", COMEDY, 2021, 200, "trailer2");
    Movie m3 = createTestMovie(3, "Movie3", DRAMA, 2022, 300, "trailer3");

    repo.add(m1);
    repo.add(m2);
    repo.add(m3);
    assert(repo.size() == 3);

    bool result = repo.removeById(2);
    assert(result == true);
    assert(repo.size() == 2);

    result = repo.removeById(1);
    assert(result == true);
    assert(repo.size() == 1);

    result = repo.removeById(3);
    assert(result == true);
    assert(repo.size() == 0);

    cout << "removeById() test passed" << endl;
}

void MemoryRepoTests::testRemoveNonExistent()
{
    cout << "Testing removeById() with non-existent ID..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    repo.add(m1);

    bool result = repo.removeById(999);
    assert(result == false);
    assert(repo.size() == 1);

    cout << "removeById() with non-existent ID test passed" << endl;
}

void MemoryRepoTests::testUpdateById()
{
    cout << "Testing updateById()..." << endl;

    MemoryRepo repo;
    Movie original = createTestMovie(1, "Original Title", ACTION, 2020, 100, "original_trailer");
    repo.add(original);

    Movie updated = createTestMovie(1, "Updated Title", COMEDY, 2021, 200, "updated_trailer");

    bool result = repo.updateById(1, updated);
    assert(result == true);
    assert(repo.size() == 1);

    cout << "updateById() test passed" << endl;
}

void MemoryRepoTests::testUpdateNonExistent()
{
    cout << "Testing updateById() with non-existent ID..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    repo.add(m1);

    Movie updated = createTestMovie(999, "Updated Title", COMEDY, 2021, 200, "trailer2");

    bool result = repo.updateById(999, updated);
    assert(result == false);
    assert(repo.size() == 1);

    cout << "updateById() with non-existent ID test passed" << endl;
}

void MemoryRepoTests::testSize()
{
    cout << "Testing size()..." << endl;

    MemoryRepo repo;
    assert(repo.size() == 0);

    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    repo.add(m1);
    assert(repo.size() == 1);

    Movie m2 = createTestMovie(2, "Movie2", COMEDY, 2021, 200, "trailer2");
    repo.add(m2);
    assert(repo.size() == 2);

    repo.removeById(1);
    assert(repo.size() == 1);

    repo.removeById(2);
    assert(repo.size() == 0);

    cout << "size() test passed" << endl;
}

void MemoryRepoTests::testGetElemByTitle()
{
    cout << "Testing getElemByTitle()..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(2, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    repo.add(m1);
    repo.add(m2);

    try
    {
        TElem found = repo.getElemById(1);
        assert(found.getId() == 1);
        assert(found.getTitle() == "Inception");

        found = repo.getElemById(2);
        assert(found.getId() == 2);
        assert(found.getTitle() == "The Matrix");
    }
    catch (exception &)
    {
        assert(false);
    }

    cout << "getElemById() test passed" << endl;
}

void MemoryRepoTests::testGetElemById()
{
    cout << "Testing getElemById()..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(2, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    repo.add(m1);
    repo.add(m2);

    try
    {
        TElem found = repo.getElemByTitle("Inception");
        assert(found.getId() == 1);
        assert(found.getTitle() == "Inception");

        found = repo.getElemByTitle("The Matrix");
        assert(found.getId() == 2);
        assert(found.getTitle() == "The Matrix");
    }
    catch (exception &)
    {
        assert(false);
    }

    cout << "getElemByTitle() test passed" << endl;
}

void MemoryRepoTests::testGetElemByIdNonExistent()
{
    cout << "Testing getElemById() with non-existent ID..." << endl;

    MemoryRepo repo;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    repo.add(m1);

    bool exceptionThrown = false;
    try
    {
        repo.getElemById(999);
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    cout << "getElemById() with non-existent ID test passed" << endl;
}

void MemoryRepoTests::testMultipleOperations()
{
    cout << "Testing multiple operations..." << endl;

    MemoryRepo repo;

    for (int i = 1; i <= 50; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        repo.add(movie);
    }
    assert(repo.size() == 50);

    for (int i = 10; i <= 40; i += 10)
    {
        repo.removeById(i);
    }
    assert(repo.size() == 46);

    for (int i = 51; i <= 70; i++)
    {
        Movie movie = createTestMovie(i, "NewMovie" + to_string(i), COMEDY, 2021, i * 50, "newtrailer" + to_string(i));
        repo.add(movie);
    }
    assert(repo.size() == 66);

    for (int i = 51; i <= 70; i++)
    {
        Movie updated = createTestMovie(i, "UpdatedMovie" + to_string(i), DRAMA, 2022, i * 200, "updatedtrailer" + to_string(i));
        repo.updateById(i, updated);
    }
    assert(repo.size() == 66);

    for (int i = 1; i <= 70; i++)
    {
        repo.removeById(i);
    }
    assert(repo.size() == 0);

    cout << "Multiple operations test passed" << endl;
}

void MemoryRepoTests::testEdgeCases()
{
    cout << "Testing edge cases..." << endl;

    MemoryRepo repo;

    const int largeNumber = 500;
    for (int i = 1; i <= largeNumber; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i, "trailer" + to_string(i));
        repo.add(movie);
    }
    assert(repo.size() == largeNumber);

    for (int i = largeNumber; i > largeNumber - 100; i--)
    {
        repo.removeById(i);
    }
    assert(repo.size() == largeNumber - 100);

    for (int i = 1; i <= 100; i++)
    {
        repo.removeById(i);
    }
    assert(repo.size() == largeNumber - 200);

    cout << "Edge cases test passed" << endl;
}

void MemoryRepoTests::runAllMemoryRepoTests()
{

    testConstructor();
    testAdd();
    testAddDuplicate();
    testRemoveById();
    testRemoveNonExistent();
    testUpdateById();
    testUpdateNonExistent();
    testSize();
    testGetElemById();
    testGetElemByTitle();
    testGetElemByIdNonExistent();
    testMultipleOperations();
    testEdgeCases();
}