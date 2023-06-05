#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *my_current = *head;
	listint_t *my_prev = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(my_current);
		return (1);
	}

	while (i < index - 1)
	{
		if (!my_current || !(my_current->next))
			return (-1);
		my_current = my_current->next;
		i++;
	}


	my_prev = my_current->next;
	my_current->next = my_prev->next;
	free(my_prev);

	return (1);
}

