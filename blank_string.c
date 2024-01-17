#include "monty.h"

/**
 * blank_string - check if string is empty or contains only spaces
 * @str: parameter
 * Return: void
 */
int blank_string(char **str)
{
	int x = 0;

	while (str[0][x] != '\0')
	{
		if (str[0][x] != ' ')
			return (-1);
		x++;
	}
	return (1);
}
