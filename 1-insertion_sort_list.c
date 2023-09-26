#include "sort.h"
#include <stdio.h>

/**
* backwards_in_swapping - swaps backwards
* @n: node to swap
*
* Return: void
*/

void backwards_in_swapping(listint_t *n)
{
listint_t *back, *front;

while (n->prev != NULL && n->n < n->prev->n)
{
back = n->prev->prev;
n->prev->next = n->next;
n ->next = n->prev;
n->prev->prev = n;
n->prev = back;
if (back != NULL)
back->next = n;
front = n;
while (front->prev != NULL)
front = front->prev;
print_list(front);
}   
}

/**
* forwards_in_swapping - swaps forwards
* @n: node to swap
*
* Return: void
*/
void forwards_in_swapping(listint_t *n)
{
listint_t *back, *front;  

back = n->prev;

if (back != NULL && back->n > n->n)
{
back->next = n->next;
n->next->prev = back;
n->prev = n->next;
n->next = back;
n->prev->next = n;

front = n;
while (front->prev != NULL)
front = front->prev;
print_list(front);

backwards_in_swapping(n->prev);
}
}

/**
* insertion_sort_list - sorts a doubly linked list of integers
*                       in ascending order using the Insertion sort algorithm
* @list: doubly linked list to sort
*
* Return: void
*/ 

void insertion_sort_list(listint_t **list)
{
listint_t *n, *back, *front;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

n = (*list)->next;

while (n != NULL)
{
back = n->prev;
if (back != NULL && back->n > n->n)
{
back->next = n->next;
if (n->next != NULL)
n->next->prev = back;
n->prev = n->next;
n->next = back;
n->prev->next = n;

front = n;
while (front->prev != NULL)
front = front->prev;
print_list(front);

backwards_in_swapping(n->prev);
}
else
forwards_in_swapping(n);
n = n->next;
}
