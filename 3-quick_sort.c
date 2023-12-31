#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *               using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_recursive_sort(array, 0, size - 1, size);
}

/**
 * partition - Partitions the array for quick sort.
 * @array: The array to be partitioned.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 * Return: The partition index.
 */
int partition(int *array, int low, int high, size_t size)
{
    int i = low - 1, j = low;
    int pivot = array[high], temp = 0;

    for (; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (array[i] != array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_recursive_sort - Implements the recursive part of Quick sort.
 * @array: The array to be sorted.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 */
void quick_recursive_sort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        quick_recursive_sort(array, low, pivot - 1, size);
        quick_recursive_sort(array, pivot + 1, high, size);
    }
}
