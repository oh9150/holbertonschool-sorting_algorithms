#include "sort.h"

/**
 * shell_sort - sorts an array or integers in ascending order using the shell
 * sort algorithm, using the knuth sequence
 * @array: the array to sort
 * @size: the size of @array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, n = 1;

	if (!array)
		return;

	for (; n < size; n = n * 3 + 1)
	{

		for (i = n - 1; i < size; i++)
		{
			if (array[i - n - 1] > array[i])
				swap(&array[i - n - 1], &array[i]);
		}
		print_array(array, size);
	}
}

/**
 * swap - swaps two integers in an array
 * @a: int #1
 * @b: int #2
 */
void swap(int *a, int *b)
{
	int tmp = *a;
 
	*a = *b;
	*b = tmp;
}
