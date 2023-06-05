#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *my_current = head;

	while (my_current)
	{
		sum += my_current->n;
		my_current = my_current->next;
	}

	return (sum);
}
