#include "monty.h"

/**
 * execute_opcode - identify opcode & call function to execute the instruction
 * @top: top of stack
 * @num: number
 * Return: void
 */
void execute_opcode(stack_t **top, unsigned int num)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"swap", swap},
		{"rotl", rotl},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int x;

	for (x = 0; ops[x].opcode != NULL; x++)
	{
		if (strcmp(global.input[0], ops[x].opcode) == 0)
		{
			ops[x].f(top, num);
			return;
		}
	}
	if (ops[x].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", num, global.input[0]);
		free(global.input);
		free_dlistint(*top);
		release(NULL, NULL, 'r');
		exit(EXIT_FAILURE);
	}
}