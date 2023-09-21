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
	/* current = current->next; */
	while (current)
	{
		key = current;
		while (current->prev && (current->prev->n > current->n))
		{
			/* inserting at head
			if (current->prev->prev == NULL)
			{
				*list = current;
				print_list(current);
				print_list(*list);
			}
			else
			{*/
			/* swap */
			swap_nodes(current->prev, current);
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		
		current = key->next;
	
		/* current = key->next */;
	}
}
