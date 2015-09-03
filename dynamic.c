#include <stdio.h>
#include <stdlib.h>
#include "dynamic.h"

void init_array(int init_len, struct myArray * array){
  array->length = init_len;
  array->current_size = 0;
  //create a data array with user input as length
  array->data = malloc(array->length * sizeof(int));
  // return array;
}

struct myArray* doubleList(struct myArray *array){
  // I wonder if this is slower than realloc
  if(array->length <= array->current_size){
    printf("We will double the list...\n");
    int *new_array = malloc(2 *array->length * sizeof(int));
    int i =0;
    for (i; i < array->current_size; ++i){
      new_array[i] =array->data[i];
    }
    array->data = new_array;

    array->length*=2;

  }
  // need to increment length
  return array;
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

  array = doubleList(array);
  // array->data[++array->current_size] = element; We dont need brackets :)
  *(array->data + ++array->current_size) = element;
  ++array->current_size;
}




// Make a clear function
