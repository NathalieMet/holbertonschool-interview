#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turns a subtree into a max heap
 * @array: The array
 * @size: Total size of the array
 * @root: Index of the root of the subtree
 * @end: Index of the last element in the heap
 */
void heapify(int *array, size_t size, size_t root, size_t end)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[largest])
		largest = left;

	if (right < end && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, end);
	}
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Build the heap */
	for (size_t i = size / 2 - 1; i < size; --i)
		heapify(array, size, i, size);

	/* Extract elements from heap one by one */
	for (size_t i = size - 1; i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
