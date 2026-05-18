#pragma once

#include <exception>
#include <string>

class MenuGUIException : public std::exception
{
private:
    std::string message;

public:
    MenuGUIException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};