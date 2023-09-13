#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    int try = 5;
    int conversion = 2;
    int penalty = 3;
    int dropgoal = 3;

    int s1 = atoi(argv[1]);
    int s2 = atoi(argv[2]);
    int s3 = atoi(argv[3]);
    int s4 = atoi(argv[4]);

    int total;
    total = (s1*try) + (s2*conversion) + (s3*penalty) + (s4*dropgoal);
    printf("%d\n", total);


}
