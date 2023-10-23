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
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @p_list: doubly linked list
 *
 * Return: No Return
 */
void insertion_sort_list(listint_t **p_list)
{
	listint_t  *p_head, *tback, *aux;

	if (!p_list || !(*p_list) || (!((*p_list)->prev) && !((*p_list)->next)))
		return;

	p_head = *p_list;
	while (p_head && p_head->next)
	{
		if (p_head->n > p_head->next->n)
		{
			aux = p_head;

			_swap(&aux, p_list);
			print_list(*p_list);
			p_head = aux;
			tback = aux;

			while (tback && tback->prev)
			{

				if (tback->n < tback->prev->n)
				{
					aux = tback->prev;

					_swap(&(aux), p_list);

					print_list(*p_list);
					tback = aux->next;
				}

				tback = tback->prev;
			}

		}
		p_head = p_head->next;
	}
}
