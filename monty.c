#include "monty.h"

stack_t *main_stack = NULL;

/**
 * main - Entry point
 * @argc: Number of progam arguments
 * @argv: List of program arguments
 *
 * Return: EXIT_SUCCESS on success
 * EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *bfile = NULL;
	char comline[256], *comvec[256], *delim = " \t\n";
	size_t vec_iter = 0, line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE %s file\n", argv[0]);
		pexit(EXIT_FAILURE);
	}

	bfile = fopen(argv[1], "r");
	if (!bfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		pexit(EXIT_FAILURE);
	}
	file_getset(bfile);
	while (fgets(comline, sizeof(comline), bfile))
	{
		comvec[0] = strtok(comline, delim);
		for (vec_iter = 1; comvec[vec_iter - 1] != NULL; vec_iter++)
			comvec[vec_iter] = strtok(NULL, delim);
		line_num++;
		if (comvec[0])
			com_handle(comvec, line_num);
	}

	pexit(EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
}


/**
 * com_handle - Handles every line of instruction
 * @comvec: Tokenized instruction line
 * @line_num: Line number
 *
 * Return: Void (Nothing)
 */
void com_handle(char **comvec, unsigned int line_num)
{
	unsigned int iter;
	stack_t *new_stack;
	int val;
	instruction_t all_com[] = {{"push", push_inst}, {"pall", pall_inst},
				   {"pint", pint_inst}, {"swap", swap_inst}, {"nop", nop_inst}};

	for (iter = 0; iter < sizeof(all_com) / sizeof(instruction_t); iter++)
		if (!strcmp(all_com[iter].opcode, comvec[0]))
		{
			if (!comvec[1])
				new_stack = NULL;
			else
			{
				new_stack = malloc(sizeof(*new_stack));
				if (!new_stack)
				{
					fprintf(stderr,
						"Error: malloc failed\n");
					pexit(EXIT_FAILURE);
				}
				val = atoi(comvec[1]);
				if (!val && *(comvec[1]) != '0')
				{
					fprintf(stderr,
						"L%i: usage: push integer\n",
						line_num);
					pexit(EXIT_FAILURE);
				}
				new_stack->n = val;
				new_stack->prev = NULL;
				new_stack->next = NULL;
			}
			all_com[iter].f(&new_stack, line_num);
			return;
		}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_num, comvec[0]);
	pexit(EXIT_FAILURE);
}

/**
 * file_getset - Stores file stream for closing
 * @f: file stream
 *
 * Return: File stream, if it exists
 */
FILE *file_getset(FILE *f)
{
	static FILE *stuck;

	if (f)
		stuck = f;
	return (stuck);
}

/**
 * pexit - Frees all allocated resources before calling exit
 * @status: Exit status
 *
 * Return: Void (Nothing)
 */
void pexit(int status)
{
	stack_t *curr, *head = main_stack;
	FILE *f;

	while (head)
	{
		curr = head->next;
		free(head);
		head = curr;
	}
	f = file_getset(NULL);
	if (f)
		fclose(f);
	exit(status);
}
