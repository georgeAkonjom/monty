#include "monty.h"

/**
 * swap_inst - Handles the swap instruction
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the bytecode
 *
 * Description: Swaps the top two elements of the stack.
 *
 * Return: Void
 */
void swap_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *top = main_stack;
	int temp;

	if (*stack)
		pexit(EXIT_FAILURE);
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
