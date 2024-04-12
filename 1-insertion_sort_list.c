#include "sort.h"

/**
*insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order using the Insertion sort algorithm
*@list: Pointer to the head of the doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *insertion_point = current->prev;
        listint_t *next_node = current->next;

        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            insertion_point = insertion_point->prev;
        }

        if (insertion_point == NULL)
        {
            if (current->prev != NULL)
                current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev = NULL;
            current->next = *list;

            if (*list != NULL)
                (*list)->prev = current;

            *list = current;
        }
        else
        {
            if (current->prev != NULL)
                current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev = insertion_point;

            if (insertion_point->next != NULL)
                insertion_point->next->prev = current;

            current->next = insertion_point->next;
            insertion_point->next = current;
        }

        current = next_node;
        print_list(*list);
    }
}
