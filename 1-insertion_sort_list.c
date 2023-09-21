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
