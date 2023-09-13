/*
Author: Michael Adebiyi
Date: Wednesday 30th November 2022
*/

/*Description: This code reads in an array (list) of numbers.
Using the sortnums function the array is sorted into ascending order.
There is a initialised counter for each integer, if the count for an integer surpasses 3 it is printed as output the amount of times it tis counted*/

#include <stdio.h>
#include <stdlib.h>


//Declaring functions 
void sortnums(int *inputnums, int length);
void counter(int *pInputnum, int length);
void findFrequent(int num, int count);
void outputFrequent(int num, int count);
 
 
int main(int argc, char *argv[]){ 

    //Initialising variables.
    int memorySpace = 5;  //Starting size of inputnums is set to 5.
    int length = argc - 1;
    int *inputnums = calloc(memorySpace, sizeof(int));

    if(!inputnums){
        printf("There is not enough memory space"); //Output when there is no more space
    }
 
    for(int i = 0; i < length; ++i){
        inputnums[i] = atoi(argv[i + 1]);

        if(i == memorySpace - 1){
            int *tmpptr;
            memorySpace += 1;
            tmpptr = (int*)realloc(inputnums, memorySpace * sizeof(int));
    
            if(!tmpptr){
                printf("A failure has occured with memory allocation\n"); //Output Incase memory allocation fails
                free(inputnums);// frees up memory space
                inputnums = NULL;
            }
             
            inputnums = tmpptr;
        }
    }
     
    sortnums(inputnums, length);
    counter(inputnums, length);
 
    return 0;
} 
 
// Sorting input number in ascending
void sortnums(int *inputnums, int length){
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(inputnums[i] > inputnums[j]) {
                int tmp = inputnums[i];
 
                inputnums[i] = inputnums[j];
                inputnums[j] = tmp; 
            }
        }
    }
}
 
//Counts occurences of intgers in array
void counter(int *pInputnum, int length){
    int count = 0;
 
    for(int i = 0; i < length; ++i){
        count = 0;
        for(int j = 0; j < length; ++j){
            if(pInputnum[i] == pInputnum[j]){
                count += 1;
            }
        }
 
        findFrequent((pInputnum[i]), count);
    }
}

//Locates most frequent integer in array by seeing if it occurs more than 3 times
void findFrequent(int num, int count){
    if(count > 3){
        outputFrequent(num, count);
    }
}

//Prints out most frequent integers in array the correct amount of times
void outputFrequent(int num, int count){
    printf("%d\n", num);
}
