// This program takes in a sentence and replaces 's' or 'ss' with 'th',
// to make it pronounced with a lisp.
#include <stdio.h>
#include <ctype.h>
void work(void);
int main(void){
    char more = 'y';
    do{
	work();
	puts("\nMore? (y/n)");
	more = getchar();
    }while(more != 'n' && more != 'N');
    
    return 0;
}

void work(void){
    char string[100];

    for(int i = 0; i < 100; i++){
	string[i] = NULL;
    }

    puts("Enter a sentence: ");
    do{
	fgets(string, 100, stdin);
    }while(strlen(string) < 2);

    int i = 0; 
    while(string[i] != NULL){
	if(tolower(string[i]) == 's'){
	    if(tolower(string[i-1]) == 's'){
		i += 2;
		continue;
	    }
	    putchar('t');
	    putchar('h');
	}else{
	    putchar(string[i]);
	}
	i++;
    }
    
}


