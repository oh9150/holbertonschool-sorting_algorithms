#include "sort.h"

/**
 * bubble_sort - sorts @array using the bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i <= size; i++)
	{
		for (j = 0; (size_t)array[j] < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&(array[j]), &(array[j + 1]));
				print_array(array, size);
			}

		}
	}	
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
