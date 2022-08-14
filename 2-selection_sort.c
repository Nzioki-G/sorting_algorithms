#include "sort.h"

/**
 * selection_sort - sorts an array of ints in asc using selection sort
 * @array: the array of ints to sort
 * @size: the size of @array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (!array || size < 2)
		return;

	/* at each point, there are 'i' sorted elements */
	for (i = 0; i < size - 1; i++)
	{
		/* index of min element */
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		/* only swap if a new min has been encountered */
		if (i != min)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
