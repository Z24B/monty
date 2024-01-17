#include "monty.h"

/**
 * newline_replace - replacing all newline characters with null characters
 * @str: pointer to a pointer to a character
 * Return: void
 */
void newline_replace(char **str)
{
	char *s = *str;
	int x = 0;

	while (s[x] != '\0')
	{
		if (s[x] == '\n')
			s[x] = ''\0';
		x++;
	}
}
