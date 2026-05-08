#include <stdio.h>
#include <crtdbg.h>

#include "Planet.h"
#include "DynamicArray.h"

#define _CRTDBG_MAP_ALLOC

int main()
{
    // int a = 0;
    // printf("input value for a: ");
    // scanf("%d", &a);
    // printf("value of a: %d \n", a);

    // char name[100];
    // scanf("%s", name);
    // printf("value: %s", name);

    // testPlanet();
    // check for memory leaks with something here
    // _CrtDumpMemoryLeaks();

    DynamicArray *array = createDynamicArray(10);
    addElem(array, 1);
    addElem(array, 2);
    addElem(array, 3);
    destroyDynamicArray(array);

    _CrtDumpMemoryLeaks();
    return 0;
}