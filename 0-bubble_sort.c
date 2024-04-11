#include <stdio.h>
#include <stddef>
#include "sort.h"

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
for (size_t k = 0; k < size; k++)
{
printf("%d", array[k]);
if (k != size - 1)
printf(", ");
}
printf("\n");
}
}
if (swapped == 0)
break;
}
}
