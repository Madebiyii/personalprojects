#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

    char ch = argv[1][0];
    char *inputstr = argv[2];
    //char ch = argv[1][0];
    int count = 0;

    while(inputstr = strchr(inputstr, ch)){
        ++count;
        ++inputstr;
    }

    printf("%d\n", count);

    return 0;
}
