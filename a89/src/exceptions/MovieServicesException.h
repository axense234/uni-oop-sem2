#pragma once

#include <exception>
#include <string>

class MovieServicesException : public std::exception
{
private:
    std::string message;

public:
    MovieServicesException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};