#include "sort.h"

/**
 * bubble_sort - sorts @array using the bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size == 0)
		return;


	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&(array[j]), &(array[j + 1]));
				print_array(array, size);
			}

		}
	}	
}

/**
 * swap - swaps @a's and @b's values
 * @a: int #1
 * @b: int #2
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
