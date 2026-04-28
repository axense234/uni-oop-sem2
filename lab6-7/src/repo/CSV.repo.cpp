#include "TextFile.repo.h"
#include "CSV.repo.h"
#include "../exceptions/RepoException.h"

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

CSVRepo::CSVRepo(const std::string &file, const std::string &output) noexcept : TextFileRepo(file, output)
{
    this->filePath = file;
    this->outputFilePath = output;
    TextFileRepo::readFromFile();
    this->outputToFile();
}

void CSVRepo::outputToFile() noexcept(false)
{
    std::ofstream file(this->outputFilePath);

    if (!file.is_open())
    {
        throw RepoException("Could not open / find the file to write to.");
    }

    for (const TElem &elem : this->getElems())
    {
        file << elem.getCSV() << '\n';
    }

    file.close();
}

void CSVRepo::add(const TElem &elem) noexcept(false)
{
    MemoryRepo::add(elem);
    TextFileRepo::writeToFile();
    this->outputToFile();
}

void CSVRepo::remove(TElemId id) noexcept(false)
{
    MemoryRepo::remove(id);
    TextFileRepo::writeToFile();
    this->outputToFile();
}

void CSVRepo::update(TElemId id, TElem payload) noexcept(false)
{
    MemoryRepo::update(id, payload);
    TextFileRepo::writeToFile();
    this->outputToFile();
}