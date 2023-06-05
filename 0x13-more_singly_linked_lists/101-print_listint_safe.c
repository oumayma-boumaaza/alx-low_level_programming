#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

size_t looped_listint_len(const listint_t *head);

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *loop_node = NULL;

	if (head == NULL)
		return (0);

	if (looped_listint_len(head) == 0)
	{
		while (current != NULL)
		{
			printf("[%p] %d\n", (void *)current, current->n);
			count++;
			current = current->next;
		}
	}
	else
	{
		while (current != NULL)
		{
			printf("[%p] %d\n", (void *)current, current->n);
			count++;
			if (current == loop_node)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				break;
			}
			current = current->next;
			if (current == loop_node)
				break;
			if (count == 1 || count % 2 == 0)
				loop_node = loop_node == NULL ? head : loop_node->next;
		}
	}

	return (count);
}

