#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum value in an array.
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * counting_sort - Performs a counting sort on the array based on a digit place.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current exponent (digit place).
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    // Count occurrences based on the current digit (exp)
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Update count array to accumulate positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy sorted output back to original array
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    print_array(array, size);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD Radix Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int max = get_max(array, size);

    // Perform counting sort for each digit place
    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort(array, size, exp);
}
