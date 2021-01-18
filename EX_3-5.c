// Sums the numbers entered by the user until a -1 is entered.
#include <stdio.h>
int main(void){
    int input = 0, sum = 0;
    while(input != -1){
	printf("\nCurrent Sum: %d\n", sum);
	printf("Please enter the next number: ");
	scanf("%d", &input);
	sum += input;
    }

    return 0;
}
