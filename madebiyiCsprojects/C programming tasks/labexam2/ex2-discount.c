//Author: Michael Adebiyi
//Date: 03/11/2022

/*Description: This code is very similar to "ex2-show-cart.c". The major differnce is that it determines wethere you are eligible for discount
and then calculates the total payment or what you pay after the discount is applied*/
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
	int numofitems = (argc - 1)/4;

	addtostruct(shopping, argc, argv);//calling functions that takes in input and adds to list
	output(shopping, numofitems);//calling function that displays the correct output

	return 0;
}

void addtostruct(Shopping shopping[], int argc, char * argv[])//this function takes in the different values and adds them to the struct
{
    int length = argc - 1;
	int numofitems = length/4;

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

void output(Shopping shopping[], int numofitems)/*takes in the struct as input. The function determines if a promotion is due using the for loop and if statement and then
calculates the total payment after discount is applied*/

{
    float total = 0;//initialising total payment

	for (int i = 0; i < numofitems; ++i){
	if (shopping[i].promotion == 0){//checking if all items to see if discount is due
	    total = total + shopping[i].amount * shopping[i].price;//calculates total if promotion isnt available
	}
	else{
	    total = total + (shopping[i].amount - (shopping[i].amount / 3)) * shopping[i].price;//calculates total if promotion is available
	}

	}
printf("%.2f\n", total);//outputs total to be paid

}
