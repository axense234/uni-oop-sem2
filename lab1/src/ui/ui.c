#include <stdio.h>
#include <stdlib.h>

#include <domain.h>

void display_menu()
{
    printf("1: Read a Vector of Numbers from Console (given numbers)\n");
    printf("2: Compute and Display the Maxes of Sequences (0=eos, -1=eor, given sequences)\n");
    printf("3: Longest Subsequence (given vector) with Values in Interval (given)\n");
    printf("4: Exit the Program\n");
    printf("5: x float to the power of n int manually\n");
}

void display_num_vector_console(int given_vector[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", given_vector[i]);
    }
    printf("\n");
}

void display_maxes_of_sequences(struct sequences_maxes maxes)
{
    for (int i = 0; i < maxes.nb_of_sequences; ++i)
    {
        printf("sequence %d max: %d \n", (i + 1), maxes.maxes_per_sequence[i]);
    }
    printf("\n");
}

void display_global_max(int global_max)
{
    printf("global max: %d", global_max);
    printf("\n");
}

void exit_program()
{
    printf("Exiting program...");
    exit(0);
}