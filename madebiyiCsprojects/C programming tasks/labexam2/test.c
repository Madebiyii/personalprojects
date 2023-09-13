//Author: Michael Adebiyi
//Date: 03/11/2022

/*Description: This code is takes in an array of integers from the command line, the first number in the array determines the size of dimension of the matrix.
 and the following numbers are in the different dimensions of the matrix. The aim of the code is to add the numbers diagonally in the upward right direction and output the total*/

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int antidiagonalsum(int (*pMatrix)[512], int inputnumber);//declares the antidiagonalsum function

int main(int argc, char *argv[]){
    int inputnum = atoi(argv[1]);//initialises the first number which is the dimension of matrix
    int inputarray[512][512];//initialuses numbers in array

    int(*pMatrix)[512] = inputarray;//using pointer to initialise

    //using nested for loop to go through all values in all dimensions of matrix
    for (int i = 0; i < inputnum; i++)
        for (int j = 0; j < inputnum; j++)
            *(*(pMatrix + i) + j) = atoi(argv[i * inputnum + j + 2]);//using pointers to sum values

    printf("%d\n", antidiagonalsum(pMatrix, inputnum));//prints out result of "antidiagonalsum" function

    return 0;
}


int antidiagonalsum(int (*pMatrix)[512], int inputnumber){//calculates total of diagonal values

    int total = 0;
    int *pTotal = &total;
    int rownum= 0;

    //for loop goes through each row
    for (int i = inputnumber - 1; i >= 0; --i){
        *pTotal += *(*(pMatrix + rownum) + i);
        rownum++;
    }
    return *pTotal;//function returns value pointed to at "*pTotal"
}
