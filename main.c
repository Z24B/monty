#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define MAX_LINE_SIZE 1024

int main(int argc, char **argv)
{
	size_t size = MAX_LINE_SIZE;
	char opcodes[MAX_LINE_SIZE];
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
	
	while (fgets(opcodes, size, source) != NULL)
	{
		line++;
		if (opcodes[0] == '\n' || opcodes[0] == '#')
			continue;
		
		release_mem(&source, NULL, 's');
		global.input = parse_instruct(opcodes);
		
		if (global.input == NULL || global.input[0][0] == '\n' || global.input[0][0] == '#')
			continue;
		else
			execute_opcode(&data_stack, line);
	}
	
	fclose(source);
	release_mem(NULL, NULL, 'r');
	free(global.input);
	free_dlistint(data_stack);
	
	return EXIT_SUCCESS;
}

