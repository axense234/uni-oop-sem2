#include "TextFile.repo.h"
#include "../exceptions/RepoException.h"

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

TextFileRepo::TextFileRepo(const std::string &file) noexcept : MemoryRepo()
{
    this->filePath = file;
    this->readFromFile();
}

void TextFileRepo::readFromFile()
{
    std::ifstream file(this->filePath);

    if (!file.is_open())
    {
        throw RepoException("Could not find the file to open.");
    }

    TElem elem;
    while (file >> elem)
    {
        this->getElems().push_back(elem);
    }

    file.close();
}

void TextFileRepo::writeToFile()
{
    std::ofstream file(this->filePath);

    if (!file.is_open())
    {
        throw RepoException("Could not open / find the file to write to.");
    }

    for (const TElem &elem : this->getElems())
    {
        file << elem << '\n';
    }

    file.close();
}

void TextFileRepo::add(const TElem &elem) noexcept(false)
{
    MemoryRepo::add(elem);
    writeToFile();
}

void TextFileRepo::remove(TElemId id) noexcept(false)
{
    MemoryRepo::remove(id);
    writeToFile();
}

void TextFileRepo::update(TElemId id, TElem payload) noexcept(false)
{
    MemoryRepo::update(id, payload);
    writeToFile();
}