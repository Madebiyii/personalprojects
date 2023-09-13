#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    float PI = 3.1415;
    int radius = 0;
    float area = 0.0;

    radius = atoi(argv[1]);
    radius = radius*radius;
    area = radius*PI;

    printf("%.2f\n",area);
    /*printf("%9.2f\n",area);*/

    return 0;

}
