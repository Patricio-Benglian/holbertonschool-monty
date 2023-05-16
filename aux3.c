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
    if (lec == NULL || lec->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    diff = lec->next->n - lec->n;
    lec = lec->next;
    _pop(stack, line_number);
    lec->n = diff;
}