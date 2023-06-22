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
		exit(EXIT_FAILURE);
	}

	bfile = fopen(argv[1], "r");
	if (!bfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(comline, sizeof(comline), bfile))
	{
		comvec[0] = strtok(comline, delim);
		for (vec_iter = 1; comvec[vec_iter - 1] != NULL; vec_iter++)
			comvec[vec_iter] = strtok(NULL, delim);
		line_num++;
		com_handle(comvec, line_num);
	}

	exit (EXIT_SUCCESS);
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
	instruction_t all_com[] = {{"push", push_inst}, {"pall", pall_inst}};

	if (!comvec[1])
		new_stack = NULL;
	else
	{
		new_stack = malloc(sizeof(*new_stack));
		if (!new_stack)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}

		val = atoi(comvec[1]);
		if (!val && *(comvec[1]) != '0')
		{
			exit(EXIT_FAILURE);
		}
		new_stack->n = val;
		new_stack->prev = NULL;
		new_stack->next = NULL;
	}

	for (iter = 0; iter < sizeof(all_com) / sizeof(instruction_t); iter++)
		if (!strcmp(all_com[iter].opcode, comvec[0]))
			all_com[iter].f(&new_stack, line_num);
}
