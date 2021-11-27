#include <stdlib.h>

#include "list.h"

/*
 * Insère une valeur en tête de liste.
 */
void push(node_t ** head, int value) {

  /* Créer un nouveau noeud */
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = *head;

  /* Met-à-jour la tête de liste */
  *head = new_node;
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
 * Insère une valeur à l'index donné. Si l'index
 * est hors d'atteinte, l'insertion n'est pas effectuée.
 */
void list_insert(node_t** head, int index, int value) {

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
      return;
    }

    previous = current;
    current = current->next;
    position++;
  }
}

int get_index(node_t** head, int value) {
  int position = 0;
  node_t* current = *head;

  /* Liste vide -> pas de valeur */
  if (*head == NULL) return -1;

  /* Parcours la liste */
  while (current->next != NULL) {

    /* Valeur trouvé */
    if (current->value == value)
      return position;

    current = current->next;
    position += 1;
  }

  return -1;
}