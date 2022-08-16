#include "sort.h"

/**
 * cocktail_sort_list - sorts a list using the cocktail sort technique
 * @list: pointer to a (head of) list to sort
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list, *min = NULL, *max = NULL;
	int swaps = 1;

	if (!*list || !(*list)->next)
		return;

	while (swaps)
	{
		swaps = 0;
		current = *list;
		while (current->next)
		{
			min = current->next;
			if (current->n > min->n)
			{
				swap(current, min);
				swaps++;
				if (!min->prev)
					*list = min;
				current = current->prev;
				print_list(*list);
			}
			current = current->next;
		}
		while (current->prev)
		{
			max = current->prev;
			if (current->n < max->n)
			{
				swap(current, max);
				swaps++;
				current = current->next;
				print_list(*list);
			}
			current = current->prev;
		}
		if (!swaps)
			break;
	}
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
