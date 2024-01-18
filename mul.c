#include "monty.h"

/**
 * mulop - multiplies second top element of stack with top element of the stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void mulop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
