#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wordposition(char *inputstr, char *word);

int main(int argc, char *argv[]){

    char *inputstr = argv[1];
    char *word = argv[2];

    wordposition(inputstr, word);

    return 0;
}


int wordposition(char *inputstr, char *word){

    char *pFoundword = NULL;
    if(strstr(inputstr, word)){

        char *pFoundword = strstr(inputstr, word);
        int firstchar = pFoundword - inputstr;
        int lastchar = (firstchar + strlen(word)) - 1;
        printf("%d %d\n", firstchar, lastchar);
    }
    return 0;
}
