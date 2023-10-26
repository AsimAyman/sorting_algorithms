#include "sort.h"
#include <stdio.h>

/**
 * _swap - swaps two values in an array
 *
 * @p_array: data to sort
 * @m: first value
 * @n: second value
 * @s: size of data
 *
 * Return: No Return
 */
void _swap(int *p_array, int m, int n, int s)
{
	int t;

	if (p_array[m] != p_array[n])
	{
		t = p_array[m];
		p_array[m] = p_array[n];
		p_array[n] = t;
		print_array(p_array, s);
	}
}

/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @p_array: data to sort
 * @mn: Left wall
 * @mx: right wall
 * @s: size of data
 *
 * Return: New Pivot
 */
int partition(int *p_array, int mn, int mx, size_t s)
{
	int i = mn, j, pivot  = p_array[mx];

	for (j = mn; j <= mx; j++)
	{
		if (p_array[j] < pivot)
		{
			_swap(p_array, i, j, s);
			i++;
		}

	}
	_swap(p_array, i, mx, s);

	return (i);
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
		quicksort(p_array, p + 1, mx, s);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @p_array: data to sort
 * @s: size of data
 *
 * Return: No Return
 */
void quick_sort(int *p_array, size_t s)
{
	if (s < 2)
		return;

	quicksort(p_array, 0, s - 1, s);
}
