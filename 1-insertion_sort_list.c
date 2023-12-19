#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion
 *                       sort algorithm.
 * @head: Pointer to the head of the doubly linked list.
 * Return: Void.
 */
void insertion_sort_list(listint_t **head)
{
    listint_t *current = NULL, *temp = NULL;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    current = *head;
    current = current->next;
    while (current)
    {
        while (current->prev && current->n < (current->prev)->n)
        {
            temp = current;
            if (current->next)
                (current->next)->prev = temp->prev;
            (temp->prev)->next = temp->next;
            current = current->prev;
            temp->prev = current->prev;
            temp->next = current;
            if (current->prev)
                (current->prev)->next = temp;
            current->prev = temp;
            if (temp->prev == NULL)
                *head = temp;
            print_list(*head);
            current = current->prev;
        }
        current = current->next;
    }
}

