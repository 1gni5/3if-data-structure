#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node {
  int value;
  struct node* next;
  struct node* previous;
} node_t;

node_t* push(node_t** head, int value);
int pop(node_t** head);
node_t* insert(node_t** head, int index, int value);

#endif // LINKED_LIST_H_