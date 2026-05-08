#pragma once

#include "Medicine.h"

typedef struct
{
    int size, capacity;
    Medicine *elems;
} DynamicArray;

DynamicArray *createDynamicArray(int cap);

void destroyDynamicArray(DynamicArray *arr);

void addElemToDynamicArray(DynamicArray *arr, Medicine elem);

void resizeDynamicArray(DynamicArray *arr);

Medicine *getElemByIndexOfDynamicArray(DynamicArray *arr, int index);

int getSizeOfDynamicArray(DynamicArray *arr);
int getCapacityOfDynamicArray(DynamicArray *arr);
Medicine *getElemsOfDynamicArray(DynamicArray *arr);

void setSizeOfDynamicArray(DynamicArray *arr, int size);
void setElemFromIndexOfDynamicArray(DynamicArray *arr, int oldIndex, int newIndex);
void setElemOfDynamicArray(DynamicArray *arr, int oldIndex, Medicine newValue);
