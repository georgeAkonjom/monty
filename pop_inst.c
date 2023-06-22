#include "monty.h"

/**
 * pop_inst - Removes the top element of the stack
 * @stack: Possible new node that should be NULL
 * @line_number: Line number
 *
 * Return: Void (Nothing)
 */
void pop_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *old;

	if (stack && *stack)
		pexit(EXIT_FAILURE);
	if (!main_stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		pexit(EXIT_FAILURE);
	}
	old = main_stack;
	main_stack = main_stack->next;
	main_stack->prev = NULL;
	free(old);
}
