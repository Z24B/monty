#include "monty.h"

/**
 * release_mem - releases the memory
 * @source: FILE streaming
 * @opcode: instructions
 * @act: the action for function
 * Return: void
 */
void release_mem(FILE **source, char ***opcode, char act)
{
	static FILE *save1;
	static char **save2;
	
	if (act == 's')
	{
		save1 = *source;
		save2 = *opcode;
	}
	else if (act == 'r')
	{
		free(save2);
		fclose(save1);
	}
}

