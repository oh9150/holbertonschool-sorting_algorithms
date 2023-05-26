#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using Counting Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max_element, i;
	int *count_array, *sorted_array;

	if (size < 2)
		return;

	max_element = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_element)
			max_element = array[i];
	}

	count_array = malloc(sizeof(int) * (max_element + 1));
	if (!count_array)
		return;
	for (i = 0; i <= max_element; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= max_element; i++)
		count_array[i] += count_array[i - 1];
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
	free(count_array);
	free(sorted_array);
}
