#ifndef DOMAIN_H
#define DOMAIN_H

#include <constants.h>

struct sequences_maxes
{
    int maxes_per_sequence[MAX_VECTOR_SIZE];
    int nb_of_sequences;
};

struct pair
{
    int first;
    int second;
};

struct lsi
{
    int elems[MAX_VECTOR_SIZE];
    int len;
};

#endif