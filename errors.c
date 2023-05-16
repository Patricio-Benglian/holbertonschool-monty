#include "monty.h"

/**
 * free_list - frees list
 * @head: pointer to head node
 */
void free_list(stack_t *head)
{
	if (head->next)
	{
		free_list(head->next);
	}
	free(head);
}

/**
 * mallocErr - handles malloc exit case
 */
void mallocErr(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * openErr - handles open failure exit case
 * @file: file which failed to open
 */
void openErr(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * funcErr - handles function parse exit case
 * @l_n: line which failed
 * @h: stack to be freed
 * @text: file input buffer to be freed
 * @opc: opcode
 * @fd: file descriptor that was opened
 */
void funcErr(unsigned int l_n, stack_t *h, char *text, char *opc, FILE *fd)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", l_n, opc);
	free_list(h);
	free(text);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * pushErr - handles push function exit case
 * @line_number: line which failed
 * @head: stack to be freed
 * @text: file input buffer to be freed
 * @fd: file descriptor that was opened
 */
void pushErr(unsigned int line_number, stack_t *head, char *text, FILE *fd)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_list(head);
	free(text);
	fclose(fd);
	exit(EXIT_FAILURE);
}
