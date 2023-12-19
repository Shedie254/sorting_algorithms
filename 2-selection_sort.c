#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                   the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description:
 * This function sorts the given array using the selection sort algorithm.
 * It iterates through the array, finds the minimum element, and swaps it
 * with the element at the current position. The process is repeated until
 * the entire array is sorted.
 *
 * Each time two elements are swapped, the function prints the updated array.
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
    int temp = 0;
    size_t i = 0, j = 0, min_index = 0;

    if (array == NULL || size == 0)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (min_index != i)
        {
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
            print_array(array, size);
        }
    }
}

