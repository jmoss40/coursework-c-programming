// I provided the dump_array and load_array functions
#include <stdlib.h>
#include <stdio.h>

void dump_array(char* filename, float array[], int size);
float* load_array(char* filename, int* size);

int main() {
    float myarray[] = {1.2, 5.2, 20.6, 50.1, 69., 30.5};
    dump_array("myar.dat", myarray, 6);
    int ar2_size;
    float *ar2 = load_array("myar.dat", &ar2_size);
    int i;
    for (i = 0; i < ar2_size; i++) {
	printf("%0.2f ", ar2[i]);
    }
    printf("\n");
    free(ar2);
    return 0;
}

void dump_array(char* filename, float array[], int size){
    FILE* file = fopen(filename, "w");
    
    fwrite(&size, sizeof(int), 1, file); // write size to file
    fclose(file);

    file = fopen(filename, "a");
    
    for(int i = 0; i < size; i++){
	float element = array[i];
	fwrite(&element, sizeof(float), 1, file); //write array to file
    }
    fclose(file);
}

float* load_array(char* filename, int* size){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
	exit(0);
    }
    
    fread(size, sizeof(int), 1, file);
    float* array = malloc(*size * sizeof(float));

    fseek(file, sizeof(int), SEEK_SET);
    fread(array, sizeof(float), *size, file);
    fclose(file);

    return array;
}

