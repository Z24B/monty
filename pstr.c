#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	(void)line_num;

	while (current != NULL && current->n != 0 &&
			current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
