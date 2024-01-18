#include "monty.h"

/**
 * _isalpha - alphabet checker
 * @i: integer
 * Return: void
 */
int _isalpha(int i)
{
	if ((i >= 97 && i <= 122) || (i >= 65 && i <= 90))
		return (1);
	else
		return (0);
}
