#include "sort.h"
#include <stdio.h>

/**
* bubble_sort - sorts an array of integers in an ascending order
*               in the program using the Bubble sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/

void bubble_sort(int *array, size_t size)
{
size_t i = 0, j, flagging, e_mp;

if (array == NULL || size == 0)
return;

do {
flagging = 0;
j = 0;

do {
if (array[j] > array[j + 1])
{
e_mp = array[j];
array[j] = array[j + 1];
array[j + 1] = e_mp;
flagging = 1;
print_array(array, size);
}
j++;
} while (j < size - i - 1);

i++;

} while (flagging);
}
