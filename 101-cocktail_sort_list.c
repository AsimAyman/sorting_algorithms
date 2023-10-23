#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @n: node base to change
 * @l: double link list head
 *
 * Return: No Return
 */
void _swap(listint_t **n, listint_t **l)
{
	listint_t *tmp = *n, *tmp2, *tmp3;


	if (!(*n)->prev)
		*l = (*n)->next;

	tmp = tmp3 = *n;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*n = tmp2;

}
/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 *
 * @l: head of list to be sortered (Double Linked List)
 *
 * Return: No Return
 */
void cocktail_sort_list(listint_t **l)
{
	listint_t *head, *aux;
	int c = 0, n = -1, m = -1;

	if (!l || !(*l) || (!((*l)->prev) && !((*l)->next)))
		return;

	head = *l;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       _swap(&aux, l);
			       print_list(*l);
			       head = aux;
			}

			c++;
			head = head->next;
		}

		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				_swap(&aux, l);
				print_list(*l);
				head = aux->next;
			}
			c--;
			head = head->prev;
		}
	}
}
