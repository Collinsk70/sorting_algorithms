#include "sort.h"

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
 * Function: selection_sort
 * Description: Sorts an array of integers in ascending order using the selection sort algorithm.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *
 * Details: This implementation prints the array after each swap operation during the sorting process.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
