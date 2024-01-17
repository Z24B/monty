#include "monty.h"

/**
 * parse_instruct - formatting & tokenizing Monty instructions for execution
 * @pnt: pointer to character representing the raw Monty instruction
 * Return: void
 */
char **parse_instruct(char *pnt)
{
	size_t x = 0;
	char **tokens = NULL;
	char *token = NULL;

	if (pnt == NULL)
		return ('\0');
	if (pnt[0] == '\0' || pnt[1] == '\0')
		return ('\0');
	newline_replace(&pnt);
	if (blank_string(&pnt) == 1)
		return ('\0');
	tokens = malloc(sizeof(char **) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		release_mem(NULL, NULL, 'r');
		free(tokens);
		exit(EXIT_FAILURE);
	}
	tokens[0] = NULL, tokens[1] = NULL, tokens[2] = NULL;
	token = strtok(pnt, " ");
	while (token != NULL && x <= 1)
	{
		tokens[x] = token;
		token = strtok(NULL, " ");
		if (x >= 1)
			break;
		x++;
	}
	tokens[x + 1] = NULL;
	return (tokens);
}
