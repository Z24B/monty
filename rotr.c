#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the head node pointer
 * @line_num: line number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *current;

	(void)line_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	current = top;

	while (current->next != NULL)
		current = current->next;

	current->next = top;
	top->prev = current;
	top->next->prev = NULL;
	*stack = top->next;
	top->next = NULL;
}
