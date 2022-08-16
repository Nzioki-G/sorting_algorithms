#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: integer stroed in the node
 * @prev: pointer to the previous elemnet of the list
 * @next: pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(listint_t *nodeA, listint_t *nodeB);
listint_t *create_listint(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void swap_array(int *array, size_t idx_1, size_t idx_2);
size_t partition_array(int *array, size_t low, size_t high, size_t size);
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

#endif
