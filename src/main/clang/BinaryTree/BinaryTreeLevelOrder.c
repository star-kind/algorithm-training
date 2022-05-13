#include "../../head/export_index.h"

typedef struct BinaryTree {
    int data;
    struct BinaryTree *left, *right;
} tree;

tree *createTree(tree *node, int t) {
    if (node == NULL) {
        node = (tree *) malloc(sizeof(tree));
        node->data = t;
        node->left = NULL;
        node->right = NULL;
        return node;
    } else {
        if (t < node->data) {
            node->left = createTree(node->left, t);
        } else {
            node->right = createTree(node->right, t);
        }
        return node;
    }
}

void display(tree *node, int level) {
    printf("\n");

    if (node != NULL) {
        display(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("%d ", node->data);
        }
        display(node->left, level + 1);
    }
}

void test_port_tree_order() {
    tree *node = NULL;
    int x, y = 1;

    printf("you can enter -99 to stop process:\t");
    scanf("%d", &x);

    while (x != -99) {
        node = createTree(node, x);
        display(node, y);

        printf("you can enter -99 to stop process:\t");
        scanf("%d", &x);
    }

    display(node, y);
}