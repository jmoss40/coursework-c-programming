/*
    This program allows the user to enter coefficients for a polynomial,
    and evaluates the polynomial using these coeffcients
*/
#include <stdio.h>
float evaluate(float coeffs[], int size, float x);
int main(void){
    int n; float x;
    printf("Enter n: ");
    scanf("%d", &n);

    float coeffs[n+1];
    printf("Enter coefficients: ");
    for(int i = 0; i < n+1; i++){
	float temp;
	scanf("%f", &temp);
	coeffs[i] = temp;
    }

    printf("Enter x: ");
    scanf("%f", &x);
    
    printf("Value is: %f\n", evaluate(coeffs, n, x));
    return 0;
}

// Note: I was instructed not to use math.h
float evaluate(float coeffs[], int size, float x){
    float total = 0;
    for(int i = 0; i < size; i++){
	float a = coeffs[i];
	if(i > 0){
	    float temp = x;
	    for(int j = 1; j <= i; j++){
		temp *= x;
	    }
	    total += a * temp;
	}else{
	    total += a;	
    	}
    }
    return total;
}

