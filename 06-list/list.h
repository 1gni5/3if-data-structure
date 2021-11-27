#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

typedef struct node {
  int value;
  struct node* next;
} node_t;

void add(node_t** head, int value);
void push(node_t** head, int value);
int pop(node_t** head);
int get_index(node_t** head, int value);
void list_insert(node_t** head, int index, int value);

#endif // LIST_H_