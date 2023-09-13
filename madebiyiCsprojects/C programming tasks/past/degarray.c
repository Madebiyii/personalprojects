// Includes.
#include <stdio.h>
#include <stdlib.h>

/*
Name: degree-array.c
Functions: main, find_count.
Parameters: Array of integers.
Returns: int.
Description: Reads in an array of integers and outputs the highest count of an element within the array.
Author: Patricija Shalkauskaite
Date: 11-11-2021
*/

// Initialising function(s).
int find_count(int *array, int length);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 1; // It's - 1 so the program name isn't counted.
    int nums[length];

    for(int i = 0; i < length; ++i)  // Creating the array of ints.
    {
        nums[i] = atoi(argv[i + 1]);  // It's + 1 so the program name isn't included.
    }

    printf("%d\n", find_count(nums, length));

    return(0);
}

int find_count(int *array, int length)
{
    int count = 0;
    int biggest_count = 0;

    for(int i = 0; i < length; ++i)
    {   
        /* Making count go back to 1 inside the loop so the count of numbers don't sum up altogether.
           We also add one to it so it counts the element itself we're checking.*/
        count = 1;
        for(int j = 0; j < length; ++j)
        {   
            /* If the number is the same as the one we're comparing it to
               and the number isn't being compared to itself. */
            if(array[j] == array[i] && i != j)
            {
                count += 1;
            }
        }
        
        if(count > biggest_count)  // Checking if the current count is bigger than the biggest count so far.
        {
            biggest_count = count;
        }
    }

    return biggest_count;
}
