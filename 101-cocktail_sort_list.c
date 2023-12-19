#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - swaps a node with the next node in the list
 * @list_ptr: double pointer to the beginning of the list
 * @node_to_swap: node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **list_ptr, listint_t *node_to_swap)
{
    node_to_swap->next->prev = node_to_swap->prev;
    if (node_to_swap->prev)
        node_to_swap->prev->next = node_to_swap->next;
    else
        *list_ptr = node_to_swap->next;
    node_to_swap->prev = node_to_swap->next;
    node_to_swap->next = node_to_swap->next->next;
    node_to_swap->prev->next = node_to_swap;
    if (node_to_swap->next)
        node_to_swap->next->prev = node_to_swap;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list_ptr: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list_ptr)
{
    char is_swapped = 1;
    listint_t *temp_node;

    if (list_ptr == NULL || *list_ptr == NULL)
        return;
    temp_node = *list_ptr;
    while (is_swapped != 0)
    {
        is_swapped = 0;
        while (temp_node->next != NULL)
        {
            if (temp_node->next->n < temp_node->n)
            {
                swap_nodes(list_ptr, temp_node);
                is_swapped = 1;
                print_list(*list_ptr);
            }
            else
                temp_node = temp_node->next;
        }
        if (is_swapped == 0)
            break;
        is_swapped = 0;
        while (temp_node->prev != NULL)
        {
            if (temp_node->prev->n > temp_node->n)
            {
                swap_nodes(list_ptr, temp_node->prev);
                is_swapped = 1;
                print_list(*list_ptr);
            }
            else
                temp_node = temp_node->prev;
        }
    }
}

