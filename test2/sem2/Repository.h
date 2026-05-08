#pragma ocnce
#include "DynamicArray.h"

class Repository
{

private:
    DynamicArray songs;

public:
    void add(const Song &s);

    int getSize() const;
};