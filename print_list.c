#include "sort.h"
#include <stdio.h>

/**
 * print_list - Prints a doubly linked list of integers.
 * @list: Pointer to the head of the doubly linked list.
 */
void print_list(const listint_t *list)
{
    while (list)
    {
        printf("%d", list->n);
        list = list->next;
        if (list)
            printf(", ");
    }
    printf("\n");
}

