#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data from one buffer to another
 *
 * @p_s: source buffer
 * @dst: destination buffer
 * @s: size of buffers
 *
 * Return: No Return
 */
void copy(int *p_s, int *dst, int s)
{
	int i;

	for (i = 0; i < s; i++)
		dst[i] = p_s[i];
}
/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @p_array: first set of data
 * @p_buff: second set of data
 * @p_minL: lower range of first set of data
 * @p_maxL: upper range of first set of data
 * @p_minR: lower range of second set of data
 * @p_maxR: upper range of second set of data
 *
 * Return: No Return
 */
void merge(int *p_array, int *p_buff, int p_minL, int p_maxL, int p_minR, int p_maxR)
{
	int i = p_minL, j = p_minR, k = p_minL;

	while (i <= p_maxL || j <= p_maxR)

		if (i <= p_maxL && j <= p_maxR)
			if (p_buff[i] <= p_buff[j])
				p_array[k] = p_buff[i], k++, i++;
			else
				p_array[k] = p_buff[j], k++, j++;

		else if (i > p_maxL && j <= p_maxR)
			p_array[k] = p_buff[j], k++, j++;
		else
			p_array[k] = p_buff[i], k++, i++;
}
/**
 * printcheck - prints an array in a given range
 *
 * @p_array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 *
 * Return: No Return
 */
void printcheck(int *p_array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", p_array[i]);
	}
	printf("\n");
}
/**
 * split - recursive function to split data into merge tree
 *
 * @p_array: array of data to be split
 * @p_buff: auxiliary array of data for merging
 * @p_min: min range of data in array
 * @p_max: max range of data in array
 * @p_size: size of total data
 *
 * Return: No Return
 */
void split(int *p_array, int *p_buff, int p_min, int p_max, int p_size)
{
	int v_mid, v_tmax, v_minL, v_maxL, v_minR, v_maxR;

	if ((max - min) <= 0)
		return;

	v_mid = (max + min + 1) / 2;
	v_tmax = max;
	max = v_mid - 1;

	v_minL = min;
	v_maxL = max;

	split(array, buff, min, max, size);

	min = v_mid;
	max = v_tmax;

	v_minR = min;
	v_maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, v_minL, v_maxL);

	printf("[right]: ");

	printcheck(array, v_minR, v_maxR);
	merge(array, buff, v_minL, v_maxL, v_minR, v_maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, v_minL, v_maxR);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @p_array: array of data to be sorted
 * @s: size of data
 *
 * Return: No Return
 */
void merge_sort(int *p_array, size_t s)
{
	int *buff;

	if (s < 2)
		return;

	buff = malloc(sizeof(int) * s);
	if (buff == NULL)
		return;

	copy(p_array, buff, s);

	split(p_array, buff, 0, s - 1, s);

	free(buff);
}
