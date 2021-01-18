/*
    This program asks the user to enter a numeric grade.
    It then calculates what their letter grade would be on
    a ten-point grading scale and prints it to the screen.
*/
#include <stdio.h>
int main(void){
    // ask the user to enter a score between 0 and 100
    // use a do-while loop to validate the input
    int score;
    do{
	puts("Enter the numeric grade: ");
	scanf("%d", &score);
    }while(score < 0 && score > 100);

    // convert the score to a letter grade
    char grade;
    if(score > 89){
	grade = 'A';
    }else if(score > 79){
	grade = 'B';
    }else if(score > 69){
	grade = 'C';
    }else if(score > 59){
	grade = 'D';
    }else{
	grade = 'F';
    }

    printf("The letter grade is a %c\n\n", grade);
    
    return 0;
}
