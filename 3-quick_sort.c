#include "sort.h"

/**
 * swap - swaps two elements's value
 * @a: int #1
 * @b: int #2
 */
void swap(int *a, int *b)
{
	int tmp;

	if (!a || !b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort - sorts @array using the quick sort algorithm with the "Lomuto"
 * partition
 * @array: the the array
 * @size: the size of @array
 */
void quick_sort(int *array, size_t size)
{
		int low = 0, high = size - 1;

		if (array == NULL)
			return;

		quick_sort_recursive(array, low, high, size);
}

/**
 * quick_sort_recursive - recursive function for quick sort algorithm
 * @array: the array to sort
 * @low: the bottom of the array
 * @high: the top of the array
 * @size: the size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;


	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * partition - takes the last element as pivot, places it in the correct
 * position and places all smaller elements to the left of the pivot and all
 * greater to the right
 * @array: the array
 * @low: the bottom of the array
 * @high: the top of the array
 * @size: the size of the array
 * Return: the index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);

	return (i + 1);
}
