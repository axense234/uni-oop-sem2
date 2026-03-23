#pragma once

#include "Movie.h"

typedef Movie TElem;
typedef int TElemId;

class DynamicVector
{
private:
    int size, capacity, factor;
    TElem *elems;

public:
    /**
     * @brief Constructor.
     *
     * @param capacity the initial max capacity of vector, default = 5
     * @param factor the factor scaling the vector, default = 2
     */
    DynamicVector(int capacity = 5, int factor = 2);

    /**
     * @brief Returns the current length of the vector.
     *
     * @return int
     */
    int length() const;

    /**
     * @brief Adds a given TElem elem to the list of elements.
     *
     * @param elem
     */
    void add(TElem elem);

    /**
     * @brief Removes a TElem elem from the list of elements by it's id.
     *
     * @param elem
     */
    void remove(TElemId id);

private:
    void resize();
};