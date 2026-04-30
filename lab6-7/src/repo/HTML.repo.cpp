#include "TextFile.repo.h"
#include "HTML.repo.h"
#include "../exceptions/RepoException.h"

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <cstdio>

HTMLRepo::HTMLRepo(const std::string &file, const std::string &output) noexcept : TextFileRepo(file, output)
{
    this->filePath = file;
    this->outputFilePath = output;

    this->output().outputToFileHTML();
}

void HTMLRepo::add(const TElem &elem) noexcept(false)
{
    MemoryRepo::add(elem);
    TextFileRepo::writeToFile();

    this->output().outputToFileHTML();
}

void HTMLRepo::remove(TElemId id) noexcept(false)
{
    MemoryRepo::remove(id);
    TextFileRepo::writeToFile();

    this->output().outputToFileHTML();
}

void HTMLRepo::update(TElemId id, TElem payload) noexcept(false)
{
    MemoryRepo::update(id, payload);
    TextFileRepo::writeToFile();

    this->output().outputToFileHTML();
}

const RepoOutput HTMLRepo::output() const
{
    RepoOutput output = RepoOutput{*this, "HTML"};
    return output;
}