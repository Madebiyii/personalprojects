//Author: Michael Adebiyi
//Date: 3/11/2022

/*Description: This code takes in an array of unsorted integers then passes the integers to the "sorted" function which sorts the integers in ascending order.
Once the array is sorted the sorted integers are passed to the "twomedian" function which divides the sorted array by 2 and prints out the postion of the two middle numbers*/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void Sorted(int inputnumbers[], int length); //initialisng "sorted" function
void twomedian(int inputnumbers[], int length);//initialsiing "twomedian" function

int main(int argc, char* argv[]){
    int length = argc - 1; //declaring length of command line
    int inputnumbers[length];

    for(int i = 0; i < length; ++i){
        inputnumbers[i] = atoi(argv[i + 1]);//taking in input from command line
    }
//calling functions
Sorted(inputnumbers, length);
twomedian(inputnumbers, length);


return 0;
}

//sorted function uses a for loop to go through array of numbers using temp variable to sort numbers in ascending order
void Sorted(int inputnumbers[], int length){
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(inputnumbers[i] > inputnumbers[j]){
                int temp = inputnumbers[i];
                inputnumbers[i] = inputnumbers[j];
                inputnumbers[j] = temp;
            }
        }
    }
}

//twomedian functions halves the list in order to find the two middle numbers and outputs them
void twomedian(int inputnumbers[], int length){
    int mid = length/2;

        printf("%d\n", inputnumbers[mid - 1]);
        printf("%d\n", inputnumbers[mid]);
}
