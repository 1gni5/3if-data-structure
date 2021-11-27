#include <stdlib.h>

#include "queue.h" 

/*
 * Insère une valeur en fin de liste.
 */
void add(node_t ** head, int value) {

  /* Créer un nouveau noeud */
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  /* Liste vide */
  if (*head == NULL) {
    *head = new_node;
    return;
  }

  /* Parcours la liste */
  node_t* current = *head; 
  while (current->next != NULL)
    current = current->next;

  /* Ajoute la nouvelle cellule */
  current->next = new_node; 
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