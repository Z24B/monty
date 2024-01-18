#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_SIZE 256

/**
 * read_file - read file line by line
 * @mainf: file
 * Return: void
 */
void read_file(FILE *mainf)
{
	stack_t *stack = NULL;
	char *opcode = NULL;
	char *arg = NULL;
	char line[MAX_LINE_SIZE];
	unsigned int line_num = 0;

	while (fgets(line, sizeof(line), mainf) != NULL)
	{
		line_num++;
		opcode = strtok(line, " \n");

		if (opcode == NULL || strchr(opcode, '#') != NULL)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \n");
			if (arg != NULL && arg_push(arg))
			{
				push(&stack, line_num, arg);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				free_list(&stack);
				fclose(mainf);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			opcode_command(opcode, &stack, line_num, mainf);
		}
	}
	free_list(&stack);
}

/**
 * free_list - frees a list
 * @head: head of the list
 * Return: void
 */
void free_list(stack_t **head)
{
	stack_t *tmp = NULL;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		(*head) = tmp;
	}
}

/**
 * arg_push - valid push arguments
 * @arg: argument
 * Return: void
 */
bool arg_push(char *arg)
{
	int x = 0;

	for ( ; arg[x]; x++)
	{
		if (arg[0] == '-')
			continue;

		if (isdigit(arg[x]) == 0)
			return (false);
	}
	return (true);
}

/**
 * opcode_command - function to process each command
 * @opcode: execution code
 * @stack: the stack
 * @line: line number
 * @f: file
 * Return: void
 */
void opcode_command(char *opcode, stack_t **stack, unsigned int line, FILE *f)
{
	int x = 0;
	instruction_t opcodes[] = {
		{"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop},
		{"sub", subop}, {"div", divop},
		{"mul", mulop}, {NULL, NULL}};

	while (opcodes[x].opcode != NULL)
	{
		if (strcmp(opcodes[x].opcode, opcode) == 0)
		{
			opcodes[x].f(stack, line);
			return;
		}
		x++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	free(opcode);
	free_list(stack);
	fclose(f);
	exit(EXIT_FAILURE);
}
