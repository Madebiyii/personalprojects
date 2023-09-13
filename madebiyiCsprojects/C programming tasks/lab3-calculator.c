#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float simpleCalc(char *operand, float num1, float num2);

int main(int argc, char *argv[]){
    //char operand[] = argv[1];
    float result;
    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);
    result = simpleCalc(argv[1], num1, num2);

return 0;
}

float simpleCalc(char *operand, float num1, float num2){
    //printf("%s\n", operand);
    float mul = 0;
    float div = 0;
    if(num1 == 0 || num2 == 0){
        printf("invalid\n");

    }
    else if(strcmp(operand, "multiply") == 0){
        mul = num1 * num2;
        printf("%f\n", mul);
    }
    else if(strcmp(operand, "divide") == 0){
        div = num1/num2;
        printf("%f\n", div);
    }
    else
        printf("invalid\n");

return 0;
}
