// This program takes a positive integer N from input and prints all prime
// numbers that are less than or equal to N.
#include <stdio.h>
#include <stdlib.h>
int check_prime(int n);
int main(void){
    int n, arrayIndex = 0;

    printf("Enter N: ");    
    scanf("%d", &n);
    
    int array[n];
    for(int i = 0; i < n; i++){
	if(check_prime(i) == 1){
	    array[arrayIndex] = i;
	    arrayIndex++;
	}
    }

    printf("Prime numbers: ");
    for(int i = 0; i < arrayIndex; i++){
	printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

int check_prime(int n){
    int flag = 0;    
    for(int i = 1; i <= n; i++){
	if(n % i == 0){
	    flag++;
	}
    }
    if(flag == 2){
	return 1;
    }
    return 0;
}
