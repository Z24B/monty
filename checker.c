#include "monty.h"

/**
 * checker - check if string is a number
 * @num: number
 * Return: void
 */
int checker(char *num)
{
	int x = 0;

	if (num[0] == '-')
		x++;
	while (num[x] != '\0')
	{
		if (num[x] < 48 || num[x] > 57)
			return (-1);
		x++;
	}
	return (1);
}
