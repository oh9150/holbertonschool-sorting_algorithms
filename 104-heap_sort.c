#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers
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
 * sift_down - Performs sift-down operation in heap sort
 * @array: Array to sort
 * @size: Size of the array
 * @start: Starting index of the subtree
 * @end: Ending index of the subtree
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;

		if (child + 1 <= end && array[child] < array[child + 1])
			child++;

		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers using Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
