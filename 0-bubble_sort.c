#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */

void print_array(const int *array, size_t size)
{
size_t i;
for (i = 0; i < size; i++)
{
printf("%d", array[i]);
if (i != size - 1)
printf(", ");
}
printf("\n");
}

/**
 * bubble_sort - Sorts an array of integers in asc order using Bubble sort
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;
int swapped;
if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
swapped = 0;
for (j = 0; j < size - 1 - i; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
swapped = 1;
printf("Swap %d and %d: ", array[j], array[j + 1]);
print_array(array, size);
}
}
if (swapped == 0)
break;
}
}
