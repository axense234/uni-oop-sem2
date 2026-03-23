#pragma once

typedef struct
{
    char *name;
    int concentration;
    int quantity;
    float price;

} Medicine;

/**
 * @brief Create a Medicine object.
 *
 * @param name Name of Medicine. (char)
 * @param concentration Concentration of Medicine. (int)
 * @param quantity Quantity of Medicine. (int)
 * @param price Price of Medicine. (int)
 * @return Medicine*
 */
Medicine *createMedicine(char *name, int concentration, int quantity, float price);

/**
 * @brief Destroys a Medicine instance
 *
 * @param m The Medicine instance to be destroyed.
 */
void destroyMedicine(Medicine *m);

char *getName(Medicine *m);
int getConcentration(Medicine *m);
int getQuantity(Medicine *m);
float getPrice(Medicine *m);

void setName(Medicine *m, char *name);
void setConcentration(Medicine *m, int concentration);
void setPrice(Medicine *m, float price);
void setQuantity(Medicine *m, int quantity);