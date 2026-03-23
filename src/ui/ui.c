#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../domain/Response.h"
#include "../repo/Pharmacy.h"
/*
    Input Validation
    - validateIntRange
    - validateInt
    - validateFloat
    - validateString

*/

void validateIntRange(int *number, int left, int right)
{
    do
    {
        printf("Number between %d and %d: ", left, right);
        scanf("%d", number);

        while (getchar() != '\n')
            ;
    } while (*number < left || *number > right);
    printf("\n");
}

void validateInt(int *number)
{
    char input_buffer[100];
    while (fgets(input_buffer, sizeof(input_buffer), stdin))
    {
        if (sscanf(input_buffer, "%d", number) == 1)
        {
            break;
        }
        else
        {
            printf("Invalid input. Try again: ");
        }
    }
}

void validateFloat(float *number)
{
    char input_buffer[100];
    while (fgets(input_buffer, sizeof(input_buffer), stdin))
    {
        if (sscanf(input_buffer, "%f", number) == 1)
        {
            break;
        }
        else
        {
            printf("Invalid input. Try again: ");
        }
    }
}

void validateString(char *string, int max_size)
{
    do
    {
        printf("String (max %d chars): ", max_size);
        fgets(string, max_size, stdin);
        string[strcspn(string, "\n")] = 0;
    } while (strlen(string) == 0);
}

/*
    Output
    - handleResponse
    - displayMenu
    - displayMedicine
    - displayMedicineInShortSupply
*/

void handleResponse(Response *res)
{
    if (res->statusCode == 200)
    {
        // 200
        printf("SUCCESS!\n");
    }
    else
    {
        // 404, 400, 409, etc..
        printf("ERROR!\n");
    }

    printf("%s\n", res->message);
    printf("Status Code: %d\n", res->statusCode);
    printf("\n");
}

void displayMenu()
{
    printf("MENU\n");
    printf("1: Add a Medicine to the Pharmacy Inventory.\n");
    printf("2: Delete a Medicine from the Pharmacy Inventory.\n");
    printf("3: Update a Medicine from the Pharmacy Inventory using an Update Payload.\n");
    printf("4: See all available Medicine by Medicine Name (asc order).\n");
    printf("5: Display all medicine in short supply.\n");
    printf("6: Exit program.\n");
    printf("7: Undo last operation.\n");
    printf("8: Redo last undone operation.\n");
    printf("\n");
}

void displayMedicine(Pharmacy *pharmacy, char *query, Response *res)
{
    // If we don't have any Medicine we return
    if (getSizeOfDynamicArray(getData(pharmacy)) < 1)
    {
        res->statusCode = 404;
        strcpy(res->message, "No Medicine to be displayed.");
        return;
    }

    DynamicArray *matched_medicine = createDynamicArray(getCapacityOfDynamicArray(getData(pharmacy)));

    // Find the medicine to be sorted and displayed
    int pharmacySize = getSizeOfDynamicArray(getData(pharmacy));
    for (int i = 0; i < pharmacySize; i++)
    {
        Medicine *current = getElemByIndexOfDynamicArray(getData(pharmacy), i);

        if (strstr(getName(current), query) != NULL || strcmp(query, "all") == 0)
        {
            addElemToDynamicArray(matched_medicine, *current);
        }
    }

    // Sort by medicine name
    int matchedMedicineSize = getSizeOfDynamicArray(matched_medicine);
    for (int i = 0; i < matchedMedicineSize - 1; i++)
    {
        for (int j = 0; j < matchedMedicineSize - i - 1; j++)
        {
            Medicine *current = getElemByIndexOfDynamicArray(matched_medicine, j);
            Medicine *next = getElemByIndexOfDynamicArray(matched_medicine, j + 1);

            if (strcmp(getName(current), getName(next)) > 0)
            {
                Medicine aux = *current;
                setElemOfDynamicArray(matched_medicine, j, *next);
                setElemOfDynamicArray(matched_medicine, j + 1, aux);
            }
        }
    }

    // Display the sorted matching medicine
    matchedMedicineSize = getSizeOfDynamicArray(matched_medicine);
    for (int i = 0; i < matchedMedicineSize; i++)
    {
        Medicine *current = getElemByIndexOfDynamicArray(matched_medicine, i);
        printf("%s - %d\n", getName(current), getConcentration(current));
        printf("Quantity: %d, Price: %.2f\n", getQuantity(current), getPrice(current));
        printf("\n");
    }

    printf("\n");

    res->statusCode = 200;
    strcpy(res->message, "Successfully displayed some Medicine.");

    // Free the dynamic array
    destroyDynamicArray(matched_medicine);
}

void displayMedicineInShortSupply(Pharmacy *pharmacy, int amount_specifier, Response *res) // FIXED: Parameter type
{
    // If we don't have any Medicine we return
    if (getSizeOfDynamicArray(getData(pharmacy)) < 1)
    {
        res->statusCode = 404;
        strcpy(res->message, "No Medicine to be displayed.");
        return;
    }

    // Match all medicine that have quantity less than the amount specifier
    DynamicArray *matched_medicine = createDynamicArray(getCapacityOfDynamicArray(getData(pharmacy)));

    int pharmacySize = getSizeOfDynamicArray(getData(pharmacy));
    for (int i = 0; i < pharmacySize; ++i)
    {
        Medicine *current = getElemByIndexOfDynamicArray(getData(pharmacy), i);
        if (getQuantity(current) < amount_specifier)
        {
            addElemToDynamicArray(matched_medicine, *current);
        }
    }

    // If no matches, we update the res object
    int matchedSize = getSizeOfDynamicArray(matched_medicine);
    if (matchedSize < 1)
    {
        res->statusCode = 404;
        strcpy(res->message, "No Medicine was matched to be displayed.");
        destroyDynamicArray(matched_medicine);
        return;
    }

    // Display the matched medicine
    for (int i = 0; i < matchedSize; i++)
    {
        Medicine *current = getElemByIndexOfDynamicArray(matched_medicine, i);
        printf("%s - %d\n", getName(current), getConcentration(current));
        printf("Quantity: %d, Price: %.2f\n", getQuantity(current), getPrice(current));
        printf("\n");
    }

    printf("\n");

    res->statusCode = 200;
    strcpy(res->message, "Successfully displayed Medicine in short supply.");

    destroyDynamicArray(matched_medicine);
}

/*
    Input
    - getUserOption
    - createMedicineFromInput
    - getUserQuery
    - getMedicineUniqueIdentifier
*/

int getUserOption(int max_options)
{
    int user_option;
    validateIntRange(&user_option, 1, max_options);
    return user_option;
}

Medicine *createMedicineFromInput()
{

    // Name
    char name[100];
    validateString(name, 100);

    // Concentration
    int concentration;
    printf("Medicine Concentration (int): ");
    validateInt(&concentration);

    // Quantity
    int quantity;
    printf("Medicine Quantity (int): ");
    validateInt(&quantity);

    // Price
    float price;
    printf("Medicine Price (float): ");
    validateFloat(&price);

    printf("\n");

    Medicine *m = createMedicine(name, concentration, quantity, price);

    return m;
}

void getUserQuery(char *user_query)
{
    printf("Search Query (char 100, \"all\"=ALL): ");
    validateString(user_query, 100);
    printf("\n");
}

void getMedicineUniqueIdentifier(char *name, int *concentration)
{
    printf("MEDICINE UI (unique identifier)\n");
    printf("----------------------------------------\n");

    printf("Medicine Name: ");
    validateString(name, 100);

    printf("Medicine Concentration: ");
    validateInt(concentration);
    printf("\n");
}