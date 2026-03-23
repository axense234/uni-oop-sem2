#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "../domain/Medicine.h"
#include "../domain/Response.h"
#include "../repo/Pharmacy.h"
#include "../helpers/helpers.h"

void undo(Pharmacy *pharmacy, Response *res)
{
    Action action = popUndoAction(pharmacy);
    if (action.type == ACTION_ADD && action.medicineIndex == 0)
    {
        res->statusCode = 400;
        strcpy(res->message, "Nothing to undo.");
        return;
    }

    DynamicArray *data = getData(pharmacy);

    switch (action.type)
    {
    case ACTION_ADD:
    {
        int size = getSizeOfDynamicArray(data);
        for (int i = action.medicineIndex; i < size - 1; i++)
        {
            Medicine *next = getElemByIndexOfDynamicArray(data, i + 1);
            setElemOfDynamicArray(data, i, *next);
        }
        setSizeOfDynamicArray(data, size - 1);

        pushRedoAction(pharmacy, action);

        res->statusCode = 200;
        strcpy(res->message, "Undo: Removed added medicine.");
    }
    break;

    case ACTION_DELETE:
    {
        int size = getSizeOfDynamicArray(data);
        for (int i = size; i > action.medicineIndex; i--)
        {
            Medicine *prev = getElemByIndexOfDynamicArray(data, i - 1);
            setElemOfDynamicArray(data, i, *prev);
        }
        setSizeOfDynamicArray(data, size + 1);

        setElemOfDynamicArray(data, action.medicineIndex, action.medicineBefore);

        pushRedoAction(pharmacy, action);

        res->statusCode = 200;
        strcpy(res->message, "Undo: Restored deleted medicine.");
    }
    break;

    case ACTION_UPDATE:
    case ACTION_UPDATE_QUANTITY:
    {
        setElemOfDynamicArray(data, action.medicineIndex, action.medicineBefore);

        pushRedoAction(pharmacy, action);

        res->statusCode = 200;
        strcpy(res->message, "Undo: Restored previous medicine state.");
    }
    break;
    }
}

void redo(Pharmacy *pharmacy, Response *res)
{
    Action action = popRedoAction(pharmacy);
    if (action.type == ACTION_ADD && action.medicineIndex == 0)
    {
        res->statusCode = 400;
        strcpy(res->message, "Nothing to redo.");
        return;
    }

    DynamicArray *data = getData(pharmacy);

    switch (action.type)
    {
    case ACTION_ADD:
        addElemToDynamicArray(data, action.medicineAfter);
        pushUndoAction(pharmacy, action);

        res->statusCode = 200;
        strcpy(res->message, "Redo: Re-added medicine.");
        break;

    case ACTION_DELETE:
    {
        int size = getSizeOfDynamicArray(data);
        for (int i = action.medicineIndex; i < size - 1; i++)
        {
            Medicine *next = getElemByIndexOfDynamicArray(data, i + 1);
            setElemOfDynamicArray(data, i, *next);
        }
        setSizeOfDynamicArray(data, size - 1);
        pushUndoAction(pharmacy, action);

        res->statusCode = 200;
        strcpy(res->message, "Redo: Re-deleted medicine.");
    }
    break;

    case ACTION_UPDATE:
    case ACTION_UPDATE_QUANTITY:
        setElemOfDynamicArray(data, action.medicineIndex, action.medicineAfter);
        pushUndoAction(pharmacy, action);

        res->statusCode = 200;
        strcpy(res->message, "Redo: Re-applied update.");
        break;
    }
}