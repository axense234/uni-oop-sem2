#include "TextFile.repo.h"
#include "HTML.repo.h"
#include "../exceptions/RepoException.h"

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

HTMLRepo::HTMLRepo(const std::string &file, const std::string &output) noexcept : TextFileRepo(file, output)
{
    this->filePath = file;
    this->outputFilePath = output;
    TextFileRepo::readFromFile();
    this->outputToFile();
}

void HTMLRepo::outputToFile() noexcept(false)
{
    std::ofstream file(this->outputFilePath);

    if (!file.is_open())
    {
        throw RepoException("Could not open / find the file to write to.");
    }

    std::string htmlOutput;
    // document
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";

    // head
    file << "<head>\n";
    file << "<title>Movie Watch List</title>";
    file << "</head>\n";

    // table
    file << "<table border=\"1\">\n";
    for (const TElem &elem : this->getElems())
    {
        file << elem.getHTMLTableRow() << '\n';
    }

    file << "</table>\n";

    file << "</html>\n";

    file.close();
}

void HTMLRepo::add(const TElem &elem) noexcept(false)
{
    MemoryRepo::add(elem);
    TextFileRepo::writeToFile();
    this->outputToFile();
}

void HTMLRepo::remove(TElemId id) noexcept(false)
{
    MemoryRepo::remove(id);
    TextFileRepo::writeToFile();
    this->outputToFile();
}

void HTMLRepo::update(TElemId id, TElem payload) noexcept(false)
{
    MemoryRepo::update(id, payload);
    TextFileRepo::writeToFile();
    this->outputToFile();
}