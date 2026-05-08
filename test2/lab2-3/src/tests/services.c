#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "../domain/Medicine.h"
#include "../domain/Response.h"
#include "../repo/Pharmacy.h"
#include "../helpers/helpers.h"
#include "../services/services.h"

Pharmacy *setup_test_pharmacy()
{
    Pharmacy *pharmacy = createPharmacy();
    return pharmacy;
}

void cleanup_test_pharmacy(Pharmacy *pharmacy)
{
    destroyPharmacy(pharmacy);
}

Medicine *create_test_medicine(char *name, int concentration, int quantity, int price)
{
    Medicine *medicine = createMedicine(name, concentration, quantity, price);
    return medicine;
}

void test_findMedicineByUniqueIdentifier_found()
{
    printf("Testing findMedicineByUniqueIdentifier - found case...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med = create_test_medicine("Paracetamol", 500, 100, 25);
    addElemToDynamicArray(getData(pharmacy), *med);

    int index = findMedicineByUniqueIdentifier(pharmacy, "Paracetamol", 500, &res);

    assert(index == 0);
    assert(res.statusCode == 200);
    assert(strcmp(res.message, "Found Medicine.") == 0);

    free(med);
    cleanup_test_pharmacy(pharmacy);
    printf("test_findMedicineByUniqueIdentifier_found passed\n");
}

void test_findMedicineByUniqueIdentifier_not_found()
{
    printf("Testing findMedicineByUniqueIdentifier - not found case...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    int index = findMedicineByUniqueIdentifier(pharmacy, "Ibuprofen", 400, &res);

    assert(index == -1);
    assert(res.statusCode == 404);
    assert(strcmp(res.message, "Could not find Medicine") == 0);

    cleanup_test_pharmacy(pharmacy);
    printf("test_findMedicineByUniqueIdentifier_not_found passed\n");
}

void test_findMedicineByUniqueIdentifier_multiple_medicines()
{
    printf("Testing findMedicineByUniqueIdentifier - multiple medicines...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med1 = create_test_medicine("Paracetamol", 500, 100, 25);
    Medicine *med2 = create_test_medicine("Ibuprofen", 400, 50, 30);
    Medicine *med3 = create_test_medicine("Aspirin", 100, 200, 15);

    addElemToDynamicArray(getData(pharmacy), *med1);
    addElemToDynamicArray(getData(pharmacy), *med2);
    addElemToDynamicArray(getData(pharmacy), *med3);

    int index = findMedicineByUniqueIdentifier(pharmacy, "Ibuprofen", 400, &res);

    assert(index == 1);
    assert(res.statusCode == 200);

    free(med1);
    free(med2);
    free(med3);
    cleanup_test_pharmacy(pharmacy);
    printf("test_findMedicineByUniqueIdentifier_multiple_medicines passed\n");
}

void test_addMedicine_new_medicine()
{
    printf("Testing addMedicine - new medicine...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med = create_test_medicine("Paracetamol", 500, 100, 25);
    addMedicine(pharmacy, med, &res);

    assert(res.statusCode == 200);
    assert(strcmp(res.message, "Successfully added Medicine to inventory.") == 0);
    assert(getSizeOfDynamicArray(getData(pharmacy)) == 1);

    Medicine *added = getElemByIndexOfDynamicArray(getData(pharmacy), 0);
    assert(strcmp(getName(added), "Paracetamol") == 0);
    assert(getConcentration(added) == 500);
    assert(getQuantity(added) == 100);
    assert(getPrice(added) == 25);

    assert(getSizeOfDynamicStack(getUndoStack(pharmacy)) == 1);
    assert(getSizeOfDynamicStack(getRedoStack(pharmacy)) == 0);

    free(med);
    cleanup_test_pharmacy(pharmacy);
    printf("test_addMedicine_new_medicine passed\n");
}

void test_addMedicine_existing_medicine()
{
    printf("Testing addMedicine - existing medicine (quantity update)...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med1 = create_test_medicine("Paracetamol", 500, 100, 25);
    addMedicine(pharmacy, med1, &res);

    Medicine *med2 = create_test_medicine("Paracetamol", 500, 50, 25);
    addMedicine(pharmacy, med2, &res);

    assert(res.statusCode == 200);
    assert(strcmp(res.message, "Successfully updated Medicine quantity since it was already in the inventory.") == 0);

    Medicine *updated = getElemByIndexOfDynamicArray(getData(pharmacy), 0);
    assert(getQuantity(updated) == 150);

    assert(getSizeOfDynamicStack(getUndoStack(pharmacy)) == 2);

    free(med1);
    free(med2);
    cleanup_test_pharmacy(pharmacy);
    printf("test_addMedicine_existing_medicine passed\n");
}

void test_addMedicine_multiple_different_medicines()
{
    printf("Testing addMedicine - multiple different medicines...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med1 = create_test_medicine("Paracetamol", 500, 100, 25);
    Medicine *med2 = create_test_medicine("Ibuprofen", 400, 50, 30);
    Medicine *med3 = create_test_medicine("Aspirin", 100, 200, 15);

    addMedicine(pharmacy, med1, &res);
    addMedicine(pharmacy, med2, &res);
    addMedicine(pharmacy, med3, &res);

    assert(getSizeOfDynamicArray(getData(pharmacy)) == 3);
    assert(getSizeOfDynamicStack(getUndoStack(pharmacy)) == 3);

    free(med1);
    free(med2);
    free(med3);
    cleanup_test_pharmacy(pharmacy);
    printf("test_addMedicine_multiple_different_medicines passed\n");
}

void test_deleteMedicineByUniqueIdentifier_success()
{
    printf("Testing deleteMedicineByUniqueIdentifier - success case...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med = create_test_medicine("Paracetamol", 500, 100, 25);
    addMedicine(pharmacy, med, &res);

    deleteMedicineByUniqueIdentifier(pharmacy, "Paracetamol", 500, &res);

    assert(res.statusCode == 200);
    assert(strcmp(res.message, "Successfully deleted a Medicine from the inventory.") == 0);
    assert(getSizeOfDynamicArray(getData(pharmacy)) == 0);

    assert(getSizeOfDynamicStack(getUndoStack(pharmacy)) == 2);

    free(med);
    cleanup_test_pharmacy(pharmacy);
    printf("test_deleteMedicineByUniqueIdentifier_success passed\n");
}

void test_deleteMedicineByUniqueIdentifier_not_found()
{
    printf("Testing deleteMedicineByUniqueIdentifier - not found case...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    deleteMedicineByUniqueIdentifier(pharmacy, "NonExistent", 100, &res);

    assert(res.statusCode == 404);
    assert(strcmp(res.message, "Could not find Medicine to delete.") == 0);
    assert(getSizeOfDynamicArray(getData(pharmacy)) == 0);

    cleanup_test_pharmacy(pharmacy);
    printf("test_deleteMedicineByUniqueIdentifier_not_found passed\n");
}

void test_deleteMedicineByUniqueIdentifier_from_middle()
{
    printf("Testing deleteMedicineByUniqueIdentifier - delete from middle...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med1 = create_test_medicine("Paracetamol", 500, 100, 25);
    Medicine *med2 = create_test_medicine("Ibuprofen", 400, 50, 30);
    Medicine *med3 = create_test_medicine("Aspirin", 100, 200, 15);

    addMedicine(pharmacy, med1, &res);
    addMedicine(pharmacy, med2, &res);
    addMedicine(pharmacy, med3, &res);

    deleteMedicineByUniqueIdentifier(pharmacy, "Ibuprofen", 400, &res);

    assert(getSizeOfDynamicArray(getData(pharmacy)) == 2);

    Medicine *remaining1 = getElemByIndexOfDynamicArray(getData(pharmacy), 0);
    Medicine *remaining2 = getElemByIndexOfDynamicArray(getData(pharmacy), 1);

    assert(strcmp(getName(remaining1), "Paracetamol") == 0);
    assert(strcmp(getName(remaining2), "Aspirin") == 0);

    free(med1);
    free(med2);
    free(med3);
    cleanup_test_pharmacy(pharmacy);
    printf("test_deleteMedicineByUniqueIdentifier_from_middle passed\n");
}

void test_updateMedicineByPayload_full_update()
{
    printf("Testing updateMedicineByPayload - full update...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *original = create_test_medicine("Paracetamol", 500, 100, 25);
    addMedicine(pharmacy, original, &res);

    Medicine *update_payload = create_test_medicine("NewName", 600, 150, 35);

    updateMedicineByPayload(pharmacy, "Paracetamol", 500, update_payload, &res);

    assert(res.statusCode == 200);

    Medicine *updated = getElemByIndexOfDynamicArray(getData(pharmacy), 0);
    assert(strcmp(getName(updated), "NewName") == 0);
    assert(getConcentration(updated) == 600);
    assert(getQuantity(updated) == 150);
    assert(getPrice(updated) == 35);

    assert(getSizeOfDynamicStack(getUndoStack(pharmacy)) == 2);

    free(original);
    free(update_payload);
    cleanup_test_pharmacy(pharmacy);
    printf("test_updateMedicineByPayload_full_update passed\n");
}

void test_updateMedicineByPayload_partial_update()
{
    printf("Testing updateMedicineByPayload - partial update...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *original = create_test_medicine("Paracetamol", 500, 100, 25);
    addMedicine(pharmacy, original, &res);

    Medicine *update_payload = create_test_medicine("", 0, 200, 0);

    updateMedicineByPayload(pharmacy, "Paracetamol", 500, update_payload, &res);

    assert(res.statusCode == 200);

    Medicine *updated = getElemByIndexOfDynamicArray(getData(pharmacy), 0);
    assert(strcmp(getName(updated), "Paracetamol") == 0);
    assert(getConcentration(updated) == 500);
    assert(getQuantity(updated) == 200);
    assert(getPrice(updated) == 25);

    free(original);
    free(update_payload);
    cleanup_test_pharmacy(pharmacy);
    printf("test_updateMedicineByPayload_partial_update passed\n");
}

void test_updateMedicineByPayload_not_found()
{
    printf("Testing updateMedicineByPayload - medicine not found...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *update_payload = create_test_medicine("NewName", 600, 150, 35);

    updateMedicineByPayload(pharmacy, "NonExistent", 100, update_payload, &res);

    assert(res.statusCode == 404);
    assert(strcmp(res.message, "Could not find Medicine to update.") == 0);

    free(update_payload);
    cleanup_test_pharmacy(pharmacy);
    printf("test_updateMedicineByPayload_not_found passed\n");
}

void test_updateMedicineByPayload_unique_constraint_violation()
{
    printf("Testing updateMedicineByPayload - unique constraint violation...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med1 = create_test_medicine("Paracetamol", 500, 100, 25);
    Medicine *med2 = create_test_medicine("Ibuprofen", 400, 50, 30);

    addMedicine(pharmacy, med1, &res);
    addMedicine(pharmacy, med2, &res);

    Medicine *update_payload = create_test_medicine("Ibuprofen", 400, 150, 35);

    updateMedicineByPayload(pharmacy, "Paracetamol", 500, update_payload, &res);

    assert(res.statusCode == 409);
    assert(strcmp(res.message, "Could not Update medicine with that update payload (unique constraint error).") == 0);

    Medicine *unchanged = getElemByIndexOfDynamicArray(getData(pharmacy), 0);
    assert(strcmp(getName(unchanged), "Paracetamol") == 0);
    assert(getConcentration(unchanged) == 500);

    free(med1);
    free(med2);
    free(update_payload);
    cleanup_test_pharmacy(pharmacy);
    printf("test_updateMedicineByPayload_unique_constraint_violation passed\n");
}

void test_edge_cases_empty_string_name()
{
    printf("Testing edge cases - empty string name...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med = create_test_medicine("", 500, 100, 25);
    addMedicine(pharmacy, med, &res);

    assert(res.statusCode == 200);
    assert(getSizeOfDynamicArray(getData(pharmacy)) == 1);

    int index = findMedicineByUniqueIdentifier(pharmacy, "", 500, &res);
    assert(index == 0);

    free(med);
    cleanup_test_pharmacy(pharmacy);
    printf("test_edge_cases_empty_string_name passed\n");
}

void test_edge_cases_zero_concentration()
{
    printf("Testing edge cases - zero concentration...\n");

    Pharmacy *pharmacy = setup_test_pharmacy();
    Response res;

    Medicine *med = create_test_medicine("Test", 0, 100, 25);
    addMedicine(pharmacy, med, &res);

    assert(res.statusCode == 200);

    int index = findMedicineByUniqueIdentifier(pharmacy, "Test", 0, &res);
    assert(index == 0);

    free(med);
    cleanup_test_pharmacy(pharmacy);
    printf("test_edge_cases_zero_concentration passed\n");
}

int main()
{
    printf("Running Pharmacy Operation Tests...\n");
    printf("====================================\n\n");

    test_findMedicineByUniqueIdentifier_found();
    test_findMedicineByUniqueIdentifier_not_found();
    test_findMedicineByUniqueIdentifier_multiple_medicines();

    printf("\n");

    test_addMedicine_new_medicine();
    test_addMedicine_existing_medicine();
    test_addMedicine_multiple_different_medicines();

    printf("\n");

    test_deleteMedicineByUniqueIdentifier_success();
    test_deleteMedicineByUniqueIdentifier_not_found();
    test_deleteMedicineByUniqueIdentifier_from_middle();

    printf("\n");

    test_updateMedicineByPayload_full_update();
    test_updateMedicineByPayload_partial_update();
    test_updateMedicineByPayload_not_found();
    test_updateMedicineByPayload_unique_constraint_violation();

    printf("\n");

    test_edge_cases_empty_string_name();
    test_edge_cases_zero_concentration();

    printf("\n====================================\n");
    printf("All tests passed successfully!\n");

    return 0;
}