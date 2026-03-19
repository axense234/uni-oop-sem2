#include <iostream>

#include "Song.cpp"
#include "DynamicArray.cpp"
#include "Repository.cpp"

using namespace std;

int main()
{

    {
        Song s{"John", "John Title", 10, 30, "https://youtube.com"};
        // cout << s.getTitle() << endl;

        DynamicArray arr{5};

        Repository repo{};

        repo.add(s);
    }
    return 0;
}