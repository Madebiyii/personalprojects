#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    float centimetres = atoi(argv[1]);
    float  inches;
    inches = centimetres/2.54;
    printf("%.2f\n", inches);

    return 0;

}
