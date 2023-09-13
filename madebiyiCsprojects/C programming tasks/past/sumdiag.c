// Includes.

#include <stdio.h>
#include <stdlib.h>

/*
Name: anti-diagonal.c
Functions: main, sum_anti_diagonally
Parameters: int n and int array of size n.
Returns: int
Description: Takes in a matrix of size n and outputs its anti-diagonal sum.
Author: Patricija Shalkauskaite
Date: 11-11-2021
*/

// Initialising function(s).
void sum_anti_diagonally(int *array, int n, int length);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int n = atoi(argv[1]);  // n tells us the size of the matrix.
    int length = argc - 2;  // It's - 2 to not count the program name and n.
    int nums[length];

    for(int i = 0; i < length; ++i)  // Creating integer array.
    {
        nums[i] = atoi(argv[i + 2]);
    }

    sum_anti_diagonally(nums, n, length);

    return(0);
}   // End of main function.

// Building initialised function.
void sum_anti_diagonally(int *array, int n, int length)
{
    // Defining variables.
    int sum = 0;

    /* Initialise i to be the first anti-diagonal element.
       It's length - 1 to avoid summing the last element (which wouldn't be an anti-diagonal element). */
    for(int i = (n - 1); i < length - 1;)
    {
        sum += array[i];
        i += n - 1;  // This is the pattern to get a matrix's anti-diagonal elements.
    }

    printf("%d\n", sum);
}
