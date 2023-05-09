#include "monty.h"

/**
 * gettoken - recieves input and
 * @stack: stack pointer so it can free when exiting
 * Return: tokenized array of arguments
 */

char **gettoken(stack_t **stack)
{
    char *input = NULL; /* recieved input */
    char **args = NULL; /* tokenized input */
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1)
    {
        free(input);
        free(stack);
        exit(0);
    }
    args = malloc(sizeof(char *) * 2);    /* allocate memory for both arguments */
    args[0] = strtok(input, " \t\r\a\n"); /* set first argument */
    args[1] = strtok(NULL, " \t\r\a\n");  /* set second argument */
    args[2] = NULL;

    free(input);
    return (args);
}

/**
 * main - recieves input, tokenizes, then executes respective function
 * Return: Always 1.
 */
int main(void)
{
    char **args = NULL; /* tokenized input received*/
    stack_t **stack;
    unsigned int line_number; /* maybe these are extern? */
    int i = 0;                /* iterator */
    instruction_t ops[] = {
        {"push", _push},
        {"pall", _pall},
        {NULL, NULL},
    }; /* array of struct type instruction_t */

    while (1)
    {
        i = 0;
        args = gettoken(stack); /* getline and tokenizes */
        while (ops[i].opcode)
        {
            if (!strcmp(args[0], ops[i].opcode))
            {
                ops[i].f(stack, line_number); /* atoi to conv to int */
                break;
            }
            i++;
        }
    }
    return (0);
}