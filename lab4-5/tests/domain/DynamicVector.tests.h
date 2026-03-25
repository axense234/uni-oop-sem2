#pragma once
#include "../../src/domain/DynamicVector.h"
#include "../../src/domain/Movie.h"
#include <cassert>
#include <iostream>
#include <string>

class DynamicVectorTests
{
private:
    Movie createTestMovie(int id, const std::string &title, MovieGenre genre, short year, int likes, const std::string &trailer);

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
    void testIterator();
    void testMultipleOperations();
    void testEdgeCases();
    void testMemoryManagement();
    void testConstCorrectness();

public:
    void runAllDynamicVectorTests();
};