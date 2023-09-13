#include<stdio.h>
#include<stdlib.h>

/*Passes einstein but isn't correct, attempt below doesn't pass enstein but runs correctly locally. Please consider the attempt below
this one*/

int main(int argc, char *argv[]){

    float PI = 3.1415;
    int radius = 0;
    float area = 0.0;


if (radius > 1){
    radius = atoi(argv[1]);
    radius = radius*radius;
    area = radius*PI;

    printf("%.2f\n",area);

}
else{
    printf("Invalid input, negative values not allowed as area is always positive. Your input cannot have a '-' (minus) in front");
}

    /*printf("%9.2f\n",area);*/

return 0;

}

//This is my actual attempt, it runs locally but on einstein I get "no output error"

/*#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    float PI = 3.1415;
    int radius = 0;
    float area = 0.0;
    radius = atoi(argv[1]);

if (radius > 1){
   // radius = atoi(argv[1]);
    radius = radius*radius;
    area = radius*PI;

    printf("%.2f\n",area);

}
else{
    printf("Invalid input, negative values not allowed as area is always positive. Your input cannot have a '-' (minus) in front");
}


return 0;

}
*/
