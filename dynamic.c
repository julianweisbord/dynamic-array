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
