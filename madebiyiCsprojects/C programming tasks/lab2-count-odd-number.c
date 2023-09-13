#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    int length = argc - 1;
    int numbers[length];
    int oddnums[length];
    int oddcounter, leftover;
    int j = 0;
    int count = 0;

    for(int i = 0;  i < length; ++i){
        numbers[i] = atoi(argv[i+1]);
    }

    for(int i = 0; i < length; ++i){
        leftover = numbers[i] % 2;

        if (leftover != 0){
            oddnums[j] = numbers[i];
            count++;
            j++;

        }

    }

    oddcounter = sizeof(oddnums) / sizeof(oddnums[0]);
    printf("%d\n", count);

    return 0;
}
