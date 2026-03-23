#include <stdlib.h>
#include <stdio.h>
#include "../domain/DynamicStack.h"

DynamicStack *createDynamicStack(int cap)
{
    DynamicStack *stack = malloc(sizeof(DynamicStack));

    if (stack == NULL)
    {
        return NULL;
    }

    stack->size = 0;
    stack->capacity = cap;

    stack->elems = malloc(cap * sizeof(Action));

    if (stack->elems == NULL)
    {
        free(stack);
        return NULL;
    }

    return stack;
}

void destroyDynamicStack(DynamicStack *stack)
{
    if (stack == NULL)
    {
        return;
    }

    free(stack->elems);
    free(stack);
    return;
}

void resizeDynamicStack(DynamicStack *stack)
{
    if (stack == NULL)
    {
        return;
    }

    stack->capacity *= 2;

    Action *aux = malloc(sizeof(Action) * stack->capacity);

    for (int i = 0; i < stack->size; ++i)
    {
        aux[i] = stack->elems[i];
    }

    free(stack->elems);
    stack->elems = aux;
}

void addElemToDynamicStack(DynamicStack *stack, Action elem)
{
    if (stack == NULL)
    {
        return;
    }

    if (stack->capacity == stack->size)
    {
        resizeDynamicStack(stack);
    }

    stack->elems[stack->size++] = elem;
}

int getSizeOfDynamicStack(DynamicStack *stack)
{
    return stack->size;
}

int getCapacityOfDynamicStack(DynamicStack *stack)
{
    return stack->capacity;
}

Action *getElemsOfDynamicStack(DynamicStack *stack)
{
    if (stack == NULL)
    {
        return NULL;
    }

    return stack->elems;
}

Action *getElemByIndexOfDynamicStack(DynamicStack *stack, int index)
{
    return &stack->elems[index];
}

void setSizeOfDynamicStack(DynamicStack *stack, int size)
{
    if (stack == NULL)
    {
        return;
    }

    stack->size = size;
}

void setElemFromIndexOfDynamicStack(DynamicStack *stack, int oldIndex, int newIndex)
{
    if (stack == NULL)
    {
        return;
    }

    stack->elems[oldIndex] = stack->elems[newIndex];
    return;
}

void setElemOfDynamicStack(DynamicStack *stack, int oldIndex, Action newValue)
{
    if (stack == NULL)
    {
        return;
    }

    stack->elems[oldIndex] = newValue;
    return;
}
