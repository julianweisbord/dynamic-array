#include <stdio.h>
#include "dynamic.h"

int main(int argc, char **argv){
  struct myArray array;
  char answer;
  int num, init_len,listChoices;

  printf("Initialize the array with how many elements? ");
  scanf("%d", &init_len);
  printf("%d\n", init_len);
  // call initialize function
  init_array(init_len,&array);
  do{
    printf("What number would you like to enter into the list?: \n");
    scanf("%d",&num);
    // each add call seams to delete length? Is it going out of scope?
    add(num,&array);
      // printf("What would you like to do with this list?\n Choice coming soon... \n");
      // scanf("%d\n",&listChoices);
      // remove element, print an element at a position

    printf("Would you like to add another list item to the array?(y/n) \n");
    scanf("%1s", &answer);
  }while(answer=='y');

// print out array
  printer(&array);
  // clear(&array);
// free array

}
