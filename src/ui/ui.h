#pragma once

#include "../domain/Response.h"
#include "../domain/Medicine.h"
#include "../repo/Pharmacy.h"

/**
 * @brief Displays the Menu Options.
 *
 */
void displayMenu();

/**
 * @brief Handle the Response object.
 *
 * @param res The Response object.
 */
void handleResponse(Response *res);

/**
 * @brief Retrieves the user option from the console.
 *
 * @param max_options The max options available, 1 index based.
 * @return The user option.
 */
int getUserOption(int max_options);

/**
 * @brief Create a Medicine instance with given data from the console.
 *
 * @return Pointer to Medicine created instance.
 */
Medicine *createMedicineFromInput();

/**
 * @brief Displays all Medicine that contain the given query in their name.
 *
 * @param pharmacy The pharmacy object containing the inventory.
 * @param query The search string for the Medicine.
 * @param res The response object to store operation result.
 */
void displayMedicine(Pharmacy *pharmacy, char *query, Response *res);

/**
 * @brief Retrieves the user search string query from the console.
 *
 * @param user_query The buffer to store the search query.
 */
void getUserQuery(char *user_query);

/**
 * @brief Retrieves the wanted Medicine UI from the console.
 *
 * @param name The buffer to store the name of the Medicine.
 * @param concentration The pointer to store the concentration of the Medicine.
 */
void getMedicineUniqueIdentifier(char *name, int *concentration);

/**
 * @brief Validates an int to be in [left, right] interval
 * @details Got the code from https://www.w3schools.com/c/c_input_validation.php
 *
 * @param number Number pointer to be validated.
 * @param left Left side of interval.
 * @param right Right side of interval.
 */
void validateIntRange(int *number, int left, int right);

/**
 * @brief Validates an int.
 * @details Got the code from https://www.w3schools.com/c/c_input_validation.php
 *
 * @param number Number pointer to be validated.
 */
void validateInt(int *number);

/**
 * @brief Validates a float.
 * @details Got the code from https://www.w3schools.com/c/c_input_validation.php
 *
 * @param number Number pointer to be validated.
 */
void validateFloat(float *number);

/**
 * @brief Validates a string.
 * @details Got the code from https://www.w3schools.com/c/c_input_validation.php
 *
 * @param string The string to be validated.
 * @param max_size Max size of string.
 */
void validateString(char *string, int max_size);

/**
 * @brief Displays all the Medicine in the Pharmacy Inventory where the supply is less than a provided value.
 *
 * @param pharmacy The pharmacy object containing the inventory.
 * @param amount_specifier The specifier amount (maximum quantity to display).
 * @param res The response object to store operation result.
 */
void displayMedicineInShortSupply(Pharmacy *pharmacy, int amount_specifier, Response *res);