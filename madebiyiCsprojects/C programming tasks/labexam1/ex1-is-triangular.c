//Author: Michael Adebiyi
//Date: 6/10/2022

/*Description: This code takes an integer as input and determines if this integer is a triangular number or not*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//initialises triangular function
int triangular(int inputnum);

int main(int argc, char* argv[]){
    int inputnum = atoi(argv[1]);
    triangular(inputnum);

return 0;
}

//function determines triangular numbers
int triangular(int inputnum){
    int increments = 0;
    int i;

//checks if input is a triangular number based on the pattern for triangular numbers
    for(i = 1; increments < inputnum; ++i){
        increments += i; //incrementation so the pattern is succesful and can be checked
        if(increments == inputnum){
            break;
        }
    }

//prints if number is triangular or not
    if(increments != inputnum){
        printf("%d is not a triangular number\n", inputnum);
    }
    else{
        printf("%d is a triangular number\n", inputnum);
    }
}
