//Author: Michael Adebiyi
//Date: 6/10/2022

/*Description: This code takes a string or 2 strings as input, and passes it through the symmetric function.
This checks if reading from the right to the middle of the word is the same as reading the word from left to the middle and for in the case of 2 words if the 2 words are palindromic*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//initialises symmetric functions
char symmetric(char *word);

int main(int argc, char *argv[]){

//takes in input and passes them through function
    char *inputstr = argv[1];
    if(symmetric(inputstr) == 0){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
return 0;
}

//function to determine symmetry
char symmetric(char *word){
    int wordlength = strlen(word);
    int midlength = strlen(word) / 2;
    //checks if word or words are symmetrical, from left and right until middlepoint
    for(int i = 0; i < midlength; ++i){
        if(word[i] != word[wordlength - i - 1]){
            return 1;
        }
    }
    return 0;
}
