#include "RepoOutput.h"

#include <cstdio>

RepoOutput::RepoOutput(const TextFileRepo &fileRepo, const std::string &fileType) noexcept : repo(fileRepo), repoType(fileType)
{
    // clean the output file initially
    std::remove(this->repo.getOutputFilePath().c_str());
};

void RepoOutput::outputToFileHTML() const noexcept(false)
{
    std::ofstream file(this->repo.getOutputFilePath());

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
    for (const TElem &elem : this->repo.getElems())
    {
        file << elem.getHTMLTableRow() << '\n';
    }

    file << "</table>\n";

    file << "</html>\n";

    file.close();
}

void RepoOutput::outputToFileCSV() const noexcept(false)
{
    std::ofstream file(this->repo.getOutputFilePath());

    if (!file.is_open())
    {
        throw RepoException("Could not open / find the file to write to.");
    }

    for (const TElem &elem : this->repo.getElems())
    {
        file << elem.getCSV() << '\n';
    }

    file.close();
}