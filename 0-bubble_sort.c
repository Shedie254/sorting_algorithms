#include "sort.h"
/**
 * bubble_sort - perform a bubble sort on the input array
 * @size: size of the array 
 * @array: pointer to the input array
 */
void bubble_sort(int *array, size_t size)
{
    size_t step, i;
    int temp;
    for (step = 0; step < size - 1; ++step)
    {
    for (i = 0; i < size - step - 1; ++i)
    {
      if (array[i] > array[i + 1])
      {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        print_array(array, size);
      }
    }
  }
}
