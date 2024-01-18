#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
}
