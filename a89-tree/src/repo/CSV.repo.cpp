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

    this->output().outputToFileCSV();
}

void CSVRepo::add(const TElem &elem) noexcept(false)
{
    MemoryRepo::add(elem);
    TextFileRepo::writeToFile();

    this->output().outputToFileCSV();
}

void CSVRepo::remove(TElemId id) noexcept(false)
{
    MemoryRepo::remove(id);
    TextFileRepo::writeToFile();

    this->output().outputToFileCSV();
}

void CSVRepo::update(TElemId id, TElem payload) noexcept(false)
{
    MemoryRepo::update(id, payload);
    TextFileRepo::writeToFile();

    this->output().outputToFileCSV();
}

const RepoOutput CSVRepo::output() const
{
    RepoOutput output = RepoOutput{*this, "CSV"};
    return output;
}