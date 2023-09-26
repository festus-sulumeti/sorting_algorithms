#include "sort.h"

/**
* swapper - rswap
* @aa: number one
* @bb: number two
*
* Return: void
*/
void swapper(int *aa, int *bb)
{
int e_mp;

e_mp = *aa;
*aa = *bb;
*bb = e_mp;
}

/**
* part- partitions the array
* @array: array to sort
* @low: low index
* @high: high index
* @size: size of the array
*
* Return: void
*/

int part(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low, j = low;

do {
if (array[j] <= pivot)
{
swapper(&array[i], &array[j]);
if (i != j)
print_array(array, size);
i++;
}
j++;
} while (j < high);

swapper(&array[i + 1], &array[high]);
if (i + 1 != j)
print_array(array, size);
return (i + 1);
}

/**
* quick_sort_recursive - sorts an array of integers in an ascending order
*             in the program using the Quick sort algorithm
* @array: array to sort
* @low: low index
* @high: high index
* @size: size of the array
*
* Return: void
*/

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pi = (low < high) ? part(array, low, high, size) : -1;

quick_sort_recursive(array, low, pi - 1, size);
quick_sort_recursive(array, pi + 1, high, size);
}

/**
* quick_sort - sorts an array of integers in an ascending order
*             in the program using the Quick sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/

void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}
