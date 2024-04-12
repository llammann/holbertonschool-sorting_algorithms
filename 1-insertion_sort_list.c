#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order using the Insertion sort algorithm
*@list: Pointer to the head of the list
*/

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    listint_t *prev_node;

    while (current != NULL)
    {
        prev_node = current->prev;
        while (prev_node != NULL && prev_node->n > current->n)
        {
            if (prev_node->prev)
                prev_node->prev->next = current;
            if (current->next)
                current->next->prev = prev_node;

            prev_node->next = current->next;
            current->prev = prev_node->prev;
            prev_node->prev = current;
            current->next = prev_node;

            if (!current->prev)
                *list = current;
            print_list(*list);
            prev_node = current->prev;
        }
        current = current->next;
    }
}
