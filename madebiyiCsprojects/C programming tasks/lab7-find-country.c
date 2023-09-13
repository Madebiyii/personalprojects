#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void result (char * name, char * capital, int size, float population);

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
    Country country[50];

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");

    for(int i = 0; i < numofcountries; ++i){
        strcpy(country[i].name, argv[index]);
        strcpy(country[i].capital, argv[index + 1]);
        country[i].population = atof(argv[index + 2]);
        country[i].size= atoi(argv[index + 3]);

        index += 4;
        if(country[i].size < 100000){
            result(country[i].name, country[i].capital, country[i].size, country[i].population);
        }
    }

return 0;
}

void result (char * name, char * capital, int size, float population){
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", name, capital, size, population);
}
