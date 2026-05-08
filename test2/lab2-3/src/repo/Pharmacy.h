#pragma once

#include "../domain/Action.h"
#include "../domain/DynamicArray.h"
#include "../domain/DynamicStack.h"

typedef struct
{
    DynamicArray *data;
    DynamicStack *undoStack;
    DynamicStack *redoStack;
} Pharmacy;

DynamicArray *getData(Pharmacy *repo);
DynamicStack *getUndoStack(Pharmacy *repo);
DynamicStack *getRedoStack(Pharmacy *repo);

/**
 * @brief Constructor.
 *
 * @return Pharmacy*
 */
Pharmacy *createPharmacy();

/**
 * @brief Deconstructor.
 *
 * @param pharmacy
 */
void destroyPharmacy(Pharmacy *pharmacy);

/**
 * @brief Pushes an Undo Action. This should be somewhere else probably.
 *
 * @param pharmacy Pharmacy.
 * @param action Action.
 */
void pushUndoAction(Pharmacy *pharmacy, Action action);

/**
 * @brief Pops an Undo Action from the Pharmacy Undo Stack.
 *
 * @param pharmacy
 * @return Action
 */
Action popUndoAction(Pharmacy *pharmacy);

/**
 * @brief Pushes a Redo Action on the Pharmacy Redo Stack.
 *
 * @param pharmacy Pharmacy.
 * @param action Redo Action.
 */
void pushRedoAction(Pharmacy *pharmacy, Action action);

/**
 * @brief Pops a Redo Action from the Pharmacy Redo Stack.
 *
 * @param pharmacy
 * @return Action
 */
Action popRedoAction(Pharmacy *pharmacy);

/**
 * @brief Clears the Pharmacy Redo Stack.
 *
 * @param pharmacy Pharmacy.
 */
void clearRedoStack(Pharmacy *pharmacy);