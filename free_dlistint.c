#include "monty.h"

/**
 * free_dlistint - free the memory allocated for a doubly linked list
 * @head: pointer to the head of a doubly linked list
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *x;

	if (head != NULL)
		while (head != NULL)
		{
			x = head;
			head = head->next;
			free(x);
		}
}
