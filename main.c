#include <stdio.h>
#include "dynamic.h"

int main(int argc, char **argv){
  struct myArray array;
  char answer;
  int num, init_len, pos, listChoices;

  printf("Initialize the array with how many elements? ");
  scanf("%d", &init_len);
  printf("%d\n", init_len);
  // call initialize function
  init_array(init_len,&array);
  do{
    printf("What number would you like to enter into the list and at what position? (num pos) \n");
    scanf("%d %d",&num, &pos);

      printf("What would you like to do with this list?\n Choice coming soon... \n");
      scanf("%d\n",&listChoices);
      // remove element, print an element at a position

    printf("Would you like to add another list item to the array?(y/n) \n");
    scanf("%1s", &answer);
  }while(answer=='y');

// print out array


}
