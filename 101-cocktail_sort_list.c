#include "sort.h"

/**
 * cocktail_sort_list - compare arr[i] with arr[i + 1] and swap as needed.
 * To the end and the back comparing arr[i - 1] with arr[i]
 * @list: the doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list;
	int is_sorted = 0;

	if (!list || !*list || !(*list)->next)
		return;
	while (!is_sorted)
	{
		is_sorted = 1; /* sorted unless proven unsorted */
		while (current->next) /* check forwards */
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				print_list(*list);
				if (!current->prev)
					*list = current->next;
				current = current->prev;
				is_sorted = 0;
			}
			current = current->next;
		}
		if (is_sorted)
			break;
		is_sorted = 1;
		while (current->prev) /* check backwards */
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				if (!current->prev)
					*list = current;
				print_list(*list);
				current = current->next;
				is_sorted = 0;
			}
			current = current->prev;
		}
		if (is_sorted)
			break;
	}
}

/**
 * swap_nodes - swaps 2 doubly-linked-list nodes
 * @nodeA: the left node
 * @nodeB: the right node
*/
void swap_nodes(listint_t *nodeA, listint_t *nodeB)
{
	/* a-prev|null, nA, nB, b-next|null */
	if (nodeA->prev != NULL)
		nodeA->prev->next = nodeB;
	if (nodeB->next != NULL)
		nodeB->next->prev = nodeA;

	nodeB->prev = nodeA->prev;
	nodeA->prev = nodeB;
	nodeA->next = nodeB->next;
	nodeB->next = nodeA;
	/* a-prev|null, nB, nA, b-next|null */
}
