#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *my_current;

	while (head)
	{
		my_current = head->next;
		free(head);
		head = my_current;
	}
}
