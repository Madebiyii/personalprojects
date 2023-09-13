#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Country {
  char name[100];
  char capital[100];
  float population;
  int size;
};

typedef struct Country Country;

void sort_country(Country Country[100], int total);
int main(int argc, char*argv[])
{
  int i = 1, total = 0;
  Country country[100];
  do
  {
    strcpy(country[total].name, argv[i++]);
    strcpy(country[total].capital, argv[i++]);
    country[total].population = atof(argv[i++]);
    country[total].size = atoi(argv[i++]);
    total++;
  } while (i < argc);
  sort_country(country, total);
  printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
  for (int j = 0; j < total; j++)
  {
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[j].name, country[j].capital, country[j].size, country[j].population);
  }
  return 0;
}
void sort_country(Country country[100], int total)
{
  int i = 0, j = 0;
  Country temp;
  for(i = 0; i < total; i++)
  {
    for(j = 0; j < (total - 1); j++)
    {
      if(country[j].population < country[j + 1].population)
      {
        temp = country[j];
        country[j] = country[j + 1];
        country[j + 1] = temp;
      }
    }
  }
}
