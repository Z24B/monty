#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
