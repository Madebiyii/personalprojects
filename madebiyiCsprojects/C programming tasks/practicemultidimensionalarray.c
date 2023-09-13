#include<stdio.h>
#include<stdlib.h>

int main(){
   int arr[2][3] = {{1, 3, 5}, {2, 4, 6}};

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 3; ++j){
        printf("%d ", arr[i][j]);
    }

    printf("\n");

  }

  /* arr[0][2] = 7;
   arr[1][1] = 8;
   //accessing elements in array
   printf("%d\n", arr[0][2]);
   printf("%d\n", arr[1][1]);*/

return 0;
}
