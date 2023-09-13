#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void isSorted(int inputnumbers[], int length);

int main(int argc, char* argv[]){
    int length = argc - 1;
    int inputnumbers[length];

    for(int i = 0; i < length; ++i){
        inputnumbers[i] = atoi(argv[i + 1]);
    }

    isSorted(inputnumbers, length);

    for(int i = 0; i < length; ++i){
        printf("%d\n", inputnumbers[i]);
    }
    return 0;
}

void isSorted(int inputnumbers[], int length){
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(inputnumbers[i] > inputnumbers[j]){
                int temp = inputnumbers[i];
                inputnumbers[i] = inputnumbers[j];
                inputnumbers[j] = temp;
            }
        }
    }
}
