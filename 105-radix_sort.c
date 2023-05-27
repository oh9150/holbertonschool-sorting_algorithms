#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using LSD radix sort
 * @array: The array of integers
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *count, *output;

	max = get_max(array, size);
	count = malloc(sizeof(int) * 10);
	output = malloc(sizeof(int) * size);
	if (!count || !output)
	{
		free(count);
		free(output);
		return;
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		int i;

		for (i = 0; i < 10; i++)
			count[i] = 0;

		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(count);
	free(output);
}

/**
 * get_max - Returns the maximum element in an array of integers
 * @array: The array of integers
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
