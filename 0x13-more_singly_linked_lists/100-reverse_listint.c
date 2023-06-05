#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *my_prev = NULL;
	listint_t *my_next = NULL;

	while (*head)
	{
		next = (*head)->my_next;
		(*head)->my_next = my_prev;
		my_prev = *head;
		*head = my_next;
	}

	*head = my_prev;

	return (*head);
}

