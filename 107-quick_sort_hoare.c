#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * Function: hoare_partition
 * Description: Orders a subset of an array of integers according to the Hoare partition scheme.
 * Parameters:
 *   @array: The array of integers.
 *   @size: The number of elements in the array.
 *   @left: The starting index of the subset to be ordered.
 *   @right: The ending index of the subset to be ordered.
 *
 * Return: The final partition index.
 *
 * Details: This implementation uses the last element of the subset as the pivot and prints
 *          the array after each swap of two elements.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * Function: hoare_sort
 * Description: Implements the quicksort algorithm through recursion to sort an array of integers.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *   @left: The starting index of the array partition to be ordered.
 *   @right: The ending index of the array partition to be ordered.
 *
 * Details: This implementation uses the Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * Function: quick_sort_hoare
 * Description: Sorts an array of integers in ascending order using the quicksort algorithm.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *
 * Details: This implementation uses the Hoare partition scheme and prints the array
 *          after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
