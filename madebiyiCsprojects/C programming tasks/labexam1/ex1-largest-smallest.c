//Author: Michael Adebiyi
//Date: 6/10/2022
//Description: this code takes in a line of input from the command line, input starts with either "smallest" or "largest", this determines what function will be executed to get a desired output

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//initialising findMax and min functions
float findMax(float inputnumbers[], int length);
float min(float inputnumbers[], int length);

/*
Function: Main
Parameters: command line arguments
returns: int
*/

//Main function
int main(int argc, char* argv[]){
//initialising variables
    float max, smallest;
    int length = argc - 2;//excludes command "largest" or "smallest"
    float inputnumbers[length];

    for(int i = 0; i < length; i++ ){
        inputnumbers[i] = atof(argv[i + 2]); //takes in arguments from command line and putd them in an array
    }

    max = findMax(inputnumbers, length);
    smallest = min(inputnumbers, length);

//comparing strings in order to determine what operation to carry out
    if(strcmp(argv[1], "smallest") == 0){
        printf("%.2f\n", min(inputnumbers, length));
    }

    else if(strcmp(argv[1], "largest") == 0){
        printf("%.2f\n", findMax(inputnumbers, length));
    }
return 0;
}

//function to find largest number
float findMax(float inputnumbers[], int length){
    int i;
    float max;
    i = 0;
    max = 0;

//for loop goes through array to compare values until largest number is found and returned
    for(int i = 0; i < length; i++){

        if(inputnumbers[i] > max){
            max = inputnumbers[i];
        }
    }
    return max;
}

//function to find smallest number
float min(float inputnumbers[], int length){
    int i;
    float smallest;
    i = 0;
    smallest = inputnumbers[1];

//for loop goes through array to compare values until smallest is found and returned
    for(int i = 0; i < length; i++){

        if(inputnumbers[i] < smallest){
            smallest = inputnumbers[i];
        }
    }
    return smallest;
}
