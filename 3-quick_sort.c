#include "sort.h"

/**
 * quick_sort - sorts array in asc. order using quick sort
 * @array: the array to be sorted
 * @size: size of @array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - applies recursion to implement quick sort
 * @array: portion of array to be sorted
 * @low: the starting point of portion of @array we're sorting
 * @high: the ending point of portion of @array we're sorting
 * @size: size of original array
 * Return: nothing
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	/* base: they meet means sub array is len 1 */
	if (low >= high)
		return;

	if (low < high)
	{
	pivot_index = partition_array(array, low, high, size);

	/* sort the left side iff pivot isn't at 0*/
	if (pivot_index != 0)
		quick_sort_recursive(array, low, pivot_index - 1, size);

	/* sort the right side */
	quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * partition_array - partitions an array by its elements with relation
 * to the pivot: smaller, pivot, larger
 * @array: array to be partitioned
 * @low: starting index in array to partition
 * @high: ending index in array to partition
 * @size: size of original array
 * Return: index of pivot
 */
size_t partition_array(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	i = low;

	/* use last element as pivot */
	pivot = array[high];
/*	printf("pivot:[%d]\t",pivot);*/

	/* from 1st element to 2nd last element */
	for (j = i; j < size; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_array(array, i, j);
				print_array(array, size);
				/* thus all smaller elements move far left */
			}
			i++;
		}
	}
	/* at this point, pivot is the next smallest. place it at i */
	if (i != high && array[i] != array[high])
	{
		swap_array(array, i, high);
		print_array(array, size);
	}

	return (i);
}

/**
 * swap_array - swaps 2 elements in an array
 * @array: the array in question
 * @idx_1: pointer to the 1st element
 * @idx_2: pointer to the 2nd element
 */
void swap_array(int *array, size_t idx_1, size_t idx_2)
{
	int tmp;

	tmp = array[idx_1];
	array[idx_1] = array[idx_2];
	array[idx_2] = tmp;
}
