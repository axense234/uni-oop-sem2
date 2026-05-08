#pragma once

#include <vector>
#include <any>

template <typename TElem, typename TElemId, typename TElemField>
class Repo
{
public:
    /**
     * @brief Gets the outputFilePath of the repo. Returns "nothing" if memory repo is used.
     *
     * @return const std::string&
     */
    virtual const std::string &getOutputFilePath() const noexcept(false) = 0;

    /**
     * @brief Gets an element by matching given field with given value.
     *
     * @param field TElemField field of the elem
     * @param value std::any value matching value
     * @return TElem the element
     */
    virtual TElem &getElemByField(TElemField field, std::any value) noexcept(false) = 0;

    /**
     * @brief Returns the number of elems in the repo.
     *
     * @return int
     */
    virtual int getSize() const noexcept = 0;

    /**
     * @brief Adds an element in the repo.
     *
     * @param elem Elem to add.
     * @throw RepositoryException If add operation failed.
     */
    virtual void add(const TElem &elem) noexcept(false) = 0;
    /**
     * @brief Removes an element from the repo using by id.
     *
     * @param id The id of the elem desired to be removed.
     * @throw RepositoryException If remove operation failed.
     */
    virtual void remove(TElemId id) noexcept(false) = 0;
    /**
     * @brief Updates an element from the repo by id, using a payload.
     *
     * @param id Id of the desired elem to be updated.
     * @param payload Update payload.
     * @throw RepositoryException If update operation failed.
     */
    virtual void update(TElemId id, TElem payload) noexcept(false) = 0;
    /**
     * @brief Retrieves the elements of the repo or empty vector if there are no elems.
     *
     * @return std::vector<TElem>& elements of the repo
     */
    virtual std::vector<TElem> &getElems() noexcept(false) = 0;
    virtual const std::vector<TElem> &getElems() const noexcept(false) = 0;

    virtual ~Repo() = default;
};