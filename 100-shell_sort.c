#include "sort.h"
#include <stdio.h>
/**
 * _swap - swaped 2 values.
 * @p_array: the array for swap him values.
 * @p_i: First index
 * @p_j: Second index
 * Return: Nothing
 */
void _swap(int *p_array, int p_i, int p_j)
{
	int t;

	if (p_array[p_i] != p_array[p_j])
	{
		t = p_array[p_i];
		p_array[p_i] = p_array[p_j];
		p_array[p_j] = t;
	}
}

/**
 * shell_sort - sort the list and print the changes
 * @p_array: The array to sort.
 * @p_size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *p_array, size_t p_size)
{
	size_t h = 0,  i, j;

	if (p_size < 2)
		return;

	while (h <= p_size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < p_size; i++)
			for (j = i; j >= h && p_array[j] < p_array[j - h]; j -= h)
				_swap(p_array, j, j - h);
		h /= 3;
		print_array(p_array, p_size);
	}
}
