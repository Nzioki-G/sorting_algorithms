#include "sort.h"

/**
 * cocktail_sort_list - sorts a list using the cocktail sort technique
 * @list: pointer to a (head of) list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list;
	int swaps = 1;

	if (!*list || !(*list)->next || !list)
		return;
	do {
		swaps = 0;
		current = *list;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				swap(current, current->next);
				swaps++;
				print_list(*list);
				if (!current->prev)
					*list = current->next;
				current = current->prev;
			}
			current = current->next;
		}
		if (!swaps)
			break;
		swaps = 0;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap(current->prev, current);
				swaps++;
				if (!current->prev)
					*list = current;
				print_list(*list);
				current = current->next;
			}
			current = current->prev;
		}
		if (!swaps)
			break;
	} while (swaps);
}


/**
 * swap - swaps 2 nodes
 * @nodeA: the first node
 * @nodeB: the second node
 * return: nothing
 */
void swap(listint_t *nodeA, listint_t *nodeB)
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
