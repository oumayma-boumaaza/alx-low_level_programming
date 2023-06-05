#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *my_node;
	listint_t *my_current = *head;

	my_node = malloc(sizeof(listint_t));
	if (!my_node || !head)
		return (NULL);

	my_node->n = n;
	my_node->next = NULL;

	if (idx == 0)
	{
		my_node->next = *head;
		*head = my_node;
		return (my_node);
	}

	for (i = 0; my_current && i < idx; i++)
	{
		if (i == idx - 1)
		{
			my_node->next = my_current->next;
			my_current->next = my_node;
			return (my_node);
		}
		else
			my_current = my_current->next;
	}

	return (NULL);
}
