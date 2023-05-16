#include "monty.h"

/**
 * _sub - subtracts one node from another
 *
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
