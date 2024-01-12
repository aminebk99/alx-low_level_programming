#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a doubly linked list.
 * @h: Double pointer to the head of the list.
 * @idx: Index where the new node should be added (starting from 0).
 * @n: Value to be assigned to the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    if (h == NULL)
        return (NULL);

    dlistint_t *current = *h, *new;

    if (idx == 0)
        return (add_dnodeint(h, n));

    while (idx != 1)
    {
        if (current == NULL)
            return (NULL);
        current = current->next;
        idx--;
    }

    if (current == NULL || current->next == NULL)
        return (add_dnodeint_end(h, n));

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->prev = current;
    new->next = current->next;
    current->next->prev = new;
    current->next = new;

    return (new);
}

