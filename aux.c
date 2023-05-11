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
    stack_t *read = *stack;
    /* Recorremos la pila hacia el último nodo */

    /* Recorremos la pila de último a primer nodo */
    while (read->next)
    {
        /* Si el nodo actual no es nulo, imprimimos su valor */
        printf("%d\n", read->n);
        read = read->next; /* Movemos el puntero hacia el nodo anterior */
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
    read = read->next;       /* Actualizar la cima de la pila */
}

/**
 * _pop - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _pop(stack_t **stack, unsigned int line_number)
{
}

/**
 * _swap - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _swap(stack_t **stack, unsigned int line_number)
{
}

/**
 * _add - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _add(stack_t **stack, unsigned int line_number)
{
}

/**
 * _nop - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _nop(stack_t **stack, unsigned int line_number)
{
}
