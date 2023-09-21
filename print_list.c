#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
		list->next->prev = list;
	}
	return (list);
}

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

/**
 * swap_nodes - swaps 2 doubly-linked-list nodes
 * @node_a: the left node
 * @node_b: the right node
*/
void swap_nodes(listint_t *node_a, listint_t *node_b)
{
	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	if (node_a->prev)
		node_a->prev->next = node_b;
	if (node_b->next)
		node_b->next->prev = node_a;

	node_a->prev = node_b;
	node_b->next = node_a;
}
