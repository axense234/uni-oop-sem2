#pragma once

#include "../domain/Medicine.h"
#include "../domain/Response.h"
#include "../repo/Pharmacy.h"

/**
 * @brief Finds a Medicine by given name AND concentration.
 *
 * @param pharmacy The pharmacy object containing the inventory.
 * @param name Name of wanted Medicine.
 * @param concentration Concentration of wanted Medicine.
 * @param res The response object used for handling the response.
 * @return Index of the found Medicine in the inventory, or -1 if not found.
 */
int findMedicineByUniqueIdentifier(Pharmacy *pharmacy, char *name, int concentration, Response *res);

/**
 * @brief Adds a Medicine instance to the Pharmacy Inventory.
 *
 * @param pharmacy The pharmacy object containing the inventory.
 * @param medicine The given Medicine instance (passed by value).
 * @param res The response object used for handling the response.
 */
void addMedicine(Pharmacy *pharmacy, Medicine *medicine, Response *res);

/**
 * @brief Deletes a Medicine instance from the Pharmacy Inventory by name and concentration.
 *
 * @param pharmacy The pharmacy object containing the inventory.
 * @param medicine The medicine instance pointer to be added.
 * @param res The response object used for handling the response.
 */
void deleteMedicineByUniqueIdentifier(Pharmacy *pharmacy, char *name, int concentration, Response *res);

/**
 * @brief Updates a Medicine instance from the Pharmacy Inventory with the given Medicine Update Payload.
 *
 * @param pharmacy The pharmacy object containing the inventory.
 * @param name The name of the Medicine. Part of Medicine UI.
 * @param concentration The concentration of the Medicine. Part of Medicine UI.
 * @param update_payload The given Medicine Update Payload (passed by value).
 * @param res The response object used for handling the response.
 */
void updateMedicineByPayload(Pharmacy *pharmacy, char *name, int concentration, Medicine *update_payload, Response *res);