#include "../../head/clang_plus_x.h"

class Monster {
public:
    int id;
    int level;
    char name;

public:
    Monster() {}

    Monster(int id, int level, const char *name) {
        this->id = id;
        this->level = level;
        memcpy(&this->name, name, strlen(name) + 1);
    }
};

template<class T>
class BiTreeNode {
public:
    T element;
    BiTreeNode<T> *left;
    BiTreeNode<T> *right;

    BiTreeNode(T &ele) {
        //initialization
        memset(&element, 0, sizeof(BiTreeNode));
        //assignment for element
        memcpy(&element, &ele, sizeof(T));
        left = right = NULL;
    }
};


template<class T>
class BiTreeSort {
public:
    BiTreeSort();
    ~BiTreeSort();

public:
    void InOrderTraverse(BiTreeNode<T> *node);
    BiTreeNode<T> *GetRoot();

private:
    void Init();
    void ClearBinTree(BiTreeNode<T> *node);

private:
    BiTreeNode<T> *ptr_root;// pointer of root node
    int size;
};

template<class T>
BiTreeSort<T>::BiTreeSort() {
    Init();
}


template<class T>
BiTreeSort<T>::~BiTreeSort() {
    cout << "destructor function" << endl;
    ClearBinTree(ptr_root);
}

template<class T>
void BiTreeSort<T>::Init() {
    Monster m1(1, 2, "column");
    Monster m2(3, 4, "spaces");
    Monster m3(5, 6, "selection");

    Monster m4(11, 12, "professional");
    Monster m5(13, 14, "courses");
    Monster m6(15, 16, "fitness");
    Monster m7(17, 18, "release");

    BiTreeNode<Monster> *n1 = new BiTreeNode<Monster>(m1);
    BiTreeNode<Monster> *n2 = new BiTreeNode<Monster>(m2);
    BiTreeNode<Monster> *n3 = new BiTreeNode<Monster>(m3);

    BiTreeNode<Monster> *n4 = new BiTreeNode<Monster>(m4);
    BiTreeNode<Monster> *n5 = new BiTreeNode<Monster>(m5);
    BiTreeNode<Monster> *n6 = new BiTreeNode<Monster>(m6);
    BiTreeNode<Monster> *n7 = new BiTreeNode<Monster>(m7);

    ptr_root = n5;
    n5->left = n4;
    n5->right = n6;

    n4->left = n1;
    n1->right = n2;
    n6->left = n3;
    n3->left = n7;
    size = 7;
}

template<class T>
BiTreeNode<T> *BiTreeSort<T>::GetRoot() {
    return ptr_root;
}

template<class T>
void BiTreeSort<T>::ClearBinTree(BiTreeNode<T> *node) {
    if (node != NULL) {
        ClearBinTree(node->left);
        ClearBinTree(node->right);
        delete node;
        node = NULL;
    }
}

template<class T>
void BiTreeSort<T>::InOrderTraverse(BiTreeNode<T> *node) {
    char *name = NULL;

    if (node != NULL) {
        InOrderTraverse(node->left);
        name = (char *) &node->element;
        name += 8;

        cout << "value: " << (int *) &node->element << endl;
        cout << "name: " << name << endl;
        InOrderTraverse(node->right);
    }
}

void TestBinTree() {
    BiTreeSort<Monster> *p = new BiTreeSort<Monster>;
    p->InOrderTraverse(p->GetRoot());
}