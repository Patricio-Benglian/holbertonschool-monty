#include "monty.h"

/**
 * _push - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _push(stack_t **stack, unsigned int line_number)
{
    int nodeNum;
    stack_t *newNode = NULL;
    /*Define un puntero a un nodo de pila, que se utilizará para crear el nuevo nodo que se agregará a la pila*/

    nodeNum = atoi(nodeValue);
    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->n = nodeNum;   /*Asignar el número al nuevo nodo*/
    newNode->next = *stack; /*Conectar el nuevo nodo al nodo superior actual*/
    newNode->prev = NULL;   /*Establecer el nuevo nodo como el nodo superior de la pila*/
    /*Si la pila ya tenía un nodo, establecer el puntero previo del nodo
    superior actual para que apunte al nuevo nodo superior*/
    if (*stack != NULL)
    {
        (*stack)->prev = newNode;
    }
    /*Establecer el puntero de pila para que apunte al nuevo nodo superior*/
    *stack = newNode;
}

/**
 * _pall - prints all values on the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _pall(stack_t **stack, unsigned int line_number)
{
    stack_t *lec = *stack;
    /* Recorremos la pila hacia el último nodo */
    while (lec != NULL) /* change to lec->next? */
    {
        if (!(lec->next))
            break;       /* Si llegamos al final de la pila, salimos del bucle */
        lec = lec->next; /* Movemos el puntero hacia el siguiente nodo */
    }
    /* Recorremos la pila de último a primer nodo */
    while (lec != NULL)
    {
        /* Si el nodo actual no es nulo, imprimimos su valor */
        if (lec->n)
            printf("%d\n", lec->n);
        else
            printf("0\n"); /* Si es nulo, imprimimos 0 */
        lec = lec->prev;   /* Movemos el puntero hacia el nodo anterior */
    }
}

/**
 * _pint - prints value at the top of the stack
 * @stack: the stack we are working in
 * @line_number: the number of the command being executed
 */

void _pint(stack_t **stack, unsigned int line_number)
{
    stack_t *lec = *stack;

    if (lec == NULL) /* Verificar si la pila está vacía */
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", lec->n); /* Imprimir el valor en la cima de la pila */
    lec = lec->next;        /* Actualizar la cima de la pila */
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
