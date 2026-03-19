#include <stdlib.h>
#include "DynamicArray.h"

DynamicArray *createDynamicArray(int cap)
{
    DynamicArray *array = malloc(sizeof(DynamicArray));
    if (array == NULL)
        return NULL;

    array->size = 0;
    array->capacity = cap;

    array->elems = malloc(cap * sizeof(TElem));

    if (array->elems == NULL)
    {
        free(array);
        return NULL;
    }

    return array;
}

void destroyDynamicArray(DynamicArray *arr)
{
    if (arr == NULL)
        return;

    free(arr->elems);
    free(arr);
    return;
}

void resize(DynamicArray *arr)
{
    if (arr == NULL)
        return;

    arr->capacity *= 2;

    TElem *aux = malloc(sizeof(TElem) * arr->capacity);

    for (int i = 0; i < arr->size; ++i)
    {
        aux[i] = arr->elems[i];
    }

    free(arr->elems);

    arr->elems = aux;
}

void addElem(DynamicArray *arr, TElem elem)
{
    if (arr == NULL)
        return;

    if (arr->capacity == arr->size)
        resize(arr);

    arr->elems[arr->size++] = elem;
}