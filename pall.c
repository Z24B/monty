#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack:pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
