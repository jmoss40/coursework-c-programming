/*
    Calculates the compound interest based on the amount to invest, 
    interest rate, and years of investment.
*/
double compound_interest(double p, double i, double n);

#include <stdio.h>
#include <math.h>
int main(void){
    double p, i, n;

    // have the user enter p
    printf("Dollar amount to invest: ");
    scanf("%lf", &p);
    while(p <= 0){
	printf("Try again; enter an amount > 0: ");
	scanf("%lf", &p);
    }

    // have the user enter i
    printf("Percentage interest rate: ");
    scanf("%lf", &i);
    while(i <= 0 || i > 15){
	printf("Rate must be > 0 and <= 15%: ");
	scanf("%lf", &i);
    }

    // have the user enter n
    printf("Years of investment: ");
    scanf("%lf", &n);
    while(n <= 0){
	printf("Years must be > 0: "); 
	scanf("%lf", &n);   
    }

    double interest = compound_interest(p, i, n);

    printf("\nIf you invest $%.2lf at %.2lf%%", p, i);
    printf("\nIts value in %.2lf years will be $%.2lf\n\n", n, interest);
    
    return 0;
}

double compound_interest(double p, double i, double n){
    return p * pow(1+(i/100), n);
}

