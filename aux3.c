#include "monty.h"

/**
 * _sub - subtracts one node from another
 * @stack: stack to subtract from
 * @line_number: number of line for error message
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *lec;
	int diff;

	lec = *stack;
	if (!(*stack)->next || !(*stack)->next->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = lec->next->n - lec->n;
	lec = lec->next;
	_pop(stack, line_number);
	lec->n = diff;
}

/**
 * _div - divides one node from another
 * @stack: stack to subtract from
 * @line_number: number of line for error message
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *lec;
	int quot;

	lec = *stack;
	if (!(*stack)->next || !(*stack)->next->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	quot = lec->next->n / lec->n;
	lec = lec->next;
	_pop(stack, line_number);
	lec->n = quot;
}

/**
 * _mul - multiplies one node with another
 * @stack: stack to subtract from
 * @line_number: number of line for error message
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *lec;
	int prod;

	lec = *stack;
	if (!(*stack)->next || !(*stack)->next->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	prod = lec->next->n / lec->n;
	lec = lec->next;
	_pop(stack, line_number);
	lec->n = prod;
}
