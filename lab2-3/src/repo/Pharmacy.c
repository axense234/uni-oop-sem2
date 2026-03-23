#include <stdio.h>
#include <stdlib.h>
#include "Pharmacy.h"

DynamicArray *getData(Pharmacy *repo)
{
    return repo->data;
}

DynamicStack *getUndoStack(Pharmacy *repo)
{
    return repo->undoStack;
}

DynamicStack *getRedoStack(Pharmacy *repo)
{
    return repo->redoStack;
}

Pharmacy *createPharmacy()
{
    Pharmacy *pharmacy = malloc(sizeof(Pharmacy));

    DynamicArray *data = createDynamicArray(100);
    DynamicStack *undo = createDynamicStack(100);
    DynamicStack *redo = createDynamicStack(100);

    if (data == NULL)
    {
        free(pharmacy);
        return NULL;
    }

    pharmacy->data = data;
    pharmacy->undoStack = undo;
    pharmacy->redoStack = redo;

    return pharmacy;
}

void destroyPharmacy(Pharmacy *pharmacy)
{
    if (pharmacy == NULL)
        return;

    destroyDynamicArray(pharmacy->data);
    destroyDynamicStack(pharmacy->undoStack);
    destroyDynamicStack(pharmacy->redoStack);
}

void pushUndoAction(Pharmacy *pharmacy, Action action)
{
    addElemToDynamicStack(pharmacy->undoStack, action);
}

Action popUndoAction(Pharmacy *pharmacy)
{

    int size = getSizeOfDynamicStack(pharmacy->undoStack);

    Action *action = getElemByIndexOfDynamicStack(pharmacy->undoStack, size - 1);
    Action result = *action;
    setSizeOfDynamicStack(pharmacy->undoStack, size - 1);
    return result;
}

void pushRedoAction(Pharmacy *pharmacy, Action action)
{
    if (pharmacy == NULL || pharmacy->redoStack == NULL)
        return;
    addElemToDynamicStack(pharmacy->redoStack, action);
}

Action popRedoAction(Pharmacy *pharmacy)
{

    int size = getSizeOfDynamicStack(pharmacy->redoStack);

    Action *action = getElemByIndexOfDynamicStack(pharmacy->redoStack, size - 1);
    Action result = *action;
    setSizeOfDynamicStack(pharmacy->redoStack, size - 1);
    return result;
}

void clearRedoStack(Pharmacy *pharmacy)
{
    setSizeOfDynamicStack(pharmacy->redoStack, 0);
}