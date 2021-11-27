#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

typedef struct node {
  int value;
  struct node* next;
} node_t;

node_t* push(node_t** head, int value);
int pop(node_t** head);
bool is_empty(node_t** head);

#endif // STACK_H_