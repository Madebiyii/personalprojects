#include<stdio.h>
#include<stdlib.h>

int main(){
    int age[5]; //= {21, 29, 25, 32, 17}; //can only store five values

    for(int i = 0; i < 5; ++i){
        scanf("%d", &age[i]);
    }

    for(int i = 0; i < 5; ++i){
        printf("%d ", age[i]);
    }
    /*printf("Enter 5 input values:\n");

    scanf("%d\n", &age[0]);
    scanf("%d", &age[1]);
    scanf("%d", &age[2]);
    scanf("%d", &age[3]);
    scanf("%d", &age[4]);


    printf("%d\n", age[0]);
    printf("%d\n", age[1]);
    printf("%d\n", age[2]);
    printf("%d\n", age[3]);
    printf("%d\n", age[4]);*/

    return 0;
}
