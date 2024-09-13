#include <stdio.h>
#include <stddef.h>
#include "search_algos.h"

/**
 * print_array - Prints the array being searched
 * @array: Pointer to the first element of the array
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive function to perform the binary search
 * @array: Pointer to the first element of the array
 * @left: Left boundary of the subarray
 * @right: Right boundary of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        /* Check if it's the first occurrence or continue searching in the left */
        if (mid == left || array[mid - 1] != value)
            return (mid);
        return (advanced_binary_recursive(array, left, mid - 1, value));
    }
    else if (array[mid] > value)
        return (advanced_binary_recursive(array, left, mid - 1, value));
    else
        return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
