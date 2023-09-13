/*
Author: Michael Adebiyi
Date: Wednesday 30th November 2022
*/

/*Description: This code takes in an array of integers and adds them as nodes to linked list.
The "delEven" function deletes even integers in the linked list.
The odd numbers remaining are passed to the getTotal function and added.
Lastly the odd numbers are outputed with the sum at the end.
 */

#include <stdio.h>
#include <stdlib.h>

//Initialising Node.
typedef struct Node Node;

//Initialising a doubly linked list with nodes
struct Node
{
    int inputnum;
    Node *next;
    Node *previous;
};

// Initialisation of functions
Node *addNodesTolinkedList(char *argv[], int length);
int foundEvencounter(char *argv[], int length);
Node *delEvens(Node *first);
void outputNodesOfLinkedList(Node *first);
void getTotal(int *total, Node *first);

//Main Function
int main(int argc, char *argv[]){

    //Initialising variables in main
    Node *first = NULL;
    int length = argc - 1;
    int total = 0;

    int evenCounter = foundEvencounter(argv, length);

    first = addNodesTolinkedList(argv, length);

    for(int i = 0; i < evenCounter; ++i){
        first = delEvens(first);
    }

    
    getTotal(&total, first);

    outputNodesOfLinkedList(first);
    printf("%d\n", total);

    return 0;
}

//Add nodes to linked List
Node *addNodesTolinkedList(char *argv[], int length){
    //Initialising pointers being used
    Node *curr, *first, *previous;  

    //Adding first node to Linked list
    first = (Node*)calloc(1, sizeof(Node));
    
    //points to the first node
    curr = first;

    //input first integer to correct position in linked list
    curr->inputnum = atoi(argv[1]);

    for(int i = 0; i < length - 1; ++i){
        curr->next = (Node*)calloc(1, sizeof(Node));
        previous = curr;
        curr = curr->next;
        curr->inputnum = atoi(argv[i + 2]);
        curr->previous = previous;
    }

    curr->next = NULL;
    return first;
}

//Increments counter for found even integers
int foundEvencounter(char *argv[], int length){
    int count = 0;

    for(int i = 0; i < length; ++i){
        if(atoi(argv[i + 1]) % 2 == 0) {
            count += 1;
        }
    }

    return count;
} 

//Deletes found even numbers
Node *delEvens(Node *first){
    Node *left = NULL;
    Node *right = NULL;
    Node *numTobeDeleted = first;

    while(numTobeDeleted->inputnum % 2 != 0 && numTobeDeleted->next != NULL){
        numTobeDeleted = numTobeDeleted->next;
    }

    //stores node to the left so correct number
    if(numTobeDeleted->next == NULL){
        left = numTobeDeleted->previous;
        left->next = NULL;
    }
    //stores node to the left so correct number
    else if(numTobeDeleted->previous == NULL){
        first = numTobeDeleted->next;
        first->previous = NULL;
    }
    //Left and right nodes are properly linked
    else{
        left = numTobeDeleted->previous;
        right = numTobeDeleted->next;

        left->next = right;
        right->previous = left;
    }

    //Frees up space for efficiency when task is completed 
    free(numTobeDeleted);

    return first;
}

//adds up odd numbers in linked list
void getTotal(int *total, Node *first){
    Node *p = first;

    while(p != NULL){
        *total += p->inputnum;
        p = p->next;
    }
}

//Prints out correct integers left in linked list
void outputNodesOfLinkedList(Node *first){
    Node* p = NULL;
    for(p = first; p != NULL; p = p->next){
        printf("%d\n", p->inputnum);
    }
}