#ifndef SORT_H
#define SORT_H

#include <stddef.h>

typedef struct listint_s
{
int n;
struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);


#endif
