#include "monty.h"

/**
 * _isdigit - checks if entire string is digits using isdigit
 * @stringNum: string of supposed numbers
 * Return: 1 if is digit, 0 else
 */
int _isdigit(char stringNum[])
{
	int i; /* iterator */

	if (stringNum[0] == '-')
		stringNum[0] = '0';
	for (i = 0; stringNum[i]; i++)
	{
		if (isdigit(stringNum[i]) == 0)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * get_func - finds relevant function
 * @arg: argument to compare to table
 * Return: function
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
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL},
	};

	while (ops[i].f != NULL)
	{
		if (strcmp(ops[i].opcode, arg) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	/* Error Case */
	return (NULL);
}
/**
 * arg_get - separates content of file into arguments
 * @file: file with arguments to parse
 */
void arg_get(char *file)
{
	void (*func)(stack_t **stack, unsigned int line_number) = NULL;
	char *text = NULL, *argument = NULL;
	size_t len = 0;
	FILE *fd; /* file descriptor */
	stack_t *stackNode = NULL;
	unsigned int line_number = 0;

	stackNode = malloc(sizeof(stack_t));
	if (stackNode == NULL)
		mallocErr();
	stackNode->n = 0;
	stackNode->next = NULL;
	stackNode->prev = NULL;
	fd = fopen(file, "r");
	if (!fd)
		openErr(file);
	while (getline(&text, &len, fd) != -1)
	{
		line_number++;
		argument = strtok(text, DELIM);
		if (!argument)
			continue;
		func = get_func(argument);
		if (func == NULL)
			funcErr(line_number, stackNode, text, argument, fd);
		if (func == _push)
		{
			nodeValue = strtok(NULL, DELIM);
			if (!nodeValue || _isdigit(nodeValue) == 0)
				pushErr(line_number, stackNode, text, fd);
		}
		func(&stackNode, line_number);
	}
	fclose(fd);
	free(text);
	free_list(stackNode);
	exit(EXIT_SUCCESS);
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

	if (argc == 2)
	{
		arg_get(argv[1]);
	}

	/* Error stuff */
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
