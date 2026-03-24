#pragma once

#include "../domain/DynamicVector.h"
#include "../domain/DynamicVectorIterator.h"

typedef DynamicVectorIterator MemoryRepoIterator;

class MovieServices;
class MenuUIController;

class MemoryRepo
{

    friend class MovieServices;
    friend class MenuUIController;

private:
    DynamicVector elements;

    /**
     * @brief Get an element by id.
     *
     * @exception Throws std::exception if the elem cannot be found.
     * @param id Id of desired elem.
     * @return TElem
     */
    TElem getElemById(TElemId id);

    /**
     * @brief Returns the elems iterator.
     */
    MemoryRepoIterator getElemsIterator() const;

public:
    /**
     * @brief Constructor.
     *
     */
    MemoryRepo();
    /**
     * @brief Adds an element in the repo.
     *
     * @param elem Elem to add.
     * @return true If add was a success.
     * @return false If add was not a success.
     */
    bool add(TElem elem);

    /**
     * @brief Removes an element from the repo using by id.
     *
     * @exception Throws std::exception if elem cannot be found.
     * @param id The id of the elem desired to be removed.
     * @return true If remove was successfull.
     * @return false If remove was not successfull.
     */
    bool removeById(TElemId id);

    /**
     * @brief Updates an element from the repo by id, using a payload.
     *
     * @exception Throws std::exception if elem cannot be found.
     * @param id Id of the desired elem to be updated.
     * @param payload Update payload.
     * @return true If update was a success.
     * @return false If update was not a success.
     */
    bool updateById(TElemId id, TElem payload);

    /**
     * @brief Returns the number of elems in the repo.
     *
     * @return int
     */
    int size();
};