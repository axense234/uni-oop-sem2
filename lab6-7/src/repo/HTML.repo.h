#pragma once

#include "TextFile.repo.h"
#include <string>

class HTMLRepo : public TextFileRepo
{

private:
    std::string filePath;
    std::string outputFilePath;

public:
    /**
     * @brief Constructor, needs a given file.
     *
     * @param filePath the file, must be std::string
     * @param outputFilePath the output file
     */
    HTMLRepo(const std::string &filePath, const std::string &outputFilePath) noexcept;

    /**
     * @brief Writes to a certain given file data. Should be used after any data mutation operation.
     *
     * @exception std::exception is thrown when file cannot be opened for some reason
     */
    void outputToFile() noexcept(false);

    /**
     * @brief Adds an element in the repo.
     *
     * @param elem Elem to add.
     * @throw RepoException if std::vector throws an exception for some reason
     */
    void add(const TElem &elem) noexcept(false) override;

    /**
     * @brief Removes an element from the repo using by id.
     *
     * @param id The id of the elem desired to be removed.
     * @throw RepositoryException if we couldn't find the elem in the elems or std::vector throws an exception
     */
    void remove(TElemId id) noexcept(false) override;

    /**
     * @brief Updates an element from the repo by id, using a payload.
     *
     * @param id Id of the desired elem to be updated.
     * @param payload Update payload.
     * @throw RepositoryException if we couldn't find the elem in the elems or std::vector throws an exception
     */
    void update(TElemId id, TElem payload) noexcept(false) override;
};