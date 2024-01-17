#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: void
 */
int main(int argc, char **argv)
{
	size_t size = 0;
	char *opcode = NULL;
	FILE *source = NULL;
	stack_t *data_stack = NULL;
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	source = fopen(argv[1], "r");
	if (source == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&opcode, &size, source) != EOF)
	{
		line++;
		release(&source, &opcode, 's');
		if (line != '\0')
			free(global.input);
		global.input = parse_instruct(opcode);
		if (global.input == NULL || (global.input[0][0] == '\n' ||
		global.input[0][0] == '#'))
			continue;
		else
			execute_opcode(&data_stack, line);
	}
	release(NULL, NULL, 'r');
	free(global.input);
	free_dlistint(data_stack);
	return (EXIT_SUCCESS);
}
