#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *list)
{
	list_t *current;

	while (list)
	{
		current = list->next;
		free(list->str);
		free(list);
		list = current;
	}
}
