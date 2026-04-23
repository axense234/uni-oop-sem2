#pragma once

template <typename T>
class List
{
protected: // works with public, might work with protected
    virtual void add(const T &e) = 0;
    virtual int getSize() = 0;
    virtual T &operator[](int pos) = 0;

    virtual ~List() = default;
};