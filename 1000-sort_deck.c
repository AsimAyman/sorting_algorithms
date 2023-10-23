#include "deck.h"
/**
 * _strcmp - Compares two strings
 *
 * @str1: string 1
 * @str2: string 2
 *
 * Return: 0 if equal
 */
int _strcmp(char *str1, const char *str2)
{
	while (*str1 != '\0')
	{
		if (*str2 == '\0')
			return (*str1);
		if (*str2 > *str1)
			return (*str1 - *str2);
		if (*str1 > *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str2 != '\0')
		return (*str2);
	return (0);
}
/**
 * _swap - Swaps two nodes of doubly linked list
 *
 * @n: node base to change
 * @d: double link list head
 *
 * Return: No Return
 */
void _swap(deck_node_t **n, deck_node_t **d)
{
	deck_node_t *tm = *n, *tm2, *tmp3;

	if (!(*n)->prev)
		*d = (*n)->next;

	tm = tmp3 = *n;
	tm2 = tm->next;

	tm->next = tm2->next;
	tmp3 = tm->prev;
	tm->prev = tm2;
	tm2->next = tm;
	tm2->prev = tmp3;

	if (tm2->prev)
		tm2->prev->next = tm2;


	if (tm->next)
		tm->next->prev = tm;

	*n = tm2;
}
/**
 * CardValue - Obtains poker card Value from node
 *
 * @c_Node: node of poker card
 *
 * Return: Value between 1 and 52
 */
int CardValue(deck_node_t *c_Node)
{
	char *cardn[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			     "Jack", "Queen", "King"};
	int v, i;
	const char *cnum;

	cnum = c_Node->card->value;
	for (i = 0; i < 13;  i++)
		if (!_strcmp(cardn[i], cnum))
		{
			i++;
			break;
		}

	v = i + (c_Node->card->kind) * 13;

	return (v);
}
/**
 * sort_deck - sorts a poker cards deck
 *
 * @d: doubly linked list
 *
 * Return: No Return
 */
void sort_deck(deck_node_t **d)
{
	deck_node_t *head, *tback, *aux;

	if (!d || !(*d) || (!((*d)->prev) && !((*d)->next)))
		return;

	head = *d;
	while (head && head->next)
	{
		if (CardValue(head) > CardValue(head->next))
		{
			aux = head;

			_swap(&aux, d);
			head = aux;
			tback = aux;

			while (tback && tback->prev)
			{
				if (CardValue(tback) < CardValue(tback->prev))
				{
					aux = tback->prev;

					_swap(&(aux), d);

					tback = aux->next;
				}

				tback = tback->prev;
			}
		}
		head = head->next;
	}
}
