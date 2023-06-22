#include "monty.h"

/**
 * pall_inst - Handles the pall instruction
 * @new_stack: new node that should be null
 * @line_number: Line number of bytecode
 *
 * Return: Void (Nothing)
 */
void pall_inst(stack_t **new_stack,
	       __attribute__((unused)) unsigned int line_number)
{
	stack_t *h = main_stack;

	if (new_stack && *new_stack)
		pexit(EXIT_FAILURE);
	while (h)
	{
		printf("%i\n", h->n);
		h = h->next;
	}
}
