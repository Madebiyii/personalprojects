#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int duplicated(int inputnums[], int length);

int main(int argc, char* argv[]){

    int inputnums[50], output;
    int length = 0;

    for(int i = 0; i < argc - 1; i++){
        inputnums[i] = atoi(argv[i + 1]);
        length++;

    }
    output = duplicated(inputnums, length);
    if(output != 0){
        printf("%d\n", output);
    }
    else{
        printf("no duplicated number\n");
    }
    return 0;
}

int duplicated(int inputnums[], int length){
    for(int i = 0; i < length; i ++){
        for(int j = i + 1; j < length; j++){
            if(inputnums[i] == inputnums[j]){
                return inputnums[i];
            }
        }
    }
    return 0;
}
