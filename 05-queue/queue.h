#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

typedef struct node {
  int value;
  struct node* next;
} node_t;

void add(node_t** head, int value);
int pop(node_t** head);
bool is_empty(node_t** head);

#endif // QUEUE_H_