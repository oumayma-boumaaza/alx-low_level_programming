#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: first node in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *my_current = head;
	unsigned int numb = 0;

	while (my_current && numb  < index)
	{
		my_current = my_current->next;
		numb ++;
	}

	return (my_current ? my_current : NULL);

}
