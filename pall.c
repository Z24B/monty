#include "monty.h"

/**
 * pall - prints all the values on the stack from the top
 * @stack: the stack
 * @cmdline: command line
 * Return: void
 */
void pall(stack_t **stack, unsigned int cmdline __attribute__((unused)))
{
	stack_t *print;

	print = *stack;
	if (print == NULL)
		return;
	while (print != NULL)
	{
		printf("%i\n", print->n);
		print = print->next;
	}
}
