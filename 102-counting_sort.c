#include "sort.h"

/**
 * counting_sort - make a count_array (size if greatest element + 1). In it
 * track the frequency of occurrence of each element in @array then sort
 * @array: the array to sort. All elements are ints >= 0
 * @size: the length of @array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, max_element, *result;
	size_t idx, count_size, pos;

	max_element = array[0];
	/* get the maximum element in array */
	for (idx = 1; idx < size; idx++)
	{
		if (array[idx] > max_element)
			max_element = array[idx];
	}
	count_size = max_element + 1;
	count_array = malloc(sizeof(int) * count_size);

	/* init count array with 0s */
	for (idx = 0; idx < count_size; idx++)
		count_array[idx] = 0;

	/* record frequency of array elements into count_array */
	for (idx = 0; idx < size; idx++)
	{
		pos = array[idx];
		count_array[pos] += 1;
	}

	/* calculate the cummulative frequecy */
	for (idx = 1; idx < count_size; idx++)
		count_array[idx] += count_array[idx - 1];

	print_array(count_array, count_size);

	/* place elements at their sorted position */
	result = malloc(size);
	for (idx = 0; idx < size; idx++)
	{
		pos = --count_array[array[idx]];
		result[pos] = array[idx];
	}

	/* copy the sorted into the initial array */
	for (idx = 0; idx < size; idx++)
	{
		array[idx] = result[idx];
	}
	free(count_array);
	free(result);
}