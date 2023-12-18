#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * Function: bitonic_merge
 * Description: Sorts a bitonic sequence within an array of integers.
 * Parameters:
 *   @array: An array of integers.
 *   @size: The number of elements in the array.
 *   @start: The starting index of the sequence in the array to be sorted.
 *   @seq: The size of the sequence to be sorted.
 *   @flow: The direction in which to perform the sorting.
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * Function: bitonic_seq
 * Description: Converts an array of integers into a bitonic sequence.
 * Parameters:
 *   @array: An array of integers.
 *   @size: The number of elements in the array.
 *   @start: The starting index of a block of the building bitonic sequence.
 *   @seq: The size of a block of the building bitonic sequence.
 *   @flow: The direction in which to sort the bitonic sequence block.
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * Function: bitonic_sort
 * Description: Sorts an array of integers in ascending order using the bitonic sort algorithm.
 * Parameters:
 *   @array: An array of integers to be sorted.
 *   @size: The number of elements in the array.
 *
 * Details: This implementation prints the array after each swap. It is designed to work
 *          specifically for array sizes equal to powers of 2 (size = 2^k where k >= 0).
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
