// Includes.
#include <stdio.h>
#include <stdlib.h>

/*
Name: median.c
Functions: main, bubble_sort, print_median.
Parameters: Array of integers.
Returns: int.
Description: Reads in an array of integers and outputs its median (two center values).
Author: Patricija Shalkauskaite
Date: 11-11-2021
*/

// Initialising function(s).
void bubble_sort(int *array, int length);
void print_median(int *array, int length);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 1; // It's - 1 so the program name isn't included.
    int nums[length];

    for(int i = 0; i < length; ++i)  // Creating the array of numbers.
    {
        nums[i] = atoi(argv[i + 1]);
    }

    bubble_sort(nums, length);
    print_median(nums, length);


    return(0);
}   // End of main function.

// Building initialised functions.
void bubble_sort(int *array, int length)  // Bubble sort will rearrange the array passed so that it's sorted.
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = i + 1; j < length; ++j)  // This way, if i = 0, then j = 1 etc.
        {
            if(array[i] > array[j])  // If the element on the left is bigger than the right, swap them.
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp; 
            }
        }
    }
}

void print_median(int *array, int length)  // This will find and print the median element as well as the element before it.
{
    int median = length / 2;
    printf("%d\n", array[median - 1]);
    printf("%d\n", array[median]);
}
