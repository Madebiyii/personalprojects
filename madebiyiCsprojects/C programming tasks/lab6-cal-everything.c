#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float CalcEverything(int num1, int  num2);

int main(int argc, char* argv[]){
    float result;
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    result = CalcEverything(num1, num2);

return 0;
}

float CalcEverything(int num1, int num2){
    if(num1 == 0 || num2 == 0){
        printf("invalid input\n");
    }

    else if(num1 != 0 || num2 != 0){
        float sum = num1 + num2;
        printf("%.2f\n", sum);
        float diff = num1 - num2;
        printf("%.2f\n", diff);
        float prod = num1 * num2;
        printf("%.2f\n", prod);
        float div = num1/num2;
        printf("%.2f\n", div);
        float power = pow(num1, num2);
        printf("%.2f\n", power);
        float natlog = log(num1) + log(num2);
        printf("%.2f\n", natlog);

    }
return 0;
}
