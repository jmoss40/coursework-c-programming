// I provided the copy and copy_offset functions to copy an array.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* copy(int ar[], int n);

int* copy_offset(int ar[], int n, int offset);

void print_array(int ar[], int size){
  for (int i = 0; i < size; i++ ) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

int main() {
  int myar[10] = {1,5,12, 23, 14, 20, 40, 50, 13, 81};
  int* mycp = copy(myar, 5);
  int* mycp2 = copy_offset(myar, 5, 5);

  print_array(myar, 10);
  print_array(mycp, 5);
  print_array(mycp2, 5);

  free(mycp);
  free(mycp2);
  return 0;
}

/*
Part 1 ) Provide copy function that takes as input an integer array
and the number of elements n to be copied, and returns another array
that contains the first n elements of the original array. 
*/
int* copy(int ar[], int n){
    int* array = malloc(n * sizeof(int));
    //int array[n];
    memcpy(&array, ar, sizeof(n));    
    return array;
}

/*
Part 2) Provide copy_offset function that takes as input an integer
array, the number of elements n to be copied, and an offset index and
returns another array that contains the n elements of the original
array starting at the offset position.
*/
int* copy_offset(int ar[], int n, int offset){
    int* array = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
	*(array + i) = ar[i + offset];
    }
    return array;
}


