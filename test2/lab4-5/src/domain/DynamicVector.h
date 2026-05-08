#pragma once

#include "Movie.h"
#include <string>

typedef Movie TElem;
typedef int TElemId;
typedef std::string TElemIdentifier;

class MemoryRepo;
class DynamicVectorIterator;
class DynamicVectorTests;
class MovieServicesTests;

template <typename TElem, typename TElemId, typename TElemIdentifier>
class DynamicVector
{

    friend class MemoryRepo;
    friend class DynamicVectorIterator;
    friend class DynamicVectorTests;
    friend class MovieServicesTests;

private:
    int size, capacity, factor;
    TElem *elems;

    /**
     * @brief Resizes the vector when capacity is reached.
     *
     */
    void resize();

    /**
     * @brief Gets an elem by given id.
     *
     * @exception Throws std::exception if it cannot find the elem.
     * @param id Given id.
     * @return TElem
     */
    TElem getElemById(TElemId id);

    /**
     * @brief Gets an elem by given identiifer.
     *
     * @exception Throws std::exception if it cannot find the elem.
     * @param identifier Given identifier.
     * @return TElem
     */
    TElem getElemByIdentifier(TElemIdentifier identifier);

public:
    /**
     * @brief Constructor.
     *
     * @param capacity the initial max capacity of vector, default = 5
     * @param factor the factor scaling the vector, default = 2
     */
    DynamicVector(int capacity = 5, int factor = 2);

    /**
     * @brief Copy constructor.
     *
     * @param other the DynamicVector to copy from
     */
    DynamicVector(const DynamicVector &other);

    /**
     * @brief Assignment operator.
     *
     * @param other the DynamicVector to assign from
     * @return DynamicVector& reference to this vector
     */
    DynamicVector &operator=(const DynamicVector &other);

    /**
     * @brief Destructor.
     *
     */
    ~DynamicVector();

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
    void add(const TElem &elem);

    /**
     * @brief Removes a TElem elem from the list of elements by its id.
     *
     * @param id
     */
    void remove(TElemId id);

    /**
     * @brief Clears the dynamic vector.
     *
     */
    void clear();

    /**
     * @brief Iterator starting from the first element.
     *
     * @return DynamicVectorIterator
     */
    DynamicVectorIterator begin() const;

    /**
     * @brief Iterator starting from the last element.
     *
     * @return DynamicVectorIterator
     */
    DynamicVectorIterator end() const;
};