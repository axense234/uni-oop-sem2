#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../domain/Medicine.h"
#include "../domain/Response.h"

Medicine *createMedicine(char *name, int concentration, int quantity, float price)
{
    Medicine *m = malloc(sizeof(Medicine));
    if (m == NULL)
    {
        return m;
    }

    m->name = malloc((strlen(name) + 1) * sizeof(char));
    if (m->name == NULL)
    {
        free(m);
        return NULL;
    }
    strcpy(m->name, name);

    m->concentration = concentration;
    m->price = price;
    m->quantity = quantity;

    return m;
}

void destroyMedicine(Medicine *m)
{
    if (m == NULL)
    {
        return;
    }

    free(m->name);
    free(m);
}

char *getName(Medicine *m)
{
    return m->name;
}

int getConcentration(Medicine *m)
{
    return m->concentration;
}

int getQuantity(Medicine *m)
{
    return m->quantity;
}

float getPrice(Medicine *m)
{
    return m->price;
}

void setName(Medicine *m, char *name)
{
    if (m == NULL)
    {
        return;
    }

    free(m->name);
    m->name = malloc((strlen(name) + 1) * sizeof(char));

    if (m->name == NULL)
    {
        return;
    }

    strcpy(m->name, name);
}

void setQuantity(Medicine *m, int quantity)
{
    if (m == NULL)
    {
        return;
    }

    m->quantity = quantity;
}

void setConcentration(Medicine *m, int concentration)
{
    if (m == NULL)
    {
        return;
    }

    m->concentration = concentration;
}

void setPrice(Medicine *m, float price)
{
    if (m == NULL)
    {
        return;
    }

    m->price = price;
}