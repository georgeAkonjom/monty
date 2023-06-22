#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

extern stack_t *main_stack;

void com_handle(char **, unsigned int);
void push_inst(stack_t **, unsigned int);
void pall_inst(stack_t **, unsigned int);
void pop_inst(stack_t **, unsigned int);
void pexit(int);
FILE *file_getset(FILE *);
void pint_inst(stack_t **stack, unsigned int line_number);
void swap_inst(stack_t **stack, unsigned int line_number);
void nop_inst(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
