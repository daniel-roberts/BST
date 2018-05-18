#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    void *data;
    struct node *left;
    struct node *right;
};

struct bst
{
    struct node *root;
    int (*compare)(void *, void *);
    void (*print)(void *);
};

//public prototypes
struct bst *bst_create(int compare(void *, void *), void print_func(void *));
int bst_add(struct bst *tree, void *data);
void bst_print(struct bst *tree);
void bst_delete(struct bst *tree);

//private helper functions
static struct node *node_create(void *data);
static int node_delete(void *data);
static void node_insert(struct node *root, struct node *a_node, int compare(void *, void *));
static void print_nodes(struct node *root, void print_func(void *));
static void cleanup(struct node *root);
#endif
