#ifndef DYNAMIC_H
#define DYNAMIC_H
#include <stdlib.h>
#include <stdio.h>

struct myArray{
  int length;
  int current_size;
  int *data; //array of ints
};

void init_array(int, struct myArray*);
void add(int, struct myArray *);
void doubleList(struct myArray* );
void printer(struct myArray* );





#endif
