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
  new_node->previous = NULL;

  /* Met-à-jour la tête de liste */
  if (*head != NULL)
    (*head)->previous = new_node;
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

  if (next_node != NULL)
    next_node->previous = NULL;

  return ret_val;
}

/*
 * Insére une valeur à l'indice données.
 * Si l'indice n'existe pas la valeur n'est pas insérée.
 */
node_t* insert(node_t** head, int index, int value) {

  int position = 0;
  node_t *current = *head;

  /* Gère l'introduction en tête de liste */
  if (index == 0)
    return push(head, value);

  /* Créer le nouveau noeud */
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;

  /* Parcours la liste */
  while (current != NULL) {

    if (position == index) {

      /* Raccorde le noeud précédent */
      new_node->previous = current->previous;
      new_node->previous->next = new_node;

      /* Raccorde le noeud suivant */
      new_node->next = current;
      current->previous = new_node;
      break;
    }

    current = current->next;
    position++;
  }

  return *head;
}
