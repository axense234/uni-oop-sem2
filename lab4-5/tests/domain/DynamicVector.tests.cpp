#include "DynamicVector.tests.h"
#include "../../src/domain/DynamicVectorIterator.h"
#include <exception>

using namespace std;

Movie DynamicVectorTests::createTestMovie(int id, const string &title, MovieGenre genre, short year, int likes, const string &trailer)
{
    return Movie(id, title, genre, year, likes, trailer);
}

void DynamicVectorTests::testConstructor()
{
    cout << "Testing constructor..." << endl;

    DynamicVector v1;
    assert(v1.length() == 0);

    DynamicVector v2(10);
    assert(v2.length() == 0);

    DynamicVector v3(15, 3);
    assert(v3.length() == 0);

    cout << "Constructor test passed" << endl;
}

void DynamicVectorTests::testCopyConstructor()
{
    cout << "Testing copy constructor..." << endl;

    DynamicVector original;
    Movie m1 = createTestMovie(1, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(2, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    original.add(m1);
    original.add(m2);

    DynamicVector copy(original);

    assert(copy.length() == original.length());
    assert(copy.length() == 2);

    DynamicVectorIterator it1 = original.iterator();
    DynamicVectorIterator it2 = copy.iterator();

    while (it1.valid() && it2.valid())
    {
        assert(it1.getCurrent().getId() == it2.getCurrent().getId());
        it1.next();
        it2.next();
    }

    original.clear();
    assert(original.length() == 0);
    assert(copy.length() == 2);

    cout << "Copy constructor test passed" << endl;
}

void DynamicVectorTests::testAssignmentOperator()
{
    cout << "Testing assignment operator..." << endl;

    DynamicVector v1;
    Movie m1 = createTestMovie(1, "Inception", SCIFI, 2010, 1000, "trailer1");
    Movie m2 = createTestMovie(2, "The Matrix", SCIFI, 1999, 2000, "trailer2");

    v1.add(m1);
    v1.add(m2);

    DynamicVector v2;
    v2 = v1;

    assert(v2.length() == v1.length());
    assert(v2.length() == 2);

    v1 = v1;
    assert(v1.length() == 2);

    DynamicVector v3;
    v3 = v2 = v1;
    assert(v3.length() == 2);

    cout << "Assignment operator test passed" << endl;
}

void DynamicVectorTests::testLength()
{
    cout << "Testing length()..." << endl;

    DynamicVector v;
    assert(v.length() == 0);

    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    v.add(m1);
    assert(v.length() == 1);

    Movie m2 = createTestMovie(2, "Movie2", COMEDY, 2021, 200, "trailer2");
    v.add(m2);
    assert(v.length() == 2);

    v.remove(1);
    assert(v.length() == 1);

    v.clear();
    assert(v.length() == 0);

    cout << "length() test passed" << endl;
}

void DynamicVectorTests::testAdd()
{
    cout << "Testing add()..." << endl;

    DynamicVector v;

    for (int i = 1; i <= 5; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
        assert(v.length() == i);
    }

    DynamicVectorIterator it = v.iterator();
    int expectedId = 1;
    while (it.valid())
    {
        assert(it.getCurrent().getId() == expectedId);
        expectedId++;
        it.next();
    }

    cout << "add() test passed" << endl;
}

void DynamicVectorTests::testAddWithResize()
{
    cout << "Testing add() with automatic resize..." << endl;

    DynamicVector v;

    for (int i = 1; i <= 10; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }

    assert(v.length() == 10);

    for (int i = 1; i <= 10; i++)
    {
        bool found = false;
        DynamicVectorIterator it = v.iterator();
        while (it.valid())
        {
            if (it.getCurrent().getId() == i)
            {
                found = true;
                break;
            }
            it.next();
        }
        assert(found);
    }

    for (int i = 11; i <= 20; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }

    assert(v.length() == 20);

    cout << "add() with resize test passed" << endl;
}

void DynamicVectorTests::testRemove()
{
    cout << "Testing remove()..." << endl;

    DynamicVector v;

    for (int i = 1; i <= 5; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }

    v.remove(3);
    assert(v.length() == 4);

    DynamicVectorIterator it = v.iterator();
    int expectedIds[] = {1, 2, 4, 5};
    for (int i = 0; i < 4; i++)
    {
        assert(it.valid());
        assert(it.getCurrent().getId() == expectedIds[i]);
        it.next();
    }

    cout << "remove() test passed" << endl;
}

void DynamicVectorTests::testRemoveNonExistent()
{
    cout << "Testing remove() with non-existent element..." << endl;

    DynamicVector v;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    v.add(m1);

    bool exceptionThrown = false;
    try
    {
        v.remove(999);
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
    assert(v.length() == 1);

    cout << "remove() with non-existent element test passed" << endl;
}

void DynamicVectorTests::testClear()
{
    cout << "Testing clear()..." << endl;

    DynamicVector v;

    v.clear();
    assert(v.length() == 0);

    for (int i = 1; i <= 5; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }
    assert(v.length() == 5);

    v.clear();
    assert(v.length() == 0);

    Movie newMovie = createTestMovie(10, "New Movie", COMEDY, 2022, 500, "newtrailer");
    v.add(newMovie);
    assert(v.length() == 1);

    cout << "clear() test passed" << endl;
}

void DynamicVectorTests::testGetElemById()
{
    cout << "Testing getElemById()..." << endl;

    DynamicVector v;

    for (int i = 1; i <= 5; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }

    Movie m3 = v.getElemById(3);
    assert(m3.getId() == 3);
    assert(m3.getTitle() == "Movie3");

    Movie m1 = v.getElemById(1);
    assert(m1.getId() == 1);

    Movie m5 = v.getElemById(5);
    assert(m5.getId() == 5);

    cout << "getElemById() test passed" << endl;
}

void DynamicVectorTests::testGetElemByIdNonExistent()
{
    cout << "Testing getElemById() with non-existent ID..." << endl;

    DynamicVector v;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    v.add(m1);

    bool exceptionThrown = false;
    try
    {
        v.getElemById(999);
    }
    catch (exception &)
    {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    cout << "getElemById() with non-existent ID test passed" << endl;
}

void DynamicVectorTests::testIterator()
{
    cout << "Testing iterator..." << endl;

    DynamicVector v;

    DynamicVectorIterator emptyIt = v.iterator();
    assert(emptyIt.valid() == false);

    for (int i = 1; i <= 5; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }

    DynamicVectorIterator it = v.iterator();
    int expectedId = 1;
    int count = 0;

    while (it.valid())
    {
        assert(it.getCurrent().getId() == expectedId);
        count++;
        expectedId++;
        it.next();
    }
    assert(count == 5);
    assert(it.valid() == false);

    v.remove(3);

    DynamicVectorIterator newIt = v.iterator();

    int expectedIds[] = {1, 2, 4, 5};
    int index = 0;
    while (newIt.valid())
    {
        assert(newIt.getCurrent().getId() == expectedIds[index]);
        index++;
        newIt.next();
    }
    assert(index == 4);
    assert(newIt.valid() == false);

    cout << "Iterator test passed" << endl;
}

void DynamicVectorTests::testMultipleOperations()
{
    cout << "Testing multiple operations in sequence..." << endl;

    DynamicVector v;

    for (int i = 1; i <= 100; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i * 100, "trailer" + to_string(i));
        v.add(movie);
    }
    assert(v.length() == 100);

    for (int i = 10; i <= 90; i += 10)
    {
        v.remove(i);
    }

    for (int i = 101; i <= 150; i++)
    {
        Movie movie = createTestMovie(i, "NewMovie" + to_string(i), COMEDY, 2021, i * 50, "newtrailer" + to_string(i));
        v.add(movie);
    }

    v.clear();

    for (int i = 1; i <= 20; i++)
    {
        Movie movie = createTestMovie(i, "FinalMovie" + to_string(i), DRAMA, 2022, i * 200, "finaltrailer" + to_string(i));
        v.add(movie);
    }
    assert(v.length() == 20);

    cout << "Multiple operations test passed" << endl;
}

void DynamicVectorTests::testEdgeCases()
{
    cout << "Testing edge cases..." << endl;

    DynamicVector v;

    const int largeNumber = 1000;
    for (int i = 1; i <= largeNumber; i++)
    {
        Movie movie = createTestMovie(i, "Movie" + to_string(i), ACTION, 2020, i, "trailer" + to_string(i));
        v.add(movie);
    }
    assert(v.length() == largeNumber);

    for (int i = largeNumber; i > largeNumber - 100; i--)
    {
        v.remove(i);
    }
    assert(v.length() == largeNumber - 100);

    for (int i = 1; i <= 100; i++)
    {
        v.remove(i);
    }
    assert(v.length() == largeNumber - 200);

    cout << "Edge cases test passed" << endl;
}

void DynamicVectorTests::testMemoryManagement()
{
    cout << "Testing memory management..." << endl;

    DynamicVector v1;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    v1.add(m1);

    DynamicVector v2 = v1;

    v1.clear();

    assert(v2.length() == 1);
    assert(v2.getElemById(1).getId() == 1);

    DynamicVector v3;
    v3 = v2;
    v2.clear();
    assert(v3.length() == 1);

    cout << "Memory management test passed" << endl;
}

void DynamicVectorTests::testConstCorrectness()
{
    cout << "Testing const correctness..." << endl;

    DynamicVector v;
    Movie m1 = createTestMovie(1, "Movie1", ACTION, 2020, 100, "trailer1");
    v.add(m1);

    const DynamicVector &constV = v;

    assert(constV.length() == 1);

    DynamicVectorIterator it = constV.iterator();
    assert(it.valid());
    assert(it.getCurrent().getId() == 1);

    cout << "Const correctness test passed" << endl;
}

void DynamicVectorTests::runAllDynamicVectorTests()
{
    testConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testLength();
    testAdd();
    testAddWithResize();
    testRemove();
    testRemoveNonExistent();
    testClear();
    testGetElemById();
    testGetElemByIdNonExistent();
    testIterator();
    testMultipleOperations();
    testEdgeCases();
    testMemoryManagement();
    testConstCorrectness();
}