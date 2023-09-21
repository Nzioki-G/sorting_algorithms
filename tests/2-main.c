#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {7, 13, 19, 48, 52, 71, 73, 86, 96, 99};
	/*{19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
