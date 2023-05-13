#include "monty.h"

/**
 * _add - adds two nodes
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *lec;
	int sum;

	lec = *stack;
	if (!(*stack)->next || !(*stack)->next->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = lec->next->n + lec->n;
	lec = lec->next;
	_pop(stack, line_number);
	lec->n = sum;
}

/**
 * _nop - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
