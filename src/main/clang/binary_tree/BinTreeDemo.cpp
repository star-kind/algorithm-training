#include "../../head/clang_plus_x.h"

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
};

using BinaTree = TreeNode *;

void createsNodeTree(BinaTree &tr) {
    char check;
    tr = new TreeNode;

    cout << "please enter node data:" << endl;
    cin >> tr->data;

    //Left Children Node
    cout << "would you like to add [" << tr->data << "]'s LEFT children?(y/n)" << endl;
    cin >> check;
    if (check == 'y') {
        createsNodeTree(tr->left);
    } else {
        tr->left = NULL;
    }

    //Right Children Node
    cout << "would you like to add [" << tr->data << "]'s RIGHT children?(y/n)" << endl;
    cin >> check;
    if (check == 'y') {
        createsNodeTree(tr->right);
    } else {
        tr->right = NULL;
    }
}

void level_order_search(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (auto i = 0; i < n; ++i) {
            TreeNode *tmp = q.front();
            q.pop();

            cout << tmp->data << "  ";
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
    }
}

void TestBinaryTreeDemo() {
    BinaTree myTree;
//    int arr[15] = {3, 5, 1, -1, -1, 8, 9, -1, -1, -1, 6, -1, 10, -1, -1};

    createsNodeTree(myTree);
    level_order_search(myTree);
}

