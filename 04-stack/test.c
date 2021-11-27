#include <stdio.h>

#include "stack.h"

int main() {

  /* Créer une nouvelle pile */
  node_t* head = NULL;

  /* Insère des valeurs */
  int values[5] = {1, 5, 4, 9, 7};
  for (int x = 0; x < 5; x++)
    push(&head, values[x]);

  /* Parcours la liste */
  node_t* reader = head;
  while (reader != NULL){
    printf("%d ", reader->value);
    reader = reader->next;
  }
  printf("\n");

  /* Dépile tout les éléments */
  while (pop(&head) != -1)
    continue;

  return 0;
}
