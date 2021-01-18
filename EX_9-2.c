/*
    This program copies all of the characters from array1 to array2
    but replaces all non-alphabetic characters with '*'. For this
    assignment I have been instructed to do this using for loops
    intstead of using strcpy.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
    char array1[] = "ab cde\n123-fgh";
    char array2[20];
    
    for(int i = 0; i < strlen(array1); i++){
	if(!isalpha(array1[i])){
	    array2[i] = '*';
	}else{
	    array2[i] = array1[i];
	}
	printf("%c", array2[i]);
    }
    printf("\n");
    return 0;
}
