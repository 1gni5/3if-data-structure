#include <stdio.h>

#include "list.h"

int main() {

  /* Créer une nouvelle liste */
  node_t* head = NULL;

  /* Insère des valeurs */
  int values[5] = {1, 5, 4, 9, 7};
  for (int x = 0; x < 5; x++)
    add(&head, values[x]);

  /* Insère une valeur par index */
  list_insert(&head, 2, 3);
  list_insert(&head, 45, 33); // Insertion impossible

  /* Parcours la liste */
  node_t* reader = head;
  while (reader != NULL){
    printf("%d ", reader->value);
    reader = reader->next;
  }
  printf("\n");

  /* Récupère l'index de la valeur 5 */
  printf("Index de 5 : %d\n", get_index(&head, 5));

  /* Dépile tout les éléments */
  while (pop(&head) != -1)
    continue;

  return 0;
}
