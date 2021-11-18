#include <stdio.h>

#include "linked-list.h"

int main() {

  /* Créer une nouvelle liste */
  node_t* head = NULL;

  /* Insère des valeurs */
  int values[5] = {1, 5, 4, 9, 7};
  for (int x = 0; x < 5; x++)
    push(&head, values[x]);

  /* Insert une valeur par indice */
  insert(&head, 3, 2);

  /* Parcours la liste */
  node_t* reader = head;
  while (reader != NULL){
    printf("%d ", reader->value);
    reader = reader->next;
  }
  printf("\n");

  /* Supprime la liste */
  while (pop(&head) != -1)
    continue;

  return 0;
}
