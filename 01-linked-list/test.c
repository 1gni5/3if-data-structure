#include <stdio.h>

#include "linked-list.h"

int main() {

  /* Create a new cell */
  cell_t* head = NULL;
  push(&head, 5);

  /* Add values */
  push(&head, 9);
  push(&head, 3);
  push(&head, 10);

  /* Remove known values */
  v_remove(&head, 10);
  v_remove(&head, 9);

  /* Remove unknown value */
  v_remove(&head, -12);

  /* Pop the head of the list */
  printf("%d\n", pop(&head));

  /* Empty the list */
  while (pop(&head) != -1)
    continue;

  return 0;
}
