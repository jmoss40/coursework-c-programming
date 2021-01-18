// This program takes in an integer number and prints out the number of 
// 1's in its binary representation. (Ex: 7 = 111, so number of 1's is 3)
#include <stdio.h>
int main(void){
    int num = 0, count = 0;
    // get the number from user input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // loop through the number - by using the maximum number of bits
    // an int can have (32), this works with any integer (including negatives)
    // sizeof(int) returns number of bytes(4), *8 = num of bits
    for(int i = 0; i < sizeof(int)*8; i++){
	if((num & 1) == 1) // if the least significant bit is 1, increment count
	    count++;
	num = num >> 1; // shift num right 1 bit
    }
    printf("Number of 1s: %d\n", count);

    return 0;
}

