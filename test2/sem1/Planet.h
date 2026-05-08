#pragma once

typedef struct
{
    double distanceToEarth;
    char *name;
    char *type;
} Planet;

/**
 * @brief Creates a Planet object
 *
 * @param name array of chars
 * @param type array of chars
 * @param dist double
 * @return Pointer to the created planet
 */
Planet *createPlanet(char *name, char *type, double dist);

/**
 * @brief Destroys a Planet Object
 *
 * @param p The Planet instance to be destroyed
 */
void destroyPlanet(Planet *p);

char *getType(Planet *p);

/**
 * @brief test
 *
 */
void testPlanet();