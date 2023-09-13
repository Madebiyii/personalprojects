#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[]){

    int width;
    width = atoi(argv[1]);

    for(int i = 0; i < width; ++i){
        printf("*");
    }
    printf("\n");

    for(int i = 0; i < width - 2; ++i){
        printf("*");

        for(int j = 0; j < width - 2; ++j){
            printf(" ");
        }
        printf("*\n");
    }
    for(int i = 0; i < width; ++i){
        printf("*");
        }
        printf("\n");

        return 0;
}
