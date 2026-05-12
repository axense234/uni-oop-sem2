#pragma once

#include <exception>
#include <string>

class RepoException : public std::exception
{
private:
    std::string message;

public:
    RepoException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};