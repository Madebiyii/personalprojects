#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Country{
    char name[50];
    char capital[50];
    float population;
    int size;
};


typedef struct Country Country;

int main(int argc, char* argv[]){

     int length = argc - 1;
     int numofcountries = length/4;
     int index = 1;
     float average = 0.0;
     Country country[50];

     printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

     for(int i = 0; i < numofcountries; ++i){
         strcpy(country[i].name, argv[index]);
         strcpy(country[i].capital, argv[index + 1]);
         country[i].population = atof(argv[index + 2]);
         country[i].size= atoi(argv[index + 3]);
         average += country[i].population;

         index += 4;
         printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[i].name, country[i].capital, country[i].size, country[i].population);
     }

     printf("Population average: %.2f\n", average / numofcountries);
return 0;
}
