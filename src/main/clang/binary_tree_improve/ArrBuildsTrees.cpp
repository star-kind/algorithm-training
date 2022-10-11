#include "../../head/clang_enhance.h"

/*
                                        A
                             -----------|--------------
                            |                         |
                            B                         C
                           |--------|                 |
                                    |       |---------|---------------|
                          |---------D       E                         F
                          |                                |----------|
                         G                                 H

level traverse sample string: ABC#DEF##G###H
*/

class TheTreesNodes {
public:
    char data;
    TheTreesNodes *left, *right;

    TheTreesNodes(char data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

TheTreesNodes *createAnTree(int index, vector<char> array) {
    if (array[index] == '#') {
        cout << "Blank Vector" << endl;
        return NULL;
    }

    int leftIndex = index * 2 + 1;
    int rightIndex = index * 2 + 2;

    TheTreesNodes *root = new TheTreesNodes(array[index]);

    if (leftIndex > array.size() - 1) {
        root->left = NULL;
    } else {
        root->left = createAnTree(leftIndex, array);
    }

    if (rightIndex > array.size() - 1) {
        root->right = NULL;
    } else {
        root->right = createAnTree(rightIndex, array);
    }

    return root;
}

bool level_display_biTree(TheTreesNodes *node) {
    if (node == NULL) {
        cout << "Empty Tree" << "\n";
        return false;
    }

    TheTreesNodes *ptr;
    queue<TheTreesNodes *> q;

    q.push(node);

    while (!q.empty()) {
        ptr = q.front();
        q.pop();

        cout << ptr->data << " ";

        if (ptr->left) {
            q.push(ptr->left);
        }

        if (ptr->right) {
            q.push(ptr->right);
        }
    }

    return true;
}

void executesArrBuilds() {
    char charArr[] = "ABC#DEF##G###H";
    int length = sizeof(charArr) / sizeof(charArr[0]);

    vector<char> vec;

    for (int i = 0; i < length - 1; ++i) {
        vec.push_back(charArr[i]);
    }

    TheTreesNodes *tree = createAnTree(0, vec);
    level_display_biTree(tree);
}
