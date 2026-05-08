#pragma once

#include "../domain/Response.h"
#include "../repo/Pharmacy.h"

/**
 * @brief Undoes the last action. Uses the Pharmacy Undo Stack.
 *
 * @param pharmacy Pharmacy.
 * @param res Response handling object.
 */
void undo(Pharmacy *pharmacy, Response *res);

/**
 * @brief Redoes the last action. Uses the Pharmacy Redo Stack.
 *
 * @param pharmacy Pharmacy.
 * @param res Response handling object.
 */
void redo(Pharmacy *pharmacy, Response *res);
