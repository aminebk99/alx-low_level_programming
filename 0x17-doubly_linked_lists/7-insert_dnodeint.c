#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: A pointer to a pointer to the head of the list.
 * @idx: The index where the new node should be added (starting from 0).
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new_node, *current = *h;

	new_node = malloc(sizeof(dlistint_t));
	if (!h)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; current && i < idx - 1; i++)
		current = current->next;

	if (!current)
		return (NULL);

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;

	if (current->next)
		current->next->prev = new_node;

	current->next = new_node;

	return (new_node);
}
