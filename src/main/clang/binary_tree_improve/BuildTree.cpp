#include "../../head/clang_enhance.h"

queue<biTrNode *> generate_root(biTrNode *&tr, queue<biTrNode *> q, vector<string> v) {
    biTrNode *node;

    string father = v[0];
    string child = v[1];

    if (father == "NULL" && child != "NULL") {
        node = new biTrNode;
        node->data = child;
        node->left = node->right = NULL;

        tr = node;
        q.push(tr);
    }

    return q;
}

queue<biTrNode *> create_tree_nodes(queue<biTrNode *> q, vector<string> v) {
    biTrNode *node, *pointer;

    string father = v[0];
    string child = v[1];
    string direction = v[2];

    if (!q.empty() && father != "NULL" && child != "NULL") {
        pointer = q.front();
        q.pop();

        /* judge parent-node of child-node whether or not,judge twice at most, one node have two children at most */
        if (father == pointer->data) {
            node = new biTrNode;
            node->data = child;
            node->left = node->right = NULL;

            if (direction == "L") {// left direction
                pointer->left = node;
                cout << pointer->data << "'s left-child is " << node->data << "\n";

            } else {// right direction
                pointer->right = node;
                cout << pointer->data << "'s right-child is " << node->data << "\n";
            }

            q.push(node);

//            delete node;
        } else {
            cout << "judge parent-node is fail" << "\n";
        }
    } else {
        cout << "end of process" << "\n";
    }

    return q;
}
