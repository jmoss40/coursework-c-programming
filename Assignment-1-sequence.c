/*
    This program reads in a sequence of numbers from the user and prints
    the largest, second-largest, and the average of the entered numbers.
    The user keeps printing numbers until they enter a negative number.
*/
#include <stdio.h>
int main(void){
    int largest = 0, second = 0;
    int count = 0, sum = 0, num = 0;
    float average = 0;
    
    printf("Enter the first number: ");
    scanf("%d", &num);
    if(num > largest)
	largest = num;
    sum += num;
    int last = num;
    count++;

    while(num >= 0){
	printf("\nEnter the next number: ");
	scanf("%d", &num);
	
	if(num < 0)
	    break;	
    
	sum += num;
	if(second == 0)
	    second = last;
	if(num > largest)
            largest = num;
        if(num > second && num < largest)
            second = num;
	count++;
    }
    average = (float)sum / count;
    
    printf("\nLargest is %d", largest);
    printf("\nSecond largest is %d", second);
    printf("\nAverage is %f\n", average);

    return 0;
}
