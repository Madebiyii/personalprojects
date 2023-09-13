#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stringReverse(char* inputstr);

int main(int argc, char *argv[]){

    char output;
    char* inputstr = argv[1];
    output = stringReverse(inputstr);

return 0;
}

char stringReverse(char* inputstr){

    int leftindex, rightindex, length, temp;
    length = strlen(inputstr);
    leftindex = 0;
    rightindex = length - 1;

    for(int i = leftindex; i < rightindex; i++){
        temp = inputstr[i];
        inputstr[i] = inputstr[rightindex];
        inputstr[rightindex] = temp;
        rightindex--;;

    }

    printf("%s\n", inputstr);
return 0;
}
