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
}

/**
 * main - recieves input, tokenizes, then executes respective function
 * Return: Always 1.
 */
int main(void)
{
    char **args = NULL; /* tokenized input received*/
    instruction_t ops[] = {
        {"push", _push},
        {"pall", _pall},
        {NULL, NULL},
    };

    while (1)
        args = gettoken();
}