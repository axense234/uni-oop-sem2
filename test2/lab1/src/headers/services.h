#include <stdio.h>
#include <constants.h>
#include <domain.h>

float to_power_of_n(float x, int n);

/**
 * Reads integers from console input until non-integer input
 * @param[out] given_vector - array to store the numbers read from console
 * @return number of integers successfully read
 *
 * @note Stops reading when encountering non-integer input
 * @note Max size of array is 1000
 */
int read_num_vector_console(int given_vector[]);

/**
 * Reads sequences of integers terminated by 0, with overall input terminated by -1
 * For each sequence, computes the maximum value
 *
 * @return struct sequences_maxes containing:
 *         - maxes_per_sequence[]: array of maximum values for each sequence
 *         - nb_of_sequences: number of sequences processed
 *
 * @note Input format: sequence1 numbers ... 0 sequence2 numbers ... 0 ... -1
 * @note Example: "5 2 7 0 3 9 1 0 -1" → maxes = [7, 9], nb_of_sequences = 2
 * @note LIL_NUMBER is used as initial value for max comparison
 */
struct sequences_maxes maxes_of_sequences(void);

/**
 * Finds the global maximum among all sequence maximums
 *
 * @param[in] maxes - structure containing all sequence maximums
 * @return the largest value among all sequence maximums
 *
 * @note If no sequences were found, returns LIL_NUMBER
 * @note Assumes maxes.nb_of_sequences contains valid count
 */
int max_of_sequences_maxes(struct sequences_maxes maxes);

/**
 * Checks if a value falls within a closed interval [first, second]
 *
 * @param[in] value - the integer to check
 * @param[in] interval - pair containing lower bound (first) and upper bound (second)
 * @return 1 if value is in interval, 0 otherwise
 *
 * @note Assumes interval.first <= interval.second
 */
int is_value_in_closed_interval(int value, struct pair interval);

/**
 * Calculates the length of a closed interval
 *
 * @param[in] interval - pair containing start (first) and end (second) indices
 * @return number of elements in the interval (second - first + 1)
 *
 * @note If interval.first > interval.second, behavior is undefined
 * @note Used to calculate subsequence lengths from coordinate pairs
 */
int closed_interval_len(struct pair interval);

/**
 * Finds the longest contiguous subsequence where all values fall within a given interval
 *
 * @param[in] vector - input array to search
 * @param[in] vector_len - length of the input array
 * @param[in] interval - value range [first, second] to check against
 * @return struct lsi containing:
 *         - elems[]: the longest subsequence found
 *         - len: length of the subsequence (0 if none found)
 *
 * @note If multiple subsequences have the same maximum length, returns the last one found
 * @note Empty result (len=0) is returned when no values are within the interval
 * @note Time complexity: O(n) where n = vector_len
 *
 * @example vector = [2,3,1,3,9,1,8,2,19,2,3], interval=[1,3]
 *          returns [2,3,1,3] (indices 0-3) or [2,3] (indices 9-10)?
 *          Actually returns longest: [2,3,1,3] (length 4)
 */
struct lsi longest_subsequence_interval(int vector[], int vector_len, struct pair interval);