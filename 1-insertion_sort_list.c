#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly ll in asc order using insertion sort
 * @list: the list to sort
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;

	/* if list is empty|has 1 element */
	if (!*list || !current || !current->next)
		return;

	/* start from 2nd element */
	current = current->next;
	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			/* if the prev is there and bigger, swap */
			swap(current->prev, current);

			/* if post swap, our node is at head, update head */
			if (!current->prev)
			{
				*list = current;
			}

			/* print */
			print_list(*list);
		}
		current = current->next;
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
