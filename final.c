
#include <stdio.h>
#include <stdlib.h>

struct order_data {
  unsigned int id;
  float price;
  unsigned int qty;
};

struct order_item {
  struct order_data* data;
  struct order_item* link;
};

struct order_data* create_order_data(unsigned int id, float price, unsigned int qty){
    struct order_data* data = (struct order_data*)malloc(sizeof(struct order_data*));
    data->id = id;
    data->price = price;
    data->qty = qty;
    return data;
}


struct order_item* create_order_item(struct order_data* data){
    struct order_item* item = (struct order_item*)malloc(sizeof(struct order_item*));
    item->data = data;
    item->link = NULL;
    return item;
}

void add_item(struct order_item* factor_head, struct order_data* data){
    struct order_item* new_item = (struct order_item*)malloc(sizeof(struct order_item*));
    new_item->data = data;
    new_item->link = NULL;
    struct order_item* temp = factor_head;
    while(temp->link != NULL){
	temp = temp->link;
    }
    temp->link = new_item;
}


float find_total(struct order_item* factor_head){
    struct order_item* temp = factor_head;
    float sum = 0.0f;
    while(temp->link != NULL){
	sum += temp->data->qty;
	temp = temp->link;
    }
    return sum;
}


void dump_factor(struct order_item* factor_head, const char filename[]){
    FILE* file = fopen(filename, "a");
    struct order_item* temp = factor_head;
    if(file != NULL){
	while(temp->link != NULL){
	    fwrite(temp->data, sizeof(struct order_item*), 1, file);
	    temp = temp->link;
	}
	fclose(file);
    }	
}

struct order_item* load_factor(const char filename[]){
    FILE* file = fopen(filename, "r");
    struct order_item* item = malloc(sizeof(struct order_item*));
    if(file != NULL){
        fread(item, sizeof(struct order_item*), 1, file);
        fclose(file);
    }
}

void print_factor(struct order_item* factor_head){
    struct order_item* temp = factor_head;
    while(temp->link != NULL){
	printf("id: %d, price: %.3f, qty: %d\n", temp->data->id, temp->data->price, temp->data->qty);
	temp = temp->link;
    }
}

int main() {
  struct order_data* data = create_order_data(1, 50.0, 1);
  struct order_item* factor_head = create_order_item(data);

  data = create_order_data(2, 30.0, 3);
  add_item(factor_head, data);
  data = create_order_data(3, 20.0, 1);
  add_item(factor_head, data);

  printf("Before dump:\n"); 
  print_factor(factor_head);
  printf("--- Total: %0.3f\n", find_total(factor_head));

  dump_factor(factor_head, "myfactor.dat");
  printf("===========\n");
  printf("After load:\n");
  struct order_item* factor_newhead = load_factor("myfactor.dat");
  print_factor(factor_newhead);
  printf("--- Total: %0.3f\n", find_total(factor_newhead));
  return 0;
}

