#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    int length = argc -1;
    int numbers[length];
    int leftover;
    int evens = 0;
    int count = 0;

    for(int i = 0; i < length; ++i){
        numbers[i] = atoi(argv[i + 1]);
    }

    for(int i = 0; i < length; ++i){
        leftover = numbers[i] % 2;

        if (leftover == 0){
            printf("%d - ", count);
            printf("%d\n", numbers[i]);
            evens++;
        }
        count++;
    }
    if (evens == 0){
        printf("Not found!\n");
    }

    return 0;
}
