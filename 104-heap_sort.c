#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * Function: max_heapify
 * Description: Rearranges an array of integers to turn a binary tree into a complete binary heap.
 * Parameters:
 *   @array: An array of integers representing a binary tree.
 *   @size: The number of elements in the array/tree.
 *   @base: The index of the base row of the tree.
 *   @root: The root node of the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * Function: heap_sort
 * Description: Sorts an array of integers in ascending order using the heap sort algorithm.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *
 * Details: This implementation uses the sift-down heap sort algorithm and prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
