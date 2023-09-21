#include "sort.h"

/**
 * selection_sort - least goes to idx 0 by swapping. Next goes to idx 1...
 * This one's time complexity NEVER improves. It will always search for the
 * least in the remaining elements.
 * @array: the array of integers to sort
 * @size: the length of this array
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, least, min;
	int tmp;

	for (idx = 0; idx < size - 1; idx++)
	{
		/* find the min of the unsorted elements */
		min = idx;
		for (least = idx + 1; least < size; least++)
		{
			if (array[least] < array[min])
				min = least;
			/* printf("# "); */
		}
		/* printf("\n"); */
		if (min == idx)
			continue;
		/* swap then print */
		tmp = array[idx];
		array[idx] = array[min];
		array[min] = tmp;
		print_array(array, size);
	}
}
