#include "monty.h"

/**
 * subop - subtracts top element of stack from second top element of stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void subop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
