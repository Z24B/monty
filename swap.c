#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int input;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	input = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = input;
}
