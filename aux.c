#include "monty.h"

/**
 * _push - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _push(stack_t **stack, unsigned int line_number)
{
    int nodeNum; /* nodeValue turned into an integer */
    stack_t *newNode = NULL;
    (void)line_number;

    nodeNum = atoi(nodeValue);
    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->n = nodeNum;
    newNode->next = *stack;
    newNode->prev = NULL;

    if (*stack != NULL)
    {
        (*stack)->prev = newNode;
    }
    *stack = newNode;
}

/**
 * _pall - prints all values on the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    while (temp->next)
    {
        printf("%i\n", temp->n);
        temp = temp->next;
    }
}

/**
 * _pint - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _pint(stack_t **stack, unsigned int line_number)
{
    stack_t *read = *stack;

    if (read == NULL) /* Verificar si la pila está vacía */
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", read->n); /* Imprimir el valor en la cima de la pila */
}

/**
 * _pop - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _pop(stack_t **stack, unsigned int line_number)
{

    stack_t *lec = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    *stack = lec->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(lec);
}

/**
 * _swap - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _swap(stack_t **stack, unsigned int line_number)
{

    stack_t *lec;
    int val;

    lec = *stack;
    if (lec == NULL || lec->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    val = lec->n;
    lec->n = lec->next->n;
    lec->next->n = val;
}
