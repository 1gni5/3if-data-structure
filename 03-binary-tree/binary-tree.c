#include <stdlib.h>
#include <stdio.h>

/* Interface locales */
#include "binary-tree.h"

/*
 * Initialise un nouvel arbre binaire de taille
 * size.
 */
tree_t* init_tree(int size) {
     tree_t* tree = (tree_t*)malloc(sizeof(tree_t));
     tree->allocated = size;
     tree->size = 0;

     tree->data = (int*)malloc(size * sizeof(int));
     return tree;
}

/*
 * Détruit un arbre passé en paramètre, libère la mémoire.
 */
void destroy_tree(tree_t* tree) {
    free(tree->data);
    free(tree);
}

/*
 * Ajoute une valeur à un arbre donné.
 */
void add_to_tree(tree_t* tree, int value) {

    /* Réallocation nécessaire */
    if (tree->allocated < (tree->size + 1)) {
        tree->allocated *= 2;
        tree->data = (int*)realloc(tree->data, tree->allocated);
    }

    tree->size += 1;
    tree->data[tree->size] = value;
}

/*
 * Affiche le contenu d'un arbre donné.
 */
void print_tree(const tree_t* tree) {
    
    for (int x = 0; x < tree->size; x++)
        printf("%d ", tree->data[x]);
    printf("\n");
}