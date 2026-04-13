#include "TextFile.repo.h"

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

TextFileRepo::TextFileRepo(const std::string &file) : MemoryRepo()
{
    this->filePath = file;
    bool result = this->readFromFile();

    // im casting it to void for now so the compiler shuts up
    (void)result;
}

bool TextFileRepo::readFromFile()
{
    std::ifstream file(this->filePath);

    if (!file.is_open())
    {
        return false;
    }

    TElem elem;
    while (file >> elem)
    {
        this->elements.push_back(elem);
    }

    file.close();
    return true;
}

void TextFileRepo::writeToFile()
{
    std::ofstream file(this->filePath);

    if (!file.is_open())
    {
        throw std::exception();
    }

    for (const TElem &elem : this->elements)
    {
        file << elem << '\n';
    }

    file.close();
}

bool TextFileRepo::add(TElem elem)
{
    bool result = MemoryRepo::add(elem);
    writeToFile();
    return result;
}

bool TextFileRepo::removeById(TElemId id)
{
    bool result = MemoryRepo::removeById(id);
    writeToFile();
    return result;
}

bool TextFileRepo::updateById(TElemId id, TElem payload)
{
    bool result = MemoryRepo::updateById(id, payload);
    writeToFile();
    return result;
}