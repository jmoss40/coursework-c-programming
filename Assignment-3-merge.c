/*
    This program reads two sorted lists of positive integers from input and
    merges the sorted list so that the merged list is still sorted.
    The merged list is then printed in ascending and descending order.
*/
#include <stdio.h>
#include <stdlib.h>
void print_array(int arr[], int size, int reverse);
void sort_array(int* array, int size);
int main(void){
    int sizeA = 0, sizeB = 0, entry = 0;

    //Allocate memory to be used as dynamic arrays - max size is 100 integers
    int* memA = (int*)malloc(sizeof(int) * 100);
    int* memB = (int*)malloc(sizeof(int) * 100);

    //Get array A
    printf("Enter array A: ");
    while(entry >= 0){
	scanf("%d", &entry);
	if(entry >= 0){
	    *(memA + sizeA) = entry;
	    sizeA++;
	}
    }

    //Make the allocated memory into an array
    int arrayA[sizeA];
    for(int i = 0; i < sizeA; i++){
	arrayA[i] = *(memA+i);
    }
    free(memA); //free the memory that was allocated

    //Print array A as it was entered
    printf("Array A: ");
    print_array(arrayA, sizeA, 0);

    //Sort array A, in case it is not already sorted
    sort_array(arrayA, sizeA);
    
    //Get array B
    entry = 0;
    printf("Enter array B: ");
    while(entry >= 0){
	scanf("%d", &entry);
	if(entry >= 0){
	    *(memB + sizeB) = entry;
	    sizeB++; 
	}
    }

    //Make the allocated memory into an array
    int arrayB[sizeB];
    for(int i = 0; i < sizeB; i++){
	arrayB[i] = *(memB+i);
    }
    free(memB); // free the memory used by Array B

    //Print array B
    printf("Array B: ");
    print_array(arrayB, sizeB, 0);

    //Sort array B, in case it is not already sorted
    sort_array(&arrayB, sizeB);

    // merge the two arrays
    int arrayC[sizeA + sizeB];
    int indexA = 0, indexB = 0, index = 0;
    for(index = 0; index < sizeA+sizeB; index++){
	if(arrayA[indexA] < arrayB[indexB]){
	    arrayC[index] = arrayA[indexA];
	    indexA++;
	}else{
	    arrayC[index] = arrayB[indexB];
	    indexB++;
	}
    }
    while(indexA < sizeA){
	arrayC[index] = arrayA[indexA];
	index++;
	indexA++;
    }
    while(indexB < sizeB){
	arrayC[index] = arrayB[indexB];
	index++;
	indexB++;
    }
    printf("Merge (ascending): ");
    print_array(arrayC, sizeA+sizeB, 0);

    printf("Merge (descending): ");
    print_array(arrayC, sizeA+sizeB, 1);
    return 0;
}

void print_array(int array[], int size, int reverse){
    if(reverse == 0){
	for(int i = 0; i < size; i++){
	    printf("%d ", array[i]);
	}
    }else{
	for(int i = size-1; i >= 0; i--){
	    printf("%d ", array[i]);
	}
    }
    printf("\n");
}

void sort_array(int* array, int size){
    int temp;
    for (int i = 0; i < size; i++) {
	for (int j = i + 1; j < size; j++){
	    if (*(array + i) > *(array + j)){
		temp =  *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = temp;
	    }
	}
    }
}

