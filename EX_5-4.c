// This program is a simple calculator. Reads an arithmetic operator
// from user (+, -, *, /), then reads 2 double numbers and applies the
// operator to them and prints the result.
#include <stdio.h>
int main(void){    
    char op;
    double num1, num2, result;

    do{
	puts("Enter an operand: ");
	scanf("%c", &op);
    }while(op != '+' && op != '-' && op != '*' && op != '/');

    puts("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(op){
	case '+':
	    result = num1 + num2;	    
	    break;
	case '-':
	    result = num1 - num2;
	    break;
	case '*':
	    result = num1 * num2;
	    break;
	case '/':
	    result = num1 / num2;
    }

    printf("%lf %c %lf = %lf\n\n", num1, op, num2, result);

    return 0;
}

