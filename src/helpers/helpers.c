#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../domain/Action.h"
#include "../domain/Medicine.h"
#include "../domain/Response.h"
#include "../repo/Pharmacy.h"
#include "../services/services.h"

Action createAddAction(Medicine medicine, int index)
{
    Action action;
    action.type = ACTION_ADD;
    action.medicineAfter = medicine;
    action.medicineBefore = medicine;
    action.medicineIndex = index;
    return action;
}

Action createDeleteAction(Medicine medicine, int index)
{
    Action action;
    action.type = ACTION_DELETE;
    action.medicineBefore = medicine;
    action.medicineAfter = medicine;
    action.medicineIndex = index;
    return action;
}

Action createUpdateAction(Medicine before, Medicine after, int index)
{
    Action action;
    action.type = ACTION_UPDATE;
    action.medicineBefore = before;
    action.medicineAfter = after;
    action.medicineIndex = index;
    return action;
}

Action createUpdateQuantityAction(Medicine before, Medicine after, int index)
{
    Action action;
    action.type = ACTION_UPDATE_QUANTITY;
    action.medicineBefore = before;
    action.medicineAfter = after;
    action.medicineIndex = index;
    return action;
}

void addStaticMedicines(Pharmacy *pharmacy, Response *res)
{
    if (pharmacy == NULL)
    {
        res->statusCode = 400;
        strcpy(res->message, "Invalid pharmacy pointer");
        return;
    }

    const char *medicineNames[10] = {
        "Paracetamol",
        "Ibuprofen",
        "Aspirin",
        "Amoxicillin",
        "Omeprazole",
        "Loratadine",
        "Metformin",
        "Amlodipine",
        "Simvastatin",
        "Levothyroxine"};

    int concentrations[10] = {500, 400, 100, 250, 20, 10, 500, 5, 20, 50};
    int quantities[10] = {150, 200, 300, 100, 120, 80, 250, 180, 140, 90};
    int prices[10] = {25, 30, 15, 45, 28, 35, 22, 40, 32, 38};

    int successCount = 0;
    int duplicateCount = 0;

    for (int i = 0; i < 10; i++)
    {
        // Create a new medicine
        Medicine *med = createMedicine(
            (char *)medicineNames[i],
            concentrations[i],
            quantities[i],
            prices[i]);

        if (med == NULL)
        {
            res->statusCode = 500;
            strcpy(res->message, "Failed to create medicine");
            return;
        }

        // Try to add the medicine to the pharmacy
        Response addRes;
        addMedicine(pharmacy, med, &addRes);

        if (addRes.statusCode == 200)
        {
            if (strstr(addRes.message, "added") != NULL)
            {
                successCount++;
            }
            else
            {
                duplicateCount++;
            }
        }
        else
        {
            free(med);
            // unhandles res case here
            return;
        }

        free(med);
    }

    res->statusCode = 200;
    strcpy(res->message,
           "Successfully added 10 static medicines to inventory.");
}