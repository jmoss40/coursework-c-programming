// I provided the create_student, print_students, and delete_list functions
// for the Student linked list.
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char* name;
  int id;
} Student;


struct Node {
  Student* data;
  struct Node* next;
};


struct Node* create_student(char* name, int id){
  struct Node* new_student = NULL;
  new_student->data->name = name;
  new_student->data->id = id;
  return new_student;
}

void print_students(struct Node* head){
  while(head->next != NULL){
    printf("Name: %s, ID: %d", head->data->name, head->data->id);
    head = head->next;
  }
}

void delete_list(struct Node* head){
  struct Node* this = head;
  while(head->next != NULL){
    head = NULL;
    head = this->next;
    this = head;
  }
}

struct Node* add_student(struct Node* head, char* name, int id) {
  struct Node* new_head = create_student(name, id);
  new_head->next = head;
  return new_head;
}


int main() {
  struct Node* head = NULL;
  head = add_student(head, "John Smith", 800011);
  head = add_student(head, "Sarah Miller", 810325);
  head = add_student(head, "Jennifer Wilson", 821138);

  print_students(head);

  //Testing memory leak
  for (int j = 0; j < 10000; j++) {
    for (int i = 0; i < 10000; i++) {
      head = add_student(head, "test1", 888122);
    }
    delete_list(head);
    head = NULL;
  }
  return 0; 
}
