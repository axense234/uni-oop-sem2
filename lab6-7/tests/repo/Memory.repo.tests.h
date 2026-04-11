#pragma once
#include "../../src/repo/Memory.repo.h"
#include "../../src/domain/Movie.h"
#include <cassert>
#include <iostream>
#include <string>

class MemoryRepoTests
{
private:
    Movie createTestMovie(int id, const std::string &title, MovieGenre genre, short year, int likes, const std::string &trailer);

    void testConstructor();
    void testAdd();
    void testAddDuplicate();
    void testRemoveById();
    void testRemoveNonExistent();
    void testUpdateById();
    void testUpdateNonExistent();
    void testSize();
    void testGetElemById();
    void testGetElemByTitle();
    void testGetElemByIdNonExistent();
    void testMultipleOperations();
    void testEdgeCases();

public:
    void runAllMemoryRepoTests();
};