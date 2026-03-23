#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ui/ui.h"
#include "services/services.h"
#include "services/undo.h"
#include "domain/Response.h"
#include "repo/Pharmacy.h"
#include "helpers/helpers.h"

int main()
{
    Pharmacy *pharmacy = createPharmacy();
    int user_option;

    Response res;
    res.statusCode = 500;
    strcpy(res.message, "Unknown error.");

    addStaticMedicines(pharmacy, &res);

    while (1)
    {
        displayMenu();
        user_option = getUserOption(8);

        switch (user_option)
        {
        case 1:
            printf("ADD MEDICINE\n");
            printf("------------------------\n");
            Medicine *medicine = createMedicineFromInput();

            addMedicine(pharmacy, medicine, &res);
            handleResponse(&res);
            break;
        case 2:
            printf("DELETE MEDICINE\n");
            printf("------------------------\n");
            char medicine_name_delete[100];
            int medicine_concentration_delete;
            getMedicineUniqueIdentifier(medicine_name_delete, &medicine_concentration_delete);

            deleteMedicineByUniqueIdentifier(pharmacy, medicine_name_delete, medicine_concentration_delete, &res);
            handleResponse(&res);
            break;
        case 3:
            printf("UPDATE MEDICINE\n");
            printf("------------------------\n");
            char medicine_name[100];
            int medicine_concentration;
            getMedicineUniqueIdentifier(medicine_name, &medicine_concentration);

            printf("Update Payload \n");
            Medicine *update_payload = createMedicineFromInput();

            updateMedicineByPayload(pharmacy, medicine_name, medicine_concentration, update_payload, &res);
            handleResponse(&res);
            break;
        case 4:
            printf("SEARCH AND DISPLAY MEDICINE\n");
            printf("-----------------------------------\n");
            char user_query[100];
            getUserQuery(user_query);

            displayMedicine(pharmacy, user_query, &res);
            handleResponse(&res);
            break;
        case 5:
            printf("DISPLAY MEDICINE SHORT SUPPLY\n");
            printf("-----------------------------------\n");

            int amount_specifier = getUserOption(400);
            displayMedicineInShortSupply(pharmacy, amount_specifier, &res);
            handleResponse(&res);
            break;
        case 6:
            printf("Exiting program........");

            destroyPharmacy(pharmacy);
            exit(1);
        case 7:
            printf("UNDO\n");
            printf("------------------------\n");

            undo(pharmacy, &res);
            handleResponse(&res);
            break;

        case 8:
            printf("REDO\n");
            printf("------------------------\n");

            redo(pharmacy, &res);
            handleResponse(&res);
            break;
        default:
            break;
        }
    }

    return 0;
}