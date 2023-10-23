#include "sort.h"

/**
 * _swap - swaps two values in an array
 *
 * @p_array: data to sort
 * @m: first value
 * @n: second value
 *
 * Return: No Return
 */
void _swap(int *p_array, int m, int n)
{
	int t;

	t = p_array[m];
	p_array[m] = p_array[n];
	p_array[n] = t;
}

/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @p_array: data to sort
 * @m: Left wall
 * @mx: right wall
 * @sz: size of data
 *
 * Return: New Pivot
 */
int partition(int *p_array, int m, int mx, size_t sz)
{
	int i, j, pivot = p_array[mx];

	for (i = m, j = mx; 1; i++, j--)
	{
		while (p_array[i] < pivot)
			i++;

		while (p_array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		_swap(p_array, i, j);
		print_array(p_array, sz);
	}
}

/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @p_array: data to sort
 * @mn: Left wall
 * @mx: right wall
 * @s: size of data
 *
 * Return: No Return
 */
void quicksort(int *p_array, int mn, int mx, size_t s)
{
	int p;

	if (mn < mx)
	{
		p = partition(p_array, mn, mx, s);
		quicksort(p_array, mn, p - 1, s);
		quicksort(p_array, p, mx, s);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Hoare partition scheme
 *
 * @p_array: data to sort
 * @s: size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *p_array, size_t s)
{
	if (!p_array || s < 2)
		return;

	quicksort(p_array, 0, s - 1, s);
}
