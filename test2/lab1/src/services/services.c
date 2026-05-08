#include <stdio.h>

#include <constants.h>
#include <domain.h>

/**
 * Reads a float and an int from console input
 * @param x - base float number
 * @param n - exponent int
 * @return x^n
 */

float to_power_of_n(float x, int n)
{
    float result = 1;

    for (int i = 0; i < n; ++i)
    {
        result *= x;
    }

    return result;
}

/**
 * Reads integers from console input until non-integer input
 * @param given_vector - array to store the numbers
 * @return number of integers successfully read
 *
 * @note Stops reading when encountering non-integer input
 */

int read_num_vector_console(int given_vector[])
{
    int count = 0;
    while (scanf("%d", &given_vector[count]) == 1)
    {
        count++;
    }
    return count;
}

struct sequences_maxes maxes_of_sequences()
{
    struct sequences_maxes result;
    int current_number;

    result.nb_of_sequences = 0;

    while (1)
    {
        result.maxes_per_sequence[result.nb_of_sequences] = LIL_NUMBER;
        while (scanf("%d", &current_number) == 1)
        {
            if (current_number == 0)
            {
                if (result.maxes_per_sequence[result.nb_of_sequences] != LIL_NUMBER)
                {
                    result.nb_of_sequences++;
                }
                break;
            }

            if (current_number == -1)
            {
                if (result.maxes_per_sequence[result.nb_of_sequences] != LIL_NUMBER)
                {
                    result.nb_of_sequences++;
                }
                return result;
            }

            if (current_number >= result.maxes_per_sequence[result.nb_of_sequences])
            {
                result.maxes_per_sequence[result.nb_of_sequences] = current_number;
            }
        }
    }
}

int max_of_sequences_maxes(struct sequences_maxes maxes)
{
    int global_max = LIL_NUMBER;

    for (int i = 0; i < maxes.nb_of_sequences; ++i)
    {
        if (maxes.maxes_per_sequence[i] >= global_max)
        {
            global_max = maxes.maxes_per_sequence[i];
        }
    }

    return global_max;
}

int is_value_in_closed_interval(int value, struct pair interval)
{
    return (interval.first <= value) && (value <= interval.second);
}

int closed_interval_len(struct pair interval)
{
    return interval.second - interval.first + 1;
}

struct lsi longest_subsequence_interval(int vector[], int vector_len, struct pair interval)
{
    struct lsi lsi;
    int max_lsi_length = LIL_NUMBER;
    struct pair current_coords;
    struct pair max_coords;

    max_coords.first = LIL_NUMBER;
    max_coords.second = LIL_NUMBER;

    current_coords.first = -1;
    current_coords.second = -1;

    for (int i = 0; i < vector_len; ++i)
    {
        if (is_value_in_closed_interval(vector[i], interval))
        {
            if (current_coords.first == -1)
            {
                current_coords.first = i;
                current_coords.second = i;
            }
            else
            {
                current_coords.second = i;
            }
        }
        else
        {
            int len_of_finished_lsi = closed_interval_len(current_coords);

            if (len_of_finished_lsi >= max_lsi_length)
            {
                max_lsi_length = len_of_finished_lsi;
                max_coords = current_coords;
            }

            current_coords.first = -1;
            current_coords.second = -1;
        }
    }

    int len_of_finished_lsi = closed_interval_len(current_coords);

    if (len_of_finished_lsi >= max_lsi_length)
    {
        max_lsi_length = len_of_finished_lsi;
        max_coords = current_coords;
    }

    if (max_coords.first == LIL_NUMBER)
    {
        lsi.len = 0;
        return lsi;
    }

    int k = 0;
    for (int i = max_coords.first; i <= max_coords.second; ++i, ++k)
    {
        lsi.elems[k] = vector[i];
    }

    lsi.len = max_lsi_length;

    return lsi;
}

/*
interval: [1, 3]
2 3 1 3 9 1 8 2 19 2 3



*/