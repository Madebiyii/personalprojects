//Author: Michael Adebiyi
//Date: 3/11/2022

/*Description: This code takes in grocery items and values that relat to each item, the values are stored in a struct when they are passed to the "addtostruct" function.
and the values are printed out when passed to the "output" function which also tells us if there is a sale or no sale */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Shopping Shopping;//defining the struct

//declaring values in the struct
struct Shopping
{
  char item[20];
  unsigned int amount;
  float price;
  unsigned int promotion;
};

//declaring functions
void addtostruct(Shopping shopping[], int argc, char * argv[]);
void output(Shopping shopping[], int numofitems);

int main(int argc, char * argv[]){
	Shopping shopping[100];
	int numofitems = (argc -1)/4;

	addtostruct(shopping, argc, argv);//calling functions that takes in input and adds to list
	output(shopping, numofitems);//calling function that displays the correct output

	return 0;
}

void addtostruct(Shopping shopping[], int argc, char * argv[])//this function takes in the different values and adds them to the struct
{
	int numofitems = (argc - 1)/4;

	int p = 1;//p stands for position
	//for loop goes through each set of items, amount price and promotion and adds them to struct
	for(int i = 0; i < numofitems; i++){
		strcpy(shopping[i].item, argv[p]);
		shopping[i].amount = atoi(argv[p + 1]);
		shopping[i].price = atof(argv[p + 2]);
		shopping[i].promotion = atoi(argv[p + 3]);
		p = p + 4;
	}
}

void output(Shopping shopping[], int numofitems)//taks in the struct as input and outputs each category and weather it qualifies for sale or not
{

	for (int i = 0; i < numofitems; i++){
	if (shopping[i].promotion == 1){
    	printf("%s,%d,%.2f,On Sale\n", shopping[i].item, shopping[i].amount, shopping[i].price);
	}
	else{
		printf("%s,%d,%.2f,No Sale\n", shopping[i].item, shopping[i].amount, shopping[i].price);
	}
	}
}
