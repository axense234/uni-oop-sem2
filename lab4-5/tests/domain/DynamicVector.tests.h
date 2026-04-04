#pragma once

#include "../../src/domain/DynamicVector.h"
#include "../../src/domain/Movie.h"
#include <string>

using namespace std;

class DynamicVectorTests
{
private:
    Movie createTestMovie(int id, const string &title, MovieGenre genre, short year, int likes, const string &trailer);

public:
    // Existing tests
    void testConstructor();
    void testCopyConstructor();
    void testAssignmentOperator();
    void testLength();
    void testAdd();
    void testAddWithResize();
    void testRemove();
    void testRemoveNonExistent();
    void testClear();
    void testGetElemById();
    void testGetElemByIdNonExistent();
    void testGetElemByIdentifier();
    void testGetElemByIdentifierNonExistent();
    void testIterator();
    void testMultipleOperations();
    void testEdgeCases();
    void testMemoryManagement();
    void testConstCorrectness();
    void testResize();

    void runAllDynamicVectorTests();
};
