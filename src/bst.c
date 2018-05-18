/*
 *
 * Author: Daniel Roberts
 * 
 * Simple generic BST API.
 * 
 */

#include <bst.h>

static struct node *node_create(void *data)
{
    struct node *temp = malloc(sizeof(struct node));

    if (!temp)
    {
        fprintf(stderr, "Failed to allocate memory for node!\n");
        return NULL; 
    }

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct bst *bst_create(int compare(void *, void *), void print_func(void *))
{
    /* 
     * Creates and returns a pointer to a BST structure created, with
     * custom compare function specified by user.
     *
     */

    struct bst *temp = malloc(sizeof(struct bst));

    if (!temp)
    {
        fprintf(stderr, "Failed to allocate memory for BST!\n");
        return NULL;
    }

    temp->root = NULL;
    temp->compare = compare;
    temp->print = print_func;
    return temp;
}

static void node_insert(struct node *root, struct node *a_node, int compare(void *, void *))
{
    int cmp = compare(root->data, a_node->data);

    switch (cmp)
    {
        case 0:
            if (root->left)
            {
                node_insert(root->left, a_node, compare);
            }
            else
            {
                root->left = a_node;
            }
            break;
        case 1:
            if (root->right)
            {
                node_insert(root->right, a_node, compare);
            }
            else
            {
                root->right = a_node;
            }
            break;
        default:
            break;
    }
    
}

int bst_add(struct bst *tree, void *data)
{
    struct node *temp = node_create(data);

    if (!temp)
    {
        return -1;
    }

    if (!tree->root)
    {
        tree->root = temp;
        return 1;
    }
    node_insert(tree->root, temp, tree->compare);
    return 1;

}

void bst_print(struct bst *tree)
{
    printf("Current nodes in BST:\n");
    print_nodes(tree->root, tree->print);
}

static void print_nodes(struct node *root, void print_func(void *))
{
    if (root)
    {
        print_nodes(root->left, print_func);
        print_func(root->data);
        print_nodes(root->right, print_func);
    }
}

void bst_delete(struct bst *tree)
{
    cleanup(tree->root);
    free(tree);
}

static void cleanup(struct node *root)
{
    if (root)
    {
        cleanup(root->left);
        cleanup(root->right);
        free(root);
    }
}
