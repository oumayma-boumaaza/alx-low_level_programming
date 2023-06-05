#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *my_node;

	my_node = malloc(sizeof(listint_t));
	if (!my_node)
		return (NULL);

	my_node->n = n;
	my_node->next = *head;
	*head = my_node;

	return (my_node);
}
