#include <stdio.h>
#include "dynamic.h"
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef INPUT_BUFFER_SIZE
#define INPUT_BUFFER_SIZE 100
#endif

int readline( char * buffer, int max ){
	// Index in buffer array
	int i, j = 1;
	// Current character
	char tmp;
	// Read until newline or max - 1 for NULL terminate
	for ( i = 0; i < max - 1 && j; ++i ){
		// Read in a character
		j = read( STDIN_FILENO, & tmp, 1 );
		// If we are at a newline then we are done
		if ( tmp == '\n' ){
			break;
		}
		// Other wise copy charaters into the buffer
		else{
			buffer[ i ] = tmp;
		}
	}
	// Remove the newline from stdin
	while ( tmp != '\n' ){
		j = read( STDIN_FILENO, & tmp, 1 );
	}
	// NULL terminate
	buffer[ i ] = '\0';
	// Length of string
	return i;
}


int main(int argc, char **argv){
  struct myArray array;
  char answer, removeChoice, removeAgain;
  char input_buffer[INPUT_BUFFER_SIZE];
  int num, init_len,listChoices, check, printNum;

  printf("Initialize the array with how many elements?\n ");
  readline(input_buffer, INPUT_BUFFER_SIZE);
  sscanf(input_buffer, "%d", &init_len);
  printf("%d\n", init_len);
  // call initialize function
  init_array(init_len,&array);
  do{
    printf("What number would you like to enter into the list?: \n");
    readline(input_buffer, INPUT_BUFFER_SIZE);
    sscanf(input_buffer, "%d", &num);
    // each add call seams to delete length? Is it going out of scope?
    add(num,&array);
    // change this to a table of options
      // remove element
		printf("Would you like to remove the last element of the array?(y/n)\n");
		readline(input_buffer, INPUT_BUFFER_SIZE);
		sscanf(input_buffer, "%1s", &removeChoice);
		if (removeChoice=='y'){
			do{
				pop_array(&array);
				printf("Would you like to do this again?(y/n)\n");
				readline(input_buffer, INPUT_BUFFER_SIZE);
				sscanf(input_buffer, "%1s", &removeAgain);
			}while(removeAgain=='y');
		}
      //  print an element at a position
    printf("Would you like to print out a number? If so what position(0 -> x) : \n");
    readline(input_buffer, INPUT_BUFFER_SIZE);
    if(sscanf(input_buffer, "%d", &printNum)!=1){
      printf("Not a number!\n");
    }
    else{
      // check if they entered int.
      // printf("user input: %d\n", printNum);
      indexer(&array, printNum);
    }
    printf("Would you like to add another list item to the array?(y/n) \n");
    readline(input_buffer, INPUT_BUFFER_SIZE);
    sscanf(input_buffer, "%1s", &answer);
  }while(answer=='y');

// print out array
  printer(&array);
  // clear(&array);
// free array

}
