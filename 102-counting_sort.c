#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using Counting Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	int max_value = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	for (i = 0; i <= (size_t)max_value; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[(int)array[i]]++;

	for (i = 1; i <= (size_t)max_value; i++)
		count_array[i] += count_array[i - 1];

	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output_array[count_array[(int)array[i]] - 1] = array[i];
		count_array[(int)array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	print_array(count_array, (size_t)(max_value + 1));
	free(count_array);
	free(output_array);
}
