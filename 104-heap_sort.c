#include "sort.h"

/**
 * _swap - swaped 2 values.
 * @l_array: the array for swap him values.
 * @m: First index
 * @n: Second index
 * @r_s: The size constant for print
 * Return: Nothing
 */
void _swap(int *l_array, int m, int n, const int r_s)
{
	int tmp;
	(void) r_s;

	if (m != n)
	{
		tmp = l_array[m];
		l_array[m] = l_array[n];
		l_array[n] = tmp;
		print_array(l_array, (size_t)r_s);
	}
}

/**
 * _largest - Find the largest number btween the layers
 * @p_array: The array for sort
 * @s: The menor element
 * @i: The largest.
 * @r_s: The size for print in swap
 * Return: Nothing.
 */
void _largest(int *p_array, size_t s, int i, const int r_s)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * i) + 2;

	if (lft < (int)s && p_array[lft] > p_array[largest])
		largest = lft;

	if (rgt < (int)s && p_array[rgt] > p_array[largest])
		largest = rgt;

	if (largest != i)
	{
		_swap(p_array, i, largest, r_s);
		_largest(p_array, s, largest, r_s);
	}
}

/**
 * heap_sort - Call largest while exist layers
 * @p_array: The array that generate the layers
 * @s: Size of the array
 * Return: Nothing
 */
void heap_sort(int *p_array, size_t s)
{
	const int r_size = (const int)s;
	int i;

	if (s < 2 || !p_array)
		return;

	for (i = s / 2 - 1; i >= 0; i--)
		_largest(p_array, s, i, r_size);

	for (i = s - 1; i >= 0; i--)
	{
		_swap(p_array, 0, i, r_size);
		_largest(p_array, i, 0, r_size);
	}
}
