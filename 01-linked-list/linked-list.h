#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct cell {
  int value;
  struct cell* next;
} cell_t;

cell_t* push(cell_t** head, int value);
int pop(cell_t** head);
int v_remove(cell_t** head, int value);

#endif // LINKED_LIST_H_
