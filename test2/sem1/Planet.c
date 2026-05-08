#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Planet.h"

Planet *createPlanet(char *name, char *type, double dist)
{
    Planet *p = malloc(sizeof(Planet));
    if (p == NULL)
        return p;

    p->name = malloc((strlen(name) + 1) * sizeof(char));
    if (p->name == NULL)
    {
        free(p);
        return NULL;
    }
    strcpy(p->name, name);

    p->type = malloc((strlen(type) + 1) * sizeof(char));
    if (p->type == NULL)
    {
        free(p->name);
        free(p);
        return NULL;
    }
    strcpy(p->type, type);

    p->distanceToEarth = dist;

    return p;
}

void destroyPlanet(Planet *p)
{
    if (p == NULL)
        return;

    free(p->name);
    free(p->type);
    free(p);
}

char *getType(Planet *p)
{
    if (p == NULL)
        return NULL;

    return p->type;
}

void testPlanet()
{
    Planet *planet = createPlanet("Earth", "planet", 10000000);
    assert(strcmp(getType(planet), "gas") == 0);
    assert(strcmp(planet->type, "planet") == 0);
}