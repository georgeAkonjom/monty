#include "monty.h"

/**
 * pint_inst - Handles the pint instruction
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the bytecode
 *
 * Description: Prints the value at the top of the stack without removing it.
 *
 * Return: Void
 */
void pint_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *top = main_stack;

	if (stack && *stack)
		pexit(EXIT_FAILURE);
	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		pexit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}
