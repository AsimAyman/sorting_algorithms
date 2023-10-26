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
	size_t m, n, p;
	int m, s = 0;

	if (s < 2)
		return;

	for (m = 0; m < s; m++)
	{
		m = p_array[m];
		p = m;

		for (n = m + 1; n < s; n++)
		{
			if (p_array[n] < m)
			{
				m = p_array[n];
				p = n;
				s = 1;
			}

		}
		p_array[p] = p_array[m];
		p_array[m] = m;
		if (s)
			print_array(p_array, s), s = 0;
	}
}
