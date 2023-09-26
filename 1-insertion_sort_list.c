#include "sort.h"
#include <stdio.h>

/**
* backwards_in_swapping - swaps backwards
* @ni: node to swap
*
* Return: void
*/

void backwards_in_swapping(listint_t *ni)
{
listint_t *back, *front;

while (ni->prev != NULL && ni->n < ni->prev->n)
{
back = ni->prev->prev;
ni->prev->next = ni->next;
ni->next = ni->prev;
ni->prev->prev = ni;
ni->prev = back;
if (back != NULL)
back->next = ni;
front = ni;
while (front->prev != NULL)
front = front->prev;
print_list(front);
}
}

/**
* forwards_in_swapping - swaps forwards
* @ni: node to swap
*
* Return: void
*/
void forwards_in_swapping(listint_t *ni)
{
listint_t *back, *front;

back = ni->prev;

if (back != NULL && back->n > ni->n)
{
back->next = ni->next;
ni->next->prev = back;
ni->prev = ni->next;
ni->next = back;
ni->prev->next = ni;

front = ni;
while (front->prev != NULL)
front = front->prev;
print_list(front);

backwards_in_swapping(ni->prev);
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
listint_t *ni;

if (list == NULL || *list == NULL || ((*list)->next == NULL))
return;

ni = *list;

while (ni->next != NULL)
{



if (ni->n > ni->next->n)
forwards_in_swapping(ni);

else
ni = ni->next;
}

while ((*list)->prev != NULL)
*list = (*list)->prev;

}
