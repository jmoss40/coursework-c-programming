// This program counts the number of lines in a text file.
#include <stdio.h>
int line_count(const char * file_name);
int main(void){
    const char * file_name = "example.txt";    
    printf("Number of lines in file: %d\n", line_count(file_name));
    return 0;
}

int line_count(const char * file_name){
    int count = 0;
    FILE* file = fopen(file_name, "r");
    if(file != NULL){
	char c = fgetc(file);
	while(c != EOF){
	    if(c == '\n'){
		count++;
	    }
	    c = fgetc(file);
	}
	fclose(file);
    }
    return count;
}
