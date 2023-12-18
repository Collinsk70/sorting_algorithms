#include "sort.h"

/**

    Function: swap_ints
    Description: Swaps the positions of two integers within an array.
    Parameters:
    @a: The first integer to be swapped.
    @b: The second integer to be swapped.
    */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**

    Function: bubble_sort
    Description: Sorts an array of integers in ascending order using the bubble sort algorithm.
    Parameters:
    @array: An array of integers to be sorted.
    @size: The number of elements in the array.
    Details: This function prints the array after each swap operation during the sorting process.
    */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
