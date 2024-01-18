#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line, char *arg);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void subop(stack_t **stack, unsigned int line_num);
void divop(stack_t **stack, unsigned int line_num);
void mulop(stack_t **stack, unsigned int line_num);
void modop(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);

void read_file(FILE *mainf);
void free_list(stack_t **head);
bool arg_push(char *arg);
void opcode_command(char *opcode, stack_t **stack, unsigned int line, FILE *f);
#endif
