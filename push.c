#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head node pointer
 * @line: line number
 * @arg: arguments
 * Return: void
 */
void push(stack_t **stack, unsigned int line, char *arg)
{
	stack_t *head = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: Error stack not found\n", line);
		exit(EXIT_FAILURE);
	}
	head = malloc(sizeof(stack_t));

	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	head->n = atoi(arg);
	head->prev = NULL;
	head->next = *stack;
	if (*stack)
		(*stack)->prev = head;

	(*stack) = head;
}
