/*
Author: Michael Adebiyi
Date: Wednesday 30th November 2022
*/

/*Description: This code takes in an array of integers and puts them into a linked list, 
the "findIrishprod" function searches for products wih origin as Ireland and then passes these products to the "priceUpdate" function,
which increases all irish products price by 20 percent.
Then the "outputNodes" function prints out the products with their codes and updated prices */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Initialising struct for Node
typedef struct Node Node;
typedef struct Product Product;

//Initialising struct for linked list
struct Node
{
    char productCode[50];
    char countryOforigin[50];
    unsigned int price;
    Node *next;
    Node *prev;
};

// Instantiating functions
Node *addNodestoLinkedlist(char *argv[], int length);  // Adds nodes to linked list.
Node *findIrishprod(Node *start);  // Checks each product to find which one is from Ireland.
int priceUpdate(Node *irishProd);  // Updates irish products' prices, increasing it up by 20%.
void outputNodes(Node *start);  // Prints out all products inputted and their information.

//Main function
int main(int argc, char *argv[]){   

    //Initialising variables
    Node *start = NULL;
    int length = argc - 1;

    //dividing by 3 to split up the three different properties
    int numOfproducts = length / 3;

    start = addNodestoLinkedlist(argv, length);
    start = findIrishprod(start);

    outputNodes(start);

    return 0;
}

//Adds inputs to linked list
Node *addNodestoLinkedlist(char *argv[], int length){
    //Initialising pointers to be used
    Node *curr, *first, *prev;

    //Initialising first node
    first = (Node*)calloc(1, sizeof(Node));

    //initialising first node using curr
    curr = first;
    strcpy(curr->productCode, argv[1]);
    strcpy(curr->countryOforigin, argv[2]);
    curr->price = atoi(argv[3]);

    //adds other inputs to Linked List
    for(int i = 3; i < length - 1; i += 3){
        curr->next = (Node*)calloc(1, sizeof(Node));
        prev = curr;
        curr = curr->next;

        //adds correct information to appropriate node
        strcpy(curr->productCode, argv[i + 1]);
        strcpy(curr->countryOforigin, argv[i + 2]);
        curr->price = atoi(argv[i + 3]);
        curr->prev = prev;
    }

    curr->next = NULL;
    return first;
}

//locates irish products in linked list
Node *findIrishprod(Node *start){
    Node* p = NULL;

    for(p = start; p != NULL; p = p->next){

        //Checks each product to see if it is an irish product
        if(strcmp(p->countryOforigin, "Ireland") == 0){
            p->price = priceUpdate(p);
        }
    }

    return start;
}

//Updates price of irish product
int priceUpdate(Node *irishProd){
    Node* p = irishProd;

    //Increasing product price by 20 percent
    p->price += p->price * 0.2;

    return p->price;
}

//Prints out products and correct codes and prices
void outputNodes(Node *start){
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next){
        printf("%s\n", p->productCode);
        printf("%s\n", p->countryOforigin);
        printf("%d\n", p->price);
    }
}
