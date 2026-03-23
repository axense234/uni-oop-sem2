#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "../domain/Medicine.h"
#include "../domain/Response.h"
#include "../repo/Pharmacy.h"
#include "../helpers/helpers.h"

int findMedicineByUniqueIdentifier(Pharmacy *pharmacy, char *name, int concentration, Response *res)
{
    // Check if medicine exists in the inventory
    int foundMedicineIndex = -1;
    int pharmacySize = getSizeOfDynamicArray(getData(pharmacy));
    for (int i = 0; i < pharmacySize; ++i)
    {
        Medicine *current = getElemByIndexOfDynamicArray(getData(pharmacy), i);
        if (strcmp(getName(current), name) == 0 && getConcentration(current) == concentration)
        {
            foundMedicineIndex = i;
            break;
        }
    }

    // Handle res
    if (foundMedicineIndex == -1)
    {
        res->statusCode = 404;
        strcpy(res->message, "Could not find Medicine");
    }
    else
    {
        res->statusCode = 200;
        strcpy(res->message, "Found Medicine.");
    }

    return foundMedicineIndex;
}

void addMedicine(Pharmacy *pharmacy, Medicine *medicine, Response *res)
{

    // Check if medicine is already in inventory
    int medicine_index = findMedicineByUniqueIdentifier(pharmacy, getName(medicine), getConcentration(medicine), res);

    if (res->statusCode == 404)
    {
        // Add medicine to inventory
        int currentSize = getSizeOfDynamicArray(getData(pharmacy));
        addElemToDynamicArray(getData(pharmacy), *medicine);

        // Create and push undo action
        Action action = createAddAction(*medicine, currentSize);
        pushUndoAction(pharmacy, action);
        clearRedoStack(pharmacy);

        res->statusCode = 200;
        strcpy(res->message, "Successfully added Medicine to inventory.");
    }
    else
    {
        // Update
        Medicine *elem = getElemByIndexOfDynamicArray(getData(pharmacy), medicine_index);
        Medicine beforeState = *elem;

        int new_quantity = getQuantity(medicine) + getQuantity(elem);
        setQuantity(elem, new_quantity);

        // Create and push undo action
        Action action = createUpdateQuantityAction(beforeState, *elem, medicine_index);
        pushUndoAction(pharmacy, action);
        clearRedoStack(pharmacy);

        res->statusCode = 200;
        strcpy(res->message, "Successfully updated Medicine quantity since it was already in the inventory.");
    }
}

void deleteMedicineByUniqueIdentifier(Pharmacy *pharmacy, char *name, int concentration, Response *res)
{
    // Check if medicine is already in inventory
    int foundMedicineIndex = findMedicineByUniqueIdentifier(pharmacy, name, concentration, res);

    if (res->statusCode == 404)
    {
        res->statusCode = 404;
        strcpy(res->message, "Could not find Medicine to delete.");
        return;
    }

    // Save the medicine being deleted for undo
    Medicine *deletedMedicine = getElemByIndexOfDynamicArray(getData(pharmacy), foundMedicineIndex);
    Medicine savedMedicine = *deletedMedicine;

    // Delete the medicine from the inventory
    // Basically shift elements to the left and decrease the inventory_len
    int pharmacySize = getSizeOfDynamicArray(getData(pharmacy));
    for (int i = foundMedicineIndex; i < pharmacySize - 1; ++i)
    {
        setElemFromIndexOfDynamicArray(getData(pharmacy), i, i + 1);
    }
    setSizeOfDynamicArray(getData(pharmacy), pharmacySize - 1);

    // Create and push undo action
    Action action = createDeleteAction(savedMedicine, foundMedicineIndex);
    pushUndoAction(pharmacy, action);
    clearRedoStack(pharmacy);

    res->statusCode = 200;
    strcpy(res->message, "Successfully deleted a Medicine from the inventory.");
}

void updateMedicineByPayload(Pharmacy *pharmacy, char *name, int concentration, Medicine *update_payload, Response *res)
{
    // Check if medicine is already in inventory
    int foundMedicineIndex = findMedicineByUniqueIdentifier(pharmacy, name, concentration, res);

    if (res->statusCode == 404)
    {
        res->statusCode = 404;
        strcpy(res->message, "Could not find Medicine to update.");
        return;
    }
    else
    {
        // Update medicine
        Medicine *foundMedicine = getElemByIndexOfDynamicArray(getData(pharmacy), foundMedicineIndex);
        // Save state before update
        Medicine beforeState = *foundMedicine;

        // If another Medicine with the same unique identifier is found, we update the res object
        int found_medicine_index = findMedicineByUniqueIdentifier(pharmacy, update_payload->name, update_payload->concentration, res);

        if (found_medicine_index != -1)
        {
            res->statusCode = 409;
            strcpy(res->message, "Could not Update medicine with that update payload (unique constraint error).");
            return;
        }

        if (strlen(getName(update_payload)) > 0)
        {
            setName(foundMedicine, getName(update_payload));
        }
        if (getConcentration(update_payload) > 0)
        {
            setConcentration(foundMedicine, getConcentration(update_payload));
        }
        if (getPrice(update_payload) > 0)
        {
            setPrice(foundMedicine, getPrice(update_payload));
        }
        if (getQuantity(update_payload) > -1)
        {
            setQuantity(foundMedicine, getQuantity(update_payload));
        }

        // Create and push undo action
        Action action = createUpdateAction(beforeState, *foundMedicine, foundMedicineIndex);
        pushUndoAction(pharmacy, action);
        clearRedoStack(pharmacy);

        res->statusCode = 200;
        strcpy(res->message, "Successfully updated the given Medicine with the given Update Payload (i think).");
    }
}