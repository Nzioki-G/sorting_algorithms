#include "sort.h"

/**
 * get_partition - given an array, take the last element as the pivot
 * and split the array such that all elements on left and right side of pivot
 * are less than and grater that pivot
 * @array: the array to partition
 * @low: the first point of array to consider
 * @high: the last in the range of array to consider
 * @size: size of the full array
 * Return: the index of point at which to split array
 */
size_t get_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, tmp;
	size_t potential_pos, iter;

	/* last elements as pivot */
	pivot = array[high];

	potential_pos = low;
	iter = potential_pos;

	while (iter < high)
	{
		if (array[iter] <= pivot)
		{
			/* move temp pivot idx forward */

			/* swap current elem with elem at temp pivot */
			if (potential_pos != iter)
			{
				tmp = array[potential_pos];
				array[potential_pos] = array[iter];
				array[iter] = tmp;
				print_array(array, size);
			}
			potential_pos++;
		}
		iter++;
	}
	if (potential_pos != high && pivot != array[potential_pos])
	{
		array[high] = array[potential_pos];
		array[potential_pos] = pivot;
		print_array(array, size);
	}

	return (potential_pos);
}

/**
 * quick_recursive - recursively perfoms quicksort on the 2 partitions
 * @array: the array being sorted
 * @low: the index of start of array portion to sort
 * @high: index of the last index in array range being sorted
 * @size: size of array
 */
void quick_recursive(int *array, size_t low, size_t high, size_t size)
{
	int partition;

	/* list is shorter than 2 */
	if (low >= high)
		return;

	if (low < high)
	{
	/* partition and get the index to pivot at */
	partition = get_partition(array, low, high, size);

	/* sort the 2 partitions */
	if (partition != 0)
		quick_recursive(array, low, partition - 1, size); /* left side of pivot */
	quick_recursive(array, partition + 1, high, size); /* right side of pivot */
	}
}

/**
 * quick_sort - pick a pivot. Place all smaller-than-pivot to the left
 * and all greater-than-pivot to the right.
 * Place pivot in the middle (it's sorted!) Do the same for each partition
 * @array: the integers to sort
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_recursive(array, 0, size - 1, size);
}
