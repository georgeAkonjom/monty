#include "monty.h"

/**
 * nop_inst - Handles the nop instruction
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the bytecode
 *
 * Description: Does nothing.
 *
 * Return: Void
 */
void nop_inst(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
