// I had to provide the average function to calculate the average
// GPA of the list of Students.
#include <stdio.h>

typedef struct {
   char* name;
   unsigned int id;
   float gpa;
} Student;


float average(Student list[], int size);

int main() {
    Student students[10];
    students[0].name = "John Smith";
    students[0].id = 1;
    students[0].gpa = 3.2;


    students[1].name = "Nick Harris";
    students[1].id = 2;
    students[1].gpa = 2.9;


    students[2].name = "Robert Daniels";
    students[2].id = 3;
    students[2].gpa = 3.5;

    students[3].name = "Nathasha Jons";
    students[3].id = 4;
    students[3].gpa = 3.1;

    printf("Average GPA is %f\n", average(students, 4));
    return 0;

}

float average(Student list[], int size){
    float average = 0;
    int i;
    for(i = 0; i < size; i++){
	average += list[i].gpa;
    }
    return average/size;
}
