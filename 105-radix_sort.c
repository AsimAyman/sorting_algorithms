#include <stdlib.h>
#include "sort.h"
/**
 * csort2 - auxiliary function of radix sort
 *
 * @p_array: array of data to be sorted
 * @b: malloc buffer
 * @s: size of data
 * @l: Less significant digit
 *
 * Return: No Return
 */
void csort2(int *p_array, int **b, int s, int l)
{
	int i, j, csize = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < s; i++)
	{
		num = p_array[i];
		for (j = 0; j < l; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		b[num][carr[num]] = p_array[i];
		carr[num] += 1;
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (carr[i] > 0)
		{
			p_array[j] = b[i][carr2[i]];
			carr2[i] += 1, carr[i] -= 1;
			j++;
		}
	}

	print_array(p_array, s);
}
/**
 * csort - auxiliary function of radix sort
 *
 * @p_array: array of data to be sorted
 * @p_size: size of data
 * @p_lsd: Less significant digit
 *
 * Return: No Return
 */
void csort(int *p_array, int p_size, int p_lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int m, jk, num, csize = 10, **bf;

	for (m = 0; m < p_size; m++)
	{
		num = p_array[m];
		for (jk = 0; jk < p_lsd; jk++)
			if (jk > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == p_size)
		return;

	bf = malloc(sizeof(int *) * 10);
	if (!bf)
		return;

	for (m = 0; m < csize; m++)
		if (carr[m] != 0)
			bf[m] = malloc(sizeof(int) * carr[m]);


	csort2(p_array, bf, p_size, p_lsd);

	csort(p_array, p_size, p_lsd + 1);

	for (m = 0; m < csize; m++)
		if (carr[m] > 0)
			free(bf[m]);
	free(bf);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 *
 * @l_array: array of data to be sorted
 * @l_size: size of data
 *
 * Return: No Return
 */
void radix_sort(int *l_array, size_t l_size)
{
	if (l_size < 2)
		return;
	csort(l_array, l_size, 1);
}
