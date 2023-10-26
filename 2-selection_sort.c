#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 *  order using the Selection sort algorithm
 *
 * @p_array: data to sort
 * @s: size of data
 *
 * Return: No Return
 */
void selection_sort(int *p_array, size_t s)
{
	size_t i, n, p;
	int m, swap = 0;

	if (s < 2)
		return;

	for (i = 0; i < s; i++)
	{
		m = p_array[i];
		p = i;

		for (n = i + 1; n < s; n++)
		{
			if (p_array[n] < m)
			{
				m = p_array[n];
				p = n;
				swap = 1;
			}

		}
		p_array[p] = p_array[i];
		p_array[i] = m;
		if (swap)
			print_array(p_array, s), swap = 0;
	}
}
