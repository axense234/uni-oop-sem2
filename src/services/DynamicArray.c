#include <stdlib.h>
#include "../domain/DynamicArray.h"

DynamicArray *createDynamicArray(int cap)
{
    DynamicArray *array = malloc(sizeof(DynamicArray));

    if (array == NULL)
    {
        return NULL;
    }

    array->size = 0;
    array->capacity = cap;

    array->elems = malloc(cap * sizeof(Medicine));

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
    {
        return;
    }

    free(arr->elems);
    free(arr);
    return;
}

void resizeDynamicArray(DynamicArray *arr)
{
    if (arr == NULL)
    {
        return;
    }

    arr->capacity *= 2;

    Medicine *aux = malloc(sizeof(Medicine) * arr->capacity);

    for (int i = 0; i < arr->size; ++i)
    {
        aux[i] = arr->elems[i];
    }

    free(arr->elems);
    arr->elems = aux;
}

void addElemToDynamicArray(DynamicArray *arr, Medicine elem)
{
    if (arr == NULL)
    {
        return;
    }

    if (arr->capacity == arr->size)
    {
        resizeDynamicArray(arr);
    }

    arr->elems[arr->size++] = elem;
}

int getSizeOfDynamicArray(DynamicArray *arr)
{
    return arr->size;
}

int getCapacityOfDynamicArray(DynamicArray *arr)
{
    return arr->capacity;
}

Medicine *getElemsOfDynamicArray(DynamicArray *arr)
{
    if (arr == NULL)
    {
        return NULL;
    }

    return arr->elems;
}

Medicine *getElemByIndexOfDynamicArray(DynamicArray *arr, int index)
{
    return &arr->elems[index];
}

void setSizeOfDynamicArray(DynamicArray *arr, int size)
{
    if (arr == NULL)
    {
        return;
    }

    arr->size = size;
}

void setElemFromIndexOfDynamicArray(DynamicArray *arr, int oldIndex, int newIndex)
{
    if (arr == NULL)
    {
        return;
    }

    arr->elems[oldIndex] = arr->elems[newIndex];
    return;
}

void setElemOfDynamicArray(DynamicArray *arr, int oldIndex, Medicine newValue)
{
    if (arr == NULL)
    {
        return;
    }

    arr->elems[oldIndex] = newValue;
    return;
}
