#pragma once

#include "Action.h"

typedef struct
{
    int size, capacity;
    Action *elems;
} DynamicStack;

DynamicStack *createDynamicStack(int cap);

void destroyDynamicStack(DynamicStack *arr);

void addElemToDynamicStack(DynamicStack *arr, Action elem);

void resizeDynamicStack(DynamicStack *arr);

Action *getElemByIndexOfDynamicStack(DynamicStack *arr, int index);

int getSizeOfDynamicStack(DynamicStack *arr);
int getCapacityOfDynamicStack(DynamicStack *arr);
Action *getElemsOfDynamicStack(DynamicStack *arr);

void setSizeOfDynamicStack(DynamicStack *arr, int size);
void setElemFromIndexOfDynamicStack(DynamicStack *arr, int oldIndex, int newIndex);
void setElemOfDynamicStack(DynamicStack *arr, int oldIndex, Action newValue);
