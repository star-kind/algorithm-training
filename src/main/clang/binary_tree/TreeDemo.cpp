#include "../../head/c_plus2.h"

class Node {
public:
    int data;
    Node *left;
    Node *right;
};

using Tree = Node *;

void buildNodeTree(Tree &tr) {
    int num;

    cout << "please enter the number: ";
    cin >> num;

    if (num == -1) {//empty child node
        tr = NULL;
    } else if (num == -99) {//jump out this function
        cout << "jump out here(need to enter -99 or -1)" << endl;
        return;
    } else {
        tr = new Node;
        tr->data = num;
        buildNodeTree(tr->left);
        buildNodeTree(tr->right);
    }
}

void gradation(const Tree &t) {
    //store pointers
    queue<Node *> q;
    Node *temp = NULL;

    q.push(t);

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        cout << temp->data << "  ";

        if (temp->left) {
            q.push(temp->left);
        } else if (temp->right) {
            q.push(temp->right);
        }
    }
}

/**
 *how to jump out buildNodeTree(): may need to enter muliple times -1 and muliple times -99
 */
void TestTreeDemo() {
    Tree mytree;

    buildNodeTree(mytree);
    gradation(mytree);
}

