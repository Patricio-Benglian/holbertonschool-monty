#include "monty.h"

/**
 * gettoken - recieves input and
 *
 */

char **gettoken(void)
{
    char *input = NULL; /* recieved input */
    char **args = NULL; /* tokenized input */
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1)
    {
        free(input);
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
    int i = 0;          /* iterator */
    instruction_t ops[] = {
        {"push", _push},
        {"pall", _pall},
        {NULL, NULL},
    }; /* array of struct type instruction_t */

    while (1)
    {
        args = gettoken();
        while (ops[i].opcode)
        {
            if (!strcmp(args[0], ops[i].op))
            {
                ops[i].opcode; /* has to run function i guess with some args i dk not yet done */
            }
        }
    }
    return (0);
}