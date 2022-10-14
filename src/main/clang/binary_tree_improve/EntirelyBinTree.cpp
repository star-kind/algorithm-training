#include "../../head/clang_enhance.h"

/*

                                    92
                                     |
                      --------------|------------------
                     |                                |
                    96                                88
                    |                                 |
            |------|---------|             |----------|------------|
           42                30            35                     110
            |
       |----|
      100

*/


#define INITIAL 0

typedef struct EntireBinaryTreeNode {
    int data;
    EntireBinaryTreeNode *left, *right;
} entireTree;

EntireBinaryTreeNode *buildsAnEntirelyTrees(int index, int *array, int arraySize) {
    if (array[index] == '\0') {
        cout << "empty value" << endl;
        return NULL;
    }

    int leftIndex = index * 2 + 1;
    int rightIndex = index * 2 + 2;

    EntireBinaryTreeNode *root = new EntireBinaryTreeNode();
    root->data = array[index];
    root->left = root->left = NULL;

    if (leftIndex > arraySize - 1) {
        root->left = NULL;
    } else {
        root->left = buildsAnEntirelyTrees(leftIndex, array, arraySize);
    }

    if (rightIndex > arraySize - 1) {
        root->right = NULL;
    } else {
        root->right = buildsAnEntirelyTrees(rightIndex, array, arraySize);
    }

    return root;
}

void post_order_nodes(entireTree *binNode) {
    if (binNode) {
        post_order_nodes(binNode->left);
        post_order_nodes(binNode->right);
        cout << binNode->data << "  ";
    }
}

bool level_ergodic_bin_trees(entireTree *binTree) {
    queue<entireTree *> queue;
    entireTree *p;

    if (binTree == NULL) {
        cout << "empty tree!" << endl;
        return false;
    }

    queue.push(binTree);
    while (!queue.empty()) {
        p = queue.front();
        queue.pop();

        cout << p->data << "  ";

        if (p->left) {
            queue.push(p->left);
        }

        if (p->right) {
            queue.push(p->right);
        }
    }
}

void executesEntireBinTree() {
    int array[] = {92, 96, 88, 42, 30, 35, 110, 100};
    int size = sizeof(array) / sizeof(int);

    entireTree *binNode = buildsAnEntirelyTrees(INITIAL, array, size);
    level_ergodic_bin_trees(binNode);
//    post_order_nodes(binNode);
}