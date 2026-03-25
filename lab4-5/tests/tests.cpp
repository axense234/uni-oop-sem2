#include <iostream>
#include <exception>

#include "../tests/domain/Movie.tests.h"
#include "../tests/domain/DynamicVector.tests.h"
#include "../tests/services/Movie.services.tests.h"
#include "../tests/repo/Memory.repo.tests.h"

using namespace std;

int main()
{

    MovieTests movieTests;
    movieTests.runAllMovieTests();

    DynamicVectorTests dynamicVectorTests;
    dynamicVectorTests.runAllDynamicVectorTests();

    MemoryRepoTests memoryRepoTests;
    memoryRepoTests.runAllMemoryRepoTests();

    MovieServicesTests movieServicesTests;
    movieServicesTests.runAllMovieServicesTests();

    return 0;
}
