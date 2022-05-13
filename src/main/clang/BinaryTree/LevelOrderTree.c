#include "../../head/export_index.h"

#define MAX_LENGTH 15

typedef struct BinaryTreeNode {
    int element;
    struct BinaryTreeNode *left, *right;
} treeNode;

// use method filling the empty to build a binary tree
void buildBinTree(treeNode *tree) {
    treeNode *pt;
    int arr[MAX_LENGTH] = {3, 5, 1, -1, -1, 8, 9, -1, -1, -1, 6, -1, 10, -1, -1};
    pt = tree;

    for (int i = 0; i < MAX_LENGTH; i++) {
        if (arr[i] < 0) {
            //empty tree
            tree = NULL;
        } else {
            tree = (treeNode *) malloc(sizeof(treeNode));

            //generate root node
            tree->element = arr[i];

            //recursion generate the sub left tree
            buildBinTree(tree->left);

            //recursion generate the sub right tree
            buildBinTree(tree->right);
        }
    }
}

void printNodeTree(treeNode node) {
    printf("%d ", node.element);
}

void levelOrder(treeNode node) {
    treeNode *p;
    treeNode **queue;

    int front, rear;
    front = rear = 0;

    //front between read required keep a certain distance
    queue[++rear] = &node;

    while (front - rear != 0) {
        p = queue[++front];//pop the head element of queue
        printNodeTree(*p);

        if (p->left != NULL) {
            queue[++rear] = p->left;
        } else if (p->right != NULL) {
            queue[++rear] = p->right;
        }
    }
}

void test_binary_tree_port() {
    treeNode *binTree;
    binTree = (treeNode *) malloc(sizeof(treeNode));

    buildBinTree(binTree);
    levelOrder(*binTree);
}
