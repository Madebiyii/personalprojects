#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char symmetric(char *word);

int main(int argc, char *argv[]){

    char *inputstr = argv[1];
    if(symmetric(inputstr) == 0){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
return 0;
}


char symmetric(char *word){
    int wordlength = strlen(word);
    int midlength = strlen(word) / 2;
    for(int i = 0; i < midlength; ++i){
        if(word[i] != word[wordlength - i - 1]){
            return 1;
        }
    }
    return 0;
}
