#include "monty.h"

/**
 * get_func - finds relevant function
 * @arg: argument to compare to table
 */
void (*get_func(char *arg))(stack_t **stack, unsigned int line_number)
{
	int i = 0; /* iterator */
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	while (ops[i].f)
	{
		if (!strcmp(ops[i].opcode, arg))
		{
			return (ops[i].f);
		}
	}
	/* Error Case */
	exit(EXIT_FAILURE);
}
/**
 * arg_get - separates content of file into arguments
 * @file: file with arguments to parse
 */
void arg_get(char *file)
{
	void (*func)(stack_t **stack, unsigned int line_number);
	char *text = NULL, *argument = NULL;
	size_t len = 0;
	int fd; /* file descriptor */
	stack_t *stackNode = NULL;
	unsigned int line_number = 0; /* Maybe extern */

	stackNode = malloc(sizeof(stack_t));
	if (stackNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Open file */
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", file);
	}
	/* Getline */
	while (getline(&text, &len, file) == -1)
	{
		argument = strtok(text, DELIM);
		if (!argument)
		{
			/*return or exit or something*/
		}
		line_number++;
		func = get_func(argument);
		stackNode->n = atoi(argument); /* set value of n*/
		func(&stackNode, line_number);
		argument = strtok(NULL, DELIM);
		line_number++;
	}
	free(text);
	free(argument);

	/* Error cases */
}

/**
 * main - recieves inputs, calls aux functions
 * @argc: argument count
 * @argv: argument values
 *
 * Return: Always 1
 */
int main(int argc, char **argv)
{
	/* If correct arg count, run */
	if (argc == 2)
		arg_get(argv[1]);

	/* Error stuff */
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}