#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *top = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		return;
	}

	if (top->next != NULL)
	{
		*stack = top->next;
		(*stack)->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(top);
}
