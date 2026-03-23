#include <iostream>

#include "domain/DynamicVector.tests.h"
#include "domain/Movie.tests.h"

using namespace std;

int main()
{

    MovieTests movieTests;
    DynamicVectorTests dynamicVectorTests;

    movieTests.testProperties();

    dynamicVectorTests.testAdd();
    dynamicVectorTests.testRemove();

    cout << "yo" << endl;

    return 0;
}