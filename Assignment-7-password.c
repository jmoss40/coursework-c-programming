// This program takes in a password from input and checks whether or not
// the password is strong.
#include <ctype.h>
#include <stdio.h>
int issymbol(char c);
int main(void){
    // get an input string from standard input
    char password[50];

    // initialize elements of password array to null - 
    // prevents unexpected behavior due to whats in memory
    for(int i = 0; i < 50; i++){
	password[i] = NULL;
    }


    printf("Please enter a new password: ");
    scanf("%s", password);
    
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int symbol = 0;
    int length = 0;

    for(int i = 0; i < 50; i++){
	if(password[i] != NULL){
	    if(islower(password[i]))
		lower = 1;
	    if(isupper(password[i]))
		upper = 1;
	    if(isdigit(password[i]))
		digit = 1;
	    if(i >= 5)
		length = 1;
	    if(issymbol(password[i]))
		symbol = 1;
	}
    }
    
    if(lower && upper && digit && length && symbol){
	printf("The password is strong!\n");
    }else{
	printf("The password needs:\n");
	if(!length)
	    printf("\tto have at least six characters.\n");
	if(!upper)
	    printf("\tat least one upper-case letter.\n");
	if(!lower)
	    printf("\tat least one lower-case letter.\n");
	if(!symbol)
	    printf("\tat least one symbol from {!,@,#,$,^,&}.\n");
	if(!digit)
	    printf("\tat least one digit.\n");
    }

    return 0;
}

// a function to check that a character is one of the symbols
// that is required for the password
int issymbol(char c){
    if(c == '!'|| c == '@'|| c == '#'|| c == '$'|| c == '^'|| c == '&'){
	return 1;
    }
    return 0;
}
