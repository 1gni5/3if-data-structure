#include <stdlib.h>

#include "linked-list.h"

/*
 * Insère une valeur en tête de liste.
 */
node_t* push(node_t ** head, int value) {

  /* Créer un nouveau noeud */
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = *head;

  /* Met-à-jour la tête de liste */
  *head = new_node;

  return *head;
}

/*
 * Supprime la tête de liste et retourne sa valeur.
 * Retourne -1 si la liste est vide (head = NULL).
 */
int pop(node_t** head) {

  int ret_val = -1;
  node_t *next_node = NULL;

  /* Liste vide */
  if (*head == NULL)
    return -1;

  /* Change la tête de liste */
  ret_val = (*head)->value;
  next_node = (*head)->next;
  free(*head);
  *head = next_node;

  return ret_val;
}

/*
 * Insére une valeur à l'indice données.
 * Si l'indice n'existe pas la valeur n'est pas insérée.
 */
node_t* insert(node_t** head, int index, int value) {

  int position = 0;
  node_t *current = *head;
  node_t *previous = NULL;

  /* Créer le nouveau noeud */
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;

  /* Parcours la liste */
  while (current != NULL) {

    if (position == index) {

      new_node->next = current;

      /* Gère la tête de liste */
      if (previous == NULL)
        *head = new_node;
      else
        previous->next = new_node;
    }

    previous = current;
    current = current->next;
    position++;
  }

  return *head;
}
