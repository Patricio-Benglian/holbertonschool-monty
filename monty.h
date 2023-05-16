#ifndef MONTY_H
#define MONTY_H

#define DELIM " \t\n\a\r"

/* Libraries */
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h> /* isdigit */

/* Global Variables */
char *nodeValue;

/* Structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
char **gettoken(stack_t **stack);
int main(int argc, char **argv);
void arg_get(char *file);
void (*get_func(char *arg))(stack_t **stack, unsigned int line_number);
int _isdigit(char stringNum[]);
void free_list(stack_t *head);

/* Error Prototypes */
void mallocErr(void);
void openErr(char *file);
void funcErr(unsigned int l_n, stack_t *h, char *text, char *opc, FILE *fd);
void pushErr(unsigned int line_number, stack_t *head, char *text, FILE *fd);

#endif