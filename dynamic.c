#include <stdio.h>
#include <stdlib.h>
#include "dynamic.h"

void init_array(int init_len, struct myArray * array){
  array->length = init_len;
  array->current_size = 0;
  //create a data array with user input as length
  array->data = malloc(array->length * sizeof(int));
}

void doubleList(struct myArray *array){
  // This may be slower than realloc
  printf("%d\n", array->length);
  if(array->length <= array->current_size){
    printf("IN IF\n");
    printf("length: %d, current size: %d", array->length, array->current_size);
    printf("We will double the list...\n");
    int *new_array = malloc((2 *array->length) * sizeof(int));
    int i =0;
    for (i; i < array->current_size; ++i){
      new_array[i] =array->data[i];
    }
    array->length*=2;
    array->data = new_array;

  }
}

void printer(struct myArray* array){
  printf("Here is the array\n");
  int i =0;
  for(i; i< array->current_size; ++i){
    printf(" %d,", array->data[i]);
  }
  printf("\n The list is %d long\n", array->current_size);
}


void add(int element, struct myArray *array){
  // first check if the array isn't big enough
  ++array->current_size;
  printf("array length %d\n", array->length);
  doubleList(array);
  // array->data[array->current_size-1] = element; We dont need brackets :)
  *(array->data + array->current_size -1) = element;

}



// Free array
// void clear(struct myArray *array){
//   int i=0;
//   for(i; i< array->current_size; ++i){
//     free(array->data[i]);
//   }
//   printf("after free\n");
//   printer(array);
// }
