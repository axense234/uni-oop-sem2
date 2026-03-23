#pragma once

#include "../domain/Medicine.h"
#include "../domain/Action.h"

/**
 * @brief Create an Action instance for an Add case.
 *
 * @param medicine Medicine handled by add.
 * @param index Index of the Medicine.
 * @return Action
 */
Action createAddAction(Medicine medicine, int index);

/**
 * @brief Create an Action instance for a Delete case.
 *
 * @param medicine Medicine handled by Delete.
 * @param index Index of the Medicine.
 * @return Action
 */
Action createDeleteAction(Medicine medicine, int index);

/**
 * @brief Create an Action instance for a Delete case.
 *
 * @param medicine Medicine handled by Delete.
 * @param index Index of the Medicine.
 * @return Action
 */
Action createUpdateAction(Medicine before, Medicine after, int index);

/**
 * @brief Create an Action instance for a Update case.
 *
 * @param medicine Medicine handled by Delete.
 * @param index Index of the Medicine.
 * @return Action
 */
Action createUpdateQuantityAction(Medicine before, Medicine after, int index);

/**
 * @brief Adds 10 generated entries to the pharmacy.
 *
 */
void addStaticMedicines(Pharmacy *pharmacy, Response *res);
