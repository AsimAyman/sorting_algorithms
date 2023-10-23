#include "sort.h"
#include <stdio.h>
/**
 * _bigest -  Give me the largest number in a array of integers
 * @array: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _bigest(int *p_array, size_t s)
{
	size_t i;
	int k = 0;

	for (i = 0; i < s; i++)
	{
		if (k < p_array[i])
			k = p_array[i];
	}

	return (k);
}
/**
 * _memset -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int s)
{
	int *ptr = NULL;
	int j;

	ptr = malloc((s) * sizeof(int));

	for (j = 0; j < s; j++)
		ptr[j] = 0;

	return (ptr);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @p_array: The Int array
 * @s: Size of array
 * Return: The sorted list
 */
void counting_sort(int *p_array, size_t s)
{
	size_t i, j;
	int k = 0;
	int *ptr = NULL, *sort_ar = NULL;

	if (s < 2)
		return;
	/*Know the largest number in the array*/
	k = _bigest(p_array, s);
	/*Make the help array*/
	ptr = _memset(k + 1);
	if (!ptr)
		return;
	/*Set the values for sorting*/
	for (i = 0; i < s; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == p_array[i])
				ptr[j] += 1;
	/*Modificate the count in the array*/
	for (i = 0; (int)i < k; i++)
		ptr[i + 1] = ptr[i] + ptr[i + 1];
	print_array(ptr, k + 1);
	/*Create the sort array*/
	sort_ar = malloc(s * sizeof(int));
	if (!sort_ar)
	{
		free(ptr);
		return;
	}

	for (i = 0; i < s; i++)
	{
		sort_ar[ptr[p_array[i]] - 1] = p_array[i];
		ptr[p_array[i]] -= 1;
	}
	for (j = 0; j < s; j++)
		p_array[j] = sort_ar[j];

	free(sort_ar);
	free(ptr);
}
