#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Linked list to search for.
 *
 * Return: Address of the node where the loop starts, or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head;
	listint_t *hare = head;

	if (!head)
		return (NULL);

	while (turtle && hare && hare->next)
	{
		hare = hare->next->next;
		turtle = turtle->next;
		if (hare == turtle)
		{
			turtle = head;
			while (turtle != hare)
			{
				turtle = turtle->next;
				hare = hare->next;
			}
			return (hare);
		}
	}

	return (NULL);
}

