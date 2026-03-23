#include "DynamicVector.tests.h"

#include <assert.h>
#include <iostream>

DynamicVectorTests::DynamicVectorTests()
{
    this->dynamicVector = DynamicVector{5};
};

void DynamicVectorTests::testAdd()
{

    std::cout << "yo" << std::endl;
    this->dynamicVector.clear();
    Movie movie;

    int currentLength = this->dynamicVector.length();
    this->dynamicVector.add(movie);
    std::cout << "yo" << std::endl;

    assert(currentLength + 1 == this->dynamicVector.length());

    std::cout << "yo" << std::endl;
}

void DynamicVectorTests::testRemove()
{

    this->dynamicVector.clear();
    Movie movie;

    int currentLength = this->dynamicVector.length();
    this->dynamicVector.add(movie);
    this->dynamicVector.remove(movie.getId());

    assert(currentLength == this->dynamicVector.length());
}
