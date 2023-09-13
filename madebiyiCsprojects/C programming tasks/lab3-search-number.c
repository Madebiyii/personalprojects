#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchNumber(int numtofind, int elementinarray);

int main(int argc, char*argv[]){
    int length = argc - 2;
    int inputnumbers[length];
    int numtofind = atoi(argv[1]);

    for(int i = 0; i < length; ++i){
        inputnumbers[i] = atoi(argv[i + 2]);
    }

    for(int i = 0; i < length; ++i){
        if(searchNumber(numtofind, inputnumbers[i]) == 0){
            printf("Found %d at %d\n", numtofind, i);
            break;
        }
        else if(i == length){
            printf("%d not found\n", numtofind);
            break;
        }
    }
    return 0;
}

int searchNumber(int numtofind, int elementinarray){
    if(numtofind == elementinarray){
        return 0;
    }
}
