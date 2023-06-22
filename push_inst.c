#include "monty.h"

/**
 * push_inst - Handles the push instruction
 * @new_stack: new node to add to stack
 * @line_number: Line number in bytecode
 *
 * Return: Void (Nothing)
 */
void push_inst(stack_t **new_stack,
	       __attribute__((unused)) unsigned int line_number)
{
	stack_t *new = *new_stack;

	if (!new)
		exit(EXIT_SUCCESS);
	new->prev = NULL;
	new->next = main_stack;
	if (main_stack)
		main_stack->prev = new;
	main_stack = *new_stack;
}
