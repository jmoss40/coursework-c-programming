// This program prints formatted output based on the input number of lines.
// (sample output below)
#include <stdio.h>
int main(void){
    int n;
    do{
	puts("Please enter the number of lines: ");
	scanf("%d", &n);
    }while(n <= 0);

    for(int i = 0; i < n; i++){
	if(i % 2 == 1)
	    printf("\n*      *");
	else
	    printf("\n********");
    }
    puts("\n");

    return 0;
}

/*
Sample output:

Please enter the  number of lines: 11
********
*      *
********
*      *
********
*      *
********
*      *
********
*      *
********

*/
