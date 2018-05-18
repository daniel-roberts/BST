/*
 *
 *
 * Test driver for BST API.
 *
 */

#include <bst.h>

int compare (void *, void *);
void print_node(void *);

int main(void)
{
    struct bst *tree = bst_create(&compare, &print_node);
    int x = 1, y = 2, z = 3, a = 7;

    bst_add(tree, &a);
    bst_add(tree, &x);
    bst_add(tree, &y);
    bst_add(tree, &z);

    bst_print(tree);
    bst_delete(tree);

    return 0;
}

int compare(void *a, void *b)
{
    return a > b;
}

void print_node(void *data)
{
    printf("Data: %d\n", *(int *)data);
}
