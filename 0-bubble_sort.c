#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 *
 * @p_array: data to sort
 * @p_size: size of data
 *
 * Return: No Return
 */
void bubble_sort(int *p_array, size_t p_size)
{
	size_t i, j, tmp;

	if (p_size < 2)
		return;

	for (i = 0; i <= p_size - 1; i++)
	{
		for (j = 0; j <= p_size - 2; j++)
		{
			if (p_array[j] > p_array[j + 1])
			{
				tmp = p_array[j];
				p_array[j] = p_array[j + 1];
				p_array[j + 1] = tmp;
				print_array(p_array, p_size);
			}
		}
	}
}
