#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using bubble sort
 * @array: the array to be sorted
 * @size: size of @array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp, swaps;
	size_t i = 0;

	if (size < 2)
		return;
	while (array)
	{
		swaps = 0;
		for (i = 0; i < size - 1; i++)
		{
			tmp = array[i + 1];
			if (array[i] > tmp)
			{
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swaps++;
			}
		}
		if (swaps == 0)
			break;
	}
}
