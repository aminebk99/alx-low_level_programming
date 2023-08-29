#include "lists.h"
/**
* reverse_listint - reverser
* @head: pointer
* Return:first node in the new list.
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *pr = NULL;
listint_t *next = NULL;
while (*head)
{
next = (*head)->next;
(*head)->next = pr;
pr = *head;
*head = next;
}
*head = pr;
return (*head);
}
