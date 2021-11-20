
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct tree {
    int size;
    int allocated;
    int* data;
} tree_t;

tree_t* init_tree(int);
void destroy_tree(tree_t*);
void add_to_tree(tree_t*, int);
void print_tree(const tree_t*);

#endif // BINARY_TREE_H_