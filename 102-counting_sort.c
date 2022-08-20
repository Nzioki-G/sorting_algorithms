#include "sort.h"

/**
 * counting_sort - sorts array using counting sort algorithm
 * this algorithm doesn't compare values
 * @array: the array to sort
 * @size: the size of @array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *count_array = NULL, *copy = NULL;
	size_t j, tmp, total = 0;

	if (!array || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (j = 0, max = 0; j < size; j++)/* find the max element in @array */
	{
		copy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
	{
		free(copy);
		return;
	}
	for (i = 0; i < max; i++) /* init counting_array with 0s */
		count_array[i] = 0;
	for (j = 0; j < size; j++) /* count occurrences of @array elements */
		count_array[array[j]] += 1;

	for (i = 0; i <= max; i++) /* get cumulative frequency(c.f) */
	{
		tmp = count_array[i];
		count_array[i] = total;
		total += tmp;
	}
	/* elements from copy are stored in @arr at index c.f. */
	for (j = 0; j < size; j++)
	{
		array[count_array[copy[j]]] = copy[j];
		count_array[copy[j]] += 1; /* decrement cumulative frequency */
	}
	print_array(count_array, max + 1);
	free(count_array);
	free(copy);
}
