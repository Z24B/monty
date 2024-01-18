#include "monty.h"

/**
 * main - Entry point process
 * @argc: number of arguments
 * @argv: arguments array
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *mainf;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	mainf = fopen(argv[1], "r");
	if (!mainf)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(mainf);
	fclose(mainf);
	return (EXIT_SUCCESS);
}
