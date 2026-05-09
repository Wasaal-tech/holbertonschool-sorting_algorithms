#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to pointer to head of list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *prev;
	int *tmp;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		while (prev != NULL && prev->n > curr->n)
		{
			prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev;
			curr->prev = prev->prev;
			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;
			curr->next = prev;
			prev->prev = curr;
			(void)tmp;
			print_list(*list);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}
