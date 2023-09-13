#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int findMax(int inputnumbers[], int length);

int main(int argc, char* argv[]){
    int max, maxnum;
    int length = argc - 1;
    int inputnumbers[length];

    for(int i = 0; i < length; i++ ){
        inputnumbers[i] = atoi(argv[i + 1]);
    }

    maxnum = findMax(inputnumbers, length);
    printf("%d\n", maxnum);
    return 0;
}

int findMax(int inputnumbers[], int length){
    int i, max;
    i = 0;
    max = 0;

    for(int i = 0; i < length; i++){

        if(inputnumbers[i] > i){
            max = inputnumbers[i];
        }
    }
    return max;
}
