//Author: Michael Adebiyi
//Date: 6/10/2022

/*Description: this code takes in an integer as input from the command line. The integer is then passsed to the hailstone function. If the integer is even it is divided by 2,
if it is odd it is multiplied by 3 and 1 is added, this is repeated for all new values until the value is 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//initialising hailstone function
int hailstones(int num);

int main(int argc, char*argv[]){
    int num = 0;
    num = atoi(argv[1]);
    printf("%d", num);
    hailstones(num);
    return 0;
}

//hailstone funtion using a while loop to determine if input is even or odd in order to give correct output for given input
int hailstones(int num){
    while(num != 1){
        if(num % 2 != 0){
            num = num * 3 + 1;
        }
        else{
            num = num/2;
        }
        printf(" %d", num);
    }

    printf("\n");

    return 0;
}
