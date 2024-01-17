#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - adds a new node to the top of the stack
 * @stack: the stack
 * @cmdline: command line
 * Return: void
 */
void push(stack_t **stack, unsigned int cmdline)
{
	stack_t *new, *temp;

	if (global.input[1] == NULL || checker(global.input[1]) == -1)
	{
		fprintf(stderr, "L%i: usage: push integer\n", cmdline);
		release_mem(NULL, NULL, 'r');
		free_dlistint(*stack);
		free(global.input);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		release_mem(NULL, NULL, 'r');
		free_dlistint(*stack);
		free(global.input);
		exit(EXIT_FAILURE);
	}
	new->next = '\0';
	new->n = atoi(global.input[1]);
	new->prev = '\0';
	*stack = new;
	new->next = temp;
	if (temp != NULL)
		temp->prev = new;
}
