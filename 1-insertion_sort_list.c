#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *prev_node;

    current = (*list)->next;

    while (current != NULL)
    {
        prev_node = current->prev;
        while (prev_node != NULL && prev_node->n > current->n)
        {
            if (prev_node->prev != NULL)
                prev_node->prev->next = current;
            if (current->next != NULL)
                current->next->prev = prev_node;
            prev_node->next = current->next;
            current->prev = prev_node->prev;
            prev_node->prev = current;
            current->next = prev_node;

            if (current->prev == NULL)
                *list = current;

            print_list(*list);

            prev_node = current->prev;
        }
        current = current->next;
    }
}
