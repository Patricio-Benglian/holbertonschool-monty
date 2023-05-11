#include "monty.h"

/**
 * free_list - frees list
 * @head: pointer to head node
 */
void free_list(stack_t *head)
{
    if (head->next)
    {
        free_list(head->next);
    }
    free(head);
}