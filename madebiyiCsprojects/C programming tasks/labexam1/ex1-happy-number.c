//Author: Michael Adebiyi
//Date: 6/10/2022

/*Description: This code takes an integer as input and determines if this integer is a happy number or not, using formula as checker*/


#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

//initialises happyNumber function
int happyNumber(int inputnum);

int main(int argc, char* argv[]){
    int hnum = atoi(argv[1]);

    while(hnum != 1 && hnum != 4){
        hnum = happyNumber(hnum);
    }
    if(hnum == 1){
        printf("is happy\n");
    }
    else if(hnum == 4){
        printf("not happy\n");
    }

return 0;
}

int happyNumber(int inputnum){
    int checker = 0; //used as variable to check if number is happy or not
    int total = 0;

//using while loop with happy number formula, it returns total which is passed into the while loop in the main function to check if it is happy or not
    while(inputnum > 0){
        checker = inputnum % 10;
        total += checker * checker;
        inputnum = inputnum/10;
    }
    return total;
}
