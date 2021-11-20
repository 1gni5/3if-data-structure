#include <stdio.h>

#include "binary-tree.h"

int main() {

    /* Créer un nouvel arbre */
    tree_t* tree = init_tree(5);

    /* Ajoute des éléments */
    int values[5] = {1, 5, 4, 9, 7};
    for (int x = 0; x < 5; x++)
        add_to_tree(tree, values[x]);

    /* Affiche les éléments */
    print_tree(tree);
    
    /* Détruit l'arbre créé */
    destroy_tree(tree);
    return 0;
}