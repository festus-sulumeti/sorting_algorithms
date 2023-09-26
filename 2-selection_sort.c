#include "sort.h"

/**
* swap_m - swaps two integers
* @a: integer number one
* @b: integer number two
*
* Return: void
*/

void swap_m(int *a, int *b)
{
int e_mp;

e_mp = *a;
*a = *b;
*b = e_mp;
}

/**
* selection_sort - sorts an array of integers in an ascending order
*                  in the program using the Selection sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/

void selection_sort(int *array, size_t size)
{
unsigned int i = 0, min, j;

if (array == NULL || size < 2)
return;

do {
min = i;
j = i + 1;

do {
if (array[j] < array[min])
min = j;
j++;
} while (j < size);

if (min != i)
{
swap_m(&array[min], &array[i]);
print_array(array, size);
}
i++;
} while (i < size - 1);
}
