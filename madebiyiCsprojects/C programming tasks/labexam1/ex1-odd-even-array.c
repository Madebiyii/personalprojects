//Author: Michael Adebiyi
//Date: 6/10/2022

/*Description: This code takes in integers from the command line as input.
Sum of all odds is calculated, all evens are taken away from the first even number.
The sum of all odd numbers and the result of taking away all evens from the first evens ae outputed*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//initialising odddevenarray function
int oddevenarray(int inputnumber[], int length);

int main(int argc, char *argv[]){

    int length = argc -1;
    int inputnumbers[length];

    for(int i = 0; i < length; ++i){
        inputnumbers[i] = atoi(argv[i + 1]); // inputs taken in from command line
    }

    oddevenarray(inputnumbers, length);
return 0;
}

//function takes in each number in array and determines if it is odd or even and then sums or subtracts depending on that
int oddevenarray(int inputnumber[], int length){
    int i, oddnums, evennums, checker;
    oddnums = 0;
    evennums = 0;
    checker = 0;

//chechks all integers in array
    for(int i = 0; i < length; ++i){
        if(inputnumber[i] % 2 == 0){

            if(checker == 0){
                evennums = evennums + inputnumber[i];
                checker = 1;
                continue;
            }
            evennums = evennums - inputnumber[i];
        }
        else{
            oddnums = oddnums + inputnumber[i];
        }
    }
    printf("%d\n%d\n", oddnums, evennums); //outputs results
}
