#include "monty.h"

/**
 * modop - division of second top element of stack by top element of stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void modop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
