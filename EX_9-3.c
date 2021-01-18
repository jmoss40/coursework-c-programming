// This program prints the abbreviation 'POTUS' for the string 
// 'president of the united states'.
#include <ctype.h>
#include <stdio.h>
#include <string.h>
void print_abbreviation(char* name);
int main(void){
    char name[] = "president of the united states";
    print_abbreviation(name);
    return 0;
}

void print_abbreviation(char* name){
    char* token = strtok(name, " ");
    while(token != NULL){
	char temp[strlen(token)];
	strcpy(temp, token);
	printf("%c", toupper(temp[0]));
	token = strtok(NULL, " ");
    }
    printf("\n");
}
