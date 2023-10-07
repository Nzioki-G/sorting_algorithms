#include "sort.h"

/**
 * power - gets the power of a number
 * @x: the base
 * @y: the exponent
 * Return: x ^ y
 */
int power(int x, int y)
{
	while (y-- > 1)
		x *= x;
	return (x);
}

/**
 * getNumAtPlace - get the integer at place value
 * @number: the whole number
 * @place: the place value
 * Return: the number in @number at place_value @place
 */
int getNumAtPlace(int number, int place)
{
	int value;

	value = power(10, place);
	return (number % value / (value / 10));
}

/**
 * getMaxPlaceValue - gets the maximum number's most significant place value
 * @array: an array of positive numbers
 * @size: length of @array
 * Return: the most significant place value of the max(array)
 */
int getMaxPlaceValue(int *array, size_t size)
{
	size_t idx;
	int max_num, place_value;

	max_num = array[0];
	place_value = 0;

	/* get max in array; for place_value */
	for (idx = 1; idx < size; idx++)
	{
		if (array[idx] > max_num)
			max_num = array[idx];
	}

	/* get most significant place value */
	while (max_num > 0)
	{
		max_num /= 10;
		place_value++;
	}

	return (place_value);
}

/**
 * reverse_array - reverses an array
 * @array: the array to reverse
 * @size: length of @array
 */
void reverse_array(int *array, size_t size)
{
	size_t left, right;
	int tmp;

	left = 0;
	right = size - 1;

	while (left < size / 2)
	{
		tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;

		left++;
		right--;
	}
}

/**
 * radix_sort - use count sort on each place value from least significant
 * LSD radix sort. This way the count array will always be length 10
 * @array: the array to sort containing numbers >= 0
 * @size: the length of the array
 */
void radix_sort(int *array, size_t size)
{
	int *count_array, *result_array, position, place = 1, place_value;
	size_t idx, res;

	if (size < 2)
		return;

	/* init count array with 0s */
	count_array = malloc(sizeof(int) * 10);
	result_array = malloc(sizeof(int) * size);
	place_value = getMaxPlaceValue(array, size);

	/* from LSD sort using count sort */
	while (place <= place_value)
	{
		for (idx = 0; idx < 10; idx++) /* init with 0s */
			count_array[idx] = 0;

		for (idx = 0; idx < size; idx++) /* count frequency */
		{
			position = getNumAtPlace(array[idx], place);
			count_array[position] += 1;
		}

		for (idx = 1; idx < 10; idx++) /* cumulative frequency */
			count_array[idx] += count_array[idx - 1];

		reverse_array(array, size);
		/* sort according to frequency */
		for (idx = 0; idx < size; idx++)
		{
			position = getNumAtPlace(array[idx], place);
			res = --count_array[position];
			result_array[res] = array[idx];
		}
		print_array(result_array, size);
		for (idx = 0; idx < size; idx++)
			array[idx] = result_array[idx];

		place++;
	}
}
