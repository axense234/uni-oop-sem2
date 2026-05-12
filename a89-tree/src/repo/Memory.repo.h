#pragma once

#include "../domain/Movie.h"
#include "Repo.repo.h"
#include <vector>
#include <utility>
#include <string>

class MovieServices;
class PlaylistServices;
class MemoryRepoTests;
class MovieServicesTests;
class MenuUI;
class HelpersTests;

typedef Movie TElem;
typedef int TElemId;

typedef MovieField TElemField;

class MemoryRepo : public Repo<TElem, TElemId, TElemField>
{

    friend class MovieServices;
    friend class PlaylistServices;
    friend class MemoryRepoTests;
    friend class MovieServicesTests;
    friend class MenuUI;
    friend class HelpersTests;

private:
    std::vector<TElem> elements;

public:
    /**
     * @brief Retrieves the elements of the repo or empty vector if there are no elems.
     *
     * @return std::vector<TElem>& elements of the repo
     */
    virtual std::vector<TElem> &getElems() noexcept(false) override;
    virtual const std::vector<TElem> &getElems() const noexcept(false) override;

public:
    /**
     * @brief Gets an element by matching given field with given value.
     *
     * @param field TElemField field of the elem
     * @param value std::any value matching value
     * @throw RepoException if value doesnt match the type of the field, or the field doesnt exisst
     * @return TElem the element
     */
    TElem &getElemByField(TElemField field, std::any value) noexcept(false) override;

public:
    /**
     * @brief Constructor.
     *
     */
    MemoryRepo();

    /**
     * @brief Returns the number of elems in the repo.
     *
     * @return int
     */
    int getSize() const noexcept;

    /**
     * @brief Adds an element in the repo.
     *
     * @param elem Elem to add.
     * @throw RepoException if std::vector throws an exception for some reason
     */
    virtual void add(const TElem &elem) noexcept(false);

    /**
     * @brief Removes an element from the repo using by id.
     *
     * @param id The id of the elem desired to be removed.
     * @throw RepositoryException if we couldn't find the elem in the elems or std::vector throws an exception
     */
    virtual void remove(TElemId id) noexcept(false);

    /**
     * @brief Updates an element from the repo by id, using a payload.
     *
     * @param id Id of the desired elem to be updated.
     * @param payload Update payload.
     * @throw RepositoryException if we couldn't find the elem in the elems or std::vector throws an exception
     */
    virtual void update(TElemId id, TElem payload) noexcept(false);
};