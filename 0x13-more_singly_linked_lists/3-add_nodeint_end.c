#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *my_node;
	listint_t *my_last = *head;

	my_node = malloc(sizeof(listint_t));
	if (!my_node)
		return (NULL);

	my_node->n = n;
	my_node->next = NULL;

	if (*head == NULL)
	{
		*head = my_node;
		return (my_node);
	}

	while (my_last->next)
		my_last = my_last->next;

	my_last->next = my_node;

	return (my_node);
}
