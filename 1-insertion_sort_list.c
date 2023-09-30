#include "sort.h"

/**
 * insertion_sort_list - loop through a list. If you find an ill-positioned
 * element, take it to its correct position then continue where you left off
 * @list: a doubly linked list of integer
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *key;
	listint_t *current;

	current = *list;
	while (current)
	{
		key = current;

		/* take a mis-positioned element back node by node */
		while (current->prev && (current->prev->n > current->n))
		{
			/* swap */
			swap_nodes(current->prev, current);

			/* reseting node at head */
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		/* here's where we were */
		current = key->next;
	}
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
