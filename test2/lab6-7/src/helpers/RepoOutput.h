#pragma once

#include "../repo/TextFile.repo.h"
#include "../exceptions/RepoException.h"

#include <string>
#include <iostream>
#include <fstream>

class RepoOutput
{
private:
    const TextFileRepo &repo;
    const std::string &repoType;

public:
    /**
     * @brief Writes to a certain given file data in CSV. Should be used after any data mutation operation.
     *
     * @exception std::exception is thrown when file cannot be opened for some reason
     */
    void outputToFileCSV() const noexcept(false);

    /**
     * @brief Writes to a certain given file data in HTML. Should be used after any data mutation operation.
     *
     * @exception std::exception is thrown when file cannot be opened for some reason
     */
    void outputToFileHTML() const noexcept(false);

public:
    /**
     * @brief Constructor.
     *
     * @param fileRepo the file based repo
     * @param fileType the file type: CSV or HTML
     */
    RepoOutput(const TextFileRepo &fileRepo, const std::string &fileType) noexcept;
};