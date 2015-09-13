#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("length: %d, current size: %d\n", array->length, array->current_size);
    printf("We will double the list...\n");
    int bytes =2*array->length * sizeof(int);
    int *new_array = malloc(bytes);
    int i;
    for (i=0; i < array->current_size; ++i){
      new_array[i] =array->data[i];
    }
    // so we don't have a memory leak.
    clear(array);
    array->data = malloc(bytes);
    for (i=0; i < array->current_size; ++i){
      array->data[i] = new_array[i];
    }
    array->length*=2;

  }
}

void printer(struct myArray* array){
  if(array->data){
    printf("Here is the array\n");
    int i;
    for(i=0; i< array->current_size; ++i){
      printf(" %d,", array->data[i]);
    }
    printf("\n The list is %d long\n", array->current_size);
  }
}


void add(int element, struct myArray *array){
  // Increase size of array
  ++array->current_size;
  printf("array length %d\n", array->length);
  // first check if the array isn't big enough
  doubleList(array);
  // array->data[array->current_size-1] = element; We dont need brackets :)
  *(array->data + array->current_size -1) = element;

}
void indexer(struct myArray *array, int printNum){
  if(printNum < 0 || printNum > (array->current_size)){
    printf("No information at this index.");
  }
  else{
    printf("%d\n",array->data[printNum]);
  }
}

void pop_array(struct myArray * array){
  if(array->data && array->current_size >0){
    printf("Array is not null, current size before pop: %d \n", array->current_size);
    // doesn't make it null
    array->data[array->current_size-1] = NULL;
    --array->current_size;
  }
  else{
    printf("Array is null.\n");
  }

}



// Free array
void clear(struct myArray *array){
  int i;
  for(i=0; i< array->current_size; ++i){
    printf("This is what will be freed: %d\n",array->data[i]);
    free(array->data[i]);
    array->data[i] =NULL;
  }
  printf("Array Should Be Empty: \n");
  printer(array);
}
