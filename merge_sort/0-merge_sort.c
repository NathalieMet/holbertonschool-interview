#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into a single sorted array.
 * @array: The original array being sorted.
 * @temp: Temporary array to hold the sorted elements.
 * @left: The starting index of the left sub-array.
 * @mid: The middle index, which is the end of the left sub-array.
 * @right: The ending index of the right sub-array.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    printf("Merging...\n[left]: ");
    for (size_t x = left; x < mid; x++)
        printf("%d%s", array[x], x < mid - 1 ? ", " : "");
    printf("\n[right]: ");
    for (size_t x = mid; x < right; x++)
        printf("%d%s", array[x], x < right - 1 ? ", " : "");
    printf("\n");

    /* Merge the two sub-arrays */
    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    /* Copy remaining elements of the left sub-array, if any */
    while (i < mid)
        temp[k++] = array[i++];

    /* Copy remaining elements of the right sub-array, if any */
    while (j < right)
        temp[k++] = array[j++];

    /* Copy the sorted sub-array into the original array */
    for (i = left; i < right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    for (size_t x = left; x < right; x++)
        printf("%d%s", array[x], x < right - 1 ? ", " : "");
    printf("\n");
}

/**
 * merge_sort_recursive - Recursively sorts an array using Merge Sort algorithm.
 * @array: The array to sort.
 * @temp: Temporary array used for merging.
 * @left: The starting index of the current sub-array.
 * @right: The ending index of the current sub-array.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (right - left <= 1)
        return;

    size_t mid = left + (right - left) / 2;

    /* Recursively sort left and right sub-arrays */
    merge_sort_recursive(array, temp, left, mid);
    merge_sort_recursive(array, temp, mid, right);

    /* Merge the two sorted sub-arrays */
    merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int *temp = malloc(size * sizeof(int));

    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}
