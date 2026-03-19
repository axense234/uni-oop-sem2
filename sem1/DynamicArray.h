#pragma once

typedef int TElem;

typedef struct
{
    int size, capacity;
    TElem *elems;
} DynamicArray;

DynamicArray *createDynamicArray(int cap);

void destroyDynamicArray(DynamicArray *arr);

void addElem(DynamicArray *arr, TElem elem);

void resize(DynamicArray *arr);