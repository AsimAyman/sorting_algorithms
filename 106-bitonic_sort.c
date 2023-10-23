#include "sort.h"
#include <stdio.h>

/**
 * printcheck - print a range
 * @p_array: The array to print
 * @r1: Less range
 * @r2: Final range
 * Return: Nothing
 */
void printcheck(int *p_array, int r1, int r2)
{
	int j;

	for (j = r1; j <= r2; j++)
	{
		if (j > r1)
			printf(", ");
		printf("%d", p_array[j]);
	}
	printf("\n");
}
/**
 * _swap - swap two elements in an array
 * @p_array: THe array to change the values
 * @m: A index
 * @n: Another index
 * @d: Direction of the array
 * Return: Nothing
 */
void _swap(int *p_array, int m, int n, int d)
{
	int tmp;

	if (d == (p_array[m] > p_array[n]))
	{
		tmp = p_array[m];
		p_array[m] = p_array[n];
		p_array[n] = tmp;
	}
}
/**
 * bitonic_merge - swap the elements to sort
 * @p_array: Array to sort
 * @l: The low element in the range to sort
 * @s: The size of the range to sort
 * @dir: Indicate which half are manage
 * @r_si: The size of the all array
 * Return: Nothing
 */
void bitonic_merge(int *p_array, int l, int s, int dir, const int r_si)
{
	int kk = s, p_i = l;

	if (s > 1)
	{
		kk = s / 2;

		for (p_i = l; p_i < l + kk; p_i++)
			_swap(p_array, p_i, p_i + kk, dir);

		bitonic_merge(p_array, l, kk, dir, r_si);
		bitonic_merge(p_array, l + kk, kk, dir, r_si);
	}
}
/**
 * _sort - segmentate the array
 * @arr: The array to sort
 * @l: The lowest element in each range
 * @s: Size of the range to sort
 * @d: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */
void _sort(int *arr, int l, int s, int d, const int r_size)
{
	int k = s;

	if (s > 1)
	{
		if (d == 1)
			printf("Merging [%d/%d] (UP):\n", s, r_size);
		if (d == 0)
			printf("Merging [%d/%d] (DOWN):\n", s, r_size);
		printcheck(arr, l, l + k - 1);

		k = s / 2;
		_sort(arr, l, k, 1, r_size);

		_sort(arr, l + k, k, 0, r_size);

		bitonic_merge(arr, l, s, d, r_size);
		if (d == 1)
		{
			printf("Result [%d/%d] (UP):\n", s, r_size);
			printcheck(arr, l, l + 2 * k - 1);
		}
		if (d == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", s, r_size);
			printcheck(arr, l, l + 2 * k - 1);
		}
	}
}
/**
 * bitonic_sort - call the sort function
 * @p_arr: The array to sort
 * @p_s: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *p_arr, size_t p_s)
{
	int up = 1;
	const int r_size = (int)p_s;

	if (p_s < 2 || !p_arr)
		return;

	_sort(p_arr, 0, (int)p_s, up, r_size);
}
