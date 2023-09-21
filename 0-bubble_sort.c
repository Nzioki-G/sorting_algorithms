#include "sort.h"

/**
 * bubble_sort - loop over and over through array swapping
 * to accomodate sorting order(asc) until sorted
 * @array: the array to sort
 * @size: the length of array
*/
void bubble_sort(int *array, size_t size)
{
	int not_sorted = 1;
	size_t idx;
	int tmp;

	if (size <= 0)
		return;

	while (not_sorted)
	{
		not_sorted = 0;
		for (idx = 1; idx < size; idx++)
		{
			/* element is smaller than previous; swap */
			if (array[idx] < array[idx - 1])
			{
				not_sorted = 1;
				tmp = array[idx];
				array[idx] = array[idx - 1];
				array[idx - 1] = tmp;
				print_array(array, size);
			}
		}
		if (not_sorted == 0)
			break;
	}
}
