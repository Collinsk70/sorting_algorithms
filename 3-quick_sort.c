#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * Function: swap_ints
 * Description: Swaps the positions of two integers within an array.
 * Parameters:
 *   @a: A pointer to the first integer to be swapped.
 *   @b: A pointer to the second integer to be swapped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Function: lomuto_partition
 * Description: Orders a subset of an array of integers according to the Lomuto partition scheme
 *              with the last element as the pivot.
 * Parameters:
 *   @array: The array of integers.
 *   @size: The number of elements in the array.
 *   @left: The starting index of the subset to be ordered.
 *   @right: The ending index of the subset to be ordered.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * Function: lomuto_sort
 * Description: Implements the quicksort algorithm through recursion to sort an array of integers.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *   @left: The starting index of the array partition to be ordered.
 *   @right: The ending index of the array partition to be ordered.
 *
 * Details: This implementation uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * Function: quick_sort
 * Description: Sorts an array of integers in ascending order using the quicksort algorithm.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *
 * Details: This implementation uses the Lomuto partition scheme and prints the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
