#include "../../head/cpp_index.h"

/*
                                            A
                              --------------|--------------
                             |                            |
                             B                            C
                            |---------|          ---------|----------
                                      |          |                  |
                                      D          E                  F
                            |---------|                   |---------|
                            |                             H
                            G

enter content:
NULL A L (Root)
A B L
A C R
B D R
C E L
C F R
D G L
F H L
NULL NULL NULL (end)
 * */

void create_bin_tree_node(binTree *&treeNode) {
    string father, child, direction;
    binTree *node, *ptr;
    queue<binTree *> que;

    cout << "first enter the RootNode [format:father,child,direction(L/R)],use space-key to separate" << endl;
    cin >> father >> child >> direction;
    if (father == "NULL" && child != "NULL") {//generate root node
        node = new binTree;
        node->data = child;
        node->left = node->right = NULL;

        treeNode = node;
        que.push(treeNode);
    }

    cout << "please keep doing enter the father,child,direction(L/R),use space-key to separate" << endl;
    cin >> father >> child >> direction;
    while (!que.empty() && father != "NULL" && child != "NULL") {
        ptr = que.front();
        que.pop();

        while (father == ptr->data) {//judge twice at most
            node = new binTree;
            node->data = child;
            node->left = node->right = NULL;

            if (direction == "L") {
                ptr->left = node;
                cout << ptr->data << "'s left-child is " << node->data << endl;
            } else {
                ptr->right = node;
                cout << ptr->data << "'s right-child is " << node->data << endl;
            }

            que.push(node);
            cout << "keep doing enter next a set data (use space-key to separate):" << endl;
            cin >> father >> child >> direction;
        }
        cout << "make a mark" << endl;
    }
    cout << "leave traces" << endl;
}

bool ergodic_display(binTree *treeNode) {
    binTree *node;

    if (!treeNode) {
        cout << "empty pointer" << endl;
        return false;
    }

    queue<binTree *> que;// queue: first in , first out
    que.push(treeNode);

    while (!que.empty()) {
        node = que.front();
        que.pop();

        cout << node->data << "  ";
        if (node->left) {
            que.push(node->left);

        }

        if (node->right) {
            que.push(node->right);

        }
    }

    cout << "\n" << "-----------------------------------------" << "\n";
    return true;
}

void three_ele_exec() {
    binTree *treeNode;
    create_bin_tree_node(treeNode);
    ergodic_display(treeNode);
}