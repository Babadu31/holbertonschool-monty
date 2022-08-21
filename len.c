#include "monty.h"

// nécessaire à partir de add

/**
 * dlistint_len - returns the number of elements in a d linked list
 * @h: head of the linked list
 * Return: the number of nodes
 */
size_t dlistint_len(stack_t *h)
{
	size_t n_nodes = 0;

	if (h == NULL)
	{
		return (0);
	}
	
  while (h != NULL)
	{
		h = h->next;
		n_nodes++;
	}
	return (n_nodes);
}
