// This program prints the sample output below using nested for loops.
#include <stdio.h>
int main(void){
    for(int i = 0; i < 10; i++){
	for(int j = 10; j > i; j--){
	    printf("*");
	}
	printf("\n");
    }

    return 0;
}

/*
Output to match:

**********
*********
********
*******
******
*****
****
***
**
*

*/
