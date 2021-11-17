#include <stdlib.h>

#include "linked-list.h"

/*
* Ajoute une nouvelle cellule de valeur=value en tête de liste.
*/
cell_t* push(cell_t ** head, int value) {

  /* Create the new cell */
  cell_t* new_cell = (cell_t*)malloc(sizeof(cell_t));
  new_cell->value = value;
  new_cell->next = *head;

  /* Set new head */
  *head = new_cell;
  return *head;
}

/*
 * Supprime la première cellule, retourne sa valeur.
 * Retourne -1 si la liste est vide (head = NULL).
*/
int pop(cell_t** head) {

  int ret_val = -1;
  cell_t *next_cell = NULL;

  /* No need to free memory */
  if (*head == NULL)
    return -1;

  /* Switch to next cell */
  next_cell = (*head)->next;
  ret_val = (*head)->value;
  free(*head);
  *head = next_cell;

  return ret_val;
}

/*
 * Supprime la première cellule pour qui valeur=value, retourne 0 si
 * trouve une cellule correspondante sinon retourne -1.
*/
int v_remove(cell_t** head, int value) {

  cell_t* current = *head;
  cell_t* previous = NULL;

  /* Parcours la liste */
  while (current != NULL) {

    /* Valeur trouvée */
    if (current->value == value) {

      /* If no previous cell exist */
      if (previous == NULL)
        *head = current->next;
      else
        previous->next = current->next;

      free(current);
      return 0;
    }

    previous = current;
    current = current->next;
  }

  return -1;
}
