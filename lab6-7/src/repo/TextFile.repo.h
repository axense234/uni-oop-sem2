#pragma once

#include "Memory.repo.h"
#include <string>

class TextFileRepo : public MemoryRepo
{

private:
    std::string filePath;

public:
    /**
     * @brief Constructor, needs a given file.
     *
     * @param file the file, must be std::string
     */
    TextFileRepo(const std::string &filePath);

    /**
     * @brief Reads from a given file data.
     *
     * @return true If read was a success.
     * @return false If read was not a success.
     */
    bool readFromFile();
    /**
     * @brief Writes to a certain given file data. Should be used after any data mutation operation.
     *
     * @exception std::exception is thrown when file cannot be opened for some reason
     */
    void writeToFile();

    /**
     * @brief Adds an element in the repo.
     *
     * @param elem Elem to add.
     * @return true If add was a success.
     * @return false If add was not a success.
     */
    bool add(TElem elem) override;

    /**
     * @brief Removes an element from the repo using by id.
     *
     * @exception Throws std::exception if elem cannot be found.
     * @param id The id of the elem desired to be removed.
     * @return true If remove was successfull.
     * @return false If remove was not successfull.
     */
    bool removeById(TElemId id) override;

    /**
     * @brief Updates an element from the repo by id, using a payload.
     *
     * @exception Throws std::exception if elem cannot be found.
     * @param id Id of the desired elem to be updated.
     * @param payload Update payload.
     * @return true If update was a success.
     * @return false If update was not a success.
     */
    bool updateById(TElemId id, TElem payload) override;
};